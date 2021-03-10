#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors",0);
  set_short("The Tower Courtyard");
  set_long("%^RESET%^%^GREEN%^Your standing in the northwest corner of the grounds. Looking to the east "+
"from where you stand, you can see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining the fence. They are "+
"very thick. You notice a large %^BOLD%^bush%^RESET%^%^GREEN%^ behind you that has been trimmed into "+
"the form of what appears to be a saber-tooth tiger. You can almost imagine "+
"it bunching its muscles, as if to spring at some unseen prey. Bet you are really "+
"glad this is only a bush.%^RESET%^\n");
  set_smell("default","You can smell the sweet fragrance of roses."); 
  set_listen("default","You can hear the faint keening of someone calling for help.");
  set_items( ([
     "bushes":"There are several different rose bushes, each a different color. Each color always seems to have a tint of red in it.",
     "bush":"This bush stands about 8 feet at, what looks to be, the shoulder, and looks very much like a saber-tooth about to spring on its unsuspecting prey. What is really unnerving about it is when the wind blows through its leaves it looks like it is breathing and twitching its stubby tail. The rustling of its branches almost sounds like a very soft, predatory growl."
]) );
  set_exits( ([
     "east":"/d/koenig/town/os5",
     "south":"/d/koenig/town/os7"
]) );
}
