/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) 
{
    ifstream ifs(ntb1);
    long int arr[999];
    string line1;
    int num = 0;
    if (ifs.is_open())
    {
        ifs >> line1;
        if (line1.length() != 14) return "0000000000";
        for (int i = 11; i < 14; i++)
        {
            if (!isdigit(line1[i])) return "0000000000";
            else num = num*10 + (line1[i]-'0');
        }
        for (int i = 0; i < num; i++) ifs >> arr[i];
    }
    
    string ans = "0000000000";
    //cout << num << "\n";
    if (num == 0) return ans;
    else
    {
        for (int i = 0; i < num; i++)
        {
            ans[arr[i]]++;
            if (ans[arr[i]] > '9') ans[arr[i]] = '0';
        }
    }
    return ans;
}

string notebook2(string ntb2) 
{
    ifstream ifs(ntb2);
    string in_str;
    string str;
    int numofword = 0;
    int cntP = 0;
    if (ifs.is_open())
    {
        getline(ifs, in_str);
        if (in_str.length() != 5) return "1111111111";
        else 
        {
            for (int i = 0; i < 5; i++)
            {
                if (!isdigit(in_str[i])) return "1111111111";
                else numofword = numofword*10 + (in_str[i] - '0');
            }
            if (numofword < 5 || numofword > 100) return "1111111111";
            else 
            {
                string s2 = "Pink";
                string s1 = "pink";
                for (int i = 0; i < numofword; i++)
                {
                    string temp;
                    getline(ifs, temp);
                    for (int k = 0; k < temp.length(); k++)
                    {
                        if (k == temp.find(s1, k))
                        {
                            cntP++;
                            k = temp.find(s1, k);
                        }
                        else if (k == temp.find(s2, k))
                        {
                            cntP++;
                            k = temp.find(s2, k);
                        }
                    }
                }
                if (cntP < 10000) cntP = cntP*cntP;
                str = to_string(cntP);
                while (str.length() < 10) str = str + "9";
            }
        }
    }
    return str;
}

string notebook3(string ntb3) 
{
    ifstream ifs(ntb3);
    string temp;
    int arr[10][10] = {};
    int i,j;
    i = j = 0; 
    if(ifs.is_open())
    {
        while(getline(ifs,temp))
        {
            int l = temp.length();
            string test = "";
            for (int k = 0; k < l; k++)
            {
                if (temp[k] != '|') test += temp[k];
                else{
                    arr[i][j] = abs(stoi(test));
                    j++;
                    test = " ";
                }
            }
            arr[i][j] = abs(stoi(test));
            i++;
            j = 0;
        }
    }

    ifs.close();
    
    int x = 1;
    int v = 1;
    for (int i = 0; i < 10; i++)
         {
            v = x;
            while(v < 10)
            {
                if (arr[i][v] <= 1) arr[i][v] = 2;
                else
                {
                    int a = arr[i][v];
                    for (int k = 2; k < a; k++)
                        {
                            if (a % k == 0)
                            {
                                a++;
                                k = 1;
                            }
                        }
                    arr[i][v] = a;
                }
                v++;
            }
            ++x;
        }

    x = 0;
    v = 0;
    for (i = 1; i < 10; i++)
        {
            while(v <= x)
            {
                int firstnum = 1;
                int secondnum = 1;
                int thirdnum = firstnum + secondnum;
                if (arr[i][v] <= 0 || arr[i][v] == 1) arr[i][v] = 1;
                else if (arr[i][v] == 2) arr[i][v] == 2;
                else 
                {
                    while (thirdnum < arr[i][v])
                    {
                        firstnum = secondnum;
                        secondnum = thirdnum;
                        thirdnum = firstnum + secondnum;
                    }
                    if (thirdnum >= arr[i][v]) arr[i][v] = thirdnum;
                }
                v++;
            }
            ++x;
            v = 0;
        }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    string ans = "";
    for (i = 0; i < 10; i++)
    {
        int a = min(arr[i][7] , min(arr[i][8], arr[i][9]));
        int b = max(arr[i][7] , max(arr[i][8], arr[i][9]));
        int sum = arr[i][7] + arr[i][8] + arr[i][9];
        arr[i][8] = sum - a - b;
        arr[i][7] = a;
        arr[i][9] = b;
        int ma = arr[i][9];
        for (j = 9; j >= 0; j--)
        {
            if (arr[i][j] > ma) ma = arr[i][j];
        }
        for (j = 9; j >= 0; j--)
        {
            if (arr[i][j] == ma) 
            {
                ans = ans + to_string(j);
                break;
            }
        }
    }

    cout << "\n";
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return ans;
}

