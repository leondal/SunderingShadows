#include "/d/shadow/mon/melnmarn.h"

inherit "/d/common/inherit/wpn_storage";

void create() {
    ::create();
    set_property("no teleport",1);  
    set_properties((["light":0, "indoors":1]));
    set_short("Tabor Weapon Storage Room");
    set_long("Only supplies and such here.\n");
    set_exits( (["up" : "/d/darkwood/tabor/room/weapon"]) );
}

void reset() {
   ::reset();
   if(!present("double bladed sword"))
   new("/d/common/obj/weapon/double_bladed_sword")->move(TO);
}
