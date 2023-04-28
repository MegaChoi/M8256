Compiling commands
g++ -o program main.cpp Utils.cpp Render.cpp ImageSpecs.cpp `pkg-config opencv4 --cflags --libs`
./program ../resources/sample10MB.wav 

Compression ratios:
    Rendering a 10MB sample file output a 4MB avi file, the ratio is 5:2, 