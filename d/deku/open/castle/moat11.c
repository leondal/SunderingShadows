//	moat11.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 05:31:25 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("In the moat");
    set_long(
@PATOR
You are standing in the moat. As an adventurer you have seen many moats, this one here is very pleasant for the eye. You smile as you look around.
PATOR
    );
set_listen("default","You hear water splashing and birds singing");
    set_exits(([
"east" : CASTLE+"moat10",
"north" : CASTLE+"moat12"
    ] ));
    set_items(([
       "trees" : "You see the trees standing at the edge of the moat. They are really beautifull !!",
       "water" : "The water is here and making it possible for the fish to swim."
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

void init()
{  ::init();
   add_action("kill_it","kill");
}

reset() {
  int x;
  ::reset();
  if (!present("fish"))
    { for (x = 0;x< random(4);x++)
      new(CASTLE+MONSTERS+"fish")->move(this_object());

    }
        }
