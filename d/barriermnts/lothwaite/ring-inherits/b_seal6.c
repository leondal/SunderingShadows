//signet rings for Lothwaite - by Circe 6/21/04
#include <std.h>
#include <move.h>
#include <security.h>
#include "../lothwaite.h"
#include "signet_ring.h"

#define LETTERS ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"})

#define BACKGROUNDS ({"waterfall","forest","valley","mountains","desert","city",\
"wheat field","caves","dwarven city","treetop village","evergreens","ocean",\
"monolith","full moon","crescent moon","steppe","grasslands","winding path",\
"justice scales","pyramid","ivy","flames","iceberg","snowcapped peak","maze",\
"chess board","castle"})
inherit OBJECT;

string FILE;

void finish();

int save_me(string file){ return 1;}

void exit(){
   TP->add_money("gold",2500);
   tell_object(TP,"Edric returns your 2500 gold coins.");
   rm(FILE);
   remove();
}

void set_file_name(string f) {
    FILE = f;
}

void init(){
   ::init();
   seteuid(UID_RESTORE);
   WF(HEADER);
   WF(NAME);
   WF(ID);
   WF(SHORT);
   write("%^BOLD%^%^RED%^NOTE: %^WHITE%^Once you complete the order "+
      "for a ring, you will be unable to change the design - %^RED%^EVER"+
      "%^WHITE%^.  Be sure you choose something that fits your character.  "+
      "Use ** to cancel your order.%^RESET%^\n\n");
   write("%^BOLD%^Please choose the initial you would like for your "+
      "ring from the list below.  Please make sure the letter you type "+
      "is in lowercase (it will be capitalized on the ring).\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
   );
   input_to("myinitial");
   return 1;
}

void myinitial(string str){
   if(!str){
      write("%^BOLD%^You must choose an initial for your ring.  If you want "+
         "to cancel your order, use **.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
      );
      input_to("myinitial");
      return;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,LETTERS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid letter!\n");
      write("%^BOLD%^Please choose the initial you would like to have featured on your "+
      "ring from the following list.  NOTE: make sure it is lowercase.  "+
      "Use ** to cancel your order.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
      );
      input_to("myinitial");
      return;
   }
   str = "a stylized %^CYAN%^"+capitalize(str)+"%^RESET%^";
   WF(MYINITIAL1(str));
   write("%^BOLD%^Please choose the second initial you would like for your "+
      "ring from the list below.  Please make sure the letter you type "+
      "is in lowercase (it will be capitalized on the ring).  "+
      "Use ** to cancel your order.\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
   );
   input_to("myinitial2");
   return 1;
}

void myinitial2(string str){
   if(!str){
      write("%^BOLD%^You must choose the second initial for your ring.  If you want "+
         "to cancel your order, use **.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
      );
      input_to("myinitial2");
      return;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,LETTERS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid letter!\n");
      write("%^BOLD%^Please choose the second initial you would like "+
      "to have featured on your ring from the following list.  "+
      "NOTE: make sure it is lowercase.  Use ** to cancel your order.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
      );
      input_to("myinitial2");
      return;
   }
   str = "a stylized %^CYAN%^"+capitalize(str)+"%^RESET%^";
   WF(MYINITIAL2(str));
   write("%^BOLD%^Please choose the background you would like for "+
      "your ring from the list below.  Use ** to cancel your order.\n");
   write("%^GREEN%^---------------------- %^YELLOW%^Backgrounds %^RESET%^%^GREEN%^-----------------------");
   write(
@CIRCE
   waterfall      forest         valley         mountains
   desert         city           caves          wheat field
   evergreens     ocean          monolith       dwarven city
   full moon      crescent moon  steppe         treetop village
   grasslands     winding path   pyramid        justice scales
   ivy            flames         iceberg        snowcapped peak
   maze           chess board    castle
CIRCE
   );
   input_to("bgchoice");
   return;
}

