# Gorgo

## 1. What is Gorgo?
Gorgo is a WIP 3D Engine being made in C++ 

## 2. Building project


### 2.1 Using Premake
In order to generate the project using **Premake**, there is a script called `vs19_windows_build.bat` that generates a Visual Studio 2019 solution. If you want another VS version you can generate it using premake as follows in the main directory (where *premake5.lua* is located)

```bash
dependencies\bin\premake5\premake5.exe vs2019 #vs2015, gmake, xcode4..
```

The possible options are listed here [premake actions](https://github.com/premake/premake-core/wiki/Using-Premake).

### 2.2 Using CMake
To build this project at least **CMake 3.18.3** is required. Actually only windows visual studio solution projects are supported.

Open a command line in main directory where `CMakeLists.txt` is located.

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" #15 2018, 14 2017...
```



---
## 3. Coding Style

* Interfaces starts by `I`
* Abstracts starts by `A`
* Class names: `UpperCamelCase`
* Public member variables: `lowerCamelCase`
* Private member variables: `m_lowerCamelCase`
* Public static variables: `UpperCamelCase`
* Private static variables: `_CAPS_LOCK_WITH_UNDERSCORES`
* Function/Method arguments: `p_lowerCamelCase`
* Function/Method names: `UpperCamelCase`
* Class member variables are located on file bottom
* Comment the functions, enums, classes, methods ([Javadoc style](https://en.wikipedia.org/wiki/Javadoc))

