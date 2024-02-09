#include <iostream>
#include "String.h"

int main()
{
    std::cout << "Hello World!\n";
    String testString = "Hello, World";

    // Testing lengths and strings
    std::cout << "String: " << testString.CStr() << "\nLength: " << testString.Length() << "\n";

    // testing comparing
    String sameString = "Hello, World";
    String differentString = "Not Hello, World";
    std::cout << "Testing Comparing: This should be 1 (true): " << testString.EqualTo(sameString) << "and this should be 0 (false): " << testString.EqualTo(differentString) << "\n";

    // Testing making a string using another
    String s1 = "World";
    String s2 = s1;
    std::cout << "Testing creating strings using another string: Hello, " << s2.CStr() << "\n";

    // Writing to console
    testString.WriteToConsole();

    // testing the == operator
    if (testString == sameString) {
        std::cout << "Testing the == operator: This should be sent\n";
    }
    else {
        std::cout << "Testing the == operator: This shouldn't be sent\n";
    }
    if (testString == differentString) {
        std::cout << "Testing the == operator: This shouldn't be sent\n";
    }
    else {
        std::cout << "Testing the == operator: This should be sent\n";
    }

    // Testing the != operator
    if (testString != sameString) {
        std::cout << "Testing the != operator: This shouldn't be sent\n";
    }
    else {
        std::cout << "Testing the != operator: This should be sent\n";
    }
    if (testString != differentString) {
        std::cout << "Testing the != operator: This should be sent\n";
    }
    else {
        std::cout << "Testing the != operator: This shouldn't be sent\n";
    }

    // Testing CharacterAt
    std::cout << "The 5th letter is " << testString.CharacterAt(4) << "\n";

    // Testing ToUpper
    std::cout << testString.CStr() << " uppercase is " << testString.ToUpper().CStr() << "\n";

    // Testing ToLower
    std::cout << testString.CStr() << " lowercase is " << testString.ToLower().CStr() << "\n";

    // Testing append
    String appendTest1 = "Hello, ";
    String appendTest2 = "World";
    std::cout << "Testing Append: " << appendTest1.Append(appendTest2).CStr() << "\n";

    // Testing prepend
    std::cout << "Testing Prepend: " << appendTest2.Prepend(appendTest1).CStr() << "\n";

    // Testing Finding
    std::cout << "Testing Finding: This should respond 0: " << testString.Find(testString) << "\n";
    String thingToFind = "World";
    std::cout << "Testing Finding: This shouldn't respond 0: " << testString.Find(thingToFind) << "\n";

    // Testing finding w/ start index
    String findTest = "Hello, World Hello, World";
    std::cout << "Testing Finding with start index: This shouldn't respond 0: " << findTest.Find(12, thingToFind) << "\n";

    // Testing = operator
    thingToFind = testString;
    std::cout << "Testing the = operator: " << thingToFind.CStr() << "\n";

    // Testing [] operator
    std::cout << "Testing [4]: " << thingToFind[4] << "\n";

    // Testing <, >, <=, >=
    String a = "a";
    String b = "b";

    if (a > b) {
        std::cout << "a is before b\n";
    }
    else {
        std::cout << "b is before a (this shouldn't be printed)\n";
    }

    if (a < b) {
        std::cout << "b is before a (this shouldn't be printed)\n";
    }
    else {
        std::cout << "a is before b\n";
    }

    if (a <= a) {
        std::cout << "Testing the <= operator: works\n";
    }
    if (a >= a) {
        std::cout << "Testing the <= operator: works\n";
    }


    // Testing replacing
    String replaceThis = "World";
    String withThis = "Hello";
    String replaceTest = "Hello, World";
    std::cout << "Hello, World with world replaced: " << replaceTest.Replace(replaceThis, withThis).CStr() << "\n";


    // Testing reading from console
    std::cout << "Input a string: ";
    std::cout << "Your input is: " << a.ReadFromConsole().CStr() << "\n";

    system("pause");
    return 0;
}