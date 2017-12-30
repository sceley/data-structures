#define MAX_COURSE 10

typedef char CourseName[4];

typedef struct {
	CourseName courses[MAX_COURSE];
	int grades;
	int length;
} Term;