#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PROGRAM_NAME "C:\\PROGRA~1\\Java\\jdk8u312-b01\\jre\\bin\\java.exe"

int main(int argc, char** argv) {
    // Ӧ����Ŀռ� = ���������� + (�������� - 1) * 3(�ո��ǰ����������) + ÿ�������ĳ��� + 1(����NUL�ַ�)
    int size = strlen(PROGRAM_NAME) + (argc - 1) * 3 + 1;
    
    // ���Գ���
    for (int i = 1; i < argc; i++) {
        size += strlen(argv[i]);
    }

    // ��д����
    char* cmd = malloc(size);
    for (int i = 0; i < size; i++) { // �������
        cmd[i] = '\0';
    }
    strcat(cmd, PROGRAM_NAME);
    for (int i = 1; i < argc; i++) {
        strcat(cmd, " \"");
        strcat(cmd, argv[i]);
        strcat(cmd, "\"");
    }
    printf("%s\n", cmd);
    system(cmd);
    return 0;
}
