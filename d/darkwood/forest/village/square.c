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
%^BOLD%^%^RED%^Town Square of Stormpemhauder%^RESET%^
The square is a gathering place for the many citizens of 
Stormpemhauder. There are benches surrounding the area
where people can be found at almost any time. You can barely
move without bumping into someone, but the people are all very
friendly here. You can see the firepit to the north.
VILLAGE
  );
  set("night long",
@VILLAGE
%^RED%^Town Square of Stormpemhauder%^RESET%^
While not as full as during the day, the town square never
seems to be empty. There are benches surrounding the area
where people can be found at almost any time. There are lit 
torches surrounding the area so as to keep it well lighted.
The firepit is to the north.
VILLAGE
  );
  set_smell("default","A delicious aroma is coming from the firepit to the north.");
  set_listen("default","People are talking and the fire crackles away.");
  set_items( ([
     "torches" : "Like the torches at the wells these stand roughly 6ft tall or higher and chase away the shadows when lit.",
     "benches" : "Very sturdy and solid and look to hold as many as 12 at one time."
  ]) );
  set_exits( ([
     "north" : "/d/darkwood/forest/village/firepit",
     "south" : "/d/darkwood/forest/village/str6",
     "east" : "/d/darkwood/forest/village/str4",
     "west" : "/d/darkwood/forest/village/str8",
     "southeast" : "/d/darkwood/forest/village/str5",
     "southwest" : "/d/darkwood/forest/village/str7",
  ]) );
}
