#include <std.h>
#include "../tormdefs.h"
inherit VAULT;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_short("The Music Box");
  set_long(
  "%^BOLD%^The Music Box%^RESET%^\n"+
  "%^BOLD%^%^CYAN%^You are standing inside a brightly decorated and slightly cluttered"+
  " shop.  There are many %^RESET%^tools %^BOLD%^%^CYAN%^for making various %^RESET%^%^ORANGE%^instruments"+
  " %^BOLD%^%^CYAN%^here, many in the beginning stages and several finished products.  The"+
  " floor is covered in a %^RED%^bright red rug%^CYAN%^, and the walls are hung with"+
  " %^YELLOW%^cheery pictures%^CYAN%^.  %^WHITE%^M%^MAGENTA%^a%^BLUE%^s%^BLACK%^k%^WHITE%^s %^CYAN%^and"+
  " %^YELLOW%^c%^BLUE%^o%^CYAN%^l%^MAGENTA%^o%^GREEN%^r%^RED%^f%^YELLOW%^u%^GREEN%^l %^CYAN%^silks are"+
  " also draped about the walls, and a %^RED%^geranium %^CYAN%^plant sits on the window sill.  A side"+
  " room, perhaps once for storage, has been opened out and aired and"+
  " appears to lead to further sections of the shop to the south."
  );
  set_items(([
  ({"rug","red rug","bright red rug"}) : "%^BOLD%^%^RED%^The rug that"+
  " covers the floor is a bit dirty and worn thin, but it is still"+
  " a bright shade of red.",
  ({"plant","geranium"}) : "%^RED%^A dark red geranium sits on the"+
  " window sill, soaking up as much sunlight as possible.",
  ({"window","window sill"}) : "A potted geranium sits on the window"+
  " sill.",
  "tools" : "There are various tools with which to make instruments"+
  " scattered about the shop.",
  "instruments" : "There are several instruments in various stages"+
  " of being constructed, as well as some finished products.",
  ({"pictures","walls"}) : "The walls are decorated with cheery pictures"+
  " of various scenes, such as picnics in a meadow and people playing"+
  " in a lake.",
  ({"masks","silks","colorful silks"}) : "There are many exotic masks"+
  " and colorful silks that are draped artfully about the room.",
  ]));
  set_smell("default","You smell the sawdust from the instruments.");
  if(query_night()) {
    set_listen("default","You can hear people passing by on the street"+
    " outside.");
  }
  else {
    set_listen("default","The streets outside are quiet at night.");
  }
  set_exits(([
  "east":TCITY+"c51",
  "south":TCITY+"bardcomps",
  ]));
  set_door("door",TCITY+"c51","east",0);
  set_open("door",1);
}

void reset()
{
   ::reset();
   if(!present("vendor")) {
      new(MON+"bard")->move(TO);
   }
}
