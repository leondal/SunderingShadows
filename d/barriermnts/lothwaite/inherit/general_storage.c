#include <std.h>
#include "../lothwaite.h"
#define ANTIOCH "/d/antioch/antioch2/obj/"+
inherit "/d/common/inherit/gs_storage.c";

void create() {
    ::create();
    set_property("no teleport",1);
    set_short("Lothwaite Traiding Post Storage Room");
    set_long("Supplies and such are stored here and you should NOT be here.\n");
    set_exits( (["up" : PATHEXIT"general"]) );
}

void reset() {
    ::reset();
if(!present("dried fruits") && !random(3))
 new(ANTIOCH"dried_fruits")->move(TO);
if(!present("iron rations") && !random(4))
 new(ANTIOCH"iron_rations")->move(TO);
if(!present("standard rations") && !random(2))
 new(ANTIOCH"standard_rations")->move(TO);
if(!present("dry rations") && !random(3))
 new(ANTIOCH"dry_rations")->move(TO);
if(!present("dried meat"))
 new(ANTIOCH"dried_meat")->move(TO);
if(!present("jerky")&& !random(3))
 new(ANTIOCH"rawhide")->move(TO);
if(!present("hard tack") && !random(4))
 new(ANTIOCH"hardtack")->move(TO);
if(!present("cheese"))
 new(ANTIOCH"cheese")->move(TO);
if(!present("fishing rod"))
 new("/d/common/obj/misc/fishing_rod")->move(TO);
if(!present("fishing rod 2"))
 new("/d/common/obj/misc/fishing_rod")->move(TO);
if(!present("drinking horn"))
 new(OBJ"drinking_horn")->move(TO);
if(!present("drinking horn 2") && !random(2))
 new(OBJ"drinking_horn")->move(TO);
}
