
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/* Student Structure */

struct student {
	int id;
	char name[50];
	int age;
	float gpa;
};

/* node of current student and pointer to the next in linked list */

struct node {
	struct student data;
	struct node *next;
};

/* pointer of first student in the list */

struct node *head = NULL;

/* Functions Prototype */

void addStudent(const struct student *const data);
void displayStudents(void);
void SearchStudentByID(int ID);
void updateStudent(int ID);
void deleteStudent(int ID);
float calculateAverageGPA(void);
void searchHighestGPA(void);

/* Main */

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int choice, id;
	float result = 0.0;
	struct student s1;

	while (1) {
		printf(
				"---------------------------------------------------------------\n");
		printf("Student Management System\n");
		printf("1. Add Students\n");
		printf("2. Display Students\n");
		printf("3. Search Students By ID\n");
		printf("4. Update Students Info\n");
		printf("5. Delete Students\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter Choice:\n");
		scanf("%d", &choice);
		printf(
				"---------------------------------------------------------------\n");

		switch (choice) {
		case 1: /*Add Student*/
			printf("Enter ID:\n");
			scanf("%d", &s1.id);
			printf("Name:\n");
			scanf("%s", s1.name);
			printf("Age:\n");
			scanf("%d", &s1.age);
			printf("GPA:\n");
			scanf("%f", &s1.gpa);
			addStudent(&s1);
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			printf("Enter student ID:");
			scanf("%d", &id);
			SearchStudentByID(id);
			break;
		case 4:
			printf("Enter Student ID to Update:");
			scanf("%d", &id);
			updateStudent(id);
			break;
		case 5:
			printf("Enter student ID to delete:");
			scanf("%d", &id);
			deleteStudent(id);
			break;
		case 6:
			result = calculateAverageGPA();
			printf("The average GPA is %0.4f\n", result);
			break;
		case 7:
			searchHighestGPA();
			break;
		case 8:
			printf("Finish \n");
			exit(0);
			break;
		default:
			printf("Invalid no. \n");
			break;
		}
	}
	return 0;
}

/* Functions */

void addStudent(const struct student *const data) {
	/* A pointer to loop  */
	struct node *current = NULL;
	/* A pointer to check if the id already existed or not */
	struct node *duplicate = NULL;
	/* Dynamic allocation for a new student in the system */
	struct node *link = (struct node*) malloc(sizeof(struct node));
	if (link != NULL) {
		duplicate = head;
		while (duplicate != NULL) {
			if (duplicate->data.id == data->id) // check duplicate id.
					{
				printf("This ID is already reserved!!\n");
				return;
			}
			duplicate = duplicate->next;
		}

		link->data.id = data->id;
		strcpy(link->data.name, data->name);
		link->data.age = data->age;
		link->data.gpa = data->gpa;

		/* Entering the student from the end of the system */

		link->next = NULL;
		if (head == NULL) {
			head = link;
			return;
		}
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = link;
	} else {
		printf("Error!!");
	}
}
/* Definition of displayStudents function */

void displayStudents(void) {

	struct node *ptr = head;
	if (ptr == NULL) {
		printf("No Students added yet!\n");
	} else {
		while (ptr != NULL) {
			printf("[ id: %d, Name: %s, Age: %d, GPA: %0.1f ]\n", ptr->data.id,
					ptr->data.name, ptr->data.age, ptr->data.gpa);
			ptr = ptr->next;
		}
	}
}

void SearchStudentByID(int ID) {

	struct node *current = NULL;

	if (head == NULL) {
		printf("No students to search!!\n");
		return;
	}

	current = head;
	while (current != NULL) // Looping until reaching the end of the system.
	{
		if (current->data.id == ID) // Checking if the id searched for is found.
				{

			printf("Student found\n");
			printf("[ id: %d, Name: %s, Age: %d, GPA: %0.1f ]\n",
					current->data.id, current->data.name, current->data.age,
					current->data.gpa);
			return;
		}
		current = current->next;
	}

	printf("Student with ID %d not found!!\n", ID);
}

void updateStudent(int ID) {

	struct node *current = NULL;

	if (head == NULL) {
		printf("No Students!!\n");
		return;
	}

	/* Start checking from the first student */

	current = head;

	while (current != NULL) {
		if (current->data.id == ID) {

			/* Entering the new info for the student */

			printf("Enter new info for the student with the id %d\n", ID);
			printf("Enter new name: ");
			scanf("%s", current->data.name);
			printf("Enter new age: ");
			scanf("%d", &current->data.age);
			printf("Enter new GPA: ");
			scanf("%f", &current->data.gpa);
			printf("Student info updated successfully!!\n");
			return;
		}

		current = current->next;
	}

	printf("The student with ID of %d is not found\n", ID);
}

void deleteStudent(int ID) {

	/* Two pointers to loop in the system */

	struct node *current = NULL;
	struct node *prev = NULL;
	struct node *delete_node = NULL;

	if (head == NULL) {
		printf("No students to be deleted!!!\n");
		return;
	}

	if (head->data.id == ID) // check the first student in the system.
			{
		delete_node = head;
		head = head->next;
		printf("Student with ID %d is successfully deleted.\n", ID);
		free(delete_node);
		return;
	}

	current = head->next;
	prev = head;

	while (current != NULL)
	{
		if (current->data.id == ID)
			delete_node = current;
		prev->next = current->next;
		printf("Student with ID %d is successfully deleted.\n", ID);
		free(delete_node);
		return;
	}
	prev = current;
	current = current->next;

	if (delete_node == NULL) {
		printf("The student with the ID %d is not found!!!\n", ID);
	}
}
float calculateAverageGPA(void) {

	struct node *current = NULL;
	float average = 0.0;
	int num = 0;
	float sum = 0.0;

	if (head == NULL)
	{
		return 0.0;
	}

	current = head;

	while (current != NULL)
	{

		sum += current->data.gpa;

		// Calculate the number of the students

		num++;
		current = current->next;
	}

	// Calculate the average of the GPAs

	average = sum / num;
	return average;
}
void searchHighestGPA(void) {

	struct node *current = NULL;
	float max = 0.0;

	if (head == NULL)
	{
		printf("No students to search!!\n");
		return;
	}

	current = head;

	int pos = 1;
	int max_pos = 1;

	int age_p = current->data.age;
	char name_p[20];
	strcpy(name_p, current->data.name);

	max = current->data.gpa;

	while (current != NULL)
	{
		if (current->data.gpa > max)
		{
			max = current->data.gpa;
			strcpy(name_p, current->data.name);
			age_p = current->data.age;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}

	printf("The highest GPA is %0.2f for the student with the id %d\n", max, max_pos);
	printf(" [ id: %d, Name: %s, Age: %d, GPA: %0.1f ]\n", max_pos, name_p, age_p, max);
}

