#include <std.h>

inherit ARMOUR;

void create(){
   ::create();
   "/d/attaya/newseneca/obj/base_girdle.c"->create_girdle(TO);
   set_wear((:TO,"wear_func":));
}

string mygender;

int wear_func(){
   mygender = ETO->query_gender();
   if(mygender == "female"){
      tell_object(ETO,"%^BOLD%^%^CYAN%^You relish the feel of the "+
         "exquisite corset and can't help but notice "+
         "how it enhances your figure.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" slips into a "+
         "corset that makes her look simply breathtaking.%^RESET%^",ETO);
      return 1;
   }else{
      tell_object(ETO,"%^BOLD%^%^BLUE%^The corset was clearly "+
         "made for a woman - you cannot begin to wear it!");
      return 0;
   }
}