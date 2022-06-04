#include <iostream>
#include "studyInPink2.h"
#include <sstream>
#include <string>
#include <cstring>
#include <fstream> 
using namespace std;
int numberTest = 10000; // number of Testcase
int main() {
    ifstream inp("input.txt"); ifstream outp("output.txt"); int resTask1 = 0, resTask2 = 0, resTask3 = 0; 
    for (int q=1; q<= numberTest; q++) {
        ofstream ntb1("ntb1.txt"); string excess, line1, line2; getline(inp,excess); getline(inp,excess); getline(inp,line1); getline(inp,line2); ntb1 << line1; 
        if (line2 != "---------") ntb1 << endl << line2; ntb1.close(); ofstream ntb2("ntb2.txt"); string line; getline(inp,line);
        if (line != "---------") ntb2 << line << endl; else line = ""; getline(inp,line); ntb2 << line; while (true) {getline(inp,line); if (line == "---------") break; ntb2 << endl << line;}
        ntb2.close(); ofstream ntb3("ntb3.txt"); for (int i=0; i<10; i++) {getline(inp,line); if (i!=9) ntb3 << line << endl; else ntb3 << line;}
        ntb3.close(); ofstream mission2("mission2.txt"); getline(inp, excess); getline(inp, line); mission2 << line << endl; getline(inp, line); mission2 << line; mission2.close(); 
        ofstream mission3("mission3.txt"); getline(inp, excess); getline(inp, line); mission3 << line << endl; getline(inp, line); mission3 << line; mission3.close(); getline(inp, excess); 
        // cout << "TESTCASE #" << q << endl; 
        string pwd1Out, pwd2Out, pwd3Out, listPwdOut, outTimesOut, outCatchUpsOut, mailOut; char reachedOut_c; bool reachedOut;
        outp >> excess >> excess >> excess >> pwd1Out >> excess >> pwd2Out >> excess >> pwd3Out >> excess >> excess >> listPwdOut >> excess >> excess >> reachedOut_c;
        reachedOut = reachedOut_c - '0'; outp >> excess >> outTimesOut >> excess >> outCatchUpsOut >> mailOut ;
        string pwd1User = notebook1("ntb1.txt"); string pwd2User = notebook2("ntb2.txt"); string pwd3User = notebook3("ntb3.txt"); string listPwdUser = generateListPasswords(pwd1User, pwd2User, pwd3User);
        int arr[100][100]; string outTimes, outCatchUps; string points, moves; ifstream mis2("mission2.txt"); mis2 >> points; mis2 >> moves; bool reached = chaseTaxi(arr, points, moves, outTimes, outCatchUps);
        mis2.close(); string loginInfo = enterLaptop("mission3.txt", "Rachel"); 
        // cout << "pw1: "; if (pwd1User == pwd1Out) cout << "Passed!"; else cout << "Not passed! ##########";
        // cout << endl << "pw2: "; if (pwd2User == pwd2Out) cout << "Passed!"; else cout << "Not passed! ##########"; 
        // cout << endl << "pw3: "; if (pwd3User == pwd3Out) cout << "Passed!"; else cout << "Not passed! ##########";
        // cout << endl << "List passwords: "; if (listPwdUser == listPwdOut) cout << "Passed!"; else cout << "Not passed! ##########"; 
        if (pwd1User == pwd1Out and pwd2User == pwd2Out and pwd3User == pwd3Out and listPwdUser == listPwdOut) resTask1++;
        // cout << endl << "Can reach: "; if (reached == reachedOut) cout << "Passed!"; else cout << "Not passed! ##########"; 
        // cout << endl << "outTimes: "; if (outTimes == outTimesOut) cout << "Passed!"; else cout << "Not passed! ##########";
        // cout << endl << "outCatchUps: "; if (outCatchUps == outCatchUpsOut) cout << "Passed!"; else cout << "Not passed! ##########"; 
        if (reached == reachedOut and outTimes == outTimesOut and outCatchUps == outCatchUpsOut) resTask2++; else cout << "TESTCASE #" << q << endl; 
        // cout << endl << "Laptop's password: "; if (loginInfo == mailOut) cout << "Passed!"; else cout << "Not passed! ##########";
        if (loginInfo == mailOut) resTask3++; 
    }
    // int task1 = ceil(((double) resTask1 / numberTest)*100); 
    // int task2 = ceil(((double) resTask2 / numberTest)*100); 
    // int task3 = ceil(((double) resTask3 / numberTest)*100); 
    cout << "Final result:" << endl; 
    cout << "Task 1: " << resTask1 << "/10000" << endl; 
    cout << "Task 2: " << resTask2 << "/10000" << endl;
    cout << "Task 3: " << resTask3 << "/10000" << endl; 
    inp.close(); outp.close();
}