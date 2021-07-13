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
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
	]));

    set_exits(([
	"south" : FORESTDIR+"road13",
	"northwest" : FORESTDIR+"road15"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");

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

