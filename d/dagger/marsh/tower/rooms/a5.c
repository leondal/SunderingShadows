#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
int FLAG;
void init() {
    ::init();
    add_action("grab_fun","get");
}
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and cramped chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. Old rusted torch brackets hang broken "
	"from the walls. Cobwebs fill the chamber, as though nothing has entered "
	"this area of the tower for years. A %^BLUE%^pedestal%^RED%^ sits "
	"in the center of the room. No dust or cobwebs gather upon the pedestal. "
	"A small %^GREEN%^jade figurine%^RED%^ sits perched atop the pedestal."
	"%^RESET%^" 
    );
    set_short("%^RED%^Cramped Chamber%^RESET%^");
    set_listen("default",
        "It is dead silent, as though sound itself fears to roam here."
    );
    set_smell("default",
        "The smell of age and decay permeates the chamber."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"brackets":"%^ORANGE%^The brackets hang broken from the walls.",
	"cobwebs":"The cobwebs cover the ceiling and the walls of the chamber.",
	"pedestal":"A small figurine sits on top of the pedestal.",
	"figurine":"The figurine appears to resemble the twisted and contorted "
	"body of a humanoid in great anguish or pain.",
    ]));
    set_exits(([
        "east": RPATH "a6",
        "southeast": RPATH "a2",
    ]));

    set_pre_exit_functions(({"east"}),({"exitb_fun"}));
    set_pre_exit_functions(({"southeast"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("reaver")) {
        write("The reaver blocks your way!");
        return 0;
    }
    write("%^GREEN%^As you head to the southeast, you hear a faint *click* beneath "
	"your feet.%^RESET%^"
    );
    return 1;
}
int exitb_fun() {
    if(present("reaver")) {
        write("The reaver blocks your way!");
        return 0;
    }
    if(FLAG == 0) {
        write(
	    "%^BOLD%^%^BLUE%^A shadow leaps from the wall and runs to the east!%^RESET%^");
        say(
	    "%^BOLD%^%^BLUE%^"+TPQCN+
	    " looks startled and heads quickly east.%^RESET%^"
	,TP);
        return 1;
    } else {
	return 1;
    }
}
void reset() {
    ::reset();
    FLAG = 0;
}
int grab_fun(string str) {
    if(!str) {
	notify_fail("Get what?\n");
        return 0;
    }
    if(str != "figurine") {
	notify_fail("Get what?\n");
        return 0;
    }
    if(FLAG != 0) {
        notify_fail("Your hand passes through the figurine!\n");
        return 0;
    }
    write("%^GREEN%^You grab the figurine!%^RESET%^");
    say("%^GREEN%^You get a bad feeling as "+TPQCN+ " grabs the figurine "
	"from the pedestal.%^RESET%^"
    ,TP);
    new( OPATH "figurin1.c" )->move(TP);
    call_out("stalker",10);
    FLAG = 1;
    return 1;
}
int stalker() {
    new( MPATH "stalker.c" )->move(TO);
    write("%^BLUE%^The shadows seem to stir.%^RESET%^");
    say("%^BLUE%^The shadows seem to stir.%^RESET%^",TP);
}
