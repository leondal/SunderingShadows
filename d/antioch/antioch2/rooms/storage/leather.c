#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Mydan's Leather Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"leather"]));
}

void reset()
{
	::reset();
if(!present("tall boots"))
 new(OBJ+"tall_boots")->move(TO);
if(!present("short boots"))
 new(OBJ+"short_boots")->move(TO);
if(!present("riding boots"))
 new(OBJ+"riding_boots")->move(TO);
if(!present("jacket"))
 new(OBJ+"jacket")->move(TO);
if(!present("deerskin boots"))
 new(OBJ+"deerskin_boots")->move(TO);
if(!present("gloves"))
 new(OBJ+"leather_gloves")->move(TO);
if(!present("tunic"))
 new(OBJ+"tunic")->move(TO);
if(!present("breeches"))
 new(OBJ+"breeches")->move(TO);
if(!present("leather"))
 new("/d/common/obj/armour/leather")->move(TO);
if(!present("studded"))
 new("/d/common/obj/armour/studded")->move(TO);
if(!present("hide"))
 new(OBJ+"hide")->move(TO);
if(!present("padded"))
 new(OBJ+"padded")->move(TO);
if(!present("leather coif"))
 new(OBJ+"leather_coif")->move(TO);
if(!present("leather shield"))
 new(OBJ+"leather_shield")->move(TO);
if(!present("deerskin shirt"))
 new(OBJ+"deerskin_shirt")->move(TO);
if(!present("deerskin skirt"))
 new(OBJ+"deerskin_skirt")->move(TO);
if(!present("deerskin boots"))
 new(OBJ+"deerskin_boots")->move(TO);
if(!present("leather belt"))
 new(OBJ+"leather_belt")->move(TO);
if(!present("leather sandals"))
 new(OBJ+"sandals")->move(TO);
if(!present("leather vest"))
 new(OBJ+"vest")->move(TO);
if(!present("leather bodice"))
 new(OBJ+"leather_bodice")->move(TO);
}
