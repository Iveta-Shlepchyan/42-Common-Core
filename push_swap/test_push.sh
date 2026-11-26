
#!/bin/bash

run_test()
{
    name=$1
    shift
    echo ""
    echo "========== $name =========="
    ./push_swap --bench "$@" > /dev/null
}

# 100 numbers
run_test "100 - LOW DISORDER" \
1 0 2 3 4 5 6 7 8 9 80 11 12 13 14 15 16 17 18 79 \
29 21 22 23 84 25 26 27 28 20 30 31 32 33 34 35 36 37 38 39 \
40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 \
60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 19 \
10 81 82 83 24 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99

run_test "100 - MEDIUM DISORDER" \
$(seq 0 2 98 | tr '\n' ' ') $(seq 99 -2 1 | tr '\n' ' ')

run_test "100 - REVERSED" \
$(seq 99 -1 0 | tr '\n' ' ')

# 500 numbers
run_test "500 - LOW DISORDER" \
1 0 $(seq 2 499 | tr '\n' ' ')

run_test "500 - MEDIUM DISORDER" \
$(seq 0 2 498 | tr '\n' ' ') $(seq 499 -2 1 | tr '\n' ' ')

run_test "500 - REVERSED" \
$(seq 499 -1 0 | tr '\n' ' ')
