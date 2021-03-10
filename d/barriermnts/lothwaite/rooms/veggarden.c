//veggarden.c - Farming/Garden area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"
inherit ROOM;

void create(){
   ::create();
   set_indoors(0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("Lothwaite Vegetable Garden");
   set_short("Lothwaite Vegetable Garden");
   set_long("%^GREEN%^Though termed a 'garden', this fertile "+
      "portion of the valley actually holds a rather large "+
      "selection of %^BOLD%^vegetables%^RESET%^%^GREEN%^.  "+
      "A low %^RESET%^fence %^GREEN%^made of %^RESET%^stone "+
      "%^GREEN%^does little more than mark the outer boundaries "+
      "of the garden, which contains rows of %^ORANGE%^carrots%^GREEN%^, "+
      "%^BOLD%^cabbages%^RESET%^%^GREEN%^, %^RESET%^turnips%^GREEN%^, "+
      "and %^BOLD%^peas%^RESET%^%^GREEN%^.  It looks as though "+
      "the firbolgs of Lothwaite grow much of what they need here, "+
      "as well as gaining %^RED%^venison %^GREEN%^and other meats "+
      "from the surrounding forest.  The garden is bordered on the "+
      "north by a%^ORANGE%^ storage silo%^GREEN%^, while the path leads "+
      "south back into the village.  Just to the north of the "+
      "%^ORANGE%^silo%^GREEN%^, you can see the large %^CYAN%^"+
      "lake %^GREEN%^enjoyed by the citizens here.%^RESET%^\n");
   set_items(([
      ({"vegetables","carrots","cabbages","turnips","peas"}) : (:TO,"veggies":),
      ({"wall","stone wall","stone"}) : "The wall surrounding "+
         "the garden is only about three feet tall - quite small "+
         "to a firbolg.  It seems meant only to remind people "+
         "the garden is there rather than provide protection.",
      ({"silo","wooden silo","storage silo"}) : "%^ORANGE%^The wooden silo to the "+
         "north stands tall against the backdrop of the mountains.  "+
         "It looks as though grain is stored here, while "+
         "vegetables are stored in the small wooden room attached "+
         "to its base.",
      "lake" : "%^BOLD%^%^BLUE%^Lake Tearmann is to the north, "+
         "forming the northern boundary of the village.  From "+
         "here, you can just make out the water glistening and "+
         "hear the sounds of splashes."
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
   set_exits(([
      "south" : PATHEXIT"pathway21"
   ]));
}

string veggies(){
   string when = season(time());
   string tmp;
   switch(when){
      case "winter":  tmp = "Despite the snow all around the village, "+
                         "vegetables still flourish here.  It seems the "+
                         "firbolg affinity for nature has not diminished "+
                         "over time.";
                      break;
      case "spring":  tmp = "The first spring vegetables peek through "+
                         "the ground, brightening the area with their "+
                         "vibrant green leaves.";
                      break;
      case "summer":  tmp = "The Lothwaite vegetable garden is in full "+
                         "bloom, with all manner of vegetables covering "+
                         "the ground here.";
                      break;
      case "autumn":  tmp = "The normally lush vegetable garden is a little "+
                       "more sparse during the fall.  There sre still "+
                       "several varieities of vegetables growing, but "+
                       "they lack the vibrant colors of vegetables in "+
                       "the spring and summer";
                    break;
   }
   return tmp;
}
void reset(){
   ::reset();
   if(!query_night()){
      switch(random(4)){
         case 0:  tell_room(TO,"A young firbolg man hoes a few rows "+
                     "in the garden.");
                  break;
         case 1:  tell_room(TO,"A young firbolg maiden walks through "+
                     "the garden picking cabbages.");
                  break;
         case 2:  tell_room(TO,"Two firbolg children throw snap "+
                     "peas at one another instead of collecting them.");
                  break;
         default:  break;
      }
   }
}