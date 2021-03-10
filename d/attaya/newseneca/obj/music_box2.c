//music_box2.c - coded by ~Circe~, descriptions by Lurue
//for new Seneca 1/6/08
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("music box");
   set_short("%^BOLD%^%^CYAN%^a glass-blown music box%^RESET%^");
   set_id(({"musicbox","music box","glass music box","carousel","carousel music box","glass-blown music box"}));
   set_long("%^RESET%^%^CYAN%^Three glass blown horses circle "+
      "around a center %^BOLD%^%^MAGENTA%^pink %^RESET%^%^CYAN%^"+
      "and %^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^spire in this "+
      "delicate carousel themed music box.  One horse is tinted "+
      "%^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^, a second is tinted "+
      "%^BOLD%^%^MAGENTA%^pink %^RESET%^%^CYAN%^and the third is "+
      "left its natural %^WHITE%^%^BOLD%^clear %^RESET%^%^CYAN%^"+
      "color.  The canopy above their heads is likewise colored, "+
      "with the panels in alternating %^BOLD%^%^BLUE%^blue "+
      "%^RESET%^%^CYAN%^and %^BOLD%^%^MAGENTA%^pink%^RESET%^"+
      "%^CYAN%^, while the ruffled edges and pennant at the top "+
      "are left %^BOLD%^%^WHITE%^clear%^RESET%^%^CYAN%^.  "+
      "%^ORANGE%^Brass colored poles %^CYAN%^extend from the "+
      "canopy down to the floor and support each horse in mid "+
      "gallop around the %^BOLD%^%^WHITE%^clear floor%^RESET%^"+
      "%^CYAN%^ supported by three %^YELLOW%^brass feet%^RESET%^"+
      "%^CYAN%^.  A small metal knob extends out the bottom of "+
      "the box and can be turned clockwise to wind the music box "+
      "up and send the horses prancing.%^RESET%^");
   set_value(1100);
   set_weight(3);
}

void init(){
   ::init();
   add_action("turn_em","turn");
}

int turn_em(string str){
   if(!str) return 0;
   if(str != "knob" && str != "knob on music box") return 0;
   tell_object(TP,"You turn the knob on a music box.");
   if(ETO == TP){
      tell_room(EETO,""+TPQCN+" turns the knob on a music box.",TP);
      tell_room(EETO,"%^BOLD%^%^WHITE%^The horses of the delicate "+
         "glass music box begin to circle around a central spire, "+
         "bounding up and down while a lively song plays in the "+
         "background.%^RESET%^");
   }else{
      tell_room(ETO,""+TPQCN+" turns the knob on a music box.",TP);
      tell_room(ETO,"%^BOLD%^%^WHITE%^The horses of the delicate "+
         "glass music box begin to circle around a central spire, "+
         "bounding up and down while a lively song plays in the "+
         "background.%^RESET%^");
   }
   call_out("turn2",3);
   return 1;
}

void turn2(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^BOLD%^%^WHITE%^Glass horses spin around "+
         "under the glass canopy of this blown glass music box "+
         "while a bright song weaves around their vigorous "+
         "chase.%^RESET%^");
   }else{
      tell_room(ETO,"%^BOLD%^%^WHITE%^Glass horses spin around "+
         "under the glass canopy of this blown glass music box "+
         "while a bright song weaves around their vigorous "+
         "chase.%^RESET%^");
   }
   call_out("turn3",3);
   return;
}

void turn3(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^BOLD%^%^WHITE%^The glass music box "+
         "plays a bright and cheerful song as the three glass "+
         "horses bound and leap around a central spire. %^RESET%^");
   }else{
      tell_room(ETO,"%^BOLD%^%^WHITE%^The glass music box "+
         "plays a bright and cheerful song as the three glass "+
         "horses bound and leap around a central spire. %^RESET%^");
   }
   call_out("turn4",3);
   return;
}

void turn4(){
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(living(ETO)){
      tell_room(EETO,"%^BOLD%^%^WHITE%^The music box's song "+
         "comes to an end and three glass horses finally comes "+
         "to a rest after their spirited chase.%^RESET%^");
   }else{
      tell_room(ETO,"%^BOLD%^%^WHITE%^The music box's song "+
         "comes to an end and three glass horses finally comes "+
         "to a rest after their spirited chase.%^RESET%^");
   }
   return;
}