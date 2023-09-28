#!/bin/bash

# directory where the backup will be saved
bdir=backup_directory

# prompting the user for a directory
read -p "Enter the name of the directory you want to backup: " dir

current_date=$(date +"%Y-%m-%d")

newname="backup_of_${dir}_${current_date}"

cp -r $dir "${bdir}/${newname}"
