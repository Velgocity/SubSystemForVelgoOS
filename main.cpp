#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <time.h>
#include <string.h>

using namespace std;

void clear()
{
    cout << "\x1B[2J\x1B[H";
}

namespace Color
{
    enum Code
    {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_BLUE = 34,
        FG_DEFAULT = 39,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_BLUE = 44,
        BG_DEFAULT = 49,
        FG_BLACK = 30,
        FG_WHITE = 37,
        BG_YELLOW = 103,
        BG_WHITE = 47
    };
    class Modifier
    {
        Code code;

    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream &
        operator<<(std::ostream &os, const Modifier &mod)
        {
            return os << "\033[" << mod.code << "m";
        }
    };
}

namespace Games
{
    void guessGame()
    {
        Color::Modifier red(Color::FG_RED);
        Color::Modifier def(Color::FG_DEFAULT);
        Color::Modifier gre(Color::FG_GREEN);
        Color::Modifier blu(Color::FG_BLUE);
        Color::Modifier wht(Color::FG_WHITE);
        srand(time(NULL));
        cout << endl
             << "Enter number : ";
        int GUESSGAME_NUMBER;
        int RANDOM_NUMBERGUESS = rand() % 100 + 1;
        cin >> GUESSGAME_NUMBER;
        while (true)
        {
            if (GUESSGAME_NUMBER < RANDOM_NUMBERGUESS)
            {
                cout << endl
                     << red << "Choose a big number : " << def;
                cin >> GUESSGAME_NUMBER;
            }
            else if (GUESSGAME_NUMBER > RANDOM_NUMBERGUESS)
            {
                cout << endl
                     << red << "Choose a small number : " << def;
                cin >> GUESSGAME_NUMBER;
            }
            else
            {
                clear();
                cout << gre << "You win!!" << def << endl
                     << endl
                     << endl;
                cout << blu << "Number : " << def << wht << GUESSGAME_NUMBER << def << endl
                     << endl;
                break;
            }
        }
    }
}

namespace apps
{
    void Calculator()
    {
        Color::Modifier red(Color::FG_RED);
        Color::Modifier def(Color::FG_DEFAULT);
        Color::Modifier gre(Color::FG_GREEN);
        Color::Modifier blu(Color::FG_BLUE);
        Color::Modifier bggre(Color::BG_GREEN);
        Color::Modifier bgdef(Color::BG_DEFAULT);
        Color::Modifier blc(Color::FG_BLACK);
        string OP_CALC;
        cout << "Select a process : ";
        cin >> OP_CALC;
        cout << endl
             << endl;

        cout << "Enter number 1 : ";
        float CALC_NUMBER1;
        float CALC_NUMBER2;
        cin >> CALC_NUMBER1;

        cout << endl;
        cout << "Enter number 2 : ";
        cin >> CALC_NUMBER2;
        cout << endl;

        if (OP_CALC == "+")
        {
            cout << gre << CALC_NUMBER1 << def << blu << " + " << def << gre << CALC_NUMBER2 << def << red << " = " << def << bggre << blc << CALC_NUMBER1 + CALC_NUMBER2 << bgdef << def << endl
                 << endl;
        }
        if (OP_CALC == "-")
        {
            cout << gre << CALC_NUMBER1 << def << blu << " - " << def << gre << CALC_NUMBER2 << def << red << " = " << def << bggre << blc << CALC_NUMBER1 - CALC_NUMBER2 << bgdef << def << endl
                 << endl;
        }
        if (OP_CALC == "*")
        {
            cout << gre << CALC_NUMBER1 << def << blu << " * " << def << gre << CALC_NUMBER2 << def << red << " = " << def << bggre << blc << CALC_NUMBER1 * CALC_NUMBER2 << bgdef << def << endl
                 << endl;
        }
        if (OP_CALC == "/")
        {
            cout << gre << CALC_NUMBER1 << def << blu << " / " << def << gre << CALC_NUMBER2 << def << red << " = " << def << bggre << blc << CALC_NUMBER1 / CALC_NUMBER2 << bgdef << def << endl
                 << endl;
        }
    }

