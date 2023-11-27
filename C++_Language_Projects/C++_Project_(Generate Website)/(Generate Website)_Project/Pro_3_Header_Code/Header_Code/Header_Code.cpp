


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//* >>>>>>>>>>>>>>> Header Code <<<<<<<<<<<<<<< *//
// Header class.
class Header
{
private:
    string htmlCode, cssCode;
    int headerNumber = 0;
    string intToString(int num)
    {
        switch (num)
        {
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        }
        return "5";
    }

public:
    void chooseHeader(vector<string> pageName)
    {

        cout << "Header1:\n"
                "--------------------------\n"
                "|         picture        |\n"
                "--------------------------\n"
                "| Home | contact | About |\n"
                "--------------------------\n"
                "Header2:\n"
                "--------------------------\n"
                "| Home | contact | About |\n"
                "--------------------------\n"
                "please, enter header number: ";

        cin >> headerNumber;

        while (headerNumber != 1 && headerNumber != 2)
        {
            cout << "please, enter a correct header number: ";
        }

        generateCode(pageName);
    }

    void generateCode(vector<string> pageName)
    {
        cssCode = "table.headerTable { width: 80%; margin-left: auto; margin-right : auto;}";

        cssCode += "td.headerTd { border: 1bx solid white; color: white; text-align: center; font-size: 20px; }";

        htmlCode = "<table class = \"headerTable\">";

        if (headerNumber == 1)
        {
            cssCode += "img.headerImg {width: 100%; height: auto; } ";

            string pictureFileName;

            cout << "Please enter picture file name: ";
            cin >> pictureFileName;

            htmlCode += "<tr><td class = \"headerTd\" colspan = \"" + intToString((int)pageName.size()) +
                        "\"><img class = \"headerImg {width: 100%; height: auto; } \" src =\ " + pictureFileName;
            htmlCode += "\" /> </td></tr>";
        }

        htmlCode += "<tr>";
        for (int i = 0; i < pageName.size(); i++)
        {
            htmlCode += "<td class = \"headerTd\">" + pageName[i] + "</td>";
        }

        htmlCode += "</tr> </table>";
    }

    string getHtml()
    {
        return htmlCode;
    }

    string getCss()
    {
        return cssCode;
    }
};
// End header class.
//* >>>>>>>>>>>>>>> End Header Code <<<<<<<<<<<<<<< *//
