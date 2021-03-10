#include "../../newbie.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("no teleport",1);
   set_short("Offestry Jewelery Storage");
   set_long("This is the storage room of the Smokey Quartz.");
}

void reset()
{
  ::reset();
 if(!present("bracelet"))
  new(CLOTHING"c_bracelet")->move(TO);
 if(!present("bracelet 2"))
  new(CLOTHING"c_bracelet")->move(TO);
 if(!present("necklace"))
  new(CLOTHING"c_necklace")->move(TO);
 if(!present("necklace 2"))
  new(CLOTHING"c_necklace")->move(TO);
 if(!present("ring"))
  new(CLOTHING"c_ring")->move(TO);
 if(!present("ring 2"))
  new(CLOTHING"c_ring")->move(TO);
 if(!present("hair clasp"))
  new(CLOTHING"c_clasp")->move(TO);
 if(!present("quartz pendant"))
  new(CLOTHING"c_pendant")->move(TO);
}
