#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
  ::create();
  set_light(2);
  set_indoors(1);
  set_property("no teleport",1);
  set_name("Portal of Temples");
  set_short("Portal of Temples");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_long(
@DESC
You are in a large room, so large that you cannot see from one end to the other.  All along the walls you see shimmering portals, each with a name inscribed above. People are walking in and out of the portals, so you see that it is safe to enter.  Looking closer, you see that there appears to be one portal for each deity of the realm.
DESC
  );
  set_smell("default","The fragrance of many types of incense lingers here.");
  set_listen("default","You can hear various chants and conversations coming through the different portals.");
  set_exits(([
    "south":MAINTOWN"church",
    "akadi":NTEMPLE"akadi",
    "anhur":NTEMPLE"anhur",
    "auppenser":NTEMPLE"auppenser",
    "auril":NTEMPLE"auril",
    "bane":NTEMPLE"bane",
    "beshaba":NTEMPLE"beshaba",
    "cyric":NTEMPLE"cyric",
//    "eldath":NTEMPLE"eldath",
    "grumbar":NTEMPLE"grumbar",
    "helm":NTEMPLE"helm",
    "istishia":NTEMPLE"istishia",
    "kelemvor":NTEMPLE"kelemvor",
    "kossuth":NTEMPLE"kossuth",
    "lathander":NTEMPLE"lathander",
//    "loviatar":NTEMPLE"loviatar",
//Killing the Loviatar room since NF killed her in game
//Circe 12/1/07
    "malar":NTEMPLE"malar",
    "mask":NTEMPLE"mask",
    "mielikki":NTEMPLE"mielikki",
      "mystra":NTEMPLE"mystra",
    "oghma":NTEMPLE"oghma",
    "selune":NTEMPLE"selune",
    "shar":NTEMPLE"shar",
    "silvanus":NTEMPLE"silvanus",
    "shaundakul":NTEMPLE"shaundakul",
    "sune":NTEMPLE"sune",
    "talos":NTEMPLE"talos",
    "tempus":NTEMPLE"tempus",
    "torm":NTEMPLE"torm",
    "tymora":NTEMPLE"tymora",
    "tyr":NTEMPLE"tyr",
//    "xvim":NTEMPLE"xvim"
  ]));
}
