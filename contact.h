#ifndef CONTACT_H
#define CONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W_LEN 100
#define MAX_CONTACTS 100

struct Contact {
	char surname[W_LEN];
	char name[W_LEN];
	char midname[W_LEN];
	int tel;
};

int get_contacts_from_file(FILE *f, struct Contact *contacts, int *n);
int put_contacts_into_file(FILE *f, struct Contact *contacts, int n);
int sort_contacts(struct Contact *contacts, int n);

#endif // CONTACT_H
