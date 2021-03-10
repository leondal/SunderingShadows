//Special version of claws for Grimmy to use so they don't break heartbeat Octothorpe 5/25/09
#include <std.h>
inherit "/d/common/obj/weapon/claw.c";


void create() {
   ::create();
   set_name("shadowy claws");
   set_id(({"blerg"}));
   set_short("Twilight Talons");
   set_obvious_short("shadowy claws");
   set_long("This set of claws consists of three prongs, each made of the
stuff of "
"shadows itself.  Of the three, the centre is longer than the rest, easily
nine or ten inches "
"in length, and partnered on either side by a slightly shorter, thicker
prong.  They are formed to rest over "
"the back of each hand, and seem to have no means of grip save for their
attachment to the bracer around the "
"wrist, yet somehow they never come loose.  It is difficult to discern
their edges at times; their partly "
"transparent substance has a surreal quality about it, but you can imagine
they would be "
"all the more sharp for it.\n");
   set_weight(0);
   set_value(0);
   set_hit((:TO,"hit_fun":));
   set_property("enchantment",5);
   set_property("monsterweapon",1);
}

int hit_fun(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(12)) {
      tell_object(ETO,"The claws shimmer and become insubstantial, as they
pass right through "
+targ->QCN+"'s flesh!");
      tell_object(targ,""+ETO->QCN+"'s claws seem to become insubstantial
as they pass right through "
"your flesh!");
      tell_room(EETO,""+ETO->QCN+"'s claws seem to become insubstantial as
they pass right through "
+targ->QCN+"'s flesh!",({ETO,targ}));
      dam = random(5)+6;
      TO->set_property("magic",1);
      targ->do_damage(targ->return_target_limb(),dam);
      TO->remove_property("magic");
      return 1;
   }
   if(!random(8)) {
      tell_object(ETO,"The shadowy claws seem to glitter darkly as you
slash at your "
"opponent, and you feel refreshed.");
      tell_object(targ,"The shadowy claws seem to glitter darkly as
"+ETO->QCN+" slashes at "
"you with them.");
      tell_room(EETO,"The shadowy claws seem to glitter darkly as
"+ETO->QCN+" slashes at "
+targ->QCN+" with them.",({ETO,targ}));
      dam = random(5)+6;
      TO->set_property("magic",1);
      ETO->do_damage("torso",(-1)*dam);
      targ->do_damage(targ->return_target_limb(),dam);
      TO->remove_property("magic");
      return 1;
   }
   if(!random(10)) {
      ETO->execute_attack();
      tell_object(ETO,"You move with fluid grace, following up one vicious
attack with another from "
"your claws!");
      tell_room(EETO,""+ETO->QCN+" moves with fluid grace, following up one
vicious attack from "
+ETO->QP+" claws with another!","ETO");
      return 1;
   }
   return 1;
}
