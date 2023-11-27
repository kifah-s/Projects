

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//* >>>>>>>>>>>>>>> Page Code <<<<<<<<<<<<<<< *//
// Page Class.
class Page
{
private:
    string htmlCode, cssCode;

public:
    void choosePage(string headerHtml, string footerHtml, string pageName, string backgroundColor)
    {
        int pageNumber;

        cout << "Page 1:\n"
                "---------------------------------------\n"
                "|    Youtube video | Youtube video    |\n"
                "---------------------------------------\n"
                "Page 2:\n"
                "---------------------------------------\n"
                "|    Youtube video | Text             |\n"
                "---------------------------------------\n"
                "choose Number: ";
        cin >> pageNumber;

        generateCode(headerHtml, footerHtml, pageName, pageNumber, backgroundColor);
    }

    void generateCode(string headerHtml, string footerHtml, string pageName, int pageNumber, string backgroundColor)
    {
        // Html Code.
        htmlCode = "<html><head><title>" + pageName + "</title>";
        htmlCode += "<link rel = \" stylesheet \" href = \" \\ header.css \">";
        htmlCode += "<link rel = \" stylesheet \" href = \" \\ footer.css \">";

        // Css Code.
        cssCode = "body { background-color: " + backgroundColor + "; }";
        cssCode += "table.pageTable { margin-right: auto; margin-left: auto; width: 80%; }";
        cssCode += "td.pageTd { color: white; text-align: center; }";
        cssCode += "iframe { width: 100%; }";

        // Html Code.
        htmlCode += "<style>" + cssCode + "</style></head>";
        htmlCode += "<body><br>" + headerHtml + "<br><br>";
        htmlCode += "<table class = \" pageTable \">";

        // Rows of number.
        cout << "Please enter a number of rows: ";
        int numberOfRows;
        cin >> numberOfRows;
        for (int i = 0; i < numberOfRows; i++)
        {
            htmlCode += "<tr><td class = \" pageTd \">";
            string videoLing;
            cout << "Please enter a video link: ";
            cin >> videoLing;
            htmlCode += "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/" + videoLing + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share\" allowfullscreen></iframe>";
            htmlCode += "<td><td class = \" pageTd \">";
            if (pageNumber == 1)
            {
                cout << "Please enter a video link: ";
                cin >> videoLing;
                htmlCode += "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/" + videoLing + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share\" allowfullscreen></iframe>";
            }
            else if (pageNumber == 2)
            {
                string text;
                cout << "Please enter a text: ";
                getchar();
                getline(cin, text);
                htmlCode += text;
            }
            htmlCode += "</td></tr>";
        }

        htmlCode += "</table>" + footerHtml + "</body></html>";
    }

    string getHtml()
    {
        return htmlCode;
    }
};
// End page class.
//* >>>>>>>>>>>>>>> End Page Code <<<<<<<<<<<<<<< *//

//! Note: Create main function just for testing page code ..

/*

int main()
{
    Page p;
    p.choosePage("<br>Header<br>", "<br>Footer<br>", "kifah", "teal");

    FILE *out = fopen("index.html", "w");
    fprintf(out, "%s", p.getHtml().c_str());

    return 0;
}

*/