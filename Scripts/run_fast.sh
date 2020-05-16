# Ignores overflows and out of bounds

filename=$PWD/$1
g++ -std=c++17 -Wshadow -Wall $filename -O2 -Wno-unused-result && ./a.out