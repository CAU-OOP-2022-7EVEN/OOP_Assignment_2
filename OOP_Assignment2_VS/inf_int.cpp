#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string>
#include "inf_int.h"

inf_int::inf_int() {
    /**
     * A default constructor (that doesn��t need any parameter)
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
    this->digits = new char[2]; // Dynamic Allocation
    this->digits[0] = '0';      // Set Default Value to 0
    this->digits[1] = '\0';
    this->length = 1;
    this->thesign = true;
}

inf_int::inf_int(int n) {
    char buf[100];

    if (n < 0) {
        // ���� ó��
        this->thesign = false;
        n = -n;
    }
    else {
        this->thesign = true;
    }

    int i = 0;
    while (n > 0) {
        // ���ڸ� ���ڿ��� ��ȯ�ϴ� ����
        buf[i] = n % 10 + '0';

        n /= 10;
        i++;
    }

    if (i == 0) {
        // ������ ������ 0�� ���
        new (this) inf_int();
    }
    else {
        buf[i] = '\0';

        this->digits = new char[i + 1];
        this->length = i;
        strcpy(this->digits, buf);
    }
}

inf_int::inf_int(const char* str) {
    //unsigned�� �� �� positive case���� ���� ���� �� ���� �߻�
    if (str[0] == '-') {
        // ������ ��
        this->thesign = false;
        this->length = strlen(str) - 1; // ���� ������ ���ڿ��� ���·� ���´ٸ� ���� �� ���̴� ������ȣ ����
        this->digits = new char[length + 1];
        for (int i = length - 1; i >= 0; i--) {
            // ����� ���� ���� ����, str[0] ����
            digits[i] = str[length - i];
        }
    }
    else {
        // ����� ��
        this->thesign = true;
        this->length = strlen(str); // ���ڿ��� ���·� ���� ��� ���ڰ� ������
        this->digits = new char[length + 1];
        for (int i = length - 1; i >= 0; i--) {
            // ����� ���� ���� ����, str[0]���� ��� ����
            digits[i] = str[length - i - 1];
        }
    }
}

inf_int::inf_int(const inf_int& a) {
    this->digits = new char[a.length + 1];

    strcpy(this->digits, a.digits);
    this->length = a.length;
    this->thesign = a.thesign;
}

inf_int::~inf_int() {
    // �޸� �Ҵ� ����
    delete digits;
}

inf_int& inf_int::operator=(const inf_int& a) {
    // �̹� ���ڿ��� ���� ��� ����
    delete this->digits;

    this->digits = new char[a.length + 1];

    strcpy(this->digits, a.digits);
    this->length = a.length;
    this->thesign = a.thesign;

    return *this;
}

bool operator==(const inf_int& a, const inf_int& b) {
    // we assume 0 is always positive.
    if ((strcmp(a.digits, b.digits) == 0) && a.thesign == b.thesign) {
        // ��ȣ�� ����, ������ ��ġ�ؾ���
        return true;
    }
    return false;
}

bool operator!=(const inf_int& a, const inf_int& b) {
    return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b) {
    // �� ��ȣ�� �ٸ� ��� a�� ��ȣ�� ����, ���>������ �翬�� �Ű�, ����>����� false�̹Ƿ� ���� ��ȯ�ص� ������.
    if (a.thesign != b.thesign) {
        return a.thesign;
    }

    if (a.thesign) {
        // a�� ����� ��
        if (a.length > b.length) {
            // ���̰� ��� ������ ŭ
            return true;
        }
        else if (a.length < b.length) {
            // ���̰� ������ ������ ����
            return false;
        }
        else {
            for (int i = a.length - 1; i >= 0; i--) {
                // ���̰� ���ٸ� �ϳ��ϳ� �� ���� (12345�� �迭�� 54321�� ����ִ� ����)
                if (a.digits[i] > b.digits[i]) {
                    return true;
                }
                else if (a.digits[i] < b.digits[i]) {
                    return false;
                }
                else {
                    // ���� �ڸ����� ���ڱ��� �����ϴٸ� �н�
                    continue;
                }
            }
        }
    }
    else {
        // a�� ������ ��
        if (a.length > b.length) {
            // ���̰� ��� ������ ����
            return false;
        }
        else if (a.length < b.length) {
            // ���̰� ������ ������ ŭ
            return true;
        }
        else {
            for (int i = a.length - 1; i >= 0; i--) {
                // ���̰� ���ٸ�
                if (a.digits[i] > b.digits[i]) {
                    return false;
                }
                else if (a.digits[i] < b.digits[i]) {
                    return true;
                }
                else {
                    continue;
                }
            }
        }
    }

    // continue�� ����Ͽ� �ݺ����� ��Ż�ع��� ��Ȳ, �̴� "����"�� �ǹ�, �� �� �Լ��� ������ ">"�� �ƴϹǷ� false
    return false;
}

bool operator<(const inf_int& a, const inf_int& b) {
    if (operator>(a, b) || operator==(a, b)) {
        return false;
    }
    else {
        return true;
    }
}

inf_int operator+(const inf_int& a, const inf_int& b) {
    inf_int c;

    if (a.thesign == b.thesign) {
        // ������ ��ȣ�� ���� ��� + �����ڷ� ����
        for (unsigned int i = 0; i < a.length; i++) {
            c.Add(a.digits[i], i + 1);
        }
        for (unsigned int i = 0; i < b.length; i++) {
            c.Add(b.digits[i], i + 1);
        }

        c.thesign = a.thesign;

        return c;
    }
    else {
        // ������ ��ȣ�� �ٸ� ��� - �����ڷ� ����
        c = b;
        c.thesign = a.thesign;

        return a - c;
    }
}

inf_int operator-(const inf_int& a, const inf_int& b) {
    inf_int c;

    if (a.thesign == b.thesign && !strcmp(a.digits, b.digits)) {
        // �� ���� ������ ���
        c.Add(0, 1);
        c.thesign = true;

        return c;
    }

    if (a.thesign == b.thesign && a.thesign) {
        // ������ ��ȣ�� ����� ���� ���
        if (a > b || a == b) {
            //a�� ������ b���� ũ�ų� ���� ��
            for (unsigned int i = 0; i < a.length; i++) {
                c.Add(a.digits[i], i + 1);
            }
            for (unsigned int i = 0; i < b.length; i++) {
                c.Sub(b.digits[i], i + 1);
            }

            c.thesign = a.thesign;
        }
        else {
            //a�� ������ b���� ���� ��
            for (unsigned int i = 0; i < b.length; i++) {
                c.Add(b.digits[i], i + 1);
            }
            for (unsigned int i = 0; i < a.length; i++) {
                c.Sub(a.digits[i], i + 1);
            }

            c.thesign = !(a.thesign);
        }
    }
    else if (a.thesign == b.thesign && !a.thesign) {
        // ������ ��ȣ�� ������ ���� ���
        if (a < b || a == b) {
            //a�� ������ b���� ũ�ų� ���� ��
            for (unsigned int i = 0; i < a.length; i++) {
                c.Add(a.digits[i], i + 1);
            }
            for (unsigned int i = 0; i < b.length; i++) {
                c.Sub(b.digits[i], i + 1);
            }

            c.thesign = a.thesign;
        }
        else {
            //a�� ������ b���� ���� ��
            for (unsigned int i = 0; i < b.length; i++) {
                c.Add(b.digits[i], i + 1);
            }
            for (unsigned int i = 0; i < a.length; i++) {
                c.Sub(a.digits[i], i + 1);
            }

            c.thesign = !(a.thesign);
        }
    }
    else {
        // ������ ��ȣ�� �ٸ� ��� + ����
        for (unsigned int i = 0; i < a.length; i++) {
            c.Add(a.digits[i], i + 1);
        }
        for (unsigned int i = 0; i < b.length; i++) {
            c.Add(b.digits[i], i + 1);
        }
        c.thesign = a.thesign;
    }

    /**
     * @brief c �� ���η� '0000'�� ���� ��� �������� ������
     */
    int _size = c.length;
    while (c.digits[_size - 1] == '0') {
        _size--;
    }

    char* _digits = new char[_size + 1];
    for (int idx = _size - 1; idx >= 0; idx--) {
        _digits[idx] = c.digits[idx];
    }
    _digits[_size] = '\0';

    c.digits = new char[_size + 1];
    strcpy(c.digits, _digits);
    c.length = _size;

    return c;
}

