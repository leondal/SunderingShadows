#include <std.h>
#include "../seneca.h"

inherit OBJECT;

string mygod;

void create(){
   ::create();
   "/d/attaya/newseneca/obj/deity_animals"->create_animal(TO);
   mygod = TO->query_property("deity");
}

void init(){
   ::init();
   add_action("read_me","read");
   add_action("squeeze_me","squeeze");
}


int read_me(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   tell_object(TP,"You see a miniature version of this "+
      "symbol stitched into the fabric:\n");
   TP->more("/d/attaya/newseneca/obj/symbols/"+mygod+"");
   return 1;
}

int squeeze_me(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   switch(random(3)){
      case 0:
         tell_object(TP,"%^BOLD%^You squeeze the soft stuffed animal, "+
            "and it says in a childlike voice, %^MAGENTA%^'%^YELLOW%^I love "+
            ""+capitalize(mygod)+"!%^MAGENTA%^'%^RESET%^");
         tell_room(EETO,"%^BOLD%^"+TPQCN+" squeezes the soft stuffed animal, "+
            "and it says in a childlike voice, %^MAGENTA%^'%^YELLOW%^I love "+
            ""+capitalize(mygod)+"!%^MAGENTA%^'%^RESET%^",ETO);
         break;
      case 1:
         tell_object(TP,"%^BOLD%^%^BLUE%^You squeeze the soft stuffed animal, "+
            "and it says in a childlike voice, %^GREEN%^'%^WHITE%^"+capitalize(mygod)+" "+
            "is the best!%^GREEN%^'%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^BLUE%^You squeeze the soft stuffed animal, "+
            "and it says in a childlike voice, %^GREEN%^'%^WHITE%^"+capitalize(mygod)+" "+
            "is the best!%^GREEN%^'%^RESET%^",ETO);
         break;
      default:
         tell_object(TP,"%^BOLD%^%^BLACK%^You squeeze the soft stuffed animal, "+
            "and it says in a childlike voice, %^WHITE%^'%^YELLOW%^"+capitalize(mygod)+" "+
            "is my BEST friend!%^WHITE%^'%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^BLACK%^You squeeze the soft stuffed animal, "+
            "and it says in a childlike voice, %^WHITE%^'%^YELLOW%^"+capitalize(mygod)+" "+
            "is my BEST friend!%^WHITE%^'%^RESET%^",ETO);
         break;
   }
   return 1;
}