#include "init.h"

long long* init::init_one_dimension_ll ( int iM )
{
    long long *nw = new long long[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = 0 ;
    }
    return nw ;
}

long long** init::init_two_dimension_ll ( int iM , int jM )
{
    long long **nw = new long long*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_ll ( jM ) ;
    }
    return nw ;
}

int* init::init_one_dimension_int ( int iM )
{
    int *nw = new int[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = 0 ;
    }
    return nw ;
}

int** init::init_two_dimension_int ( int iM , int jM )
{
    int **nw = new int*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_int ( jM ) ;
    }
    return nw ;
}

short int* init::init_one_dimension_sh ( int iM )
{
    short int *nw = new short int[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = 0 ;
    }
    return nw ;
}

short int** init::init_two_dimension_sh ( int iM , int jM )
{
    short int **nw = new short int*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_sh ( jM ) ;
    }
    return nw ;
}

float* init::init_one_dimension_fl ( int iM )
{
    float *nw = new float[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = 0 ;
    }
    return nw ;
}

float** init::init_two_dimension_fl ( int iM , int jM )
{
    float **nw = new float*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_fl ( jM ) ;
    }
    return nw ;
}

double* init::init_one_dimension_db ( int iM )
{
    double *nw = new double[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = 0 ;
    }
    return nw ;
}

double** init::init_two_dimension_db ( int iM , int jM )
{
    double **nw = new double*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_db ( jM ) ;
    }
    return nw ;
}

bool* init::init_one_dimension_bl ( int iM )
{
    bool *nw = new bool[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = 0 ;
    }
    return nw ;
}

bool** init::init_two_dimension_bl ( int iM , int jM )
{
    bool **nw = new bool*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_bl ( jM ) ;
    }
    return nw ;
}

std::string* init::init_one_dimension_str ( int iM )
{
    std::string *nw = new std::string[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = "" ;
    }
    return nw ;
}

std::string** init::init_two_dimension_str ( int iM , int jM )
{
    std::string **nw = new std::string*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension_str ( jM ) ;
    }
    return nw ;
}

