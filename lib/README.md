# *\lib\README.md

using jsoncpp lib and gflags lib

* 2022.10.11 link jsoncpp static lib

compiled by mingw32-make from jsoncpp-src 1.9.5 (https://github.com/open-source-parsers/jsoncpp/releases/tag/1.9.5)

linked .lib\jsoncpp\lib\libjsoncpp.a and libjsoncpp.dll.a in .\CMakeLists.txt

* 2022.10.13 link gflags static lib

compiled by mingw32-make from gflags-src 2.2.2 (https://github.com/gflags/gflags/releases/tag/v2.2.2)

use find_package in .\CMakeLists.txt

* 2022.10.13 link CSerialPort static lib

compiled by mingw32-make from CSerialPort-src 4.2.0 (https://github.com/itas109/CSerialPort/releases/tag/v4.2.0)

linked .\lib\CSerialPort\lib\liblibcserialport.dll.a in .\CMakeLists.txt