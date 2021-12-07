extern data_location();

struct symrec {
	char *name; /* name of symbol */
	int offset; /* data offset */
	struct symrec *next; /*link field */
};

typedef struct symrec symRec;
symRec *sym_table = (symRec *) 0;

symRec *putsym(char *sym_name) {
	symRec *ptr;
	ptr = (symRec *) malloc (sizeof(symRec));
	ptr->name = (char *) malloc (strlen(sym_name)+1);
	
	strcpy(ptr->name, sym_name);

	ptr->offset = data_location();

	ptr->next = (symRec *) sym_table;
	sym_table = ptr;

	return ptr;
}

symRec *getsym (char *sym_name) {
	symRec *ptr;
	
	for(ptr = sym_table; ptr!= (symRec *) 0; ptr = (symRec *) ptr->next) {
		if(strcmp(ptr->name, sym_name) ==0) 
			return ptr;
	}
	
	return 0;
}


