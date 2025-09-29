#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <ios>
#include <filesystem>
#include <vector>

void add (std::ifstream &file,std::filesystem::path &dir, std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){
    std::string word;

    while(file >> word){
    if(hash.find(word) != hash.end()){hash.at(word).back().second++; continue;}
                hash[word].push_back({dir.filename(),1});
}
    file.close();

}




void search (std::string &word,std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){ 
    //deal with exception later
  
    for(auto &s: hash.at(word)){
        std::cout<<"{"<<s.first.string()<<","<<s.second<<"}  ";
    }
   
    std::cout<<"\n";
}

void deletes (std::string &word,std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){
for(auto &k:hash){

    for(int i=0;i<k.second.size();i++){
        if(k.second.at(i).first.filename().string() == word) {k.second.erase(k.second.begin() + i); i--;}
    }

}

}


int main(){while(true){
    std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> hash;
    std::cout<<"Choose:\n1.Add file\n2.Search word\n3.Delete file\n4.Exit\n";
    int x;        std::string s;std::ifstream file;std::filesystem::path p;
    std::cin>>x;
    switch(x){
        case 1: 
            std::cout<<"Enter directory (or 0 to return):";
            std::cin>>s;
            if(!s.compare("0")) continue;
            file.open(s,std::ios::in);
            if(!file.is_open()){std::cout<<"File not found!\n";continue;}
            p = s;
            add(file,p,hash);
        break;

        case 2:
            std::cout<<"Enter word:\n";
            std::cin>>s;
            if(hash.find(s) ==hash.end()){ std::cout<<"Word not found!\n";continue;}
        break;

        case 3:
            std::cout<<"Enter file name with .txt:\n";
            std::cin>>s;
            deletes(s,hash);

        break;
}


}


return 0;}