#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;


vector<vector<vector<double>>> getIDsAndCrossedSensorsAndTime
(vector<vector<int>>& racersData){
    vector<vector<vector<int>>> newRacersData;
    for(size_t sensorNo = 0; sensorNo <3;++sensorNo){
        newRacersData.push_back(vector<vector<int>>());
        for(vector<int> row: racersData){
            if (row[0]==sensorNo) newRacersData[sensorNo].push_back(row);
        };
    };

    vector<vector<vector<double>>> IDsAndSensorsAndTimeMin;
    vector<vector<double>> IDs = {vector<double>(), vector<double>(),
     vector<double>()};
    IDs[0].push_back(100);
    IDs[1].push_back(132);
    IDs[2].push_back(182);
    IDsAndSensorsAndTimeMin.push_back(IDs);
    IDsAndSensorsAndTimeMin.push_back(vector<vector<double>>());
    IDsAndSensorsAndTimeMin[1].push_back(vector<double>());
    IDsAndSensorsAndTimeMin[1].push_back(vector<double>());
    IDsAndSensorsAndTimeMin[1].push_back(vector<double>());

    for(size_t sensorNo = 0;sensorNo <newRacersData.size();++sensorNo){

        for(size_t racerNo = 0; racerNo<newRacersData[sensorNo].size();
         ++racerNo){

            if (newRacersData[sensorNo][racerNo][1] ==100){
                IDsAndSensorsAndTimeMin[1][0].push_back(sensorNo);
                IDsAndSensorsAndTimeMin[1][0].push_back(
                    newRacersData[sensorNo][racerNo][2]*60+
                    newRacersData[sensorNo][racerNo][3]+
                    newRacersData[sensorNo][racerNo][4]/60.0
                );
            }
            else if (newRacersData[sensorNo][racerNo][1] ==132){
                IDsAndSensorsAndTimeMin[1][1].push_back(sensorNo);
                IDsAndSensorsAndTimeMin[1][1].push_back(
                    newRacersData[sensorNo][racerNo][2]*60+
                    newRacersData[sensorNo][racerNo][3]+
                    newRacersData[sensorNo][racerNo][4]/60.0
                );
            }
            else{
                IDsAndSensorsAndTimeMin[1][2].push_back(sensorNo);
                IDsAndSensorsAndTimeMin[1][2].push_back(
                    newRacersData[sensorNo][racerNo][2]*60+
                    newRacersData[sensorNo][racerNo][3]+
                    newRacersData[sensorNo][racerNo][4]/60.0
                );
            };
        };

    };

    return IDsAndSensorsAndTimeMin;
};

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


vector<int> specializedSplit( string target, string delimiter=","){

    for(size_t i = 0; i< target.size();++i)
        if(target[i] == ' ') target[i] = ',';

    vector<int> toBeReturned;
    size_t nextDelimiterIndex = target.find(delimiter,0);

    if(nextDelimiterIndex < target.size())
        toBeReturned.push_back(stoi(target.substr(0, nextDelimiterIndex)));

    while(nextDelimiterIndex<target.size()-1 &&
    nextDelimiterIndex < target.find(delimiter,nextDelimiterIndex+1)){

        toBeReturned.push_back(stoi(target.substr(nextDelimiterIndex+1,
        target.find(delimiter,nextDelimiterIndex+1)-nextDelimiterIndex-1)));

        nextDelimiterIndex = target.find(delimiter,nextDelimiterIndex+1);
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


    string dataLines = myFileString.substr(myFileString.find("\n")+1);


    vector<string> dataLinesVect = split(dataLines, "\n");

    vector<vector<int>> dataArray;
    for(string dataLine:dataLinesVect)
        dataArray.push_back(specializedSplit(dataLine));

    vector<vector<vector<double>>> IDsAndCrossedSensorsAndTime =
    getIDsAndCrossedSensorsAndTime(dataArray);


    vector<double> sensorsPlacesMile;
    sensorsPlacesMile.push_back(0);
    sensorsPlacesMile.push_back(7);
    sensorsPlacesMile.push_back(13.1);

    for(size_t racerNo = 0; racerNo < 3;++racerNo)
        if(IDsAndCrossedSensorsAndTime[1][racerNo].size()<6){
            cout<<"\nThe racer of ID "<<
            IDsAndCrossedSensorsAndTime[0][racerNo][0]
            <<" was detected only by the sensors:\t";
            for(size_t registeredSensorNo = 0;
            registeredSensorNo<IDsAndCrossedSensorsAndTime[1][racerNo].size();
            registeredSensorNo+=2)
                cout<<
                IDsAndCrossedSensorsAndTime[1][racerNo][registeredSensorNo]
                <<"  ";
        }
        else {
            for(size_t index = 1; index <4.5;index+=2)
                if((IDsAndCrossedSensorsAndTime[1][racerNo][index+2]-
                IDsAndCrossedSensorsAndTime[1][racerNo][index])/
                (sensorsPlacesMile[(index+1)/2]-
                sensorsPlacesMile[(index-1)/2])<4.5)
                    cout<<"\nThe racer of ID "<<
                    IDsAndCrossedSensorsAndTime[0][racerNo][0]
                    <<" pace in the split of number "<<(index+1)/2<<" was "<<
                    (IDsAndCrossedSensorsAndTime[1][racerNo][index+2]-
                    IDsAndCrossedSensorsAndTime[1][racerNo][index])
                    /(sensorsPlacesMile[(index+1)/2]-
                    sensorsPlacesMile[(index-1)/2])<<" minutes/mile only.";


        };

  return 0;

};