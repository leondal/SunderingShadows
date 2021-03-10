#include "/d/ptalkin/ptalkin.h"
inherit "std/room";

void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
set_short("Ptlakin Flower shop storage room");
set_long("Supplies and such are stored here.");

set_exits(([
"up" : PROOM+"flower.c"]));
}
void reset() {

::reset();
if(!present("chocopeach"))
new("/d/ptalkin/items/chocopeach")->move(this_object());
if(!present("chocorose"))
new("/d/ptalkin/items/chocorose")->move(this_object());
if(!present("wroses"))
new("/d/ptalkin/items/wroses")->move(this_object());
if(!present("goldenslippers"))
new("/d/ptalkin/items/gslippers")->move(this_object());
if(!present("eveningstars"))
new("/d/ptalkin/items/eveningstars")->move(this_object());
if(!present("necklace"))
new("/d/ptalkin/items/necklace")->move(this_object());
if(!present("teddybear"))
new("/d/ptalkin/items/teddybear")->move(this_object());
if(!present("torque"))
new("/d/ptalkin/items/torque")->move(this_object());
             }
