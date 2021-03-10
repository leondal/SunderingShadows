//Coded by Bane//
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_property("no teleport",1);
    set_name("Systyquah's general store storage room");
    set_short("Systyquah's general store storage room");
    set_long(
	"This is a storage room.  If you are a mortal you shouldn't be here.  "+
	"Either teleport out or ask an immort to remove you."
    );
    set_property("light",1);
    set_property("indoors",1);
    set_smell("default","It smells of oil and old clothes.");
    set_listen("default","The room is silent.");
    set_exits( ([
    ]) );
}

void reset() {

    ::reset();
if(!present("chest"))
 new("d/common/obj/misc/chest")->move(TO); 
if(!present("sack"))
 new("d/common/obj/misc/sack")->move(TO); 
if(!present("ssack"))
 new("d/common/obj/misc/ssack")->move(TO); 
if(!present("pouch"))
 new("d/common/obj/misc/pouch")->move(TO); 
if(!present("climb_tool"))
 new("d/common/obj/misc/climb_tool")->move(TO); 
if(!present("torch"))
 new("d/common/obj/misc/torch")->move(TO); 
if(!present("lantern"))
 new("d/common/obj/misc/lantern")->move(TO); 
if(!present("oil"))
 new("d/common/obj/misc/oil")->move(TO); 
if(!present("bullseye"))
 new("d/common/obj/misc/bullseye")->move(TO); 
if(!present("sword"))
new("/d/common/obj/weapon/longsword")->move(TO);
if(!present("axe"))
new("/d/common/obj/weapon/battle_axe")->move(TO);
if(!present("dagger"))
new("/d/common/obj/weapon/dagger")->move(TO);
if(!present("banded"))
new("/d/common/obj/armour/banded")->move(TO);
if(!present("chain"))
new("/d/common/obj/armour/chain")->move(TO);
if(!present("hide"))
new("/d/common/obj/armour/hide")->move(TO);
if(!present("leather"))
new("/d/common/obj/armour/leather")->move(TO);
if(!present("helm"))
new("/d/common/obj/armour/helm")->move(TO);
if(!present("robe"))
new("/d/common/obj/armour/robe")->move(TO);
}
