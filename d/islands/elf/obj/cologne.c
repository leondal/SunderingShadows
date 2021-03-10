#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","golden meadow"}));
   set_short("%^RESET%^%^YELLOW%^Golden Meadow%^RESET%^");
   set_long("This is a wooden bottle with a golden top"+
   " on it.  Opening the topper reveals a sent of "+
   "plants from a %^ORANGE%^fresh meadow%^RESET%^.   It is a crisp "+
   "clean sent that one could wear to add a pleasant smell.%^RESET%^");
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
   if(str == "cologne" || str == "golden meadow"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and the fragrance of "+
         "%^ORANGE%^meadows %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^ORANGE%^meadow-"+
         "scented %^RESET%^cologne.",TP);
      TP->set("long","%^RESET%^"+capitalize(TP->QS)+" "+
         "is wearing a crisp %^ORANGE%^meadow%^RESET%^ scent%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}