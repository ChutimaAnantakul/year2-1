#include <stdio.h>
#define b 20
int a[b],i,me,data;


menu(){
	int m;
	printf("_________________________\n");
	printf("   1 : Input Data\n");
	printf("   2 : Search Data\n");
	printf("   0 : Exit Program\n");
	printf("Enter menu : ");
	scanf("%d",&m);
	if(m < 0 || m > 2){
		printf("\nUnknow menu\nEnter menu again. \n");
		m = menu();
	}
	return m;
}

sort(){ // selection
	int key,k,c;
	for(k = 0;k<b;k++){
		for(key = k+1;key < b;key++){
			if(a[k] > a[key]){
				c = a[k];
				a[k] = a[key];
				a[key] = c;
			}
		}
	}
}
input(){
	for(i = 0;i < b;i++){
		printf("Input data[%d] : ",i+1);
		scanf("%d",&data);
		a[i] = data;
	}
	sort();
}



search(){
	int dot;
	printf("Enter data to seach : ");
	scanf("%d",&dot);
	for(i = 0;i < b; i++){
		if(dot == a[i]){
			dot = -1;
			break;
		}
	}
	switch(dot){
		case -1 :
			printf("\n>>>>>> Data is found <<<<<<<\n");
			break;
		default :
			printf("\n>>>>>> Data is not found <<<<<<\n");
			break;
	}
}

main(){
	while(true){
		switch(menu()){
			case 1 :
				input();
				break;
			case 2 :
				search();
				break;
			default :
				return false;
		}
	}
}
