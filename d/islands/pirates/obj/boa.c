#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create() {
   ::create();
   set_name("bracers");
   set_id(({"bracers","bracers of armor","plated bracers"}));
   set_short("%^BLACK%^%^BOLD%^Bracers of Armor%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^plated steel bracers%^RESET%^");
   set_long("These bracers are made from plates of steel, tinted to a %^BLACK%^%^BOLD%^shining midnight "
"shade%^RESET%^ of black.  The plates have been curved and pieced together to form these remarkably durable, "
"but slightly heavy, arm guards.  They are a little longer than average bracers, covering the wearer's "
"wrists and running along the forearms all the way to the elbows.\n");
   set_lore("%^WHITE%^%^BOLD%^These bracers seem like a lighter form of standard bodily plate armor, but "
"with the obvious advantage that they give far more mobility.  They seem to have become quite a popular item "
"among many rogue warriors, as a lighter and cheaper alternative for heavier armor types.%^RESET%^\n");
   set_property("lore difficulty",11);
   set_weight(12);
   set_value(1000);
   set_size(2);
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   ::check();
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" clasps the plates of the %^BLACK%^bracers %^WHITE%^around "
+ETO->QP+" forearms.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You clasp the plates of the %^BLACK%^bracers %^WHITE%^around your forearms.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" unclasps the %^BLACK%^dark bracers%^WHITE%^.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You unclasp the %^BLACK%^dark bracers%^WHITE%^.%^RESET%^");
   return 1;
}

int is_metal() { return 1; }
