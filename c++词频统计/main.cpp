    #include <iostream>
    #include <string>
    #include <fstream>
    #include <map>
    #include <vector>
    #include <algorithm>
     
    using namespace std;
     
    bool myfunction(const pair<string, int>& lhs, const pair<string, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
     
    int main(int argc, char const *argv[])
    {
        map<string,int> myMap;
        fstream password;
        password.open("./password.txt", ios::in);
        while (!password.eof())
        {
            string temp;
            password >> temp;
            ++myMap[temp];
        }
        vector<pair<string, int> > myVector(myMap.begin(), myMap.end());
        sort(myVector.begin(), myVector.end(), myfunction);
        password.close();
        for (int i = 0; i < 10; i++)
        {
            cout << myVector[i].first << " " << myVector[i].second << endl;
        }
     
        return 0;
    }
