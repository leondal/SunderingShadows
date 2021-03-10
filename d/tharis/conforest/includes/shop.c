#include <std.h>
#include "../defs.h"
#include "/d/common/common.h"
inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",1);
  set_property("light",2);
  set_short("Trendamas' Armor Storage Room");
  set_long("Various items are stored here.");
  set_property("no teleport",1);
  set_exits((["down" : ROOMS+"c2.c"]));
}

void reset() {
::reset();
if(!present("helm"))             new(CARMOR"helm")->move(TO);
if(!present("shield"))           new(CARMOR"shield")->move(TO);
if(!present("two handed"))       new(CWEAP"two_hand_sword")->move(TO);
if(!present("two_battle_axe"))   new(OBJ+"two_battle_axe")->move(TO);
if(!present("bastard_two"))      new(CWEAP"bastard_two")->move(TO);
if(!present("lleather"))         new(OBJ+"lleather")->move(TO);
if(!present("lstudded"))         new(OBJ+"lstudded")->move(TO);
}
