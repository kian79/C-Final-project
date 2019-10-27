#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct student {
    char name[12];
    char lastName[35];
    char studentID[8];
    char age[5];
    char sex[20];
    char major[60];
    char number[12];
    char address[100];
    struct student *next;
};

// -------------------------------------------------------------------------------------------------------

void save(student* head){
    FILE *ptr;
    student * s;
    ptr=fopen("d:\\project.txt","w");
    s=head->next;
    while(s !=NULL){
        fprintf(ptr,"\r\n");
        fputs(s->name, ptr);
        fprintf(ptr, "\r\n");

        fputs(s->lastName, ptr);
        fprintf(ptr, "\r\n");

        fputs(s->studentID, ptr);
        fprintf(ptr, "\r\n");

        fputs(s->age, ptr);
        fprintf(ptr, "\r\n");

		fputs(s->sex,ptr);
		fprintf(ptr,"\r\n");
		
        fputs(s->major, ptr);
        fprintf(ptr, "\r\n");

        fputs(s->number, ptr);
        fprintf(ptr, "\r\n");

        fputs(s->address, ptr);
        s=s->next;
    }
    fclose(ptr);
}


student *create_node() {
    student *s = (student *) malloc(sizeof(student));
    s->next = NULL;

    printf("Enter student's name:\r\n");
    scanf("%s", s->name);

    printf("Enter student's lastname:\r\n");
    scanf("%s", s->lastName);

    printf("Enter student's id:\r\n");
    scanf("%s", s->studentID);

    printf("Enter student's age:\r\n");
    scanf("%s", &s->age);

    printf("Enter student's sex:\r\n");
    scanf("%s", &s->sex);

    printf("Enter student's major:\r\n");
    scanf("%s", s->major);

    printf("Enter student's phone number:\r\n");
    scanf("%s", s->number);

    printf("Enter student's address:\r\n");
    scanf("%s", s->address);

    return s;
}

//---------------------------------------------------------------------------------------------------------------------

student *add_end(student *head, student *s) {
    student *tra;
    tra = head;
    while (tra->next != NULL) 
        tra = tra->next;
    tra->next = s;
    return head;
}

int strcompare(char str1[], char str2[]) {
    int j = 0;
    if (str1[0] == '\0' || str2[0] == '\0') return 0;
    while (str1[j] && str2[j]) {
        if (str1[j] == str2[j])j++;
        else return 0;
    }
    if((!str1[j] && str2[j]) || (str1[j] && !str2[j])) return 0;
    return 1;
}

