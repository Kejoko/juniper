#!/bin/bash

# Ensure running in unix environment
if [[ "$OSTYPE" != "linux-gnu"* && "$OSTYPE" != "darwin"* ]]
then
  exit 1
fi

# Ensure CMake is installed

# Ensure make is installed

echo "... Building Juniper application ..."

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
  exit 4
}
{
  echo "... Running make ..."
  make
} || {
  echo "... make error ..."
  exit 5
}

cd ..
mv build/JuniperApp .

echo "... Successfully built Juniper application ..."
exit 0
