#include <std.h>
#include "../../antioch.h"
inherit "/d/common/inherit/gs_storage";

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Gralibard's General Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"general"]));
   new("/d/common/obj/sheath/sheath_medium")->move(TO);
   new("/d/common/obj/sheath/sheath_medium")->move(TO);
   new("/d/common/obj/sheath/sheath_great")->move(TO);
   new("/d/common/obj/sheath/sheath_small")->move(TO);
   new("/d/common/obj/sheath/sheath_large")->move(TO);
   new("/d/common/obj/sheath/sheath_mstaff")->move(TO);
   new("/d/common/obj/sheath/sheath_mbludgeon")->move(TO);
   new("/d/common/obj/sheath/sheath_lgstaff")->move(TO);
   new("/d/common/obj/sheath/sheath_lgbludgeon")->move(TO);
}

void reset()
{
   object obj;

	::reset();
if(!present("sack")) 
 new("/d/common/obj/misc/sack")->move(TO);
if(!present("ssack"))
 new("/d/common/obj/misc/ssack")->move(TO);
if(!present("pouch"))
 new("/d/common/obj/misc/pouch")->move(TO);
if(!present("spouch"))
 new("/d/common/obj/misc/spouch")->move(TO);
if(!present("climb_tool"))
 new("/d/common/obj/misc/climb_tool")->move(TO);
if(!present("rope"))
 new("/d/common/obj/misc/rope")->move(TO);
if(!present("torch"))
 new("/d/common/obj/misc/torch")->move(TO);
if(!present("lantern"))
 new("/d/common/obj/misc/lantern")->move(TO);
if(!present("oil"))
 new("/d/common/obj/misc/oil")->move(TO);
if(!present("beacon"))
 new("/d/common/obj/misc/beacon")->move(TO);
if(!present("bullseye"))
 new("/d/common/obj/misc/bullseye")->move(TO);
if(!present("flint"))
 new("/d/common/obj/misc/flint")->move(TO);
if(!present("chest"))
 new("/d/common/obj/misc/chest")->move(TO);
 if(!present("gem pouch"))
  new("/d/islands/tonerra/obj/gpouch")->move(TO);
 if(!present("bandage"))
  new("/d/common/obj/misc/bandage")->move(TO);
   while(!present("paper 8")) new("/d/tharis/obj/paper")->move(TO);
if (!objectp(obj=present("wood")))
 obj = new("/d/common/obj/misc/wood.c");
 obj->move(TO);
 obj->set_value(3);
 obj->set_cointype("copper");
}
