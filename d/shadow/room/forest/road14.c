#include "forest.h"
inherit "/d/shadow/room/forest/road1";

int found = 0;


void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_items(([
	"road":"A new road through the forest.",
	"forest":"A quiet forest, for sure. Only the sounds of birds."
	]));
 
    set_exits(([
	"south" : FORESTDIR+"road13",
	"northwest" : FORESTDIR+"road15"
   	]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear birds singing.");

}

init()
{
	::init();
	add_action("dig_it","dig");
}

reset()
{
	::reset();
	found = 0;
}

int dig_it(string str)
{
	if (!str)
          { notify_fail("You can't dig nothing  !\n");
	    return 0;
	  }
	else
	  {
	    if (str != "with hands")
		{ notify_fail("Well you can't dig it !!\n");
		  return 0;
		}
	   else
		{
		  if (found)
			{ notify_fail("The road has been dug in before !\n");
			  return 0;
			}
		  else
			{
			  tell_player(TP,
		"You dig in the road and you find a hourglass !");
			  tell_room(environment(TP),
                TPQCN+" digs in the road and finds something !", ({ TP }));
		new("/d/shadow/obj/misc/hourglass")->move(this_object());
		found = 1;
			  return 1;
			}
		}
	}
}

