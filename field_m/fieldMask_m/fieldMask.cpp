#include "fieldMask.h"

//Private section

int fldMask::dec_vect ( int sub , int res )
{
    if ( sub > 0 )
    {
        return res - 1 ;
    }
    return res + 1 ;
}

int fldMask::check_step ( int* &srcCrd , int* &resCrd )
{
    int size = 0 ;
    int subI = resCrd[1] - srcCrd[1] ;
    int subJ = resCrd[0] - srcCrd[0] ;
    int mdlI = abs ( subI ) ;
    int mdlJ = abs ( subJ ) ;
    if ( mdlI == 1 && mdlJ == 1 )
    {
        return 1 ;
    }
    if ( mdlI == 2 && mdlJ == 2 )
    {
        int rI = dec_vect ( subI , resCrd[1] ) ;
        int rJ = dec_vect ( subJ , resCrd[0] ) ;
        if ( mask[rI][rJ] >= 0 )
        {
            return 1 ;
        }
    }
    return 0 ;
}
int fldMask::generate_mask ( field &fldIn )
{
    mask = new int*[size] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        mask[i] = new int[size] ;
        for ( int j = 0 ; j < size ; j++ )
        {
            mask[i][j] = get_color_figure ( i , j , fldIn ) ;
        }
    }
    return 0 ;
}

void fldMask::free_mask ()
{
    for ( int i = 0 ; i < size ; i++ )
    {
        delete[] mask[i] ;
        mask[i] = nullptr ;
    }
    delete[] mask ;
    mask = nullptr ;
}

int fldMask::get_color_figure ( int iIn , int jIn , field &fldIN )
{
    int result = 0 ;
    cell* pCell = fldIN.get_cell ( iIn , jIn ) ;
    figure* pFg = pCell->get_point_figure () ;
    if ( pFg != nullptr )
    {
        if ( pFg->get_color () )
        {
            return 1 ;
        }
        return 0 ;
    }
    return -1 - ( ( iIn + jIn + 1  ) % 2 ) ;
}

int* fldMask::calc_border_for_start ( bool colorIn , int &sizeOut )
{
    int countOfBorders = 2 ;
    int* result = new int[countOfBorders] ;
    if ( colorIn )
    {
        result[0] = size / 2 + 1;
        result[1] = size ;
        return result ;
    }
    result[0] = 0 ;
    result[1] = size / 2 - 1 ;
    return result ;
}


bool fldMask::check_out_of_range ( int iIn , int jIn )
{
    return ( iIn >= 0 && iIn < size ) &&
            ( jIn >= 0 && jIn < size ) ;
}


//Public section

fldMask::fldMask ( field &fldIn )
{
    size = fldIn.get_size () ;
    generate_mask ( fldIn ) ;
}

fldMask::~fldMask ()
{
    free_mask () ;
}


int** fldMask::get_smart_mask ( bool color )
{
    int** result = new int*[size] ;
    int needInt = 0 ;
    if ( color )
    {
        needInt = 1 ; 
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        result[i] = new int[size] ;
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( mask[i][j] == needInt )
            {
                result[i][j] = calc_enemy_fgs ( i , j , color ) ;
            }
            else
            {
                result[i][j] = -1 ;
            }
        }
    }
    return result ;
}

int** fldMask::get_smart_empt_mask ( bool color )
{
    int** result = new int*[size] ;
    int needInt = 0 ;
    if ( color )
    {
        needInt = 1 ; 
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        result[i] = new int[size] ;
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( mask[i][j] == -1 )
            {
                result[i][j] = calc_enemy_fgs ( i , j , !color ) ;
            }
            else
            {
                result[i][j] = -3 ;
            }
        }
    }
    return result ;
}

int** fldMask::get_mask ( int &sizeOut )
{
    sizeOut = size ;
    return mask ;
}

int** fldMask::get_mask_of_steps ( int* &crdIn )
{
    int* resCrd = new int[crdDimns] ;
    int** resMask = new int*[size] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        resMask[i] = new int[size] ;
        resCrd[1] = i ;
        for ( int j = 0 ; j < size ; j++ )
        {
            resMask[i][j] = 0 ;
            resCrd[0] = j ;
            if ( check_step ( crdIn , resCrd ) ) 
            {
                if ( mask[i][j] == -1 )
                {
                    resMask[i][j] = 1 ;
                }
            }
        }
    }
    return resMask ;
}

int** fldMask::get_mask_for_start ( bool colorIn )
{
    int sizeB = 0 ;
    int* borders = calc_border_for_start ( colorIn , sizeB ) ;
    int** res = new int*[size] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        res[i] = new int[size] ;
        for ( int j = 0 ; j < size ; j++ )
        {
            res[i][j] = 0 ;
            if ( ( ( i + j ) % 2) &&
                    ( i < borders[1] && i >= borders[0] ) )
            {
                res[i][j] = 1 ;
            }
        }
    }
    return res ;
}


int fldMask::calc_enemy_fgs ( int iIn , int jIn , bool color )
{
    int needInt = 1 ;
    int result = 0 ;
    if ( color )
    {
        needInt = 0 ;
    }
    for ( int i = iIn - 1 ; i < iIn + 2 ; i+=2 )
    {
        for ( int j = jIn - 1 ; j < jIn + 2 ; j+=2 )
        {
            if ( check_out_of_range ( i , j ) &&
                ( mask[i][j] == needInt ) )
            {
                result++ ;
            }
        }
    }
    return result ;
}



void fldMask::print_mask ()
{
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( mask[i][j] >= 0 )
            {
                std::cout << " " ;
            }
            std::cout << mask[i][j] << " " ;
        }
        std::cout << std::endl ;
    }
}

void fldMask::print_smart_mask ( bool color )
{
    int** res = get_smart_mask ( color ) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( res[i][j] >= 0 )
            {
                std::cout << " " ;
            }
            std::cout << res[i][j] << " " ;
        }
        std::cout << std::endl ;
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        delete[] res[i] ;
    }
    delete[] res ;
    
}

void fldMask::print_smart_empt_mask ( bool color )
{
    int** res = get_smart_empt_mask ( color ) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( res[i][j] >= 0 )
            {
                std::cout << " " ;
            }
            std::cout << res[i][j] << " " ;
        }
        std::cout << std::endl ;
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        delete[] res[i] ;
    }
    delete[] res ;
    
}

void fldMask::print_mask_of_steps ( int* &crdIn )
{
    int** res = get_mask_of_steps ( crdIn ) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            std::cout << res[i][j] << " " ;
        }
        std::cout << std::endl ;
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        delete[] res[i] ;
    }
    delete[] res ;
}

void fldMask::print_mask_start ( bool colorIn )
{
    int** res = get_mask_for_start ( colorIn ) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            std::cout << res[i][j] << " " ;
        }
        std::cout << std::endl ;
    }
    for ( int i = 0 ; i < size ; i++ )
    {
        delete[] res[i] ;
    }
    delete[] res ;
}
