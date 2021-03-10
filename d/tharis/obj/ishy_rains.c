//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","istishia's refreshing rains"}));
   set_short("%^RESET%^%^CYAN%^Istishia's Refreshing Rains%^RESET%^");
   set_long("%^CYAN%^A teardrop-shaped bottle that looks like a "+
      "%^BOLD%^%^BLUE%^drop of rain %^RESET%^%^CYAN%^is filled "+
      "with a %^BOLD%^pale blue liquid%^RESET%^%^CYAN%^.  "+
      "Opening the bottle reveals a blend of amber and wallflower "+
      "as well as watery notes of the fresh, cool sea air.  "+
      "The refreshing and crisp perfume smells oddly like a rainstorm.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "perfume" || str == "istishia's refreshing rains"){
      if(count > 4){
         tell_object(TP,"The bottle of perfume is empty.");
         return 1;
      }
      tell_object(TP,"You dab on the perfume, and the fragrance of "+
         "%^CYAN%^a rainstorm %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^CYAN%^rain-"+
         "scented %^RESET%^perfume.",TP);
      TP->set("long","%^BOLD%^%^BLUE%^"+capitalize(TP->QS)+" "+
         "is wearing a crisp, refreshing perfume.%^RESET%^");
      count++;
      return 1;
   }
   return 0;
}

