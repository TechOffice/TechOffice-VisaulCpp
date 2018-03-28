cl.exe is a C/C++ compiler shipped with Visual Studio. In general, It is placed in C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin. You can set the Path of system variable to include it. Then you can use it in the command prompt.

```
cl.exe
```

```
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin>cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24215.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```


**hello.cpp**
```
#include <iostream>  
using namespace std;  
void main()  
{  
    cout << "Hello, world, from Visual C++!" << endl;  
}  

```

Because this code include iostream library. so it requires to pass parameter of library path to cl.exe by /I <library path>. In general, the standard library path is in C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include.

```
cl.exe \I C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include hello.cpp
```