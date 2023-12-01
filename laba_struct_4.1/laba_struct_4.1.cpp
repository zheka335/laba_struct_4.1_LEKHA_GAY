#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef struct list
{
	char field;
	list* pNext;
	list* pPrev;
};


void list_function();
void menu(list*&, list*&, list*&);//переделать
void print_list(list*&, list*&, list*&);//переделать
void add_elem_front(list*&, list*&, list*&);//раздвоить и переделать
void check_work_pointer(list*&, list*&);//проверяет в конце ли списка рабочий указатель
void move_wp_to_head(list*&, list*&);//
void move_wp_front(list*&);//раздвоить

void removeAt_front(list*&);//раздвоить, и переделать
void clear(list*&, list*&);//
void check_on_clear(list*&);//
void print_value_front(list*&);//раздвоить
list* get_elem_front(list*&);//раздвоить
void change_value_front(list*&);//раздвоить


int main()
{
	list_function();
}


void list_function()
{
	char c;
	list* head = (list*)malloc(sizeof(list));
	//printf("Enter thr character: ");
	//while ((c = getchar()) == '\n') {};
	//head->field = c;

	head->pNext = nullptr;
	head->pPrev = nullptr;
	list* tail = head;
	list* work_ptr = head;
	list*& ref_head = head;
	list*& ref_work = work_ptr;
	list*& ref_tail = tail;
	


	menu(ref_head, ref_work, ref_tail);

	print_list(ref_head, ref_work,ref_tail);
}

