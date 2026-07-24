#!/bin/bash

processed=0
duplicates=0
backedup=0

> report.txt
> errors.log
> seen_checksums.txt

for file in submissions/*
do
    if [ -f "$file" ]
    then
        processed=$((processed + 1))

        checksum=$(md5sum "$file" 2>>errors.log | cut -d " " -f1)

        if grep -q "$checksum" seen_checksums.txt
        then
            duplicates=$((duplicates + 1))
        else
            echo "$checksum" >> seen_checksums.txt
            cp "$file" backup/ 2>>errors.log
            backedup=$((backedup + 1))
        fi
    fi
done

echo "Files processed : $processed" > report.txt
echo "Duplicate files : $duplicates" >> report.txt
echo "Files backed up : $backedup" >> report.txt
