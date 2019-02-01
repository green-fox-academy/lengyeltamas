#include <iostream>

class postit {

public:
    postit (std::string a, std::string b, std::string c) {
        backgroundcolor = a;
        text = b;
        textcolor = c;
    }

    std::string tostring () {
        std::string data = "background color is: " + backgroundcolor + " text: " + text + " text color: " + textcolor + "\n";
        return data;
    };

private:
    std::string backgroundcolor;
    std::string text;
    std::string textcolor;
};


int main() {

    postit postit1 ("orange", "Idea 1", "blue");
    postit postit2 ("pink", "Awesome", "black");
    postit postit3 ("yellow", "Superb!", "green");

    std::cout << postit1.tostring() << postit2.tostring() << postit3.tostring() << std::endl;

    return 0;
}