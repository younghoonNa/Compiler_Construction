enum code_ops { HALT, STORE, JMP_FALSE, GOTO, 
	DATA, LD_INT, LD_VAR,
	READ_INT, WRITE_INT,
	LT, EQ, GT, ADD, SUB, MULT, DIV, PWR, MOD};

char *op_name[] = {"halt", "store", "jmp_false", "goto",
			"data", "ld_int", "ld_var",
		"read_int", "write_int",
		"lt", "eq", "gt", "add", "sub", "mult", "div", "pwr", "mod" };

struct instruction {
	enum code_ops op;
	int arg;
};

struct instruction code[999];
int stack[999];

int pc = 0;
struct instruction ir;
int ar = 0;
int top = 0;

void fetch_execute_cycle() {
	do {
	/* Fetch */
	//printf("code pc : %u\n", code[pc].op);
	ir = code[pc++];
	//printf(" ir op : %u\n", ir.op);
	/* Execute */
	switch(ir.op) {
	case HALT:		printf( "\nhalt\n" ); break;
	case READ_INT: 		printf( "Input: ");
				scanf("%id", &stack[ar+ir.arg]);
				//printf("READ INT\n");
				break;
	case WRITE_INT: 	printf(" OUTPUT : %d\n", stack[top--]); break;
	case STORE: 		stack[ir.arg] = stack[top--]; break;
	case JMP_FALSE:		if (stack[top--] == 0)
				pc = ir.arg; break;
	case GOTO:		pc = ir.arg; break;
	case DATA: 		top = top + ir.arg;
				//printf("DATA PRINT\n");
				break;
	case LD_INT:		stack[++top] = ir.arg; break;
	case LD_VAR:		stack[++top] = stack[ar+ir.arg]; break;
	case LT:		if (stack[top-1] < stack[top] )
				stack[--top] = 1;
				else
				stack[--top] = 0;
				break;
	case EQ:		if (stack[top-1] == stack[top])
				stack[--top] = 1;
				else
				stack[--top] = 0;
	case GT:		if (stack[top-1] > stack[top])
				stack[--top] = 1;
				else
				stack[--top] = 0;
				break;
	case ADD:		stack[top-1] = stack[top-1] + stack[top];
				top--;
				break;
	case SUB:		stack[top-1] = stack[top-1] - stack[top];
				top--;
				break;
	case MULT:		stack[top-1] = stack[top-1] * stack[top];
				top--;
				break;
	case DIV:		stack[top-1] = stack[top-1] / stack[top];
				top--;
				break;
	case PWR:		stack[top-1] = stack[top-1] ^ stack[top];
				top--;
				break;
	case MOD:		stack[top-1] = stack[top-1] % stack[top];
				top--;
				break;
	default: 		printf( "Internal Error : Memory Dump\n");
				break;

		}
	} while (ir.op != HALT);

}
