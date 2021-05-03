#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grades.h"
#include "linked-list.h"
#define FAIL 1
#define MAX_GRADE 100
void destroy_student (void *elem);
void destroy_course (void *elem);
int clone_student (void *elem, void **output);
int clone_course (void *elem, void **output);

void student_printer(struct iterator *student_i);
struct iterator* find_id (struct grades *grades, int id_num);
//struct iterator* find_course (struct student *student, const char *course);

//int main(int argc, char *argv[]) {

struct grades {
  struct list *list;
};
struct student {
	//struct student *next;
	//struct student *prev;
	char* name;
	int id;
	struct list *course_list;
};

struct course {
	//struct course *next;
	//struct course *prev;
	char* course_name;
	int grade;
};
/*
 * @brief Prints the courses of the student with "id" in the following
 * format: STUDENT-NAME STUDENT-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @param grades is the system of grades
 * @param student_i is an iterator to the requested student
 */
void student_printer(struct iterator *student_i){
	printf("%s %d:", (((struct student*)list_get(student_i))->name),
			(((struct student*)list_get(student_i))->id));
	struct iterator* student_info =
			list_begin((((struct student*)list_get(student_i))->course_list));
	if(student_info != NULL){
		printf(" %s %d", (((struct course*)student_info)->course_name),
						(((struct course*)student_info)->grade));
	//	printf(" %s %d", (((struct course*)student_info)->course_name),
		//				(((struct course*)student_info)->grade));
		while((student_info=list_next(student_info))!=NULL){
			printf(", %s %d", (((struct course*)student_info)->course_name),
				(((struct course*)student_info)->grade));
		}
	}
	printf("\n");
}
/*
 * @brief Finds a student in the system according to his id
 * @param grades is the system
 * @param id_num is the id of the studefrent we're looking for
 * @returns an iterator to the student in the system
 */
struct iterator* find_id (struct grades *grades, int id_num){
	struct iterator *i=list_begin(grades->list);
	while (i!=NULL && (((struct student*)(list_get(i)))->id)!=id_num){
		i = list_next(i);
	}
	if (i==NULL){
		return NULL;
	}
	return i;
}
/*
 * @brief Finds a course in a students course list according to its name
 * @param grades is the system in which the students appear
 * @param course is the name of the course we're looking for
 * @returns an iterator to the course in the list of the student
 */
struct iterator* find_course (struct student *student,const char *course){
	struct iterator* i=list_begin(student->course_list);
	while (i!=NULL &&
		!strcmp(((struct course*)(list_get(i)))->course_name, course)){
		i = list_next(i);
	}
	if (i==NULL){
		return NULL;
	}
	return i;
}

struct grades* grades_init(){
	struct grades *student_list=(struct grades*)malloc(sizeof(struct grades*));
	if(!student_list){
		return NULL;
	}
	student_list->list = list_init(clone_student, destroy_student);
	return student_list;
}

void grades_destroy(struct grades *grades){
	list_destroy(grades->list);
	free(grades);
}

int grades_add_student(struct grades *grades, const char *name, int id){
	if (grades->list==NULL || find_id(grades, id)!=NULL){
		return FAIL;
	}
	struct student *student;
	student=(struct student*)malloc(sizeof(*student));
	if(!student){
		return FAIL;
	}
	student->name=(char*)malloc((strlen(name)+1)*sizeof(char));
	if(!name){
		return FAIL;
	}
	strcpy(student->name, name);
	student->id=id;
	student->course_list = list_init(clone_course, destroy_course);
	list_push_back(grades->list, student);
	free(student);
	return 0;
}

int grades_add_grade(struct grades *grades,
					 const char *name,
					 int id,
					 int grade){
	struct iterator *i=find_id(grades, id);
	if (grades==NULL || i==NULL || grade<0 || grade>MAX_GRADE ||
			find_course(list_get(i), name)!=NULL){
		return FAIL;
	}
	struct course *course;
	course=(struct course*)malloc(sizeof(*course));
	if(!course){
		return FAIL;
	}
	course->course_name=(char*)malloc((strlen(name)+1)*sizeof(char));
	if(!course->course_name){
		return FAIL;
	}
	strcpy(course->course_name,name);
	course->grade=grade;
	list_push_back(((struct student*)list_get(i))->course_list, course);
	free(course);
	return 0;
}

float grades_calc_avg(struct grades *grades, int id, char **out){
	int sum=0;
	struct iterator *i=find_id(grades, id);
	struct iterator* j=
			list_begin((((struct student*)(list_get(i)))->course_list));
	if ((list_size(((struct student*)(list_get(i)))->course_list))==0){
		return 0;
	}
	while(j!=NULL){
		sum+=((struct course*)list_get(j))->grade;
	}
	return (float)sum/
			list_size(((struct student*)(list_get(i)))->course_list);
}

int grades_print_student(struct grades *grades, int id){
	struct iterator* student_i =find_id (grades,id);
	if(student_i==NULL){
		return FAIL;
	}
	student_printer(student_i);
	return 0;
}

int grades_print_all(struct grades *grades){
	if(grades->list==NULL){
		return FAIL;
	}
	struct iterator* student_i = list_begin(grades->list);
	while (student_i!=NULL){
		student_printer(student_i);
		student_i=list_next(student_i);
	}
	return 0;
}
void destroy_student (void *elem){
	free(((struct student*)elem)->name);
	list_destroy((((struct student*)elem)->course_list));
	free(elem);
}
void destroy_course (void *elem){
	free(((struct course*)elem)->course_name);
	free(elem);
}
int clone_student (void *elem, void **output){
	struct student *student;
	student=(struct student*)malloc(sizeof(*student));
	if(!student){
		return FAIL;
	}
	*output=student;
	/*((struct student*)*output)->name=
		(char*)malloc((strlen(((struct student*)elem)->name)+1)*sizeof(char));*/
	//((struct student*)*output)->prev=((struct student*)elem)->prev;
	//((struct student*)*output)->next=((struct student*)elem)->next;
	((struct student*)*output)->name=((struct student*)elem)->name;
	((struct student*)*output)->id=((struct student*)elem)->id;
	((struct student*)*output)->course_list=
			((struct student*)elem)->course_list;
	return 0;
}
int clone_course (void *elem, void **output){
	struct course *course;
	course=(struct course*)malloc(sizeof(*course));
	if(!course){
		return FAIL;
	}
	*output=course;
/*	((struct course*)*output)->course_name=
		(char*)malloc((strlen((((struct course*)elem))->course_name)+1)*sizeof(char));*/
	//((struct course*)*output)->next=((struct course*)elem)->next;
	//((struct course*)*output)->prev=((struct course*)elem)->prev;
	((struct course*)*output)->course_name=
			((struct course*)elem)->course_name;
	((struct course*)*output)->grade=((struct course*)elem)->grade;
	return 0;
}


//    return 0;
//}
