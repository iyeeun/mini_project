#ifndef _MANAGER_H
#define _MANAGER_H
#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int listProduct(Product *p, int index){
    printf("****** 상품 목록 ******\n");
    for(int i = 0; i < index; i ++) {
    	if(p[i].price == 0)
		continue;
	printf("%d : ", i+1);
        readProduct(p[i]);
    }    
    printf("\n");
    return 1;
}

void searchProductName(Product *p, int index) {
	int searchcnt = 0;
	char search[50];

	getchar();
	printf("검색하고 싶은 상품의 이름을 입력해주세요. :");
	scanf("%[^\n]s", search);
	for(int i = 0; i < index; i ++) {
		if(strstr(p[i].name, search)) {
			readProduct(p[i]);
			searchcnt ++;
		}
	}
	if(searchcnt == 0)
		printf("\n%s\n에 대한 검색 결과가 없습니다.\n", search);
}

int saveData(Product *p, int index) {
	FILE *fp = fopen("product.txt", "wt");
	fprintf(fp, "%s %d %d %d %d\n", p->name, p->weight, p->price, p->stars, p->numStars);
	fclose(fp);
	return 1;
}

#endif
