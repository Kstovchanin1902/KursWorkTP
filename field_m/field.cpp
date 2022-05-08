#include "field.h"

//Private section

void field::free_cells ()
{
    if ( cls != nullptr )
    {
        for ( int i = 0 ; i < size ; i++ )
        {
            delete[] cls[i] ;
        }
        delete[] cls ;
        cls = nullptr ;
    }
}

int field::calc_count_w_cells ()
{
    int result = 0 ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( cls[i][j].get_color () )
            {
                result++ ;
            }
        }
    }
    return result ;
}

int field::calc_count_b_cells ()
{
    int result = 0 ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( !( cls[i][j].get_color () ) )
            {
                result++ ;
            }
        }
    }
    return result ;
}

int field::calc_count_cells_with_w_fg ()
{
    int result = 0 ;
    bool colorFg = false ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            colorFg = cls[i][j].get_point_figure ()->get_color () ;
            if ( colorFg )
            {
                result++ ;
            }
        }
    }
    return result ;
}

int field::calc_count_cells_with_b_fg ()
{
    int result = 0 ;
    bool colorFg = false ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            colorFg = cls[i][j].get_point_figure ()->get_color () ;
            if ( !colorFg )
            {
                result++ ;
            }
        }
    }
    return result ;
}

int field::calc_count_cells_with_all_fg ()
{
    int result = 0 ;
    result += calc_count_cells_with_b_fg () ;
    result += calc_count_cells_with_w_fg () ;
    return result ;
}


void field::print_underline ()
{
    print_void () ;
    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout << "-------" ;
    }
    std::cout << std::endl ;
}

void field::print_numberline ()
{
    print_void () ;
    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout << "   " << i << "   " ;
    }
    std::cout << std::endl ;
}

void field::print_void ()
{
    std::cout << "       " ;
}


//Public section

field::field ()
{
    cls = nullptr ;
    size = 0 ;
    countFgOnDesk = 0 ;
}

field::~field ()
{
    free_cells () ;
}

bool field::generate_field ()
{
    if ( size && countFgOnDesk )
    {
        cls = new cell*[size] ;
        for ( int i = 0 ; i < size ; i++ )
        {
            cls[i] = new cell[size] ;
            for ( int j = 0 ; j < size ; j++ )
            {
                cls[i][j].set_crd ( j , i ) ;
                cls[i][j].set_color ( ( i + j + 1 ) % 2 ) ;
            }
        }
        return true ;
    }
    return false ;
}


int field::get_size ()
{
    return size ;
}

bool field::set_size ( int sizeIn )
{
    if ( sizeIn >= minFieldSize )
    {
        size = sizeIn ;
        return true ;
    }
    return false ;
}


int field::get_count_fg_on_desk ()
{
    return countFgOnDesk ;
}

bool field::set_count_fg_on_desk ( int countIn )
{
    if ( countIn >= minCountFgOnDesk )
    {
        countFgOnDesk = countIn ;
        return true ;
    }
    return false ;
}


cell* field::get_all_white_cell ()
{
    if ( cls == nullptr )
    {
        return nullptr ;
    }
    int count = calc_count_w_cells () ;
    int indx = 0 ;
    cell* result = new cell[count] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( cls[i][j].get_color () && indx < count )
            {
                result[indx] = cls[i][j] ;
                indx++ ;
            }
        }
    }
    return result ;
}

cell* field::get_all_black_cell ()
{
    if ( cls == nullptr )
    {
        return nullptr ;
    }
    int count = calc_count_w_cells () ;
    int indx = 0 ;
    cell* result = new cell[count] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( !( cls[i][j].get_color () ) && indx < count )
            {
                result[indx] = cls[i][j] ;
                indx++ ;
            }
        }
    }
    return result ;
}

cell* field::get_cell_with_all_fg ( int &count )
{
    if ( cls == nullptr )
    {
        return nullptr ;
    }
    count = calc_count_w_cells () ;
    int indx = 0 ;
    cell* result = new cell[count] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( !( cls[i][j].empty_cell () ) && indx < count )
            {
                result[indx] = cls[i][j] ;
                indx++ ;
            }
        }
    }
    return result ;
}

cell* field::get_cell_with_black_fg ( int &count )
{
    if ( cls == nullptr )
    {
        return nullptr ;
    }
    count = calc_count_w_cells () ;
    int indx = 0 ;
    bool colorFg = false ;
    cell* result = new cell[count] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            colorFg = cls[i][j].get_point_figure ()->get_color () ;
            if ( !( colorFg ) && indx < count )
            {
                result[indx] = cls[i][j] ;
                indx++ ;
            }
        }
    }
    return result ;
}

cell* field::get_cell_with_white_fg ( int &count )
{
    if ( cls == nullptr )
    {
        return nullptr ;
    }
    count = calc_count_w_cells () ;
    int indx = 0 ;
    bool colorFg = false ;
    cell* result = new cell[count] ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            colorFg = cls[i][j].get_point_figure ()->get_color () ;
            if ( ( colorFg ) && indx < count )
            {
                result[indx] = cls[i][j] ;
                indx++ ;
            }
        }
    }
    return result ;
}

cell* field::get_cell ( int iIn , int jIn )
{
    return &cls[iIn][jIn] ;
}

cell* field::get_cell ( int* &crd )
{
    return &cls[crd[1]][crd[0]] ;
}

bool field::move_fg ( int* &srcCrd , int* &resCrd , bool colorIn )
{
    figure* pFg = get_cell ( srcCrd )->get_point_figure () ;
    if ( pFg->get_color () == colorIn )
    {
        get_cell ( srcCrd )->cell_to_free () ;
        get_cell ( resCrd )->set_point_figure ( *pFg ) ;
        return 0 ;
    }
    return 1 ;
}


void field::print_field ()
{
    if ( size && countFgOnDesk )
    {
        print_numberline () ;
        print_underline () ;
        for ( int i = 0 ; i < size ; i++ )
        {
            std::cout << "   " << i << "   " ;
            for ( int j = 0 ; j < size ; j++ )
            {
                cls[i][j].print() ;
            }
            std::cout << "   " << i << "   " << std::endl ;
            print_underline () ;
        }
        print_numberline () ;
    }
}

