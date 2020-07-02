#!/bin/bash

# Ensure running in unix environment
if [[ "$OSTYPE" != "linux-gnu"* && "$OSTYPE" != "darwin"* ]]
then
  exit 1
fi

# Ensure CMake is installed

# Ensure make is installed

echo "... Building Juniper Engine ..."

# Create build directory
if [ ! -d build ]
then
  echo "... Creating build directory ..."
  mkdir build
else
  echo "... build directory exists ..."
fi
cd build

# CMake and make to build Juniper Engine
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
mv build/JuniperEngine .

echo "... Successfully built Juniper Engine ..."
exit 0
