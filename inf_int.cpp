#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string>
#include "inf_int.h"

inf_int::inf_int()
{
    /**
     * A default constructor (that doesn’t need any parameter)
     * will have a simple process to initialize the internal members.
     *
     * we will initialize the digit as zero,
     * additionally putting the null at the end of the digit array
     * to indicate the end of the string,
     * digits = {48, 0};
     *
     * and set the length as 1
     * and bool sign as true.
     */
    this->digits = new char[2]; // 동적할당

    this->digits[0] = '0'; // default 값 0 설정
    this->digits[1] = '\0';
    this->length = 1;
    this->thesign = true;
}

inf_int::inf_int(int n)
{
    char buf[100];

    if (n < 0)
    { // 음수 처리
        this->thesign = false;
        n = -n;
    }
    else
    {
        this->thesign = true;
    }

    int i = 0;
    while (n > 0)
    { // 숫자를 문자열로 변환하는 과정
        buf[i] = n % 10 + '0';

        n /= 10;
        i++;
    }

    if (i == 0)
    {                         // 숫자의 절댓값이 0일 경우
        new (this) inf_int(); // 생성자 재호출...gcc에서 컴파일에러가 있다고 함. inf_int()의 경우 별개의 인스턴스가 생성됨.
    }
    else
    {
        buf[i] = '\0';

        this->digits = new char[i + 1];
        this->length = i;
        strcpy(this->digits, buf);
    }
}

inf_int::inf_int(const char* str) // by 채승운
{
    int i;      //unsigned로 둘 때 positive case에서 역순 삽입 시 에러 발생
    if (str[0] == '-') // 음수일 때
    {
        this->thesign = false;
        this->length = strlen(str) - 1; // 음수 정수가 문자열의 형태로 들어온다면 실제 그 길이는 음수부호 제외
        this->digits = new char[length + 1];
        for (i = length - 1; i >= 0; i--)
        {
            digits[i] = str[length - i]; // 계산을 위한 역순 삽입, str[0] 제외
        }
    }
    else // 양수일 때
    {
        this->thesign = true;
        this->length = strlen(str); // 문자열의 형태로 들어온 모든 문자가 숫자임
        this->digits = new char[length + 1];
        for (i = length - 1; i >= 0; i--)
        {
            digits[i] = str[length - i - 1]; // 계산을 위한 역순 삽입, str[0]까지 모두 포함
        }
    }
}

inf_int::inf_int(const inf_int& a)
{
    this->digits = new char[a.length + 1];

    strcpy(this->digits, a.digits);
    this->length = a.length;
    this->thesign = a.thesign;
}

inf_int::~inf_int()
{
    delete digits; // 메모리 할당 해제
}

inf_int& inf_int::operator=(const inf_int& a)
{
    if (this->digits)
    {
        delete this->digits; // 이미 문자열이 있을 경우 제거.
    }
    this->digits = new char[a.length + 1];

    strcpy(this->digits, a.digits);
    this->length = a.length;
    this->thesign = a.thesign;

    return *this;
}

bool operator==(const inf_int& a, const inf_int& b)
{
    // we assume 0 is always positive.
    if ((strcmp(a.digits, b.digits) == 0) && a.thesign == b.thesign) // 부호가 같고, 절댓값이 일치해야함.
        return true;
    return false;
}

bool operator!=(const inf_int& a, const inf_int& b)
{
    return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b)
{
    if (a.thesign != b.thesign) // 두 부호가 다른 경우 a의 부호를 따라감, 양수>음수면 당연한 거고, 음수>양수면 false이므로 음수 반환해도 무방함.
        return a.thesign;

    if (a.thesign) // a가 양수일 때
    {
        if (a.length > b.length) // 길이가 길면 무조건 큼
            return true;
        else if (a.length < b.length) // 길이가 작으면 무조건 작음
            return false;
        else
        {
            for (int i = a.length - 1; i >= 0; i--) // 길이가 같다면 하나하나 비교 시작 (12345면 배열엔 54321이 담겨있는 상태)
            {
                if (a.digits[i] > b.digits[i])
                    return true;
                else if (a.digits[i] < b.digits[i])
                    return false;
                else
                    continue; // 같은 자릿수에 숫자까지 동일하다면 패스
            }
        }
    }
    else // a가 음수일 때
    {
        if (a.length > b.length) // 길이가 길면 무조건 작음
            return false;
        else if (a.length < b.length) // 길이가 작으면 무조건 큼
            return true;
        else
        {
            for (int i = a.length - 1; i >= 0; i--) // 길이가 같다면
            {
                if (a.digits[i] > b.digits[i])
                    return false;
                else if (a.digits[i] < b.digits[i])
                    return true;
                else
                    continue;
            }
        }
    }

    return false; // continue만 계속하여 반복문을 이탈해버린 상황, 이는 "같음"을 의미, 즉 이 함수의 목적인 ">"가 아니므로 false
}

