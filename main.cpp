#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include<sstream>
#include<iterator>
#include<vector>

using std::cout;
using std::cerr;

void run(const std::string&);
void run(std::stringstream&);
void runFile(const std::string&);
void runPrompt();

void runFile(const std::string&path)
{
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    run(buffer);
}

void runPrompt()
{
    for(;;)
    {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);
        run(line);
    }
}

void run(const std::string&code)
{
    std::stringstream buffer;
    buffer << code;
    run(buffer);
}

void run(std::stringstream& streamedCode)
{
    std::vector<std::string> tokens;
    copy(std::istream_iterator<std::string>(streamedCode), 
            std::istream_iterator<std::string>(), 
            back_inserter(tokens));
    for(const auto&token: tokens)
        printf("token: %s\n", token.c_str());
}

int main(const int argc, const char * const * const argv)
{
    switch(argc)
    {
        case 2:
            {
                std::string script{argv[1]}; 
            }
            break;
        case 1:
            {
                runPrompt();
            }
            break;
        default:
            cerr << "Usage: cloxebbbe [script]\n";
            return 64;
    }
    return 0;
}
