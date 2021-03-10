// added path to lead to new Antipal. hall after discussing with Grendel.  *Styx*  12/5/02

#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no sneak", 1);
    set_room_type("gate");
    set_short("Northwestern gates of Tonovi");
    set_long(
   "Here at the northwestern gates you can see that they have been opened and closed a lot, and actually look a lot stronger than the main gates.  You can see openings into the walls of the city to the southwest and northeast, and to the southeast of you is one of the roads that travel around the city.\n"
    "There is a heavy door in the wall to the north that is blocked open.  It leads to a path along the outside of the walls."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"gate" : "This great iron gate is built incredibly strong.  It is currently closed, blocking the road to the Duke's keep.",
	"walls" : "These sturdy walls ring most of the city, protecting it from invasion.",
      ]) );
    set_exits( ([
	"northeast" : RPATH "wall16",
	"southwest" : RPATH "wall15",
	"southeast" : RPATH "street21",
        "north" : "/d/dagger/tonovi/antipath1"
//	"northwest" : RPATH "keep/road1",
      ]) );
    set_pre_exit_functions( ({"northwest"}), ({"no_go"}) );
}

int no_go(){
    tell_object(TP, "You try to walk through the gate, and bang your head into it painfully.");
    tell_room(ETP, TPQCN+" tries to walk through the gate, and doesn't make it very far.", ({TP}));
    TP->do_damage("head", 1);
    return 0;
}

void init(){
    ::init();
    add_action("sneak", "sneak");
}

int sneak(string str){
    tell_object(TP, "You try to sneak through the gate, and bang your head into it painfully.");
    tell_room(ETP, TPQCN+" tries to sneak through the gate, and doesn't make it very far.", ({TP}));
    TP->do_damage("head", 1);
    return 1;
}
