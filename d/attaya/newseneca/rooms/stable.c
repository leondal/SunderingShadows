// ~Circe~ 11/4/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit "/d/common/inherit/hitching_post";

#define ANIMALS ({"elephant","jaguar","boar","tiger","lion"})

int flag;
string ANIMAL;

void create(){
   ::create();
   if(!flag){
      ANIMAL = ANIMALS[random(sizeof(ANIMALS))];
      flag = 1;
   }
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",1);
   set_property("indoors",1);
   set_name("Stable of the Tropical Breeze Inn");
   set_short("Stable of the Tropical Breeze Inn");
   set_long("%^BOLD%^Stable of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "Sturdily crafted from quality wood, this stable is clearly meant "+
      "to withstand %^BOLD%^%^BLACK%^stormy weather %^RESET%^while "+
      "protecting the animals within.  The stable is neatly divided "+
      "into %^ORANGE%^stalls%^RESET%^, several of which seem larger "+
      "than necessary for a horse.  A %^ORANGE%^tethering post %^RESET%^"+
      "close to the door allows those who are making a quick stop a "+
      "place to secure their mounts.  Near the door, brightly painted "+
      "%^YELLOW%^shelves %^RESET%^hold materials needed for the care "+
      "of the mounts.  Bags of %^BOLD%^sugar cubes%^RESET%^, drying "+
      "%^ORANGE%^carrots%^RESET%^ and %^RED%^apples%^RESET%^, and "+
      "some odd-looking pieces of %^RED%^dried meat %^RESET%^are left "+
      "upon the shelf, providing a quick snack.  A %^ORANGE%^trough "+
      "%^RESET%^full of %^CYAN%^water %^RESET%^runs along the western "+
      "wall, and a few %^YELLOW%^bags of grain %^RESET%^are stored on "+
      "a shelf high above it.  In the southwestern corner are two tall "+
      "%^BOLD%^%^BLACK%^iron cages%^RESET%^, one of which holds a "+
      "saddled %^BOLD%^"+ANIMAL+"%^RESET%^!  The northern wall features "+
      "a door to the entrance hall of the inn.\n");
   set_smell("default","The strong aroma of hay and animals fills the air.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore above the snuffling of the mounts.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard "+
         "over the noises of the mounts.");
   }
   set_exits(([
     "east"  : ROOMS"skyline42",
     "north" : ROOMS"inn_entrance"
   ]));
   set_items(([
      ({"stall","stalls"}) : "%^ORANGE%^The stalls are separated by four "+
         "foot walls that end about a foot above the ground for ease "+
         "in cleaning.  Each stall has a feed bag hanging from the door "+
         "and clean hay spread along the floor.%^RESET%^",
      ({"shelves","sugar cubes","carrots","apples","dried meat","shelf"}) : "The "+
         "shelves are dyed in a %^YELLOW%^yellow hue %^RESET%^that would make "+
         "the brilliant inn proud.  Snacks for the mounts have been spread "+
         "atop them, giving owners a choice for a treat.  The dried meat "+
         "looks a little odd beside the typical horse treats of sugar cubes, "+
         "carrots, and apples.",
      ({"trough","water"}) : "The wooden trough has been sealed to prevent "+
         "the water from leaking through.  The water seems clear a cool, "+
         "a perfect place for thirsty mounts to drink.",
      ({"grain","bags of grain","bags"}) : "On a shelf above the trough, "+
         "well out of the reach of curious horses, sit several bags of "+
         "grain used by the stablehands for those mounts who are boarded here "+
         "for a time while their owners explore the city.",
      ({"cage","cages","iron cage","iron cages",""+ANIMAL+""}) : "%^BOLD%^"+
         "%^BLACK%^Two tall iron cages with thick bars are in the southeastern "+
         "corner, spaced rather far apart from each other and the stalls.  "+
         "The reason for this is readily apparent, as one holds an awe-"+
         "inspiring %^WHITE%^"+ANIMAL+"%^BLACK%^!%^RESET%^",
      ({"post","tethering post"}) : "Near the entrance from the street is a "+
         "tethering post in place of a stall.  The post is formed from two "+
         "uprights supporting a horizontal beam, giving a secure place "+
         "for owners to leave their mounts briefly."
   ]));
   set_door("sliding door","/d/attaya/newseneca/rooms/skyline42","east",0,0);
   set_door_description("sliding door","%^ORANGE%^This wide door "+
      "slides back, leaving a large opening through which to bring "+
      "in mounts.  The door is reinforced with iron bands and has "+
      "an even stronger outer door that can be let down in storms.%^RESET%^");
   set_door("stable door","/d/attaya/newseneca/rooms/inn_entrance","north",0,0);
   set_door_description("stable door","This small door leads through the "+
      "northern wall into the inn's entry hall, giving patrons easy "+
      "access to the comforts of the inn.");
   if(query_night()==1){
      set_open("sliding door",0);
      "/d/attaya/newseneca/rooms/skyline42"->set_open("sliding door",0);
   }else{
      set_open("sliding door",1);
      "/d/attaya/newseneca/rooms/skyline42"->set_open("sliding door",1);
   }
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
   set_open("stable door",1);
}
