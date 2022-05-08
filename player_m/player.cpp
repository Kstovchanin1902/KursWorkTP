#include "player.h"

//Private section





//Protect section

void player::decr_count_fg ()
{
    if ( countFgs > 0 )
    {
        countFgs-- ;
    }
}

void player::free_fgs ()
{
    if ( fgs != nullptr )
    {
        delete[] fgs ;
        fgs = nullptr ;
    }
}


//Public section

player::player ()
{
    fgs = nullptr ;
    number = countPlayers ;
    aiChecker = false ;
    countPlayers++ ;
    countFgs = 0 ;
    countFgsOnD = 0 ;
    color = false ;
}

player::~player ()
{
    free_fgs () ;
}

int player::get_count_lives_fgs ()
{
    int result = 0 ;
    if ( fgs == nullptr )
    {
        return -1 ;
    }
    for ( int i = 0 ; i < countFgsOnD ; i++ )
    {
        if ( fgs[i].get_life () )
        {
            result++ ;
        }
    }
    return result ;
}


int player::get_count_fgs_on_d ()
{
    return countFgsOnD ;
}

void player::set_count_fgs_on_d ( int countIn )
{
    if ( countIn >= minCountFgOnDesk )
    {
        countFgsOnD = countIn ;
    }
}


int player::get_count_fgs ()
{
    return countFgs ;
}

void player::set_count_fgs ( int countIn )
{
    if ( countIn > minCountFgOnDesk )
    {
        countFgs = countIn ;
    }
}


bool player::get_color ()
{
    return color ;
}

void player::set_color ( bool colorIn )
{
    color = colorIn ;
}


figure* player::get_point_fg ( int indxIn )
{
    return &fgs[indxIn] ;
}

figure** player::get_point_fgs ()
{
    return &fgs ;
}

bool player::kill_fg ( int indxIn )
{
    if ( fgs == nullptr )
    {
        return false ;
    }
    fgs[indxIn].kill () ;
    return true ;
}

std::vector<step> player::get_vect_steps ()
{
    std::vector<step> res ;
    return res ;
}

int player::get_indx_dead_fg ()
{
    if ( fgs != nullptr )
    {
        for ( int i = 0 ; i < countFgsOnD ; i++ )
        {
            if ( !fgs[i].get_life () )
            {
                return i ;
            }
        }
    }
    return -1 ;
}

bool player::set_fg ( int indxIn , int* &crd )
{
    if ( !fgs[indxIn].get_life () )
    {
        figure* fgN = new figure ;
        fgN->set_color ( color ) ;
        fgN->set_sprite ( spriteFabric::product_sprite ( number ) ) ;
        fgN->set_crd ( crd ) ;
        fgN->set_num ( indxIn ) ;
        fgs[indxIn] = *fgN ;
        countFgs-- ;
    }
    return true ;
}

bool player::get_check_ai ()
{
    return aiChecker ;
}

bool player::generate_fgs ()
{
    if ( countFgs < countFgsOnD )
    {
        return false ;
    }
    fgs = new figure[countFgsOnD] ;
    std::string sprite = spriteFabric::product_sprite ( number ) ;
    for ( int i = 0 ; i < countFgsOnD ; i++ )
    {
        fgs[i].set_color ( color ) ;
        fgs[i].set_sprite ( sprite ) ;
        fgs[i].set_num ( i ) ;
        countFgs-- ;
    }
    return true ;
}

int player::get_num ()
{
    return number ;
}


void player::print_info ()
{
    std::cout << "number = " << number << std::endl ;
    std::cout << "countFgsOnD = " << countFgsOnD << std::endl ;
    std::cout << "countFgs = " << countFgs << std::endl ;
    std::cout << "color = " << color << std::endl ;


    bool colorF = false ;
    bool lifeF = false ;
    std::string sprite = "" ;
    int* crd = nullptr ;
    int num = 0 ;

    for ( int i = 0 ; i < countFgsOnD ; i++ )
    {
        colorF = fgs[i].get_color () ;
        lifeF = fgs[i].get_life () ;
        sprite = fgs[i].get_sprite () ;
        crd = fgs[i].get_crd () ;
        num = fgs[i].get_num () ;

        std::cout << " fgs[" << i << "] : " << std::endl ;
        std::cout << "{" << std::endl ;
        std::cout << "color = " << colorF << std::endl ;
        std::cout << "life = " << lifeF << std::endl ;
        std::cout << "sprite = " << sprite << std::endl ;
        std::cout << "crd : {" ;
        if ( crd != nullptr )
        {
            std::cout << " x = " << crd[1] << " ; " ;
            std::cout << "y = " << crd[0] ; 
        }
        std::cout << "}" << std::endl ;
        std::cout << "number = " << num << std::endl ;
        std::cout << "}" << std::endl ;
    }
}

