//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","dryad's essence"}));
   set_short("%^RESET%^%^ORANGE%^Dryad's Essence%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Housed in a wooden bottle carved to "+
      "look like a graceful tree a pure liquid is placed.  Opening "+
      "up the bottle reveals the aroma of %^WHITE%^vanilla%^ORANGE%^, "+
      "%^RED%^sandalwood%^ORANGE%^, and patchouli, with lower notes "+
      "of fresh %^YELLOW%^citrus%^RESET%^%^ORANGE%^, %^GREEN%^melons"+
      "%^ORANGE%^, %^BOLD%^%^MAGENTA%^peaches%^RESET%^%^ORANGE%^, "+
      "and %^MAGENTA%^plums %^ORANGE%^blended together harmoniously.  "+
      "This scent is also known as %^GREEN%^Mielikki's Radiance"+
      "%^ORANGE%^.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "perfume" || str == "dryad's essence"){
      if(count > 4){
         tell_object(TP,"The bottle of perfume is empty.");
         return 1;
      }
      tell_object(TP,"You dab on the perfume, and the fragrance of "+
         "%^ORANGE%^vanilla %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^ORANGE%^vanilla-"+
         "scented %^RESET%^perfume.",TP);
      TP->set("long","%^BOLD%^%^MAGENTA%^"+capitalize(TP->QS)+" "+
         "is cloaked in a sweet, fruity aroma.%^RESET%^");
      count++;
      return 1;
   }
   return 0;
}

