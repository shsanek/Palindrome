int fact(int num);
void printINT(int a);
void printSymbol(char a);

int main() {
    for (int i = 0; i<10; i++) {
        printINT(fact(i));
    }
    return 0;
}

int fact(int num) {
    if (num == 0) {
        return 1;
    }
    return num * fact(num - 1);
}

void printINT(int a) {
    char text[16];
    if (a < 0) {
        printSymbol('-');
        a = -a;
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
    __asm__ (
        "push %eax;"
        "nop;"
        "nop;"
        "pop %eax;"
    );
}