inf_int operator*(const inf_int& a, const inf_int& b) {
    inf_int c;

    for (unsigned int i = 0; i < a.length; ++i) {
        // traverse multiplicand
        for (unsigned int j = 0; j < b.length; ++j) {
            // traverse multiplier
            c.Add((a.digits[i] - '0') * (b.digits[j] - '0'), j + i + 1);
            // multiplicand�� multiplier�� �� �ڸ����� ���� ��� Add
        }
    }
    a.thesign == b.thesign ? c.thesign = true : c.thesign = false;

    // ���� ��ȣ�� ���ٸ� true, �ٸ��ٸ� false
    return c;
}

inf_int operator/(const inf_int& a, const inf_int& b) {
    inf_int c;

    // ZERO-Division
    if (b.length == 1 && b.digits[0] == '0') {
        c.digits = new char[4];
        c.digits[0] = 'N';
        c.digits[1] = 'a';
        c.digits[2] = 'N';
        c.digits[3] = '\0';
        c.length = 3;
        c.thesign = true;
        return c;
    }

    // ������ ���̰� �������� ���̺��� ���, ���� '0'�� ��ȯ�Ѵ�.
    // ��) 4567 / 23456 = 0 (������ : 4567)
    if (a.length < b.length) {
        return c;
    }
    else if (a.length == b.length) {
        // a, b ����� �ٲ���
        inf_int dividend(a);
        inf_int divisor(b);
        dividend.thesign = true;
        divisor.thesign = true;

        if (dividend < divisor) {
            // ��) 4567 / 4568 = 0 (������ : 4567)
            return c;
        }
        else {
            int subQ = 0;
            // ��) -4567 / 1111 = -4 (������ : -123)
            // 4567 / 1111 ���� ����ϰ� ��ȣ ó��
            // ���� 1�� �ڸ��� ���´�. ���������� ������ �� �� ������ŭ ����, �� Ƚ����ŭ Add �Լ��� ���� ī��Ʈ���ش�.
            while (dividend > divisor || dividend == divisor) {
                dividend = dividend - divisor;

                subQ++;
            }

            c = inf_int(subQ);
            c.length = 1;
            c.thesign = a.thesign == b.thesign;
            return c;
        }
    }
    else {
        // ������ ���������� ���� ������ ������
        // ex) 456789 / 1111
        // q -> 345689, 234589, 123489, 11189, 79�� ��ȭ
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

            while (dividend > divisor || dividend == divisor) {
                dividend = dividend - divisor;

                subQ++;
            }

            // ù��°�� 0�� ������ �ǳʶٰ� 
            // �ƴϸ� '0'�� ���ۿ� �־���
            if (subQ == 0 && resultLength == 0)
                continue;

            // �� �ڸ� ���� ������, �ش� �ڸ��� �־���.
            buf[resultLength++] = subQ + '0';
        }

        buf[resultLength] = '\0';

        c = inf_int(buf);
        c.length = resultLength;
        c.thesign = a.thesign == b.thesign;

        return c;
    }
}

