@echo off
:: Ensure running in widnows environment

:: Ensure CMake is installed

:: Ensure if make is installed

echo ... Building Juniper application ...

:: Create build folder
:build_folder
echo ... Creating build folder ...
if exist $0\..\..\build (
  echo ... build folder exists ...
  goto cmake
)
mkdir $0\..\..\build

:: CMake and make to build the Juniper application
:cmake
cd ..\build
echo ... Running CMake ...
cmake ..
if %ERRORLEVEL% neq 0 (
  echo ... CMake error ...
  goto end
)
:make
echo ... Running make ...
make
if %ERRORLEVEL% neq 0 (
  echo ... make error ...
)
goto end

:end
pause
