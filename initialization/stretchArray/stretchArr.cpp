#include "stretchArr.h"

long long* stretchArr::rsz_arr_once_ll ( long long* src , int &iM )
{
    long long *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_ll ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

long long* stretchArr::rsz_add_arr_once_ll ( long long* src ,
        long long data , int &iM )
{
    long long *result = rsz_arr_once_ll ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

long long** stretchArr::rsz_arr_twice_ll ( long long **src , int &iM ,
        int &jM )
{
    long long **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_ll ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

long long** stretchArr::rsz_add_arr_twice_ll ( long long **src ,
        long long *data , int &iM , int &jM )
{
    long long **result = rsz_arr_twice_ll ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}

int* stretchArr::rsz_arr_once_int ( int* src , int &iM )
{
    int *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_int ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

int* stretchArr::rsz_add_arr_once_int ( int* src ,
        int data , int &iM )
{
    int *result = rsz_arr_once_int ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

int** stretchArr::rsz_arr_twice_int ( int **src , int &iM ,
        int &jM )
{
    int **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_int ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

int** stretchArr::rsz_add_arr_twice_int ( int **src ,
        int *data , int &iM , int &jM )
{
    int **result = rsz_arr_twice_int ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}

short int* stretchArr::rsz_arr_once_sh ( short int* src , int &iM )
{
    short int *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_sh ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

short int* stretchArr::rsz_add_arr_once_sh ( short int* src ,
        short int data , int &iM )
{
    short int *result = rsz_arr_once_sh ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

short int** stretchArr::rsz_arr_twice_sh ( short int **src , int &iM ,
        int &jM )
{
    short int **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_sh ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

short int** stretchArr::rsz_add_arr_twice_sh ( short int **src ,
        short int *data , int &iM , int &jM )
{
    short int **result = rsz_arr_twice_sh ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}

double* stretchArr::rsz_arr_once_db ( double* src , int &iM )
{
    double *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_db ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

double* stretchArr::rsz_add_arr_once_db ( double* src ,
        double data , int &iM )
{
    double *result = rsz_arr_once_db ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

double** stretchArr::rsz_arr_twice_db ( double **src , int &iM ,
        int &jM )
{
    double **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_db ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

double** stretchArr::rsz_add_arr_twice_db ( double **src ,
        double *data , int &iM , int &jM )
{
    double **result = rsz_arr_twice_db ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}

float* stretchArr::rsz_arr_once_fl ( float* src , int &iM )
{
    float *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_fl ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

float* stretchArr::rsz_add_arr_once_fl ( float* src ,
        float data , int &iM )
{
    float *result = rsz_arr_once_fl ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

float** stretchArr::rsz_arr_twice_fl ( float **src , int &iM ,
        int &jM )
{
    float **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_fl ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

float** stretchArr::rsz_add_arr_twice_fl ( float **src ,
        float *data , int &iM , int &jM )
{
    float **result = rsz_arr_twice_fl ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}

bool* stretchArr::rsz_arr_once_bl ( bool* src , int &iM )
{
    bool *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_bl ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

bool* stretchArr::rsz_add_arr_once_bl ( bool* src ,
        bool data , int &iM )
{
    bool *result = rsz_arr_once_bl ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

bool** stretchArr::rsz_arr_twice_bl ( bool **src , int &iM ,
        int &jM )
{
    bool **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_bl ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

bool** stretchArr::rsz_add_arr_twice_bl ( bool **src ,
        bool *data , int &iM , int &jM )
{
    bool **result = rsz_arr_twice_bl ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}

std::string* stretchArr::rsz_arr_once_str ( std::string* src , int &iM )
{
    std::string *result = NULL ;
    if ( ( src != NULL ) && iM > 0 )
    {
        int nIM = iM + 1 ;
        result = init::init_one_dimension_str ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

std::string* stretchArr::rsz_add_arr_once_str ( std::string* src ,
        std::string data , int &iM )
{
    std::string *result = rsz_arr_once_str ( src , iM ) ;
    if ( result != NULL )
    {
        result[iM - 1] = data ;
        delete [] src ;
    }
    return result ;
}

std::string** stretchArr::rsz_arr_twice_str ( std::string **src , int &iM ,
        int &jM )
{
    std::string **result = NULL ;
    if ( ( src != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        int nIM = iM + 1 ;
        result = init::init_two_dimension_str ( nIM , jM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
            delete [] src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

std::string** stretchArr::rsz_add_arr_twice_str ( std::string **src ,
        std::string *data , int &iM , int &jM )
{
    std::string **result = rsz_arr_twice_str ( src , iM , jM ) ;
    if ( ( result != NULL ) && ( iM > 0 ) && ( jM > 0 ) )
    {
        result[iM - 1] = data ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            delete [] src[i] ;
        }
        delete [] src ;
    }
    return result ;
}
