#include <std.h>
#include "tabor.h"
inherit ROOM;

void create(){
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Kelsey's Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMDIR+"new-tailor"]));
}


void reset(){
object obj;
   ::reset();
if(!present("wool tunic")){
 obj = new("/d/barriermnts/lothwaite/obj/wool_tunic");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("wool tunic 2")){
 obj = new("/d/barriermnts/lothwaite/obj/wool_tunic");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("wool tunic 3")){
 obj = new("/d/barriermnts/lothwaite/obj/wool_tunic");
 obj->set_size(random(3)+1);
 obj->move(TO);
}
if(!present("fleece vest")){
 obj = new("/d/barriermnts/lothwaite/obj/fleece_vest");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("thick leather gloves")){
 obj = new("/d/barriermnts/lothwaite/obj/gloves");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("leather breeches")){
 obj = new("/d/barriermnts/lothwaite/obj/leather_breeches");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("leather breeches 2")){
 obj = new("/d/barriermnts/lothwaite/obj/leather_breeches");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("leather breeches 3") && !random(2)){
 obj = new("/d/barriermnts/lothwaite/obj/leather_breeches");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("tall leather boots")){
 obj = new("/d/barriermnts/lothwaite/obj/boots");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("fine sandals")){
 obj = new("/d/barriermnts/lothwaite/obj/sandals");
 obj->set_size(2);
 obj->move(TO);
}
if(!present("robe"))
 new("/d/common/obj/armour/robe")->move(TO);
if(!present("robe 2"))
 new("/d/common/obj/armour/robe")->move(TO);
if(!present("randshoesxxx"))
 new("/d/common/obj/rand/r_shoes")->move(TO);
if(!present("cloak"))
 new("/d/common/obj/rand/cloak")->move(TO);
if(!present("cloak 2") && !random(2))
 new("/d/common/obj/rand/cloak")->move(TO);
if(!present("skirt"))
 new("/d/common/obj/rand/skirts")->move(TO);
if(!present("skirt 2"))
 new("/d/common/obj/rand/skirts")->move(TO);
if(!present("silk shirt"))
 new("/d/common/obj/rand/shirt")->move(TO);
if(!present("silk shirt 2"))
 new("/d/common/obj/rand/shirt")->move(TO);
}