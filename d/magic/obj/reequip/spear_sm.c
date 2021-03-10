#include <std.h>
inherit "/d/common/obj/weapon/spear_sm";

void create(){
   ::create();
   set_long(""+::query("long")+"\n\nThis item looks a little tired and worn from use.");
   set_wield((:TO,"custom_wield":));
   set_value(0);
}

int custom_wield() {
   if(!TO->query_owns_item(ETOQN)) {               
     tell_object(ETO,"This does not belong to you.");
     return 0;
   }
   return 1;
}