inf_int operator%(const inf_int& a, const inf_int& b) {
    inf_int c;

    // a / b == Q (Remainder c)
    // a == b * Q + c
    // c == a - b * Q
    // c == a - b * (a / b) 
    c = a - (b * (a / b));

    if (c.digits[0] == '\0')
        return inf_int();

    // �������� ��ȣ�� '=' ���꿡�� ó��
    return c;
}

ostream& operator<<(ostream& out, const inf_int& a) {
    if (!a.thesign) {
        out << '-';
    }

    for (int i = a.length - 1; i >= 0; i--) {
        out << a.digits[i];
    }

    return out;
}

void inf_int::Add(const int num, const unsigned int index) {
    // a�� index �ڸ����� n�� ���Ѵ�. 0<=n<=9, ex) a�� 82�϶�, Add(a, 36, 2)�� ����� 442
    if (this->length < index) {
        this->digits = (char*)realloc(this->digits, index + 1);
        if (this->digits == nullptr) {
            // �Ҵ� ���� ����ó��
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }
        this->length = index;              // ���� ����
        this->digits[this->length] = '\0'; // �ι��� ����        
    }

    if (this->digits[index - 1] < '0') {
        // ���� ���� '0'���� ���� �ƽ�Ű���� ��� 0���� ä��. �������� �ʾҴ� ���ο� �ڸ����� ��� �߻�
        this->digits[index - 1] = '0';
    }

    // �� ����
    int product = (this->digits[index - 1] - '0') + num;

    if (product > 9) {
        // �ڸ��ø��� �߻��ϴ� ���

        int carry = product / 10; // carry
        int remainder = product % 10; // remainder

        this->digits[index - 1] = (char)(remainder + 48);
        // remainder�� (�ƽ�Ű��) 48 ���� char�� ��ȯ�� ���� �ڸ����� ����
        Add(carry, index + 1);
        // carry�� �ٽ��ѹ� Add ȣ��
    }
    else {
        this->digits[index - 1] = (char)(product + 48);
        // �ڸ��ø� �߻����� �ʴ´ٸ�, product�� char�� ��ȯ�� �ٷ� ����
    }
}

