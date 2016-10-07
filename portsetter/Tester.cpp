//Matthew Freeze
//CS3370
//Tester for portsetter program

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    //Test 1
    system("echo Test_1 >test.txt");
    int statusCode = system("./portsetter.cpp.o >>test.txt") / 256; 
    if (statusCode != 0) { cout << "Test 1 {setport}                    Failed\n";} 
        else { cout << "Test 1 {setport}                 Passed\n";}
    
    //Test 2
    system("echo '\n'Test_2 >>test.txt");
    statusCode = system("./portsetter.cpp.o -h >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 2 {setport -h}                Failed\n";} 
        else { cout << "Test 2 {setport -h}              Passed\n";}
        
    //Test 3
    system("echo '\n'Test_3 >>test.txt");
    statusCode = system("./portsetter.cpp.o --help >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 3 {setport --help}             Failed\n";} 
        else { cout << "Test 3 {setport --help}          Passed\n";}
    
    //Test 4
    system("echo '\n'Test_4 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p 4040 >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 4 {setport -p 4040}            Failed\n";} 
        else { cout << "Test 4 {setport -p 4040}         Passed\n";}
    
    //Test 5
    system("echo '\n'Test_5 >>test.txt");
    statusCode = system("./portsetter.cpp.o --port 4040 >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 5 {setport --port 4040}        Failed\n";} 
        else { cout << "Test 5 {setport --port 4040}     Passed\n";}
        
    //Test 6
    system("echo '\n'Test_6 >>test.txt");
    statusCode = system("./portsetter.cpp.o help >>test.txt") / 256;
    if (statusCode != 104) { cout << "Test 6 {setport help}             Failed\n";} 
        else { cout << "Test 6 {setport help}            Passed\n";}
    
    //Test 7
    system("echo '\n'Test_7 >>test.txt");
    statusCode = system("./portsetter.cpp.o -help >>test.txt") / 256;
    if (statusCode != 104) { cout << "Test 7 {setport -help}            Failed\n";} 
        else { cout << "Test 7 {setport -help}           Passed\n";}
       
    //Test 8
    system("echo '\n'Test_8 >>test.txt");
    statusCode = system("./portsetter.cpp.o --h >>test.txt") / 256;
    if (statusCode != 104) { cout << "Test 8 {setport --h}              Failed\n";} 
        else { cout << "Test 8 {setport --h}             Passed\n";}
    
    //Test 9
    system("echo '\n'Test_9 >>test.txt");
    statusCode = system("./portsetter.cpp.o -h --help >>test.txt") / 256;
    if (statusCode != 102) { cout << "Test 9 {setport -h --help}        Failed\n";} 
        else { cout << "Test 9 {setport -h --help}       Passed\n";}
    
    //Test 10
    system("echo '\n'Test_10 >>test.txt");
    statusCode = system("./portsetter.cpp.o -hs >>test.txt") / 256;
    if (statusCode != 104) { cout << "Test 10 {setport -hs}             Failed\n";} 
        else { cout << "Test 10 {setport -hs}            Passed\n";}
        
    //Test 11
    system("echo '\n'Test_11 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p --port 9 >>test.txt") / 256;
    if (statusCode != 106) { cout << "Test 11 {setport -p --port 9}     Failed\n";} 
        else { cout << "Test 11 {setport -p --port 9}    Passed\n";}
        
    //Test 12
    system("echo '\n'Test_12 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p 77 33 >>test.txt") / 256;
    if (statusCode != 106) { cout << "Test 12 {setport -p 77 33}        Failed\n";} 
        else { cout << "Test 12 {setport -p 77 33}       Passed\n";}
        
    //Test 13
    system("echo '\n'Test_13 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p -21 >>test.txt") / 256;
    if (statusCode != 103) { cout << "Test 13 {setport -p -21}          Failed\n";} 
        else { cout << "Test 13 {setport -p -21}         Passed\n";}
        
    //Test 14
    system("echo '\n'Test_14 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p 0 >>test.txt") / 256;
    if (statusCode != 103) { cout << "Test 14 {setport -p 0}            Failed\n";} 
        else { cout << "Test 14 {setport -p 0}           Passed\n";}
        
    //Test 15
    system("echo '\n'Test_15 >>test.txt");
    statusCode = system("./portsetter.cpp.o --port >>test.txt") / 256;
    if (statusCode != 104) { cout << "Test 15 {setport --port}          Failed\n";} 
        else { cout << "Test 15 {setport --port}         Passed\n";}
    
    //Test 16
    system("echo '\n'Test_16 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p 90642 >>test.txt") / 256;
    if (statusCode != 103) { cout << "Test 16 {setport -p 90642}        Failed\n";} 
        else { cout << "Test 16 {setport -p 90642}       Passed\n";}
    
    //Test 17
    system("echo '\n'Test_17 >>test.txt");
    statusCode = system("./portsetter.cpp.o -x 45321 >>test.txt") / 256;
    if (statusCode != 102) { cout << "Test 17 {setport -x 45321}        Failed\n";} 
        else { cout << "Test 17 {setport -x 45321}       Passed\n";}
    
    //Test 18
    system("echo '\n'Test_18 >>test.txt");
    statusCode = system("./portsetter.cpp.o -P 714 >>test.txt") / 256;
    if (statusCode != 102) { cout << "Test 18 {setport -P 714}          Failed\n";} 
        else { cout << "Test 18 {setport -P 714}         Passed\n";}
        
    //Test 19
    system("echo '\n'Test_19 >>test.txt");
    statusCode = system("./portsetter.cpp.o -? >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 19 {setport -?}                Failed\n";} 
        else { cout << "Test 19 {setport -?}             Passed\n";}
        
    //Test 20
    system("echo '\n'Test_20 >>test.txt");
    statusCode = system("./portsetter.cpp.o -! >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 20 {setport -!}                Failed\n";} 
        else { cout << "Test 20 {setport -!}             Passed\n";}
        
    //Test 21
    system("echo '\n'Test_21 >>test.txt");
    statusCode = system("./portsetter.cpp.o --about >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 21 {setport --about}          Failed\n";} 
        else { cout << "Test 21 {setport --about}        Passed\n";}
        
    //Test 22
    system("echo '\n'Test_22 >>test.txt");
    statusCode = system("./portsetter.cpp.o -v >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 22 {setport -v}              Failed\n";} 
        else { cout << "Test 22 {setport -v}             Passed\n";}
        
    //Test 23
    system("echo '\n'Test_23 >>test.txt");
    statusCode = system("./portsetter.cpp.o --version >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 23 {setport --version}       Failed\n";} 
        else { cout << "Test 23 {setport --version}      Passed\n";}
        
    //Test 24
    system("echo '\n'Test_24 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p -e PORT >>test.txt") / 256;
    if (statusCode != 0) { cout << "Test 24 {setport -p -e PORT}      Failed\n";} 
        else { cout << "Test 24 {setport -p -e PORT}     Passed\n";}
        
    //Test 25
    system("echo '\n'Test_25 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p -e FAKE_PRT >>test.txt") / 256;
    if (statusCode != 107) { cout << "Test 25 {setport -p -e FAKE_PRT}  Failed\n";} 
        else { cout << "Test 25 {setport -p -e FAKE_PRT} Passed\n";}
        
    //Test 26
    system("echo '\n'Test_26 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p -e C9_USER >>test.txt") / 256;
    if (statusCode != 108) { cout << "Test 26 {setport -p -e C9_USER}  Failed\n";} 
        else { cout << "Test 26 {setport -p -e C9_USER}  Passed\n";}
        
    //Test 27
    system("echo '\n'Test_27 >>test.txt");
    statusCode = system("./portsetter.cpp.o -p num >>test.txt") / 256;
    if (statusCode != 105) { cout << "Test 27 {setport -p num}        Failed\n";} 
        else { cout << "Test 27 {setport -p num}         Passed\n";}
    
    return 0;
}   
