//knife for elf vamp coded by hades 9/5/20
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
    ::create();
    set_name("betrayer's edge");
    set_id( ({"knife","dark knife","edge","betrayer's edge"}) );
    set_short("%^BOLD%^%^RED%^Betrayer's edge%^RESET%^");
    set_obvious_short("%^RED%^a dark knife%^RESET%^");
    set_long(
       "This is a sinister knife with a blackened blade."+
       "  It has a black hilt that has several dark "+
       "stones embeded into it.  The whole weapon "+
       "pulses with negative energy.  "+
       "The iron is cold to the touch."
    );
    set_lore("This knife fits the murder weapon"+
    " description of a royal couple in a long "+
    "forgotten kingdom.  It was said that the elves"+
    " princess and the human prince were killed by an elven"+
    " diplomat.  Their two children, a brother and sister "+
    "were left to fend for themselves after.");
    set_property("lore difficulty",35);
    set_value(1000);
    set_property("enchantment",3+random(3));
    set_damage_type("cold iron");
    set_wield((:TO,"extra_wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"extra_hit":));
    set_item_bonus("stealth", 4);
    set_item_bonus("reflex", 4);  
    set_item_bonus("perception", 4);  
    set_item_bonus("bonus_spell_slots_5",1);
}

int extra_wield(){
    if (ETO->query_property("good item")) {
        tell_object(ETO, "The knife rejects you while you are using such goodly items!");
        return 0;
    }
   
   tell_object(ETO,"%^BLUE%^The knife glows with a pale light.");
   tell_room(EETO,"%^RED%^"+ETOQCN+" looks sinister "+
         "as "+ETO->QP+" knife glows darkly.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
   return 1;
}

int removeme(){
   ETO->set_property("evil item",-1);
   return 1;
}

int extra_hit(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(random(1000) < 200){
     tell_object(ETO,"%^RED%^A wave of negative energy pulses from the knife!");
     tell_room(EETO,"%^RED%^The knife wielded by "+ETOQCN+" pulses "+
      "with negative energy as it slashes "+targ->QCN+"'s body.",({ETO,targ}));
     tell_object(targ,"%^BOLD%^%^RED%^The knife wielded by "+ETOQCN+" "+
      "pulses with negative energy as it stabs into you!");

     
     targ->cause_typed_damage(targ,0,roll_dice(3,20),"negative energy");
   }
   return 0;
}
