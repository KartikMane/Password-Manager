#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    string name[5];
    string pass[5];
    ofstream hout("Pass.txt");
    name[0] = "Leetcode";
    name[1] = "Instagram";
    name[2] = "Hackerrank";
    name[3] = "Email";
    name[4] = "Google";
    pass[0] = "llll";
    pass[1] = "iiiii";
    pass[2] = "hhhhh";
    pass[3] = "eeeee";
    pass[4] = "ggggg";
    for (int j = 0; j < 5; j++)
    {
        hout << name[j] << ": " << endl;
        hout << pass[j] << endl;
    }

    while (true)
    {
        cout << "Select the operation to be performed :" << endl;
        int n;
        cout << "1 : Update all passwords." << endl;
        cout << "2 : Update a specific password." << endl;
        cout << "3 : Display all passwords." << endl;
        cout << "4 : Display a specific password." << endl;
        cout << "5 : End" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            for (int i = 0; i < 5; i++)
            {
                ofstream("Pass.txt");
                cout << "Which password to enter :" << endl;
                cin >> name[0];
                cout << "Enter password :" << endl;
                cin >> pass[0];
                hout << name[0] << " :" << endl;
                hout << pass[0] << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Enter which password to update :" << endl;
            string zz;
            cin >> zz;
            std::ifstream inputFile("Pass.txt"); // Open the file for reading

            if (!inputFile.is_open())
            {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }

            std::string targetWord = zz; // Change this to the word you want to find
            std::string line;
            bool found = false;

            while (std::getline(inputFile, line))
            {
                if (line.find(targetWord) != std::string::npos)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                if (std::getline(inputFile, line))
                {
                    std::cout << "Current Password \"" << targetWord << "\": " << line << std::endl;
                }
                else
                {
                    std::cout << "No line found after \"" << targetWord << "\"." << std::endl;
                }
            }
            else
            {
                std::cout << "Word \"" << targetWord << "\" not found in the file." << std::endl;
            }
            inputFile.close(); // Close the file

            cout << "Enter new password :" << endl;
            string abc;
            cin >> abc;
            string replaceStr = line;        // String to replace
            string replacementStr = abc;     // String To replace with
            ifstream filein("Pass.txt");
            ofstream fileout("Pass.txt",ios::app);    // Temporary file
            string strTemp;

            while (filein >> strTemp) // taking every word and comparing with replaceStr
            {
                if (strTemp == replaceStr) // if your word found then replace
                {
                    strTemp = replacementStr;
                }
                strTemp += " ";
                fileout << strTemp; // output everything to fileout(temp.txt)
            }
            filein.close();
            fileout.close();
            inputFile.close(); // Close the file
            break;
        }
        case 3:
        {
            ifstream in;
            in.open("Pass.txt");
            string st2;
            cout<<"Before updation :";
            while (in.eof() == 0)
            {
                getline(in, st2);
                cout << st2 << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter which password to be displayed :" << endl;
            string h;
            cin >> h;
            std::ifstream inputFile("Pass.txt"); // Open the file for reading

            if (!inputFile.is_open())
            {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }

            std::string targetWord = h; // Change this to the word you want to find
            std::string line;
            bool found = false;

            while (std::getline(inputFile, line))
            {
                if (line.find(targetWord) != std::string::npos)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                if (std::getline(inputFile, line))
                {
                    std::cout << "Current Password \"" << targetWord << "\": " << line << std::endl;
                }
                else
                {
                    std::cout << "No line found after \"" << targetWord << "\"." << std::endl;
                }
            }
            else
            {
                std::cout << "Word \"" << targetWord << "\" not found in the file." << std::endl;
            }
            inputFile.close(); // Close the file
            break;
        }
        case 5:
        {
            exit(0);
        }
        }
    }
    return 0;
}