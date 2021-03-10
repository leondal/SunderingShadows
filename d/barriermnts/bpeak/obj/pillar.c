#include <std.h>
#include <daemons.h>
#include "../bpeak.h"
inherit "/d/common/obj/weapon/giant_club.c";

void create()
{
        ::create();
        set_name("pillar of integrity");
        set_id(({"club","pillar","white pillar","pillar of integrity"}));
        set_short("%^RESET%^P%^YELLOW%^i%^RESET%^llar of In%^YELLOW%^t%^RESET%^egrity");
        set_obvious_short("%^BOLD%^white pillar%^RESET%^");
        set_long("%^BOLD%^This heavy club-like object appears to be made"+
		" from white marble.  It is a hexagonal shaped pillar with"+
		" a shortened handle at the bottom for gripping with both "+
		"hands.   There is a large %^RESET%^%^CYAN%^lapis lazuli%^RESET%^%^BOLD%^ at the end of the "+
		"hilt added to balance out the giant weapon.  The shaft is"+
		" covered with a %^YELLOW%^golden dragon%^WHITE%^ shaped etching that winds"+
		" from hilt to tip.%^RESET%^");
        set_lore("This is the weapon of a long forgotten firbolg "+
        "warrior. He served the god of justice and his philosophy was to slay "+
        "evil immediately.  It is said that he joined a crusade "+
        "to the barrier mountains but was never heard from again.");
        set_property("lore",24);
        set_property("enchantment",(random(2))+3);
        set_value(1600);
        set_hit((:TO,"hit_func":));
        set_wield((:TO,"wieldme":));
        set_unwield((:TO,"removeme":));
		set_item_bonus("bludgeoning resistance",1);
}

int wieldme()
{

  if(ALIGN->is_good(ETO)){
            tell_object(ETO,"The lapis lazuli"+
               " on the hilt flashes in approval.");
            tell_room(EETO,"The lapis lazuli"+
                 " on the hilt of "+ETO->QCN+"'s"+
                 " pillar flashes briefly.",ETO);
            set_item_bonus("magic resistance",1);
            set_item_bonus("attack bonus",2);
            set_item_bonus("damage bonus",2);
            ETO->set_property("good item",1);
            }

    else if(ALIGN->is_neutral(ETO)){
           tell_object(ETO,"The lapis lazuli"+
                " on the hilt glow faintly.");
           tell_room(EETO,"The lapis lazuli "+
                 "on the hilt of "+ETO->QCN+"'s"+
                        " pillar glow faintly.",ETO);
                        set_item_bonus("magic resistance",1);
           set_item_bonus("attack bonus",0);
           set_item_bonus("damage bonus",0);
           ETO->set_property("good item",1);
           }

    else if(ALIGN->is_evil(ETO)){
            tell_object(ETO,"All the lapis lazuli"+
                        " on the hilt flash angrily as you wield the sacred"+
                        " pillar.");
            tell_room(EETO,"The lapis lazuli"+
                        " on the hilt of "+ETO->QCN+"'s"+
                        " pillar flash briefly.",ETO);
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
              " you release your grip on the pillar.");  

  if(ALIGN->is_neutral(ETO)){
      tell_object(ETO,"The lapis lazuli"+
           " in the hilt of the pillar glow faintly as you release"+
           " it.");
      tell_room(EETO,"The lapis lazuli"+
                    " in the hilt of "+ETO->QCN+"'s"+
                    " pillar glow faintly.",ETO);
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
                " with your weapon and it lets out a fearsome roar..");
                tell_object(victim,"%^YELLOW%^"+ETO->QCN+" strikes "+
                " you with a weapon that lets out a roar.",);
                tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" strikes "+
                victim->QCN+" with "+ETO->QO+
                " weapon that lets out a roar.",({ETO,victim}));
                victim->cause_typed_damage(victim,0,roll_dice(1,8)+3,"bludgeoning");
                break;
            case 35..46:
                tell_object(ETO,"%^BOLD%^Time seems to slow down for you,"+
                " allowing you to hammer into "+victim->QCN+" "+
                "with a series of attacks, bashing the pillar "+
                " into "+victim->QP+" repeatedly.");
                tell_object(victim,"%^BOLD%^"+ETO->QCN+" suddenly moves"+
                " swiftly, hammering the pillar into you with unnatural speed.",);
                tell_room(EETO,"%^BOLD%^%"+ETO->QCN+" suddenly"+
                " moves swiftly, hammering into "+victim->QCN+" with a "+
                "series of blurring attacks.",({ETO,victim}));
                victim->cause_typed_damage(victim,0,roll_dice(1,8)+3,"bludgeoning");
                ETO->execute_attack();
                ETO->execute_attack();
        
                break;       
    
            default: 
                tell_object(ETO,"%^BOLD%^The %^YELLOW%^gold serpent%^BOLD%^"+
                " etched on the pillar"+
                " comes to life and erupts from the stone.");

                tell_room(EETO,"%^BOLD%^A translucent gold serpent erupts from "
                +ETO->QCN+"'s pillar.",({ETO}));
                ob2=new(TMONDIR+"serpent");
                ob2->move(EETO);
                ob2->force_me("protect "+ETO->query_name());
                ETO->add_follower(ob2);
                break;
        }
        return 1;
        }
}
