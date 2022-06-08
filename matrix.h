#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>


class matrix {
public:
    matrix(unsigned w=0, unsigned h=0);

    matrix(const matrix& other);

    ~matrix();
    
   inline unsigned get_width() const
    {
        return width;
    }
    
    inline unsigned get_height() const
    {
        return height;
    }
    
    void set_width(unsigned w)
    {
        create_matrix(w, height);
    }
    
    void set_height(unsigned h)
    {
        create_matrix(width, h);
    }
    
    void set_value(unsigned i, unsigned j, double value);
    
    void print();
	
	matrix& operator = (const matrix& other);
	
    matrix operator *(const matrix& other) const;

    matrix& operator *=(const matrix& other);

    matrix operator *(double v);
    matrix operator +(const matrix& other);
    matrix operator +(double v);
    matrix transpose();

private:
    double** values;
    unsigned width;
    unsigned height;
    void create_matrix(unsigned w, unsigned h)
    {
        if(width != 0 && height != 0)
        {
            for(int i=0; i<height; i++)
                delete[] values[i];
            delete[] values;
        }
        this->width = w;
        this->height = h;
        if(w != 0 && h != 0)
        {
            values = new double *[height];
            for (int i = 0; i < height; i++) {
                values[i] = new double[width];
                for (int j = 0; j < width; j++)
                    values[i][j] = 1;
            }
        }
    }
};


#endif //MATRIX_MATRIX_H
