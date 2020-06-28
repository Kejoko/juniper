# Juniper
A platform independent 3D physics game engine.

### Setting up and building Juniper/JuniperApp
#### Linux/Mac
1. Clone the Juniper repository to your desired destination on your drive
1. Open terminal or your preferred command line interface
1. cd into the Juniper directory, wherever you cloned it
1. In your command line interface run the command ```./scripts/setup-unix.sh```
   * Mac: This script will attempt to install [Homebrew](https://brew.sh/) and [CMake](https://cmake.org/)
   * Linux: This script will attempt to install [CMake](https://cmake.org/)
1. In your command line interface run the command ```./scripts/build-unix.sh```
1. Run the JuniperApp executable in the Juniper directory
#### Windows
##### Using Visual Studio
1. Ensure you have the [Visual Studio IDE](https://visualstudio.microsoft.com/vs/) installed
1. Clone the Juniper repository to your desired destination on your drive
1. Open the Juniper folder in file explorer
1. With the Juniper folder opened, right click in the file explorer window and select ```Open in Visual studio```
   * Visual Studio will automatically run CMake to create the build environment and open the Juniper folder in the Solution Explorer
1. Double click the CMakeLists.txt, in the top level Juniper folder, in the Solution Explorer to open it for editing
   * To make this easier for the future, right click on the top level CMakeLists.txt in the Solution Explorer and click ```Set as Startup Item```.
  This will allow you to build the application while the top level CMakeLists.txt isn't opened.
1. Press the ```F5``` key to run the application
