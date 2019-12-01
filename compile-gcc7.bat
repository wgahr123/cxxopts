wsl gcc-7 --version
wsl gcc-7 -Iinclude src/test_desc.cpp -lstdc++
wsl mv a.out test_desc.gcc7
wsl chmod +x test_desc.gcc7
wsl ./test_desc.gcc7 -h -w60 -e
