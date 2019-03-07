#!/bin/env bash
ls apps src tests plugins CMakeLists.txt | grep -E "(h|.cpp|.txt)\$" | entr -d "./build.sh"
