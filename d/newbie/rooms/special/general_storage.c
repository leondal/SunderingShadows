//changed to use the common general store list - it was essentially the same.
//anything special wanted here can still be added into the reset() function
//Styx 7/29/01

#include <std.h>
#include "/d/common/common.h"

inherit "/d/common/inherit/gs_storage";
object ob;

void create() {
   ::create();
   set_property("no teleport",1);
   set_short("Offestry General Storage");
   set_long("This is the supply room for the Odds and Ends general store.");
   set_exits( (["up" : "/d/newbie/rooms/town/general.c"]) );
}

void reset() {
  ::reset();
  if(!present("mining pick")) new("/d/newbie/obj/misc/mining_pick.c")->move(TO);
  while (ob=present("gem")) ob->remove();
  if(!present("climb_tool 2") && !random(2))   new(CMISC"climb_tool")->move(TO);
  if(!present("basket 2") && !random(2))       new(CMISC"basket")->move(TO);
  if(!present("torch 2") && !random(2))        new(CMISC"torch")->move(TO);
  if(!present("pouch 2"))                      new(CMISC"pouch")->move(TO); 
}
