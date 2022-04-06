#include <iostream>
#include <string>
namespace whoamifk {
    typedef uint64_t _size;
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
       error_mess, error_mess, "twenty", "thirty",
       "forty", "fifty", "sixty", "seventy",
       "eighty", "ninty",
    };
    static std::string _hundred = "hundred";
    static std::string _powers[] = {
       error_mess, "thousand", "million", "billion",
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
           return words(_num);
        }
        std::string words(const _size& num) {
            if (num > _maxnum) return error_mess;
            initbuf();
            _size n = num;
            if (n == 0) {
                appendbuf(_singles[n]);
                return _buf;
            }
            if (n >= 1000) {
                for (size_t i = 5; i > 0; --i) {
                    _size power = static_cast<_size>(pow(1000.0,i));
                    _size _n = (n - (n % power)) / power;
                    if (_n) {
                        _size index = i;
                        numword _nw(_n);
                        appendDel();
                        appendbuf(_nw.words());
                        appendDel();
                        appendbuf(_powers[index]);
                        n -= _n * power;
                    }
                }
            }
            if (n >= 100 && n < 1000) {
                _size _n = (n - (n % 100)) / 100;
                numword _nw(_n);
                appendDel();
                appendbuf(_nw.words());
                appendDel();
                appendbuf(_hundred);
                n -= _n * 100;
            }
            if (n >= 20 && n < 100) {
                _size _n = (n - (n % 10)) / 10;
                appendDel();
                appendbuf(_tens[_n]);
                n -= _n * 10;
                isHyphen = true;
            }
            if (n >= 10 && n < 20) {
                appendDel();
                appendbuf(_teens[n - 10]);
                n = 0;
            }
            if (n > 0 && n < 10) {
                appendDel();
                appendbuf(_singles[n]);
            }
            return _buf;
        }
        
        std::string operator()(const _size& num) {
            return words(num);
        }
        void appendbuf(std::string s) {
            _buf += s;
        }
        void appendDel() {
            if (_buflen) {
                appendbuf(isHyphen ? _hypen : _space);
                isHyphen = false;
            }
        }
    };
};

int main()
{
    whoamifk::numword nw;
    uint64_t n;
    n = 3;
    std::cout << "n is " << n << ", " << nw.words(n) << std::endl;
    n = 45;
    std::cout << "n is " << n << ", " << nw.words(n) << std::endl;
    n = 474142398123;
    std::cout << "n is " << n << ", " << nw.words(n) << std::endl;
    n = 999999999999999999;
    std::cout << "n is " << n << ", " << nw.words(n) << std::endl;
    n = 1000000000000000000;
    std::cout << "n is " << n << ", " << nw.words(n) << std::endl;
    return 0;
}