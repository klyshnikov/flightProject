#include "SvgGenerator.h"
#include "PngGenerator.h"

namespace calculation {

    void SvgGenerator::generateSvgImage(const SectorBunch& sectorBunch, std::string fileName) {
        createSvgImage(fileName); // generate hat
        addStartedScript(fileName);
        addBackground(fileName, sectorBunch);

        addBarChartSvg(fileName, sectorBunch);

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
                addNoiseInImage(sectorBunch, fileName, i, j);
            }
        }

        endSvgFile(fileName);
    }

    ColorArgument SvgGenerator::getColor(int noise) {
        int redScale = std::min(255.0, (double(noise)/max_noise)*500);
        //double transparencyScale = (redScale/255.0)*0.5;
        return ColorArgument(redScale, 255-redScale, 0, 0.3);
    }

    void SvgGenerator::createSvgImage(std::string fileName) {
        std::ofstream out;
        out.open(path_+fileName);
        if (out.is_open()) {
            out << R"__(<?xml version="1.0" standalone="no"?>)__" << "\n"
                << R"__(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)__" << "\n"
                << R"__(<svg version="1.1" width="2048" height="2048" onload="init(evt)" viewBox="0 0 2048 2048" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">)__" << "\n";

            out << R"__(<style type="text/css">
        text { font-family:Verdana; font-size:12px; fill:rgb(0,0,0); }
        #search, #ignorecase { opacity:0.1; cursor:pointer; }
        #search:hover, #search.show, #ignorecase:hover, #ignorecase.show { opacity:1; }
        #subtitle { text-anchor:middle; font-color:rgb(160,160,160); }
        #title { text-anchor:middle; font-size:17px}
        #unzoom { cursor:pointer; }
        #frames > *:hover { stroke:black; stroke-width:0.5; cursor:pointer; }
        .hide { display:none; }
        .parent { opacity:0.5; }
        #tooltip {
                  background: cornsilk;
                  border: 1px solid black;
                  border-radius: 5px;
                  padding: 5px;
                 }
</style>
)__" << "\n";
        }
        out.close();
    }
