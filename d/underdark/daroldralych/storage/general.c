#include <std.h>;
#include "../defs.h"
#include "/d/common/common.h"
inherit ROOM;

#define ANTIOCH "/d/antioch/antioch2/obj/"+

void create() {
   ::create();
   set_name("General store storage");
   set_short("General store storage");
   set_long("Storage room for Darol'dralych general store.");
   set_property("no teleport",1);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
}

void reset() {
   ::reset();
   if(!present("sack")) new(CMISC"sack")->move(TO);
   if(!present("sack 2")) new(CMISC"sack")->move(TO);
   if(!present("backpack") && random(3)) new(CMISC"backpack")->move(TO);
   if(!present("climb_tool")) new(CMISC"climb_tool")->move(TO);
   if(!present("rope")) new(CMISC"rope")->move(TO);
   if(!present("rope 2")) new(CMISC"rope")->move(TO);
   if(!present("deck")) new("/d/shadow/obj/misc/deckofcards")->move(TO);
   if(!present("die")) new("/d/shadow/obj/misc/die")->move(TO);
   if(!present("dark lantern")) new(CMISC"darkbeacon")->move(TO);
   while(!present("dark oil 3")) new(CMISC"darkoil")->move(TO);
   if(!present("bookxxx")) new(CMISC"book")->move(TO);
   while(!present("paper 4")) new(CMISC"paper")->move(TO);
   if(!present("flint") && !random(2)) new(CMISC"flint")->move(TO);
   if(!present("standard rations") && !random(2))
     new(ANTIOCH"standard_rations")->move(TO);
   if(!present("dried meat"))
     new(ANTIOCH"dried_meat")->move(TO);
   if(!present("cheese"))
     new(ANTIOCH"cheese")->move(TO);
   if(!present("waterskin"))
     new(ANTIOCH"waterskin")->move(TO);
   if(!present("wine bottle") && !random(5))
     new(ANTIOCH"wine_bottle")->move(TO);
}
