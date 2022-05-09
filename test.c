// 구조체
// 식당리스트- 식당이름,등급,가능여부
// 예약리스트 - 식당이름,예약자명
// 1.파일저장(예약리스트)
// 2.파일불러오기(예약가능한 식당
// 3.예약
// 4.예약취소
// 5.예약리스트출력
// 6.변경된 예약가능한 식당리스트 저장
// 7.특정등급의 예약가능한 식당리스트 출력
// 8.예약자 이름검색해서 예약정보확인
// 9.원하는 이름의 식당 예약가능여부확인
// 10.식당추가
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char shop[20];
    char tier;
    int pos;//1이면 가능 0이면 불가능
}rest;
typedef struct{
    char shop[20];
    char name[20];
}reserve;

int main(){
    rest* r[20];
    reserve* re[20];
    int count,menu;
    while(1){

    }
}
int loadrest(rest *p[]){
	int n = 0;
    FILE *file;
    file = fopen("rest.txt","r");
    while(!feof(file)){
		p[n]=(rest*)malloc(sizeof(rest));//이코드 안쓰면 segment fault뜸 저 구조체형식의 포인터변수만 선언한다고 되는게 아님,메모리를 할당해줘야함
		int result = fscanf(file,"%s %c %d",p[n]->shop,&(p[n]->tier),&(p[n]->pos));
		if (result < 1) break;//입력받더라도 잘못된 입렵을 받으면 n을 증가시키지 않고 break됨 정상적입력후 마지막 dummy값이 들어가는 거 방지
		n++;
	}
	fclose(file);
    return n;
}
void reserverest(rest *r[],reserve* re[],int a,int* b){//a가 식당의 개수 b가 햔재예약자수
    char shopname[20];
    scanf("%s",shopname);
    for(int i = 0; i < a; i++){
        if(strcmp(shopname,r[i]->shop) == 0 && r[i]->pos==1){
            r[i] -> pos = 0;
            strcpy(re[*b]->shop,shopname);
            printf("예약자이름입력:");
            scanf("%s",re[*b]->name);
            (*b)++;
        }
    }
}
void cancelreser(rest *r[],reserve* re[],int a,int b){
    char name[20];
    printf("예약자이름입력:");
    scanf("%s",name);
    for(int i = 0; i < b; i++){
        if(strcmp(name,re[i]->name)==0){
            
        }
    }
}
