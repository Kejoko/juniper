#!/bin/bash

# Ensure running in linux environment
if [[ "$OSTYPE" != "linux-gnu"* && "$OSTYPE" != "darwin"* ]]
then
  exit 1
fi

echo "... Building Juniper application ..."

# Check if CMake is installed

# Check if make is installed

# Create build directory
if [ ! -d build ]
then
  echo "... Creating build directory ..."
  mkdir build
else
  echo "... build directory exists ..."
fi
cd build

# CMake and make to build the Juniper application
{
  echo "... Running CMake ..."
  cmake ..
} || {
  echo "... CMake error ..."
  exit 2
}
{
  echo "... Running make ..."
  make
} || {
  echo "... make error ..."
  exit 3
}

cd ..
mv build/JuniperApp .

echo "... Successfully built Juniper application ..."
exit 0
