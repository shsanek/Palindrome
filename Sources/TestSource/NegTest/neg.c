void printINT(int a);
void printSymbol(char a);

int main() {
    int a = 10;
    a = a * -1;
    printINT(a);
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
    asm (
        "mov %0, %%al;"
        "int $0x10;"
        :"=rm"(a)
        :
        : "%al"
    );
}
