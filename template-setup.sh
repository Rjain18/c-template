#!/bin/bash

read -p "Project command name (name of target and directory): " proj_command
if [ -d "../$proj_command" ]; then
	echo "Error: '../$proj_command' already exists"
	exit 1
fi

mkdir "../$proj_command"
git init "../$proj_command"
