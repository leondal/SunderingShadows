#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_short("Meriago's general trading storage");
   set_long("This is a storage area that you should not be in unless you're a wiz.");
}

void reset()
{
 ::reset();
 if(!present("torch"))
  new("/d/common/obj/misc/torch")->move(TO);
 if(!present("oil"))
  new("/d/common/obj/misc/oil")->move(TO);
 if(!present("flint"))
  new("/d/common/obj/misc/flint")->move(TO);
 if(!present("pouch"))
  new("/d/common/obj/misc/pouch")->move(TO);
 if(!present("sack"))
  new("/d/common/obj/misc/sack")->move(TO);
 if(!present("basket"))
  new("/d/common/obj/misc/basket")->move(TO);
 if(!present("small sack"))
  new("/d/common/obj/misc/ssack")->move(TO);
 if(!present("fishing pole"))
  new("/d/common/obj/misc/fishing_pole")->move(TO);
  present("fishing pole")->set_value(1);
 if(!present("bait"))
  new("/d/common/obj/misc/bait")->move(TO);
 if(!present("bait 2"))
  new("/d/common/obj/misc/bait")->move(TO);
 if(!present("bait 3"))
  new("/d/common/obj/misc/bait")->move(TO);
 if(!present("lantern"))
  new("/d/common/obj/misc/lantern")->move(TO);
 if(!present("statue"))
  new(OBJ+"r_statue")->move(TO);
 if(!present("statue 2"))
  new(OBJ+"r_statue")->move(TO);
 if(!present("statue 3"))
  new(OBJ+"r_statue")->move(TO);
 if(!present("statue 4"))
  new(OBJ+"r_statue")->move(TO);
 if(!present("hair comb"))
  new(OBJ+"r_comb")->move(TO);
 if(!present("hair comb 2"))
  new(OBJ+"r_comb")->move(TO);
 if(!present("fish stew"))
  new(OBJ+"stew")->move(TO);
if(!present("earrings"))
  new(OBJ+"r_earrings")->move(TO);
	if(!present("earrings 2"))
  new(OBJ+"r_earrings")->move(TO);


}
