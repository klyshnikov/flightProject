#ifndef TFNV_COLORARGUMENT_H
#define TFNV_COLORARGUMENT_H

namespace calculation {

    class ColorArgument {
    public:
        int r_;
        int g_;
        int b_;
        double transparency_;
        ColorArgument(int r, int g, int b, double transparency);
    };

}

#endif
