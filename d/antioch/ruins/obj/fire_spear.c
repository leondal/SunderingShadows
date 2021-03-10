//Added short, lore, and changed to inherit mspear - Cythera 4/05
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/mspear.c";

void create()
{
   ::create();
   set_name("burning spear");
   set_obvious_short("%^RESET%^%^ORANGE%^A burning hot spear%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Spear of the %^RED%^B%^BOLD%^u"+
		"%^RESET%^%^ORANGE%^r%^YELLOW%^n%^RESET%^%^ORANGE%^i"+
		"%^BOLD%^%^RED%^n%^RESET%^%^RED%^g %^ORANGE%^Fires%^RESET%^");
   set_id(({"burning spear","spear","burning hot spear","hot spear","fire spear","smoldering spear"}));
   set_long("%^ORANGE%^This spear is still hot, as though it"+
   " has just come out of the forge. It is a dull orange in"+
   " color, as though the fire is smoldering, biding its time"+
   " before it unleashes itself. The spear itself is of fine"+
   " quality, provided that it doesn't bend out of shape. The"+
   " tip of the spear has been tempered, and while it still"+
   " appears hot you can see the grey of the steel. The tip"+
   " is an inch and a half in width, and about four inches"+
   " long. It joins with two other curved prongs that come"+
   " out at the end of the shaft. It seems well balanced,"+
   " if you can stand to wield it.%^RESET%^");
   set_value(500);
  // set_wc(1,6);
  // set_large_wc(1,8);
  // set_type("piercing");
  // set_prof_type("medium spear");
  // set_weapon_speed(6);
   set_lore("Forged in the armory of the demons of the Plane of "+
		"Fire, the Spear of the Burning Fires is a common "+
		"weapon for devils and demons.  Infused with a living"+
		" flame, the demons and devils delight in the pain and"+
		" agony the spear causes.  Followers of Kossuth, upon "+
		"witnessing the effects of the spear grew giddy and "+
		"excited to see such a savage weapon.");
	set_property("lore",9);
   set_property("enchantment",2);
   set_item_bonus("damage bonus",2);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"hitme":));
}

int wieldme()
{
   if((string)ETO->query_diety() == "auril" || (string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BOLD%^%^RED%^The fiery spear burns"+
      " you horribly and you can't stand to hold it!");
      tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
      " is burned horribly by the fiery spear and can't keep "+ETO->QP+""+
      " hands on it.",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",random(15)+1);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
   if(ETO->query_lowest_level() < 18) {
      tell_object(ETO,"You are not experienced enough to use"+
      " such a weapon.");
      return 0;
   }
   if((string)ETO->query_diety() == "kossuth") {
      tell_object(ETO,"%^ORANGE%^The warmth of the spear feels"+
      " good in your hands");
      return 1;
   }
   tell_object(ETO,"%^RED%^You feel your hands blister as you"+
   " grip the shaft of the spear, causing great pain.");
   tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" can't"+
   " help but wince as "+ETO->QS+" grips the hot"+
   " shaft of the spear.",ETO);
   set_property("magic",1);
   ETO->do_damage("torso",random(10)+1);
   ETO->add_attacker(TO);
   ETO->continue_attack();
   ETO->remove_attacker(TO);
   remove_property("magic");
   return 1;
}

int removeme()
{
   if((string)ETO->query_diety() == "kossuth") {
      tell_object(ETO,"%^YELLOW%^You release the warm spear and"+
      " your hands feel cool again.");
      return 1;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^OUCH!!\nYou peel your fingers away"+
   " from the spear, leaving a layer of skin behind!");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+""+
   " screams as "+ETO->QS+" releases the hot spear,"+
   " leaving some of "+ETO->QP+" burnt flesh behind"+
   " on the shaft.",ETO);
   set_property("magic",1);
   ETO->do_damage("torso",random(10)+1);
   ETO->add_attacker(TO);
   ETO->continue_attack();
   ETO->remove_attacker(TO);
   remove_property("magic");
   return 1;
}

int hitme(object targ)
{
   string limb;

   if(!random(6)) {
      tell_object(targ,"%^ORANGE%^"+ETO->QCN+"'s burning"+
      " spear scrapes you wickedly and burns your flesh!");
      tell_object(ETO,"%^ORANGE%^"+targ->QCN+" winces"+
      " as your spear burns "+targ->QP+" flesh.");
      targ->do_damage("torso",random(6)+1);
      return 1;
   }
   if(!random(8)) {
      tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s spear"+
      " blackens your skin as it slices your flesh.");
      tell_object(ETO,"%^YELLOW%^The spear blackens "+targ->QCN+"'s"+
      " skin as you slice into "+targ->QP+".");
      targ->do_damage("torso",random(8)+2);
      return 1;
   }
   if(!random(12)) {
      switch(random(4)) {
         case 0:
            limb = "left arm";
            break;
         case 1:
            limb = "right arm";
            break;
         case 2:
            limb = "right leg";
            break;
         case 3:
            limb = "left leg";
            break;
      }
      tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+"'s"+
      " spear gets too close to your "+limb+", badly burning it!");
      tell_object(ETO,"%^BOLD%^%^RED%^You hold your spear against"+
      " "+targ->QCN+"'s "+limb+" for a moment, causing"+
      " it to blister and burn.");
      tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+"'s"+
      " burning spear is pressed against "+targ->QCN+"'s"+
      " "+limb+" for a moment and it instantly blisters quite badly.",({ETO,targ}));
      targ->do_damage("torso",random(8)+5);
      return 1;
   }
   return 2;
}
