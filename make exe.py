# Xander O'Hara
# 05-09-2024
# "Hello, World" assignment py code to exe


import PyInstaller.__main__
import os

script_path = "C:\\Users\\xande\\Desktop\\VS CODE\\School\\C++ Class\\Hello World - Project 1\\PY\\helloworld.py"
script_directory = os.path.dirname(script_path)

PyInstaller.__main__.run([
    script_path,
    '--onefile',
    '--distpath',
    script_directory,
])

print("done")

