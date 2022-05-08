#ifndef STEPH
#define STEPH



class step
{
private:
    int* srcCrd ; //source coordinates
    int* resCrd ; //result coordinates
    int numFg ; //figure number
    bool colorFg ; //figure color

    void free_src () ;
    void free_res () ;
public:
    step () ;
    ~step () ;

    int* get_source_crd () ;
    void set_source_crd ( int iIn , int jIn ) ;
    void set_source_crd ( int* &srcCrdIn ) ;

    int* get_result_crd () ;
    void set_result_crd ( int iIn , int jIn ) ;
    void set_result_crd ( int* &resCrdIn ) ;

    int get_num_fg () ;
    void set_num_fg ( int numFgIn ) ;

    bool get_color_fg () ;
    void set_color_fg ( bool colorFgIn ) ;

} ;
#endif
