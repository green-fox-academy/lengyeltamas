#include<iostream>
#include<fstream>
#include<string.h>


int main()
{
    std::ifstream fin("usage.txt");
    int count=0;
    char ch[20],c[20];

    std::cout<<"Enter a word to count:";
    std::cin >> c;

    while(fin)
    {
        fin>>ch;
        if(strcmp(ch,c)==0)
            count++;
    }

    std::cout << "Occurrence = "<<count<<"\n";
    fin.close();

    return 0;
}