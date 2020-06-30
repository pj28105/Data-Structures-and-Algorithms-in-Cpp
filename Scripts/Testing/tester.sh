for((i = 1; ; ++i)); do
    echo "Test "$i
    cat in.txt
    ./gen $i > in.txt
    diff -w <(./a < in.txt) <(./brute < in.txt) || break
    echo "Passed test "$i
    echo "***************************************************"
done
echo "Failed on test "$i