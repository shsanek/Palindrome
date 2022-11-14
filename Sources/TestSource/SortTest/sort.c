void printINT(int a);
void printSymbol(char a);

int main() {
    int a[5];
    a[0] = 3;
    a[1] = 2;
    a[2] = 0;
    a[3] = 1;
    a[4] = -2;

    for (int i = 0; i < 5; i++) {
        int j = 0;
        while (j < i) {
            if (a[i] < a[j]) {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
            j++;
        }
    }

    for (int i = 0; i < 5; i++) {
        printINT(a[i]);
        printSymbol(' ');
    }
    return 0;
}

void printINT(int a) {
    char text[16];
    if (a < 0) {
        printSymbol('-');
        a = -a;
    }
    if (a == 0) {
        printSymbol('0');
        return;
    }
    int index = 0;
    while (a > 0) {
        text[index] = '0' + a % 10;
        a = a / 10;
        index += 1;
    }
    for (int i = 0; i < index; i++) {
        printSymbol(text[index - 1 - i]);
    }
}

void printSymbol(char a) {
    asm (
        "mov %0, %%al;"
        "int $0x10;"
        :"=rm"(a)
        :
        : "%al"
    );
}