bool operator<(const inf_int& a, const inf_int& b)
{
    if (operator>(a, b) || operator==(a, b))
    {
        return false;
    }
    else
    {
        return true;
    }
}

inf_int operator+(const inf_int& a, const inf_int& b)
{
    inf_int c;
    unsigned int i;

    if (a.thesign == b.thesign)
    { // 이항의 부호가 같을 경우 + 연산자로 연산
        for (i = 0; i < a.length; i++)
        {
            c.Add(a.digits[i], i + 1);
        }
        for (i = 0; i < b.length; i++)
        {
            c.Add(b.digits[i], i + 1);
        }

        c.thesign = a.thesign;

        return c;
    }
    else
    { // 이항의 부호가 다를 경우 - 연산자로 연산
        c = b;
        c.thesign = a.thesign;

        return a - c;
    }
}

inf_int operator-(const inf_int& a, const inf_int& b)   //코드 최적화 필요
{
    inf_int c;
    unsigned int i;

    if (a.thesign == b.thesign && a.thesign == true)
    { // 이항의 부호가 양수로 같을 경우
        if (a > b || a == b) {      //a의 절댓값이 b보다 크거나 같을 때
            for (i = 0; i < a.length; i++)
            {
                c.Add(a.digits[i], i + 1);
            }
            for (i = 0; i < b.length; i++)
            {
                c.Sub(b.digits[i], i + 1);
            }

            c.thesign = a.thesign;
        }
        else {      //a의 절댓값이 b보다 작을 때
            for (i = 0; i < b.length; i++)
            {
                c.Add(b.digits[i], i + 1);
            }
            for (i = 0; i < a.length; i++)
            {
                c.Sub(a.digits[i], i + 1);
            }

            c.thesign = !(a.thesign);
        }
        return c;
    }
    else if (a.thesign == b.thesign && a.thesign == false)
    { // 이항의 부호가 음수로 같을 경우
        if (a < b || a == b) {      //a의 절댓값이 b보다 크거나 같을 때
            for (i = 0; i < a.length; i++)
            {
                c.Add(a.digits[i], i + 1);
            }
            for (i = 0; i < b.length; i++)
            {
                c.Sub(b.digits[i], i + 1);
            }

            c.thesign = a.thesign;
        }
        else {      //a의 절댓값이 b보다 작을 때
            for (i = 0; i < b.length; i++)
            {
                c.Add(b.digits[i], i + 1);
            }
            for (i = 0; i < a.length; i++)
            {
                c.Sub(a.digits[i], i + 1);
            }

            c.thesign = !(a.thesign);
        }
        return c;
    }
    else
    { // 이항의 부호가 다를 경우 + 연산
        for (i = 0; i < a.length; i++)
        {
            c.Add(a.digits[i], i + 1);
        }
        for (i = 0; i < b.length; i++)
        {
            c.Add(b.digits[i], i + 1);
        }
        c.thesign = a.thesign;

        return c;
    }
}

inf_int operator*(const inf_int& a, const inf_int& b)
{
    inf_int c;

    for (unsigned int i = 0; i < a.length; ++i)
    {
        // traverse multiplicand
        for (unsigned int j = 0; j < b.length; ++j)
        {
            // traverse multiplier
            c.Add((a.digits[i] - '0') * (b.digits[j] - '0'), j + i + 1);
            // multiplicand와 multiplier의 한 자리수씩 곱한 결과 Add
        }
    }
    a.thesign == b.thesign ? c.thesign = true : c.thesign = false;
    // 이항 부호가 같다면 true, 다르다면 false
    return c;
}

