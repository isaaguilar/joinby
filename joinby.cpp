// joinby.cpp by Isa Aguilar
#include <vector>
#include <iostream>

int main(int argc, char * argv[]){
    char * joiner = argv[1]; // only a single char is accepted
    std::vector<char> items;

    if (argc < 3) {
        // When less than three arguments, input from pipes are used as args
        std::string pipeInput;
        while (std::getline(std::cin,pipeInput)) {
            for (int i = 0; i < pipeInput.size(); ++i) {
                if (std::isspace(pipeInput[i])) {
                    items.push_back(*joiner);
                } else {
                    items.push_back(pipeInput[i]);
                }
            }
            items.push_back(*joiner);
        }
    } else {
        // At 3+ arguments, the command includes more than just a joiner and
        // will not read from piped inputs
        for (int i = 2; i < argc; ++i) {
            char * strptr = argv[i];
            for (int j = 0; strptr[j] > 0; ++j) {
                items.push_back(strptr[j]);
            }
            items.push_back(*joiner);
        }
    }
    items.pop_back(); // always ends in the joiner
    for (char i: items) std::cout << i;
    std::cout << std::endl;
    return 0;
}
