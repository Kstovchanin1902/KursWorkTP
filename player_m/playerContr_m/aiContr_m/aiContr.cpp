#include "aiContr.h"
//Private section

int* aiContr::find_n_zero_crd ( int** &srcMask , int size )
{
    int* result = new int[crdDimns] ;
    for ( int j = 0 ; j < size ; j++ )
    {
        for ( int i = 0 ; i < size ; i++ )
        {
            if ( srcMask[i][j] )
            {
                result[0] = j ;
                result[1] = i ;
                srcMask[i][j] = 0 ;
                return result ;
            }
        }
    }
    std::cout << "error: count figures on the desk in obj " ;
    std::cout << " (field) not equal count figures on the " ;
    std::cout << "desk in obj (player)" ;
    return nullptr ;
}





//Protected section

int* aiContr::moving ( player &aiIn , field &fldIn )
{
    std::vector<step> stepVec = aiIn.get_vect_steps () ;
    int sizeVec = stepVec.size () ;
    std::cout << "sizeVec = " << sizeVec << std::endl ;
    if ( sizeVec > 0 )
    {
        std::cout << "sizeVec > 0  - " << ( sizeVec > 0 ) << std::endl ;
        int randNum = rand() % sizeVec ;
        step needStep = stepVec[randNum] ;
        int* srcCrd = nullptr ;
        srcCrd = needStep.get_source_crd () ;
        std::cout << "srcCrd x,y = " << srcCrd[0] << "," << srcCrd[1] ;
        std::cout << std::endl ;
        int* resCrd = nullptr ;
        resCrd = needStep.get_result_crd () ;
        std::cout << "resCrd x,y = " << resCrd[0] << "," << resCrd[1] ;
        std::cout << std::endl ;
        fldIn.move_fg ( srcCrd , resCrd , aiIn.get_color () ) ;
        return resCrd ;
    }
    return nullptr ;
}








//Public section

int aiContr::set_start_figure ( player &aiIn , field &fldIn )
{
    int sizeFld = fldIn.get_size () ;
    int countFOD = aiIn.get_count_fgs_on_d () ;
    int countFgs = 0 ;
    bool aiColor = aiIn.get_color () ;
    fldMask fMask ( fldIn ) ;
    int** maskS = fMask.get_mask_for_start ( aiColor ) ;
    int* crd = nullptr ;
    for ( int i = 0 ; i < countFOD ; i++ )
    {
        crd = find_n_zero_crd ( maskS , sizeFld ) ;
        if ( crd != nullptr )
        {
            fldIn.get_cell ( crd )->
                set_point_figure ( *aiIn.get_point_fg ( i ) ) ;
        }
    }
    return 0 ;
}

int aiContr::move ( player &aiIn , field &fldIn , int* &setCrd )
{
    int* resCrd = moving ( aiIn , fldIn ) ;
    if ( resCrd != nullptr )
    {
        kill_enemy_fgs ( resCrd , fldIn ) ;
        if ( check_to_die ( resCrd , fldIn ) &&
                !plLg.check_of_needed_in_fg ( aiIn ) ) {
            return check_to_set ( resCrd , setCrd , fldIn ) ;
        }
    }
    return 0 ;
}








