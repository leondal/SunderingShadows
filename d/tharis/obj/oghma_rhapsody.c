//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","divine rhapsody"}));
   set_short("%^RESET%^%^RED%^Divine Rhapsody%^RESET%^");
   set_long("%^RED%^In a red-tinted square bottle this liquid "+
      "is housed.  Opening the stopper on the bottle reveals "+
      "the rich aroma of %^ORANGE%^tobacco %^RED%^and %^YELLOW%^"+
      "spice%^RESET%^%^RED%^, with low tones of musk, sandalwood, "+
      "and amber.  This masculine scent is favored by many "+
      "warriors for formal occassion, or to mask the smells of "+
      "battle.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}
string query_type(){
    return "cologne";
}

int wear_per(string str){
   if(str == "cologne" || str == "divine's rhapsody"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and the fragrance of "+
         "%^RED%^spice %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^RED%^spice-"+
         "scented %^RESET%^cologne.",TP);
      TP->set("long","%^RED%^"+capitalize(TP->QS)+" "+
         "is wearing a spicy, smokey, masculine scent%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

