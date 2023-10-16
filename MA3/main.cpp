#include <map>
#include "TwitterData.hpp"
using namespace std;


int main(int argc, char* argv[])
{
    string check;



    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here
    //

    map<string, TwitterData> S1, S2;
    // For search By User Name
    for (int i = 0; i < 5; ++i)
    {
        S1.insert(pair<string, TwitterData>(twitter_data[i].getUserName(), twitter_data[i]));
        cout << "Key: " << twitter_data[i].getUserName() << "Value: " << twitter_data[i].print() << endl;
    }
    cout << "Enter UserName for Search: ";
    cin >> check;

    auto temp = S1.find(check);

    if (temp != S1.end())
    {
        cout << "Key: " << check << "Was Found: "  << endl;
        cout << "Value: " << temp->second.print() << endl;
        cout << check << "Is Now Deleted From Map" << endl;
    }
    else
    {
        cout << "Key: " << check << ", Was Not Found." << endl;
    }


    S1.erase(check);

    




    // For search By Email
    for (int i = 0; i < 5; ++i)
    {
        S2.insert(pair<string, TwitterData>(twitter_data[i].getEmail(), twitter_data[i]));
        cout << "Key: " << twitter_data[i].getEmail() << "Value: " << twitter_data[i].print() << endl;
    }

    cout << "Enter Email for Search: ";
    cin >> check;

    auto temp2 = S2.find(check);

    if (temp2 != S2.end())
    {
        cout << "Key: " << check << "Was Found: " << endl;
        cout << "Value: " << temp2->second.print() << endl;
        cout << check << "Is Now Deleted From Map" << endl;
    }
    else
    {
        cout << "Key: " << check << " Was Not Found." << endl;
    }


    S2.erase(check);






    cout << endl;
    cout << "Scenario 1 Final Map" << endl;
    for (auto pair : S1)
    {
        cout << "Key:" << pair.first << "Value: " << pair.second.print() << endl;
    }

    cout << endl;
    cout << "Scenario 2 Final Map" << endl;
    for (auto pair : S2)
    {
        cout << "Key:" << pair.first << "Value: " << pair.second.print() << endl;
    }




    return 0;
}