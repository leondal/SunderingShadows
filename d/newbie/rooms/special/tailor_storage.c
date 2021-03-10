//made to load 2 of everything to make it easier for newbies.  Circe 5/28/04
#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("no teleport",1);
   set_short("Offestry Tailor Storage");
   set_long("This is the storage room of the Singing Seamstress.");
}

void reset()
{
  ::reset();
 if(!present("boots"))
  new(CLOTHING"boots")->move(TO);
 if(!present("boots 2"))
  new(CLOTHING"boots")->move(TO);
 if(!present("cloak"))
  new(CLOTHING"cloak")->move(TO);
 if(!present("cloak 2"))
  new(CLOTHING"cloak")->move(TO);
 if(!present("belt"))
  new(CLOTHING"belt")->move(TO);
 if(!present("belt 2"))
  new(CLOTHING"belt")->move(TO);
 if(!present("hat"))
  new(CLOTHING"c_hat")->move(TO);
 if(!present("hat 2"))
  new(CLOTHING"c_hat")->move(TO);
 if(!present("tunic"))
  new(CLOTHING"c_tunic")->move(TO);
 if(!present("tunic 2"))
  new(CLOTHING"c_tunic")->move(TO);
 if(!present("dress"))
  new(CLOTHING"c_dress")->move(TO);
 if(!present("dress 2"))
  new(CLOTHING"c_dress")->move(TO);
 if(!present("leggings"))
  new(CLOTHING"c_leggings")->move(TO);
 if(!present("leggings 2"))
  new(CLOTHING"c_leggings")->move(TO);
 if(!present("shirt"))
  new(CLOTHING"c_shirt")->move(TO);
 if(!present("shirt 2"))
  new(CLOTHING"c_shirt")->move(TO);
 if(!present("hat"))
  new(CLOTHING"c_hat")->move(TO);
 if(!present("hat 2"))
  new(CLOTHING"c_hat")->move(TO);
 if(!present("gloves"))
  new(CLOTHING"c_gloves")->move(TO);
 if(!present("gloves 2"))
  new(CLOTHING"c_gloves")->move(TO);
/* This bugs more, causing a pseudo crash.
 if(!present("pants"))
  new(CLOTHING"c_pants")->move(TO);
 if(!present("pants 2"))
  new(CLOTHING"c_pants")->move(TO);

Garrett */

 if(!present("skirt"))
  new(CLOTHING"c_skirt")->move(TO);
 if(!present("skirt 2"))
  new(CLOTHING"c_skirt")->move(TO);
}
