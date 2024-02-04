#!/bin/bash

RED="\e[0;31m"
GREEN="\e[0;32m"
YELLOW="\e[0;33m"
ESC="\e[0m"

MAIN_BIN=main
CC=g++
ERROR="${RED}ERROR:${ESC}"
TEST_TMP=judge_test_tmp.txt

if [ $# != 1 ]; then
    echo -e "${ERROR} Parameter missing."
    exit
elif [ ! -f "$1" ]; then
    echo -e "$ERROR File not found."
    exit
else
    if [ -f MAIN_BIN ]; then
        rm MAIN_BIN
    fi
    
    $CC -o $MAIN_BIN "$1"

    if [ ! -f $MAIN_BIN ]; then
        echo -e "$ERROR Compilation Error."
        echo ;
        exit
    fi
fi

N=0
TEST_CNT=$(ls -1q tests/in/ | wc -l)

for (( i=1 ; i<=TEST_CNT ; i++ ))
do
    echo "==== Test $i/$TEST_CNT ===="
    ./$MAIN_BIN < "tests/in/input$i.txt" 1> $TEST_TMP
    diff -w $TEST_TMP tests/out/output$i.txt

    if [ $? -eq 1 ]; then
        echo -e "${RED}FAIL${ESC}"
    else
        N=$(( N+1 ))
        echo -e "${GREEN}PASS${ESC}"
    fi
done

rm -f $TEST_TMP $MAIN_BIN

if [[ $N -eq $TEST_CNT ]]; then
    echo -e "${GREEN}All tests passed.${ESC}"
else
    echo -e "${RED}Some failed tests ($((TEST_CNT-N))/$TEST_CNT)${ESC}"
fi