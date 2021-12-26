#! /bin/bash

EXEC='./megaphone'

make > /dev/null
$EXEC $@