string sumstring(string s1, string s2)
    {
        string ans = "";

        int rem = 0;
        for (int i = 0; i < 10; i++)
        {
            int sum = (s1[i]-'0') + (s2[i]-'0') + rem;
            if (sum >= 10) {
            ans = ans + to_string(sum%10);
            rem = sum/10;
            }
            else 
            {
                rem = 0;
                ans = ans + to_string(sum);
            }
        }
        return ans;
    }

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    string t = pwd1 + ";" + pwd2 + ";" + pwd3 + ";" + sumstring(pwd1,pwd2) + ";" + sumstring(pwd1,pwd3) + ";" + sumstring(pwd2,pwd3) + ";" + sumstring(sumstring(pwd1,pwd2),pwd3) + ";" + sumstring(pwd1,sumstring(pwd2,pwd3)) + ";" + sumstring(sumstring(pwd1,pwd2),sumstring(pwd1,pwd3));
    return t;
}

void taximove(char moves, int &x, int &y, int arr[100][100])
    {
            if (moves == 'U') 
            {
                if (x > 0) 
                {
                    arr[x-1][y] = arr[x][y] + 9; 
                    //cout << arr[x-1][y]<< " ";
                    x--;
                }
            }
            else if (moves == 'D') 
            {
                if (x < 99)
                {
                    arr[x+1][y] = arr[x][y] + 9; 
                    //cout << arr[x+1][y]<< " ";
                    x++;
                }
            }
            else if (moves == 'L') 
            {
                if (y > 0)
                {   
                    arr[x][y-1] = arr[x][y] + 9; 
                    //cout << arr[x][y-1]<< " ";
                    y--;
                }
            }
            else if (moves == 'R') 
            {
                if (y < 99)
                {
                    arr[x][y+1] = arr[x][y] + 9;
                    //cout << arr[x][y+1] << " "; 
                    y++;
                }
            }
    }

bool isCaught(int arr[100][100], int time[], int xcor[], int ycor[], string &outTimes, string &outCatchUps, int numofpoints)
{
    for (int i = 0; i < numofpoints; i++)
    {
        if (arr[xcor[i]][ycor[i]] >= time[i])
        {
            for (int j = 0; j < numofpoints; j++)
            {
                if (j < i)
                {
                    outTimes += to_string(time[j]) + ";";
                    outCatchUps += "N;";
                }

                else if (j == i)
                {
                    outTimes += to_string(time[j]) + ";";
                    outCatchUps += "Y;";
                }

                else
                {
                    outTimes += "-;";
                    outCatchUps += "-;";
                }
            }
            outTimes.pop_back();
            outCatchUps.pop_back();
            return true;  
        }
    }
    return false;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            arr[i][j] = -9;
        }
    }
    arr[0][0] = 0;

    string temp = "";
    int arlen = 0;
    for (int i = 0; i < points.length(); i++)
    {
        if (points[i] == '-')
        {
            arlen++;
        }
    }

    //arlen is the number of "-"

    int xcor[arlen + 1]; //use to store xcor[0] = 0 of Sherlock;
    int ycor[arlen + 1]; //use to store ycor[0] = 0 of Sherlock;
    int indexa = 0;
    int indexb = 0;

    for (int i = 0; i < points.length(); i++)
    {
        if (points[i] == ',')
        {
            int a,b,c;
            for (a = i - 1; a >= 0; a--)
            {
                if (points[a] == '(')
                {
                    temp = "";
                    for (int k = a + 1; k <= i - 1; k++)
                    {
                        temp += points[k];
                    }
                    xcor[indexa] = stoi(temp);
                    indexa++;
                    
                    break;
                }
            }

            for (b = i + 1 ; ; b++)
            {
                if (points[b] == ')')
                {
                    temp = "";
                    for (int c = i + 1; c <= b - 1; c++)
                    {
                        temp += points[c];
                    }
                    ycor[indexb] = stoi(temp);
                    indexb++;
                    break;
                }
            }
        }
    }

    //arlen is the number of "-"

    int time[arlen + 1];
    time[0] = 14*(abs(xcor[0]) + abs(ycor[0]));
    //cout << time [0] << " ";
    for (int i = 1; i < arlen + 1; i++)
    {
        time[i] = 14*(abs(xcor[i] - xcor[i-1]) + abs(ycor[i] - ycor[i-1])) + time[i-1];
        //cout << time[i] << " ";
    }
    //cout << "\n";
    int a,b;
    a = b = 0;
    for (int t = 0; t < moves.length(); t++)
    {
        //process the moves of taxi
        taximove(moves[t],a,b,arr);
        
    }
    if (isCaught(arr,time , xcor,ycor, outTimes, outCatchUps,arlen + 1) == 1) return true;
    outTimes = "";
    outCatchUps = "";
    for (int t = 0; t < arlen + 1; t++)
    {
        outTimes += to_string(time[t]) +";";
        outCatchUps += "N;";
    }
    outTimes.pop_back();
    outCatchUps.pop_back();
    return false;
}

string enterLaptop(string tag, string message) {
    ifstream ifs2(tag);
    string temp;
    string email;
    int number;
    if (ifs2.is_open())
    {
        ifs2 >> temp >> email;
        ifs2 >> temp >> number;
    }

    temp = "";
    for (int i = 0; i < number; i++)
    {
        temp += message;
    }

    return email + ";" + temp;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */