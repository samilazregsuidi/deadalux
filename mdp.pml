bool s0a0 = true;
bool s0a1 = true;
bool s1a0 = true;
bool s1a1 = true;
bool s2a0 = true;
bool s2a1 = true;

int s = 0;

active proctype mdp(){
	
	
	do
	:: s == 0 -> 
		if
		:: s0a0 -> 
			if
			:: s = 0;
			:: s = 2;
			fi;
			
		:: s0a1 -> s = 2;
		fi;
	
	:: s == 2 ->
		if
		:: s2a0 -> 
			if
			:: [ 0.4 ] s = 0;
			:: [ 0.6 ] s = 2;
			fi;
			
		:: s2a1 ->
			if
			:: [ 0.4 ] s = 2;
			:: [ 0.3 ] s = 0;
			:: [ 0.3 ] s = 1;
			fi;
		fi;
		
	:: s == 1 -> 
		if 
		:: s1a0 ->
			if 
			:: [ 0.1 ] s = 1;
			:: [ 0.7 ] s = 0;
			:: [ 0.2 ] s = 2;
			fi;
			
		:: s1a1 ->
			if 
			:: [ 0.95 ] s = 1;
			:: [ 0.05 ] s = 2;
			fi;
		fi;
	od;
}

bltl prop0 {
	[] {k > 10} (s == 1)
}
