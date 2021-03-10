inherit "std/room";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
 	set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/deku/town/gs_store"]) );
}

void reset() {

::reset();
if(!present("chest"))
 new("d/shadow/obj/misc/chest")->move(this_object()); 
if(!present("sack"))
 new("d/shadow/obj/misc/sack")->move(this_object()); 
if(!present("ssack"))
 new("d/shadow/obj/misc/ssack")->move(this_object()); 
if(!present("pouch"))
 new("d/shadow/obj/misc/pouch")->move(this_object()); 
if(!present("spouch"))
 new("d/shadow/obj/misc/spouch")->move(this_object()); 
if(!present("rope"))
 new("d/shadow/obj/misc/rope")->move(this_object()); 
if(!present("torch"))
 new("d/shadow/obj/misc/torch")->move(this_object()); 
if(!present("lantern"))
 new("d/shadow/obj/misc/lantern")->move(this_object()); 
if(!present("oil"))
 new("d/shadow/obj/misc/oil")->move(this_object()); 
if(!present("flint"))
 new("d/shadow/obj/misc/flint")->move(this_object()); 

             }
