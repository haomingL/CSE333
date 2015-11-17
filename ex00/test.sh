#!/bin/bash
# Haoming Liu
# 1332998
# haoming@cs.washington.edu
if ./true; then
    echo Success
else
    echo Failure
fi

if ! ./false; then
    echo Success
else
    echo Failure
fi
