#include <stdio.h>

/*
 *
 * gcc -c test.cpp
 * gcc -shared -o test.dll test.o
 *
 */
extern "C" {
    int FakeRecProcessPages(int sid, const char* pDocFile, const char* pImageFiles[]) {
        printf("Settings Id: %d\nDocument File: %s\n", sid, pDocFile);

        if(NULL != pImageFiles) {
            printf("Image Files:\n");
            for(const char** current = pImageFiles; NULL != current && NULL != *current; ++current) {
                printf("\t%s\n", *current);
            }
        }

        return 0;
    }
}
