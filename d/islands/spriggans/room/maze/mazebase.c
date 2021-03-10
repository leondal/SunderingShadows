#include <std.h>
#include <terrain.h>
#include "../../spriggan.h"
inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("A narrow tunnel");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air is stagnant and oppressive here beneath the trees.");
  set_listen("default","Strange bird calls and the buzzing of insects can be heard.");
  set_items(([     
      ({"canopy","tree canopy"}) : "%^GREEN%^The upper boughs of the trees "+
         "form a canopy high overhead.  It is so dense that little light "+
         "penetrates to fall to where you stand.",
      ({"foliage","decaying foliage"}) : "%^ORANGE%^The ground is littered with "+
         "a thick layer of decaying foliage from the trees and plants in the "+
         "area.  Combined with the bushes and the thick tree trunks, it can "+
         "make travel difficult."
  ]));
}

void init(){
   ::init();
   add_action("look","look");
}

int look(string str){
   string COLOR;
   if(str == "tree" || str == "trees" || str == "trunks"){
      switch(random(8)){
         case 0:  tell_object(TP,"%^GREEN%^Your gaze falls on a massive "+
                     "tree with a broad, %^ORANGE%^woody flanges %^GREEN%^"+
                     "at the base of its trunk.%^RESET%^");
                  break;
         case 1:  tell_object(TP,"%^BOLD%^%^GREEN%^Nearby, you see "+
                     "a tree with a knobbly trunk that has round "+
                     "%^RESET%^%^MAGENTA%^purple fruit %^BOLD%^"+
                     "%^GREEN%^growing directly from the trunk!%^RESET%^");
                  break;
         case 2:  tell_object(TP,"%^GREEN%^You catch sight of an "+
                     "enormous tree with serrated fern-like leaves!%^RESET%^");
                  break;
         case 3:  tell_object(TP,"%^ORANGE%^Before you, you see "+
                     "only a massive trunk that would take several "+
                     "people to stretch around.  It stretches up "+
                     "high into the canopy, as far as the eye can see.%^RESET%^");
                  break;
         case 4:  tell_object(TP,"%^YELLOW%^The tree before you features "+
                     "huge elephant ear-shaped leaves of green and yellow "+
                     "with odd %^RED%^red flowers %^YELLOW%^that look a "+
                     "bit like sea urchins.%^RESET%^");
                  break;
         default: tell_object(TP,"%^ORANGE%^Trees tower all around you, "+
                     "their thick trunks blocking out the majority "+
                     "of what light there might be above.%^RESET%^");
                  break;
      }
      tell_room(ETP,""+TPQCN+" looks over the trees.",TP);
      return 1;
   }
   if(str == "flowers" || str == "flower"){
      switch(random(8)){
         case 0:  tell_object(TP,"%^GREEN%^You spot a beautiful "+
                     "%^BOLD%^%^MAGENTA%^fuscia flower %^RESET%^"+
                     "%^GREEN%^shaped like a many-pointed star "+
                     "with wispy petals.%^RESET%^");
                  break;
         case 1:  tell_object(TP,"%^MAGENTA%^You see a deep "+
                     "purple bell-shaped flower with a "+
                     "brilliant %^YELLOW%^yellow %^RESET%^%^MAGENTA%^"+
                     "interior.%^RESET%^");
                  break;
         case 2:  tell_object(TP,"%^RESET%^%^ORANGE%^Your gaze comes "+
                     "to rest on a stunning %^BOLD%^%^MAGENTA%^slipper "+
                     "orchid %^RESET%^%^ORANGE%^with %^BOLD%^%^RED%^bold "+
                     "red spots%^RESET%^%^ORANGE%^.%^RESET%^");
                  break;
         case 3:  tell_object(TP,"%^GREEN%^You spot a large bush "+
                     "covered with brilliant %^BOLD%^%^RED%^"+
                     "poinsettias%^RESET%^%^GREEN%^!");
                  break;
         case 4:  tell_object(TP,"%^GREEN%^A beautiful crested "+
                     "%^YELLOW%^bird of %^MAGENTA%^paradise %^RESET%^"+
                     "%^GREEN%^is sprouting nearby.%^RESET%^");
                  break;
         default: tell_object(TP,"%^GREEN%^The dense jungle is filled "+
                     "with %^MAGENTA%^m%^BOLD%^u%^RED%^l%^YELLOW%^t%^GREEN%^i%^CYAN%^-"
                     "%^GREEN%^c%^YELLOW%^o%^RED%^l%^MAGENTA%^o%^RESET%^%^MAGENTA%^r"
                     "%^CYAN%^e%^BOLD%^d %^GREEN%^flowers %^RESET%^%^GREEN%^"+
                     "growing among the decaying foliage.%^RESET%^");
                  break;
      }
      tell_room(ETP,""+TPQCN+" looks over the flowers.",TP);
      return 1;
   }
   if(str == "eye" || str == "eyes"){
      switch(random(5)){
         case 0:  COLOR = "%^BOLD%^%^RED%^red";
                  break;
         case 1:  COLOR = "%^BOLD%^%^GREEN%^green";
                  break;
         case 2:  COLOR = "%^YELLOW%^yellow";
                  break;
         case 3:  COLOR = "%^BOLD%^%^WHITE%^silver";
                  break;
         default:  COLOR = "%^MAGENTA%^violet";
                  break;
      }
      tell_object(TP,"You peer around and see glittering "+COLOR+" eyes%^RESET%^ watching you.");
      return 1;
   }
   return 0;
}


string long_desc(){
    return "%^RESET%^%^GREEN%^This dense jungle is packed with "+
       "the %^ORANGE%^trunks %^GREEN%^of many types of trees, "+
       "making it impossible to see far.  The upper boughs of the "+
       "trees form a %^BOLD%^%^GREEN%^canopy %^RESET%^%^GREEN%^"+
       "overhead that blocks out all but the %^RESET%^weakest "+
       "light%^GREEN%^, regardless of the time of day.  "+
       "%^MAGENTA%^M%^BOLD%^u%^RED%^l%^YELLOW%^t%^GREEN%^i%^CYAN%^-"
       "%^GREEN%^c%^YELLOW%^o%^RED%^l%^MAGENTA%^o%^RESET%^%^MAGENTA%^r"
       "%^CYAN%^e%^BOLD%^d %^GREEN%^flowers %^RESET%^%^GREEN%^"+
       "crowd around the bases of the trees and poke up from the "+
       "%^YELLOW%^decaying foliage %^RESET%^%^GREEN%^littering "+
       "the ground.  You occasionally catch a glimpse of "+
       "%^BOLD%^eyes %^RESET%^%^GREEN%^peering out at you from "+
       "high up in the treetops or around the trunks.\n";
}