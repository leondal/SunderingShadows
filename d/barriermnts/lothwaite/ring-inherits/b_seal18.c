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
      "ring from the following list.  NOTE: make sure it is lowercase.%^RESET%^\n\n");
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
   WF(MYSEAL18);
   WF(SEAL);
   ob = new(FILE);
   if(ob->move(TP) != MOVE_OK){
      ob->move(ETP);
   }
   write("Edric finishes your ring and gives it to you.");
   TO->remove();
   return;
}
