#include <std.h>
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Tonerra's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/islands/tonerra/village/hut1"]));
}

void reset() {
  ::reset();
  if(!present("torch"))
    new("d/shadow/obj/misc/torch")->move(this_object()); 
  if(!present("torch 2"))
    new("d/shadow/obj/misc/torch")->move(this_object()); 
  if(!present("rope"))
    new("d/shadow/obj/misc/rope")->move(this_object()); 
  if(!present("ssack"))
    new("d/shadow/obj/misc/sack")->move(this_object());
  if(!present("basket"))
    new("d/shadow/obj/misc/sbasket")->move(this_object());
  if(!present("lantern"))
    new("d/shadow/obj/misc/lantern")->move(this_object());
  if(!present("oil"))
    new("d/shadow/obj/misc/oil")->move(this_object());
    if(!present("gem")){
	  new("/d/islands/tonerra/obj/gem")->move(TO);
  new("/d/islands/tonerra/obj/gem")->move(TO);
}
}
