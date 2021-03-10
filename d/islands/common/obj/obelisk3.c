//tstatue.c

#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
	::init();
	add_action("read","read");
	}
	
void create(){
	::create();
	
	set_name("obelisk");
	set_id(({"obelisk","onyx obelisk"}));
       set_short("%^BOLD%^%^BLUE%^Onyx obelisk");
        set_long("
    A towering 100 foot tall obelisk stands here.  It is completely smooth and forged of onyx.
    There is some writing the face nearest you.

");
	set_weight(100000);
	set_value(10000);
	}
	
int read(string str){
	if(!str || str != "obelisk") return  0;
	
       tell_room(environment(TO),TPQCN+" reads the writing on the obelisk face.",TP);
    write("\n\n\%^BOLD%^%^BLUE%^Beyond the sea and the lord, ancient demon of air and darkness is the southern point of light.\n\n");
	return 1;
	}
	
