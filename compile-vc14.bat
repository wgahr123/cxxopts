setlocal
call "%VS140COMNTOOLS%..\..\VC\bin\amd64\vcvars64.bat"
cl /EHsc -Iinclude src\test_desc.cpp
ren test_desc.exe test_desc.vc14.exe
test_desc.vc14.exe -h -w60 -e
