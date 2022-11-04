system p1;
system p2;

typedef features {
	bool B1;
	bool B2
}

features f;

byte i;

active proctype foo() {
	
	p1.f.B1 = true;
	p2.f.B2 = true;
	
	if :: f.B1 -> i = 2; :: else -> skip; fi;
	if :: f.B2 -> i = 1; :: else -> skip; fi;
	
	assert(p1.i > p2.i);
}

