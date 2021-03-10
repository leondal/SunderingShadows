//kite_cloud.c - kite for new Seneca.  
//Description by Lurue, coded by ~Circe~ 7/15/08
#include <std.h>
#include "../seneca.h"

inherit OBJECT;

int flying;

void create(){
   ::create();
   set_name("cloud kite");
   set_id(({"kite","cloud kite","box kite","silk kite","blue silk kite"}));
   set_short("%^BOLD%^%^WHITE%^A %^CYAN%^silk %^BLACK%^box %^WHITE%^kite%^RESET%^");
   set_long("Created in the shape of a square box, this kite is "+
      "wrapped in a thin sheet of %^BOLD%^%^CYAN%^blue silk %^RESET%^"+
      "that has been painted with tiny %^BOLD%^clo%^CYAN%^u%^WHITE%^ds "+
      "%^RESET%^and %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i"+
      "%^GREEN%^n%^RESET%^%^CYAN%^b%^BOLD%^o%^BLUE%^w%^MAGENTA%^s%^RESET%^.  "+
      "The top and bottom of the kite are left open, exposing the "+
      "thin %^ORANGE%^wooden dowels %^RESET%^that form the structure "+
      "of this sky-bound kite.  A second box has been secured under "+
      "the first, this one made of %^BOLD%^%^BLACK%^black silk %^RESET%^"+
      "with %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r "+
      "%^BOLD%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s %^RESET%^decorating "+
      "its surface.  The two are held together via long %^ORANGE%^dowels "+
      "%^RESET%^in each corner, and are secured to a long tether string "+
      "that extends out from either end and loops down to tie off at a "+
      "third string that can be uncoiled from a spindle.  "+
      "You can <launch> this kite to put it into the air, <fly> "+
      "it while it is there, and <reel> it in when you are finished.");
   set_weight(2);
   set_value(50);
   flying = 0;
}

void init(){
   ::init();
   add_action("launch_em","launch");
   add_action("fly_em","fly");
   add_action("reel_em","reel");
}

int launch_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if((int)ETP->query_property("indoors") > 0){
      tell_object(TP,"You cannot fly a kite inside here!");
      return 1;
   }
   if(ETO != TP){
      tell_object(TP,"You need to pick up the kite first.");
      return 1;
   }
   if(flying){
      tell_object(TP,"The kite is already in the air!");
      return 1;
   }
   tell_object(TP,"You unreel the string and toss the kite into "+
      "the wind, launching it into the air.");
   tell_room(ETP,""+TPQCN+" unreels string from the kite and "+
      "tosses it into the wind, launching it.",TP);
   flying = 1;
   return 1;
}

int fly_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(!flying){
      tell_object(TP,"You must launch the kite first!");
      return 1;
   }
   tell_object(TP,"You tug upon the string, directing the kite "+
      "a bit further into the wind.");
   tell_room(ETP,""+TPQCN+" tugs upon the kite's string, directing "+
      "its movement into the wind.",TP);
   return 1;
}

int reel_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(!flying){
      tell_object(TP,"There is no need to reel in the kite when "+
         "you are already holding it.");
      return 1;
   }
   tell_object(TP,"You begin to reel in the string of the kite, "+
      "bringing it to the ground.");
   tell_room(ETP,""+TPQCN+" begins to reel in the kite's string, "+
      "bringing it to the ground.",TP);
   flying = 0;
   return 1;
}