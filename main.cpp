#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include<sstream>

using std::cout;
using std::cerr;

void run(const std::string&);
void runFile(const std::string&);
void runPrompt();

void runFile(const std::string&path)
{
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    run(buffer.str());
}

void runPrompt()
{
    ((void)0);
    std::cout << "...And I cry...\n";

    for(;;)
    {
        std::string line;
        std::getline(std::cin, line);
        run(line);
    }
}

void run(const std::string&code)
{
    (void)code;
    std::cout << "I run...\n";
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
