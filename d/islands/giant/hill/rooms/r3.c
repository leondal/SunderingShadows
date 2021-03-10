#include "/d/islands/giant/giant.h"
inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("%^ORANGE%^Kiddie's Room%^RESET%^");
   set_long(
@TERRATO
   %^ORANGE%^%^BOLD%^This appears to be where the young giants play.  Although
for kids they look very viscious.  They are all armed with various "toys"
and about the size of the average Ogre.  Thier frolicking however the
moment you enter the room, and you can tell you now have thier FULL
attention.  Perhaps they are wondering what kinds of fun games they
could play with you!
TERRATO
   );

   set_smell("default","You smell dirty stinky children.");
   set_listen("default","You hear the yelling and bickering of many children.");

   set_exits(([
      "toys":"%^BOLD%^'Toys' for young giants apparently consist of many large pointed and blunt objects, the children uses these 'toys' to buold thier strength and stamina by sparring against each other%^RESET%^",
   ]));

   set_exits(([
      "west":HROOM+"h4.c",
   ]));
}

void reset(){
   ::reset();
   if(!present("kid")){
      new(HMON+"kid.c")->move(TO);
      new(HMON+"kid.c")->move(TO);
      new(HMON+"kid.c")->move(TO);
      new(HMON+"kid.c")->move(TO);
      new(HMON+"kid.c")->move(TO);
   }
}
