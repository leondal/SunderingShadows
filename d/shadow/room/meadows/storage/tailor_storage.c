#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_short("Farith's storage area");
   set_long("This is a storage room that you shouldn't be in unless you're a wiz.");
}

void reset()
{
 ::reset();
 if(!present("cloak")) 
  new(OBJ+"r_cloak")->move(TO);
 if(!present("cloak 2"))
  new(OBJ+"r_cloak")->move(TO);
 if(!present("dress"))
  new(OBJ+"r_dress")->move(TO);
 if(!present("dress 2"))
  new(OBJ+"r_dress")->move(TO);
 if(!present("hat"))
  new(OBJ+"r_hat")->move(TO);
 if(!present("jacket"))
  new(OBJ+"r_jacket")->move(TO);
 if(!present("jacket 2"))
  new(OBJ+"r_jacket")->move(TO);
 if(!present("leggings"))
  new(OBJ+"r_leggings")->move(TO);
 if(!present("leggings 2"))
  new(OBJ+"r_leggings")->move(TO);
 if(!present("pants"))
  new(OBJ+"r_pants")->move(TO);
 if(!present("pants 2"))
  new(OBJ+"r_pants")->move(TO);
 if(!present("scarf"))
  new(OBJ+"r_scarf")->move(TO);
 if(!present("shirt"))
  new(OBJ+"r_shirt")->move(TO);
 if(!present("shirt 2"))
  new(OBJ+"r_shirt")->move(TO);
 if(!present("shirt 3"))
  new(OBJ+"r_shirt")->move(TO);
 if(!present("shorts"))
  new(OBJ+"r_shorts")->move(TO);
 if(!present("shorts 2"))
  new(OBJ+"r_shorts")->move(TO);
 if(!present("skirt"))
  new(OBJ+"r_skirt")->move(TO);
 if(!present("skirt 2"))
  new(OBJ+"r_skirt")->move(TO);
 if(!present("sweater"))
  new(OBJ+"r_sweater")->move(TO);
 if(!present("sweater 2"))
  new(OBJ+"r_sweater")->move(TO);
 if(!present("tunic"))
  new(OBJ+"r_tunic")->move(TO);
 if(!present("tunic 2"))
  new(OBJ+"r_tunic")->move(TO);
}
