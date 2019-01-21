cd /tmp && rm -rf benchmark && git clone git@github.com:google/benchmark.git && cd benchmark && mkdir build && cd build && cmake .. && make -j8 && sudo make install && cd ../.. && rm -rf benchmark
