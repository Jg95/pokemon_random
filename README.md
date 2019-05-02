Compilation instructions

Install SDL2 with its compinents image and tff

In ubuntu run "sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev"

Go to the source of the repository and execute the folowing
    mkdir build
    cd build
    cmake ..
    make -j4
    
Finally run "./pokemon_random" and enjoy
