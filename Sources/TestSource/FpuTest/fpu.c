void printINT(int a);
void printSymbol(char a);

int main() {
    float i = 10;
    float j = 10;
    float r = i * j;
    printINT(r);
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
        "push %%eax;"
        "mov %0, %%al;"
        "int $0x10;"
        "pop %%eax;"
        :"=rm"(a)
        :
        : "eax"
    );
}
