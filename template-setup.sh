#!/bin/bash

read -p "Project command name (name of target and directory): " proj_command
if [ -d "../$proj_command" ]; then
	echo "Error: '../$proj_command' already exists"
	exit 1
fi

mkdir "../$proj_command"
git init "../$proj_command"
mkdir "../$proj_command/.github" || exit 1

cp_check() {
	if cp -r "$1" "../$proj_command"; then
		echo "Copied $1 to ../$proj_command"
	else
		echo "Failed to copy $1"
		exit 1
	fi
}
cp_check ./.clang-format
cp_check ./.git/description
cp_check ./.github/ISSUE_TEMPLATE
cp_check ./.gitignore
cp_check ./include
cp_check ./src
cp_check ./tests
cp_check ./CHANGELOG.md
cp_check ./CMakeLists.txt
cp_check ./CONTRIBUTING.md
cp_check ./Doxyfile
cp_check ./LICENSE
cp_check ./README.md

cd ../$proj_command

# find and replace recursively through new current directory
# 01PROJCMD with proj_command
# 01PROJTEMP with Human readable Project Name
# 01PROJDESC with Human readable Project Description
# 01PROJUPPER with Upper Case version of the proj_command or new prompt that asks them to type that. Whatever is easier



git add .
git commit -m "initial commit; copied template from tpalmerstudios/c-template"

echo "Project $proj_command set up successfully!"

