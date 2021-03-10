inherit "std/room";

void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
set("short", "Elvanta's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
set_exits( (["up" : "/d/dagger/Elvanta/forest/roomgs_store"]) );
}

void reset() {

::reset();
if(!present("chest"))
 new("d/shadow/obj/misc/chest")->move(this_object()); 
if(!present("schest"))
 new("d/shadow/obj/misc/schest")->move(this_object()); 
if(!present("sack"))
 new("d/shadow/obj/misc/sack")->move(this_object()); 
if(!present("ssack"))
 new("d/shadow/obj/misc/ssack")->move(this_object()); 
if(!present("pouch"))
 new("d/shadow/obj/misc/pouch")->move(this_object()); 
if(!present("spouch"))
 new("d/shadow/obj/misc/spouch")->move(this_object()); 
if(!present("climb_tool"))
 new("d/shadow/obj/misc/climb_tool")->move(this_object()); 
if(!present("basket"))
 new("d/shadow/obj/misc/basket")->move(this_object()); 
if(!present("sbasket"))
 new("d/shadow/obj/misc/sbasket")->move(this_object()); 
if(!present("torch"))
 new("d/shadow/obj/misc/torch")->move(this_object()); 
if(!present("lantern"))
 new("d/shadow/obj/misc/lantern")->move(this_object()); 
if(!present("oil"))
 new("d/shadow/obj/misc/oil")->move(this_object()); 
if(!present("beacon"))
 new("d/shadow/obj/misc/beacon")->move(this_object()); 
if(!present("bullseye"))
 new("d/shadow/obj/misc/bullseye")->move(this_object()); 
if(!present("flint"))
 new("d/shadow/obj/misc/flint")->move(this_object()); 
if(!present("lkchest"))
 new("d/shadow/obj/misc/lkchest")->move(this_object()); 

             }
