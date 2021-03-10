//ptrail1.c
#include <std.h>
#include "../kildare.h"

inherit TOUT;
void create(){
object ob;
   ::create();
   set_short("A mountain trail");
   set_long(
@CIRCE
%^CYAN%^The rocky footpath through the small village twists and turns 
past buildings, winding its way here.  To the northeast, a path 
continues to climb up the mountainside.  Quickly, the land 
becomes more treacherous and after climbing just a bit, the few 
evergreens begin to close in on the pathway, making it difficult 
to see very far.  The trees up higher in the mountains are foreboding, 
with skeletal limbs that dance on the wind.
CIRCE
   );

   set_smell("default","The clean air of the mountains is mixed with a scent of decay.");
   set_listen("default","Distant screeches can be heard over the roaring wind.");
   set_items(([
      (({"trail","footpath","path","foot path"})) : "The clean footpath of the village "+
         "begins to give way here, becoming covered with rubble.",
      (({"evergreens","tree","trees"})) : "Although few trees grow just here, not "+
         "much higher in the mountains are great forests of skeletal evergreens.  "+
         "Their limbs wave in the air, creating strange clicking noises.",
      (({"mountainside","mountain"})) : "The mountainside begins to rise sharply "+
         "here, accessible only by the rubble-strewn path.  Evergreens dot the "+
         "mountainside and begin to tower over the path."
   ]));

   set_exits(([
      "northeast" : ROOMS"ptrail2",
      "southwest" : TROOMS"path10"
      ]));
}

void reset(){
   ::reset();
   if(!present("area sign")) new("/d/common/obj/areas/kildare_sign")->move(TO);
}
