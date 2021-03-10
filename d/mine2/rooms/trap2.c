#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine trap 2");
    set_long(""
"%^BOLD%^BLUE%^ "
"You are a room that is filled with water.  There is hardly any air for you to breathe, " 
"and you may soon die from the lack of air.  As you can tell, there are no exits at all.  "
"But who knows, there maybe a way out.  "
""
"");

     set_listen("default","You hear water.");
     set_smell("default","You smell fish.");

        set_climb_exits(([
             "dive":({"d/mine2/rooms/mine16",56,20,300}),
]));


    set_items(([
         "cavern" : "It is a filled with water.",
         "water" : "It is fills the room.",
         "fish" : "They are coming in and out of a small hole.",
         "shaft" : "It is filled with water.",
         "hole" : "If you could hold your breathe for long enough, you could swim out of it.",
         "room" : "It is filled with water.",
         "ground" : "It is covered with water.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
void init()
{
  ::init();
write("%^BOLD%^CYAN%^When you take your first step into the room, you step in what you thought was just a little puddle of water.  When you start to get sucked into it, you know you are in trouble.");
say("Someone joins you.");
}



