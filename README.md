# ReWIND

ReWIND is a simple __WIP__ schedule management app built with Qt Quick and C++.

## Requirements

- CMake 3.16 or later
- A C++23 compiler
- Qt 6.12 or later, including Qt Quick and Qt SQL with the SQLite driver

## Build and run

```sh
cmake -S . -B build
cmake --build build
./build/appReWIND
```

If CMake cannot find Qt, set `CMAKE_PREFIX_PATH` to your Qt installation directory when configuring.

## License

GPLv3 license.\
See [LICENSE](LICENSE) for more details.
