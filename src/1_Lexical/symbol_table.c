#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sym sym_table[20];

void generate_symbol_table() {
    char token[20], temp_attr[20], c;
    int i = 0, j, attrno = 0, memory = 1000, line;

    FILE *fp = fopen("tokens.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening input file.\n");
        return;
    }

    FILE *csvFile = fopen("symbol_table.csv", "w");
    if (csvFile == NULL)
    {
        printf("Error opening CSV file.\n");
        fclose(fp);
        return;
    }
    fprintf(csvFile, "SNo,Token,Attribute,AttributeNumber,MemoryLocation\n");

    FILE *jsonFile = fopen("symbol_table.json", "w");
    if (jsonFile == NULL)
    {
        printf("Error opening JSON file.\n");
        fclose(fp);
        fclose(csvFile);
        return;
    }
    fprintf(jsonFile, "[\n");

    while (fscanf(fp, "%19[^\t]\t%19[^\t]\t%d\n", token, temp_attr, &line) == 3) {
        // Process token only if it's an identifier/main function
        if (strcmp(temp_attr, "Identifier") == 0 || strcmp(temp_attr, "Main Function") == 0) {
            int flag = 0;
            for (j = 0; j < i; j++) {
                if (strcmp(sym_table[j].token, token) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                // Add to symbol table
                strcpy(sym_table[i].token, token);
                 strcpy(sym_table[i].attr, temp_attr);
                sym_table[i].sno = i + 1;
                sym_table[i].attrno = ++attrno;
                sym_table[i].addr = memory;
                memory += 4;
                i++;
            }
        }
    }

    fclose(fp);

    printf("\n------------Symbol Table---------------------\n\n");
    printf("SNo\tToken\t\tAttribute\t\tMemory Location\n\n");

    for (j = 0; j < i; j++)
    {
        printf("%d\t%s\t\t< %s , %d >\t\t%d\n", sym_table[j].sno, sym_table[j].token, sym_table[j].attr, sym_table[j].attrno, sym_table[j].addr);
        fprintf(csvFile, "%d,%s,%s,%d,%d\n", sym_table[j].sno, sym_table[j].token, sym_table[j].attr, sym_table[j].attrno, sym_table[j].addr);

        fprintf(jsonFile, "  {\n");
        fprintf(jsonFile, "    \"SNo\": %d,\n", sym_table[j].sno);
        fprintf(jsonFile, "    \"Token\": \"%s\",\n", sym_table[j].token);
        fprintf(jsonFile, "    \"Attribute\": \"%s\",\n", sym_table[j].attr);
        fprintf(jsonFile, "    \"AttributeNumber\": %d,\n", sym_table[j].attrno);
        fprintf(jsonFile, "    \"MemoryLocation\": %d\n", sym_table[j].addr);
        if (j == i - 1)
            fprintf(jsonFile, "  }\n");
        else
            fprintf(jsonFile, "  },\n");
    }

    fprintf(jsonFile, "]\n");

    // After writing to CSV/JSON
    if (ferror(csvFile)) {
        printf("Error writing to CSV file!\n");
    }
    if (ferror(jsonFile)) {
        printf("Error writing to JSON file!\n");
    }

    fflush(csvFile);
    fflush(jsonFile);
    fclose(csvFile);
    fclose(jsonFile);

    printf("\n✅ Symbol Table successfully saved to 'symbol_table.csv' and 'symbol_table.json'\n");
}



// int main() {
//     generate_symbol_table();
//     return 0;
// }   