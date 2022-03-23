#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {

    std::ifstream file;
    std::string filePath = "kingjamesbible.txt";

    // STEP 1: Read all chars from file to vector
    file.open(filePath);

    char tmpChar;
    std::vector<char> allChars;

    while(file.get(tmpChar)){
        allChars.push_back(tmpChar);
    }

    file.close();

    // STEP 2: Print amount of chars of file
    std::cout << "=>\t" << allChars.size() << " total chars" << std::endl;

    // STEP 3: Print amount of lines of file
    std::cout << "=>\t" << (std::count(allChars.begin(), allChars.end(), '\n') + 1) << " number of lines" << std::endl;

    // STEP 4: Print amount of alfabetical chars of file
    int alphabetCount = 0;

    for(auto & c : allChars){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){ alphabetCount++; }
    }

    std::cout << "=>\t" << alphabetCount << " total alphabet chars" << std::endl << std::endl;

    // STEP 5: Transform all uppercase chars to lowercase chars
    std::transform(allChars.begin(), allChars.end(), allChars.begin(), ::tolower);

    // STEP 6: Make a list for the count of every char within the vector
    char currentChar = 'a';
    std::map<char, int> alphaMap;

    for(int i = 0; i <= 25; i++){
        alphaMap.insert({currentChar + i, 0});
    }

    for(auto & c: allChars){
        if(c >= 'a' && c <= 'z'){

            auto charPos = alphaMap.find(c);

            if(charPos != alphaMap.end()){
                alphaMap[c] += 1;
            }

        }
    }

    // STEP 7: Print list of count score of char vector
    auto lambdaMapCharCmp = [](std::pair<char, int> & x, std::pair<char, int> & y){return x.second < y.second;};

    std::cout << "ALPHABETICAL ORDER" << std::endl;
    std::cout << "================================" << std::endl;

    // Alphabetical order
    std::cout << "=>\tCHAR\tSCORE" << std::endl;

    for(auto & c: alphaMap){
        std::cout << "=>\t'" << c.first << "'\t" << c.second << std::endl;
    }

    std::cout << std::endl;

    // Score order
    std::cout << "SCORE ORDER" << std::endl;
    std::cout << "================================" << std::endl;

    std::vector<std::pair<char, int>> scoreVector;
    for(auto & c: alphaMap){
        scoreVector.push_back(c);
    }

    std::sort(scoreVector.begin(), scoreVector.end(), lambdaMapCharCmp);

    std::reverse(scoreVector.begin(), scoreVector.end());
    std::cout << "=>\tCHAR\tSCORE" << std::endl;
    for(auto & c: scoreVector){
        std::cout << "=>\t'" << c.first << "'\t" << c.second << std::endl;
    }

    std::cout << std::endl;

    // STEP 8: Create Top 10 of words
    auto lambdaMapStringCmp = [](std::pair<std::string, int> & x, std::pair<std::string, int> & y){return x.second < y.second;};

    std::map<std::string, int> mapAllWords;
    std::vector<std::string> allWords;
    std::string tmpString;

    // Collect the words from file
    file.open(filePath);

    while(!file.eof()){
        file >> tmpString;
        allWords.push_back(tmpString);
        tmpString.clear();
    }

    file.close();

    // Remove the chars that aren't within the alphabet (neither lower- and uppercase)
    for(auto & word : allWords){
        for(auto & c : word){
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))){
                word.erase(std::remove(word.begin(), word.end(), c), word.end());
            }
        }

        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    
    // Fill map with all words
    for(auto & word : allWords){
        mapAllWords.insert({word, 0});
    };

    // Set the score for each word within the map
    for(auto & word: allWords){
        auto found = mapAllWords.find(word);

        if(found != mapAllWords.end()){
            mapAllWords[word] += 1;
        }
    }

    // Create a top 10 map
    std::vector<std::pair<std::string, int>> scoreWordsVector;

    for(auto & word: mapAllWords){
        scoreWordsVector.push_back(word);
    }

    std::sort(scoreWordsVector.begin(), scoreWordsVector.end(), lambdaMapStringCmp);
    std::reverse(scoreWordsVector.begin(), scoreWordsVector.end());

    // Show the result
    std::cout << "TOP 10 WORDS" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "#\tWORD\tCOUNT" << std::endl;

    int counter = 1;
    for(int i = 0; i < 10; i++){
        std::cout << counter << "\t"
        << scoreWordsVector[i].first << "\t"
        << scoreWordsVector[i].second << std::endl;
        counter++;
    }

    std::cout << std::endl;

}