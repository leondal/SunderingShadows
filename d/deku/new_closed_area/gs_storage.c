inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
 	set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["east" : "/d/deku/new/gs_store"]) );
}

void reset() {

::reset();
/*  changing to use the common inherit to save memory and quit using /d/shadow stuff
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
if(!present("rope"))
 new("d/shadow/obj/misc/rope")->move(this_object()); 
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
if(!present("tools"))
  new("d/tharis/obj/thief_tools.c")->move(this_object());
*/
             }
