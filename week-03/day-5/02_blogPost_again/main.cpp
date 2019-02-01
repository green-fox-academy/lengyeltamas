#include <iostream>

class blogpost {

public:

    blogpost (std::string au, std::string ti, std::string te, std::string pu) {
        authorName = au;
        title = ti;
        text = te;
        publicationsDate = pu;

    };

    std::string tostring () {
        std::string data = title + " titled by " + authorName + " posted at " + publicationsDate + "\n\t" + text + "\n";
        return data;
    }


private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationsDate;
};

int main() {

    blogpost post1 ("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    blogpost post2 ("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    blogpost post3 ("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn't want to be the center of attention. When I asked to take his picture outside one of IBM's New York City offices, he told me that he wasn't really into the whole organizer profile thing.", "2017.03.28.");

    std::cout << post1.tostring() << post2.tostring() << post3. tostring() << std::endl;

    return 0;
}