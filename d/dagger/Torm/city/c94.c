//Took out key so people can't get locked inside *Styx* 3/9/02
//Also combined barkeeps and made the one do double duty and wander back and forth.

#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit BAR;

object *monsArray;

void create()  {
  ::create();
  set_property("indoors",1);
  set_property("no sticks", 1);
  monsArray = allocate(1);
  set_short( "The Seahorse restaurant"  );
  set_door("door",TCITY+"c93","north",0);
  set_long(
   "The Seahorse restaurant.\n"
  "  This restaurant shows a lot of love in its upkeep."
   "  The tables are all polished and what you can see of the kitchen through an open passboard shows excellent signs of cleanliness and competence from the cooks."
   "  A few citizens of Torm sit at the tables here, and it's obvious from their clothes this is one of the more exclusive places."
   "  There are flower arrangements at each table, and tasteful pictures hung on the walls."
  );
   set_smell("default","The smell of the flowers mingles with the sea spray.");
   set_listen("default","You can hear the waves crashing outside.");
   set_items(([
   "tables" : "The tables are very nice, the tops are done in pieces of tile that come together to show a picture. Some are just random patterns, others are beautiful flowers, and some are pictures of coral reefs and fish. On each table is a flower arrangement of some sort as well, all fresh.",
   ({"flowers","flower arrangement"}) : "A flower arrangement sits at the center of each table. Sometimes it is just a single rose of varying shades, usually for the smaller two-person tables that are off to the edges of the room. The larger tables have a variety of flowers in them, ranging from tulips to carnations and even some gardenias. Each vase is made out of crystal and cut in varying patterns, slender for the smaller arrangements, and a bit larger and more curved to hold more flowers.",
   ({"vase","vases"}) : "The vases that hold the flowers are all made out of beautiful crystal. The smaller vases are quite slender and would probably topple if more than one or two flowers was placed in them, they have beautiful designs of angular flowers carved into them. The larger vases tend to be more curved and rounded, able to hold more water for the thirsty flowers. They also have designs, but they are mostly geometric shapes.",
   "floor" : "The floor is kept carefully swept and free from dirt. There is no carpet here since it would be quickly ruined this close to the ocean, but the boards are sturdy and have been given a darker stain and coat of varnish to help preserve them.",
   ({"ceiling","chandeliers"}) : "A few delicate crystal chandeliers hang down from the ceiling. Dozens of white candles are lit, and the light from the candles refracts through the crystals, sending a dizzying but beautiful pattern out across the room.",
   ({"walls","paintings"}) : "Tasteful paintings are hung on the walls, adding a finishing touch to the gentle atmosphere this place cultivates.",
   ]));
  set_exits(([
  "north":TCITY+"c93",
  "east":TCITY+"c95",
  ]));
   if(query_night() == 1) {
      set_open("door",0);
   }
   else {
      set_open("door",1);
   }
}

void reset(){
   object ob;
   int i;
   ::reset();
//   i = sizeof(monsArray);
   for(i = 0;i < sizeof(monsArray);i++){
     if(!objectp(monsArray[i])) {
       ob = new(MON+"barkeep6");
       ob->move(TO);
       monsArray[i] = ob;
     }
   }
}

