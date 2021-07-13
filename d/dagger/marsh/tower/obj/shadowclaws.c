/*Switching back to piercing to see if there still is an issue - Octothorpe 10/3/17*/
//converted to slashing type to prevent stabs; was causing bugs with sheathes. Nienne, 02/10
#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

object claw,bracer;

void create() {
   ::create();
   set_name("shadowy claws");
   set_id(({"shadowclaw","claw","claws","shadowy claws","talons","talon","twilight talons"}));
   set_short("%^BOLD%^%^BLACK%^Twil%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^ght Talons%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y claws%^RESET%^");
   set_long("%^BLUE%^This set of claws consists of three prongs, each made of the stuff of %^BOLD%^%^BLACK%^"
"shadows%^RESET%^%^BLUE%^ itself.  Of the three, the centre is longer than the rest, easily nine or ten inches "
"in length, and partnered on either side by a slightly shorter, thicker prong.  They are formed to rest over "
"the back of each hand, and seem to have no means of grip save for their attachment to the bracer around the "
"wrist, yet somehow they never come loose.  It is difficult to discern their edges at times; their partly "
"%^WHITE%^transparent %^BLUE%^substance has a surreal quality about it, but you can imagine they would be "
"all the more sharp for it.%^RESET%^\n");
   set_weight(0);
   set_value(0);
   set_property("no curse",1);
   set_type("divine");
   set_prof_type("magic weapons");
   set_weapon_prof("simple");
   set_damage_type("piercing");
   set_hit((:TO,"hit_fun":));
   set_property("able to cast",1);
}

void __ActuallyUnwield() {
    ::__ActuallyUnwield();
    if(objectp(claw)) { if((int)claw->query_wielded()) {
            claw->__ActuallyUnwield();
        }}
    if(objectp(bracer)) {
        if((int)bracer->query_status()) {
            tell_room(EETO,"%^BLUE%^The shadowy claws shimmer and disappear.%^RESET%^");
            bracer->do_reset();
        }
    }
    TO->remove();
}

void set_claw(object ob1) { claw = ob1; }
void set_bracer(object ob1) { bracer = ob1; }

int hit_fun(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();

   if(!random(12)) {
      tell_object(ETO,"%^BLUE%^The claws shimmer and become insubstancial, as they pass right through "
+targ->QCN+"'s flesh!%^RESET%^");
      tell_object(targ,"%^BLUE%^"+ETO->QCN+"'s claws seem to become insubstancial as they pass right through "
"your flesh!%^RESET%^");
      tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s claws seem to become insubstancial as they pass right through "
+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
      dam = roll_dice(1, 10);
      TO->set_property("magic",1);
      TO->remove_property("magic");
      return dam;
   }

   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The shadowy claws seem to glitter darkly as you slash at your "
"opponent, and you feel refreshed.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLACK%^The shadowy claws seem to glitter darkly as "+ETO->QCN+" slashes at "
"you with them.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^The shadowy claws seem to glitter darkly as "+ETO->QCN+" slashes at "
+targ->QCN+" with them.%^RESET%^",({ETO,targ}));
      dam = roll_dice(1, 10);
      TO->set_property("magic",1);
      ETO->add_hp(dam);
      TO->remove_property("magic");
      return dam;
   }

   if(!random(10)) {
      ETO->execute_attack();
      tell_object(ETO,"%^RED%^You move with fluid grace, following up one vicious attack with another from "
"your claws!%^RESET%^");
      tell_room(EETO,"%^RED%^"+ETO->QCN+" moves with fluid grace, following up one vicious attack from "
+ETO->QP+" claws with another!%^RESET%^","ETO");
      return 0;
   }
   return 0;
}