void inf_int::Add(const char num, const unsigned int index) {
    // a�� index �ڸ����� n�� ���Ѵ�. 0<=n<=9, ex) a�� 391�϶�, Add(a, 2, 2)�� ����� 411
    if (this->length < index) {
        this->digits = (char*)realloc(this->digits, index + 1);
        if (this->digits == nullptr) {
            // �Ҵ� ���� ����ó��
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }

        this->length = index;              // ���� ����
        this->digits[this->length] = '\0'; // �ι��� ����
    }

    if (this->digits[index - 1] < '0') {
        // ���� ���� '0'���� ���� �ƽ�Ű���� ��� 0���� ä��. �������� �ʾҴ� ���ο� �ڸ����� ��� �߻�
        this->digits[index - 1] = '0';
    }

    this->digits[index - 1] += num - '0'; // �� ����

    if (this->digits[index - 1] > '9') {
        // �ڸ��ø��� �߻��� ���
        this->digits[index - 1] -= 10; // ���� �ڸ������� (�ƽ�Ű��) 10�� ����
        Add('1', index + 1);           // ���ڸ��� 1�� ���Ѵ�
    }
}

void inf_int::Sub(const char num, const unsigned int index) {
    // a�� index �ڸ����� n�� ����. 0<=n<=9, ex) a�� 391�϶�, Sub(a, 2, 2)�� ����� 371
    if (this->length < index) {
        this->digits = (char*)realloc(this->digits, index + 1);
        if (this->digits == nullptr) {
            // �Ҵ� ���� ����ó��
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }

        this->length = index;              // ���� ����
        this->digits[this->length] = '\0'; // �ι��� ����
    }

    if (this->digits[index - 1] < '0') {
        // ���� ���� '0'���� ���� �ƽ�Ű���� ��� 0���� ä��. �������� �ʾҴ� ���ο� �ڸ����� ��� �߻�
        this->digits[index - 1] = '0';
    }

    this->digits[index - 1] -= num - '0'; // �� ���� (����)

    if (this->digits[index - 1] < '0') {
        // �ڸ������� �߻��� ���
        this->digits[index - 1] += 10; // ���� �ڸ������� (�ƽ�Ű��) 10�� ���ϰ�
        Sub('1', index + 1);           // ���ڸ��� 1�� ����.
    }

    if (this->digits[this->length - 1] == '0') {
        // �ڸ����� �����ϴ� ��� (���� ���� �ڸ����� �ƽ�Ű���� '0')
        this->digits = (char*)realloc(this->digits, this->length);  // �ƽ�Ű���� '0'�� ���ڸ� ���Ÿ� ���� ���Ҵ�
        if (this->digits == NULL) {
            // �Ҵ� ���� ����ó��
            cout << "Memory reallocation failed, the program will terminate." << endl;
            exit(0);
        }
        this->length = index - 1;              // ���� ������ (1 ����)
    }
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

    if (!this->thesign) {
        returnVal += '-';
    }

    for (int i = this->length - 1; i >= 0; i--) {
        returnVal += this->digits[i];
    }

    return returnVal;
}