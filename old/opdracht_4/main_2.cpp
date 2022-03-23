
#include <vector>
#include <iostream>
#include <string>

#include "fileReader.hpp"

int main(void) {

    std::cout << "==== READING 'kingjamesbible.txt' ====" << std::endl;

    std::string filePath = "kingjamesbible.txt";
    FileReader reader(filePath);

    // Read all chars in file to vector
    std::vector<char> allChars = reader.file_chars_to_vector();
    std::cout << "=>\t" << allChars.size() << " total chars" << std::endl << std::endl;

    // Read total lines of file
    std::vector<std::string> allLines = reader.file_lines_to_vector();
    std::cout << "=>\t" << allLines.size() << " total lines" << std::endl << std::endl;

    // Read chars to alphabetical order
    int alphabetCount = reader.file_count_alphabet_chars();
    std::cout << "=>\t" << alphabetCount << " total alphabet chars" << std::endl << std::endl;

    // Convect vector to lower chars
    std::vector<char> alphaChars = reader.file_alphabet_chars_to_vector();
    reader.char_vector_to_lower(alphaChars);

    // Count every char in vector
    std::map<char, int> charMap = reader.file_map_count_of_chars( alphaChars );

    // Print char counter map
    for( auto & c : charMap ){
        std::cout << "=>\t'" << c.first << "' : " << c.second << " in char map" << std::endl;
    }

    std::cout << std::endl;

    // Top 10 most found words in file
    std::map<std::string, int> topWordsMap = reader.file_top_words();

    int counter = 1;
    for( auto & c : topWordsMap ){
        std::cout << "=>\t" 
        << "#" << counter << " : '"
        << c.first << "' -> " << c.second << " times" 
        << std::endl;

        counter++;
    }

    std::cout << std::endl;
    std::cout << "======================================" << std::endl;

}