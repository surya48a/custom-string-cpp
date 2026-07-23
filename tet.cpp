#include "String.h"
#include <iostream>

using namespace std;
using namespace surya;

int main()
{
    cout << "========== Constructors ==========\n";

    STRING s1;
    STRING s2("Hello");
    STRING s3("World");
    STRING s4(s2);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;


    cout << "\n========== Assignment ==========\n";

    s1 = s2;
    cout << s1 << endl;


    cout << "\n========== Operator + ==========\n";

    cout << s2 + s3 << endl;
    cout << s2 + " Surya" << endl;
    cout << "Hi " + s2 << endl;


    cout << "\n========== Operator += ==========\n";

    s2 += s3;
    cout << s2 << endl;


    cout << "\n========== Comparison ==========\n";

    cout << (s2 == s3) << endl;
    cout << (s2 != s3) << endl;
    cout << (s2 > s3) << endl;
    cout << (s2 < s3) << endl;
    cout << (s2 >= s3) << endl;
    cout << (s2 <= s3) << endl;


    cout << "\n========== Indexing ==========\n";

    cout << s2[0] << endl;
    cout << s2[2] << endl;


    cout << "\n========== at/front/back ==========\n";

    cout << s2.at(1) << endl;
    cout << s2.front() << endl;
    cout << s2.back() << endl;


    cout << "\n========== Length ==========\n";

    cout << s2.length() << endl;
    cout << s2.size() << endl;


    cout << "\n========== Empty ==========\n";

    cout << s2.empty() << endl;


    cout << "\n========== c_str ==========\n";

    cout << s2.c_str() << endl;


    cout << "\n========== Push / Pop ==========\n";

    s2.push_back('X');
    cout << s2 << endl;

    s2.pop_back();
    cout << s2 << endl;


    cout << "\n========== Find ==========\n";

    cout << s2.find("lo") << endl;
    cout << s2.find("xyz") << endl;


    cout << "\n========== Compare ==========\n";

    cout << s2.compare(s3) << endl;


    cout << "\n========== Append ==========\n";

    s2.append(s3);
    cout << s2 << endl;


    cout << "\n========== Swap ==========\n";

    cout << "Before Swap\n";
    cout << s2 << endl;
    cout << s3 << endl;

    s2.swap(s3);

    cout << "After Swap\n";
    cout << s2 << endl;
    cout << s3 << endl;


    cout << "\n========== Clear ==========\n";

    s3.clear();
    cout << s3 << endl;
    cout << s3.empty() << endl;


    cout << "\n========== Friend Functions ==========\n";

    cout << strlen(s2) << endl;

    cout << strcmp(s2, s4) << endl;

    strcpy(s4, s2);
    cout << s4 << endl;

    strcat(s4, s3);
    cout << s4 << endl;

    strrev(s4);
    cout << s4 << endl;

    strupper(s4);
    cout << s4 << endl;

    strlower(s4);
    cout << s4 << endl;

    cout << strchr(s4, 'o') << endl;
    cout << strrchr(s4, 'o') << endl;

    cout << strstr(s4, "lo") << endl;
    cout << strstr(s4, s2) << endl;


    cout << "\n========== End ==========\n";
}
