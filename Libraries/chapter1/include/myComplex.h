#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

class myComplex {
  public:

////////////////////////////////////////////////////////////////////////////////
//    DATA MEMBERS
////////////////////////////////////////////////////////////////////////////////

    //size of complex set
    static const size_t SIZE = 2;

    //array indicies of real and imaginary entries
    static const size_t REAL = 0;
    static const size_t IMAG = 1;

    // allow access of data via array-like or by direct addressing
    union {
      double _data[2];
      struct  {
        double realn;
        double imagn;
      };
    };

////////////////////////////////////////////////////////////////////////////////
//    CONSTRUCTORS/DESTRUCTORS
////////////////////////////////////////////////////////////////////////////////

    /**
     * default complex Constructor. intializes complex num to 0.0,0.0
     */
    myComplex();

    /**
     * construct a complex number from inputs
     * 
     * @param real the real component
     * @param imag the imaginary component
     */
    myComplex(const double real, const double imag);

    /** 
     * copy construct from another complex number
     * 
     * @param other the complex num to copy
     */
    myComplex(const myComplex& other);

    /**
     * destructor
     */
    ~myComplex();

////////////////////////////////////////////////////////////////////////////////
//    DATA ACCESSORS
////////////////////////////////////////////////////////////////////////////////

    /**
     * get real component
     */
    double real() const;

    /**
     * get imaginary component
     */
    double imag() const;

////////////////////////////////////////////////////////////////////////////////
//    ARITHMETIC OPERATIONS
////////////////////////////////////////////////////////////////////////////////

    /**
     * add a complex and real number
     */
    friend myComplex operator+(const myComplex& a, const double b);

    /**
     * add a complex and real number
     */
    friend myComplex operator+(const double b, const myComplex& a);

    /**
     * add two complex numbers
     */
    friend myComplex operator+(const myComplex& a, const myComplex& b);

    /**
     * subtract a complex and real number
     */
    friend myComplex operator-(const myComplex& a, const double b);

    /**
     * subtract a complex and real number
     */
    friend myComplex operator-(const double b, const myComplex& a);

    /**
     * subtract two complex numbers
     */
    friend myComplex operator-(const myComplex& a, const myComplex& b);

    /**
     * multiply a complex number by a constant
     */
    friend myComplex operator*(const myComplex& a, const double b);

    /**
     * multiply a complex number by a constant
     */
    friend myComplex operator*(const double b, const myComplex& a);

    /**
     * multiply two complex numbers together
     */
    friend myComplex operator*(const myComplex& b, const myComplex& a);

    /**
     * divide a complex number by a constant
     */
    friend myComplex operator/(const myComplex& a, const double b);

    /**
     * divide a complex number by a constant
     */
    friend myComplex operator/(const double b, const myComplex& a);

    /**
     * divide one complex number by another
     */
    friend myComplex operator/(const myComplex& b, const myComplex& a);

////////////////////////////////////////////////////////////////////////////////
//    UNARY OPERATIONS
////////////////////////////////////////////////////////////////////////////////

    /**
     * negation operator
     */
    friend myComplex operator-(const myComplex& a);

    /**
     * complex conjugate operator
     */
    static myComplex conj(const myComplex& a);

    /**
     * modulus operator
     */
    static double modulus(const myComplex& a);

    /**
     * the square of the modulus operator
     */
    static double modSqrd(const myComplex& a);

    /**
     * the result of adding the real and imaginary parts together.
     */
    static double magnitude(const myComplex& a);

////////////////////////////////////////////////////////////////////////////////
//    ASSIGNMENT
////////////////////////////////////////////////////////////////////////////////

    /**
     * copy assignment
     */
    myComplex &operator=(const myComplex& other);

////////////////////////////////////////////////////////////////////////////////
//    COMPARISON
////////////////////////////////////////////////////////////////////////////////

    /**
     * compares the real and imaginary parts of the complex number.
     */
    bool operator==(const myComplex& other) const;
};

#endif