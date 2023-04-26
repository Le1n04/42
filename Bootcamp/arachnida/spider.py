import os
import argparse
import requests
import shutil
from urllib.parse import urlparse
from bs4 import BeautifulSoup
"""

El programa spider permitirá extraer todas las imágenes de un sitio web, de manera
recursiva, proporcionando una url como parámetro. Gestionarás las siguientes opciones
del programa:

./spider [-rlpS] URL

• Opción -r : descarga de forma recursiva las imágenes en una URL recibida como
parámetro.
• Opción -r -l [N] : indica el nivel profundidad máximo de la descarga recursiva.
En caso de no indicarse, será 5.
• Opción -p [PATH] : indica la ruta donde se guardarán los archivos descargados.

En caso de no indicarse, se utilizará ./data/.

El programa descargará por defecto las siguientes extensiones:
◦ .jpg/jpeg
◦ .png
◦ .gif
◦ .bmp

"""

def get_links(content):
    soup = BeautifulSoup(content, "html.parser")
    links = []
    for img in soup.find_all("img"):
        src = img.get("src")
        if src:
            links.append(src)
        return links
    
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Download images from a web page.")
    parser.add_argument("url", type=str, nargs="?", help="URL of the web page")
    parser.add_argument("-r", "--recursive", action="store_true", help="Download images from pages linked to the URL recursively")
    parser.add_argument("-l", "--level", type=int, default=1, help="Maximum level of recursion when downloading images (default: 1)")
    parser.add_argument("-p", "--path", type=str, default="images.url", help="Path to the folder where images will be saved (default: images.url)")
    parser.add_argument('-c', '--clean', action='store_true',  help='Delete the image folder before scraping.')
    print(parser.parse_args)