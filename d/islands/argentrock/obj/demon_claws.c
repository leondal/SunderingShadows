#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
        ::create();
        set_name("demon claws");
        set_id(({"demon claws","claws","weapon","black
claws","brace","claw"}));
        set_obvious_short("%^BOLD%^%^BLACK%^A black brace with thick claws%^RESET%^");
        set_short("%^BOLD%^%^BLACK%^D%^RED%^e%^BLACK%^m%^RED%^o%^BLACK%^n"+
                " Claws%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^Three long sharp %^WHITE%^claws"+
                "%^BLACK%^ are attached to a black iron brace.  "+
                "Each thick %^WHITE%^claw%^BLACK%^ extends out five "+
                "inches before they taper to a fine point.  The tips "+
                "of the claws are caked with %^RESET%^%^RED%^dried "+
                "blood%^BOLD%^%^BLACK%^, giving them a sinister look."+
                "  The inside of the black iron brace is lined with "+
                "%^BOLD%^%^RED%^red%^BLACK%^ scaled leather that has"+
                " a slick %^RESET%^o%^BOLD%^i%^RESET%^l%^BOLD%^y%^BLACK%^"+
                " texture to it.%^RESET%^\n");
        set_lore("The new rulers of Argentrock, the fey'ri crafted "+
                "these weapons from the claws of the demons they usurped."+
                "  The demonic claws are mystically attached to a metal "+
                "brace made of black iron.  Using the flesh from the "+
                "demons, the fey'ri weaponsmiths lined the inside of "+
                "each brace for comfort, or just as a reminder of how "+
                "far they have come.  These vicious and deadly claws "+
                "are said to be able to slice through even the strongest"+
                " plate mail as if it was paper.");
      set_property("lore difficulty",13);
      set_property("enchantment",4);
      set_value(3000);
      set_ac(1);
      set_wield((:TO,"wield_func":));
      set_unwield((:TO,"unwield_func":));
      set_hit((:TO,"hit_func":));
	  set_item_bonus("fire resistance",10);
}
int wield_func(string str) {
   if((int)ETO->query_lowest_level() < 25) {
        tell_object(ETO,"%^RED%^The claws refuse you!");
        return 0;
        }
      tell_object(ETO,"%^RED%^You strap on the brace to your arm and "+
                "feel the oily skin coating your flesh.");
      ETO->set_property("evil item",1);
      return 1;
}
int unwield_func(string str) {
        tell_object(ETO,"%^RED%^You slip the brace off, and quickly"+
                " wipe away the oily coating over your flesh.");
        ETO->set_property("evil item",-1);
                return 1;
}
int hit_func(object victim) {
        if(!objectp(TO)) return 1;
        if(!objectp(ETO)) return 1;
        if(!objectp(victim)) return 1;
        if(random(1000) < 220){
        switch(random(50)){
case 0..34:
      tell_object(ETO,"%^RED%^You pierce "+victim->QCN+"'s defenses"+
                " with your claws, violently tearing into "+victim->QO+".");
      tell_object(victim,"%^RED%^"+ETO->QCN+" pierces your defenses with"+
                " "+ETO->QP+" claws, violently tearing into you.",);
      tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" pierces"+
                " "+victim->QCN+"'s defenses with a violent strike from"+
                " "+ETO->QP+" claws.",({ETO,victim}));
	  victim->cause_typed_damage(victim,0,roll_dice(1,8)+4,"slashing");
        break;
case 35..40:
        tell_object(ETO,"%^BOLD%^%^BLACK%^You lunge at "+victim->QCN+" "+
                "with a great leap, driving your claws deep into "+victim->QO+".");
        tell_object(victim,"%^BOLD%^%^BLACK%^"+ETO->QCN+" lunges at you"+
                " with a great leap, driving "+ETO->QP+" claws deep into"+
                " your flesh!",);
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" lunges at  "+
                ""+victim->QCN+" with a great leap, driving "+ETO->QP+" claws"+
                " deep into "+victim->QP+" flesh.",({ETO,victim}));
        ETO->execute_attack();

        break;
case 41..49:
        tell_object(ETO,"%^BOLD%^%^RED%^An oily slick flim coats the surface"+
                " of the claws as you gore "+victim->QCN+".");
        tell_object(victim,"%^BOLD%^%^RED%^"+ETO->QCN+" gores you with"+
                " "+ETO->QP+" claws.\n%^RESET%^%^RED%^ Your blood begins"+
                " to burn!",);
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" gores "+
                ""+victim->QCN+" with "+ETO->QP+" claws.",({ETO,victim}));
        victim->cause_typed_damage(victim,0,roll_dice(1,10)+8,"slashing");
        victim->add_poisoning(10);
        break;
        
default:  tell_object(ETO,"%^BOLD%^%^RED%^Congrats, Turbo.  You get"+
                " the special screwed up message.  Please bug report this"+
                " and what you were doing/fighting when you got this message.");
        break;
                }
                return 1;
        }
}
