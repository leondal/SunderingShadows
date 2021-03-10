#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe barnyard comes to an end here "+
      "on the edges of a light %^GREEN%^forest%^RESET%^.  Several "+
      "%^GREEN%^trees %^RESET%^have been cut down, leaving their "+
      "bare %^ORANGE%^stumps %^RESET%^next to a %^ORANGE%^woodpile%^RESET%^.\n");
   add_item(({"forest","trees","tree","stumps"}),"The forest does not "+
      "spread far, but it seems to be enough to supply this one small "+
      "house with ample wood.  Near the edges, you notice that smaller "+
      "trees are growing, evidence that the owner carefully plants to "+
      "replenish his stock.  The stumps have been cut neatly with an axe.");  
   add_item(({"pile","wood pile","woodpile"}),"The pile consists of wood "+
      "neatly quartered into two foot sections, perfect for feeding a "+
      "fire.  It definitely seems more is here than needed to heat the "+
      "house, though perhaps that is because the owner uses it for "+
      "his many experiments as well.");
   set_exits(([
      "north" : PATHS"farm19",
      "northwest" : PATHS"farm18",
      "west" : PATHS"farm16"
   ]));
}

void reset(){
   ::reset();
   if(!present("tin man") && !random(2)){
      new(MON"tinman")->move(TO);
   }
}
