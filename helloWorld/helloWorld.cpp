//Daniel Esparza Arizpe - a01637076
//Lunes 7 de agosto

#include <iostream>

int main(){
    std::string name;
    std::cout<<"Dame tu nombre"<<std::endl;
    std::cin>>name;
    int len = name.size();
    std::cout<<"Hi! " << name <<", your name has " << len << " characters"<<std::endl;

}