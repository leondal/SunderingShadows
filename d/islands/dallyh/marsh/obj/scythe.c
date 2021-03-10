#include <std.h>
inherit WEAPON;

void create(){
   ::create();

    set_name("Scythe of Damnation");
    set_short("%^RESET%^%^BLUE%^Scythe of Damnation%^RESET%^");
    set_id(({"scythe of damnation","scythe","damnation"}));
    set_long(
   "This dark scythe has a jet black blade. It has a slight black aura around it which seems to radiate evil.  The handle of this scythe seems to have been put together from finger bones.  Only a truly evil creature would create such a grotesque weapon."
            );
    set_wc(2,5);
    set_large_wc(3,5);
    set_weight(30);
    set_value(80);
    set_type("slashing");
    set_size(2);
    set_prof_type("scythe");
    set_property("enchantment",1);
    set_hit( (:this_object(), "extra_hit":) );
    set_wield((:this_object(), "extra_wield":));
   set_unwield((:TO,"removeme":));
}
int extra_hit(object ob) {
   if(!objectp(ob)) return 1;
    if(random(15) < 2) {
       tell_object(ETO, "%^RESET%^%^BLUE%^The scythe slides easily through "+ob->query_cap_name()+" creating a deep wound!");
        tell_object(ob, "%^RESET%^%^BLUE%^"+ETO->query_cap_name()+"'s scythe slides easily through your flesh creating a deep wound!");
tell_room(environment(query_wielded()), "%^RESET%^%^BLUE%^The scythe slides easily through "+ob->query_cap_name()+"'s flesh creating a deep wound!",({ETO,ob}));
     ob->do_damage("torso", 5+random(10));
     return 1;
    }
}

int extra_wield() {
if(TP->query_level() < 20) {
 tell_object(TP,"You aren't yet good enough to use such a weapon.");
  return 0;
} else {
   ETO->set_property("evil item",1);
   return 1;
}
}

int removeme()
{
   ETO->set_property("evil item",-1);
   return 1;
}
