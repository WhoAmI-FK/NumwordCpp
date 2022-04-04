#include <iostream>
#include <string>
namespace whoamifk {
    typedef size_t _size;
    constexpr _size _maxlength = 1024;
    constexpr _size _maxnum = 999999999999999999;
    static const char* error_mess = "error";
    static std::string _singles[] = {
        "zero","one","two","three",
        "four","five","six","seven",
        "eight","nine"
    };
    static std::string _teens[] = {
       "ten", "eleven", "twelve", "thirteen",
       "fourteen", "fifteen", "sixteen",
       "seventeen", "eighteen", "nineteen"
    };
    static std::string _tens[] = {
       errnum, errnum, "twenty", "thirty",
       "forty", "fifty", "sixty", "seventy",
       "eighty", "ninty",
    };
    static std::string _hundred = "hundred";
    static std::string _powers[] = {
       errnum, "thousand", "million", "billion",
       "trillion", "quadrillion"
    };
    static std::string _hypen = "-";
    static std::string _space = " ";
    

    class numword {
    private:
        _size _num = 0;
        std::string _buf;
        _size _buflen;
        bool isHyphen = false;
    public:

    };
};

int main()
{
}