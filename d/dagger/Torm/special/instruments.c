#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("no teleport",1);
   set_property("light",2);
   set_short("Instrument Storage");
   set_long("You really shouldn't be in here unless you're a wiz.");
}

void reset()
{
 ::reset();
 if(!present("lyre"))
  new(OBJ+"lyre")->move(TO);
 if(!present("ocean drums"))
  new(OBJ+"drums")->move(TO);
 if(!present("maracas"))
  new(OBJ+"maracas")->move(TO);
 if(!present("whistle"))
  new(OBJ+"whistle")->move(TO);
 if(!present("tambourine"))
  new(OBJ+"tambourine")->move(TO);
 if(!present("instrument case"))
  new("/d/common/obj/instruments/instrument_case")->move(TO);
}