//    <rect id="ttcol0__" x="8" y="65%" width="9" height="48" fill="#6f58e9" opacity="1" tabindex="-1" style="outline: none;" role="img" aria-label="0, 19. Item 1."/>

   void SvgGenerator::addNoiseInImage(const SectorBunch& sectorBunch, std::string fileName, int i, int j) {
        ColorArgument colorArgument = getColor(Algorithms::countNoiseLevel(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises));
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            //out << R"__(<g id="frames">)__" << "\n";

            out << "\t" << R"(<rect x=")" << j*32 << R"(" y=")" << i*32 << R"(" width=")" << 32 << R"(" height=")" << 32 << R"(" fill="rgba()"
            << colorArgument.r_ << ","
            << colorArgument.g_ << ","
            << colorArgument.b_ << ","
            << colorArgument.transparency_
            << ")\" onmousemove=\"showTooltip(evt, [";
            auto values = get24NoisesInSector(sectorBunch, i, j);
            out << values[0];
            for (int i = 1; i < values.size(); i++){
                out << "," << values[i];
            }
            out << "]);\" onmouseout=\"hideTooltip(); \">   \n" << getGistogram(sectorBunch, i, j) << R"(</rect>)";
        }
        out.close();
    }

    void SvgGenerator::endSvgFile(std::string fileName) {
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << " </svg> \n";
        }
        out.close();
    }

    void SvgGenerator::addBackground(std::string fileName, const SectorBunch& sectorBunch) {
        PngGenerator::generatePng(sectorBunch.center_.latitude, sectorBunch.center_.longitude);

        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << R"(<image href="map.png" x="0" y="0" height="2048" width="2048" />)";
        }
        out.close();
    }

    std::string SvgGenerator::getGistogram(const SectorBunch& sectorBunch, int i, int j) {
        return "";
        std::vector<int> currentSectorDataToShow(24);
        std::vector<int> currentSectorData24Values(24);
        std::string result = "";
        result += "<title>\n";
        for (int i = 0; i < 24; ++i) {
            if (!sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[i].empty()) {
                currentSectorDataToShow[i] = (Algorithms::countNoiseLevelByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[i])/double(max_noise))*bar_chart_size;
                currentSectorData24Values[i] = Algorithms::countNoiseLevelByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[i]);
            } else {
                currentSectorDataToShow[i] = 0;
                currentSectorData24Values[i] = 0;
            }
        }

        for (int row = bar_chart_size; row >= 1; --row) {
            for (int h = 0; h < 24; ++h) {
                if (currentSectorDataToShow[h] >= row) {
                    result += Algorithms::getStringBiggerSize("#", 3);
                } else {
                    result += Algorithms::getStringBiggerSize(" ", 3);;
                }
            }
            result += "\n";
        }

        for (auto v : currentSectorData24Values) {
            result += Algorithms::getStringBiggerSize(std::to_string(v), 3);
        }
        result += "</title>";
        return result;
    }

    void SvgGenerator::addStartedScript(std::string fileName) {
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << R"__(<script>
        <![CDATA[
function setTTColData(ttcol, dbl) {
  ttcol.setAttribute("y", (100-dbl)+'%')
  ttcol.setAttribute("y", (79-(dbl*0.79))+'%')
  ttcol.setAttribute("height", (dbl*0.79)+'%')
}

function showTooltip(evt, dbls) {
  for (let i = 0; i < 24; i++) {
      let ttcol = document.getElementById("ttcol"+i);
      setTTColData(ttcol, dbls[i])

  }

  let tooltip = document.getElementById("tooltip");
  tooltip.style.visibility = "visible";
  tooltip.setAttribute("x", evt.pageX + 10)
  tooltip.setAttribute("y", evt.pageY + 10)
}

function hideTooltip() {
  var tooltip = document.getElementById("tooltip2");
  tooltip.style.visibility = "hidden";
}
]]>
</script>
)__";
        }
        out.close();
    }

    void SvgGenerator::addBarChartSvg(std::string fileName, const SectorBunch &sectorBunch) {
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << R"__(<svg id="tooltip" version="1.1" style="font-family: Roboto; font-size: 12px;" xmlns="http://www.w3.org/2000/svg" width="650" height="400" viewBox="0 0 650 400" aria-hidden="false" aria-label="Interactive chart">
<defs aria-hidden="true">
<clipPath >
<rect x="0" y="0" width="596" height="316" fill="none"></rect>
</clipPath>
<clipPath >
<rect x="0" y="0" width="596" height="316" fill="none"></rect>
</clipPath>
</defs>
<rect fill="#ffffff" x="0" y="0" width="650" height="400" rx="0" ry="0" aria-hidden="true"></rect>
<rect fill="none" x="10" y="47" width="596" height="316" aria-hidden="true"></rect>
<g data-z-index="0" aria-hidden="true"></g>
<rect fill="none" data-z-index="1" x="10" y="47" width="596" height="316" aria-hidden="true"></rect>
<g data-z-index="1" aria-hidden="true">
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 34.5 47 L 34.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 59.5 47 L 59.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 83.5 47 L 83.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 108.5 47 L 108.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 133.5 47 L 133.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 158.5 47 L 158.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 183.5 47 L 183.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 208.5 47 L 208.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 232.5 47 L 232.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 257.5 47 L 257.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 282.5 47 L 282.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 307.5 47 L 307.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 332.5 47 L 332.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 357.5 47 L 357.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 381.5 47 L 381.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 406.5 47 L 406.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 431.5 47 L 431.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 456.5 47 L 456.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 481.5 47 L 481.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 506.5 47 L 506.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 530.5 47 L 530.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 555.5 47 L 555.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 580.5 47 L 580.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 605.5 47 L 605.5 363" opacity="1"></path>
<path fill="none" stroke-dasharray="none" data-z-index="1" d="M 9.5 47 L 9.5 363" opacity="1"></path>
</g>
<g data-z-index="1" aria-hidden="true"></g>
<g data-z-index="1" aria-hidden="true">
<path fill="none" stroke="#e6e6e6" stroke-width="1" stroke-dasharray="none" data-z-index="1" d="M 10 363.5 L 606 363.5" opacity="1"></path>
<path fill="none" stroke="#e6e6e6" stroke-width="1" stroke-dasharray="none" data-z-index="1" d="M 10 110.5 L 606 110.5" opacity="1"></path>
<path fill="none" stroke="#e6e6e6" stroke-width="1" stroke-dasharray="none" data-z-index="1" d="M 10 300.5 L 606 300.5" opacity="1"></path>
<path fill="none" stroke="#e6e6e6" stroke-width="1" stroke-dasharray="none" data-z-index="1" d="M 10 237.5 L 606 237.5" opacity="1"></path>
<path fill="none" stroke="#e6e6e6" stroke-width="1" stroke-dasharray="none" data-z-index="1" d="M 10 173.5 L 606 173.5" opacity="1"></path>
<path fill="none" stroke="#e6e6e6" stroke-width="1" stroke-dasharray="none" data-z-index="1" d="M 10 46.5 L 606 46.5" opacity="1"></path>
</g>
<g data-z-index="2" aria-hidden="true">
<path fill="none" stroke="#ccd6eb" stroke-width="1" data-z-index="7" d="M 10 363.5 L 606 363.5"></path>
</g>
<g data-z-index="2" aria-hidden="true">
<path fill="none" data-z-index="7" d="M 10 47 L 10 363"></path>
</g>
<g data-z-index="2" aria-hidden="true">
<path fill="none" data-z-index="7" d="M 606 47 L 606 363"></path>
</g>
<g data-z-index="3" aria-hidden="false">
<g data-z-index="0.1" opacity="1" transform="translate(10,47) scale(1 1)" clip-path="url(#highcharts-i470t67-2760-)" style="cursor: pointer;" aria-hidden="false">)__" << "\n";

            for (int i = 0; i<24; ++i) {
                out << R"__(<rect id="ttcol)__" <<  i << R"__(" x=")__" << (8+(25*i)) << R"__(" y="65%" width="9" height="48" fill="#6f58e9" opacity="1" tabindex="-1" style="outline: none;" role="img" aria-label="0, 19. Item 1."> </rect>)__" << "\n";
            }

            out << R"__(</g>