inf_int operator/(const inf_int& a, const inf_int& b)
{
    inf_int c;

    // 제수의 길이가 피제수의 길이보다 길면, 몫을 '0'로 반환한다.
    // 예) 4567 / 23456 = 0 (나머지 : 4567)
    if (a.length < b.length)
        return c;
    else if (a.length == b.length)
    {
        // a, b 양수로 바꿔줌
        inf_int dividend(a);
        inf_int divisor(b);
        dividend.thesign = true;
        divisor.thesign = true;

        if (dividend < divisor)
        {
            // 예) 4567 / 4568 = 0 (나머지 : 4567)
            return c;
        }
        else
        {
            int subQ = 0;
            // 예) -4567 / 1111 = -4 (나머지 : -123)
            // 4567 / 1111 먼저 계산하고 부호 처리
            // 몫이 1의 자리만 나온다. 피제수에서 제수를 뺄 수 있을만큼 빼고, 뺀 횟수만큼 Add 함수를 통해 카운트해준다.
            while ( dividend > divisor || dividend == divisor)
            {
                dividend = dividend - divisor;

                subQ++;
            }

            c = inf_int(subQ);
            c.length = 1;
            c.thesign = (a.thesign == b.thesign ? true : false);
            return c;
        }
    }
    else
    {
        // 제수를 지속적으로 빼줄 가변적 피제수
        // ex) 456789 / 1111
        // q -> 345689, 234589, 123489, 11189, 79로 변화
        inf_int dividend(a);
        dividend.thesign = true;
        char buf[100000];
        int resultLength = 0;

        for (int i = a.length - b.length + 1; i >= 1; i--) {
            // ex) 456789 / 1111
            // divisor -> 111100, 11110

            inf_int divisor = b * inf_int(10).pow(i - 1);
            divisor.thesign = true;
            int subQ = 0;

            cout << "quotient " << dividend << endl;
            cout << "divisor: " << divisor << endl;

            while (dividend > divisor || dividend == divisor) {
                dividend = dividend - divisor;

                subQ++;
            }

            // 첫번째로 0이 나오면 건너뛰고 
            // 아니면 '0'을 버퍼에 넣어줌
            if (subQ == 0 && resultLength == 0)
                continue;

            // 각 자리 몫이 나오면, 해당 자리에 넣어줌.
            buf[resultLength++] = subQ + '0';
        }

        buf[resultLength] = '\0';

        c = inf_int(buf);
        c.length = resultLength;
        c.thesign = (a.thesign == b.thesign ? true : false);
        return c;
    }

    // 알 수 없는 오류로 분기문을 빠져나온 경우, (int_inf)'0' 반환
    return c;
}

inf_int operator%(const inf_int& a, const inf_int& b) {
    inf_int c;

    // a / b == Q (Remainder c)
    // a == b * Q + c
    // c == a - b * Q
    // c == a - b * (a / b) 
    c = a - (b * (a / b));

    // 나머지의 부호는 '=' 연산에서 처리
    return c;
}

ostream& operator<<(ostream& out, const inf_int& a)
{
    int i;

    if (a.thesign == false)
    {
        out << '-';
    }
    for (i = a.length - 1; i >= 0; i--)
    {
        out << a.digits[i];
    }
    return out;
}

void inf_int::Add(const int num, const unsigned int index) // a의 index 자리수에 n을 더한다. 0<=n<=9, ex) a가 82일때, Add(a, 36, 2)의 결과는 442
{
    if (this->length < index)
    {
        this->digits = (char*)realloc(this->digits, index + 1);
        if (this->digits == NULL)
        { // 할당 실패 예외처리
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }
        this->length = index;              // 길이 지정
        this->digits[this->length] = '\0'; // 널문자 삽입        
    }

    if (this->digits[index - 1] < '0')
    { // 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
        this->digits[index - 1] = '0';
    }

    int product = (this->digits[index - 1] - '0') + num;
    // 값 연산

    if (product > 9)
    {   // 자리올림이 발생하는 경우

        int carry = product / 10; // carry
        int remainder = product % 10; // remainder

        this->digits[index - 1] = (char)(remainder + 48);
        // remainder를 (아스키값) 48 더해 char로 변환해 현재 자릿수에 삽입
        Add(carry, index + 1);
        // carry는 다시한번 Add 호출
    }
    else {
        this->digits[index - 1] = (char)(product + 48);
        // 자리올림 발생하지 않는다면, product를 char로 변환해 바로 삽입
    }
}

