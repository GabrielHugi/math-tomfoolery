#include <stdio.h>
int ninethou = 0;
int survivor(int numofpeople, int numofjump) {
    if (numofpeople == 1) return 0;
    // returns zero above as for the killing starts on the first soldier
    if (ninethou == 0) {
        ninethou = 1;
        return (survivor(numofpeople-1, numofjump) + 0) % numofpeople;
    } 
    else {
        ninethou = 1;
        return (survivor(numofpeople-1, numofjump) + numofjump) % numofpeople;
    }
    // above line goes jumping from soldier to soldier ^ and looping ^ and i still dont get how it works to be honest
}

int main() {
    int start, i, results[1000], resultsi = 0;
    for (start = 14; start <= 100; start++) {
        if (start != 0) {
            for (i = 1; survivor(start, i) != 12; i++) {ninethou = 0;}
            //printf("%d\n", i+1); 
            results[resultsi] = i+1;
            resultsi++;
        }   
    }
    for (i = 0; i < resultsi; i++) {
        printf("%d - %d\n", i+14, results[i]);
    }
    
    return 0;
}


/*

#include <stdio.h>
int ninethou = 0;
int survivor(int numofpeople, int numofjump) {
    if (numofpeople == 1) return 0;
    // returns zero above as for the killing starts on the first soldier
    if (ninethou == 0) {
        ninethou = 1;
        return (survivor(numofpeople-1, numofjump) + 0) % numofpeople;
    } 
    else {
        ninethou = 1;
        return (survivor(numofpeople-1, numofjump) + numofjump) % numofpeople;
    }
    // above line goes jumping from soldier to soldier ^ and looping ^ and i still dont get how it works to be honest
}

int main() {
    int start, i, results[1000], resultsi = 0;
    scanf("%d", &start);
    if (start != 0) {
            for (i = 3; survivor(start, i) != 12; i++) {ninethou = 0;}
            //printf("%d\n", i+1); 
            results[resultsi] = i+1;
            resultsi++;
    }
    while (start != 0) {
        scanf("%d", &start);
        if (start != 0) {
            for (i = 3; survivor(start, i) != 12; i++) {ninethou = 0;}
            //printf("%d\n", i+1); 
            results[resultsi] = i+1;
            resultsi++;
        }   
    }
    for (i = 0; i < resultsi; i++) {
        printf("%d\n", results[i]);
    }
    
    return 0;
}*/