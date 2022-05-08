#include "plContr.h"

//Private section

int* plContr::input_crd ( int size , std::string msg )
{
    int* resCrd = new int[crdDimns] ;
    int resOOR = 0 ;
    int resCol = 0 ;
    std::string eMsg = "" ;
    std::cout << msg << std::endl ;
    std::string internalMsg = "" ;
    do
    {
        internalMsg = "x = " ;
        resCrd[0] = inputContr::p_num ( internalMsg ) ;
        internalMsg = "y = " ;
        resCrd[1] = inputContr::p_num ( internalMsg ) ;
        resOOR = plLg.check_crd_out_of_range ( resCrd , size ) ;
        if ( resOOR )
        {
            std::cout << eMsg << std::endl ;
        }
        resCol = plLg.check_crd_color ( resCrd , eMsg ) ;
        if ( resCol )
        {
            std::cout << eMsg << std::endl ;
        }
    } while ( resOOR || resCol ) ;
    return resCrd ;
}

int* plContr::input_start_mv_crd ( bool color , field &fldIn )
{
    int size = fldIn.get_size () ;
    int* result = nullptr ;
    std::string msg = "Enter source coordinates: " ;
    do
    {
        result = input_crd ( size , msg ) ;
    } while ( plLg.check_condit_st_mv ( result , color , fldIn ) ) ;
    return result ;
}

int* plContr::input_end_mv_crd ( int* &srcCrd , bool color ,
                                    field &fldIn )
{
    int size = fldIn.get_size () ;
    int* result = nullptr ;
    std::string msg = "Enter result coordinates: " ;
    do
    {
        result = input_crd ( size ,  msg ) ;
    } while ( plLg.check_condit_end_mv ( srcCrd , result , color ,
                                            fldIn ) ) ;
    return result ;
}

int* plContr::input_start_crd ( int size , bool color ,
                                std::string msg )
{
    int* crd = nullptr ;
    do
    {
        crd = input_crd ( size , msg ) ;
    } while ( plLg.check_s_out_of_range ( crd , size , color ) ) ;
    return crd ;
}


//Protect section

int* plContr::moving ( player &plIn , field &fldIn )
{
    int size = fldIn.get_size () ;
    bool color = plIn.get_color () ;
    std::string msg = "Enter result coordinates: " ;
    int* srcCrd = input_start_mv_crd ( color , fldIn ) ;
    fldMask fM ( fldIn ) ;
    fM.print_mask_of_steps ( srcCrd ) ;
    int* resCrd = input_end_mv_crd ( srcCrd , color , fldIn ) ;
    fldIn.move_fg ( srcCrd , resCrd , plIn.get_color () ) ;
    delete[] srcCrd ;
    return resCrd ;
}

int plContr::kill_enemy_fgs ( int* &srcCrd , field &fldIn )
{
    fldMask fM ( fldIn ) ;
    int size = fldIn.get_size () ;
    fldIn.print_field () ;
    bool color = fldIn.get_cell ( srcCrd )->
                    get_point_figure ()->get_color () ;
    int** smartM = fM.get_smart_mask ( !color ) ; 
    for ( int i = 0 ; i < size ; i ++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( smartM[i][j] >= 3 )
            {
                fldIn.get_cell ( i , j )->kill_figure () ;
            }
        }
    }
    return 0 ;
}

int plContr::check_to_die ( int* &srcCrd , field &fldIn )
{
    fldMask fM ( fldIn ) ;
    bool color = fldIn.get_cell ( srcCrd )->
                    get_point_figure()->get_color() ;
    int** smartM = fM.get_smart_mask ( color ) ;
    fM.print_smart_mask ( color ) ;
    if ( smartM[srcCrd[1]][srcCrd[0]] == 3 )
    {
        fldIn.get_cell ( srcCrd )->kill_figure () ;
        return 0 ;
    }
    return 1 ;
}

int plContr::check_to_set ( int* &srcCrd , int* &resCrd ,
                            field &fldIn )
{
    fldMask fM ( fldIn ) ;
    if ( resCrd != nullptr )
    {
        delete[] resCrd ;
        resCrd = nullptr ;
    }
    int size = fldIn.get_size () ;
    bool color = fldIn.get_cell ( srcCrd )->
                    get_point_figure()->get_color() ;
    int** smartM = fM.get_smart_empt_mask ( color ) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( smartM[i][j] >= 3 )
            {
                resCrd = new int[crdDimns] ;
                resCrd[0] = j ;
                resCrd[1] = i ;
                return 1 ;
            }
        }
    }
    return 0 ;
}





//Public section

//for apply this method player must be initialize
int plContr::set_start_figure ( player &plIn , field &fldIn )
{
    int* crd = nullptr ;
    int size = fldIn.get_size () ;
    int countFgs = plIn.get_count_fgs_on_d () ;
    bool color = plIn.get_color () ;
    std::string msg = "Enter coordinates: " ;
    std::string colorStr = plLg.choise_str_color ( color ) ;
    std::cout << "color: " << colorStr << std::endl ;
    for ( int i = 0 ; i < countFgs ; i++ )
    {
        fldIn.print_field () ;
        std::cout << "figure[" << i << "]: " << std::endl ;
        std::cout << "{" << std::endl ;
        crd = input_start_crd ( size , color , msg ) ;
        fldIn.get_cell ( crd )->
            set_point_figure ( *plIn.get_point_fg ( i ) ) ;
        std::cout << "}" << std::endl ;
        delete[] crd ;
        crd = nullptr ;
    }
    std::cout << std::endl ;
    return 0 ;
}

int plContr::set_figure ( int* &setCrd , player &plIn ,
                            field &fldIn )
{
    int countLives = plIn.get_count_lives_fgs () ;
    int countFOD = plIn.get_count_fgs_on_d () ;
    if ( countLives == countFOD )
    {
        return 1 ;
    }
    int indx = plIn.get_indx_dead_fg () ;
    if ( indx >= 0 )
    {
        plIn.set_fg ( indx , setCrd ) ;
        fldIn.get_cell ( setCrd )->
            set_point_figure ( *plIn.get_point_fg ( indx ) ) ;
        return 0 ;
    }
    return 1 ;
}

//setCrd this is coordinates for set new figur on the desk
//this coordinates retrun from function to address
//Function return 1 if has find a cell for set new figur
//else return 0
int plContr::move ( player &plIn , field &fldIn , int* &setCrd )
{
    int* resCrd = moving ( plIn , fldIn ) ;
    kill_enemy_fgs ( resCrd , fldIn ) ;
    if ( check_to_die ( resCrd , fldIn ) &&
            !plLg.check_of_needed_in_fg ( plIn ) )
    {
        return check_to_set ( resCrd , setCrd , fldIn ) ;
    }
    return 0 ;
}






