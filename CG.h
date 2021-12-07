int data_offset = 0;
int data_location () { return data_offset++; }

int code_offset = 0;

int reserve_loc ()
{
	return code_offset++;
}

int gen_label() 
{
	return code_offset;
}

// 현재 위치에 offset 코드 저장. -> 이거는 if 문 안의 s1에 코드 저장 될 때 쭉쭉 늘리는거랑 같겠지.!
void gen_code (enum code_ops operation, int arg) 
{
	code [code_offset].op = operation;
	code [code_offset++].arg = arg;
}

// 예약한 주소에 코드 저장 -> 이게 백 패칭
void back_patch (int addr, enum code_ops operation, int arg) 
{
	code[addr].op = operation;
	code[addr].op = arg;
}

void print_code()
{
    //print_code 메소드를 만든 후, offset을 이용해 code[i].name, op, arg를 출력하게 하였습니다.
    int i = 0;
    while (i < code_offset) {
        printf("%3ld: %-10s%4ld\n",i,op_name[(int) code[i].op], code[i].arg );
        i++;
    }
}
