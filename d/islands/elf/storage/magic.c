//4 magic shop
#include <std.h>
#include "../elf.h"
inherit ROOM;

void create()
{
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_short("magic Storage Room");
        set_long("Various items are stored here.");
        set_property("no teleport",1);
        set_exits((["down" : ROOMS"store"]));
}

void reset()
{ ::reset();
if(!present("alchemist's fire"))
 new(OBJ"afire")->move(TO);
if(!present("stone"))
 new(OBJ"bioun")->move(TO);
if(!present("ring of magic protection"))
 new(OBJ"mr_ring")->move(TO);
if(!present("rage dart"))
 new(OBJ"dart")->move(TO);
if(!present("brooch"))
 new(OBJ"sbrooch")->move(TO);
if(!present("flower"))
 new(OBJ"flower")->move(TO);
if(!present("case"))
 new(OBJ"scroll_case")->move(TO);
if(!present("potion of cure blindness"))
 new("/d/common/obj/potion/cure_blindness")->move(TO);
if(!present("potion of detect invisibility"))
 new("/d/common/obj/potion/det_invis")->move(TO);
if(!present("seed of return"))
 new(OBJ"seed")->move(TO);
if(!present("paper"))
 new("/d/common/obj/misc/paper")->move(TO);
if(!present("parchment"))
 new("/d/common/obj/misc/parchment")->move(TO);
if(!present("canvas"))
 new("/d/common/obj/misc/canvas")->move(TO);
if(!present("book"))
 new("/d/common/obj/misc/book")->move(TO);
if(!present("quiver"))
 new("/d/common/obj/misc/quiver")->move(TO);
if(!present("iridescent ioun"))
 new(OBJ"iioun")->move(TO);
if(!present("wood sheath"))
 new(OBJ"sheath")->move(TO);
if(!present("sack"))
  new(OBJ"sack")->move(TO);
if(!present("larrows"))
  new("/d/common/obj/lrweapon/larrows")->move(TO);
if(!present("cloak"))
  new(OBJ"cloak")->move(TO);
if(!present("cologne"))
  new(OBJ"cologne")->move(TO);
}