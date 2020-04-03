@echo off
if not exist "./bin" mkdir bin
cl ./src/main.cpp /EHsc /Fe:./bin/touch.exe /Fo:./bin/touch.obj -I ".."