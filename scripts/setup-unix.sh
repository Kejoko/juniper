#!/bin/bash

# Ensure running in unix environment
if [[ "$OSTYPE" != "linux-gnu"* && "$OSTYPE" != "darwin"* ]]
then
  exit 1
fi

echo "... Installing Juniper dependencies ..."

# Install deps for mac
if [[ "$OSTYPE" == "darwin"* ]]
then
  echo "... Installing Homebrew ..."
  {
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
  } || {
    echo "... Failed Homebrew installation ..."
    exit 1
  }
  echo "... Homebrew installation successful ..."
  
  echo "... Installing CMake ..."
  {
    brew install cmake
  } || {
    echo "... Failed CMake installation ..."
    exit 2
  }
  echo "... CMake installation successful"
fi
echo "... Successfully installed all dependencies ..."
exit 0

# Install deps for linux
if [[ "$OSTYPE" == "linux-gnu"* ]]
then
  echo "... Installing CMake ..."
  {
    sudo apt-get -y install cmake
  } || {
    echo "... Failed CMake installation ..."
    exit 2
  }
  echo "... CMake installation successful ..."
fi
echo "... Successfully installed all dependencies ..."
exit 0
