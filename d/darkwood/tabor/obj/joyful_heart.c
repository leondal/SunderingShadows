//Coded by Circe 6/8/04 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","joyful heart"}));
   set_short("%^BOLD%^%^MAGENTA%^Joyful %^RED%^Heart "+
      "%^MAGENTA%^Perfume%^RESET%^");
   set_long("Filling an ornately %^BOLD%^%^MAGENTA%^pa%^RED%^in"+
      "%^MAGENTA%^ted bottle %^RESET%^is an almost clear liquid "+
      "that has a %^YELLOW%^pale yellow color %^RESET%^to it.  "+
      "The perfume is made from the %^BOLD%^%^MAGENTA%^jasmine "+
      "flower%^RESET%^, a common plant used by many women in the "+
      "Tsvaren Empire.  The scent is light and crisp with a "+
      "wonderfully subtle exotic floral scent.");
   set_value(200);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
string long;
   if(str == "perfume" || str == "joyful heart"){
      if(count > 4){
         tell_object(TP,"The bottle of perfume is empty.");
         return 1;
      }
      tell_object(TP,"You dab on the perfume, and the scent of "+
         "%^BOLD%^%^MAGENTA%^jasmine %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^BOLD%^%^MAGENTA%^jasmine-"+
         "scented %^RESET%^perfume.",TP);
      long = TP->query_long();
      TP->set("long","%^BOLD%^%^MAGENTA%^A light, crisp, exotic "+
         "floral scent hangs about "+TP->QO+"%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

