#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 
 
#define max 100  
#define lengthofstr 500  
 
// using structure for task aka stack for storing tasks  
typedef struct task_editor{  
    char *task[lengthofstr]; // data variable of stack  
    int tracker; // top variable as tracker of tasks  
} Task;  
 
// create function to allocate memory  
Task *create() {  
    Task *tsk = (Task*)malloc(sizeof(Task));  
    tsk->tracker = -1;  
    return tsk;  
}  
 
// push function of stack as add task to add the tasks 
void add(Task *newtask, char *desc) {  
    if(newtask == NULL)  
        newtask = create();  
    else {  
        newtask->tracker++;  
        newtask->task[newtask->tracker] = (char *)malloc(strlen(desc) + 1); 
        strcpy(newtask->task[newtask->tracker], desc);  
    }  
}  
 
// peek function as view task to view all the tasks 
void view(Task *newtask) {  
    int i;  
    if(newtask->tracker != -1) {  
        for(i = 0; i < newtask->tracker + 1; i++) {  
            printf("%d. %s\n", i + 1, newtask->task[i]);  
        }  
    }  
    else {  
        printf("No task added\n");  
    }  
    printf("\n"); 
}  
 
// pop function as delete task to delete the specific tasks 
Task *delete(Task *t_task, int num) {  
    int i; 
    Task *tempholder = create(); 
    for(i = 0; i < t_task->tracker + 1; i++) { 
        if(i == num - 1) { 
            free(t_task->task[i]);  
            continue; 
        } 
        else { 
            add(tempholder, t_task->task[i]); 
        } 
    } 
    free(t_task);  
    return tempholder; 
} 
 
// change function to update the tasks 
Task *change(Task *tsk, int del, char *taskscanner) { 
    free(tsk->task[del - 1]);  
    tsk->task[del - 1] = (char *)malloc(strlen(taskscanner) + 1); 
    strcpy(tsk->task[del - 1], taskscanner); 
    return tsk; 
} 
 
int main() { 
    int i = 1, fn_num, del; 
    char taskscanner[max]; 
    Task *tsk = create(); 
 
    while(i != 0) { 
        printf("----------------MENU----------------\n\n"); 
        printf("Choose an option:\n"); 
        printf("1. Add task \n"); 
        printf("2. View task \n"); 
        printf("3. Delete task \n"); 
        printf("4. Update task \n"); 
        printf("5. EXIT \n\n"); 
         
        scanf("%d", &fn_num); 
         
        if(fn_num == 1) { 
            printf("Enter the task:\n"); 
            scanf(" %[^\n]s", taskscanner); 
            add(tsk, taskscanner); 
            printf("\n"); 
        } 
         
        else if(fn_num == 2) 
            view(tsk); 
         
        else if(fn_num == 3) { 
            printf("Enter the number of task to be deleted:\n"); 
            scanf("%d", &del); 
            tsk = delete(tsk, del); 
            printf("\n"); 
        } 
         
        else if(fn_num == 4) { 
            printf("Enter the number of task:\n"); 
            scanf("%d", &del); 
            printf("\nEnter the updated task:\n"); 
            scanf(" %[^\n]s", taskscanner);  
            tsk = change(tsk, del, taskscanner); 
            printf("\n"); 
        } 
         
        else if(fn_num == 5) { 
            for (int j = 0; j <= tsk->tracker; j++) { 
                free(tsk->task[j]);  
            } 
            free(tsk);  
            return 0; 
        } 
         
        else 
            printf("Enter a valid option number:\n"); 
         
        //clrscr(); 
    } 
    return 0;  
}