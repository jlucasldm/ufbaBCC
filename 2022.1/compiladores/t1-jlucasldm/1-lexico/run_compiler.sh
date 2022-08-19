#!/bin/bash
# run.sh
# parameters: input file name (.icl)

pathname=$(basename $(dirname $1 .icl))
name=$(basename $1 .icl)
./iclc < $1 > "./$pathname/$name.s"
