// #include "/d/shadow/room/city/melnmarn.h"   short.h #includes common.h
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;

void create() {
  ::create();
    set_properties( ([
      "light" : 2,
      "indoors" : 1,
      "no teleport" : 1,
    ]) );
    set_short("Armor storage room");
    set_long(
    "You aren't supposed to be here, so get out."
    );
    set_exits( ([
      "up" : RPATH "armor.c",
    ]) );
}

void reset() {

::reset();
if(!present("chain"))
 new(ARMORDIR+"chain")->move(TO); 
if(!present("banded"))
 new(ARMORDIR+"banded")->move(TO); 
if(!present("scale"))
 new(ARMORDIR+"scale")->move(TO); 
if(!present("bronze"))
 new(ARMORDIR+"bronze")->move(TO); 
if(!present("plate"))
 new(ARMORDIR+"plate")->move(TO); 
if(!present("ring"))
 new(ARMORDIR+"ring")->move(TO); 
if(!present("padded"))
 new(ARMORDIR+"padded")->move(TO); 
if(!present("helm"))
 new(ARMORDIR+"helm")->move(TO); 
if(!present("shield"))
 new(ARMORDIR+"shield")->move(TO); 
if(!present("buckler"))
 new(ARMORDIR+"buckler")->move(TO); 
if(!present("sshield"))
 new(ARMORDIR+"sshield")->move(TO); 
if(!present("mshield"))
 new(ARMORDIR+"mshield")->move(TO); 
if(!present("leather"))
 new(ARMORDIR+"leather")->move(TO); 
if(!present("small fullplate"))
     new(ARMORDIR+"sfullplate")->move(TO);
if(!present("big fullplate"))
 new(ARMORDIR+"fullplate")->move(TO); 
if(!present("robe"))
 new(ARMORDIR+"robe")->move(TO); 

}

