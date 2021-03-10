#include <std.h>
#include "../tormdefs.h"
inherit BAR;
void create()
  {
  ::create();
  set_door("door",TCITY+"c41","north","Torm masterkey");
  set_short("Whalebones Gathering");
  set_long(
  "Whalebones Gathering.\n"
  "  This large establishment seems a good place to get a decent meal."
  "  The floors are clean and from the look of the waitstaff you get what you pay for with a smile."
  "  A few of the regular diners sit around their tables in small conversation while you look for an empty table for yourself."
   "  On the walls hang the bones of a rather small whale, although they take up plenty of space in here."
  );
   set_items(([
   ({"floor","floors"}) : "The floors are kept fairly clean, judging from how popular this place seems, they must be swept regularly.",
   "tables" : "There are several wooden tables scattered about the room. The larger ones have small arrangements of fresh flowers, but most of those are taken. There are a couple empty tables scattered about the room, however.",
   ({"flowers","flower arrangements"}) : "The flowers are freshly cut lillies, usually only one or two per vase, but it brightens the room a little.",
   "lillies" : "%^BOLD%^%^WHITE%^The lillies are very beautiful, they have slender yellow centers, but are otherwise pure white. They give off no smell, but they lighten the room.%^RESET%^",
   ({"vase","vases"}) : "The vases are fairly simple and slender, made of pottery that has been glazed a dark blue.",
   "ceiling" : "A few large brass chandeliers hang from the ceilings with lit candles.",
   ({"chandeliers","brass chandeliers","candles"}) : "A couple large brass chandeliers hang down from the ceiling. They are filled with lit candles that drip wax into small holders. They keep the room fairly well lit.",
   ({"wall","walls"}) : "The walls around the room are covered in whalebones that must be small for a whale, but take up most of the wall space.",
   ({"bones","whalebones"}) : "%^BOLD%^%^WHITE%^Whalebones cover the walls, reaching from a smaller head that spans over six feet, to the ribs that are almost twelve feet, and down to the tail. The whale was probably small for one of its kind, but the bones are huge, and the actual whale would be even bigger!",
   ]));
  set_exits(([
  "north":TCITY+"c41",
  ]));
  set_open("door",1);
}
void reset(){
  object ob;
  ::reset();
  if(!present("waitstaff",TO)) {
      new(MON+"barkeep1")->move(TO);
  }
  if(!present("torm citizen",TO)){
     ob=new(MON+"citizen.c");
     ob->set_speed(0);
     ob->move(TO);
  }
}
