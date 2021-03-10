#include <std.h>
#include "../tecqumin.h"
inherit "/d/common/obj/weapon/longsword";

int FLAG;

void create(){
   ::create();
   set_id(({"sword","macana","Macana","wooden sword","wood sword","macana of the wilds","Macana of the Wilds"}));
   set_name("Macana of the Wilds");
   set_obvious_short("%^RESET%^%^ORANGE%^a sharp wooden sword%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Macana of the %^GREEN%^W%^BOLD%^i"
      "%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^%^GREEN%^s%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This longsword is made entirely of "+
      "a single piece of Chonta wood.  The %^GREEN%^blade %^ORANGE%^"+
      "has been sharpened on both sides, and despite its wooden "+
      "nature, it can slice as easily as a razor.   The %^GREEN%^"+
      "blade %^ORANGE%^is decorated with %^RESET%^designs %^ORANGE%^"+
      "from %^BOLD%^%^GREEN%^nature%^RESET%^%^ORANGE%^ - thick "+
      "%^BOLD%^%^GREEN%^ban%^YELLOW%^d%^GREEN%^s of i%^YELLOW%^v"+
      "%^GREEN%^y %^RESET%^%^ORANGE%^border images of %^BOLD%^"+
      "%^BLACK%^jaguars %^RESET%^%^ORANGE%^prowling through the "+
      "%^GREEN%^trees%^ORANGE%^.  Intertwined through it all are "+
      "countless hidden %^BOLD%^%^BLACK%^snakes%^RESET%^%^ORANGE%^, "+
      "each poised to strike.  A %^GREEN%^serpentine crossguard "+
      "%^ORANGE%^has been carved from the wood, as well as a "+
      "sturdy hilt.  The hilt is covered in strips of %^RESET%^thin "+
      "hide %^ORANGE%^that looks suspiciously human.%^RESET%^");
   set_lore(
      "Crafted by the lost warriors of the Tecqumin, this sword "+
      "was given to young warriors upon their ascention into "+
      "adulthood.  When given, the sword is completely smooth.  "+
      "As the young man ages and faces battles, he adds images of his "+
      "foes to the blade - ever mindful of the dominion of "+
      "Quali, the great spirit of nature.  As such, these swords "+
      "all feature similar images, though any Tecqumin warrior "+
      "could tell at a glance which sword was his.");
   set_property("lore difficulty",18);
   set_value(350+random(76));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",3);
   set_item_owner_prop("multiple_owners",0);
   FLAG = 0;
}

void init(){
        ::init();
        if(!interactive(ETO)) return;
        TO->add_item_owner(ETOQN);
}

int wield_func(string str){
   if((string)ETO->query_race() == "yuan-ti") return 1;
   if(!TO->query_owns_item(ETOQN)){               
      tell_object(ETO,"%^ORANGE%^The spirit of the macana rejects you!%^RESET%^");
      return 0;
   }
   tell_object(ETO,"%^RESET%^%^ORANGE%^The %^GREEN%^spirit %^ORANGE%^of "+
      "the macana flows through you!%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+"'s eyes gain intensity as "+
      ""+ETO->QS+" wields the wooden sword.%^RESET%^",ETO);
   if(ETO->is_class("ranger")){
      if((int)ETO->query_guild_level("ranger") < 35){
         return 1;
      }else{
         if((int)TO->query_property("enchantment") < 0){
            return 1;
         }else{
            FLAG = 1;
            TO->remove_property("enchantment");
            TO->set_property("enchantment",5);
            if(TO->query_property("enchantment")< 5){
               remove_property("enchantment");
               set_property("enchantment",5);
            }
         }
      }
   }
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^You feel the %^GREEN%^spirit "+
      "%^ORANGE%^of the forest recede as you lower the sword.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^The intensity in "+ETOQCN+"'s eyes "+
      "fades as "+ETO->QS+" lowers the sword.%^RESET%^",ETO);
   if(FLAG == 1){
      TO->remove_property("enchantment");
      TO->set_property("enchantment",3);
      if(TO->query_property("enchantment")< 3){
         remove_property("enchantment");
         set_property("enchantment",3);
      FLAG = 0;
      }
   }
   return 1;
}

int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(8)) {
       switch(random(22)){
          case 0..11:  tell_object(ETO,"%^RESET%^%^GREEN%^The sword "+
                         "spins smoothly in your hands, cutting "+
                         ""+vic->QCN+" viciously!%^RESET%^");
                       tell_object(vic,"%^RESET%^%^GREEN%^"+ETOQCN+" "+
                         "spins "+ETO->QP+" sword smoothly, cutting "+
                         "you viciously!%^RESET%^");
                       tell_room(EETO,"%^RESET%^%^GREEN%^"+ETOQCN+" "+
                         "spins "+ETO->QP+" sword smoothly, cutting "+
                         ""+vic->QCN+" viciously!%^RESET%^",({ETO,vic}));
                       set_property("magic",1);
                       vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(1, 10) + 7, "slashing");
                       set_property("magic",-1);
                       break;
          case 12..17: tell_object(ETO,"%^BOLD%^%^GREEN%^The "+
                          "serpents upon your sword's crossguard "+
                          "suddenly spring to life, biting "+vic->QCN+"!"+
                          "%^RESET%^",ETO);
                       tell_object(vic,"%^BOLD%^%^GREEN%^You feel a "+
                          "sudden %^RED%^bite%^GREEN%^ as the serpents "+
                          "on "+ETOQCN+"'s sword spring to life!%^RESET%^");
                       tell_room(EETO,"%^BOLD%^%^GREEN%^In disbelief, you "+
                          "see the serpents on "+ETOQCN+"'s sword "+
                          "spring to life and %^RED%^bite %^GREEN%^"+
                          ""+vic->QCN+"!",({ETO,vic}));
                       set_property("magic",1);
                       vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(1, 4) + 5, "piercing");
                       set_property("magic",-1);
                       if(!"daemon/saving_d"->saving_throw(vic,"paralyzation_poison_death",-2)){
                          tell_object(vic,"%^BOLD%^%^RED%^You feel poison "+
                             "burning through your veins!%^RESET%^");
                          vic->add_poisoning(20);
                       }
                       break;
          case 18..21: 
                       tell_object(ETO,"%^RESET%^%^ORANGE%^You fling out your "+
                          "hand toward "+vic->QCN+", calling upon the "+
                          "might of nature!%^RESET%^"); 
                       tell_object(vic,"%^RESET%^%^ORANGE%^"+ETOQCN+" speaks "+
                          "incomprehensible words as "+ETO->QS+" flings out "+
                          ""+ETO->QP+" toward you!%^RESET%^");
                       tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" speaks "+
                          "incomprehensible words as "+ETO->QS+" flings out "+
                          ""+ETO->QP+" toward "+vic->QCN+"!%^RESET%^",({ETO,vic}));
                       new("/cmds/priest/_thorn_spray")->use_spell(ETO,vic,5);
                     break;
          default:  break;
       }
    return random(3);
    }
}