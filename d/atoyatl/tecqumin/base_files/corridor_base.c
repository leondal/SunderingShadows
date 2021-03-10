#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;

string long_desc();

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 0);
  set_short("A low, arched stone corridor");
  set_long((:TO, "long_desc":));
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_smell("default","The air is still and humid, carrying hints of the perfumes of jungle plants");
  set_listen("default","The busy noises of the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ are reduced to muffled whispers from outside.");
  set_items( ([     
       ({ "sconce", "sconces", "torch", "torches", "torch sconce", "torch sconces" }): 
    "The sconces on the walls are empty, the torches they once held"
   +"  having long since rotted away.",
   ({"ceiling", "low ceiling", "arched ceiling", "arch"}): "The low height and"
   +" arch of the ceiling makes you realise you must be in the part of the"
   +" building that represents one of the forelegs of the %^ORANGE%^j%^BOLD%^%^BLACK%^"
   +"a%^RESET%^%^ORANGE%^g%^BOLD%^u%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^"
   +" that the whole structure is modelled on.",
   ({"L shape", "shape", "turn", "ninety degree turn", 
      "right angle", "ninety degrees"}): "You"
    +" realise the the shape of the corridor is a stylised version of one"
    +" of the forelegs of the %^BOLD%^%^YELLOW%^j%^RESET%^%^ORANGE%^u"
    +"%^BOLD%^%^YELLOW%^ng%^RESET%^%^ORANGE%^l%^BOLD%^%^YELLOW%^e"
    +" c%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^t%^RESET%^ that the"
    +" whole building represents"
   ]) );
}

void init(){
  ::init();

}

void reset(){
  ::reset();
}

string long_desc(){
  string desc;
  desc = "This stone walled corridor is in an L shape, turning"
    +" ninety degrees from east-west to north-south part way along its"
    +" length. It has an arched ceiling and a flat floor. The walls are lined"
    +" with torch sconces.";
  return desc;
}
