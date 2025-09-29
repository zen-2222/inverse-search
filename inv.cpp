#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <ios>
#include <filesystem>
#include <vector>

void add (std::ifstream file,std::filesystem::path &dir, std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){
    std::string word;
    file.open(dir,std::ios::in);

    while(file >> word){
    if(hash.find(word) != hash.end()){hash.at(word).back().second++; continue;}
                hash[word].push_back({dir.filename(),1});
}
    file.close();

}




void search (std::string &word,std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){ 
    //deal with exception later
  
    for(auto &s: hash.at(word)){
        std::cout<<"{"<<s.first<<","<<s.second<<"}  ";
    }
   
    std::cout<<"\n";
}

void deletes (std::string &word,std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){
for(auto &k:hash){

    for(int i=0;i<k.second.size();i++){
        if(k.second.at(i).first.filename() == word) {k.second.erase(k.second.begin() + i); i--;}
    }

}

}


