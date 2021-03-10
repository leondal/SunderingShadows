#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Trendamas' Armor Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"armor"]));
}

void reset()
{
	::reset();
if(!present("chain"))
 new("/d/common/obj/armour/chain")->move(TO);
if(!present("banded"))
 new("/d/common/obj/armour/banded")->move(TO);
if(!present("scale"))
 new("/d/common/obj/armour/scale")->move(TO);
if(!present("bronze"))
 new("/d/common/obj/armour/bronze")->move(TO);
if(!present("plate"))
 new("/d/common/obj/armour/plate")->move(TO);
if(!present("ring"))
 new("/d/common/obj/armour/ring")->move(TO);
if(!present("helm"))
 new("/d/common/obj/armour/helm")->move(TO);
if(!present("shield"))
 new("/d/common/obj/armour/shield")->move(TO);
if(!present("buckler"))
 new("/d/common/obj/armour/buckler")->move(TO);
if(!present("sshield"))
 new("/d/common/obj/armour/sshield")->move(TO);
if(!present("mshield"))
 new("/d/common/obj/armour/mshield")->move(TO);
if(!present("field"))
 new("/d/common/obj/armour/field")->move(TO);
if(!present("splint"))
 new("/d/common/obj/armour/splint")->move(TO);
if(!present("brigadine"))
 new("/d/common/obj/armour/brigadine")->move(TO);
 if(!random(4) && !present("fullplate"))
  new("/d/common/obj/armour/fullplate")->move(TO);
if(!random(3) && !present("breastplate"))
 new(OBJ+"breastplate")->move(TO);
}
