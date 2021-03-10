#include <std.h>
inherit "/d/common/obj/weapon/trident";

void create() {
    ::create();
   set_id(({"trident","coral trident","tarzam's ruler of the seas"}));
   set_name("%^RESET%^Sea Trident%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^Coral Trident%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Tarzam's ruler of the seas%^RESET%^");
   set_long("%^CYAN%^At first glance one might think this trident has "+
   "been spoiled by time on the ocean floor. Coral and seashells"+
   " cling to the wooden pole, and it consistently seems to"+
   " drip seawater, no matter how long its been out of"+
   " it. However upon closer inspection one can still"+
   " make out the two carved sections where a pair of "+
   "hands were meant to hold the weapon. And the "+
   "three prongs at its tip are unspoiled by time or "+
   "seawater. An obsidian black metal with sharpened "+
   "onyx gemstones, all three displaying wickedly "+
   "serrated edges, if getting stabbed by this weapon "+
   "wasn't bad enough, it would seem the pullback would be far worse.");
   set_property("lore difficulty",35);
   set_lore("This weapon seems like it came from an ancient"+
   " legend of a merman.  Tales are sung among sea cultures"+
   " of tarzam who fought back the dragon turtle that tried to destroy his tribe.");
   set_value(9000);
   set_property("enchantment",4);  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){

      tell_room(EETO,"%^CYAN%^ "
           +ETOQCN+"'s drips water when wielded.",ETO);
      tell_object(ETO,"%^CYAN%^The trident drips water continously when wielded.");
      return 1;
}
int unwield_func(){
  
   tell_room(EETO,"%^CYAN%^The weapon of "+ETOQCN+
   " drips less.",ETO);
   tell_object(ETO,"The trident seems to drip less when unwielded.");
   return 1;
}
int hit_func(object target) {
   string limb;
   if(!objectp(target)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   if(random(1000) < 400){
     switch(random(6)){
      case 0..3:
	    limb = target->return_target_limb();
        tell_room(EETO,"%^CYAN%^"+ETOQCN+" plunges the trident into "
                  +target->QCN+"'s "+limb+" and rips it out with a gush of blood.",({target,ETO}));
        tell_object(ETO,"%^CYAN%^You plunge the trident into "+target->QCN+
            "'s "+limb+" and rip it out with a gush of blood.",target);
        tell_object(target, "%^CYAN%^"
         +ETO->QCN+" plunges the trident into your "+limb+" and rips it out with a gush of blood.");
         return roll_dice(2,8)+2;

     case 4:
            tell_room(EETO,"%^CYAN%^"+ETOQCN+" swipes low with the butt end of "+ETO->QP+
			" trident and sends "+target->QCN+" sprawling."
                         ,({target,ETO}));
            tell_object(ETO,"%^CYAN%^"+target->QCN+
                        " is sent tumbling from a %^BOLD%^low swipe.",target);
            tell_object(target, "%^CYAN%^Catching you off guard "
			+ETO->QCN+" swipes your feet from under you with "
			+ETO->QP+" trident!");
            target->set_tripped(1,
			"%^CYAN%^You try to get up, but the world is spinning.",15);
            return roll_dice(1,4)+1;
	  case 5:
            tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s sprays off water leaving a find mist in the area."
                         ,({target,ETO}));
            tell_object(ETO,"%^CYAN%^Words of a spell gather in your mind.");
			tell_object(target,"%^CYAN%^"+ETO->QCN+
			  " strikes you with a splash of water.");
			new("/cmds/spells/c/_cloudburst")->use_spell(ETO,target,15,100,"cleric");
			return roll_dice(1,4)+1;
      }
   }
}
