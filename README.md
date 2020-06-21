# Juniper
A platform independent 3D physics game engine.

### Dependencies
This project is dependent upon some libraries.
* [CMake](https://cmake.org/download/) command line tools (version 3.17) - Required (linux/mac/windows)
  * NOTE: If you are planning on using Visual Studio 2019, CMake version 3.17 is already installed for the IDE
* GCC - Required (linux/mac), Recommended (windows)
  * On mac with [homebrew](https://brew.sh/) installed, run the command ```brew install gcc``` in terminal
  * On windows this is [MinGW](http://www.mingw.org/), [here](https://www.youtube.com/watch?v=sXW2VLrQ3Bs&t=32s) is a helpful video on installation
* [Gnu Make](https://www.gnu.org/software/make/) - Required (linux/mac), Recommended (windows)
  * Should be installed by default on linux/mac
  * [Here](http://gnuwin32.sourceforge.net/packages/make.htm) is helpful page for windows installation

### Setting up and building Juniper/JuniperApp
#### Linux/Mac
1. Clone the Juniper repository to your desired destination on your drive
1. Open terminal or your preferred command line interface
1. cd into the Juniper directory, wherever you cloned it
1. In your command line interface run the command ```./scripts/build-unix.sh```
1. Run the JuniperApp executable in the Juniper directory
#### Windows
##### Using GCC
1. Ensure you have all of the dependencies installed
1. Clone the Juniper repository to your desired destination on your drive
1. Double click the ```build-windows.bat``` file in the scripts folder to run it
1. Run the JuniperApp executable in the Juniper folder
##### Using Visual Studio
1. I'm really not sure how to use the Visual Studio (or other IDEs) with cmake
