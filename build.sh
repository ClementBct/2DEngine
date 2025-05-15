#!/bin/bash

# Variables
BUILD_DIR="build"
GENERATOR="Unix Makefiles"

if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"
cmake .. -G "$GENERATOR"
cmake --build .
