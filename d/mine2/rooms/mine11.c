
#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
           ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("A mine shaft");
    set_long(""
"%^BOLD%^ORANGE%^ "
"This shaft is very cold and stuffy.  There are several little pieces of " 
"chiped rock on the ground.  There are little pieces of gold on the ground "
"but you do not get them because of how little money they are worth.  There is "
"a broken pick on the ground, that is in about 100 pieces, probably from a miner "
"who became depressed over not getting anything.");

     set_listen("default","You hear the rumbling of a rock slide.");
     set_smell("default","You smell something odd.");
    set_exits(([
       "down" : "/d/mine2/rooms/mine24",
        "west" : "/d/mine2/rooms/mine10",
    ] ));
    set_items(([
         "cavern" : "It is farly small, and is very stuffy.",
         "pick" : "It looks like an angry miner through it down onto the ground breaking it into 100 pieces.",
         "marks" : "The marks are from picks  from earlier tried to get gold.",
         "shaft" : "It is accually a small cavern, that is very stuffy and cold.",
         "gold" : "There are little gold pieces in here, but it's not worth it to take the time to get them.",
         "rock" : "There is several pieces of chiped rock on the ground.",
         "ground" : "It is covered with chiped rock.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
