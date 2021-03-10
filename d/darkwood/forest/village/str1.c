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
you can see the entire layout of the village in the only 
clearing you have come across in the Darkwoods. Upon 
first glance there doesnt appear to be much here 
except for people and a few pets.
VILLAGE
  );
  set_smell("default","Food arouses your stomach.");
  set_listen("default","People busy themselves with their daily work.");
  set_items( ([
     "street" : "Its dusty pal!",
     "clearing" : "Its a grassy clearing with a single dusty road and some buildings, thus forming a small village.",
     "layout" : "You can see homes scattered throughout the village.\nTo the southwest is a possible warehouse.\nTo the south is a central firepit and beyond it is what appears to be a general store.\nTo the southeast lies a home much larger then others.\nTo the west and far southeast are stone wells.\nAnd on first glance the only way out of the village is the way you came in.",
     "people" : "Men, women, and children run around doing their daily work or playing.",
     "pets" : "The pets vary but mostly dogs and pigs and the occassional cow and horse."
  ]) );
  set_exits( ([
     "east" : "/d/darkwood/forest/village/str2",
     "west" : "/d/darkwood/forest/village/str10",
     "north" : "/d/darkwood/forest/village/trail3",
     "south" : "/d/darkwood/forest/village/firepit"
  ]) );
}
