//	moat3.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 1995

#include <castle.h>

inherit ROOM;

void create() {
     ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("In the moat");
    set_long(
@ONLINE09D
You are standing in the moat. The water sill looks fresh here.
You see the corner of the castle here.  You wonder what could
be around the bend?
ONLINE09D
    );
set_listen("default","You hear water splashing and birds singing");
    set_exits(([
"west" : CASTLE+"moat2",
"east" : CASTLE+"moat4"
    ] )); 
    set_items(([
       "water" : "You see some fish in the clear water. It looks they are playing follow the leader.",
       "corner" : "What do you think it is, 2 walls ending in a square angle !"
    ] ));
}

int kill_it(string str)
{
  if (str == "fish")
    { if ((int)this_player()->query_level() > 6 && present("fish") )
	{
	  write("You want to kill a harmless animal ????\n I thought you where a real adventurer !!!!");
	  return 1;
	}
    }
  return 0;
}

init()
{
  ::init();
  add_action("kill_it","kill");
}


reset() {
  int x;
  ::reset();
  if (!present("fish"))
    { for (x = 0 ;x < random(2);x++)
      new(CASTLE+MONSTERS+"fish")->move(this_object());

    }
        }
