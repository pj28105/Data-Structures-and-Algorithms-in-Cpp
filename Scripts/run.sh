# Checks for overflows and out of bounds
filename=$PWD/$1
g++ -std=c++17 -Wshadow -Wall $filename -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g && ./a.out
