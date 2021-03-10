#include <std.h>
#include "../witchlair.h"
inherit ROOM;

void create() {
 ::create();
 set_property("light",0);
 set_property("no sticks",0);
 set_property("no teleport",0);
 set_property("no starve",0);
 set_property("no magic",0);
 set_property("no steal",0);
 set_short("%^BOLD%^%^BLACK%^A dark tunnel of %^GREEN%^vines");
 set_long("%^BOLD%^%^BLACK%^A dark tunnel of %^GREEN%^vines\n\n"
"%^RESET%^%^GREEN%^The hole you've had to crawl on hands and "
"knees into opens up into this tunnel barely tall enough to stand"
" in. The light barely penetrates several inches beyond the "
"entrance, leaving the tunnel shrouded in darkness...better hope "
"you've brought a torch.");
 set_smell("The pungent scent of the vines is overwhelming.");
 set_listen("Only the occasional rustling disturbs the silence "
"as some vermin or another scurries about unseen.");
 set_items(([
   ({"walls", "wall", "vines"}) : "%^BOLD%^%^BLACK%^Since you "
"can evidently see in this pitch-black tunnel, you notice the "
"vines have grown thick enough to form a tightly-woven barrier "
"that effectively blocks out all light.",
 ]));
 set_exits(([
  "east":ROOMS"grove8",
  "west":ROOMS"viikcave",
 ]));
}
