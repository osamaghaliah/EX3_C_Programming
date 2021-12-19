#ifndef WORD
#define WORD 30
#endif
#ifndef TXT
#define TXT 1024
#endif

int count(char wrd[WORD]);
void gematria(char wrd[WORD], char txt[TXT]);
void atbash(char wrd[WORD], char txt[TXT], char *result);
int inWord(char wrd[WORD], char ch);
int allStars(char tst[WORD]);
void anagram(char (*ang)[WORD], char (*txt)[TXT]);
