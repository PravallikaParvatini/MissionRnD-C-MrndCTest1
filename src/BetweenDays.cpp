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
	int days=0,d1, m1, y1, d2, m2, y2, i, dim[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	if (date1head == NULL || date2head == NULL)
		return -1;
	d1 = date1head->data * 10+date1head->next->data;
	date1head = date1head->next->next;
	d2 = date2head->data * 10+date2head->next->data;
	date2head = date2head->next->next;
	m1 =date1head->data * 10 + date1head->next->data;
	date1head = date1head->next->next;
	m2 = date2head->data * 10 + date2head->next->data;
	date2head = date2head->next->next;
	y1 = date1head->data * 1000 + (date1head->next->data*100);
	date1head = date1head->next->next;
	y1 = y1 + date1head->data * 10 + (date1head->next->data);
	y2 = date2head->data * 1000 + (date2head->next->data * 100);
	date2head = date2head->next->next;
	y2 = y2 + date2head->data * 10 + (date2head->next->data);
	if (d1 <= 0 || d1 > 31 || d2 <= 0 || d2 > 31)
		return -1;
	if (m1 <= 0 || m1 > 12 || m2 <= 0 || m2 > 12)
		return -1;
	if (y1 == y2&&m1 == m2 && (d1 == d2 || d2 == d1 + 1 || d1 == d2 + 1))
		return -1;
	if (y1 == y2)
	{
		if (m1 == m2)
			days = d2 - d1 - 1;
		else
		{
			days = dim[m1 - 1] - d1 +d2 - 1;
		}
	}
	else
	{
		days = y2 - y1 * 365;
		days = days - (m1 - m2) * 30;
	}
	return days;
}