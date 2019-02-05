#include <iostream>

class postit {

public:
    postit (std::string backgroundcolor, std::string text, std::string textcolor) {
        _backgroundcolor = backgroundcolor;
        _text = text;
        _textColor = textcolor;
    }

    std::string tostring () {
        std::string data = "PostIt with " + _backgroundcolor + " color, and with this " + _textColor + " text: " + _text + "\n";
        return data;
    }


private:
    std::string _backgroundcolor;
    std::string _text;
    std::string _textColor;

};

int main() {

    postit postit1 ("orange", "Idea 1", "blue");
    postit postit2 ("pink", "Awesome", "black");
    postit postit3 ("yellow", "Superb!", "green");

    std::cout << postit1.tostring() << postit2.tostring() << postit3.tostring() << std::endl;

    return 0;
}