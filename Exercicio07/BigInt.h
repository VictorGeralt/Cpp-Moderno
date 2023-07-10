#include <iostream>
#include <string>

class BigInt
{
public:
    std::string numero;

    BigInt()
    {
        this->numero = "";
    }

    BigInt(std::string numero)
    {
        this->numero = numero;
    }

    BigInt(BigInt &numero)
    {
        this->numero = numero.numero;
    }

    int size()
    {
        return numero.size();
    }

    int compareString(std::string str1, std::string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 < len2)
        {
            return -1;
        }
        else if (len1 > len2)
        {
            return 1;
        }
        else
        {
            for (int i = 0; i < len1; i++)
            {
                if (str1[i] < str2[i])
                {
                    return -1;
                }
                else if (str1[i] > str2[i])
                {
                    return 1;
                }
            }
            return 0;
        }
    }

    BigInt operator+(const BigInt &b)
    {
        std::string num1 = numero;
        std::string num2 = b.numero;

        if (num1.length() < num2.length())
        {
            std::swap(num1, num2);
        }

        int n1 = num1.length();
        int n2 = num2.length();

        int carry = 0;
        BigInt result = BigInt();

        for (int i = 0; i < n2; i++)
        {
            int digit1 = num1[n1 - i - 1] - '0';
            int digit2 = num2[n2 - i - 1] - '0';
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.numero = std::to_string(sum % 10) + result.numero;
        }

        for (int i = n2; i < n1; i++)
        {
            int digit1 = num1[n1 - i - 1] - '0';
            int sum = digit1 + carry;
            carry = sum / 10;
            result = std::to_string(sum % 10) + result.numero;
        }

        if (carry)
        {
            result = std::to_string(carry) + result.numero;
        }

        return result;
    }

    BigInt operator-(const BigInt &b)
    {
        std::string num1 = numero;
        std::string num2 = b.numero;

        bool negative = false;
        if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2))
        {
            std::swap(num1, num2);
            negative = true;
        }

        int n1 = num1.length();
        int n2 = num2.length();

        BigInt result = BigInt();
        int carry = 0;

        for (int i = 0; i < n2; i++)
        {
            int digit1 = num1[n1 - i - 1] - '0';
            int digit2 = num2[n2 - i - 1] - '0';
            int diff = digit1 - digit2 - carry;
            carry = 0;
            if (diff < 0)
            {
                diff += 10;
                carry = 1;
            }
            result = std::to_string(diff) + result.numero;
        }

        for (int i = n2; i < n1; i++)
        {
            int digit1 = num1[n1 - i - 1] - '0';
            int diff = digit1 - carry;
            carry = 0;
            if (diff < 0)
            {
                diff += 10;
                carry = 1;
            }
            result = std::to_string(diff) + result.numero;
        }

        while (result.size() > 1 && result.numero[0] == '0')
        {
            result.numero.erase(0, 1);
        }

        if (negative)
        {
            result = "-" + result.numero;
        }

        return result;
    }
    BigInt operator*(const BigInt &b)
    {
        std::string num1 = numero;
        std::string num2 = b.numero;
        if (num1.length() < num2.length())
        {
            std::swap(num1, num2);
        }

        int n1 = num1.length();
        int n2 = num2.length();

        std::string result = "";

        for (int i = n2 - 1; i >= 0; i--)
        {
            int carry = 0;
            std::string partialResult = "";

            for (int j = 0; j < n2 - i - 1; j++)
            {
                partialResult += "0";
            }

            int digit2 = num2[i] - '0';
            for (int j = n1 - 1; j >= 0; j--)
            {
                int digit1 = num1[j] - '0';
                int product = digit1 * digit2 + carry;
                carry = product / 10;
                product %= 10;
                partialResult = std::to_string(product) + partialResult;
            }

            if (carry > 0)
            {
                partialResult = std::to_string(carry) + partialResult;
            }

            carry = 0;
            int n = result.length();
            for (int j = 0; j < partialResult.length(); j++)
            {
                int digit1 = j < n ? result[n - j - 1] - '0' : 0;
                int digit2 = partialResult[partialResult.length() - j - 1] - '0';
                int sum = digit1 + digit2 + carry;
                carry = sum / 10;
                sum %= 10;
                if (j < n)
                {
                    result[n - j - 1] = std::to_string(sum)[0];
                }
                else
                {
                    result = std::to_string(sum) + result;
                }
            }
            if (carry > 0)
            {
                result = std::to_string(carry) + result;
            }
        }

        while (result.length() > 1 && result[0] == '0')
        {
            result.erase(0, 1);
        }

        return result;
    }

    BigInt operator/(const BigInt &b)
    {

        std::string num1 = numero;
        std::string num2 = b.numero;

        int n1 = num1.length();
        int n2 = num2.length();
        BigInt quotient = BigInt();
        BigInt remainder = BigInt();

        for (int i = 0; i < num1.size(); i++)
        {
            remainder.numero += num1[i];
            int count = 0;
            while (compareString(remainder.numero, num2) >= 0)
            {
                remainder = remainder - num2;
                count++;
            }
            quotient.numero += std::to_string(count);
        }

        // remover zeros à esquerda do quociente
        while (quotient.numero.length() > 1 && quotient.numero[0] == '0')
        {
            quotient.numero.erase(0, 1);
        }

        return quotient;
    }
};

BigInt operator""_url(const char *str)
{

    return BigInt(str);
}