<g data-z-index="0.1" opacity="1" transform="translate(10,47) scale(1 1)" clip-path="none" aria-hidden="true">
</g>
</g>
<g data-z-index="3" aria-hidden="true">
<g stroke-linecap="round" style="cursor: pointer;" transform="translate(616,10)">
<title>Chart context menu</title>
<rect fill="#ffffff" x="0.5" y="0.5" width="24" height="22" rx="2" ry="2" stroke="none" stroke-width="1"></rect>
<path fill="#666666" d="M 6 6.5 L 20 6.5 M 6 11.5 L 20 11.5 M 6 16.5 L 20 16.5" data-z-index="1" stroke="#666666" stroke-width="3"></path>
<text font-family='Roboto-Regular,Roboto' x="0" data-z-index="1" y="15.5" style="color: rgb(51, 51, 51); font-weight: normal; fill: rgb(51, 51, 51);"></text>
</g>
</g>
<text font-family='Roboto-Regular,Roboto' x="325" text-anchor="middle" data-z-index="4" style="color: rgb(51, 51, 51); font-size: 18px; fill: rgb(51, 51, 51);" y="24" aria-hidden="true">Chart title</text>
<text font-family='Roboto-Regular,Roboto' x="325" text-anchor="middle" data-z-index="4" style="color: rgb(102, 102, 102); fill: rgb(102, 102, 102);" y="46" aria-hidden="true"></text>
<text font-family='Roboto-Regular,Roboto' x="10" text-anchor="start" data-z-index="4" style="color: rgb(102, 102, 102); fill: rgb(102, 102, 102);" y="397" aria-hidden="true"></text>
<g data-z-index="6" opacity="1" transform="translate(10,47) scale(1 1)" style="cursor: pointer;" aria-hidden="true">)__";

            for (int i = 0; i<24; ++i) {
                out << R"__(<g data-z-index="1" style="cursor: pointer;" transform="translate()__" << (1+(25*i)) <<R"__(,300)">)__" <<
                       R"__(<text id="ttval)__" << i << R"__(" font-family='Roboto-Regular,Roboto' x="5" data-z-index="1" y="16" style="color: rgb(255, 255, 255); font-size: 11px; font-weight: bold; fill: rgb(255, 255, 255);">19</text> </g>)__" << "\n";

            }

            out << R"__(</g>
