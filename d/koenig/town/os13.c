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
  set_long("%^RESET%^%^GREEN%^You are standing in the southeast corner of the grounds. Looking to the west "+
"from where you stand you can see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining most of the fence, and a "+
"large %^BOLD%^%^BLACK%^misshapen tree%^RESET%^%^GREEN%^ of some kind. You notice a %^BOLD%^bush%^RESET%^%^GREEN%^ behind you that has "+
"been trimmed to resemble a rhinocerous. You can almost imagine it getting "+
"ready to paw the earth and charge some unexpecting target, pulverizing it. Thank your lucky stars that it's only a bush.%^RESET%^\n");
  set_smell("default","You can smell the sweet fragrance of roses."); 
  set_listen("default","You can hear the faint keening of someone calling for help.");
  set_items( ([
     "bushes":"There are several different rose bushes...each a different color but each color always seems to have a tint of red in it.",
     "bush":"This bush stands about 8 feet tall at, what appears to be, the shoulder of the beast. It's a bit unnerving for you to watch the wind blow through its leaves. It almost looks like muscles bunching and relaxing."
]) );
  set_exits( ([
     "west":"/d/koenig/town/os12",
     "north":"/d/koenig/town/os14"
]) );
}
