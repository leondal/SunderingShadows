// Armor Storeroom (wizards-only)
// Thorn@ShadowGate
// 4/13/95
// Town of Azha
// armor_storage.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_property("no teleport",1);
	set_light(2);
	set_indoors(1);  
	set_short("Armor Storeroom (wizards-only)");
  set_long(
@AZHA
%^BOLD%^Armor Storeroom (wizards-only)%^RESET%^
  This room stores the armor sold by merchants in Azha Market.
AZHA
    );
	set_exits(([
	"out" : "/d/azha/town/wroad",
  ] ));     
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
if(!present("fullplate"))
 new(ARMORDIR+"fullplate")->move(this_object());
//if(!present("tsarvani pack"))
 //new("/d/azha/obj/pack")->move(this_object());
}
