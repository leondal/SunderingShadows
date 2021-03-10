#include <std.h>
#include "../tormdefs.h"
inherit BAR;
void create()
  {
  ::create();
  set_property("indoors",1);
  set_door("door",TCITY+"c29","south","masterkey");
  set_smell("default","Something is rotting in here somewhere...");
    set_listen("default","The waves of the Dagger Sea come through the mutterings of the patrons.");
  set_short("Black orc bar");
  set_long(
  "  Black orc bar seems to collect all the riffraff and the more boistrous sailors to its tables and ale taps."
  "  The tables show signs of wear and not much love added back into them in the way of upkeep."
  "  Broken crockery lies in a corner where someone hasn't bothered to sweep it up yet, and over all the impression you get here is buy a drink or get the hell out."
   "  There are a few bar stools on the north side, some of which are empty if you wanted a drink. There's no place in here that is quiet, however." 
  );
   set_items(([
   "tables" : "The tables are rather worn and scratched, some have obviously been split in half before and were repaired...sort of. The place is fairly crowded, but there are a few free tables in the back if you really want to sit at them.",
   "floor" : "The floor is covered in dirt and grime, and in one corner broken pieces of crockery. Every now and then you notice someone drop something, and then pick it up off the floor and eat it. Sometimes a brave rat will dart in and steal some of the food.",
   ({"crockery","broken crockery"}) : "Broken crockery lies in a pile in one corner. Not only hasn't it been swept up, it appears as though whenever something breaks, they merely sweep it into that pile!",
   ({"stools","bar stools"}) : "On the north side of the room are a few bar stools, some of which are empty. They aren't in the best of shape, but at least they appear sturdy.",
   ]));
  set_exits(([
  "south":TCITY+"c29",
  ]));
  set_open("door",1);
}
void reset(){
  object ob;
  ::reset();
  if(!present("taath",TO)){
 new(MON+"barkeep5")->move(TO);
  }
  if(!present("drunken pirate",TO)){
  ob=new(MON+"pirated");
  ob->set_speed(0);
  ob->move(TO);
  }
  if (!present("grubcheck", TO)){
  ob=new(MON+"grubcheck");
  ob->set_speed(0);
  ob->move(TO);
  }
}
