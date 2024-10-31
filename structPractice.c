// C program to implement 
// the above approach 
#include <stdio.h> 
#include <string.h> 

// Declaration of inner structure 
struct college_details 
{ 
int college_id; 
char college_name[50]; 
	
}; 

// Declaration of Outer structure 
struct student_detail 
{ 
int student_id; 
char student_name[20]; 
float cgpa; 
	
// Inner structure variable 
struct college_details *clg;
} stu, *stu_ptr; 

// Driver code 
int main() 
{ 
struct college_details college = {14567, "GeeksforGeeks"};

struct student_detail stu = {12, "Kathy", 7.8, &college}; 
	
stu_ptr = &stu;
	
// Printing the details 
printf("College ID : %d \n", stu_ptr->clg -> college_id); 
printf("College Name : %s \n", stu_ptr->clg -> college_name); 
printf("Student ID : %d \n", stu_ptr->student_id); 
printf("Student Name : %s \n", stu_ptr->student_name); 
printf("Student CGPA : %f \n", stu_ptr->cgpa); 
return 0; 
}
