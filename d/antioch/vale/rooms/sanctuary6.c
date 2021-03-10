#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_property("no teleport",1);
   set_property("fill waterskin",1); //suitable now to cast reflection spell, per player request, 9 Dec 19, Uriel
   if(query_night()) {
      set_short("%^BOLD%^A bridge over a pool%^RESET%^");
   }
   else {
      set_short("%^BOLD%^A bridge over a %^CYAN%^pool%^RESET%^");
   }
   set_long(
   "%^GREEN%^Druidic Sanctuary%^RESET%^\n"+
   "%^GREEN%^You are standing on the bridge in the center of the"+
   " sanctuary. The bridge is sturdy and made of solid %^BOLD%^%^WHITE%^stones%^RESET%^%^GREEN%^. You"+
   " notice that each block has been engraved with some kind of %^ORANGE%^animal"+
   " %^GREEN%^or %^BOLD%^plant%^RESET%^%^GREEN%^. The blocks on the bottom"+
   " are typically %^BOLD%^plants%^RESET%^%^GREEN%^ and land"+
   " dwelling %^ORANGE%^animals%^GREEN%^, while the blocks on the side are"+
   " %^BOLD%^%^BLUE%^birds %^RESET%^%^GREEN%^and other"+
   " %^BOLD%^%^CYAN%^avians%^RESET%^%^GREEN%^. Raised up on the top of the "+
   "railing is a slender %^BOLD%^vine%^RESET%^%^GREEN%^ with"+
   " leaves. The bridge is truly a masterpiece and just standing over"+
   " the %^BOLD%^%^CYAN%^pool%^RESET%^%^GREEN%^ lends you a sense of inner %^CYAN%^peace%^GREEN%^.\n"
   );
   set("night long",
   "%^GREEN%^Druidic Sanctuary%^RESET%^\n"+
   "%^BOLD%^%^BLUE%^You are standing on the bridge in the center of the sanctuary. The"+
   " %^CYAN%^pool%^BLUE%^ beneath you seems almost to glow with a"+
   " %^WHITE%^milky white%^BLUE%^ light, similar to that of a %^WHITE%^moonstone%^BLUE%^. Looking at it"+
   " fills you with a calm sense of %^RESET%^%^CYAN%^serenity%^BOLD%^%^BLUE%^. You notice that the"+
   " bridge on which you are standing has %^GREEN%^leafy vines %^BLUE%^raised up on the"+
   " stone railings. There are also other %^RESET%^%^ORANGE%^animals%^BOLD%^%^BLUE%^"+
   " and %^GREEN%^plants%^BLUE%^ engraved"+
   " in the stone that are a bit harder to make out at night.\n"
   );
   set_smell("default","The air is fresh and clear.");
   set_listen("default","Everything is peacefully quiet here.");
   set_items(([
   "path" : "%^ORANGE%^There is a small dirt path that winds around the edges"+
   " of the pool.",
   "bridge" : "%^BOLD%^The bridge you are standing on is arched in the center"+
   " and has railings on either side with stones that have been carved"+
   " with the shapes of wild animals and plants. You notice that the"+
   " top of the railing has a carved stone vine delicately raised up."+
   " The bottom stones have pictures of plants and flowers as well as"+
   " land dwelling animals, while the side rail stones have images of"+
   " butterflies, dragonflies, birds, and other flying creatures. It"+
   " is a marvelous little masterpiece.",
   ({"wall","wall of brambles"}) : "%^GREEN%^The wall of brambles"+
   " circles the sanctuary, protecting it from the outside world.%^RESET%^",
   "pool" : "%^BOLD%^%^CYAN%^The pool in the center is oval shaped and"+
   " completely calm. It reflects the bridge and the sky above and"+
   " instills in you a sense of peace.",
   ]));
   set_exits(([
   "north" : ROOMS+"sanctuary5",
   "south" : ROOMS+"sanctuary1",
   ]));
}

void reset()
{
   ::reset();
   if(query_night()) {
      add_item("pool","%^BOLD%^The pool shines like a milky white"+
      " moonstone in the center of the sanctuary, oval shaped and"+
      " depthless it seems serene. Just looking at it causes a sense"+
      " of utter peace to wash over you.%^RESET%^");
   }
   if(!present("arch druid")) {
      new(MONS+"archdruid")->move(TO);
  }
}