void menu(list*& ref_head, list*& ref_work, list*& ref_tail)
{
	int i, flag_on_start = 0, flag_on_finish = 0;

	while (1)
	{
		printf(("\n1. Start working with the list\n2. Clear the list\n3. Check the list for emptiness\n4. Move the work pointer to the head of the list\n"
			"5. Check work pointer in the tail\n6. Move work pointer to the right\n7. Print the value of the element, which located after work pointer\n"
			"8. Remove the elemet, which located after work pointer\n9. Get element, which located after work pointer\n"
			"10. Chenge the value of element, which located after work pointer\n11. Add the element after work pointer\n"
			"12. Print the list\n13. Finish working with list\n14. Finish the programm\n"));

		printf("\nEnter the number of function that you want to start: ");
		scanf("%d", &i);

		switch (i)
		{
		case(1):
		{
			char c = 0;
			if (flag_on_start) printf("\nWork with the list has already started\n");
			flag_on_start = 1;
			printf("Enter the chararcter: ");
			while ((c = getchar()) == '\n');
			ref_head->field = c;
			break;
		}
		case(2):
		{
			if (flag_on_start)clear(ref_head, ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(3):
		{
			if (flag_on_start)check_on_clear(ref_head);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(4):
		{
			if (flag_on_start)move_wp_to_head(ref_head, ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(5):
		{
			if (flag_on_start)check_work_pointer(ref_work, ref_tail);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(6):
		{
			if (flag_on_start)move_wp_front(ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(7):
		{
			if (flag_on_start)print_value_front(ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(8):
		{
			if (flag_on_start)removeAt_front(ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(9):
		{
			if (flag_on_start)get_elem_front(ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(10):
		{
			if (flag_on_start)change_value_front(ref_work);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(11):
		{
			if (flag_on_start)add_elem_front(ref_head, ref_work, ref_tail);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(12):
		{
			if (flag_on_start)print_list(ref_head, ref_work, ref_tail);
			else printf("\nStart working with list (press 1)!\n");
			break;
		}
		case(13):
		{
			flag_on_start = 0;
			break;
		}
		case(14):
		{
			if (!flag_on_start) flag_on_finish = 1;
			else printf("\nFinish working with the list (press 13)!\n");
		}
		}

		if (flag_on_finish)break;

	}
}

void print_list(list*& ref_head, list*& ref_work, list*& ref_tail)

{
	list* ptr_head = ref_head;
	list* ptr_tail = ref_tail;

	printf("\n");
	if (ptr_head->pNext == nullptr && ptr_head->field == 0) check_on_clear(ref_head);
	else {
		while (ptr_head != nullptr)
		{
			printf("%c  ", ptr_head->field);
			ptr_head = ptr_head->pNext;
		}
		printf("\n");

		while (ptr_tail != nullptr)
		{
			printf("%c  ", ptr_tail->field);
			ptr_tail = ptr_tail->pPrev;
		}
		printf("\n");
	}
	printf("P.Y - %c", ref_work->field);
}

void add_elem_front(list*& ref_head, list*& ref_work, list*& ref_tail)
{
	char c;
	if (ref_head == ref_tail)
	{
		list* temp_ptr = (list*)malloc(sizeof(list));

		printf("Enter the character: ");
		while ((c = getchar()) == '\n') {};
		temp_ptr->field = c;

		temp_ptr->pPrev = ref_work;//
		ref_work->pNext = temp_ptr;
		ref_tail = ref_work->pNext;
		ref_tail->pNext = nullptr;
	}
	else
	{
		if (ref_work == ref_tail)
		{
			list* temp_ptr = (list*)malloc(sizeof(list));

			printf("Enter the number: ");
			while ((c = getchar()) == '\n') {};
			temp_ptr->field = c;

			temp_ptr->pPrev = ref_work;//
			ref_work->pNext = temp_ptr;
			ref_tail = temp_ptr;
			temp_ptr->pNext = nullptr;
		}
		else
		{
			list* temp_ptr = (list*)malloc(sizeof(list));

			printf("Enter the character: ");
			while ((c = getchar()) == '\n') {};
			temp_ptr->field = c;

			temp_ptr->pPrev = ref_work;
			temp_ptr->pNext = ref_work->pNext;
			ref_work->pNext->pPrev = temp_ptr;
			ref_work->pNext = temp_ptr;

		}
	}
}

void check_work_pointer(list*& ref_work, list*& ref_tail)
{
	if (ref_work == ref_tail)
	{
		printf("\nThe work pointer is at the end of the list\n");
	}
	else
	{
		printf("\nThe work pointer isn`t at the end of the list\n");
	}
}

void move_wp_front(list*& ref_work)
{
	if (ref_work->pNext == nullptr)
	{
		printf("\nWork pointer is indicating on tail of list\n");
	}
	else
	{
		ref_work = ref_work->pNext;
	}
}

void move_wp_to_head(list*& ref_head, list*& ref_work)
{
	ref_work = ref_head;
}

void removeAt_front(list*& ref_work)
{
	list* temp_ptr = (list*)malloc(sizeof(list));
	temp_ptr = ref_work->pNext;
	if (ref_work->pNext != nullptr)
	{
		ref_work->pNext->pNext->pPrev = ref_work;
		ref_work->pNext = ref_work->pNext->pNext;
		free(temp_ptr);
		
	}
	else
	{
		printf("work pointer is indicating on tail of list\n");
	}
}

void clear(list*& ref_head, list*& ref_work)
{
	move_wp_to_head(ref_head, ref_work);
	while (ref_head->pNext != nullptr)
	{
		removeAt_front(ref_work);
	}
	ref_head->field = 0;
}

void check_on_clear(list*& ref_head)
{
	list* temp_ptr = ref_head;
	int flag = 0;
	if (temp_ptr->pNext == nullptr && temp_ptr->field == 0)printf("\nThe list is empty\n");
	else
	{
		printf("\nThe list isn`t empty\n");
	}
}

void print_value_front(list*& ref_work)
{
	if (ref_work->pNext != nullptr)
	{
		printf("\nThe value - %c\n", ref_work->pNext->field);
	}
	else
	{
		printf("\nThe work pointer is indicating on tail of list\n");
	}
}

list* get_elem_front(list*& ref_work)//оттестить
{
	list* temp_ptr = (list*)malloc(sizeof(list));
	if (ref_work->pNext != nullptr)
	{
		printf("\nThe element is taken\n");
		temp_ptr = ref_work->pNext;
		printf("its value - %c\n", temp_ptr->field);
		removeAt_front(ref_work);
		return(temp_ptr);
	}
	else
	{
		printf("The work pointer is indicating on the tail of the list\n");
	}
}

void change_value_front(list*& ref_work)
{
	char c = 10;
	if (ref_work->pNext != nullptr)
	{
		printf("Enter the character: ");
		while ((c = getchar()) == '\n') {}
		ref_work->pNext->field = c;
	}
	else
	{
		printf("\nThe work pointer is indicating on the tail of the list\n");
	}
}