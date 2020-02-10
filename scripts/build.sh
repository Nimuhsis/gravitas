#!/bin/bash

PROJECT_NAME="$(grep -oh 'project([A-Za-z]\+' CMakeLists.txt | awk -F'(' '{print $2}')"

echo "Project Name = ${PROJECT_NAME}"

cd bin

target_release() {
	cd release
	cmake -DCMAKE_BUILD_TYPE=Release ../..
	make

	if [ $? -eq 2 ]
	then
		echo "\e[1m\e[31mFailed at Compilation\e[0m"
		exit
	fi

	echo "Built ${PROJECT_NAME} in bin/release/"
	./${PROJECT_NAME}
}

target_debug() {
	cd debug
	cmake -DCMAKE_BUILD_TYPE=Debug ../..
	make

	if [ $? -eq 2 ]
	then
		echo "\e[1m\e[31mFailed at Compilation\e[0m"
		exit
	fi

	echo "Built ${PROJECT_NAME} in bin/debug/"
	./${PROJECT_NAME}
}

if [ "$1" = "release" ]
then
	target_release
elif [ "$1" = "run" ]
then
	target_release
	./"${PROJECT_NAME}" 
elif [ "$1" = "both" ]
then
	target_release
	target_debug
else
	target_debug
fi
