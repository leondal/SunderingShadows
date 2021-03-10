#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("sit","sit");
}

void create(){
    ::create();

    set_name("chair");
    set_id(({"chair","leather chair"}));
    set_short("Leather backed chair");
    set_long(
      "A sturdy stained black walnut chair with leather cushions and back.  The ends of the armrests look like the heads of dragons."
    );
    set_weight(450);
    set_value(100);
}
int sit(string str){
    if (!str){
	write("Sit where?\n");
	return(1);
    }
    if (str=="chair" || str=="on chair"){
	write(
	  "%^BOLD%^You sit down on the leather backed chair and lean back."
	);
	tell_room(TO,"" +TPQCN+" sits down on the leather backed chair and leans back.",TP);
	return (1);
    }
    return (0);
}
