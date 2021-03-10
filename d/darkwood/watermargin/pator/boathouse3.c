//      boathouse3.c
//      Written by Pator@ShadowGate
//      Wed Apr  5 09:15:57 1995

#include <boathouse.h>

inherit ROOM;

void create() {
    room::create();
    set_light(2);
    set_short("Ouside Kurgan's Boathouse");
    set_property("indoors",0);
    set("day long",
@DAY
As you step out of the boathouse all you see is a big lake with a few boats on  it.  After a while you notice the carver making a new oar for a rowing boat.
Because the water is clear you can see the bottom of the lake and something
shining down there. You can get it only by taking a big breath and entering the water !!
DAY
    );
    set("night long",
@NIGHT
As you step out of the boathouse you can hardly make out the boats that are 
floating on the lake.  You stumble over some carving tools and end just at the
waterside.  You see something in the water, but it is to deep to get it. So if you want it you need to get yourself wet from top to bottom !
** For renting a boat go north !
NIGHT
	);
set_items( (["carving tools" : "The carver left them here so he can use them in the morning.",
            "water" : "There sure is something down there, but it is deep !!" ]));
set_smell("default","The smell of wet wood, water and freshly carved wood battle.");
set_listen("default","Only the silence of rippling water is heard.");
set_listen("carver","The carving noises can't get through to you.");
    set_exits(([
       "east"  : WATERM_BH+"boathouse2.c",
       "north" : WATERM_BH+"dock.c"]));
}

int dive()
{ message("my_action","You take a big breath and jump into the fresh water.\n",this_player());
  message("other_action",this_player()->query_cap_name()+" jumps into the water and vanishes in his waves",environment(this_player()));
  this_player()->move_player(WATERM_BH+"boathouse4.c");
  return 1;
}

void init()
{ ::init();
  add_action("dive","dive");
}
