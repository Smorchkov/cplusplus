#include "matrix.h"

matrix::matrix(unsigned w, unsigned h):width(0), height(0)
{
    create_matrix(w, h);
    std::cout<<"Constructor\n";
}

matrix::matrix(const matrix& other)
{
    this->width = other.width;
    this->height = other.height;
    values = new double*[height];
    for(int i=0; i<height; i++)
    {
        values[i] = new double[width];
            for(int j=0; j<width; j++)
                values[i][j] = other.values[i][j];
        }
        std::cout<<"Copy constructor\n";
}
    
matrix::~matrix()
{
	std::cout<<"Destructor\n";
        if(width != 0)
            for(int i=0; i<height; i++)
                delete[] values[i];
        if(height != 0)
            delete[] values;
}

void matrix::set_value(unsigned i, unsigned j, double value)
{
	if(i >= height || j >= width)
		std::cout<<"Warning! Element with coordinates ("<<i<<","<<j<<") doesn't exist\n";
    else
		values[i][j] = value;
}

void matrix::print()
{
    for(int i=0; i<height; i++)
    {
        for (int j = 0; j < width; j++)
           std::cout<<values[i][j]<<" ";
        std::cout<<std::endl;
    }
}

matrix& matrix::operator =(const matrix& other)
{
	    std::cout<<"Called operator = between matrix and matrix\n";

	        if (this == &other)
            return *this;
        this->width = other.width;
        this->height = other.height;
        values = new double*[height];
        for(int i=0; i<height; i++)
        {
            values[i] = new double[width];
            for(int j=0; j<width; j++)
                values[i][j] = other.values[i][j];
        }
        return *this;
}

matrix matrix::operator *(const matrix& other) const
{
	matrix result;
    std::cout<<"Called operator * between matrix and matrix\n";
    if(width != other.height)
    {
    	return result;
	}
	
	result.set_width(other.width);
	result.set_height(height);
	
	for(int i=0; i<height; i++)
	{
		
		for(int j=0; j<other.width; j++)
		{
			double v=0;

			for(int l=0; l<width; l++)
			{
				v = v + values[i][l]*other.values[l][j];
				result.set_value(i, j, v);	
			}
		}
	}
		
	return result;
}


matrix& matrix::operator *=(const matrix& other)
{
	matrix result;
    std::cout<<"Called operator *= between matrix and matrix\n";
    if(width != other.height)
    {
    	return result;
	}
	
	result.set_width(other.width);
	result.set_height(height);
	
	for(int i=0; i<height; i++)
	{
		
		for(int j=0; j<other.width; j++)
		{
			double v=0;

			for(int l=0; l<width; l++)
			{
				v = v + values[i][l]*other.values[l][j];
				result.set_value(i, j, v);	
			}
		}
	}
	
		this->width = result.width;
        this->height = result.height;
        values = new double*[height];
        for(int i=0; i<height; i++)
        {
            values[i] = new double[width];
            for(int j=0; j<width; j++)
                values[i][j] = other.values[i][j];
        }
        
    return *this;
}


matrix matrix::operator *(double v)
{       

	matrix result;
    std::cout<<"Called operator * between matrix and double\n";

	result.set_width(width);
	result.set_height(height);
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			result.set_value(i, j, v*values[i][j]);
		}
	}

	return result;
}

matrix matrix::operator +(const matrix& other)
{
	matrix result;
    std::cout<<"Called operator + between matrix and matrix\n";
    if(width != other.width || height != other.height)
    {
    	return result;
	}
	
	result.set_width(width);
	result.set_height(height);
	
	for(int i=0; i<height; i++)
	{
		
		for(int j=0; j<width; j++)
		{
			double v=0;
				v = values[i][j]+other.values[i][j];
				result.set_value(i, j, v);	
			}
		}
		
	return result;
}


matrix matrix::operator +(double v)
{       

	matrix result;
    std::cout<<"Called operator + between matrix and double\n";

	result.set_width(width);
	result.set_height(height);
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			result.set_value(i, j, v+values[i][j]);
		}
	}

	return result;
}

matrix matrix::transpose()
{
	matrix result;
	result.set_width(width);
	result.set_height(height);

	std::cout<<"Called transpose matrix\n";

	
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			result.set_value(i, j, values[j][i]);
		}
	}
	return result;

}
