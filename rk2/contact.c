#include "contact.h"

int get_contacts_from_file(FILE *f, struct Contact *contacts, int *n)
{
	int exit_code = EXIT_SUCCESS;
	
	char surname[W_LEN];
	char name[W_LEN];
	char midname[W_LEN];
	int tel;
	
	for (*n = 0; *n < MAX_CONTACTS && fscanf(f, "%s%s%s%d", (char *) &surname, (char *) &name, (char *) &midname, &tel) > 0 && !exit_code; (*n)++)
	{
		struct Contact contact;
		strcpy(contact.surname, surname);
		strcpy(contact.name, name);
		strcpy(contact.midname, midname);
		contact.tel = tel;
		
		contacts[*n] = contact;
	}
	
	return EXIT_SUCCESS;
}

int put_contacts_into_file(FILE *f, struct Contact *contacts, int n)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%s\n%s\n%s\n%d\n", contacts[i].surname, contacts[i].name, contacts[i].midname, contacts[i].tel);
	}
	return EXIT_SUCCESS;
}

int swap(struct Contact *c1, struct Contact *c2)
{
	
	return EXIT_SUCCESS;
}

int sort_contacts(struct Contact *contacts, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int key = strcmp(contacts[i].surname, contacts[j].surname);
			if (key > 0)
				swap(&contacts[i], &contacts[j]);
		}
	}
	return EXIT_SUCCESS;
}
