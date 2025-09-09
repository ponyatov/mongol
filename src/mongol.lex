%{
    #include "mongol.hpp"
    char *yyfile = nullptr;
%}

%option noyywrap yylineno

%x comment

sign  [+\-]
dec   [0-9]
alpha [a-zA-Z_]
alnum [a-zA-Z_0-9]

%%
"#!".*          {}                  // shebang
"//".*          {}                  // line comment
"/*"            {BEGIN(comment);}   // block comment
<comment>"*/"   {BEGIN(INITIAL);}
<comment>.      {}

":"             {return COLON;}

{alpha}{alnum}* {yylval.s = new std::string(yytext); return ID;}

[ \t\r\n]+      {}                  // drop spaces
.               {yyerror("");}      // any undetected char
