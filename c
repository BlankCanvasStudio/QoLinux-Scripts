#!/bin/bash
if [[ $file =~ \.gz$ ]]
then
   g++ $1 
  ./a.out
fi
