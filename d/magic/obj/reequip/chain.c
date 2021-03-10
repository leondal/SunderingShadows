#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
   ::create();
   set_long(""+::query_base_long()+"\n\n  This item looks a little tired and worn from use.");
   set_wear((:TO,"custom_wear":));
   set_value(0);
}

int custom_wear() {
   if(!TO->query_owns_item(ETOQN)) {               
     tell_object(ETO,"This does not belong to you.");
     return 0;
   }
   return 1;
}
