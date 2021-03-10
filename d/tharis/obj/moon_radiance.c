//Coded by Circe 1/9/05 with desc by Shar
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","moon's radiance"}));
   set_short("%^BOLD%^%^WHITE%^Moon's Radiance%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^A smooth polished silver bottle is "+
      "filled with a %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m"+
      "%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g "+
      "liquid.  Pulling off the %^CYAN%^star-shaped stopper "+
      "%^WHITE%^reveals a rich floral aroma of gardenia and "+
      "%^MAGENTA%^rose%^WHITE%^, with tones of %^RESET%^%^RED%^"+
      "sandalwood%^BOLD%^%^WHITE%^ and %^BLUE%^iris%^WHITE%^.  "+
      "This romantic aroma is used by many maidens and those in "+
      "love or wishing to gain the attention of a suitor.%^RESET%^");
   set_value(random(50)+100);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wear_per","wear");
}


int wear_per(string str){
   if(str == "perfume" || str == "moon's radiance"){
      if(count > 4){
         tell_object(TP,"The bottle of perfume is empty.");
         return 1;
      }
      tell_object(TP,"You dab on the perfume, and a %^BOLD%^%^MAGENTA%^"+
         "romantic floral scent %^RESET%^rises in the air.");
      tell_room(ETP,""+TPQCN+" wears a %^BOLD%^%^MAGENTA%^floral-"+
         "scented %^RESET%^perfume.",TP);
      TP->set("long","%^BOLD%^%^MAGENTA%^A romantic floral scent "+
         "rolls off of "+TP->QP+" body%^RESET%^");
      count++;
      return 1;
   }
   return 0;
}

