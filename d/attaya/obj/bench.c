#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("sit","sit");
}

void create(){
    ::create();

    set_name("Bench");
    set_id(({"bench","marble bench"}));
    set_short("Marble bench");
    set_long(
      "It is a smooth marble bench that looks quite appealing after a lon day on your feet."
    );
    set_weight(100000);
    set_value(10000);
}
int sit(string str){
    if (!str){
	write("Sit where?\n");
	return(1);
    }
    if (str=="bench" || str=="on bench"){
	write(
	  "%^BOLD%^You sit down on the bench and relax."
	);
	tell_room(TO,"" +TPQCN+" sits down on the bench.",TP);
	return (1);
    }
    return (0);
}