    void texte()
    {
        Color::Modifier def(Color::FG_DEFAULT);
        Color::Modifier blu(Color::FG_BLUE);
        string TEXTE_COMMAND;
        cout << "; OP TEXTE ; ";
        cin >> TEXTE_COMMAND;

        if (TEXTE_COMMAND == "new")
        {
            string FILENAME;
            string TEXTE_TEXT;

            cout << "Enter new file name : ";
            cin >> FILENAME;

            cout << endl
                 << endl
                 << "Note : ";
            cin >> ws;

            getline(cin, TEXTE_TEXT);

            ofstream MYTEXT_WRITETEXTE("storage/texts/notes/" + FILENAME + ".txt");
            MYTEXT_WRITETEXTE << TEXTE_TEXT;
            MYTEXT_WRITETEXTE.close();
        }
        else if (TEXTE_COMMAND == "get")
        {
            string FILENAME;
            string FILETEXT;
            cout << "Enter file : ";
            cin >> FILENAME;

            ifstream myWriter("storage/texts/notes/" + FILENAME + ".txt");
            getline(myWriter, FILETEXT);
            cout << "Todo (" << blu << FILENAME << def << ")"
                 << " : " << FILETEXT << endl
                 << endl;
            myWriter.close();
        }
        else if (TEXTE_COMMAND == "del")
        {
            string TEXTETEXTENAME;
            cout << "Enter delete text name : ";
            cin >> TEXTETEXTENAME;
            string TEXTETEXTPATH = "storage/texts/notes/" + TEXTETEXTENAME + ".txt";
            char *TEXTETEXTPATHCHAR = new char[TEXTETEXTPATH.length() + 1];
            strcpy(TEXTETEXTPATHCHAR, TEXTETEXTPATH.c_str());
            remove(TEXTETEXTPATHCHAR);
        }
    }
    void todo()
    {
        Color::Modifier def(Color::FG_DEFAULT);
        Color::Modifier blu(Color::FG_BLUE);
        string OP_COMMAND;
        cout << ";OP TODO; ";
        cin >> OP_COMMAND;

        if (OP_COMMAND == "add")
        {
            string TODONAME;
            string TODOTEXT;
            cout << "Enter new todo name : ";
            cin >> TODONAME;

            cout << "Todo : ";
            cin >> ws;

            getline(cin, TODOTEXT);

            ofstream myTodoWriter("storage/texts/todo/" + TODONAME + ".txt");
            myTodoWriter << TODOTEXT;
            myTodoWriter.close();
        }
        else if (OP_COMMAND == "get")
        {
            string TODONAME;
            string TODOTEXT;
            cout << "Enter todo name : ";
            cin >> TODONAME;

            ifstream myTodoWriter("storage/texts/todo/" + TODONAME + ".txt");
            getline(myTodoWriter, TODOTEXT);
            cout << "Todo (" << blu << TODONAME << def << ")"
                 << " : " << TODOTEXT << endl
                 << endl;
            myTodoWriter.close();
        }
        else if (OP_COMMAND == "del")
        {
            string TODONAME;
            cout << "Enter delete todo name : ";
            cin >> TODONAME;
            string TODOPATH = "storage/texts/todo/" + TODONAME + ".txt";
            char *TODOPATHCHAR = new char[TODOPATH.length() + 1];
            strcpy(TODOPATHCHAR, TODOPATH.c_str());
            remove(TODOPATHCHAR);
        }
    }
}

