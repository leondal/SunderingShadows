//inn_stairs.c by ~Circe~ 10/2/10
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Stairway of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Stairway of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Stairway of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "The %^ORANGE%^stairway%^RESET%^ winding upward through the %^BOLD%^%^MAGENTA%^"+
      "Tropical Breeze %^RESET%^features a bannister made of unfinished "+
      "%^BOLD%^driftwood%^RESET%^.  Paintings of %^ORANGE%^beach %^RESET%^and "+
      "%^CYAN%^fishing %^RESET%^scenes are scattered here and there in the "+
      "soft %^BOLD%^glow %^RESET%^of decorative %^BOLD%^%^GREEN%^g%^BLUE%^l%^CYAN%^a"+
      "%^WHITE%^s%^GREEN%^s%^BLUE%^ g%^CYAN%^l%^WHITE%^o%^GREEN%^b"+
      "%^BLUE%^e%^CYAN%^s%^RESET%^ that dangle from the ceiling.  To the south, an "+
      "archway leads into a large room filled with rows of beds, all neatly "+
      "made except for those currently occupied.\n");
   set_smell("default","The light fragrance of the sea seems to linger here.");
   set_listen("default","The soft murmur of conversation rises from the floor below.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"globe","globes","glass globe","glass globes"}) : "The "+
         "globes are made of blown glass in shades of %^BOLD%^%^BLUE%^"+
         "blue %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^, "+
         "reminiscent of the %^CYAN%^sea%^RESET%^ while the softly "+
         "glowing %^BOLD%^white light %^RESET%^brings to mind "+
         "images of whitecaps.  They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      ({"bannister","driftwood","driftwood bannister"}) : "The roughly finished "+
         "bannister is worn smooth in places from countless hands.  It is "+
         "bleached white from the sun, echoing the floor tiles.",
      ({"painting","paintings","scene","scenes"}) : "Various scenes, from "+
         "painted shells to images of families on the beach, are placed "+
         "at random intervals along the wall, giving the hallway a "+
         "comfortable, welcoming feeling.",
      ({"room","large room","bed","beds"}) : "The room to the south is "+
         "clearly some sort of common room where travelers may rent "+
         "a bed for the night.  Each bed provides a comfortable place "+
         "for one to rest, but not a lot of privacy."
   ]));
   set_exits(([
      "down" : ROOMS"inn_main",
      "south" : ROOMS"inn_common",
      "up" : ROOMS"inn_stairs2"
   ]));
}

