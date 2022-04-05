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
        _size _num;
        std::string _buf;
        _size _buflen;
        bool isHyphen;
        void clearBuff() {
            _buf.clear();
        }
        void initbuf() {
            clearBuff();
            isHyphen = false;
        }
    public:
        numword() : _num(0) {

        }
        numword(const _size& l) :
            _num(l)
        {

        }
        void setNum(const _size& l) {
            _num = l;
        }
        _size getNum() const {
            return _num;
        }
        std::string words() {
            words(_num);
        }
        std::string words(const _size& num) {
            if (num > _maxnum) return error_mess;
            initbuf();
            _size n = num;
            if (n == 0) {
                appendbuf(_singles[n]);
                return _buf;
            }
        }
        
        std::string operator()(const _size& num) {
            return words(num);
        }
        void appendbuf(std::string s) {
            _buf += s;
        }
    };
};

int main()
{
}