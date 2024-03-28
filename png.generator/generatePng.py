import os
import sys
import folium
from pyppeteer import launch
import asyncio
from PIL import Image


async def main(latitude: float, longitude: float):
    m = folium.Map(location=[latitude, longitude],
                   zoom_start=11)

    m.save("map.html")

    browser = await launch(headless=True)
    page = await browser.newPage()
    await page.goto(f"file://{os.path.abspath('.')}/map.html")
    await page.setViewport({'width': 1500, 'height': 1500})
    await page.screenshot({'path': "map.png"})
    # os.remove("map.html")


if __name__ == '__main__':
    asyncio.get_event_loop().run_until_complete(main(float(sys.argv[1]), float(sys.argv[2])))
    im = Image.open('map.png')
    im_crop = im.crop((285, 285, 1225, 1225))
    im_crop.save('map.png', quality=95)
