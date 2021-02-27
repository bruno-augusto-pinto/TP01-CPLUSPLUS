//https://www.cplusplus.com/reference/fstream/fstream/
//https://docs.microsoft.com/pt-br/cpp/standard-library/filesystem?view=msvc-160

#ifndef arquivos_hpp
#define arquivos_hpp

#include <fstream>
#include <vector>
#include <experimental/filesystem> 

#include "usuarios.hpp"

using namespace std;

using namespace std::experimental::filesystem::v1;

void setAdmin();

char verificaLogin(const string&, const string&);

int cadastraUsuario(const string&, const string&, const char&);

#endif
