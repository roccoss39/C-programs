#include <iostream>
#include <string>
#include <vector>

//In this task you are required to, given a string, replace every letter with its position in the alphabet.

// If anything in the text isn't a letter, ignore it and don't return it.

// "a" = 1, "b" = 2, etc.

std::string alphabet_position(const std::string &text)
{
    std::vector<int> v{text.begin(), text.end()};
    std::string Str{""};
    for (auto elem : v)
    {
        elem = tolower(elem);
        if ((elem - 96) > 0 && (elem - 96) < 27)
            Str += (std::to_string(elem - 96)) + " ";
    }
    if (!Str.empty())
    Str.erase(Str.size() - 1);
    return Str;
}

int main()
{
    std::cout << alphabet_position("The sunset sets at twelve o' clock.");
}