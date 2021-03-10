#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
   "/d/common/obj/rand/base_pants.c"->create_pants(TO);
   switch(random(10)){
      case 0..4: set_size(1);
              break;
      case 5: set_size(3);
              break;
      default: set_size(2);
               break;
   }
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
   if((int)ETO->query_highest_level() < 12) {
    tell_object(ETO,"%^BOLD%^%^RED%^You are not worthy of such fine pants!");
        return 0;
   }else{
	return 1;
	}
}
