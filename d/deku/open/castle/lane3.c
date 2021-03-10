//	lane3.c
//	Pator@ShadowGate
//	Fri May 12 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_light(0);
    set_indoors(0);
    set_short("On the lane towards the castle");
    set("day long",
@DAY
You are on the lane towards the castle to the north and the town
to the south.   On the sides of the lane, there are oak trees 
standing, and further in the forest is to thick to enter.  On
the western side though it's not as dense.
DAY
    );
    set("night long",
@NIGHT
This lane is lined with oaks and the forest after them is very thick and you can't enter it. The oaks are blocking most of the moonlight.
NIGHT
    );
set_listen("default","The woods reveal wood-like noises.");
    set_exits(([
"south" : CASTLE+"lane2",
"north" : CASTLE+"lane4"
    ] ));
set_items(([ "oaks" : "The oaks are lining the road and are very old.",
	     "wood" : "It is on both sides of the lane and it is too thick to enter.",
	     "castle" : "It is to the north." ]));
   
}

int search_it()
{ tell_room(environment(this_player()),"A trapdoor opens with a loud noise.");
add_exit(CASTLE+"castleW2","enter");
   set_pre_exit_functions(({"enter"}),({"do_enter"}));
  return 1;
}
	  
init()
{
  ::init();
  add_action("search_it","search");
}

reset()
{
  ::reset();
  remove_exit("enter");
}

int do_enter(){
   write("You enter the trapdoor and you slip !! You slide down for a very long time .");
   write("When you look you are inside the castle near the stables");
   return 1;
}
