//Coded by Circe 1/9/05 with desc by night
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","secrets of night"}));
   set_short("%^RESET%^%^MAGENTA%^Secrets of Night%^RESET%^");
   set_long("%^MAGENTA%^In a purple crystal vial, a %^BOLD%^%^BLACK%^"+
      "dark liquid %^RESET%^%^MAGENTA%^is kept.  Opening the %^BOLD%^"+
      "%^BLACK%^jet stopper %^RESET%^%^MAGENTA%^on this bottler "+
      "reveals a blend of floral orchids, violets, rose, and "+
      "blackberry musk, a sensual alluring scent.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "perfume" || str == "secrets of night"){
      if(count > 4){
         tell_object(TP,"The bottle of perfume is empty.");
         return 1;
      }
      tell_object(TP,"You dab on the perfume, and a %^MAGENTA%^"+
         "rich floral scent %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^MAGENTA%^floral-"+
         "scented %^RESET%^perfume.",TP);
      TP->set("long","%^RESET%^%^MAGENTA%^"+capitalize(TP->QS)+" "+
         "is cloaked in a rich, sensual floral scent.%^RESET%^");
      count++;
      return 1;
   }
   return 0;
}

