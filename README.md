# Gorgo

## Building project


To build this project at least **CMake 3.18.3** is required. Actually only windows visual studio solution projects are supported.

Open a command line in main directory where `CMakeLists.txt` is located.

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" #15 2018, 14 2017...
```
---
## Building Gorgo


---
## Coding Style

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

