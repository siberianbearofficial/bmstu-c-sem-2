#include "main.h"

int main(int argc, char **argv)
{
	FILE *fin;
	FILE *fout;
	if ((fin = fopen(argv[1], "r")) && (fout = fopen(argv[2], "w")))
	{
		struct Contact contacts[MAX_CONTACTS];
		int n;
		if (!get_contacts_from_file(fin, contacts, &n))
		{
			sort_contacts(contacts, n);
			put_contacts_into_file(fout, contacts, n);
		}
	}
	return EXIT_SUCCESS;
}
