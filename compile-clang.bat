wsl clang --version
wsl clang -Wall -Iinclude src/test_desc.cpp -lstdc++
wsl mv a.out test_desc.clang
wsl chmod +x test_desc.clang
wsl ./test_desc.clang -h -w60 -e
