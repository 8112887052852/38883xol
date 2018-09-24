#include<iostream>
#include<string>

using std::cout;
using std::cerr;

void runFile(const std::string& script)
{
    (void)script;
}

void runPrompt()
{
    ((void)0);
}

int main(const int argc, const char**argv)
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
            cerr << "Usage: coxebbbe [script]\n";
            return 64;
    }
    return 0;
}
