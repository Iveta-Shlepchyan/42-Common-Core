

#!/bin/bash

run_test()
{
    algo=$1
    name=$2
    shift 2

    echo ""
    echo "========== $algo | $name =========="
    ./push_swap --bench "$algo" "$@" > /dev/null
}

# Generate patterns
make_even_odd()
{
    n=$1
    for ((i = 0; i < n; i += 2)); do
        echo "$i"
    done
    for ((i = 1; i < n; i += 2)); do
        echo "$i"
    done
}

make_low_high()
{
    n=$1
    for ((i = 0; i < n / 2; i++)); do
        echo "$i"
        echo "$((n - 1 - i))"
    done
}

make_organ_pipe()
{
    n=$1
    for ((i = 0; i < n / 2; i++)); do
        echo "$i"
    done
    for ((i = n - 1; i >= n / 2; i--)); do
        echo "$i"
    done
}

make_blocks()
{
    n=$1
    block=$2
    start=0

    while ((start < n)); do
        end=$((start + block - 1))
        ((end >= n)) && end=$((n - 1))

        for ((i = end; i >= start; i--)); do
            echo "$i"
        done
        start=$((start + block))
    done
}

make_nearly_sorted()
{
    n=$1
    arr=($(seq 0 $((n - 1))))

    # A few misplaced elements
    temp=${arr[0]}
    arr[0]=${arr[1]}
    arr[1]=$temp

    temp=${arr[10]}
    arr[10]=${arr[80]}
    arr[80]=$temp

    temp=${arr[20]}
    arr[20]=${arr[90]}
    arr[90]=$temp

    printf '%s\n' "${arr[@]}"
}

# Build test arrays
for n in 100 500; do
    mapfile -t sorted < <(seq 0 $((n - 1)))
    mapfile -t reversed < <(seq $((n - 1)) -1 0)
    mapfile -t even_odd < <(make_even_odd "$n")
    mapfile -t low_high < <(make_low_high "$n")
    mapfile -t organ_pipe < <(make_organ_pipe "$n")
    mapfile -t blocks < <(make_blocks "$n" 10)
    mapfile -t nearly_sorted < <(make_nearly_sorted "$n")
    mapfile -t random < <(shuf -i 0-$((n - 1)))

    # Run every algorithm against every pattern
    for algo in --simple --medium --complex; do

        run_test "$algo" "$n - SORTED" "${sorted[@]}"

        run_test "$algo" "$n - NEARLY SORTED" \
            "${nearly_sorted[@]}"

        run_test "$algo" "$n - EVEN / ODD" \
            "${even_odd[@]}"

        run_test "$algo" "$n - LOW / HIGH" \
            "${low_high[@]}"

        run_test "$algo" "$n - ORGAN PIPE" \
            "${organ_pipe[@]}"

        run_test "$algo" "$n - REVERSED BLOCKS" \
            "${blocks[@]}"

        run_test "$algo" "$n - RANDOM" \
            "${random[@]}"

        run_test "$algo" "$n - REVERSED" \
            "${reversed[@]}"

    done
done

