#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
    set_door("door","/d/koenig/town/tower16.c","door","open_door");
    set_open("door",0);
  set_property("light", 1);
  set_property("indoors",0);
  set_short("The Tower Courtyard");
  set_long("%^RESET%^%^GREEN%^You step outside onto the grounds surrounding the tower. Some of it looks "+
"well cared for while other parts look rather neglected. The %^BOLD%^%^BLACK%^wrought iron "+
"fence%^RESET%^%^GREEN%^ looks just as solid from this side as it did from the other. In some "+
"spots though the %^ORANGE%^fence%^RESET%^%^GREEN%^ is over grown with %^BOLD%^plants%^RESET%^%^GREEN%^ and %^BOLD%^bushes%^RESET%^%^GREEN%^. You have a few "+
"options in what direction you can go, but I'd tread carefully if I were you.%^RESET%^\n");
  set_smell("default", "You can smell the sweet fragrance of roses and other things here.");
  set_listen("default", "You can hear a soft keening for help.");
  set_listen("keening", "It appears to be coming somewhere from the southwest.");
  set_items( ([
     "fence" : "You feel in your bones there has to be a way through, if you can only find it.",
     "plants" : "You can see roses to the northeast and the southwest, but you also notice some rather large weeds.",
     "bushes" : "Some of these have been trimmmed into the shapes of animals... at least you think it's the form of animals."
]) );
  set_exits( ([
     "door" : "/d/koenig/town/tower16",
     "north" : "/d/koenig/town/os2",
     "south" : "/d/koenig/town/os14"
]) );
}