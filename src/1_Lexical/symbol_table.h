// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

struct sym {
    int sno;
    char token[20];
    char attr[20];
    int attrno;
    int addr;
};

void generate_symbol_table();

#endif