#include "ai.h"
//Private section







//Protected section

void ai::prcssng_steps_fg ( figure &fgIn , fldMask &fMaskIn ,
                            int &size )
{ 
    bool fgColor = fgIn.get_color () ;
    int fgNum = fgIn.get_num () ;
    int* fgCrd = fgIn.get_crd () ;
    int** stepMask = fMaskIn.get_mask_of_steps ( fgCrd ) ;
    step* stepAdd = nullptr ;
    fMaskIn.print_mask_of_steps ( fgCrd ) ;
    std::cout << std::endl ;
    std::cout << "prcssng" << std::endl ;
    for ( int i = 0 ; i < size ; i++ )
    {
        for ( int j = 0 ; j < size ; j++ )
        {
            if ( stepMask[i][j] )
            {
                stepAdd = new step ;
                std::cout << "fgCrd x,y = " << fgCrd[0] << "," ;
                std::cout << fgCrd[1] << std::endl ;
                std::cout << "resCrd x,y = " << j << "," << i << std::endl ;
                stepAdd->set_source_crd ( fgCrd ) ;
                stepAdd->set_color_fg ( fgColor ) ;
                stepAdd->set_num_fg ( fgNum ) ;
                stepAdd->set_result_crd ( i , j ) ;
                stepVec.push_back ( *stepAdd ) ;
                step crd = stepVec[stepVec.size () - 1] ;
                int* src = crd.get_source_crd () ;
            }
        }
    }
    std::cout << "prcssng'" << std::endl ;
}

void ai::refresh_steps ( field &fldIn )
{
    stepVec.clear () ;
    std::cout << "Refresh AI steps " << std::endl ;
    fldMask fMask ( fldIn ) ;
    int sizeFld = fldIn.get_size () ;
    for ( int i = 0 ; i < countFgsOnD ; i++ )
    {
        if ( fgs[i].get_life () )
        {
            prcssng_steps_fg ( fgs[i] , fMask , sizeFld ) ;
        }
    }
}







//Public section

ai::ai ()
{
    aiChecker = true ;
}

ai::~ai ()
{
    stepVec.clear () ;
}

int ai::get_size_vect ()
{
    return stepVec.size () ;
}

std::vector<step> ai::get_vect_steps ()
{
    return stepVec ;
}







