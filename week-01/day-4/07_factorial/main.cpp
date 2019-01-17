#include <iostream>
#include <string>

int factorio (int n, int m) {
    int f = 1;
    for(int i = 0; i <= n; i+=1) {
        f = f * i ;
    }
    f = m;
}

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.


    int n;
    int m;

    std::cout << "Give me a number: " << std::endl;
    std::cin >> n;

    std::cout << "Give me a number to overwrite: " << std::endl;
    std::cin >> m;

    factorio(n, m);

    return m;
}