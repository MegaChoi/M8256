Compiling commands
g++ -o program main.cpp Utils.cpp Render.cpp ImageSpecs.cpp `pkg-config opencv4 --cflags --libs`

./program ../resources/30MB.mp3
./program ../resources/sample10MB.wav 