int add_after_id(student *head, char *preId, student *secondStu) {
    student *temp;
    temp = head;
    while (temp != NULL) {
        if (strcompare(temp->studentID, preId)) {
            secondStu->next = temp->next;
            temp->next = secondStu;
            if(strcompare("0",preId)) printf("contact added successfuly at the first of the list");
             else
			 printf("contact added successfuly after %s\n", temp->name);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int add_after_pn(student *head, char prePn[], student *secondStu) {
    student *temp;
    temp = head;
    while (temp != NULL) {
        if (strcompare(temp->number, prePn)) {
            secondStu->next = temp->next;
            temp->next = secondStu;
            if(strcompare("0",prePn)) printf("contact added successfuly at the first of the list");
            else
			 printf("contact added successfuly after %s\n", temp->name);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

student *load_file(FILE *fptr) {
    char c = fgetc(fptr);
    if (c == EOF)
        return NULL;

    student *student_file = (student *) malloc(sizeof(student));
    char s[10];
    fscanf(fptr, "%s", student_file->name);
    fscanf(fptr, "%s", student_file->lastName);
    fscanf(fptr, "%s", student_file->studentID);
    fscanf(fptr, "%s", student_file->age);
    fscanf(fptr, "%s", student_file->sex);
    fscanf(fptr, "%s", student_file->major);
    fscanf(fptr, "%s", student_file->number);
    fscanf(fptr, "%s", student_file->address);
    student_file->next = NULL;
    return student_file;
}

void load(student *head) {
    FILE *fptr1 = fopen("d:\\project.txt", "r");
    if (!fptr1) return;

    struct student *cur;
    struct student *prev = NULL;
    while (true) {
        cur = load_file(fptr1);
        if (!cur) {
            break;
        }
        add_end(head, cur);
        prev = cur;
    }
    fclose(fptr1);
}

student *search(student *head,int c){
	student* temp=head;
	char input[20];
	switch(c){
		case 1:	
		printf("Enter student's name:\n\r");
		scanf("%s",input);
	    while(temp !=NULL){
		if(strcompare(temp->name,input)){
		printf("student's name is : %s\n", temp->name);
        printf("student's lastname is : %s\n", temp->lastName);
        printf("student's ID is : %s\n", temp->studentID);
        printf("student's age is : %s\n", temp->age);
        printf("student's sex is : %s\n",temp->sex);
        printf("student's major is : %s\n", temp->major);
        printf("students phone number is : %s\n", temp->number);
        printf("student's address is : %s\n", temp->address);	
		break;		
		}
		 temp=temp->next;
		if(!temp) printf("no %s found\n",input);
	}
	getchar();		
			break;
		case 2:
			printf("Enter student's id:\n\r");
			scanf("%s",input);
	while(temp){
		
		if(strcompare(temp->studentID,input)){
		printf("student's name is : %s\n", temp->name);
        printf("student's lastname is : %s\n", temp->lastName);
        printf("student's ID is : %s\n", temp->studentID);
        printf("student's age is : %s\n", temp->age);
		printf("student's sex is : %s\n",temp->sex);
        printf("student's major is : %s\n", temp->major);
        printf("students phone number is : %s\n", temp->number);
        printf("student's address is : %s\n", temp->address);	
		break;		
		}
		 temp=temp->next;
		if(!temp) printf("no %s found\n",input);
	}
		getchar();
			break;
		case 3:
			printf("Enter student's phone number:\n\r");
			scanf("%s",input);
	while(temp){
		
		if(strcompare(temp->number,input)){
		printf("student's name is : %s\n", temp->name);
        printf("student's lastname is : %s\n", temp->lastName);
        printf("student's ID is : %s\n", temp->studentID);
        printf("student's age is : %s\n", temp->age);
        printf("student's sex is : %s\n",temp->sex);
        printf("student's major is : %s\n", temp->major);
        printf("students phone number is : %s\n", temp->number);
        printf("student's address is : %s\n", temp->address);
		break;			
		}
		 temp=temp->next;
		  if(!temp) printf("no %s found\n",input);
	}getchar();
			break;
		case 4:
			printf("Enter student's lastname:\n\r");
			scanf("%s",input);
	while(temp){
		
		if(strcompare(temp->lastName,input)){
		printf("student's name is : %s\n", temp->name);
        printf("student's lastname is : %s\n", temp->lastName);
        printf("student's ID is : %s\n", temp->studentID);
        printf("student's age is : %s\n", temp->age);
        printf("student's sex is : %s\n",temp->sex);
        printf("student's major is : %s\n", temp->major);
        printf("students phone number is : %s\n", temp->number);
        printf("student's address is : %s\n", temp->address);	
		break;
		}
		  else temp=temp->next;
		  if(!temp) printf("no %s found\n",input);
	}
	getchar();
			break;
	}
	return temp;
}

student *displayList(student *head) {
    student *temp;
    temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("------------student's number <%d> information is --------- \n", i);
        printf("student's name is : %s\n", temp->name);
        printf("student's lastname is : %s\n", temp->lastName);
        printf("student's ID is : %s\n", temp->studentID);
        printf("student's age is : %s\n", temp->age);
        printf("student's sex is : %s\n",temp->sex);
        printf("student's major is : %s\n", temp->major);
        printf("students phone number is : %s\n", temp->number);
        printf("student's address is : %s\n", temp->address);
        temp = temp->next;
        i++;
        printf("\n");
    }
}
int check(student* temp,student*s){
    if (!strcompare(temp->name, s->name))
        return 0;
    if (!strcompare(temp->lastName, s->lastName))
        return 0;
    if (!strcompare(temp->studentID, s->studentID))
        return 0;
    if (!strcompare(temp->address, s->address))
        return 0;
    if (!strcompare(temp->number, s->number))
        return 0;
    if (!strcompare(temp->age, s->age))
        return 0;
    if (!strcompare(temp->sex,s->sex))
        return 0;
    if (!strcompare(temp->major, s->major))
        return 0;
    return 1;
}
bool IfInList(student *head, student *s) {
    student *temp;
    temp = head;
    while (temp != NULL) {
        if(check(temp,s))
            return 1;
        temp=temp->next;
    }
    return 0;
}
student *fake_head() {
    student *head = (student *) malloc(sizeof(student));
    head->name[0] = '\0';
    head->lastName[0] = '\0';
    head->studentID[0] = '0';
    head->studentID[1] = '\0';
    head->number[0] = '0';
    head->number[1] = '\0';
    head->age[0] = '0';
    head->sex[0] = '\0';
    head->major[0] = '\0';
    head->next = NULL;
    return head;
}

student *del_node(student *head,int d) {
	char input[30];   
    student* temp;
    student *temp1;
    temp=head;

    switch(d){
    	case 1:
    		printf("enter student's name\n");
    		scanf("%s",input);
    		while(temp->next !=NULL){
    			if(strcompare(temp->next->name,input)){
    			temp1=temp->next;
				temp->next=temp->next->next;
				printf("%s deleted successfuly",input);
				free(temp1);
				break;
				}
				temp=temp	->next;
			}
			break;
    	case 2:
    		printf("enter student's id\n");
    		scanf("%s",input);
    		while(temp->next !=NULL){
    			if(strcompare(temp->next->studentID,input)){
    			temp1=temp->next;
				temp->next=temp->next->next;
				printf("%s deleted successfuly",input);
				free(temp1);
				break;
				}
				temp=temp->next;
			}
    		break;
    	case 3:
    		printf("enter student's phone number\n");
    		scanf("%s",input);
    		while(temp->next !=NULL){
    			if(strcompare(temp->next->number,input)){
    			temp1=temp->next;
				temp->next=temp->next->next;
				printf("%s deleted successfuly",input);
				free(temp1);
				break;
				}
				temp=temp->next;
			}
    		break;
    	case 4:
    		printf("enter student's lastname\n");
    		scanf("%s",input);
    		while(temp->next !=NULL){
    			if(strcompare(temp->next->lastName,input)){
    			temp1=temp->next;
				temp->next=temp->next->next;
				printf("%s deleted successfuly",input);
				free(temp1);
				break;
				}
				temp=temp->next;
			}
    		break;
	}
	getchar();

}

void clear(void) {
    while (getchar() != '\n');
}

void edit(student *head){
	student* temp;
	printf("How do you want to find the contact whom you want to edit?\n\r");
	printf("1-by name");
    printf("\t\t\t2-by id");
    printf("\t\t\t3-by phone number");
    printf("\t\t\t4-by lastname\n");
   	int SNum;
    scanf("%d",&SNum);
    bool flag=true;
    temp=search(head->next,SNum);
    if(!temp) return ;
	int n;
    while(flag){
	printf("\nWhat do you want to edit?\n");
    printf("1-name\n");
	printf("2-lastname\n");
	printf("3-student id\n");
	printf("4-age\n");
	printf("5-sex\n");
	printf("6-major\n");
	printf("7-phonenumber\n");
	printf("8-address\n");
	printf("9-quit\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("Enter new name:\n");
			scanf("%s",temp->name);
			break;
		case 2:
			printf("Enter new lastname:\n");
			scanf("%s",temp->lastName);
			break;
		case 3:
			printf("Enter new id:\n");
			scanf("%s",temp->studentID);
			break;
		case 4:
			printf("Enter new age:\n");
			scanf("%s",temp->age);
			break;
		case 5:
			printf("Enter new sex:\n");
			scanf("%s",temp->sex);
			break;
		case 6:
			printf("Enter new major:\n");
			scanf("%s",temp->major);
			break;
		case 7:
			printf("Enter new phone number:\n");
			scanf("%s",temp->number);
			break;
		case 8:
			printf("Enter new address:\n");
			scanf("%s",temp->address);
			break;
		case 9:
			flag=false;
			break;}
			system("cls");
		printf("student's name is : %s\n", temp->name);
        printf("student's lastname is : %s\n", temp->lastName);
        printf("student's ID is : %s\n", temp->studentID);
        printf("student's age is : %s\n", temp->age);
        printf("student's sex is : %s\n",temp->sex);
        printf("student's major is : %s\n", temp->major);
        printf("students phone number is : %s\n", temp->number);
        printf("student's address is : %s\n", temp->address);	
	}
	save(head);
	}
int main() {
    char c;
    student *s;
    system("color 2b");
    student *head = fake_head();
    FILE *ptr;
    load(head);
    while (1) {
		system("cls");
        bool flag = false;
        printf("\t\t\t\t**------------------------------------------------**\n");
        printf("\t\t\t\t\t  welcome to my phonebook:)))\n");
 		printf("\t\t\t\t**------------------------------------------------**\n");
        printf("\t\t\t\t|\twhat can I do for you? :)   \t\t   | \r\n");
        printf("\t\t\t\t|\tEnter <a> to add a new contact \t\t   | \r\n");
        printf("\t\t\t\t|\tEnter <r> to remove a contact \t\t   | \r\n");
         printf("\t\t\t\t|\tEnter <s> to search a contact \t\t   | \r\n");
        printf("\t\t\t\t|\tEnter <d> to display list of contacts\t   | \r\n");
        printf("\t\t\t\t|\tEnter <e> to edit an existing contact      | \r\n");
        printf("\t\t\t\t|\tEnter <q> to quit \t\t\t   | \r\n");
        printf("\t\t\t\t**------------------------------------------------**\n");
//            clear();
        scanf("%c", &c);
        system("cls");
        switch (c) {
            case 'a':
            case 'A':
                ptr = fopen("d:\\project.txt", "a");
                s = create_node();
                if (IfInList(head, s) || head->next == NULL) {
                    head = add_end(head, s);
                    printf("contact added successfuly at the end of the list");
                    getchar();
                    save(head);
                } else {
                    char define;
                    char preId[7];
                    char prePn[11];
                    printf("how do you want to define previous student?(<i>for ID and <p> for phonenumber)\r\n");
                    clear();
                    scanf("%c", &define);
                    switch (define) {
                        case 'I':
                        case 'i':
                            printf("plaese enter the id of previous student: (enter <0> to add at the first of the list)\r\n");
                            clear();
                            scanf("%s", preId);
                            if (add_after_id(head, preId, s)) {save(head);printf("\n\n\n\n\t\t\t\t\t\tEnter any key"); getchar();}
                            else {
                                printf("There is no student with this id\n");
                            }
                            break;
                        case 'p':
                        case 'P':
                            printf("plaese enter the phone number of previous student: (enter <0> to add at the first of the list)\r\n");
                            clear();
                            scanf("%s", prePn);
                            if (add_after_pn(head, prePn, s)){save(head);printf("\n\n\n\n\t\t\t\t\t\tEnter any key"); getchar(); }
                            else {
                                printf("There is no student with this phone number\n");
                            }
                            break;
                    }
                }
                break;

            case 'q':
            case 'Q':
                flag = true;
                break;

            case 'R':
            case 'r':
            	printf("how do you want to remove the student from the list?\n\r");
            	int d;
            	printf("1-by name");
              	printf("\t\t\t2-by id");
            	printf("\t\t\t3-by phone number");
            	printf("\t\t\t4-by lastname\n");
            	scanf("%d",&d);
                del_node(head,d);
                save(head);
                break;
            case 'D':
            case 'd':
            	if(!head->next) printf("Nothing to show!!!\n\n\n\n\n\t\t\t\t\t");
                displayList(head->next);
                printf("press 'Enter'' to continue :)");
                getchar();
                break;
            case 'S':
            case 's':
            	printf("how do you want to search? :) \n\r");
            	printf("1-by name");
              	printf("\t\t\t2-by id");
            	printf("\t\t\t3-by phone number");
            	printf("\t\t\t4-by lastname\n");
            	int SNum;
            	scanf("%d",&SNum);
            	search(head->next,SNum);
                break;
            case 'E':
            case 'e':
				edit(head);
	            break;
	        default:
	        	printf("invalid input press 'Enter' to try again:) \n");
	        	getchar();
	        	break;
        }
        clear();
        if (flag) break;
    }
    return 0;
}
