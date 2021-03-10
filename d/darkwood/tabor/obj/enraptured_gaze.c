//Coded by Circe 6/8/04 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("cologne");
   set_id(({"cologne","bottle of cologne","enraptured gaze"}));
   set_short("%^RESET%^%^GREEN%^Enraptured %^YELLOW%^Gaze "+
      "%^RESET%^%^GREEN%^Cologne%^RESET%^");
   set_long("Housed in a %^CYAN%^glass vial%^RESET%^, this fine "+
      "fragrance contains a mixture of %^YELLOW%^lemon%^RESET%^, "+
      "%^ORANGE%^mandarin%^RESET%^, and %^RED%^coriander %^RESET%^"+
      "for a clean, crisp scent.  Undertones of %^GREEN%^moss"+
      "%^RESET%^, %^BOLD%^cedar%^RESET%^, and %^ORANGE%^musk "+
      "%^RESET%^give subtle warmth to this scent.  This cologne is "+
      "popular with young men of the Tsvaren Empire.");
   set_value(200);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
string long;
   if(str == "cologne" || str == "enraptured gaze"){
      if(count > 4){
         tell_object(TP,"The bottle of cologne is empty.");
         return 1;
      }
      tell_object(TP,"You splash on the cologne, and a %^BOLD%^crisp, "+
         "clean scent %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^BOLD%^crisp, "+
         "clean %^RESET%^cologne.",TP);
      long = TP->query_long();
      TP->set("long","%^YELLOW%^A clean, crisp scent mulls about "+
         ""+TP->QO+"%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

