#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <fstream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

class FileReader {
private:
    std::ifstream file;
    std::string   filePath;

public:

    FileReader( std::string & path ):
        filePath( path )
    {};

    std::vector<char> file_chars_to_vector(){

        file.open(filePath);

        char tmpChar;
        std::vector<char> charVector;

        while(file.get(tmpChar)){
            charVector.push_back(tmpChar);
        }

        file.close();
        return charVector;
    }

    std::vector<std::string> file_lines_to_vector(){

        file.open(filePath);

        std::string tmpString;
        std::vector<std::string> stringVector;

        while (!file.eof()){
            std::getline(file, tmpString);
            stringVector.push_back(tmpString);
            tmpString.clear();
        }

        file.close();
        return stringVector;

    }

    std::vector<std::string> file_words_to_vector(){

        file.open(filePath);

        std::vector<std::string> stringVector;
        std::string tmpString;

        while (!file.eof()){
            file >> tmpString;
            stringVector.push_back(tmpString);
            tmpString.clear();
        }

        file.close();
        return stringVector;
    }

    int file_count_alphabet_chars(){

        int count = 0;
        std::vector<char> allChars = file_chars_to_vector();

        for( auto & c : allChars ){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){ count++; }

        }

        return count;

    }

    std::vector<char> file_alphabet_chars_to_vector(){

        std::vector<char> alphaChars;
        std::vector<char> allChars = file_chars_to_vector();

        for( auto & c : allChars ){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){ alphaChars.push_back(c); }
        }

        return alphaChars;

    }

    char char_to_lower( char & c ){
        (c >= 'A' && c <= 'Z') ? (c -= 32) : c;
        return c;
    }

    std::string string_to_lower( std::string & s ){

        for( auto c : s ){
            char_to_lower(c);
        }

        return s;

    }

    void char_vector_to_lower( std::vector<char> & charVector ){
        
        for(auto & c : charVector){
            char_to_lower(c);
        }

    }

    std::map<char, int> file_map_count_of_chars( std::vector<char> & charVector ){

        char alphaLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        std::map<char, int> alphaMap;

        for( auto letter : alphaLetters ){
            alphaMap[letter] = 0;
        }

        for( auto & c : charVector ){

            for( auto letter : alphaLetters ){
                if( letter == char_to_lower(c) ){ alphaMap[letter] += 1; }
            }

        }

        return alphaMap;

    }   

    std::map<std::string, int> file_top_words(){
        
        std::map<std::string, int> mapAllWords;
        std::vector<std::string> vecWords = file_words_to_vector();

        for (auto & word : vecWords){

            for (auto & letter : word){

                if (!((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))){
                    word.erase(std::remove(word.begin(), word.end(), letter), word.end());
                }

            }

        }

        for (auto & word : vecWords){
            string_to_lower(word);
            mapAllWords[word] = 0;
        }

        for (auto &word : vecWords){

            auto found = mapAllWords.find(word);

            if (found != mapAllWords.end()){
                mapAllWords[word] += 1;
            }

        }

        std::map<int, std::string> topWordsReversed;

        for( auto & item : mapAllWords ){
            topWordsReversed[item.second] = item.first;
        }

        auto value = topWordsReversed.rend();
        std::map<std::string, int> topWords;

        for( int i = 0; i < 10; i++ ){
            value++;
            topWords[value->second] = value->first;
        }
    
        return topWords;

    }



};


#endif //FILEREADER_HPP