#!/bin/sh

# クリーンアップ関数
cleanup() {
	rm -f result_expected result_user test_user test_expected
}
trap cleanup EXIT

make all
if ! make all; then
	echo "Error: Failed to build libft"
	exit 1
fi

cc -g test.c -DFT -o test_user -L. -lft -L/usr/lib/x86_64-linux-gnu -lbsd
if ! cc -g test.c -DFT -o test_user -L. -lft -L/usr/lib/x86_64-linux-gnu -lbsd; then
	echo "Error: Failed to build test_user"
	exit 1
fi

./test_user > result_user
if ! ./test_user > result_user; then
	echo "failed to execute, exit code:$?"
	echo "'cat result_user' to show output"
	exit 1
fi

if valgrind -q ./test_user > result_user; then
	cc -g test.c -lbsd -o test_expected
	if ! cc -g test.c -lbsd -o test_expected; then
		echo "Error: Failed to build test_expected"
		exit 1
	fi
	
	./test_expected > result_expected
	if ! ./test_expected > result_expected; then
		echo "Error: test_expected failed to execute, exit code: $?"
		exit 1
	fi
	
	echo "=====RESULT====="
	if diff -a -U 3 result_expected result_user; then
		echo "no diff found"
	else
		echo "=====RESULT====="
		echo "diff found"
		echo "'cat result_expected' to show expected result"
		echo "'cat result_user' to show user result"
		exit 1
	fi
else
	echo "failed to execute, exit code:$?"
	echo "'cat result_user' to show output"
	exit 1
fi
