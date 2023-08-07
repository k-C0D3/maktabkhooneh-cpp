#include <iostream>
#include <string>

std::string centerAlign(const std::string& sentence) {
    int sentenceLength = sentence.length();
    if (sentenceLength >= 20) {
        return sentence;
    } else {
        int paddingLength = (20 - sentenceLength) / 2;
        std::string padding(paddingLength, ' ');
        std::string centeredSentence = padding + sentence + padding;
        return centeredSentence;
    }
}

int main() {
    std::string inputSentence;
    std::cout << "Please enter a short sentence:  ";
    std::getline(std::cin, inputSentence);
    std::string centeredSentence = centerAlign(inputSentence);
    std::cout << centeredSentence << std::endl;

    return 0;
}