//pirateweap

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("no teleport",1);

   set_short(
@JAVAMAKER
weapon storage
JAVAMAKER
   );

   set_long(
@JAVAMAKER
Weapon storage for Shawologon's arms market
JAVAMAKER
   );

   set_smell("default","");
   set_listen("default","");
   set_items(([
   ]));

   set_exits(([
   ]));

}


void reset(){
   ::reset();
if(!present("dagger"))
new(NORMWEP+"dagger")->move(TO); 
if(!present("whalebone"))
new(WEAP+"whalebone")->move(TO); 
if(!present("rapier"))
new(WEAP+"rapier")->move(TO); 
if(!present("saw edged dagger"))
new(WEAP+"sawdagger")->move(TO); 
if(!present("long dagger"))
new(WEAP+"longdagger")->move(TO);
}

void init(){
   ::init();

}







