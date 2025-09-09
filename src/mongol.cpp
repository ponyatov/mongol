#include "mongol.hpp"

int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
        yyfile = argv[i];
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
        yyfile = nullptr;
    }
    vm();
}

void arg(int argc, char *argv) {  //
    fprintf(stderr, "arg[%i] = <%s>\n", argc, argv);
}

void yyerror(const char *msg) {
    fprintf(stderr, "\n\n %s:%i %s [%s]\n\n", yyfile, yylineno, msg, yytext);
    exit(-1);
}

byte M[Msz];
addr Cp = 0;
addr Ip = -1;

std::map<std::string, addr> label;

addr compile(Op op) { return compile((byte)op); }

addr compile(byte b) {
    assert(Cp + sizeof(byte) < Msz);
    M[Cp] = b;
    Cp += sizeof(byte);
    return Cp;
}

addr compile(addr a) {
    assert(Cp + sizeof(addr) < Msz);
    *(addr *)&M[Cp] = a;
    Cp += sizeof(addr);
    return Cp;
}

addr compile(cell c) {
    assert(Cp + sizeof(cell) < Msz);
    *(cell *)&M[Cp] = c;
    Cp += sizeof(cell);
    return Cp;
}

void vm() {
    assert(Ip < Cp);
    Op op = (Op)M[Ip++];
    fprintf(stderr, "\n%.4X: %.2X ", Ip - 1, op);
    switch (op) {
        case Op::nop:
            nop();
            break;
        case Op::halt:
            halt();
            break;
        default:
            fprintf(stderr, " unknown command\n\n");
            exit(-1);
    }
}

bool trace = true;

void nop() {
    if (trace) fprintf(stderr, "nop");
}

void halt() {
    if (trace) fprintf(stderr, "halt\n");
    exit(0);
}
