#include <std.h>
#define ANTIOCH "/d/antioch/antioch2/obj/"+
inherit "/d/common/inherit/gs_storage.c";

void create() {
    ::create();
    set_property("no teleport",1);
    set_short("Tabor's Dry Goods Store Storage Room");
    set_long("Supplies and such are stored here and you should NOT be here.\n");
    set_exits( (["up" : "/d/darkwood/tabor/room/gstore"]) );
}

void reset() {
    ::reset();
if(!present("mixed nuts") && !random(3))
 new(ANTIOCH"nuts")->move(TO);
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
if(!present("waybread") && !random(6))
 new(ANTIOCH"waybread")->move(TO);
if(!present("waterskin") && !random(2))
 new(ANTIOCH"waterskin")->move(TO);
if(!present("cheese"))
 new(ANTIOCH"cheese")->move(TO);
if(!present("wine bottle") && !random(5))
 new(ANTIOCH"wine_bottle")->move(TO);
}
