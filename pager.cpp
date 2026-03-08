#include <iostream>
#include <string>

int main () {

    std::string phrase;

    while (std::getline(std::cin, phrase)) {

        std::cout << phrase << std::endl;

    }

    return 0;

}