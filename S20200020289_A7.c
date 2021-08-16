//Codes written by NIKHIL KUMAR; ROLL - S20200020289:---

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

//que - 1

typedef struct {
    int roll;
    char name[20];
    float marks[3];
}stud_record;

stud_record * record_search(stud_record record_array[], int n, int roll) {
    stud_record* temp = NULL;

    for(int i=0; i<n; i++) {
        if (record_array[i].roll == roll) {
            temp = &record_array[i];
            return temp;
        }
    }
    return temp;
}



// que - 2

int  check_string(char arr[]){

    int count1 = 0, count2 = 0;

    for(int i = 0; i<51; i++){
    if(i == 50 || arr[i] == '\0')
         return count1;

        if(arr[i] == '1')
        {if(count2==1)
            return 0;
            else  count1 = 1;
        }
        if(arr[i] == '0'){
            if(count1==1)
             count2 = 1;
            }
      }
}




//que - 3

int modified_binary_search(int array[], int n, int key, int k){

    int top, mid, last, search = key;

    top = k;
    last = n - 1;
    mid = (top - last) / 2;
    
    while (top <= last){

        if (array[mid] < search)
            top = mid + 1;
        else if (array[mid] == search)
        {
            return mid + 1;
        }
        else
            last = mid - 1;

        mid = (top + last) / 2;
    }

    top = 0, last= k-1, mid = (top + last) / 2;

    while (top <= last){

        if (array[mid] < search)
            top = mid + 1;
        else if (array[mid] == search)
        {
            return mid + 1;
        }
        else
            last = mid - 1;

        mid = (top + last) / 2;
    }
    return -1;
}




int main(void) {
// que - 1------------------------------------------------------------------------------------------------------------------
/*
    stud_record stu[5];
    stud_record* temp;
    int srch_roll;

    stu[0].roll = 304;
    strcpy(stu[0].name, "Meghana");
    stu[0].marks[0] = 9.5; stu[0].marks[1] = 6.2; stu[0].marks[2] = 8.9;

    stu[1].roll = 289;
    strcpy(stu[1].name, "Nikhil");
    stu[1].marks[0] = 9.0; stu[1].marks[1] = 7.8; stu[1].marks[2] = 8.9;

    stu[2].roll = 250;
    strcpy(stu[2].name, "Prashant");
    stu[2].marks[0] = 8.4; stu[2].marks[1] = 4.5; stu[2].marks[2] = 9.8;

    stu[3].roll = 170;
    strcpy(stu[3].name, "Ashwani");
    stu[3].marks[0] = 7.7; stu[3].marks[1] = 8.4; stu[3].marks[2] = 4.6;


    printf("Enter the roll of student u want to find student...\n(Enter either of rolls = 304/289/250/170)  = ");
    scanf("%d", &srch_roll);
    temp = record_search(stu, 3, srch_roll);

    if (temp == NULL)
        printf("Record not found!\n");
    
    else {
        printf("\n\t\tThis roll no. is present in records!\n");
        printf("\t--------------------------------------------------------\n\n");
        printf("Student name: %s\n", temp->name);
        printf("Student roll_no.: %d\n", temp->roll);
        printf("Student marks: %.2f\t %.2f\t %.2f\n", temp->marks[0], temp->marks[1], temp->marks[2]);
    }
    return 0;
*/

//que - 2--------------------------------------------------------------------------------------------------------------------------
/*
     printf("Enter string : ");
    char arr[50];
    scanf("%s", arr);

    if(check_string(arr))
    printf("1\n");
    else
    printf("0\n");
    return 0;
*/

// que - 3--------------------------------------------------------------------------------------------------------------------
/*
    int array[5] ={3,4,5,1,2};
    int key = 3;

    int location = modified_binary_search(array, 5, key, 2);
    if( location == -1){
        printf("\t%d NOT found in the array...\n", key);
    } else {
        printf("\t%d founded at location %d...\n", key, location);
    }
    return 0;
*/

}