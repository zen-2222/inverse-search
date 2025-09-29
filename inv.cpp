#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <ios>
#include <filesystem>
void addfile (std::ifstream file,std::filesystem::path dir, std::unordered_map <std::string, std::pair<std::filesystem::path,int>> &hash){
    std::string word;
    file.open(dir,std::ios::in);

    while(file >> word){

        if(hash.find(word) == hash.end()){ //if word unexists we create it
            hash[word] = {dir.filename(),0};}

        else{hash.at(word).second++;} // else increment the counter

    }
    file.close();
}