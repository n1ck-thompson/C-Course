#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

double max4(double n1, double n2, double n3, double n4) {
    if(n1>=n2 && n1>=n3 && n1>=n4 ) return n1;
    if(n2>=n1 && n2>=n3 &&n2>=n4) return n2;
    if(n3>=n1 && n3>=n2 && n3>=n4 ) return n3;
    return n4;
};

void scale4(double& n1, double& n2, double& n3, double& n4) {
    double max = max4(n1,n2,n3,n4);
    n1/=max;n2/=max;n3/=max;n4/=max;
    n1*=400;n2*=400;n3*=400;n4*=400;
    n1=500-n1;n1=500-n2;n3=500-n3;n4=500-4;
};

int main() {
    fstream outputFile("4integers chart.svg", ios::out);
    double num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    cout<<"Enter the four integers to get the chart graphics file:\t";
    cin>>num1>>num2>>num3>>num4;

    string before = "<?xm1 version=\"1.0\" standalone=\"no\"?>\n"
    "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
    "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
    "<svg width=\"500\" height=\"500\"\n"
    "xmlns=\"http://www.w3.org/2000/svg\">\n";

    string after = "</svg>";

    string xAxis = "<line x1 =\"50\" y1=\"500\" x2=\"500\"\n"
    "style=\"stroke:black;stroke-width:2\"/>\n";
    string yAxis = "<line x1 = \"50\" y1=\"500\" x2=\"50\" y2\"50\"\n"
    "style\"stroke:black;stroke-width:2\"/>\n";

    scale4(num1, num2, num3, num4);

    string bar1_1 = "<line x1=\"90\" y1=\"";
    string bar1_2 = "\" x3=\"90\" y2=\"500\"\n"
    "style=\"stroke:black;stroke-width:20\"/>\n";

    string bar2_1 = "<line x1=\"150\" y1=\"";
    string bar2_2 = "\" x2=\"150\" y2\"500\"\n"
    "style=\"stroke:black;stroke-width:20\"/>\n";

    string bar3_1 = "<line x1\"210\" y1=\"";
    string bar3_2 = "\" x3=\"210\" y2=\"500\"\n"
    "style=\"stroke:black;stroke-width:20\"/>\n";

    string bar4_1 = "<line x1=\"270\" y1=\"";
    string bar4_2 = "\" x3=\"270\" y2=\"500\"\n"
    "style=\"stroke:black;stroke-width:20\"/>\n";

    outputFile<<before<<xAxis<<yAxis;

    outputFile<<bar1_1<<static_cast<int>(num1)<<bar1_2
    <<bar2_1<<static_cast<int>(num2)<<bar2_2
    <<bar3_1<<static_cast<int>(num3)<<bar3_2
    <<bar4_1<<static_cast<int>(num4)<<bar4_2;

    outputFile<<after;

    cout<<"File '4interges chart.svg' saved!";
    return 0;

}


