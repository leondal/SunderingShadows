
#include <std.h>
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
 ::create();
  set_indoors(0);
  set_property("no teleport",1);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);
  set_light(2);
  set_short("A run down old dock");
 set_long(
@GRAYHAWK
%^YELLOW%^Seafang Harbor%^RESET%^
This is a very old and decayed dock.  The dock is about 20 feet long
and hangs over the greenish, reeking sea.  At the end of the dock
is a very strange object, maybe its a horn.  You notice that there
is a thick grayish fog hanging over the water about 40 feet toward
the east.  
There is a %^RED%^warning%^RESET%^ here you should read.
GRAYHAWK
);
set_exits(([
"southwest":"/d/deku/forest/dforest2-5",
]));

set_pre_exit_functions(({"southwest"}),({"GoThroughDoor"}));

set_smell("default","You smell the salty ocean air carrying across this dangerous land.");
find_object_or_load("d/shadow/virtual/sea/obj/ferryboat2")->move(TO);
set_listen("default","You hear the sounds of waves crashing against the sandy beaches."); 
}


int __Read_me(string str) {
    if(str == "warning") {
    write(
@SAIDE

%^B_CYAN%^%^YELLOW%^READ CAREFULLY 

This is meant to be a warning of the danger on the island.
Those under level 10 are no longer permitted to enter.
The island is meant for those 10+ and offers good 
rewards and difficult challenges for those of that
level.
SAIDE
);
    return 1;
    }
    return ::__Read_me(str);
}

void init() {
    ::init();
    add_action("__Read_me","read");
}

int GoThroughDoor() {
    if(TP->query_highest_level() < 10) {
        //"/cmds/avatar/_note.c"->format_checkpoint(TP,"%^B_CYAN%^%^YELLOW%^Tried to enter Deku despite the warning on "+ctime(time())+".%^RESET%^\n");
        tell_object(TP,"%^B_CYAN%^%^YELLOW%^You are unable "+
        "to enter the island of deku at this level.  Read "+
        "the %^RESET%^%^RED%^warning%^B_CYAN%^%^YELLOW%^ if you "+
        "haven't already!%^RESET%^");
        return 0;
    }
    return 1;
}
