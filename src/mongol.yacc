%{
    #include "mongol.hpp"
%}

%defines %union { char c; std::string *s; int n; float f; Op op; }

%token     COLON
%token<s>  ID
%token<op> CMD0
%%
syntax : | syntax ex

ex: COLON ID        { fprintf(stderr,":%s\n",$2->c_str());
                        label[*$2]=Cp; Ip=Cp; }
  | CMD0            { fprintf(stderr,"%.2X",$1); compile($1); }
