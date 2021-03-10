//Coded by Circe 6/8/04 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","blushing laughter"}));
   set_short("%^BOLD%^%^MAGENTA%^Blushing %^YELLOW%^Laughter "+
      "%^MAGENTA%^Perfume%^RESET%^");
   set_long("This %^YELLOW%^honey-colored liquid %^RESET%^fills "+
      "a %^BOLD%^%^CYAN%^crystal vial%^RESET%^.  The scent in the "+
      "vial is a warm fragrant scent with sweet aromas.  A mixture "+
      "of %^ORANGE%^vanilla%^RESET%^, %^YELLOW%^honey%^RESET%^, and "+
      "subtle %^MAGENTA%^orchid %^RESET%^undertones fill your senses.  "+
      "After a moment your catch the hidden tones of %^ORANGE%^ginger"+
      "%^RESET%^, ylang-ylang, and musk.");
   set_value(200);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
string long;
   if(str == "perfume" || str == "blushing laughter"){
      if(count > 4){
         tell_object(TP,"The bottle of perfume is empty.");
         return 1;
      }
      tell_object(TP,"You dab on the perfume, and the scent of "+
         "%^YELLOW%^honey %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^YELLOW%^honey-"+
         "scented %^RESET%^perfume.",TP);
      long = TP->query_long();
      TP->set("long","%^YELLOW%^A warm, sweet aroma rolls off "+
         ""+TP->QO+"%^RESET%^.");
      count++;
      return 1;
   }
   return 0;
}

