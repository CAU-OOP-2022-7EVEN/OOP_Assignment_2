#include <iostream>
#include "inf_int_test.h"
#include "inf_int.h"

using namespace std;

void inf_int_test::TestDefault()
{
    inf_int a, e;
    inf_int b(100);
    inf_int c("-123451987651234572749499923455022211");
    inf_int d("-321111111111122222222222233333333333444444444445555555555");
    inf_int f = d;
    inf_int g(f);

    // cin >> g ;   // not required

    a = b * c;
    // e=g/f;       // not required

    b = c - d;

    if (f == d)
    {
        cout << "a : " << a << endl;
        cout << "b : " << b << endl;
        cout << "c : " << c << endl;
        cout << "d : " << d << endl;
        // cout << "e : " << e << endl;
        cout << "f : " << f << endl;
        // cout << "g : " << g << endl;
    }
}

void inf_int_test::TestOperate4digits()
{
    pair<int, int> testA[5] = {make_pair(1000, 2000), make_pair(1120, 4892), make_pair(4728, 3850), make_pair(4829, 2492), make_pair(3294, 1111)};
    cout << "---------- 천(1000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<int, int> testB[5] = {make_pair(-1000, -2000), make_pair(-1120, -4892), make_pair(-4728, -3850), make_pair(-4829, -2492), make_pair(-3294, -1111)};
    cout << "---------- 천(1000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate4digitsWith2digits()
{
    pair<int, int> testA[5] = {make_pair(1000, 20), make_pair(1120, 48), make_pair(4728, 38), make_pair(4829, 24), make_pair(3294, 11)};
    cout << "---------- 천(1000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<int, int> testB[5] = {make_pair(-1000, -20), make_pair(-1120, -48), make_pair(-4728, -38), make_pair(-4829, -24), make_pair(-3294, -11)};
    cout << "---------- 천(1000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 천(1000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate10digits()
{
    pair<const char *, const char *> testA[5] = {
        make_pair("1000000000", "2000000000"),
        make_pair("1120000000", "4800000000"),
        make_pair("4728000000", "3800000000"),
        make_pair("4829000000", "2400000000"),
        make_pair("3294000000", "1100000000")};
    cout << "---------- 10억(1000000000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<const char *, const char *> testB[5] = {
        make_pair("-1000000000", "-2000000000"),
        make_pair("-1120000000", "-4800000000"),
        make_pair("-4728000000", "-3800000000"),
        make_pair("-4829000000", "-2400000000"),
        make_pair("-3294000000", "-1100000000")};
    cout << "---------- 10억(1000000000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate10digitsWith5digits()
{
    pair<const char *, const char *> testA[5] = {
        make_pair("1000000000", "20000"),
        make_pair("1120000000", "48000"),
        make_pair("4728000000", "38000"),
        make_pair("4829000000", "24000"),
        make_pair("3294000000", "11000")};
    cout << "---------- 10억(1000000000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<const char *, const char *> testB[5] = {
        make_pair("-1000000000", "-20000"),
        make_pair("-1120000000", "-48000"),
        make_pair("-4728000000", "-12355"),
        make_pair("-4829000000", "-45646"),
        make_pair("-3294000000", "-92395")};
    cout << "---------- 10억(1000000000)의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10억(1000000000)의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate50digits()
{
    pair<const char *, const char *> testA[5] = {
        make_pair("1000000000000000000000000000000000000000000000000", "2000000000000000000000000000000000000000000000000"),
        make_pair("1120000000000000000000000000000000000000000000000", "4800000000000000000000000000000000000000000000000"),
        make_pair("4728000000000000000000000000000000000000000000000", "3800000000000000000000000000000000000000000000000"),
        make_pair("4829000000000000000000000000000000000000000000000", "2400000000000000000000000000000000000000000000000"),
        make_pair("3294000000000000000000000000000000000000000000000", "1100000000000000000000000000000000000000000000000")};
    cout << "---------- 10^50의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<const char *, const char *> testB[5] = {
        make_pair("-1000000000000000000000000000000000000000000000000", "-20000000000000000000000000000000000000000000"),
        make_pair("-1120000000000000000000000000000000000000000000000", "-48000000000000000000000000000000000000000000"),
        make_pair("-4728000000000000000000000000000000000000000000000", "-12355000000000000000000000000000000000000000"),
        make_pair("-4829000000000000000000000000000000000000000000000", "-45646000000000000000000000000000000000000000"),
        make_pair("-3294000000000000000000000000000000000000000000000", "-92395000000000000000000000000000000000000000")};
    cout << "---------- 10^50의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate50digitsWith25digits()
{
    pair<const char *, const char *> testA[5] = {
        make_pair("1000000000000000000000000000000000000000000000000", "200000000000000000000000"),
        make_pair("1120000000000000000000000000000000000000000000000", "480000000000000000000000"),
        make_pair("4728000000000000000000000000000000000000000000000", "380000000000000000000000"),
        make_pair("4829000000000000000000000000000000000000000000000", "240000000000000000000000"),
        make_pair("3294000000000000000000000000000000000000000000000", "110000000000000000000000")};
    cout << "---------- 10^50의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<const char *, const char *> testB[5] = {
        make_pair("-1000000000000000000000000000000000000000000000000", "-200000000000000000000000"),
        make_pair("-1120000000000000000000000000000000000000000000000", "-480000000000000000000000"),
        make_pair("-4728000000000000000000000000000000000000000000000", "-123550000000000000000000"),
        make_pair("-4829000000000000000000000000000000000000000000000", "-456460000000000000000000"),
        make_pair("-3294000000000000000000000000000000000000000000000", "-923950000000000000000000")};
    cout << "---------- 10^50의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^50의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate100digits()
{
    pair<const char *, const char *> testA[5] = {
        make_pair("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("112000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "480000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("472800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "380000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("482900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "240000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("329400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
    };
    cout << "---------- 10^100의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<const char *, const char *> testB[5] = {
        make_pair("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("-112000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-480000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("-472800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-123550000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("-482900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-456460000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
        make_pair("-329400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-923950000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")};
    cout << "---------- 10^100의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}

void inf_int_test::TestOperate100digitsWith50digits()
{
    pair<const char *, const char *> testA[5] = {
        make_pair("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "2000000000000000000000000000000000000000000000000"),
        make_pair("112000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "4800000000000000000000000000000000000000000000000"),
        make_pair("472800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "3800000000000000000000000000000000000000000000000"),
        make_pair("482900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "2400000000000000000000000000000000000000000000000"),
        make_pair("329400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "1100000000000000000000000000000000000000000000000")
    };
    cout << "---------- 10^100의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " + " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) + inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " - " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) - inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " * " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) * inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " / " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) / inf_int(testA[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testA[i].first) << " % " << inf_int(testA[i].second) << " = " << inf_int(testA[i].first) % inf_int(testA[i].second) << endl;
    }

    pair<const char *, const char *> testB[5] = {
        make_pair("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-2000000000000000000000000000000000000000000000000"),
        make_pair("-112000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-4800000000000000000000000000000000000000000000000"),
        make_pair("-472800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-1235500000000000000000000000000000000000000000000"),
        make_pair("-482900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-4564600000000000000000000000000000000000000000000"),
        make_pair("-329400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "-9239500000000000000000000000000000000000000000000")};
    cout << "---------- 10^100의 자리 더하기(+) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " + " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) + inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 빼기(-) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " - " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) - inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 곱하기(*) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " * " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) * inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나누기(/) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " / " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) / inf_int(testB[i].second) << endl;
    }
    cout << '\n'
         << "---------- 10^100의 자리 나머지(%) 케이스 -----------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " : " << inf_int(testB[i].first) << " % " << inf_int(testB[i].second) << " = " << inf_int(testB[i].first) % inf_int(testB[i].second) << endl;
    }
}
