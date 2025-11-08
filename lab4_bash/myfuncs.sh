#! /bin/bash

test_variable (){
    name="ehduq"
    echo "your name is $name" 
}

#test_variable

test_para (){
    echo $1
    echo $2
    echo $3
    echo $@
    echo $*
    echo $#
}

#test_para 10 20 30

#echo $1
#echo $2
#echo $3
#echo $@
#echo $*
#echo $#
#echo $0

test_for(){
    for n in 10 20 30; do
        echo $n
    done

    for x in $@; do
        echo $x
    done
}

#test_for kdy ehduq

files=$(ls)
#echo $files

files_2=$(ls | wc -l)
#echo $files_2


print_file_and_lines() {
    # myfirstbash.sh
    # test.txt
    # ...
    # 현재 디렉토리에 있는 파일들의 라인 개수
    file=$(ls)
    for f in $file; do
        echo $f
        line_num=$(cat $f | wc -l)
        echo $line_num
    done
}

#print_file_and_lines

num_a="10"
num_b=20
mul=$((3 * 5))
echo $mul
sum=$(($num_a + $num_b))
echo $sum

sum_from_1_to_n(){
    sum_result=0
    term=$(seq 10)
    for x in $term; do
        sum_result=$((sum_result + x))
    done
    echo $sum_result

}

sum_from_1_to_n

for_other(){
    for n in {a..z}; do
        echo $n
    done

    for n in {1..10}; do
        echo $n
    done
}

#for_other

test_cond() {
    sum=0
    for n in $(seq 100); do
        if [ $((n % 2)) -eq 0 ]; then
            sum=$((sum + n))
        else 
            sum=$sum
        fi
    done
    echo $sum
}

#test_cond

print_long_words_starting_with_c(){
    # print words that are longer than or equal 20
    words=$(cat /usr/share/dict/words | grep ^c)
    for w in $words; do
        #echo $w
        w_len=$(echo $w | wc -c)
        if [ $w_len -ge 20 ]; then
            echo $w $w_len
        fi
    done
}

print_long_words_starting_with_c

