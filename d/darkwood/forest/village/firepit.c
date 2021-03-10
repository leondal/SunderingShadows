#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",0);
  set_short("Central Firepit of Stormpemhauder");
  set("day long",
@VILLAGE
%^BOLD%^%^RED%^Central Firepit of Stormpemhauder%^RESET%^
The central firepit is kept lit at all times and appears to have 
meat roasting over it on a spit. There is even a pot simmering near
by the fire that is giving off a most delicious odor. Benches sit 
around the pit in an almost semi circle so that on get togethers 
it is easier for everyone to see each other and talk. There are 
currently unlit torches surrounding the outer boundaries of the area.
VILLAGE
  );
  set("night long",
@VILLAGE
%^RED%^Central Firepit of Stormpemhauder%^RESET%^
The central firepit is kept lit at all times and appears to have 
meat roasting over it on a spit. There is even a pot simmering near 
by the fire that is giving off a most delicious odor. Benches sit
around the pit in an almost semi circle so that on get togethers 
it is easier for everyone to see each other and talk. There are 
lit torches surrounding the outer boundaries of the area so 
as to keep it well lighted.
VILLAGE
  );
  set_smell("default","A delicious aroma is coming from the firepit and pot.");
  set_listen("default","People are talking and the fire crackles away.");
  set_items( ([
     "spit" : "There appears to be fresh venison roasting. Maybe you can get a slice of it...",
     "pot"  : "You look into the pot and find potatoes and onions lightly seasoned and covered with butter. Maybe you can dip some out of the pot...",
     "torches" : "Like the torches at the wells these stand roughly 6ft tall or higher and chase away the shadows when lit.",
     "benches" : "Very sturdy and solid and look to hold as many as 12 at one time."
  ]) );
  set_exits( ([
     "north" : "/d/darkwood/forest/village/str1",
     "south" : "/d/darkwood/forest/village/square",
     "east" : "/d/darkwood/forest/village/str3",
     "west" : "/d/darkwood/forest/village/str9",
     "northeast" : "/d/darkwood/forest/village/str2",
     "northwest" : "/d/darkwood/forest/village/str10",
  ]) );
}

void init()
{
  ::init();
  add_action("slice_venison","slice");
  add_action("dip_pot","dip");
  }

int slice_venison(string str)
{
  tell_object(TP,"You grab up a nearby carving knife.\n");
  tell_object(TP,"You slice off a chunk of venison to eat.");
  tell_room(environment(TP),TPQCN+" slices off a chunk of venison to eat.",TP);
  new("/d/darkwood/obj/venison.c")->move(TP);
  return 1;
}
int dip_pot(string str)
{
  tell_object(TP,"You grab a nearby ladle.\n");
  tell_object(TP,"You dip the ladle in the pot and get some potatoes and onions to eat.");
  tell_room(environment(TP),TPQCN+" dips some potatoes and onions out of the pot to eat.",TP);
  new("/d/darkwood/obj/potgoods.c")->move(TP);
  return 1;
}
