#include <std.h>
#include <daemons.h>
#include "../elf.h"
inherit "/d/common/obj/weapon/giant_bastard.c";

void create()
{
        ::create();
        set_name("Elven Curved Blade");
        set_id(({"blade","curved blade","elven curved blade","sword"}));
        set_short("%^RESET%^Elven Curved Blade%^RESET%^");
        set_obvious_short("%^BOLD%^Giant Curved Blade%^RESET%^");
        set_long("This is a giant elven curved blade.  It is made from a "+
        "mix of iron and silver for the blade.  The hilt is made from a"+
        " jade infused wood.   Silver filled etchings of serpents "+
        "are on either side of the blade.%^RESET%^");
        set_lore("This is the weapon of a long forgotten voadkyn "+
        "warrior. He served the elven gods defending against human crusaders.  "+
        "He made it his mission to hunt down the undead overlords leading "+
        "The crusade in the shadows only to be murdered by a vampire "+
        "in his sleep.");
        set_property("lore",34);
        set_property("enchantment",(random(2))+5);
        set_value(1600);
        set_hit((:TO,"hit_func":));
        set_wield((:TO,"wieldme":));
        set_unwield((:TO,"removeme":));
		set_item_bonus("divine resistance",5);
        set_damage_type("silver");
}

int wieldme()
{

  if(ALIGN->is_good(ETO)){
            tell_object(ETO,"%^GREEN%^The jade"+
               " on the hilt flashes %^BOLD%^brightly in approval.");
            tell_room(EETO,"%^GREEN%^The jade"+
                 " on the hilt of "+ETO->QCN+"'s"+
                 " pillar flashes briefly.",ETO);
            set_item_bonus("magic resistance",2);
            set_item_bonus("attack bonus",2);
            set_item_bonus("damage bonus",2);
            ETO->set_property("good item",1);
            }

    else if(ALIGN->is_neutral(ETO)){
           tell_object(ETO,"%^GREEN%^The jade"+
                " on the hilt glow faintly.");
           tell_room(EETO,"%^GREEN%^The jade "+
                 "on the hilt of "+ETO->QCN+"'s"+
                        " pillar glow faintly.",ETO);
           set_item_bonus("magic resistance",1);
           set_item_bonus("attack bonus",0);
           set_item_bonus("damage bonus",0);
           ETO->set_property("good item",1);
           }

    else if(ALIGN->is_evil(ETO)){
            tell_object(ETO,"The jade"+
                        " on the hilt flashes angrily as you wield the sacred"+
                        " sword.");
            tell_room(EETO,"The jade"+
                        " on the hilt of "+ETO->QCN+"'s"+
                        " sword flash briefly.",ETO);
            set_item_bonus("damage resistance",-10);
            set_item_bonus("attack bonus",-1);
            set_item_bonus("damage bonus",-1);
            ETO->set_property("good item",1);
			}
   return 1;
}

int removeme()
{
  if(ALIGN->is_good(ETO))
       tell_object(ETO,"You feel less protected as"+
              " you release your grip on the sword.");  

  if(ALIGN->is_neutral(ETO)){
      tell_object(ETO,"The jade"+
           " in the hilt of the sword glows faintly as you release"+
           " it.");
      tell_room(EETO,"The jade"+
                    " in the hilt of "+ETO->QCN+"'s"+
                    " sword glows faintly.",ETO);
				}
  if(ALIGN->is_evil(ETO))
            tell_object(ETO,"This weapon seems very happy"+
                        " to be rid of you.");
             
  ETO->set_property("good item",-1);
  return 1;
}


int hit_func(object victim) {
        object ob2;
		int bonus;
        if(!objectp(TO)) return 1;
        if(!objectp(ETO)) return 1;
        if(!objectp(victim)) return 1;
		if(ALIGN->is_evil(ETO)) return 1;
		if(ALIGN->is_neutral(ETO)) bonus = 1;
		if(ALIGN->is_good(ETO)) bonus = 10;
        if(random(1000) < 220){
		
        switch(random(56)+bonus)
        {       
            case 0..34:
                tell_object(ETO,"%^YELLOW%^You strike "+victim->QCN+
                " with your weapon and it slashes them deeply.");
                tell_object(victim,"%^YELLOW%^"+ETO->QCN+" strikes "+
                " you with a weapon that cuts deep.",);
                tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" strikes "+
                victim->QCN+" with "+ETO->QO+
                " weapon that cuts deep.",({ETO,victim}));
                victim->cause_typed_damage(victim,0,roll_dice(1,8)+3,"slashing");
                break;
            case 35..46:
                tell_object(ETO,"%^GREEN%^Time seems to slow down for you,"+
                " allowing you to slah into "+victim->QCN+" "+
                "with a series of attacks, hacking "+
                " into "+victim->QP+" repeatedly.");
                tell_object(victim,"%^GREEN%^"+ETO->QCN+" suddenly moves"+
                " swiftly, clashing the sword into you with unnatural speed.",);
                tell_room(EETO,"%^GREEN%^"+ETO->QCN+" suddenly"+
                " moves swiftly, slashing into "+victim->QCN+" with a "+
                "series of blurring attacks.",({ETO,victim}));
                victim->cause_typed_damage(victim,0,roll_dice(1,8)+8,"slashing");
                victim->cause_typed_damage(victim,0,roll_dice(1,8)+8,"slashing");
            
              
        
                break;       
    
            default: 
                tell_object(ETO,"%^GREEN%^The serpent"+
                " etched on the sword"+
                " comes to life and erupts from the blade.");

                tell_room(EETO,"%^GREEN%^A translucent green serpent erupts from "
                +ETO->QCN+"'s sword.",({ETO}));
                ob2=new(MON"serpent");
                ob2->move(EETO);
                ob2->force_me("protect "+ETO->query_name());
                ETO->add_follower(ob2);
                break;
        }
        return 1;
        }
}