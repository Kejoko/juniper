#!/bin/bash
# Build the Juniper application using CMake and make
echo "... Building Juniper application ..."

# Check if CMake is installed

# Check if make is installed

# Check if bin directory exists
if [ ! -d bin ]
then
  echo "... Creating bin directory ..."
  # Create bin directory
  mkdir bin
else
  echo "... bin directory exists ..."
fi

# CMake and make to build the Juniper application
cd bin
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

echo "... Successfully built Juniper application ..."
exit 0
