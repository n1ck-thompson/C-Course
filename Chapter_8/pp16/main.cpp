#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;


vector<string> split(const string& target, const string& delimiter){


    vector<string> toBeReturned;
    size_t nextDelimiterIndex = target.find(delimiter,0);

    if(nextDelimiterIndex < target.size())
        toBeReturned.push_back(target.substr(0, nextDelimiterIndex));

    while(nextDelimiterIndex<target.size()-1 &&
    nextDelimiterIndex < target.find(delimiter,nextDelimiterIndex+1)){

        toBeReturned.push_back(target.substr(nextDelimiterIndex+1,
        target.find(delimiter,nextDelimiterIndex+1) - nextDelimiterIndex - 1));

        nextDelimiterIndex = target.find(delimiter,nextDelimiterIndex+1);
    };

    return toBeReturned;
};

vector<vector<vector<string>>> racersDataExtractor(const vector<string>
&myFileLast9Lines){


    vector<vector<vector<string>>> toBeReturned;
    for(size_t j=0;j<3;++j){
        toBeReturned.push_back(vector<vector<string>>());
        for(size_t i=0;i<3;++i)
            toBeReturned[j].push_back(split(myFileLast9Lines[i+3*j],","));

        if(j>0){
            vector<string> temp;
            for(size_t k1 = 0; k1<3;++k1){
                for(size_t k2 = 0; k2<3;++k2){
                    if(toBeReturned[j][k1][1]==toBeReturned[j-1][k2][1]){
                        temp = toBeReturned[j][k1];
                        toBeReturned[j][k1] = toBeReturned[j][k2];
                        toBeReturned[j][k2] = temp;

                    };

                };
            };
        };
    };

    return toBeReturned;
};

int main(){

    fstream myData("racers' data.dat", ios::in);
    if(!myData){
        cout<<"I couldn't find \"racers' data.dat\" in the current"
        " directory.\n";
        system("pause");
        exit(1);
    };

    string myFileString;
    char next;
    while(myData.get(next)) myFileString+=next;

    string startTime = myFileString.substr(0, myFileString.find("\n"));

    string dataLines = myFileString.substr(myFileString.find("\n")+1);

    vector<string> dataLinesVect = split(dataLines, "\n");


    vector<vector<vector<string>>> racersData =
        racersDataExtractor(dataLinesVect);


    cout<<"Enter the racer's ID:\t";
    string racerID;cin>>racerID;


    int racerNumber =-1;
    for(size_t i =0; i<3;++i)
        if(racersData[0][i][1] == racerID) racerNumber = i;
    if (racerNumber<0){
        cout<<"\nInvalid ID.\n";
        system("pause");
        exit(1);
    };
    double startTimeminutes = 0;
    double secondTimeminutes = 0;
    double thirdTimeminutes = 0;

    vector<string> startTimeVec = split(racersData[0][racerNumber][2]," ");
    vector<string> secondTimeVec = split(racersData[1][racerNumber][2]," ");
    vector<string> thirdTimeVec = split(racersData[2][racerNumber][2]," ");

    startTimeminutes = stod(startTimeVec[0])*60+
        stod(startTimeVec[1])+stod(startTimeVec[2])/60;

    secondTimeminutes = stod(secondTimeVec[0])*60+
        stod(secondTimeVec[1])+stod(secondTimeVec[2])/60;

    thirdTimeminutes = stod(thirdTimeVec[0])*60+
        stod(thirdTimeVec[1])+stod(thirdTimeVec[2])/60;


    //Displaying the results
    cout<<"the racer's overall finish is "<<racersData[2][racerNumber][2]
     <<"\nrace split times in minutes/mile for split1 is "<<
     (secondTimeminutes - startTimeminutes)/7
    <<"\nrace split times in minutes/mile for split2 is "<<
     (thirdTimeminutes - secondTimeminutes)/6.1
    <<"\nthe overall race time (minutes) is "<<
    (thirdTimeminutes - startTimeminutes)<<
    "\nand overall race pace (minutes/mile) is "<<
    (thirdTimeminutes - startTimeminutes)/13.1
    <<"." ;

    return 0;

};