clear
if [[ $1 == "re" ]]
then
    echo "------------RE-BUILD"------------
    rm -rf ./build/ ./ECS.a
    mkdir ./build/ && cd ./build/
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    cmake --build .
    cd ..
    echo "------------END------------"

elif [[ $1 == "d" ]]
then
    echo ""------------DEBUG"------------"
    rm -rf ./build/ ./ECS.a
    mkdir ./build/ && cd ./build/
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
    cmake --build . -v
    cd ..
    echo "------------END------------"

elif [[ $1 == "c" ]]
then
    echo "------------CLEAR------------"
    rm -rf ./build/ ./ECS.a
    echo "------------END------------"

else
    echo "------------BUILD------------"
    if [ ! -d "./build/" ]
    then
        mkdir ./build/ && cd ./build/
        cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
        cd ..
    else
        cmake --build ./build/
    fi
    echo "------------END------------"
fi
