#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PROGRAM_NAME "C:\\PROGRA~1\\Java\\jdk8u312-b01\\jre\\bin\\java.exe"

int main(int argc, char** argv) {
    // 应分配的空间 = 程序名长度 + (参数个数 - 1) * 3(空格和前后两个引号) + 每个参数的长度 + 1(最后的NUL字符)
    int size = strlen(PROGRAM_NAME) + (argc - 1) * 3 + 1;
    
    // 测试长度
    for (int i = 1; i < argc; i++) {
        size += strlen(argv[i]);
    }

    // 编写命令
    char* cmd = malloc(size);
    for (int i = 0; i < size; i++) { // 清空数组
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
