inherit "std/room";
#include <std.h>
#include <objects.h>
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set_short("A storage room for the herbal shop.");
    set("long","Items of various degree are stored here.");
    set_exits( (["east" : "/d/koenig/town/herbshop1.c"]) );
}
void reset() {
::reset();           
if(!present("raging heal"))
   new("/d/koenig/town/items/raging_heal.c")->move(this_object());
   new("/d/koenig/town/items/raging_heal.c")->move(this_object());
   new("/d/koenig/town/items/raging_heal.c")->move(this_object());
   new("/d/koenig/town/items/raging_heal.c")->move(this_object());
if(!present("healing potion plus"))
   new("/d/koenig/town/items/heal1.c")->move(this_object());
   new("/d/koenig/town/items/heal1.c")->move(this_object());
   new("/d/koenig/town/items/heal1.c")->move(this_object());
   new("/d/koenig/town/items/heal1.c")->move(this_object());
if(!present("healing potion"))
   new("/d/koenig/town/items/heal2.c")->move(this_object());
   new("/d/koenig/town/items/heal2.c")->move(this_object());
   new("/d/koenig/town/items/heal2.c")->move(this_object());
   new("/d/koenig/town/items/heal2.c")->move(this_object());
if(!present("antidote"))
   new("/d/koenig/town/items/cure.c")->move(this_object());
   new("/d/koenig/town/items/cure.c")->move(this_object());
while(!present("packet of herbs 25"))
   new("/d/common/obj/brewing/herb_inherit")->move(TO);
if(!present("herb pouch"))
   new("/d/common/obj/brewing/herb_pouch")->move(TO);
if(!present("herb pouch 2"))
   new("/d/common/obj/brewing/herb_pouch")->move(TO);
if(!present("herb pouch 3") && !random(3))
   new("/d/common/obj/brewing/herb_pouch")->move(TO);
}

