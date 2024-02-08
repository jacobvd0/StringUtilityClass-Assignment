#include <iostream>
#include "String.h"

int main()
{
    std::cout << "Hello World!\n";
    String testString = "Hello, World";
    // tesing lengths and strings
    std::cout << "String: " << testString.CStr() << "\nLength: " << testString.Length() << "\n";

    // testing comparing
    String sameString = "Hello, World";
    String differentString = "Not Hello, World";
    std::cout << "This should be true: " << testString.EqualTo(sameString) << "\nThis should be false: " << testString.EqualTo(differentString) << "\n";

    // Testing making a string using another
    String s1 = "works!";
    String s2 = s1;
    std::cout << "This " << s2.CStr() << "\n";

    // Writing to console
    testString.WriteToConsole();

    // testing the == operator
    if (testString == sameString) {
        std::cout << "This should be sent\n";
    }
    else {
        std::cout << "This shouldn't be sent\n";
    }
    if (testString == differentString) {
        std::cout << "This shouldn't be sent\n";
    }
    else {
        std::cout << "This should be sent\n";
    }

    // Testing the != operator
    if (testString != sameString) {
        std::cout << "This shouldn't be sent\n";
    }
    else {
        std::cout << "This should be sent\n";
    }
    if (testString != differentString) {
        std::cout << "This should be sent\n";
    }
    else {
        std::cout << "This shouldn't be sent\n";
    }

    // Testing CharacterAt
    std::cout << "The 5th letter is " << testString.CharacterAt(4) << "\n";

    // Testing ToUpper
    std::cout << testString.ToUpper().CStr() << "\n";

    // Testing ToLower
    std::cout << testString.ToLower().CStr() << "\n";

    // Testing append
    std::cout << testString.Append(differentString).CStr() << "\n";

    // Testing prepend
    std::cout << testString.Prepend(differentString).CStr() << "\n";

    // Testing Finding
    std::cout << "This should respond 0: " << testString.Find(sameString) << "\n";
    String thingToFind = "World";
    std::cout << "This shouldn't respond 0: " << testString.Find(thingToFind) << "\n";

    // Testing finding w/ start index
    String findTest = "Hello, World Hello, World";
    std::cout << "This shouldn't respond 0: " << findTest.Find(12, thingToFind) << "\n";

    // Testing = operator
    thingToFind = findTest;
    std::cout << "Changed: " << thingToFind.CStr() << "\n";

    // Testing [] operator
    std::cout << thingToFind[4] << "\n";
}