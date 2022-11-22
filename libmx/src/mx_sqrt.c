// #include <stdio.h>

int mx_sqrt(int x) {
    for (int i = 1; i < x; i++) {
        if ((i * i) == x) {
            return i;
        }
    }
    return 0;
}

// int main(void){
//     printf("%d", mx_sqrt(1024));
//     return 0;
// }
