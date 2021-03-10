#include <std.h>
//Updated for weapon feats Octothorpe 5/11/09
inherit "/d/common/obj/weapon/lance.c";

void create()
{
   ::create();
   set_name("silver lance");
   set_id(({"lance","silver lance"}));
   set_short("%^WHITE%^%^BOLD%^Silver Lance%^RESET%^");
   set_long("%^BOLD%^This lance has been crafted from the finest of silver"+
   " that must have been somehow enchanted to keep it from bending or"+
   " breaking easily. The lance is nicely balanced and you notice the"+
   " symbol of a pegasus carved into the shaft, the insignia of Antioch.");
   //set_weight(10);
   set_value(100);
   //set_wc(1,8);
   //set_large_wc(1,12);
   //set_size(1);
   //set_type("piercing");
   //set_prof_type("lance");
   //set_property("lance",1);
   set_hit((:TO,"check":));
   if(!random(6)) {
       set("no curse",1);
      set_property("enchantment",1);
   }
   set_special_material_type("silver");
}

int check(object targ)
{
   if(!objectp(ETO)) return 0;
   if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle()))
      ETO->force_me("drop lance");
   return 0;

   if(!random(5)) {
      tell_object(ETO,"%^BOLD%^For the glory of Antioch you drive your silver"+
      " lance deep into your "+targ->query_cap_name()+"!");
      tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+" drives"+
      " "+ETO->query_possessive()+" silver lance deeply into "+targ->query_cap_name()+".",({ETO,targ}));
      tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+" drives "+ETO->query_possessive()+""+
      " silver lance deeply into you!");
      targ->cause_typed_damage(targ, "torso", roll_dice(1, 4) + 3, "silver");
      return 1;
   }
}

int query_size()
{
   if(objectp(ETO) && living(ETO))
      return (int)ETO->query_size();
   return ::query_size();
}