void bgchoice(string str){
   if(str == "**"){
      return exit();
   }
   if(member_array(str,BACKGROUNDS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid background choice!\n");
      write("%^BOLD%^Please choose a background from the following list.\n\n");
      write("%^GREEN%^---------------------- %^YELLOW%^Backgrounds %^RESET%^%^GREEN%^-----------------------");
      write(
@CIRCE
   waterfall      forest         valley         mountains
   desert         city           caves          wheat field
   evergreens     ocean          monolith       dwarven city
   full moon      crescent moon  steppe         treetop village
   grasslands     winding path   pyramid        justice scales
   ivy            flames         iceberg        snowcapped peak
   maze           chess board    castle
CIRCE
      );
      input_to("bgchoice");
      return;
   }
   switch(str){
      case "waterfall":  str = "a serene, cascading %^CYAN%^waterfall%^RESET%^";
                   break;
      case "forest":  str = "a vast %^GREEN%^hardwood forest%^RESET%^";
                   break;
      case "valley":  str = "a wide, %^BOLD%^%^GREEN%^peaceful vale%^RESET%^";
                   break;
      case "mountains":  str = "%^ORANGE%^rocky mountains %^RESET%^"+
                   "rising against the %^CYAN%^sky%^RESET%^";
                   break;
      case "desert":  str = "a wide, %^ORANGE%^sandy desert %^RESET%^"+
                   "braced by tall %^YELLOW%^dunes%^RESET%^";
                   break;
      case "city":  str = "a sprawling %^BOLD%^walled city %^RESET%^"+
                   "with a %^CYAN%^tower %^RESET%^rising high";
                   break;
      case "wheat field":  str = "a quiet %^GREEN%^wheat field %^RESET%^"+
                   "with a %^ORANGE%^farmhouse %^RESET%^nearby";
                   break;
      case "caves":  str = "a gaping %^BOLD%^%^BLACK%^cave %^RESET%^"+
                   "leading into the %^ORANGE%^mountainside%^RESET%^";
                   break;
      case "dwarven city":  str = "the %^BOLD%^stone archways %^RESET%^of a dwarven city";
                   break;
      case "treetop village":  str = "the quiet peace of an elven "+
                   "%^GREEN%^treetop village%^RESET%^";
                   break;
      case "evergreens":  str = "a dense %^GREEN%^evergreen forest%^RESET%^";
                   break;
      case "ocean":  str = "a %^ORANGE%^ship %^RESET%^dancing upon "+
                   "the %^CYAN%^ocean%^RESET%^";
                   break;
      case "monolith":  str = "a solitary %^BOLD%^monolith %^RESET%^"+
                   "in a flat %^GREEN%^field%^RESET%^";
                   break;
      case "full moon":  str = "a full risen %^BOLD%^moon %^RESET%^in a cloudless sky";
                   break;
      case "crescent moon":  str = "a pale %^BOLD%^%^BLACK%^crescent "+
                   "moon%^RESET%^ veiled by clouds";
                   break;
      case "steppe":  str = "a %^ORANGE%^sandy steppe %^RESET%^with "+
                   "a few patches of %^GREEN%^grass%^RESET%^";
                   break;
      case "grasslands":  str = "lush, flat %^BOLD%^%^GREEN%^grasslands "+
                   "%^RESET%^with a single %^GREEN%^tree %^RESET%^in the distance";
                   break;
      case "winding path":  str = "a narrow %^ORANGE%^path %^RESET%^"+
                   "winding through rolling hills";
                   break;
      case "justice scales":  str = "the evenly balanced %^YELLOW%^"+
                   "scales of justice%^RESET%^";
                   break;
      case "pyramid":  str = "an aged %^YELLOW%^pyramid %^RESET%^"+
                   "rising from the %^ORANGE%^desert%^RESET%^";
                   break;
      case "ivy":  str = "a simple border of tangled %^GREEN%^ivy%^RESET%^";
                   break;
      case "flames":  str = "a writhing mass of %^BOLD%^%^RED%^fl"+
                   "%^YELLOW%^am%^RED%^es%^RESET%^";
                   break;
      case "iceberg":  str = "a massive %^BOLD%^iceberg %^RESET%^"+
                   "rising out of the %^CYAN%^ocean%^RESET%^";
                   break;
      case "snowcapped peak":  str = "a lone %^ORANGE%^mountain "+
                   "%^RESET%^with a %^BOLD%^snowcapped peak%^RESET%^";
                   break;
      case "maze":  str = "an intricate %^BOLD%^maze %^RESET%^viewed from above";
                   break;
      case "chess board":  str = "a finely crafted %^BOLD%^c%^BLACK%^h"+
                   "%^WHITE%^e%^BLACK%^s%^WHITE%^s board%^RESET%^";
                   break;
      case "castle":  str = "a sturdy %^BOLD%^castle %^RESET%^"+
                   "looming against the %^CYAN%^sky%^RESET%^";
                   break;
   }
   WF(MYBACK(str));
   finish();
}

void finish(){
object ob;
   WF(LONG);
   WF(WEIGHT);
   WF(VALUE);
   WF(AC);
   WF(LIMBS);
   WF(TYPE);
   WF(LORE);
   WF(LOREDIFF);
   WF(CLOSE);
   WF(INI);
   WF(INI2);
   WF(MYSEAL6);
   WF(SEAL);
   ob = new(FILE);
   if(ob->move(TP) != MOVE_OK){
      ob->move(ETP);
   }
   write("Edric finishes your ring and gives it to you.");
   TO->remove();
   return;
}
