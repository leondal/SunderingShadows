//piratearmor

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
armor storage
JAVAMAKER
   );

   set_long(
@JAVAMAKER
Armor storage for Apilton's armor shop
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
if(!present("leather"))
new(NORMARM+"leather")->move(TO); 
if(!present("chain"))
new(NORMARM+"chain")->move(TO); 
if(!present("hide"))
new(NORMARM+"hide")->move(TO); 
if(!present("robe"))
new(NORMARM+"robe")->move(TO); 
if(!present("padded"))
new(NORMARM+"padded")->move(TO);
}

void init(){
   ::init();

}







