// joinby.cpp by Isa Aguilar
#include <vector>
#include <iostream>

int main(int argc, char * argv[]){
    char const* joiner = argv[1]; // accepts any char*

    int len_of_joiner;
    for (int i = 0; joiner[i] != 0; ++i) {
        ++len_of_joiner;
    }

    std::vector<char> items;

    if (argc < 3) {
        // When less than three arguments, input from pipes are used as args
        std::string pipeInput;
        while (std::getline(std::cin,pipeInput)) {
            for (int i = 0; i < pipeInput.size(); ++i) {
                if (std::isspace(pipeInput[i])) {
                    for (int j = 0; j < len_of_joiner; ++j) {
                        items.push_back(joiner[j]);
                    }
                } else {
                    items.push_back(pipeInput[i]);
                }
            }
            for (int j = 0; j < len_of_joiner; ++j) {
                items.push_back(joiner[j]);
            }
        }
    } else {
        // At 3+ arguments, the command includes more than just a joiner and
        // will not read from piped inputs
        for (int i = 2; i < argc; ++i) {
            char * strptr = argv[i];
            for (int j = 0; strptr[j] > 0; ++j) {
                items.push_back(strptr[j]);
            }
            for (int j = 0; j < len_of_joiner; ++j) {
                items.push_back(joiner[j]);
            }
        }
    }

    // always ends in the joiner which must be removed
    for (int i = 0; i < len_of_joiner; ++i) {
        items.pop_back();
    }

    for (char i: items) std::cout << i;
    std::cout << std::endl;
    return 0;
}
