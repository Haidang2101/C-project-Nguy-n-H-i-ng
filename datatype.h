#include <stdbool.h>
struct Date {
	int month, day, year;
};

struct Student{
	char studentId[10];
	char name[20];
	struct Date dateOfBirth;
	bool gender;
	char email[30];
	char phone[20];
	char password[20];
};



