#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("no teleport",1);
   set_property("light",2); 
   set_short("Minstrel's storage room");
   set_long("If you're not a wiz you better not be here.");
}

void reset()
{
  ::reset();
 if(!present("harp"))
  new(OBJ+"harp")->move(TO);
 if(!present("flute"))
  new(OBJ+"flute")->move(TO);
 if(!present("guitar"))
  new(OBJ+"guitar")->move(TO);
 if(!present("instrument case"));
  new("/d/common/obj/instruments/instrument_case")->move(TO);
}
