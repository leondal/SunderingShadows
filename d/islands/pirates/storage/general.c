#include <std.h>;
#include "../piratedefs.h"
#include "/d/common/common.h"
inherit ROOM;

void create() {
   ::create();
   set_name("The Wide Open Port storage");
   set_short("The Wide Open Port storage");
   set_long("Storage room for The Wide Open Port.");
   set_property("no teleport",1);
}

void reset() {
   ::reset();
   if(!present("sack")) new(CMISC"sack")->move(TO);
   if(!present("pouch")) new(CMISC"pouch")->move(TO);
   if(!present("climb_tool")) new(CMISC"climb_tool")->move(TO);
   if(!present("rope")) new(CMISC"rope")->move(TO);
   if(!present("lkchest") && !random(3)) new(CMISC"lkchest")->move(TO);
   if(!present("deck")) new("/d/shadow/obj/misc/deckofcards")->move(TO);
   if(!present("die")) new("/d/shadow/obj/misc/die")->move(TO);
   if(!present("eyepatch")) new(CMISC"eyepatch")->move(TO);
   if(!present("torch") && !random(3)) new(CMISC"torch")->move(TO);
   if(!present("lantern")) new(CMISC"lantern")->move(TO);
   if(!present("bullseye") && !random(3)) new(CMISC"bullseye")->move(TO);
   if(!present("dark lantern") && !random(5)) new(CMISC"darkbeacon")->move(TO);
   if(!present("reg_oil")) new(CMISC"oil")->move(TO);
   if(!present("reg_oil 2")) new(CMISC"oil")->move(TO);
   if(!present("dark oil")) new(CMISC"darkoil")->move(TO);
   while(!present("dart 3")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("medium sheath")) new(CSHEATH"sheath_medium")->move(TO);
   if(!present("small sheath")) new(CSHEATH"sheath_small")->move(TO);
   if(!present("medium holster") && !random(3)) new(CSHEATH"sheath_mbludgeon")->move(TO);
   if(!present("leather")) new(CARMOR"leather")->move(TO);
   if(!present("sleather")) new("/d/dagger/kinaro/obj/armors/sleather")->move(TO);
   if(!present("buckler")) new(CARMOR"buckler")->move(TO);
   if(!present("dagger")) new(CWEAP"dagger")->move(TO); 
   if(!present("handaxe")) new(CWEAP"handaxe")->move(TO); 
   if(!present("knife")) new(CWEAP"knife")->move(TO);
   if(!present("scimitar")) new(CWEAP"scimitar")->move(TO); 
   if(!present("rapier")) new(CWEAP"rapier")->move(TO);
}
