#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
int FLAG;
void init() {
    ::init();
    add_action("insert_fun","insert");
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
	"in the center of the room. No dust or cobwebs gather upon the %^BLUE%^pedestal%^RED%^. "
	"A small %^GREEN%^depression%^RED%^ is located on the top side of the %^BLUE%^pedastal%^RED%^."
	"%^RESET%^" 
    );
    set_short("%^RED%^Cramped Chamber%^RESET%^");
    set_listen("default",
        "It is silent, yet the silence is filled with cosmic sounds."
    );
    set_smell("default",
        "The smell of ancient decay surrounds you."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"brackets":"%^ORANGE%^The brackets hang broken from the walls.",
	"cobwebs":"The cobwebs cover the ceiling and the walls of the chamber.",
	"pedestal":"The pedestal is small and plain looking. A small depression is located "
	"within the top side of it.",
	"depression":"The depression looks as though a gem or a jewel or a stone could be inserted into it.",
    ]));
    set_exits(([
        "west": RPATH "e3",
    ]));

}
int insert_fun(string str) {
    object GEM;
    if(!str) {
	notify_fail("Insert what into what?\n");
	return 0;
    }
    if(str != "gem into depression") {
 	notify_fail("Insert what into what?\n");
	return 0;
    }
    if(!present("gem",TP)) {
	notify_fail("You don't have a gem to insert!\n");
	return 0;
    }
    if(!(GEM = present("demongem5",TP))) {
	notify_fail("That gem does not fit into the depression!\n");
	return 0;
    }
    if(FLAG == 1) {
	notify_fail("The portal is already open!\n");
	return 0;
    }
    write(
	"%^RED%^You insert the demongem into the depression!\nA slow rumble fills the chamber!\n"
	"%^BLUE%^A portal appears!%^RESET%^"
    );
    say(
	"%^RED%^"+TPQCN+" inserts a gem into the depression!\nA slow rumble fills the chamber!\n"
	"%^BLUE%^A portal appears!%^RESET%^"
    ,TP);
    GEM->remove();
    TO->add_exit( RPATH "e12","portal");
    FLAG = 1;
    return 1;
}
void reset() {
    if(FLAG == 1) {
	FLAG = 0;
        set_exits(([
            "west": RPATH "e3",
        ]));
    }
}
		