void inf_int::Add(const char num, const unsigned int index) // a의 index 자리수에 n을 더한다. 0<=n<=9, ex) a가 391일때, Add(a, 2, 2)의 결과는 411
{
    if (this->length < index)
    {
        this->digits = (char*)realloc(this->digits, index + 1);
        if (this->digits == NULL)
        { // 할당 실패 예외처리
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }

        this->length = index;              // 길이 지정
        this->digits[this->length] = '\0'; // 널문자 삽입
    }

    if (this->digits[index - 1] < '0')
    { // 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
        this->digits[index - 1] = '0';
    }

    this->digits[index - 1] += num - '0'; // 값 연산

    if (this->digits[index - 1] > '9')
    {                                  // 자리올림이 발생할 경우
        this->digits[index - 1] -= 10; // 현재 자릿수에서 (아스키값) 10을 빼고
        Add('1', index + 1);           // 윗자리에 1을 더한다
    }
}

void inf_int::Sub(const char num, const unsigned int index) // a의 index 자리수에 n을 뺀다. 0<=n<=9, ex) a가 391일때, Sub(a, 2, 2)의 결과는 371
{
    if (this->length < index)
    {
        this->digits = (char*)realloc(this->digits, index + 1);
        if (this->digits == NULL)
        { // 할당 실패 예외처리
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }

        this->length = index;              // 길이 지정
        this->digits[this->length] = '\0'; // 널문자 삽입
    }

    if (this->digits[index - 1] < '0')
    { // 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
        this->digits[index - 1] = '0';
    }

    this->digits[index - 1] -= num - '0'; // 값 연산 (빼기)

    if (this->digits[index - 1] < '0')
    {                                  // 자리내림이 발생할 경우
        this->digits[index - 1] += 10; // 현재 자릿수에서 (아스키값) 10을 더하고
        Sub('1', index + 1);           // 윗자리에 1을 뺀다.
    }
    if (this->digits[this->length - 1] == '0')  // 자리수가 감소하는 경우 (가장 높은 자리수의 아스키값이 '0')
    {
        this->digits = (char*)realloc(this->digits, this->length);  // 아스키값이 '0'인 앞자리 제거를 위해 재할당
        if (this->digits == NULL)
        { // 할당 실패 예외처리
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }
        this->length = index - 1;              // 길이 재지정 (1 감소)
    }
    /*
    for (int i = this->length - 1; i >= 0; i--) {
        cout << this->digits[i];
    }
    cout << endl;
    */
}

inf_int inf_int::subInfInt(const unsigned int startIndex, const unsigned int endIndex) {
    /**
     * @brief return sub inf_int within index (likewise substr() of string),
     * thesign is same with parent inf_int
     * index starts with 1 (king received)
     *
     * @param startIndex
     * @param endIndex
     * @return sub inf_int within index (likewise substr() of string)
     */
     // ex) new inf_int('12345').subInfInt(2,4) == new inf_int('234')
    unsigned int _size = endIndex - startIndex + 1;

    inf_int temp(*this);
    string str = temp.digits;
    str = str.substr(startIndex - 1, _size);

    temp.digits = new char[_size];
    strcpy(temp.digits, str.c_str());
    temp.length = _size;
    temp.thesign = this->thesign;

    return temp;
}

inf_int inf_int::pow(const unsigned int exponent) {
    inf_int result(1);

    for (int i = 0; i < exponent; i++) {
        result = result * (*this);
    }

    return result;
}

string inf_int::getResultChar() {
    string returnVal = "";

    if (this->thesign == false){
        returnVal += '-';
    }
    for (int i = this->length - 1; i >= 0; i--){
        returnVal += this->digits[i];
    }

    return returnVal;
}