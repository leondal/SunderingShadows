#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
   set_name("leather pants");
   set_id(({"pants","leather pants","tight leather pants"}));
   set_short("Tight leather pants");
   set_long(
   "This pants are made of a very thin black leather, they look somewhat stretchable but rather form fitting and somewhat on the small side."
   );
   set_weight(2);
   set_value(75);
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_wear((:TO,"wearit":));
   set_remove((:TO,"removeit":));
}

int wearit() {
   tell_object(ETO,"You barely manage to get the pants on, they're so small and tight!");
   tell_room(environment(ETO),""+ETO->query_cap_name()+" squeezes "+ETO->query_objective()+"self into the tight leather pants.",ETO);
   return 1;
}

int removeit() {
   tell_object(ETO,"You breath a little easier now that you're out of those damn pants.");
   tell_object(environment(ETO),""+ETO->query_cap_name()+" struggles free of the leather pants and seems rather relieved to be out of them.",ETO);
   return 1;
}
