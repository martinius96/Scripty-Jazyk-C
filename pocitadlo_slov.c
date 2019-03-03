#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
char word[200];
struct node * next;
int count;
};
struct node* add_node(struct node* first,const char* word) {
	struct node* item = (struct node*)malloc(sizeof(struct node));	
	strcpy(item->word,word); //kopiruj string
	item->next = NULL; //dalsi prvok nastav na null
	if(first == NULL){
		first = item;
		item->count = 1;
		return item;
	}else{
		struct node* this = first;
		while(this->next != NULL){
			if(strcmp(this->word, word)==0){
				this->count+=1;
				 return first;
			}
			this = this->next;
		}
		this->next =  calloc(1, sizeof(struct node));
		this->next->count=1;
		strcpy(this->next->word, word);
	}
	//this->next->count =1;
	return first;
}
void print_node(struct node* first) {
	struct node* cursor = first;
	while (cursor != NULL) {
		printf("%s", cursor->word);
		printf(" %d\n", cursor->count);
		cursor = cursor->next;
	}
}
int main(){
	char word[200];
	struct node* node = NULL;


	while(1){
		printf("Zadajte slovo\n");
		int r = scanf("%s", word);
		if (r == 1)	{
		
			node = add_node(node, word);
               
			printf("Obsah zoznamu:\n");
			print_node(node);
               }
               else if  (r == EOF){
			break;
		}
	}
   	return 0;
}
