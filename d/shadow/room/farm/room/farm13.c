#include <std.h>
#include "../farm.h"

inherit CROOM;

void pick_critters();

void create(){
   pick_critters();
   ::create();
   set_repop(35);
   set_terrain(GRASSLANDS);
   set_travel(RUTTED_TRACK);
   set_name("A shaded fountain");
   set_property("light",3);
   set_property("indoors",0);
   set_short("%^RESET%^%^CYAN%^A shaded fountain%^RESET%^");
   set_long("%^CYAN%^This small area surrounded by tall %^GREEN%^"+
      "grass %^CYAN%^is something of a hidden %^BOLD%^oasis"+
      "%^RESET%^%^CYAN%^.  The %^GREEN%^grass %^CYAN%^here is "+
      "much shorter than the surrounding area, which seems to "+
      "be a wall of sorts offering protection against the foul "+
      "scents of the farm.  Tall %^ORANGE%^willows %^CYAN%^"+
      "shade the area, offering their cool protection against "+
      "the elements.  In the center of the clearing is an "+
      "aging %^BOLD%^dragon fountain %^RESET%^%^CYAN%^of impressive "+
      "design.  Its low %^BOLD%^%^BLUE%^pool %^RESET%^%^CYAN%^"+
      "seems a perfect birdbath, but strangely no birds are "+
      "within it.  %^YELLOW%^Metallic songbirds %^RESET%^"+
      "%^CYAN%^crowd its ledge, however, and their song fills "+
      "the air with its harmony.  Two curving %^RESET%^"+
      "stone benches %^CYAN%^have been set on either side of the "+
      "%^BOLD%^fountain%^RESET%^%^CYAN%^, creating a pleasant "+
      "resting place.\n");
   set_smell("default","The clean fragrance of grass and trees surrounds you.");
   set_listen("default","The air is filled with the metallic melody of songbirds.");
   set_items(([
      ({"fountain","stone fountain","pool"}) : "The stone fountain "+
         "looks to be made of %^BOLD%^alabaster%^RESET%^.  The basin "+
         "is a shallow %^BOLD%^%^BLUE%^pool %^RESET%^that collects "+
         "water pouring from the dragon's open mouth.  The dragon is "+
         "positioned as if he's running down a mountainside, his claws "+
         "digging into the rock as he leans down to breathe 'fire'.  "+
         "His tail snakes up around the mountaintop, hinting at the "+
         "sheer side of the dragon.  Empty sockets stare where the "+
         "dragon's eyes should be.  They were no doubt gems that have "+
         "been plundered by adventurers.",
      ({"willow","willows","trees"}) : "The willow trees sweep their "+
         "long, flexible branches along the ground, offering shade "+
         "and fragrance to this hidden paradise.",
      "grass" : "The grass here is much shorter than the surrounding "+
         "area.  Surely someone must tend it.",
      ({"bench","benches","stone benches"}) : "The stone benches "+
         "curve to match the circle of the fountain.  Images of "+
         "slender dragons have been carved along the legs, echoing "+
         "the fountain's details.  They look to be fairly comfortable "+
         "places to <sit>."
   ]));
   set_exits(([
      "west" : PATHS"farm12",
      "northwest" : PATHS"farm8",
      "north" : PATHS"farm9",
      "northeast" : PATHS"farm10",
      "east" : PATHS"farm14"
   ]));
}

void pick_critters(){
   int i,j;
   i = random(3)+1;
   for(j=0;j<i;j++){
      new(MON"bird")->move(TO);
   }
}

void init(){
   ::init();
   add_action("sit_em","sit");
}

int sit_em(string str){
   if(!str) return 0;
   if(str == "bench" || str == "on bench"){
      tell_object(TP,"%^CYAN%^You settle onto the stone bench and "+
         "feel a little more relaxed.");
      tell_room(TO,"%^CYAN%^"+TPQCN+" sits on the stone bench.",TP);
      TP->force_me("pose %^CYAN%^sitting on a stone bench%^RESET%^");
      return 1;
   }
   if(str == "ground" || str == "grass" || str == "on ground" || str == "in grass"){
      tell_object(TP,"%^GREEN%^You take a seat on the short grass "+
         "and realize it's quite soft.");
      tell_room(TO,"%^GREEN%^"+TPQCN+" sits in the grass.",TP);
      TP->force_me("pose %^GREEN%^sitting in the grass%^RESET%^");
      return 1;
   }
   if(str == "ledge" || str == "on ledge"){
      tell_object(TP,"%^BOLD%^%^BLUE%^You sit on the ledge of the "+
         "fountain and hear the bubbling of the water.");
      tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" sits on the ledge "+
         "of the fountain.",TP);
      TP->force_me("pose %^BOLD%^%^BLUE%^sitting on the fountain ledge%^RESET%^");
      return 1;
   }
   tell_object(TP,"Where would you like to sit - bench, grass, or ledge?");
   return 1;
}