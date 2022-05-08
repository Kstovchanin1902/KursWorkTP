#ifndef FIGUREH
#define FIGUREH

#include <string>

const int crdDimns = 2 ; // dimension of coordinates

class figure
{
private:
    int* crd ; //coordinates crd[0] - x , crd[1] - y
    int num ; //number = index in the player figures array
    bool color ; //white - 1 , black - 0 
    bool life ; //life - 1 , dead - 0 
    std::string sprite ;

    void free_crd () ;
public:
    figure () ;
    ~figure () ;

    int* get_crd () ;
    int get_crd_x () ;
    int get_crd_y () ;
    void set_crd ( int xIn , int yIn ) ;
    void set_crd ( int* crdIn ) ;

    int get_num () ;
    void set_num ( int numIn ) ;

    bool get_color () ;
    void set_color ( bool colorIn ) ;

    bool get_life () ;
    void kill () ;
    void resurrect () ;

    std::string get_sprite () ;
    void set_sprite ( std::string spriteIn ) ;

    void operator= ( figure &right ) ;
} ;
#endif
