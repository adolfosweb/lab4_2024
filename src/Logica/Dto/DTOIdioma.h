#ifndef LOGICA_DTO_DTOIDIOMA_H_
#define LOGICA_DTO_DTOIDIOMA_H_

#include <iostream>
using namespace std;

class DTOIdioma{
private:
    string idioma;
public:
    DTOIdioma();
    DTOIdioma(string Idioma);
    ~DTOIdioma();
    string getIdioma();

    // friend  bool operator==(const DTOIdioma& lhs, const DTOIdioma& rhs) const;
   
};



#endif /* LOGICA_DTO_DTOIDIOMA_H_*/