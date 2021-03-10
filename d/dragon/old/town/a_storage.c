// /d/dragon/town/a_storage.c
#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set("short", "Pennor's General Store Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits((["up" : "/d/deku/town/armorer"]));
}

void reset() {

::reset();
if(!present("chain"))
 new(ARMORDIR+"chain")->move(this_object()); 
if(!present("banded"))
 new(ARMORDIR+"banded")->move(this_object()); 
if(!present("scale"))
 new(ARMORDIR+"scale")->move(this_object()); 
if(!present("bronze"))
 new(ARMORDIR+"bronze")->move(this_object()); 
if(!present("plate"))
 new(ARMORDIR+"plate")->move(this_object()); 
if(!present("ring"))
 new(ARMORDIR+"ring")->move(this_object()); 
if(!present("fullplate"))
 new(ARMORDIR+"fullplate")->move(this_object()); 

}

