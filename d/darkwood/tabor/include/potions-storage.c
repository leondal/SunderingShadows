#include <std.h>
#include "tabor.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
   set_short("Madhu's Potions Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
   set_exits((["down" : ROOMDIR+"potion1"]));
}

void reset()
{
   ::reset();
   if(!present("cure blindness"))

new("d/darkwood/tabor/obj/potions/cure_blindness")->move(TO);
   new("d/darkwood/tabor/obj/potions/cure_blindness")->move(TO);
   if(!present("gender potion"))
   if(!random(2)) new("d/darkwood/tabor/obj/potions/mfpotion")->move(TO);
   if(!random(2)) new("d/darkwood/tabor/obj/potions/fmpotion")->move(TO);
   if(!present("cure poison"))
   new("d/darkwood/tabor/obj/potions/cure_poison")->move(TO);
    if(!present("detect invisibility"))
   if(!random(3)) new("d/darkwood/tabor/obj/potions/det_invis")->move(TO);
   if(!random(3)) new("d/darkwood/tabor/obj/potions/det_invis")->move(TO);
   if(!present("extra heal"))
   new("d/darkwood/tabor/obj/potions/extra_heal")->move(TO);
   new("d/darkwood/tabor/obj/potions/extra_heal")->move(TO);
   new("d/darkwood/tabor/obj/potions/extra_heal")->move(TO);
   if(!present("hurt"))
   if(!random(2)) new("d/darkwood/tabor/obj/potions/hurt")->move(TO);
   if(!present("invisible"))
   if(!random(3)) new("d/darkwood/tabor/obj/potions/invisible")->move(TO);
   if(!random(3)) new("d/darkwood/tabor/obj/potions/invisible")->move(TO);
   if(!random(3)) new("d/darkwood/tabor/obj/potions/invisible")->move(TO);
   if(!present("paralyze"))
   if(!random(2)) new("d/darkwood/tabor/obj/potions/paralyze")->move(TO);
   if(!present("poison"))
   if(!random(2)) new("d/darkwood/tabor/obj/potions/poison")->move(TO);
   if(!random(2)) new("d/darkwood/tabor/obj/potions/poison")->move(TO);
   if(!present("raging heal"))
   new("d/darkwood/tabor/obj/potions/raging_heal")->move(TO);
   if(!present("weaken"))
   if(!random(4)) new("d/darkwood/tabor/obj/potions/weaken")->move(TO);
}
