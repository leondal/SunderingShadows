#include <std.h>;
#include "../defs.h"
#include "/d/common/common.h"
inherit ROOM;

void create() {
   ::create();
   set_name("Muuldaan general storage");
   set_short("Muuldaan general storage");
   set_long("Storage room for Muuldaan general store.");
   set_property("no teleport",1);
}

void reset() {
   ::reset();
   if(!present("sack")) new(CMISC"sack")->move(TO);
   if(!present("sack 2")) new(CMISC"sack")->move(TO);
   if(!present("climb_tool")) new(CMISC"climb_tool")->move(TO);
   if(!present("picks")) new(CMISC"thief_tools")->move(TO);
   if(!present("golden ring") && !random(5)) new("/d/azha/obj/mr_ring")->move(TO);
   if(!present("rope")) new(CMISC"rope")->move(TO);
   if(!present("rope 2")) new(CMISC"rope")->move(TO);
   if(!present("lkchest") && !random(2)) new(CMISC"lkchest")->move(TO);
   if(!present("deck")) new("/d/shadow/obj/misc/deckofcards")->move(TO);
   if(!present("die")) new("/d/shadow/obj/misc/die")->move(TO);
   if(!present("die 2")) new("/d/shadow/obj/misc/die")->move(TO);
   if(!present("torch") && !random(3)) new(CMISC"torch")->move(TO);
   if(!present("lantern")) new(CMISC"lantern")->move(TO);
   if(!present("dark lantern")) new(CMISC"darkbeacon")->move(TO);
   if(!present("dark lantern 2") && !random(2)) new(CMISC"darkbeacon")->move(TO);
   if(!present("reg_oil")) new(CMISC"oil")->move(TO);
   if(!present("dark oil")) new(CMISC"darkoil")->move(TO);
   if(!present("dark oil 2")) new(CMISC"darkoil")->move(TO);
}
