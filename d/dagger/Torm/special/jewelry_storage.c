#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("no teleport",1);
   set_property("light",2);
   set_short("Torm's jewelry shop");
   set_long("Unless you're a wiz you'd better not be here.");
}

void reset()
{
 ::reset();
 if(!present("gold bracelet"))
  new(OBJ+"gbracelet")->move(TO);
 if(!present("pearl earrings"))
  new(OBJ+"pearrings")->move(TO);
 if(!present("whalebone choker"))
  new(OBJ+"choker")->move(TO);
 if(!present("water opal necklace"))
  new(OBJ+"opal_necklace")->move(TO);
 if(!present("water opal ring"))
  new(OBJ+"opal_ring")->move(TO);
 if(!present("pearl ring"))
  new(OBJ+"pring")->move(TO);
 if(!present("silver comb"))
  new(OBJ+"scomb")->move(TO);
 if(!present("pearl anklet"))
  new(OBJ+"panklet")->move(TO);
 if(!present("torm r_necklace"))
  new(OBJ+"r_necklace")->move(TO);
 if(!present("r_pearls"))
  new(OBJ+"r_pearls")->move(TO);
}