int main()
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier gre(Color::FG_GREEN);
    Color::Modifier blu(Color::FG_BLUE);
    Color::Modifier bgred(Color::BG_RED);
    Color::Modifier bggre(Color::BG_GREEN);
    Color::Modifier bgdef(Color::BG_DEFAULT);
    Color::Modifier blc(Color::FG_BLACK);
    Color::Modifier wht(Color::FG_WHITE);
    Color::Modifier bgyellow(Color::BG_YELLOW);
    Color::Modifier bgwht(Color::BG_WHITE);
    clear();
    ifstream name("storage/name.txt");
    ifstream password("storage/password.txt");

    string Name;
    string Password;

    while (getline(name, Name))
    {
        Name = Name;
    }

    while (getline(password, Password))
    {
        Password = Password;
    }

    name.close();
    password.close();
    if (Name == "" || Password == "")
    {
        mkdir("storage");
        mkdir("storage/apps");
        cout << "You don't have an account, so you need to create a new account." << endl
             << endl;
        string newAccountName;
        cout << "Enter account name : ";
        cin >> newAccountName;
        ofstream newAccountWriteName("storage/name.txt");
        newAccountWriteName << newAccountName;
        newAccountWriteName.close();
        cout << "Enter account password : ";
        string newAccountPassword;
        cin >> newAccountPassword;
        ofstream newAccountWritePassword("storage/password.txt");
        newAccountWritePassword << newAccountPassword;
        newAccountWritePassword.close();
        cout << "Thank you for creating an account.";
        clear();
    }
    else
    {
        string PATH = "MAIN";
        string enterPassword;
        cout << "Enter your password : ";
        cin >> enterPassword;
        clear();
        while (true)
        {
            if (enterPassword == Password)
            {
                string command;
                cout << red << "NAME : " << blc << bggre << Name << bgdef << wht << "; " << gre << "PATH : " << blc << bgred
                     << PATH << bgdef << wht << ";" << endl
                     << blu << "? ~" << def << " # ";
                cin >> ws;
                getline(cin, command);
                if (command == "close")
                {
                    return 0;
                }
                else if (command == "settings::changeName")
                {
                    string changeNameNewName;
                    cout << "New name : ";
                    cin >> changeNameNewName;
                    Name = changeNameNewName;
                    ofstream changeNewName("storage/name.txt");
                    changeNewName << Name;
                    changeNewName.close();
                    cout << "Restart...";
                    return 0;
                }
                else if (command == "settings::changePassword")
                {
                    string changePasswordNewPassword;
                    cout << "New password : ";
                    cin >> changePasswordNewPassword;
                    Password = changePasswordNewPassword;
                    ofstream changeNewPassword("storage/password.txt");
                    changeNewPassword << Password;
                    changeNewPassword.close();
                    cout << "Restart...";
                    return 0;
                }
                else if (command == "clr")
                {
                    clear();
                }
                else if (command == "developer::help-developer")
                {
                    cout << endl
                         << endl
                         << bgyellow << blc << "Rust" << bgdef << def << " is the most beautiful programming language that we can offer you for creating applications."
                         << endl
                         <<

                        "Other programming languages are not recommended. "
                         << endl
                         <<

                        "(Although this application is coded in " << red << bgyellow << "C++" << def << bgdef << ", we recommend rust. Faster, simpler)"
                         << endl
                         << endl;
                }
                else if (command == "user::help")
                {
                    cout << R""""(
                        1. close : The exit command closes the application completely.

                        2. clr : The CLR command clears the terminal.
                    )"""";
                }
                else if (command == "games::guessGame")
                {
                    Games::guessGame();
                }
                else if (command == "apps::calculator")
                {
                    apps::Calculator();
                }
                else if (command == "apps::calc")
                {
                    apps::Calculator();
                }
                else if (command == "settings::deleteSystem")
                {
                    cout << "Deleting..." << endl;
                    remove("storage/name.txt");
                    remove("storage/password.txt");
                    rmdir("storage");
                }
                else if (command == "settings::user::help")
                {
                    cout << endl
                         << endl
                         << R""""(
                        User settings : 
                            1. Change name.
                            2. Change password.
                            3. ...
                    )"""" << endl
                         << endl;
                }
                else if (command == "apps::texte")
                {
                    apps::texte();
                }
                else if (command == "apps::todo")
                {
                    apps::todo();
                }
                else if (command == "cd")
                {
                    string CDGO;
                    cout << ";; ";
                    cin >> CDGO;
                    chdir(CDGO.c_str());
                    PATH += "/" + CDGO;
                }
                else if (command == "ls")
                {
#ifdef _WIN32
                    system("dir");
#ifdef _LINUX
                    system("ls");
#endif
#endif
                }
                else
                {
                    cout << endl
                         << red << "Error : " << def << command << gre << " there is no such command." << def << endl
                         << endl;
                }
            }
            else
            {
                cout << "Your password is incorrect.";
                return 0;
            }
        }
    }
}