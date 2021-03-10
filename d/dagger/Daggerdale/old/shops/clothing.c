#include <std.h>
inherit ROOM;

#define OBJ "/d/dagger/Daggerdale/shops/items/"

void create()
{
   ::create();
   set_property("no teleport",1);
   set_short("Daggerdale clothing storage");
   set_long("This is Kedathia's clothing storage area in Daggerdale.");
}

void reset()
{
 ::reset();
 if(!present("d_boots"))
  new(OBJ+"r_boots")->move(TO);
 if(!present("gown"))
  new(OBJ+"r_gown")->move(TO);
 if(!present("belt"))
  new(OBJ+"r_belt")->move(TO);
 if(!present("cloak"))
  new(OBJ+"r_cloak")->move(TO);
 if(!present("dress"))
  new(OBJ+"r_dress")->move(TO);
 if(!present("jacket"))
  new(OBJ+"r_jacket")->move(TO);
 if(!present("leggings"))
  new(OBJ+"r_leggings")->move(TO);
 if(!present("pants"))
  new(OBJ+"r_pants")->move(TO);
 if(!present("shirt"))
  new(OBJ+"r_shirt")->move(TO);
 if(!present("shorts"))
  new(OBJ+"r_shorts")->move(TO);
 if(!present("skirt"))
  new(OBJ+"r_skirt")->move(TO);
 if(!present("tunic"))
  new(OBJ+"r_tunic")->move(TO);
 if(!present("vest"))
  new(OBJ+"r_vest")->move(TO);
	if(!present("scarf"))
		new("/d/shadow/room/meadows/obj/r_scarf.c")->move(TO);
	if(!present("scarf 2"))
		new("/d/shadow/room/meadows/obj/r_scarf.c")->move(TO);
	if(!present("hat"))
		new("/d/shadow/room/meadows/obj/r_hat.c")->move(TO);
	if(!present("hat 2"))
		new("/d/shadow/room/meadows/obj/r_hat.c")->move(TO);
	if(!present("handkerchief"))
		new("/d/antioch/antioch2/obj/r_hchief.c")->move(TO);
}
