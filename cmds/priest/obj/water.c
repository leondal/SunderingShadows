// Revised by Pator@ShadowGate
#include <std.h>

inherit "/d/magic/obj/mirror.c";

int drinks;
int set_drinks(int i);

void create() {
    ::create();
    set_id( ({ "water", "pool" , "pool of water", "mirror" }) );
    set_name("water");
    set_short("A pool of clear water");
    set_long( "A pool of clear water. Looks like it is drinkable and highly reflective.");
    set_drinks(random(20));
    set_property("no animate",1);
    set_property("no offer",1);
}


int set_drinks(int i) {
    if ( i < 5  ) i = 5;
    if ( i > 20 ) i = 20;
    drinks = i;
    drinks *= 3;
    return 1;
}

void init(){
    ::init();
	add_action("drink_some","drink");
}

int drink_some(string str){
    if((!str) || (str != "water from pool"))
	return notify_fail("Syntax: <drink water from pool>\n");
    else
        if(!TP->add_quenched(50)) return notify_fail("You are already quenched!\n");
	write("You take a large drink from the pool.");
	drinks --;
	if(drinks < 1) remove();
    return 1;

}
