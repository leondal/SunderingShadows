#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Felawyr's Weapon Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"weapon"]));
}

void reset()
{
	::reset();
if(!present("bastard"))
 new("/d/common/obj/weapon/bastard")->move(TO);
if(!present("battle_axe"))
 new("/d/common/obj/weapon/battle_axe")->move(TO);
if(!present("broad"))
 new("/d/common/obj/weapon/broad")->move(TO);
if(!present("club"))
 new("/d/common/obj/weapon/club")->move(TO);
if(!present("dagger"))
 new("/d/common/obj/weapon/dagger")->move(TO);
if(!present("handaxe"))
 new("/d/common/obj/weapon/handaxe")->move(TO);
if(!present("knife"))
 new("/d/common/obj/weapon/knife")->move(TO);
if(!present("longsword"))
 new("/d/common/obj/weapon/longsword")->move(TO);
if(!present("mace"))
 new("/d/common/obj/weapon/mace")->move(TO);
if(!present("morningstar"))
 new("/d/common/obj/weapon/morningstar")->move(TO);
if(!present("staff"))
 new(OBJ+"staff")->move(TO);
if(!present("quarter_staff"))
 new("/d/common/obj/weapon/quarter_staff")->move(TO);
if(!present("scimitar"))
 new("/d/common/obj/weapon/scimitar")->move(TO);
if(!present("shortsword"))
 new("/d/common/obj/weapon/shortsword")->move(TO);
if(!present("trident"))
 new("/d/common/obj/weapon/trident")->move(TO);
if(!present("warhammer"))
 new("/d/common/obj/weapon/warhammer")->move(TO);
if(!present("medium spear"))
 new("/d/common/obj/weapon/mspear")->move(TO);
if(!present("halberd"))
 new("/d/common/obj/weapon/halberd")->move(TO);
if(!present("pick"))
 new("/d/common/obj/weapon/pick")->move(TO);
if(!present("sickle"))
 new("/d/common/obj/weapon/sickle")->move(TO);
if(!present("two_hand_sword"))
 new("/d/common/obj/weapon/two_hand_sword")->move(TO);
if(!present("scythe"))
 new("/d/common/obj/weapon/scythe")->move(TO);
if(!present("bastard_two"))
 new("/d/common/obj/weapon/bastard_two")->move(TO);
if(!present("longbow"))
 new("/d/common/obj/lrweapon/longbow")->move(TO);
if(!present("larrows"))
 new("/d/common/obj/lrweapon/larrows")->move(TO);
if(!present("knuckles"))
 new(OBJ+"knuckles")->move(TO);
}
