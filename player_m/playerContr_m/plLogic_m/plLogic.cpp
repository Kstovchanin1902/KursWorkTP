#include "plLogic.h"
//Private section

int plLogic::dec_vect ( int sub , int res )
{
    if ( sub > 0 )
    {
        return res - 1 ;
    }
    return res + 1 ;
}





//Public section


bool plLogic::check_step ( int* &srcCrd , int* &resCrd ,
                            field &fldIn )
{
    int size = 0 ;
    fldMask fM ( fldIn ) ;
    int** mask = fM.get_mask ( size ) ; 
    int subI = resCrd[1] - srcCrd[1] ;
    int subJ = resCrd[0] - srcCrd[0] ;
    int mdlI = abs ( subI ) ;
    int mdlJ = abs ( subJ ) ;
    if ( mdlI == 1 && mdlJ == 1 )
    {
        return false ;
    }
    if ( mdlI == 2 && mdlJ == 2 )
    {
        int rI = dec_vect ( subI , resCrd[1] ) ;
        int rJ = dec_vect ( subJ , resCrd[0] ) ;
        if ( mask[rI][rJ] >= 0 )
        {
            return false ;
        }
    }
    return true ; ;
}


int plLogic::check_out_of_range ( int num , int size , 
                                    std::string &eMsg )
{
    if ( num < 0 )
    {
        eMsg = "out of range (num is lower of zero (0))" ;
        return -1 ;
    }
    if ( num >= size )
    {
        eMsg = "out of range (num is more of max size)" ;
        return 1 ;
    }
    return 0 ;
}

int plLogic::check_opt_out_of_range ( int num , int min ,
                                int max , std::string &eMsg )
{
    if ( num < min )
    {
        eMsg = "out of range (num is lower of" ;
        eMsg += std::to_string ( min ) + ")" ;
        return -1 ;
    }
    if ( num >= max )
    {
        eMsg = "out of range (num is more of" ;
        eMsg += std::to_string ( max ) + ")" ;

        return 1 ;
    }
    return 0 ;
}

//if out num = : 1 - one of x or y out of range
//               2 - x and y out of range
int plLogic::check_crd_out_of_range ( int* &crd , int size )
{
    std::string eMsgX = "" ; 
    std::string eMsgY = "" ;
    int resX = check_out_of_range ( crd[0] , size , eMsgX ) ;
    int resY = check_out_of_range ( crd[1] , size , eMsgY ) ;
    int res = 0 ;
    if ( resX )
    {
        res += abs ( resX ) ;
        std::cout << "error: x : " << eMsgX << std::endl ;
    }
    if ( resY )
    {
        res += abs ( resY ) ;
        std::cout << "error: y : " << eMsgY << std::endl ;
    }
    return res ;
}

int plLogic::check_crd_opt_out_of_range ( int* &crd , int min ,
                                        int max )
{
    std::string eMsgX = "" ; 
    std::string eMsgY = "" ;
    int resY = check_opt_out_of_range ( crd[1] , min , max ,
                                        eMsgY ) ;
    int res = 0 ;
    if ( resY )
    {
        res += abs ( resY ) ;
        std::cout << "error: y : " << eMsgY << std::endl ;
    }
    return res ;
}

int plLogic::check_s_out_of_range ( int* &crd , int size ,
                                        bool color )
{
    int max = 0 ;
    int min = 0 ;
    if ( color )
    {
        min = size - ( size / 2 - 1 ) ;
        max = size ; 
    }
    else
    {
        min = 0 ;
        max = size / 2 - 1 ;
    }
    return check_crd_opt_out_of_range ( crd , min , max ) ;
}

int plLogic::check_crd_color ( int* &crd , std::string &eMsg )
{
    int sum = 0 ;
    if ( crd == nullptr )
    {
        eMsg = "error: crd array is not exist" ;
        return -1 ;
    }
    sum = crd[0] + crd[1] ;
    if ( ! ( sum % 2 ) )
    {
        eMsg = "error: color of cell = white" ;
        return 1 ;
    }
    return 0 ;
}

    //Checked the conditions to equals of
    //count lives figures and count figures on the desk
    //return false if needed in figures
    //else return true
bool plLogic::check_of_needed_in_fg ( player &plIn )
{
    int livesFgs = plIn.get_count_lives_fgs () ;
    int fgsOTD = plIn.get_count_fgs_on_d () ;
    if ( livesFgs == fgsOTD )
    {
        return true ;
    }
    return false ;
}


bool plLogic::check_color_fg ( int* &crd , bool color ,
                                field &fldIn )
{
    figure* pFg = fldIn.get_cell ( crd )->get_point_figure () ;
    if ( pFg != nullptr )
    {
        return ( color == pFg->get_color () ) ;
    }
    return 1 ;
}

bool plLogic::check_condit_st_mv ( int* &crd , bool color ,
                                        field &fldIn )
{
    if ( !fldIn.get_cell ( crd )->empty_cell () )
    {
        bool colorFg = fldIn.get_cell ( crd )->
                get_point_figure ()->get_color () ;
        return ! ( colorFg == color ) ;
    }
    return true ;
}

bool plLogic::check_condit_end_mv ( int* &srcCrd , int* &resCrd ,
                                     bool colorIn , field &fldIn )
{
    if  ( fldIn.get_cell ( resCrd )->empty_cell () )
    {
        if ( !check_step ( srcCrd , resCrd , fldIn ) )
        {
            return false ;
        }
        else
        {
            std::cout << "step is wrong!" << std::endl ;
        }
    }
    return true ;
}

std::string plLogic::choise_str_color ( bool color )
{
    if ( color )
    {
        return "white" ;
    }
    return "black" ;
}

