//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","waters of the tide"}));
   set_short("%^BOLD%^%^BLUE%^Waters of the Tide%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^In a blue crystal round bottle, a "+
      "watery concotion of %^RESET%^%^GREEN%^green tea%^BOLD%^"+
      "%^BLUE%^, %^WHITE%^jasmine%^BLUE%^, and %^RESET%^%^ORANGE%^"+
      "musk %^BOLD%^%^BLUE%^is kept.  The lush and natural scent is an "+
      "easy one that is favored by many men who want to wear a "+
      "scent without it overpowering them and others.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "cologne" || str == "waters of the tide"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and the fragrance of "+
         "%^CYAN%^green tea %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^CYAN%^green tea-"+
         "scented %^RESET%^cologne.",TP);
      TP->set("long","%^CYAN%^"+capitalize(TP->QS)+" "+
         "is wearing a fresh, clean cologne%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

