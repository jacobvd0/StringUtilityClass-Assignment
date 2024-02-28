#include <iostream>
#include "String.h"
#include <fstream>

int main()
{ 
    // Creates/Opens log.txt and logs any successful/unsucessful results to it
    std::fstream logFile;
    logFile.open("log.txt", std::ios::out | std::ios::app);

    if (!logFile.is_open()) {
        std::cout << "Unable to open the log file. \n\nPress enter to exit.\n";
        std::cin.get();
        return 0;
    }

    struct tm newTime;
    time_t now = time(0);
    localtime_s(&newTime, &now);
    // Date: 5/02/2015 Time: 13:48:00 

    int sec = newTime.tm_sec;
    int minute = newTime.tm_min;
    int hour = newTime.tm_hour;
    int day = newTime.tm_mday;
    int month = 1 + newTime.tm_mon;
    int year = newTime.tm_year + 1900;

    logFile << "Date: " << day << "/" << month << "/" << year << " Time: " << hour << ":" << minute << ":" << sec << "\n";

    int testNum = 0;

    // Testing making a string
    String testString = "Hello, World";

    // Testing lengths and strings
    int lengthOfTest = testString.Length();
    std::cout << "String: " << testString.CStr() << "\nLength: " << lengthOfTest << "\n";
    if (lengthOfTest == 12) {
        logFile << "Test " << testNum << " Length Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " Length Unsuccessful\n";
        testNum++;
    }

    // testing comparing
    String sameString = "Hello, World";
    String differentString = "Not Hello, World";
    std::cout << "Testing Comparing: This should be 1 (true): " << testString.EqualTo(sameString) << "and this should be 0 (false): " << testString.EqualTo(differentString) << "\n";
    if (testString.EqualTo(sameString) && !testString.EqualTo(differentString)) {
        logFile << "Test " << testNum << " EqualTo Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " EqualTo Unsuccessful\n";
        testNum++;
    }

    // Testing making a string using another
    String s1 = "World";
    String s2 = s1;
    std::cout << "Testing creating strings using another string: Hello, " << s2.CStr() << "\n";

    

    // Writing to console
    testString.WriteToConsole();

    // testing the == operator
    if (testString == sameString) {
        std::cout << "Testing the == operator: This should be sent\n";
        logFile << "Test " << testNum << " EqualOperator Successful\n";
        testNum++;
    }
    else {
        std::cout << "Testing the == operator: This shouldn't be sent\n";
        logFile << "Test " << testNum << " EqualOperator Unsuccessful\n";
        testNum++;
    }
    if (testString == differentString) {
        std::cout << "Testing the == operator: This shouldn't be sent\n";
        logFile << "Test " << testNum << " EqualOperator Unsuccessful\n";
        testNum++;
    }
    else {
        std::cout << "Testing the == operator: This should be sent\n";
        logFile << "Test " << testNum << " EqualOperator Successful\n";
        testNum++;
    }

    // Testing the != operator
    if (testString != sameString) {
        std::cout << "Testing the != operator: This shouldn't be sent\n";
        logFile << "Test " << testNum << " NotEqualOperator Unsuccessful\n";
        testNum++;
    }
    else {
        std::cout << "Testing the != operator: This should be sent\n";
        logFile << "Test " << testNum << " NotEqualOperator Successful\n";
        testNum++;
    }
    if (testString != differentString) {
        std::cout << "Testing the != operator: This should be sent\n";
        logFile << "Test " << testNum << " NotEqualOperator Successful\n";
        testNum++;
    }
    else {
        std::cout << "Testing the != operator: This shouldn't be sent\n";
        logFile << "Test " << testNum << " NotEqualOperator Unsuccessful\n";
        testNum++;
    }

    // Testing CharacterAt
    std::cout << "The 5th letter is " << testString.CharacterAt(4) << "\n";
    if (testString.CharacterAt(4) == 'o') {
        logFile << "Test " << testNum << " CharacterAt Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " CharacterAt Unsuccessful\n";
        testNum++;
    }

    String uppercaseVersion = "HELLO, WORLD";
    // Testing ToUpper
    std::cout << testString.CStr() << " uppercase is " << testString.ToUpper().CStr() << "\n";

    if (testString.ToUpper().EqualTo(uppercaseVersion)) {
        logFile << "Test " << testNum << " ToUpper Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " ToUpper Unsuccessful\n";
        testNum++;
    }

    String lowercaseVersion = "hello, world";
    // Testing ToLower
    std::cout << testString.CStr() << " lowercase is " << testString.ToLower().CStr() << "\n";

    if (testString.ToLower().EqualTo(lowercaseVersion)) {
        logFile << "Test " << testNum << " ToLower Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " ToLower Unsuccessful\n";
        testNum++;
    }

    // Testing append
    String appendTest1 = "Hello, ";
    String appendTest2 = "World";
    std::cout << "Testing Append: " << appendTest1.Append(appendTest2).CStr() << "\n";

    if (appendTest1.Append(appendTest2).EqualTo(testString)) {
        logFile << "Test " << testNum << " Append Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " Append Unsuccessful\n";
        testNum++;
    }

    // Testing prepend
    std::cout << "Testing Prepend: " << appendTest2.Prepend(appendTest1).CStr() << "\n";

    if (appendTest2.Prepend(appendTest1).EqualTo(testString)) {
        logFile << "Test " << testNum << " Prepend Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " Prepend Unsuccessful\n";
        testNum++;
    }

    // Testing Finding
    std::cout << "Testing Finding: This should respond 0: " << testString.Find(testString) << "\n";

    if (testString.Find(testString) == 0) {
        logFile << "Test " << testNum << " Find Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " Find Unsuccessful\n";
        testNum++;
    }

    String thingToFind = "World";
    std::cout << "Testing Finding: This shouldn't respond 0: " << testString.Find(thingToFind) << "\n";

    if (testString.Find(thingToFind) != 0) {
        logFile << "Test " << testNum << " Find Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " Find Unsuccessful\n";
        testNum++;
    }

    // Testing finding w/ start index
    String findTest = "Hello, World Hello, World";
    std::cout << "Testing Finding with start index: This shouldn't respond 0: " << findTest.Find(12, thingToFind) << "\n";

    if (findTest.Find(12, thingToFind) != 0) {
        logFile << "Test " << testNum << " Find (with start index) Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " Find (with start index) Unsuccessful\n";
        testNum++;
    }

    // Testing = operator
    thingToFind = testString;
    std::cout << "Testing the = operator: " << thingToFind.CStr() << "\n";
    if (thingToFind.EqualTo(testString)) {
        logFile << "Test " << testNum << " EqualOperator Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " EqualOperator Unsuccessful\n";
        testNum++;
    }


    // Testing [] operator
    std::cout << "Testing [4]: " << thingToFind[4] << "\n";

    if (thingToFind[4] == 'o') {
        logFile << "Test " << testNum << " CheckIndex Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " CheckIndex Unsuccessful\n";
        testNum++;
    }

    // Testing <, >, <=, >=
    String a = "a";
    String b = "b";

    if (a > b) {
        std::cout << "a is before b\n";
        logFile << "Test " << testNum << " GreaterThan Successful\n";
        testNum++;
    }
    else {
        std::cout << "b is before a (this shouldn't be printed)\n";
        logFile << "Test " << testNum << " GreaterThan Unsuccessful\n";
        testNum++;
    }

    if (a < b) {
        std::cout << "b is before a (this shouldn't be printed)\n";
        logFile << "Test " << testNum << " LessThan Unsuccessful\n";
        testNum++;
    }
    else {
        std::cout << "a is before b\n";
        logFile << "Test " << testNum << " LessThan Successful\n";
        testNum++;
    }

    if (a <= a) {
        std::cout << "Testing the <= operator: works\n";
        logFile << "Test " << testNum << " LessThanOrEqual Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " LessThanOrEqual Unsuccessful\n";
        testNum++;
    }
    if (a >= a) {
        std::cout << "Testing the <= operator: works\n";
        logFile << "Test " << testNum << " GreaterThanOrEqual Successful\n";
        testNum++;
    }
    else {
        logFile << "Test " << testNum << " GreaterThanOrEqual Unsuccessful\n";
        testNum++;
    }


    // Testing replacing
    String replaceThis = "World";
    String withThis = "Hello";
    String replaceTest = "Hello, World";
    std::cout << "Hello, World with world replaced: " << replaceTest.Replace(replaceThis, withThis).CStr() << "\n";
    String thisShouldBeTheResult = "Hello, Hello";
    if (thisShouldBeTheResult.EqualTo(replaceTest.Replace(replaceThis, withThis))) {
        logFile << "Test " << testNum << " Replace Successful\n\n";
    }
    else {
        logFile << "Test " << testNum << " Replace Unsuccessful\n\n";
        testNum++;
    }

    // Testing reading from console
    std::cout << "Input a string: ";
    std::cout << "Your input is: " << a.ReadFromConsole().CStr() << "\n";
    

    logFile.close();
    system("pause");
    return 0;
}