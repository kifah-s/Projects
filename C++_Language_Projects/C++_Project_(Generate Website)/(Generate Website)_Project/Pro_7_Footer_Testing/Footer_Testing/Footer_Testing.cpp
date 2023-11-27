
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//* >>>>>>>>>>>>>>> Footer Code <<<<<<<<<<<<<<< *//
// Footer Class.
class Footer
{
private:
    string htmlCode, cssCode;

public:
    void chooseFooter(string websiteName)
    {
        int footerNumber;

        cout << "Footer 1:\n"
                "-----------------------------------\n"
                " (website Name) all rights reserve \n"
                "-----------------------------------\n"
                "Footer 2:\n"
                "-----------------------------------\n"
                "|    (Footer background color)    |\n"
                " (website Name) all rights reserved\n"
                "-----------------------------------\n"
                "Enter footer number: ";

        cin >> footerNumber;

        generateCode(footerNumber, websiteName);
    }

    void generateCode(int footerNumber, string websiteName)
    {
        // Add footer using html code.
        htmlCode = "<br><br><footer><div class = \"footerDiv\">" + websiteName + " all rights reserved</div></footer>";

        // Add design for footer using css code.
        cssCode = "footer { margin-left: auto; margin-right: auto; } ";
        cssCode += "div.footerDiv { text-align: center; left: 0; bottom: 0; width: 100%; ";

        if (footerNumber == 2)
        {
            // Add footer background color.
            string footerBackgroundColor;
            cout << "Please enter a footer background color: ";
            cin >> footerBackgroundColor;
            cssCode += "background-color: " + footerBackgroundColor + ";";

            // Add footer text color.
            string footerTextColor;
            cout << "Please enter a footer text color: ";
            cin >> footerTextColor;
            cssCode += "color: " + footerTextColor + ";";
            cssCode += "position: fixed;";
        }
        cssCode += "}";
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
// End Footer Class.
//* >>>>>>>>>>>>>>> End Footer Code <<<<<<<<<<<<<<< *//

//! Note: Create main function just for testing footer code ..

/*

int main()
{
    Footer f;
    f.chooseFooter("kifah");
    FILE *html = fopen("index.html", "w");
    fprintf(html, "<html><head><title>kifah</title>");
    fprintf(html, "<style>%s</style><body>", f.getCss().c_str());

    for (int i = 0; i < 100; i++)
    {
        fprintf(html, "kifah<br>");
    }

    fprintf(html, "%s</body></html>", f.getHtml().c_str());

    return 0;
}

*/