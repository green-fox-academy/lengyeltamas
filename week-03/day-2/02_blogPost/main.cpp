#include <iostream>
#include <string>


class BlogPost {
public:
    BlogPost (std::string a, std::string b, std::string c, std::string d) {
        authorName = a;
        title = b;
        text = c;
        publicationDate = d;
    }

    std::string tostring () {
        std::string data = "\"" + title + "\"" + "titled by " + authorName + " posted at " + "\"" + publicationDate + "\"" + "\n\t" + text + "\n";
        return data;
    };

private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;
};

int main(int argc, char* args[]) {

    BlogPost post1 ("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost post2 ("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything..", "2010.10.10.");
    BlogPost post3 ("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn't want to be the center of attention. When I asked to take his picture outside one of IBM's New York City offices, he told me that he wasn't really into the whole organizer profile thing.", "2017.03.28.");

    std::cout << post1.tostring() << post2.tostring() << post3.tostring() << std::endl;

}