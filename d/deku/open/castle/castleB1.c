// File    : castleB1.c
// Author  : Pator@ShadowGate
// Date    : 06/14/95 && 11/15/95

#include <castle.h>

inherit ROOM;

int found;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    seteuid(getuid());
    set_indoors(1);
    set_light(1);
    set_short("The castle blacksmith");
    set_long(
@PATOR
You have entered the castle forge. As you expected it is very hot in here
and this is the place where the castle blacksmith makes his things : tools,
swords, shields and more things one needs.
PATOR
	   );
    set_items(([
       "anvil" : "It has been born of a dark metal",
       "hammers" : "A master craftsman made these for sure !",
       "bucket" : "It is filled with water to cool the hot metal."]));
   set_listen("default","The sounds of weapon creation are crisp here!");
   set_smell("default","You smell the heavy scent of steel, metal and the flames in the forge.");
    set_exits(([
        "south":CASTLE+"castleW11",
    ]));
}

void reset()
{
  ::reset();
    found = 0;
    if (!(present("blacksmith")))
      { new(CASTLE+"monster/blacksmith")->move(this_object()); }
}

void init()
{
  ::init();
//    add_action("search_it","search");
}


int search_it(string str)
{
  string YOU;
  object ob;
  YOU = (string)this_player()->query_cap_name();
  if (!str)
    {
      notify_fail("You get dirty but find nothing !");
      return 0;
    }
  else
    {
      if (!(str == "bucket"))
	{
	  notify_fail("You search around "+str+" but find nothing. \n");
	  return 0;
	}
      if (!found)
	{ 
	  tell_player(this_player(),
		      "You find a blackenend key in the bucket !");
	  tell_room(environment(this_player()),
	    YOU+" pokes around the bucket and seems to have found something !",
				({ this_player() }));
	  ob = new(CASTLE+"object/blackkey");
	  ob->move(this_player());
	  found = 1;
	  return 1;
	}
      else
	{
	  tell_player(this_player(),
	      "The bucket seems to have been thorougly searched already !");
	  tell_room(environment(this_player()),
	       YOU+" pokes around the bucket.\n", ({ this_player() }));
	  return 1;
        }
    }
}
