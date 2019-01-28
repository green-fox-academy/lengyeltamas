#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(int argc, char* args[]) {

    std::map<std::string, std::string> tree01;
    tree01.insert(std::make_pair("type", "pine"));
    tree01.insert(std::make_pair("leaf color", "evergreen"));
    tree01.insert(std::make_pair("age", "two"));
    tree01.insert(std::make_pair("sex", "male"));

    std::map<std::string, std::string> tree02;
    tree02.insert(std::make_pair("type", "walnut"));
    tree02.insert(std::make_pair("leaf color", "dark green"));
    tree02.insert(std::make_pair("age", "twenty"));
    tree02.insert(std::make_pair("sex", "female"));

    std::map<std::string, std::string> tree03;
    tree03.insert(std::make_pair("type", "oak"));
    tree03.insert(std::make_pair("leaf color", "light green"));
    tree03.insert(std::make_pair("age", "ninety"));
    tree03.insert(std::make_pair("sex", "male"));

    std::map<std::string, std::string> tree04;
    tree04.insert(std::make_pair("type", "pear"));
    tree04.insert(std::make_pair("leaf color", "light green"));
    tree04.insert(std::make_pair("age", "fifteen"));
    tree04.insert(std::make_pair("sex", "female"));

    std::map<std::string, std::string> tree05;
    tree05.insert(std::make_pair("type", "apple"));
    tree05.insert(std::make_pair("leaf color", "mid green"));
    tree05.insert(std::make_pair("age", "seventeen"));
    tree05.insert(std::make_pair("sex", "male"));

    return 0;
}