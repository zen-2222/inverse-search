#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <ios>
#include <filesystem>
#include <vector>

void add (std::ifstream &file,std::filesystem::path &dir, std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){
    std::string word; 

    while(file >> word){ bool z=1;
        if(hash.find(word) != hash.end()){
            for(auto &k: hash.at(word)){
                if(!k.first.filename().string().compare(dir.filename().string())) {k.second++;z=0; break;} //if pair is found increment counter and move on


            }
            
    
        }
        if(z) hash[word].push_back({dir.filename().string(),1}); // if the word exists but/or if the pair doesn't exist
    }
    file.close();

}




void search (std::string &word,std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){ 
  
    for(auto &s: hash.at(word)){
        std::cout<<"{"<<s.first.filename().string()<<","<<s.second<<"} ";  }
   
    std::cout<<"\n";
}

void deletes (std::string &word,std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> &hash){
for(auto &k:hash){

    for(int i=0;i<k.second.size();i++){
        if(k.second.at(i).first.filename().string() == word) {k.second.erase(k.second.begin() + i); i--;}
    }

}

}


int main(){  std::unordered_map <std::string, std::vector<std::pair <std::filesystem::path,int>>> hash;
 std::string s;std::ifstream file;std::filesystem::path p;
        int x;
        std::cout<<"Press any key to start\n";
    while(true){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Choose:\n1.Add file\n2.Search word\n3.Delete file\n4.Exit\n";

        std::cin>>x;
        if (x<1 || x>4 || std::cin.fail()){ std::cout<<"Command unrecognized \n";continue;}
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
                search(s,hash);
            break;

            case 3:
                std::cout<<"Enter file name with .txt:\n";
                std::cin>>s;
                deletes(s,hash);

            break;
        
            case 4:return 0;



        }



    }


return 0;}