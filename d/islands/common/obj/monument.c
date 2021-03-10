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
	
	set_name("monument");
	set_id(({"monument","onyx monument"}));
       set_short("%^BOLD%^%^BLUE%^Onyx monument");
        set_long("
    This is a large monument that rises to a height of about twelve feet, then slopes to a single point.  It bears the symbol of the Kinnesaruda Empire.  A sundial-like bronze disk is set into the center of the monument and a plaque is just beneath it.

");
	set_weight(100000);
	set_value(10000);
	}
	
int read(string str){
	if(!str || str != "plaque") return  0;
	
       tell_room(environment(TO),TPQCN+" reads the the plaque.",TP);
    write("\n\n\%^BOLD%^%^YELLOW%^Against the way of time, speak the names of the warriors of the light. \n""%^RESET%^The Dominion Warrior sleeps...\n");
	return 1;
	}
	
