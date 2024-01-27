#! /usr/bin/bash

echo "cd @PROJECT_BINARY_DIR@ || exit"
cd @PROJECT_BINARY_DIR@ || exit

echo "@KTEST_RUN_UTEST_INVOKER@ @path@ @run_utest_args@ | tee test_output/@target@.out.txt"
@KTEST_RUN_UTEST_INVOKER@ @path@ @run_utest_args@ | tee test_output/@target@.out.txt

utest_exit_code=${PIPESTATUS[0]}

if [ $utest_exit_code -eq 0 ]; then
    echo "Running utest target @target@ succeeded"
else
    echo "Running utest target @target@ failed"
fi
