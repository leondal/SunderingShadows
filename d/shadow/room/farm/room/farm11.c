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
   set_name("A pumpkin patch");
   set_property("light",3);
   set_property("indoors",0);
   set_short("%^RESET%^%^ORANGE%^A pumpkin patch%^RESET%^");
   set_long("A low, crumbling %^ORANGE%^wooden fence %^RESET%^"+
      "marks off the boundaries to this %^ORANGE%^pumpkin "+
      "patch%^RESET%^.  The patch seems largely forgotten, "+
      "with %^ORANGE%^pumpkins %^RESET%^growing large and "+
      "%^GREEN%^rotting %^RESET%^on the %^GREEN%^vine%^RESET%^.  "+
      "Most look as though they've been partially eaten, "+
      "and the profuse amounts of %^GREEN%^pig droppings %^RESET%^"+
      "give the likely reason why.  The %^ORANGE%^pumpkins "+
      "%^RESET%^are all sizes and in all stages of development, "+
      "from tiny seedlings to those that would be waist-high "+
      "to a gnome.  Strangely, many of the %^ORANGE%^pumpkins "+
      "%^RESET%^have grown in all kinds of crazy colors - from "+
      "%^MAGENTA%^purple%^RESET%^ and %^RED%^red %^RESET%^to "+
      "a vivid %^BOLD%^%^BLUE%^blue%^RESET%^!\n");
   set_smell("default","Phew...smells like no one's cleaned up "+
      "after the animals in a long time.");
   set_listen("default","The grunting of pigs sounds all around you.");
   set_items(([
      ({"pumpkins","pumpkin"}) : "The pumpkins grow in countless "+
         "colors and sizes, creating an interesting appearance.  "+
         "The vibrant %^GREEN%^green %^RESET%^of the vines hints "+
         "at the wonderful fertilizer the pig pooh has been.",
      ({"fence","wooden fence"}) : "The wooden fence is falling down "+
         "in many places, offering only a vague idea of the borders "+
         "of the pumpkin patch.  Clearly, this is the reason for "+
         "the pigs' apparent run of the place.",
      ({"pooh","pig pooh"}) : "Disgusting greens, browns, and blacks..."+
         "eww, why are you looking at that?!"
   ]));
   set_search("default","You find rotten bits of pumpkin and pig pooh.");
   set_exits(([
      "east" : PATHS"farm12",
      "north" : PATHS"farm7",
      "northeast" : PATHS"farm8"
   ]));
}

void pick_critters(){
     switch(random(3)){
        case 0:  set_monsters(({MON"pig"}),({2+random(2)}));
                 break;
        case 1:  set_monsters(({MON"pig",MON"turkey"}),({1,1}));
                 break;
        case 2:  set_monsters(({MON"pig"}),({3+random(3)}));
                 break;
        default: break;
     }
}