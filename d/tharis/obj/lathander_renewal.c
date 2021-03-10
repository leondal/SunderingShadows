//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","lathander's renewal"}));
   set_short("%^BOLD%^%^WHITE%^Lathander's Renewal%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^A clear crystal bottle carved to look "+
      "like a mass of %^WHITE%^clouds %^CYAN%^holds a light "+
      "blue liquid.  Opening the bottle reveals a blended scent "+
      "of %^GREEN%^lime%^CYAN%^, %^RESET%^%^GREEN%^leaves%^BOLD%^%^CYAN%^"+
      ", %^RESET%^%^GREEN%^sage%^BOLD%^%^CYAN%^, %^RESET%^%^ORANGE%^"+
      "nutmeg%^BOLD%^%^CYAN%^, vetiver, and %^RESET%^%^RED%^sandalwood"+
      "%^BOLD%^%^CYAN%^.  This light and airy scent reminds "+
      "many of summer days and is quite popular during the "+
      "winter months.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "cologne" || str == "lathander's renewal"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and the fragrance of "+
         "%^CYAN%^summer %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^CYAN%^summer-"+
         "scented %^RESET%^cologne.",TP);
      TP->set("long","%^CYAN%^About "+TP->QO+" is a light, exotic "+
         "masculine scent.%^RESET%^");
      count++;
      return 1;
   }
   return 0;
}

