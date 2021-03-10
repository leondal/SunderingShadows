#include <std.h>
#include "../lothwaite.h"
#define ANTIOCH "/d/antioch/antioch2/obj/"+
inherit ROOM;

object obj;

void create() {
    ::create();
    set_property("no teleport",1);
    set_short("Lothwaite Clothing Store");
    set_long("Supplies and such are stored here and you should NOT be here.\n");
    set_exits( (["up" : PATHEXIT"clothing"]) );
}

void reset() {
    ::reset();
if(!present("deerskin boots") && !random(2)){
 obj = new(ANTIOCH"deerskin_boots");
 obj->set_size(3);
 obj->move(TO);
}
if(!present("wool tunic"))
 new(OBJ"wool_tunic")->move(TO);
if(!present("vest"))
 new(OBJ"fleece_vest")->move(TO);
if(!present("leather breeches"))
 new(OBJ"leather_breeches")->move(TO);
if(!present("tall leather boots"))
 new(OBJ"boots")->move(TO);
if(!present("dress")){
 obj = new(ANTIOCH"r_dress");
 obj->set_size(3);
 obj->move(TO);
}
if(!present("sandals"))
 new(OBJ"sandals")->move(TO);
if(!present("gloves"))
 new(OBJ"gloves")->move(TO);
if(!present("robe"))
 new(OBJ"robe")->move(TO);
}
