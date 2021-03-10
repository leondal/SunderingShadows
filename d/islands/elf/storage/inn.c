//4 shanta's shop
#include <std.h>
#include "../elf.h"
inherit ROOM;

void create(){
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_short("Shanta's food Storage Room");
        set_long("Various items are stored here.");
        set_property("no teleport",1);
        set_exits((["down" : ROOMS"inn"]));
}

void reset(){
 ::reset();
if(!present("nuts"))
 new("/d/antioch/antioch2/obj/nuts")->move(TO);

if(!present("dried fruits"))
 new("/d/antioch/antioch2/obj/dried_fruits")->move(TO);

if(!present("salad"))
 new(OBJ"salad")->move(TO);

if(!present("waybread"))
 new("/d/antioch/antioch2/obj/waybread")->move(TO);

if(!present("wine bottle"))
 new(OBJ"wine")->move(TO);
 
if(!present("cabbage"))
 new(OBJ"cabbage")->move(TO);

if(!present("broccoli"))
 new(OBJ"broccoli")->move(TO);
 
if(!present("berries"))
 new(OBJ"berries")->move(TO);
 
if(!present("mead"))
 new(OBJ"mead")->move(TO);
 
if(!present("nectar"))
 new(OBJ"nectar")->move(TO);
}
