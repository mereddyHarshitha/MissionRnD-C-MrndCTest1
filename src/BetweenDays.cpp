/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	
	if (date1head == NULL && date2head == NULL)
		return -1;
	int day1[2], month1[2], year1[4];

	struct node *ptr = date1head;
	day1[0] = ptr->data;
	ptr = ptr->next;
	day1[1] = ptr->data;
	ptr = ptr->next;
	month1[0] = ptr->data;
	ptr = ptr->next;
	month1[1] = ptr->data;
	ptr = ptr->next;
	year1[0] = ptr->data;
	ptr = ptr->next;
	year1[1] = ptr->data;
	ptr = ptr->next;
	year1[2] = ptr->data;
	ptr = ptr->next;
	year1[3] = ptr->data;
	ptr = ptr->next;

	int day2[2], month2[2], year2[4];

	struct node *ptr1 = date2head;
	day2[0] = ptr1->data;
	ptr1 = ptr1->next;
	day2[1] = ptr1->data;
	ptr1 = ptr1->next;
	month2[0] = ptr1->data;
	ptr1 = ptr1->next;
	month2[1] = ptr1->data;
	ptr1 = ptr1->next;
	year2[0] = ptr1->data;
	ptr1 = ptr1->next;
	year2[1] = ptr1->data;
	ptr1 = ptr1->next;
	year2[2] = ptr1->data;
	ptr1 = ptr1->next;
	year2[3] = ptr1->data;
	ptr1 = ptr1->next;

	int d,days,d1,d2;
	d = year2 - year1;
	if (d != 0)
		days = d * 365;
	d1 = month2 - month1;
	if (d1 != 0)
		days =days+ d1 * 30;
	d2 = day2 - day1;
	days = days + d2;

	return days;
}