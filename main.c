#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024
#define WORD 30 

int count(char wrd[WORD]) {
    int cnt=0;
    
    for(int i=0; i<WORD; i++) {
        if (wrd[i] == '\t' || wrd[i] == '\n' || wrd[i] == ' ')
            break;
        if (wrd[i] > 96 && wrd[i] < 123)
            cnt += wrd[i] - 96;
    }

    return cnt;
}

void gematria(char wrd[WORD], char txt[TXT]) {
    printf("Gematria Sequences: ");

    int cnt = count(wrd);
    char word[WORD];
    int sum = 0, r = 0, flag = 0, first = 0;
    
    for (int i = 0; i < TXT; i++) {
        if (txt[i] == '~')
            break;
        
        for (int k = i; k < TXT; k++) {
            if (txt[k] == '~') {
                r = 0;
                sum = 0;
                word[0] = ' ';
                break;
            }       
    
            if (flag == 0 && (txt[k] <= 96 || txt[k] >= 123)) {
                r = 0;
                sum = 0;
                break;
            }

            if (txt[k] > 96 && txt[k] < 123) {
                sum += txt[k]-96;
                flag = 1;
            }

            if (txt[k] > 64 && txt[k] < 91) {
                sum += txt[k] - 64;
                flag = 1;
            }

            if (flag == 1) {
                word[r] = txt[k];
                r++;
            }

            if (sum > cnt) {
                sum = 0;
                r = 0;
                word[0] = ' ';
                flag = 0;
                break;
            }

            if (sum == cnt) {
                word[r] = ' ';
                if (first == 0) {
                    printf("%s", word);
                    first = 1;    
                }

                else printf("~%s", word);    
            
                r = 0;
                sum = 0;
                flag = 0;
                break;
            }
        }
    }
    printf("\n");
}


void atbash(char wrd[WORD], char txt[TXT], char *result){
    int bad = 0;
    
    for(int i = 0; i < TXT; i++) {
        if (wrd[i] == ' ' || wrd[i] == '\t' || wrd[i] == '\n') break;
        
        if(wrd[i] != txt[i]) {
            bad=1;
            break;
        }
        else
            result[i] = wrd[i];
    }

    if(bad==1)
        strcpy(result, "");
}

int inWord(char wrd[WORD], char ch) { // returns char index in word, if doesn't exist returns -1.
    for (int i = 0; i < WORD; i++) {
        if (wrd[i] == ' ' || wrd[i] == '\n' || wrd[i] == '\t') break;
        if (wrd[i] == ch) return i;
    }
    return -1;
}

int allStars(char tst[WORD]) { // checks if the whole word is *'s.
    for (int i = 0; i < WORD; i++) {
        if (tst[i] == ' ' || tst[i] == '\t' || tst[i] == '\n')
            break;
        if (tst[i] != '*')
            return -1;
    }

    return 1;
}

void anagram(char (*ang)[WORD], char (*txt)[TXT]) {
    printf("Anagram Sequences: ");

    char temp[WORD];
    char res[TXT];
    int idx=0, first = 0;
    strcpy(temp, *ang);
    
    for(int i=0; i<TXT; i++){
      if(allStars(temp) == 1){
          if (first == 0) {
            printf("%s", res);
            first =1 ;
          }
          else {
            printf("~%s", res);
            strcpy(res,"");
            idx=0;
        }
      }

      if((*txt)[i] == '~') return;
      
      strcpy(temp, *ang);
      idx = 0;
      
      for(int k = i; k < TXT; k++) {
          if (inWord(temp, (*txt)[k]) == -1) { // not in word.
            if ((*txt)[k] != ' ') { // not a space.
                i = k + 1;
                break;  
            }

            if(idx > 0) {
                res[idx] = (*txt)[k];
                idx++;
            }
          }

          else {
              temp[inWord(temp, (*txt)[k])] = '*';
              res[idx] = (*txt)[k];
              idx++;
              res[idx] = ' ';
          }
      }
    }
}

int main() {
    char wrd[WORD];
    char txt[TXT];

    for (int i = 0; i < WORD; i++) {
        scanf("%c", &wrd[i]);
        if (wrd[i] == '\t' || wrd[i] == '\n' || wrd[i] == ' ')
            break;
    }
    
    for (int i = 0; i < TXT; i++) {
        scanf("%c", &txt[i]);
        if (txt[i] == '~')
            break;
    }
    
    gematria(wrd, txt);
    char atb[WORD];
    strcpy(atb, wrd);
    
    for (int i = 0; i < WORD; i++) {
        if(atb[i] == ' ' || atb[i] == '\n' || atb[i] == '\t')
            break;
        int diff = 77 - atb[i];

        if (abs(diff) > 12) {
            diff = 109 -atb[i];
            atb[i] += diff*2+1;
        }
    }

    char atbResult[WORD] = "";
    atbash(atb,txt,atbResult);
    printf("Atbash Sequences: %s", atbResult);
    printf("\n");
    anagram(&wrd, &txt);

    return 0;
}