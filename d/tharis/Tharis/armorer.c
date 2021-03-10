//armorer.c - updated by Circe 9/24/03
//colored by Circe 9/13/04

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks",1);
   set_property("light",2);
   set_property("indoors",1);
   set_name("Tharis armorer");
   set_short("Tharis armorer");
   set_long(
@JAVAMAKER
%^YELLOW%^The Stone Breastplate%^RESET%^
This large room is dominated by a threesome of huge %^BOLD%^%^BLACK%^anvils 
%^RESET%^standing in the center of the room.  Huge %^BOLD%^%^RED%^fi%^YELLOW%^r%^RED%^es %^RESET%^roar and dance as the 
%^BOLD%^%^BLACK%^bellows %^RESET%^are pumped.  %^CYAN%^Water %^RESET%^steams as a %^BOLD%^breastplate %^RESET%^is cooled, 
while other workers are busy finishing up %^BOLD%^%^BLUE%^gauntlets %^RESET%^and %^BOLD%^shields%^RESET%^.  
To the left you see an %^MAGENTA%^older fellow %^RESET%^with a large %^YELLOW%^needle 
%^RESET%^and thick %^ORANGE%^leather cord %^RESET%^binding together two pieces of 
%^ORANGE%^leather%^RESET%^ to form a suit of armor.
JAVAMAKER
   );

   set_smell("default","The hot steam and the smoke from the wood-fed "+
      "fire combine in a heinous assault on your senses.");
   set_listen("default","You hear the crack of a hammer being applied "+
      "to steel on an unforgiving anvil.");
   set_items(([
      "leather" : "These raw pieces of hide will be tanned and worked "+
         "and then sewn into coifs, suits and skirts.  Suits of leather "+
         "armor and various bits of leather are everywhere in here, "+
         "indicating that leather armor is in high demand here in Tharis.",
      ({"anvils","anvil"}) : "These large pieces of cast iron wear the "+
         "scars of many years of hard labor.  "+
         "The hammer and the strength of the men using them combine "+
         "with these anvils to create "+
         "beauty from the ugly chunks of steel and iron and bronze "+
         "that come from the fires.",
      "bellows" : "These large leather bound devices feed air into "+
         "the fire making it roar with a new life and delight.",
      ({"fire","fires"}) : "Large fire pits stand near two of the "+
         "anvils, providing a place for the armorsmiths to heat the "+
         "metal before working with it.",
      ({"breastplate","shields","gauntlets"}) : "Various pieces of "+
         "armor lie in all stages of completion around the room.  It "+
         "seems several apprentices are working at all times to keep "+
         "the fires going.  Despite the pieces of metal armor, it "+
         "is clear from the display here that leather armor is much "+
         "more popular with the people who shop here."
   ]));

   set_exits(([
      "east" : ROOMS"main2",
   ]));
   set_door("armorer door", ROOMS"main2", "east", 0);
}


void reset(){
   ::reset();
   if(!present("linny")){
      find_object_or_load(MON"linny")->move(TO);
   }
}