#include "include/octagon.h"
#include <fstream>
#include <iostream>

int main() {
    Octagon octagon1(4);

    std::ofstream out_file("data.txt");
    out_file << octagon1;
    std::cout << octagon1 << '\n' << octagon1.get_center()[0] << ' ' << octagon1.get_center()[1] << '\n';
    out_file.close();

    Octagon octagon2;

    std::ifstream in_file("data.txt");
    in_file >> octagon2;
    std::cout << octagon2 << '\n' << octagon2.get_center()[0] << ' ' << octagon2.get_center()[1] << '\n';
    in_file.close();
    return 0;
}