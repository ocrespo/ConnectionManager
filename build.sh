rm -R -f build
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=..  ..
make VERBOSE=1
make install