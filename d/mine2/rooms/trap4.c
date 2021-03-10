#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
        ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine trap 4");
    set_long(""
"%^RED%^ "
"You are in a room, with no way out at all.  There is a miror in the corner"
"of the room.  You would have to climb out of this room."
""
""
"");

     set_listen("default","You hear northing.");
     set_smell("default","You smell nothing.");

      set_climb_exits(([
"climb":({"d/mine2/rooms/mine26",2,30,300}),
]));

    set_items(([
         "cavern" : "It is just a normal mine shaft, with no way out.",
         "room" : "There is no way out!",
         "top" : "There is nothing ot grab onto.",
         "shaft" : "There is a mirror in the room.",
         "miror" : "If you stare hard enough, you can get out.",
         "ground" : "It is jut plain.",
         "ground" : "It is covered with corpses.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
void init()
{
  ::init();
write("%^BOLD%^WHITE%^As you enter the room, a bright light makes it so you can not see, and you trip, and fall down a long shaft.");
say("Someone joins you.");
}



