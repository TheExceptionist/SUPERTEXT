#include "defs.h"

bool e_std::accept(const std::string& question, const std::string& match)
{
    std::string input;
    printf("%s\n", question.c_str());

    std::cin >> input;

    if (match.compare(input) == 0) return true;
    else return false;
}

void e_std::store(const std::string& question, std::string* storeTo)
{
    std::string input;
    printf("%s\n", question.c_str());

    std::cin >> input;
    *storeTo = input;
}

int e_std::acceptIntln(const std::string& question)
{
    return e_std::acceptInt(question+"\n");
}

int e_std::acceptInt(const std::string& question)
{
    std::string input;
    printf("%s", question.c_str());

    std::string::size_type size;

    std::cin >> input;
    int answer = 0;

    try
    {
        answer = (std::stoi(input, &size));
    }
    catch(const std::invalid_argument& ia)
    {
        fprintf(stderr, "Invalid argument: %s!\n", input.c_str());
    }

    if(answer == EXIT_CODE)
    {
        exit(1);
    }

    return answer;
}

int e_std::loopAccept(const std::string& question, const std::string& match, std::string* storeTo, const int type)
{
    bool invalid = true;
    int answer = 0;

    do
    {
        switch(type)
        {
            case ACCEPT:
            {
                invalid = accept(question, match);

                if(invalid)
                {
                    printf("Invalid Answer!\n");
                }
            }
            break;
            case STORE:
            {
                store(question, storeTo);
                invalid = false;
            }
            break;
            case ACCEPT_INT:
            {
                answer = acceptInt(question);
                invalid = false;
            }
            break;
            default:
            {
                printf("Invalid Accept Type!\n");
            }
        }
    }
    while(invalid);

    return answer;
}

void e_std::println(const std::string& str)
{
    printf("%s\n", str.c_str());
}

int e_std::randInt(int min, int max)
{
    return ((rand() % (max - min)) + min);
}

//Unix systems only
void e_std::clear()
{
    printf("\033c");
}