#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine trap 1");
    set_long(""
"%^RED%^ "
"You are in a deep hole, that apears to have no way out.  " 
"As you look around, you notice that the rocks on the side of the wall "
"are strangly pointed.  "
"Other than that, this room looks like it will be the death of you!"
"");

     set_listen("default","You hear hear air rushing out, making it hard to breathe.");
     set_smell("default","You smell rotting corpses.");
   set_exits(([
"hole" : "/d/shadow/room/grassland/grass18",
]));
  set_invis_exits( ({"hole"}) );
    set_items(([
         "cavern" : "It is a large hole.",
         "corpse" : "It is the corpse of an earlier victim.",
         "corpses" : "They are all over the gorund.",
         "shaft" : "It is you barial room.",
         "walls" : "They are covered with straqnge rocks.",
"rocks" : "The rocks cover the room, except for one spot where there is a hole.",
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
write("%^BOLD%^RED%^As you enter the room, you slip on a small rock, and slid into a small hole.  You start to slide down a slide type shaft, and then fall onto the floor with a loud %^FLASH%^THUD%^RESET%^BOLD%^RED%^!");
say("Someone joins you.");
}



