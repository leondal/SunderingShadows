#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Kedaria's Jewelry Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"jeweler"]));
}

void reset()
{
	::reset();
if(!present("r_armband"))
 new(OBJ+"r_armband")->move(TO);
 if(!present("r_armband 2"))
  new(OBJ+"r_armband")->move(TO);
if(!present("r_ring"))
 new(OBJ+"r_ring")->move(TO);
 if(!present("r_ring 2"))
  new(OBJ+"r_ring")->move(TO);
 if(!present("r_ring 3"))
  new(OBJ+"r_ring")->move(TO);
	if(!present("earrings"))
	new("/d/shadow/room/meadows/obj/r_earrings.c")->move(TO);
	if(!present("earring 2"))
	new("/d/shadow/room/meadows/obj/r_earrings.c")->move(TO);
if(!present("r_bracelet"))
 new(OBJ+"r_bracelet")->move(TO);
 if(!present("r_bracelet 2"))
  new(OBJ+"r_bracelet")->move(TO);
 if(!present("r_bracelet 3"))
  new(OBJ+"r_bracelet")->move(TO);
if(!present("r_circlet"))
 new(OBJ+"r_circlet")->move(TO);
 if(!present("r_circlet 2"))
  new(OBJ+"r_circlet")->move(TO);
if(!present("r_broach"))
 new(OBJ+"r_broach")->move(TO);
 if(!present("r_broach 2"))
  new(OBJ+"r_broach")->move(TO);
if(!present("r_necklace"))
 new(OBJ+"r_necklace")->move(TO);
 if(!present("r_necklace 2"))
  new(OBJ+"r_necklace")->move(TO);
 if(!present("r_necklace 3"))
  new(OBJ+"r_necklace")->move(TO);
if(!random(5)) {
 if(!present("ruby ring"))
  new(OBJ+"ruby_ring")->move(TO);
 }
if(!random(3)) {
 if(!present("heart locket"))
  new(OBJ+"heart_locket")->move(TO);
 }
if(!random(6)) {
 if(!present("rhinestone diadem"))
  new(OBJ+"diadem")->move(TO);
 }
if(!random(8)) {
 if(!present("moonstone pendant"))
  new(OBJ+"pendant")->move(TO);
 }
if(!random(10)) {
 if(!present("star sapphire ring"))
  new(OBJ+"star_ring")->move(TO);
 }
if(!random(10)) {
 if(!present("sapphire necklace"))
   new(OBJ+"sapphire_necklace")->move(TO);
 }
 if(!present("medium jeweled sheath"))
  new("/d/common/obj/sheath/jeweled_msheath")->move(TO);
 if(!present("small jeweled sheath"))
  new("/d/common/obj/sheath/jeweled_ssheath")->move(TO);
 if(!present("large jeweled sheath"))
  new("/d/common/obj/sheath/jeweled_lsheath")->move(TO);
 if(!present("medium weapon holster"))
  new("/d/common/obj/sheath/jeweled_mholster")->move(TO);
 if(!present("medium weapon sleeve"))
  new("/d/common/obj/sheath/jeweled_mstaff")->move(TO);
 if(!present("large weapon sleeve"))
  new("/d/common/obj/sheath/jeweled_lstaff")->move(TO);
 if(!present("shield strap"))
  new("/d/common/obj/sheath/jeweled_strap")->move(TO);
}
