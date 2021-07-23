// really big morning star for giants
#include <std.h>
inherit "/d/common/obj/weapon/giant_morningstar";

void create() {
    ::create();
   set_id(({"morning star","giant star","star"}));
   set_name("%^RESET%^%^ORANGE%^Giant's %^BOLD%^%^WHITE%^Star%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A huge morning star%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Giant's %^BOLD%^%^WHITE%^Star%^RESET%^");
   set_long("%^ORANGE%^This weapon is a expertly crafted giant morning"+
   " star.  However, unlike a normal morning star it has a %^WHITE%^huge"+
   " diamond%^ORANGE%^ at the end of its chain.  There are several "+
   "%^WHITE%^glowing runes%^ORANGE%^ etched into the ball which is not round "+
   "like a normal morning star but a gem shape.  The"+
   " shaft is made of iron with %^WHITE%^silver spirals%^ORANGE%^ filling "+
   "grooves down to the handle. %^RESET%^ ");
   set_lore("This weapon was created by an group of "+
   "voadkyn enchanters who wished to keep the forest "+
   "safe from hords that would raid their homes.  It "+
   "was said that no one could stand against the "+
   "crushing blows of the hero who wielded it.");
   set_property("lore difficulty",25);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("strength",2);
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_func(){
   if((int)ETO->query_level() < 25 ) {
      tell_object(ETO,"You drop the weapon on yourself.");
      ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 25) + 24, "untyped");
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
   return 0;
   }
      tell_room(environment(ETO),"%^CYAN%^The runes on "
           +ETOQCN+"'s weapon glows brightly.",ETO);
      tell_object(ETO,"%^CYAN%^The runes on the diamond glow brightly.");
      return 1;
}
int unwield_func(){
   tell_room(environment(ETO),"%^CYAN%^The weapon of "+ETOQCN+" stops
glowing.",ETO);
   tell_object(ETO,"The rune stops glowing unwielded.");
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 400){
     switch(random(5)){
      case 0..3:
        tell_room(environment(ETO),"%^RED%^The diamond slams into "
                  +target->query_cap_name()+" %^BOLD%^brutally.",({target,ETO}));
        tell_object(ETO,"%^RED%^The diamond slams into "+target->query_cap_name()+
            " %^BOLD%^brutally.",target);
        tell_object(target, "%^RED%^"
         +ETO->query_cap_name()+" weapon slams into"+
         " you %^BOLD%^brutally.");
         return roll_dice(2,8)+2;

     case 4:
            tell_room(environment(ETO),"%^CYAN%^The huge diamond"+
                         " strikes low at "+target->query_cap_name()+"'s legs."
                         ,({target,ETO}));
            tell_object(ETO,"%^CYAN%^"+target->query_cap_name()+
                        " takes a crushing low blow.",target);
            tell_object(target, "%^CYAN%^"+ETO->query_cap_name()+"'s morning "+
			"star strikes your legs sweeping them out from under you.");
            target->set_tripped(random(2)+1,
			"You try to get up, but the world is spinning.");
            return roll_dice(1,4)+1;
      }
   }
}