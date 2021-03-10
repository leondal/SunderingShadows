#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
   ::create();
   "/d/attaya/newseneca/obj/base_jacket.c"->create_doublet(TO);
   switch(random(7)){
      case 0..1: set_size(1);
              break;
      case 2: set_size(3);
              break;
      default: set_size(2);
               break;
   }
   set_wear((:TO,"wear_func":));
}

string mygender;

int wear_func(){
   mygender = ETO->query_gender();
   if(mygender == "male"){
      tell_object(ETO,"%^BOLD%^%^BLUE%^You slip on the doublet "+
         "and can't help but admire the way it makes you look.");
      tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" looks quite "+
         "dashing as he slips into his "+TO->query_short()+".",ETO);
      return 1;
   }else{
      tell_object(ETO,"%^BOLD%^%^BLUE%^The doublet was clearly "+
         "made for a man - you cannot begin to wear it!");
      return 0;
   }
}