%{
    #include "mongol.hpp"
%}

%defines %union { char c; std::string *s; int n; float f; }

%token    COLON
%token<s> ID
%%
syntax : | syntax ex

ex: COLON ID        { fprintf(stderr,":%s\n",$2->c_str()); label[*$2]=Cp; }
