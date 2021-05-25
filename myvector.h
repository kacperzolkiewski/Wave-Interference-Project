#ifndef MYVECTOR_H
#define MYVECTOR_H


class MyVector
{
public:
    MyVector();

    void print() const;

    void set(double, double, double);

    double& operator[] (unsigned);

    MyVector operator+ (const MyVector& ) const;

    MyVector operator- (const MyVector& ) const;


private:
    double m_vector[4];

};

#endif // MYVECTOR_H
