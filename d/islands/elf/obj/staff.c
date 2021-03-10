#include <std.h>
inherit "/d/common/obj/weapon/quarter_staff";

void create() {
    ::create();
   set_id(({"staff","summoner's bane","bane"}));
   set_name("%^RESET%^Summoner's Bane%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^staff with an odd gem%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Summoners Bane%^RESET%^");
   set_long("%^RESET%^This looks to be a finely crafted "+
   "staff with several dark ruins painted on the surface"+
   ".  There is a very %^BOLD%^%^BLACK%^large black%^RESET%^ an %^MAGENTA%^violet gem set"+
   "%^RESET%^ into one end of the staff radiating a strange aura.");
   set_property("lore difficulty",35);
   set_lore("A sect of gold elven magi are rumored to experement"+
   " with anti magic.  This appears to be a creation of that "+
   "order.   This weapon is rumored to be able to undo summoning"+
   " magic by striking a summoned creature with it.");
   set_value(9000);
   set_property("enchantment",5+random(2));  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){

      tell_room(EETO,"%^MAGENTA%^ "
           +ETOQCN+"'s gives off a strange aura when wielded.",ETO);
      tell_object(ETO,"%^MAGENTA%^Your staff gives off a strange aura when wielded.");
      return 1;
}
int unwield_func(){
  
   tell_room(EETO,"%^MAGENTA%^The weapon of "+ETOQCN+
   "'s stops giving off an aura.",ETO);
   tell_object(ETO,"%^MAGENTA%^Your staff stops giving off an aura when unwielded.");
   return 1;
}
int hit_func(object target) {
   string limb;
   object *minions;
   int i = 0;
   int count = 0;
   if(!objectp(target)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   if(present("summoned monster",EETO)){
    minions   = query_current_attackers();
   
    for(i=0;i<sizeof(minions);i++) //$@$#% fodder
    {
      if(count > 3) break;
      if(!objectp(minions[i])) { continue; }
      if(interactive(minions[i])) { continue; }
      if(member_array(minions[i]->query_id(),"summoned monster") == -1) { continue; }
      tell_object(ETO,"%^MAGENTA%^Your staff's anti-magic undoes the summoning of "+minions[i]->QCN);
      tell_room(EETO,"%^MAGENTA%^A wave of anti-magic from"+ETOQCN+"'s staff undoes the summoning of"+minions[i]->QCN+".",ETO);
      minions[i]->die();
      count++;

    }
    return 1;
   }
   if(random(1000) < 400){
     switch(random(6)){
      case 0..4:
	    limb = target->return_target_limb();
        tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" strikes the staff into "
                  +target->QCN+"'s "+limb+" with a loud thud.",({target,ETO}));
        tell_object(ETO,"%^MAGENTA%^You strike into "+target->QCN+
            "'s "+limb+" with a loud thud.",target);
        tell_object(target, "%^MAGENTA%^"
         +ETO->QCN+" strikes into your "+limb+" with a loud thud.");
         return roll_dice(2,8)+2;


	  case 5:
            tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+"'s staff glows oddly when the strike connects."
                         ,({target,ETO}));
            tell_object(ETO,"%^MAGENTA%^Words of a spell gather in your mind.");
			tell_object(target,"%^MAGENTA%^"+ETO->QCN+
			  "'s staff glows at it strikes you.");
			new("/cmds/spells/v/_voracious dispelling")->use_spell(ETO,target,15,100,"warlock");
			return roll_dice(1,4)+1;
      }
   }
}
