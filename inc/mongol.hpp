#pragma once

/// @defgroup config config
/// @ingroup vm
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

/// @defgroup types types
/// @ingroup vm
/// @{
typedef uint8_t byte;
typedef uint16_t addr;
typedef int32_t cell;
/// @}

/// @defgroup memory memory
/// @ingroup vm
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

/// @defgroup vm vm
/// @{

extern void vm();

extern bool trace;

enum class Op {
    nop = 0x00,   ///<
    halt = 0xFF,  ///<
};

extern void nop();
extern void halt();

/// @}

/// @defgroup compiler compiler
/// @{

extern std::map<std::string, addr> label;

extern addr compile(Op op);
extern addr compile(byte b);
extern addr compile(addr a);
extern addr compile(cell c);

/// @}

/// @defgroup parser parser
/// @ingroup compiler
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
