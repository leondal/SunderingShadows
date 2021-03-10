//kite_quad.c - Four color kite for new Seneca.  
//Description by Lurue, coded by ~Circe~ 7/14/08
#include <std.h>
#include "../seneca.h"

inherit OBJECT;

#define COLOR1 ({"%^YELLOW%^yellow%^RESET%^","%^YELLOW%^lemon%^RESET%^","%^ORANGE%^mustard%^RESET%^","%^YELLOW%^yellow%^RESET%^-%^ORANGE%^orange%^RESET%^","%^ORANGE%^orange%^RESET%^","%^ORANGE%^salmon%^RESET%^","%^YELLOW%^gold%^RESET%^"})

#define COLOR2 ({"%^RED%^rust%^RESET%^","%^BOLD%^%^RED%^red%^RESET%^","%^BOLD%^%^RED%^red%^RESET%^-%^ORANGE%^orange%^RESET%^","%^BOLD%^%^MAGENTA%^pink%^RESET%^","%^RED%^maroon%^RESET%^","%^BOLD%^%^MAGENTA%^fuschia%^RESET%^","%^MAGENTA%^violet%^RESET%^","%^BOLD%^%^MAGENTA%^lilac%^RESET%^","%^BOLD%^%^MAGENTA%^lavender%^RESET%^","%^MAGENTA%^purple%^RESET%^","%^BOLD%^%^BLACK%^black%^RESET%^"})

#define COLOR3 ({"%^BOLD%^%^BLUE%^blue%^RESET%^","%^CYAN%^cornflower%^RESET%^","%^BOLD%^%^CYAN%^azure%^RESET%^","%^BOLD%^%^CYAN%^sky blue%^RESET%^","%^CYAN%^powder blue%^RESET%^","%^BLUE%^midnight blue%^RESET%^","%^BOLD%^%^BLUE%^royal blue%^RESET%^"})

#define COLOR4 ({"%^GREEN%^green%^RESET%^","%^YELLOW%^yellow%^RESET%^-%^GREEN%^green%^RESET%^","%^GREEN%^olive%^RESET%^","%^BOLD%^%^GREEN%^lime green%^RESET%^","%^GREEN%^mint%^RESET%^","%^BOLD%^%^GREEN%^sea green%^RESET%^","%^BOLD%^white%^RESET%^","%^BOLD%^silver%^RESET%^"})

int flying;

void create(){
string CLR1,CLR2,CLR3,CLR4;
   ::create();
   CLR1 = COLOR1[random(sizeof(COLOR1))];
   CLR2 = COLOR2[random(sizeof(COLOR2))];
   CLR3 = COLOR3[random(sizeof(COLOR3))];
   CLR4 = COLOR4[random(sizeof(COLOR4))];
   set_name("diamond kite");
   set_id(({"kite","diamond kite","four-color kite"}));
   set_short("%^BOLD%^%^WHITE%^A %^RED%^c%^RESET%^%^ORANGE%^o"+
      "%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^f%^RESET%^%^BLUE%^u"+
      "%^MAGENTA%^l %^BOLD%^%^WHITE%^diamond-shaped kite%^RESET%^");
   set_long("Diamond-shaped, this fanciful kite is made from four "+
      "triangles of colorful rice paper.  Each triangle is a "+
      "different color than the rest.  A combination of "+CLR1+", "+
      ""+CLR2+", "+CLR3+", and "+CLR4+" gives the kite a whimsical "+
      "appearance.  The vibrant triangles have been securely glued "+
      "down to a pair of crossed dowels that provide structure and "+
      "support without making the kite too heavy to fly.  Providing "+
      "the kite with extra color and maneuverability, a string of "+
      "%^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r"+
      "%^BLUE%^f%^RESET%^%^BLUE%^u%^MAGENTA%^l %^BOLD%^%^WHITE%^r"+
      "%^RED%^i%^RESET%^%^ORANGE%^b%^YELLOW%^b%^GREEN%^o%^CYAN%^n%^BLUE%^s "+
      "%^RESET%^has been secured to its tail.  At the center of the "+
      "kite, where the dowels cross, a long, thin string has been "+
      "tied, providing a way to tether the kite to a longer spindle "+
      "of string and allow the kite to be flown high in the sky.  "+
      "You can <launch> this kite to put it into the air, <fly> "+
      "it while it is there, and <reel> it in when you are finished.");
   set_weight(2);
   set_value(25);
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