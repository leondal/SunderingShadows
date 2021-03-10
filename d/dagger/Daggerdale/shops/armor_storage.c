#include "/d/shadow/room/city/melnmarn.h"
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set("short", "Pennor's General Store Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : ROOMDIR+"armor"]) );
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
if(!present("padded"))
 new(ARMORDIR+"padded")->move(this_object()); 
if(!present("helm"))
 new(ARMORDIR+"helm")->move(this_object()); 
if(!present("shield"))
 new(ARMORDIR+"shield")->move(this_object()); 
if(!present("buckler"))
 new(ARMORDIR+"buckler")->move(this_object()); 
if(!present("sshield"))
 new(ARMORDIR+"sshield")->move(this_object()); 
if(!present("mshield"))
 new(ARMORDIR+"mshield")->move(this_object()); 
if(!present("leather"))
 new(ARMORDIR+"leather")->move(this_object()); 
if(!present("fullplate"))
 new(ARMORDIR+"fullplate")->move(this_object()); 
if(!present("robe"))
 new(ARMORDIR+"robe")->move(this_object()); 

}

