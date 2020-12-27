#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string houseArr[5][5] = {
    {"A","B","C","D","E"},
    {"1","1","1","1","1"},
    {"2","2","2","2","2"},
    {"3","3","3","3","3"},
    {"4","4","4","4","4"}
};

/*
    main -> shows array, asks for input
    parseInput -> checks user input
    checkWithArray -> checks if input exists in array
*/

void checkWithArray(std::string arrInput[]){
    
    bool letter = false, num = false;
    int letterIndex, numIndex;

    //check letter
    for(std::size_t i = 0; i < 5; i++){

        int x = arrInput[0].compare(houseArr[0][i]);

        if(x == 0){
            letter = true;
            letterIndex = i;
        }
    }

    //check number
    if(std::stoi(arrInput[1]) < 5){
        num = true;
        numIndex = (std::stoi(arrInput[1]));
    }

    if(letter && num){
        printf("%s", "\nExists\n");
    }else{
        printf("%s", "\nDoesn't exist\n");
    }
}

void parseInput(std::string input){
    
    std::string parsedInput[2];

    if(input.length() <= 2){
        for(size_t i = 0; i < input.length(); i++){
            parsedInput[i] = input[i];
        }

        checkWithArray(parsedInput);
    }else{
        std::cout << "\ninvalid input\n" << std::endl;
    }
}

int main(){

    for(std::size_t i = 0; i < 5; i++){
        for(std::size_t j = 0; j < 5; j++){
            std::cout << houseArr[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    std::string n;

    std::cout << "\nEx.: C2\n" << std::endl;
    std::cout << "Input: ";
    getline(std::cin, n);

    parseInput(n);

    return 0;
}
