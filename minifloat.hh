#ifndef MINIFLOAT_HH
#define MINIFLOAT_HH

class minifloat
{
  public:
    minifloat();
    minifloat(float f);

    operator float () const;

    minifloat operator-() const;

    minifloat& operator=(minifloat m);
    minifloat& operator=(float m);

    minifloat& operator+=(minifloat m);
    minifloat& operator+=(float m);

    minifloat& operator-=(minifloat m);
    minifloat& operator-=(float m);

    minifloat& operator*=(minifloat m);
    minifloat& operator*=(float m);

    minifloat& operator/=(minifloat m);
    minifloat& operator/=(float m);

    bool isFinite() const;
    bool isNormalized() const;
    bool isDenormalized() const;
    bool isZero() const;
    bool isNan() const;
    bool isInfinity() const;
    bool isNegative() const;

    static minifloat posInf();
    static minifloat negInf();
    static minifloat qNan();
    static minifloat sNan();

    unsigned char bits() const;
    void setBits(unsigned char bits);

    union uif {
      unsigned char i:8;
      float f;
    }; 

  private:
    unsigned char _m;
};


std::ostream& operator << (std::ostream &os, minifloat m);
std::istream& operator >> (std::istream &is, minifloat &m);

inline
minifloat::minifloat() {}

inline
minifloat::minifloat(float f) {
    /* TODO */
    uif x;
    x.f = f;

    if (f == 0) {
        _m = (x.i >> 8);
    } else {
        unsigned char e = (x.i >> 4);

        /* TODO table lookup for e */

        if (e) {
            unsigned char m =  _m & 0b00000111;
            _m = e + (m + 0);
        } else {
            /* TODO create convert function */
        }
    }
}

inline
minifloat::operator float () const {
    /* TODO */
    return 0;
}


inline minifloat
minifloat::operator- () const {
    minifloat m;
    m._m = _m ^ 0b1000000;
}


inline minifloat&
minifloat::operator= (minifloat m) {
    _m = m._m;
    return *this;
}


inline minifloat&
minifloat::operator= (float f) {
    *this = minifloat(f);
    return *this;
}

inline minifloat &
minifloat::operator += (minifloat m)
{
    *this = minifloat (float (*this) + float (m));
    return *this;
}


inline minifloat &
minifloat::operator += (float f)
{
    *this = minifloat (float (*this) + f);
    return *this;
}


inline minifloat &
minifloat::operator -= (minifloat m)
{
    *this = minifloat (float (*this) - float (m));
    return *this;
}


inline minifloat &
minifloat::operator -= (float f)
{
    *this = minifloat (float (*this) - f);
    return *this;
}


inline minifloat &
minifloat::operator *= (minifloat m)
{
    *this = minifloat (float (*this) * float (m));
    return *this;
}


inline minifloat &
minifloat::operator *= (float f)
{
    *this = minifloat (float (*this) * f);
    return *this;
}


inline minifloat &
minifloat::operator /= (minifloat m)
{
    *this = minifloat (float (*this) / float (m));
    return *this;
}


inline minifloat &
minifloat::operator /= (float f)
{
    *this = minifloat (float (*this) / f);
    return *this;
}


inline bool 
minifloat::isFinite () const
{
    // Infinity values:
    // 0 1111 000 = +infinity
    // 1 1111 000 = -infinity
    unsigned char e = (_m >> 3) & 0b00001111;
    return e < 15;
}


inline bool
minifloat::isNormalized () const
{
    unsigned char e = (_m >> 3) & 0b00001111;
    return e > 0 && e < 15;
}


inline bool
minifloat::isDenormalized () const
{
    unsigned char e = (_m >> 3) & 0b00001111;
    unsigned char m =  _m & 0b00000111;
    return e == 0 && m != 0;
}


inline bool
minifloat::isZero () const
{
    return (_m & 0b01111111) == 0;
}


inline bool
minifloat::isNan () const
{
    unsigned char e = (_m >> 3) & 0b00001111;
    unsigned char m =  _m & 0b00000111;
    return e == 15 && m != 0;
}


inline bool
minifloat::isInfinity () const
{
    unsigned char e = (_m >> 3) & 0b00001111;
    unsigned char m =  _m & 0b00000111;
    return e == 15 && m == 0;
}


inline bool 
minifloat::isNegative () const
{
    return (_m & 0b10000000) != 0;
}


inline minifloat
minifloat::posInf ()
{
    minifloat m;
    m._m = 0b01111000;
    return m;
}


inline minifloat
minifloat::negInf ()
{
    minifloat m;
    m._m = 0b11111000;
    return m;
}


inline minifloat
minifloat::qNan ()
{
    /* TODO review */
    minifloat m;
    m._m = 0b01111111;
    return m;
}


inline minifloat
minifloat::sNan ()
{
    /* TODO review */
    minifloat m;
    m._m = 0b01111011;
    return m;
}


inline unsigned char
minifloat::bits () const
{
    return _m;
}


inline void
minifloat::setBits (unsigned char bits)
{
    _m = bits;
}


#endif  /* MINIFLOAT_HH */
