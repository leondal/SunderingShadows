#include <std.h>
inherit ROOM;

#define OBJ "/d/dagger/Daggerdale/shops/items/"

void create()
{
   ::create();
   set_property("no teleport",1);
   set_short("Daggerdale jewelry storage");
   set_long("This is Jerat's jewelry storage area in Daggerdale.");
}

void reset()
{
 ::reset();
 if(!present("smokey quartz pendant"))
  new("/d/newbie/obj/clothing/c_pendant")->move(TO);
 if(!present("moonstone amulet"))
  new(OBJ+"r_amulet")->move(TO);
 if(!present("hair comb"))
  new("/d/shadow/room/meadows/obj/r_comb")->move(TO);
 if(!present("r_broach"))
  new("/d/antioch/antioch2/obj/r_broach")->move(TO);
 if(!present("moonstone earrings"))
  new(OBJ+"earrings")->move(TO);
 if(!present("bracelet"))
  new("/d/newbie/obj/clothing/c_bracelet")->move(TO);
 if(!present("r_circlet"))
  new("/d/antioch/antioch2/obj/r_circlet")->move(TO);
 if(!present("r_armband"))
  new("/d/antioch/antioch2/obj/r_armband")->move(TO);
 if(!present("crescent necklace"))
  new(OBJ+"crescent_necklace")->move(TO);
 if(!present("clasp"))
  new(OBJ+"r_clasp")->move(TO);
 if(!random(4) && !present("tiara"))
  new(OBJ+"tiara")->move(TO);
 if(!present("anklets"))
  new(OBJ+"anklets")->move(TO);
	if(!present("r_ring"))
 new("/d/antioch/antioch2/obj/r_ring")->move(TO);
 if(!present("r_ring 2"))
  new("/d/antioch/antioch2/obj/r_ring")->move(TO);
 if(!present("r_ring 3"))
  new("/d/antioch/antioch2/obj/r_ring")->move(TO);
	if(!present("earrings 2"))
	new("/d/shadow/room/meadows/obj/r_earrings.c")->move(TO);
	if(!present("earrings 3"))
	new("/d/shadow/room/meadows/obj/r_earrings.c")->move(TO);
if(!present("r_bracelet"))
 new("/d/antioch/antioch2/obj/r_bracelet")->move(TO);
 if(!present("r_bracelet 2"))
  new("/d/antioch/antioch2/obj/r_bracelet")->move(TO);
 if(!present("r_bracelet 3"))
  new("/d/antioch/antioch2/obj/r_bracelet")->move(TO);

}
