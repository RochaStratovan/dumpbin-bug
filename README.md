# Problem

`dumpbin /dependents` only shows direct dependents. It does not show grandchild dependents

This is a simplified program to illustrate the problem.

## Program Architecture

1. Executable 'TheProgram` uses `Child.dll`
1. `Child.dll` uses `GrandChild.dll`
1. `GrandChild.dll` doesn't depend upon any other dlls

## Steps

### Create the Visual Studio Files from CMake

Using VS2022 for a 64bit build create the Visual Studio solution in the Build
folder.

``` cmake
mkdir build
cmake . -BBuild -G"Visual Studio 17 2022" -A x64
```

### Open the solution with Visual Studio

``` dos
start Build\TheProgram.sln
```

### Compile the solution using Visual Studio GUI

### Open the Visual Studio Command Prompt Shell

### Copy the generated DLL files to the EXE folder

From the VS Command Prompt shell

``` dos
copy lib1\Debug\Child.dll app\Debug
copy lib2\Debug\GrandChild.dll app\Debug
```

### Validate the program runs

From the VS Command Prompt shell

``` dos
app\Debug\TheProgram.exe
```

## use Dumpbin on the program to view dependencies

The final step is to use dumpbin on the progrm to view dependnecies. Observe that it only shows the child dependencies, and doesn't show any grandchild dependnecies.

``` dos
dumpbin /dependents app\Debug\TheProgram.exe




Microsoft (R) COFF/PE Dumper Version 14.37.32824.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file app\Debug\TheProgram.exe

File Type: EXECUTABLE IMAGE

  Image has the following dependencies:

    Child.dll
    VCRUNTIME140D.dll
    ucrtbased.dll
    KERNEL32.dll

  Summary

        1000 .00cfg
        1000 .data
        1000 .idata
        1000 .pdata
        3000 .rdata
        1000 .reloc
        1000 .rsrc
        8000 .text
```
