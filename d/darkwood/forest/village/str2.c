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
before two homes that have a small grove of fruit trees 
between them.
VILLAGE
  );
  set_smell("default","Food arouses your stomach.");
  set_listen("default","People busy themselves with their daily work.");
  set_items( ([
     "street" : "Its dusty pal!",
     "clearing" : "Its a grassy clearing with a single dusty road and some buildings, thus forming a small village.",
     "layout" : "You can see homes scattered throughout the village.\nTo the southwest is a central firepit and to the south of it appears to be a general store.\nTo the south lies a home much larger then others.\nTo the far south is a stone well.\nAnd on first glance the only way out of the village is the way you came in.",
     "people" : "Men, women, and children run around doing their daily work or playing.",
     "pets" : "The pets vary but mostly dogs and pigs and the occassional cow and horse.",
     "grove" : "The trees are small but bare delicious fruit such as apples, pears, peaches, and plums."
  ]) );
  set_exits( ([
     "east" : "/d/darkwood/forest/village/home2",
     "west" : "/d/darkwood/forest/village/str1",
     "north" : "/d/darkwood/forest/village/home1",
     "south" : "/d/darkwood/forest/village/str3",
     "northeast" : "/d/darkwood/forest/village/undead1",
     "southwest" : "/d/darkwood/forest/village/firepit"
  ]) );
  set_invis_exits( ({"northeast"}) );
  }
