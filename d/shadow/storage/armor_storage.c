#include "/d/common/common.h"
#define ROOMDIR "/d/shadow/room/city/"

// inherit ROOM; changing to use the common inherit & moving to a storage dir
// *Styx* 12/31/03, last change 11/22/01

inherit "/d/common/inherit/armor_storage_full.c";

void create() {
  ::create();
    set_exits( (["up" : ROOMDIR+"armor"]) );
}

void reset() {
   ::reset();
  if(!present("small fullplate"))
     new(CARMOUR"sfullplate")->move(this_object());
/*
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
if(!present("medium fullplate"))
 new(ARMORDIR+"fullplate")->move(TO); 
if(!present("robe"))
 new(ARMORDIR+"robe")->move(TO); 
*/
}

