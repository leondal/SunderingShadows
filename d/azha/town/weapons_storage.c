// Wespons Storeroom (wizards-only)
// Thorn@ShadowGate
// 4/13/95
// Town of Azha
// weapons_storage.c
// updated by Styx to get basic weapons from /d/common

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/common/common.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_property("no teleport",1);
	set_light(2);
	set_indoors(1);  
	set_short("Weapons Storeroom (wizards-only)");
  set_long(
@AZHA
%^BOLD%^Weapons Storeroom (wizards-only)%^RESET%^
  This room stores the weapons sold by merchants in Azha Market.
AZHA
    );
	set_exits(([
	"out" : "/d/azha/town/wroad",
  ] ));     
}

void reset() {

::reset();
if(!present("bastard"))                   new(CWEAP"bastard")->move(TO);
if(!present("bastard_two"))               new(CWEAP"bastard_two")->move(TO);
if(!present("battle axe"))                new(CWEAP"battle_axe")->move(TO);
if(!present("broad"))                     new(CWEAP"broad")->move(TO);
if(!present("dagger"))                    new(CWEAP"dagger")->move(TO);
if(!present("halberd"))                 new(AEQUIPDIR+"ihalberd")->move(TO);
if(!present("handaxe"))                   new(CWEAP"handaxe")->move(TO);
if(!present("longsword"))                 new(CWEAP"longsword")->move(TO);
if(!present("mace"))                      new(CWEAP"mace")->move(TO);
 
while(!present("scimitar 2")) { 
	new(AEQUIPDIR+"iscimitar")->move(TO);
}

while(!present("light recurved bow 3")) { 
	new(AEQUIPDIR+"recurved_bow")->move(TO);
}
while(!present("arrows 2")) {
      new(CLRWEAP"arrows")->move(TO);
}

if(!present("shortsword"))                new(CWEAP"shortsword")->move(TO);
if(!present("trident"))                   new(CWEAP"trident")->move(TO);
if(!present("two_hand_sword"))            new(CWEAP"two_hand_sword")->move(TO);
}
