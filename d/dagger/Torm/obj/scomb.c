#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("silver comb");
   set_short("%^WHITE%^%^BOLD%^Silver Comb%^RESET%^");
   set_id(({"silver comb","comb","hair comb"}));
   set_long("%^BOLD%^The comb is made of fine silver and has slender teeth"+
   " that can be put in the finest of hair. The ends of the comb are inlaid"+
   " with tiny white pearls, flowery designs are etched around them, giving"+
   " the silver comb a delicate appearance. It is meant to be worn in a"+
   " woman's hair, helping to sweep it back and keep it out of her face.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"head"}));
   set_value(450);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme()
{
   if((string)ETO->query_gender() != "female") {
      return notify_fail("This is a woman's comb!");
   }
   tell_object(ETO,"%^BOLD%^You carefully sweep your hair back and fit the"+
   " silver comb in place.");
   tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+" sweeps her"+
   " hair back and secures the silver comb.",ETO);
   return 1;
}

int removeme()
{
   tell_object(ETO,"You remove the %^BOLD%^silver comb%^RESET%^ and your hair"+
   " tumbles back into your face.");
   tell_room(environment(ETO),""+ETO->query_cap_name()+" removes her %^BOLD%^silver"+
   " comb%^RESET%^, freeing her hair from its restraint.",ETO);
   return 1;
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
