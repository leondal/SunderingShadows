#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",2);
  set_property("indoors",0);
  set_climate("temperate");
  set_short("Dusty street of Stormpemhauder");
  set_long(
@VILLAGE
%^ORANGE%^Dusty street of Stormpemhauder%^RESET%^
You find yourself standing on a dusty street in 
Stormpemhauder, the only street in fact. From here 
you can see most the layout of the village in the only 
clearing you have come across in the Darkwoods. You stand 
before one of the homes and the central firepit.
VILLAGE
  );
  set_smell("default","Food arouses your stomach.");
  set_listen("default","People busy themselves with their daily work.");
  set_items( ([
     "street" : "Its dusty pal!",
     "layout" : "You can see homes scattered throughout the village.\nTo the west is a central firepit and to the south of it appears to be a general store.\nTo the south lies more homes and a stone well.\nTo the far west is one of the warehouses.\nAnd on first glance the only way out of the village is the way you came in.",
     "people" : "Men, women, and children run around doing their daily work or playing.",
     "pets" : "The pets vary but mostly dogs and pigs and the occassional cow and horse."
  ]) );
  set_exits( ([
     "east" : "/d/darkwood/forest/village/telhome",
     "west" : "/d/darkwood/forest/village/firepit",
     "north" : "/d/darkwood/forest/village/str2",
     "south" : "/d/darkwood/forest/village/str4"
  ]) );
}
