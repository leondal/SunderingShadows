#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
         ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine trap 5");
    set_long(""
"%^WHITE%^ "
"You are in loged in a small hole.  As you try to wiggle, you become loged more "
"solidly.  There is a little stream running down the hole."
"  If you had enough strength, you could climb."
""
"");

     set_listen("default","You hear water rushing by your head.");
     set_smell("default","You smell fresh water.");

        set_climb_exits(([
              "climb":({"d/mine2/rooms/mine16",3,20,300}),

]));


    set_items(([
         "hole" : "It is a large hole.",
         "water" : "It is very cold!",
         "stream" : "It is creating force, and maybe if you hold your breath, it will create enough force to push you out!",
         "cold" : "It is cold.",
         "walls" : "They are wet.",
         "rocks" : "They are very soft.",
         "ground" : "It is slipery.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
void init()
{
  ::init();
write("%^BOLD%^CYAN%^As you enter the room, a tidal wave of water forces you into a small hole.");
say("Someone joins you.");
}



