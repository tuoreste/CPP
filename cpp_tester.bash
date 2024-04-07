#!/bin/bash

# Function to compile and run the C++ test
run_test() {
    filename="$1"
    testname="${filename%.*}"
    
    # Compile the C++ file with -std=c++98 flag
    g++ -std=c++98 "$filename" -o "$testname"

    # Check if compilation is successful
    if [ $? -eq 0 ]; then
        echo "Compilation successful for $filename"
        # Run the test
        ./"$testname"
        # Check if test passes
        if [ $? -eq 0 ]; then
            echo "Test passed: $testname"
            echo "ok"
        else
            echo "Test failed: $testname"
            echo "ko"
        fi
    else
        echo "Compilation failed for $filename"
        echo "ko"
    fi
}

# Main script starts here

# Embedded test 1
cat <<EOF > test1.cpp
#include <iostream>
int main() {
    std::cout << "Test 1 Passed!" << std::endl;
    return 0;
}
EOF

# Embedded test 2
cat <<EOF > test2.cpp
#include <iostream>
int main() {
    std::cout << "Test 2 Passed!" << std::endl;
    return 0;
}
EOF

# Embedded test 3
cat <<EOF > test3.cpp
#include <iostream>
int main() {
    std::cout << "Test 3 Passed!" << std::endl;
    return 1; // Intentionally failing this test
}
EOF

# Run tests
run_test test1.cpp
run_test test2.cpp
run_test test3.cpp

# Clean up temporary test files
rm -f test*.cpp test*.exe
