#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_short("%^ORANGE%^A tiny path%^RESET%^");
   set_long(
   "%^GREEN%^This is a very old and rather over grown trail that has dwindled"+
   " down to a tiny, unused %^ORANGE%^path%^GREEN%^. At one point it may have lead out of"+
   " %^BOLD%^%^CYAN%^Moonstone Vale%^RESET%^%^GREEN%^ into the %^MAGENTA%^"+
   "mountains%^GREEN%^ beyond, but it hasn't been used"+
   " by anyone in so many years that it ends right here. The forest"+
   " has grown up around and in front of you, leaving only the tiny"+
   " remenant of a trail here and to the south.\n"
   );
   set_smell("default","You can smell the grass beneath your feet.");
   set_listen("default","The forest is alive with rustling sounds and birdsong.");
   set_items(([
   ({"bushes","scrub brush","brush"}) : "%^GREEN%^Scrub brush has started growing along the"+
   " edges of the vale and the forest.",
   ({"forest","trees"}) : "%^BOLD%^%^GREEN%^The forest is right next to you. You can see the tall"+
   " green trees reaching into the sky and hear the scurrying of little animals"+
   " that are busily rushing about. It is not like the Dark Forest at all, and"+
   " you almost wonder if this is what the Dark Forest was like long ago.",
   ({"path","trail"}) : "%^ORANGE%^The tiny trail has been largely overgrown by"+
   " weeds and vines. It once was several feet wide from what you can"+
   " tell, but most of the stones lining the path have been washed"+
   " away that it is hardly anything now. At one point it probably lead"+
   " out of Moonstone Vale to the other side of the mountain, but after"+
   " evil occupied these lands for so long it has been forgotten.",
   ]));
   set_exits(([
   "south" : FPATH+"trail1",
   ]));
}
