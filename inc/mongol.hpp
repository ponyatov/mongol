#pragma once

/// @defgroup config config
/// @{
#define Msz 0x10000
#define Rsz 0x100
#define Dsz 0x10
/// @}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <string>

/// @defgroup main main
/// @{
extern int main(int argc, char *argv[]);
extern void arg(int argc, char *argv);
/// @}

/// @defgroup parser parser
/// @{
extern int yylex();
extern FILE *yyin;
extern char *yyfile;
extern char *yytext;
extern int yylineno;
extern int yyparse();
extern void yyerror(const char *msg);
#include "mongol.yacc.hpp"
/// @}

/// @defgroup types types
/// @{
typedef uint8_t byte;
typedef uint16_t addr;
typedef int32_t cell;
/// @}

/// @defgroup memory memory
/// @{

/// @name main memory
/// @{
extern byte M[Msz];
extern addr Cp;
extern addr Ip;
/// @}

/// @name return stack
/// @{
extern addr R[Rsz];
extern byte Rp;
/// @}

/// @name data stack
/// @{
extern cell D[Dsz];
extern byte Dp;
/// @}

/// @}

/// @defgroup compiler compiler
/// @{

extern std::map<std::string, addr> label;
/// @}