<g data-z-index="7" aria-hidden="true"><text font-family='Roboto-Regular,Roboto' x="22.416666666667332" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">0</text><text font-family='Roboto-Regular,Roboto' x="47.250000000000334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">1</text><text font-family='Roboto-Regular,Roboto' x="72.08333333333333" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">2</text><text font-family='Roboto-Regular,Roboto' x="96.91666666666333" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">3</text><text font-family='Roboto-Regular,Roboto' x="121.75000000000334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">4</text><text font-family='Roboto-Regular,Roboto' x="146.58333333333334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">5</text><text font-family='Roboto-Regular,Roboto' x="171.41666666667334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">6</text>
<text font-family='Roboto-Regular,Roboto' x="196.25000000000335" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">7</text><text font-family='Roboto-Regular,Roboto' x="221.08333333333334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">8</text><text font-family='Roboto-Regular,Roboto' x="245.91666666667336" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">9</text><text font-family='Roboto-Regular,Roboto' x="270.7500000000033" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">10</text><text font-family='Roboto-Regular,Roboto' x="295.5833333333333" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">11</text><text font-family='Roboto-Regular,Roboto' x="320.41666666667334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">12</text><text font-family='Roboto-Regular,Roboto' x="345.2500000000033" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">13</text><text font-family='Roboto-Regular,Roboto' x="370.0833333333333" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">14</text><text font-family='Roboto-Regular,Roboto' x="394.91666666667334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">15</text><text font-family='Roboto-Regular,Roboto' x="419.7500000000033" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">16</text><text font-family='Roboto-Regular,Roboto' x="444.5833333333333" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">17</text><text font-family='Roboto-Regular,Roboto' x="469.41666666667334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">18</text><text font-family='Roboto-Regular,Roboto' x="494.2500000000033" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">19</text><text font-family='Roboto-Regular,Roboto' x="519.0833333333334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">20</text><text font-family='Roboto-Regular,Roboto' x="543.9166666666733" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">21</text><text font-family='Roboto-Regular,Roboto' x="568.7500000000034" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">22</text><text font-family='Roboto-Regular,Roboto' x="593.5833333333334" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="middle" transform="translate(0,0)" y="382" opacity="1">23</text></g><g data-z-index="7" aria-hidden="true"></g>
<g data-z-index="7" aria-hidden="true">
<text font-family='Roboto-Regular,Roboto' x="621" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="start" transform="translate(0,0)" y="367" opacity="1">0</text>
<text font-family='Roboto-Regular,Roboto' x="621" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="start" transform="translate(0,0)" y="114" opacity="1">100</text>
<text font-family='Roboto-Regular,Roboto' x="621" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="start" transform="translate(0,0)" y="304" opacity="1">25</text>
<text font-family='Roboto-Regular,Roboto' x="621" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="start" transform="translate(0,0)" y="241" opacity="1">50</text>
<text font-family='Roboto-Regular,Roboto' x="621" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="start" transform="translate(0,0)" y="177" opacity="1">75</text>
<text font-family='Roboto-Regular,Roboto' x="621" style="color: rgb(102, 102, 102); cursor: default; font-size: 11px; fill: rgb(102, 102, 102);" text-anchor="start" transform="translate(0,0)" y="51" opacity="1">125</text>
</g>
<g style="cursor: default; white-space: nowrap; pointer-events: none;" data-z-index="8" transform="translate(552,270)" opacity="0.802" aria-hidden="true">
<path fill="none" d="M 3.5 0.5 L 80.5 0.5 C 83.5 0.5 83.5 0.5 83.5 3.5 L 83.5 41.5 C 83.5 44.5 83.5 44.5 80.5 44.5 L 47.5 44.5 L 41.5 50.5 L 35.5 44.5 L 3.5 44.5 C 0.5 44.5 0.5 44.5 0.5 41.5 L 0.5 3.5 C 0.5 0.5 0.5 0.5 3.5 0.5" stroke="#000000" stroke-opacity="0.049999999999999996" stroke-width="5" transform="translate(1, 1)"></path>
<path fill="none" d="M 3.5 0.5 L 80.5 0.5 C 83.5 0.5 83.5 0.5 83.5 3.5 L 83.5 41.5 C 83.5 44.5 83.5 44.5 80.5 44.5 L 47.5 44.5 L 41.5 50.5 L 35.5 44.5 L 3.5 44.5 C 0.5 44.5 0.5 44.5 0.5 41.5 L 0.5 3.5 C 0.5 0.5 0.5 0.5 3.5 0.5" stroke="#000000" stroke-opacity="0.09999999999999999" stroke-width="3" transform="translate(1, 1)"></path>
<path fill="none" d="M 3.5 0.5 L 80.5 0.5 C 83.5 0.5 83.5 0.5 83.5 3.5 L 83.5 41.5 C 83.5 44.5 83.5 44.5 80.5 44.5 L 47.5 44.5 L 41.5 50.5 L 35.5 44.5 L 3.5 44.5 C 0.5 44.5 0.5 44.5 0.5 41.5 L 0.5 3.5 C 0.5 0.5 0.5 0.5 3.5 0.5" stroke="#000000" stroke-opacity="0.15" stroke-width="1" transform="translate(1, 1)"></path>
<path fill="rgba(247,247,247,0.85)" d="M 3.5 0.5 L 80.5 0.5 C 83.5 0.5 83.5 0.5 83.5 3.5 L 83.5 41.5 C 83.5 44.5 83.5 44.5 80.5 44.5 L 47.5 44.5 L 41.5 50.5 L 35.5 44.5 L 3.5 44.5 C 0.5 44.5 0.5 44.5 0.5 41.5 L 0.5 3.5 C 0.5 0.5 0.5 0.5 3.5 0.5" stroke="#6f58e9" stroke-width="1">
</path>
<text font-family='Roboto-Regular,Roboto' x="8" data-z-index="1" y="18" style="color: rgb(51, 51, 51); font-size: 12px; fill: rgb(51, 51, 51);">
<tspan style="font-size: 10px;">23</tspan>
<tspan dy="15" x="8">​</tspan>
<tspan style="color: rgb(111, 88, 233); fill: rgb(111, 88, 233);">●</tspan> Item 1: <tspan style="font-weight: bold;">17</tspan>
<tspan >​</tspan>
</text>
</g>
</svg>)__" << "\n";
        }
        out.close();
    }

    std::vector<int> SvgGenerator::get24NoisesInSector(const SectorBunch &sectorBunch, int i, int j) {
        std::vector<int> currentSectorDataToShow(24);
        std::vector<int> currentSectorData24Values(24);
        for (int h = 0; h < 24; ++h) {
            if (!sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[h].empty()) {
                currentSectorDataToShow[h] = (Algorithms::countNoiseLevelByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[h])/double(max_noise))*bar_chart_size;
                currentSectorData24Values[h] = Algorithms::countNoiseLevelByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[h]);
            } else {
                currentSectorDataToShow[h] = 0;
                currentSectorData24Values[h] = 0;
            }
        }

        return currentSectorData24Values;
    }

}
