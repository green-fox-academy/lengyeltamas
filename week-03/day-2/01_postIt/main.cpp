#include <iostream>
#include <string>


class postIt {
public:
    postIt (std::string a, std::string b, std::string c ) {
        backgroundColor = a;
        text = b;
        textColor = c;
    }

    std::string tostring () {
        std::string data = "background color: " + backgroundColor + " text: " + text + " text color: " + textColor + "\n";
        return data;
    };

private:
    std::string backgroundColor;
    std::string text;
    std::string textColor;
};

int main(int argc, char* args[]) {

    postIt orangePostIt ("orange", "Idea1", "blue");
    postIt pinkPostIt ("pink", "Awesome", "black");
    postIt yellowPostIt ("yellow", "Superb!", "green");

    std::cout << orangePostIt.tostring() << pinkPostIt.tostring() << yellowPostIt.tostring() << std::endl;
}