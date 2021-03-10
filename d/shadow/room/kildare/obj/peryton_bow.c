//drop from the sister/peryton queen in Kildare Glen, based in part on the rhino bow ~Circe~ 9/1/19
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/lrweapon/longbow.c";

void create(){
   ::create();
   set_id(({"bow","longbow","long bow","peryton bow","feathered longbow","hornbow","bow of horn","reach of the abyss","abyss bow"}));
   set_name("feathered longbow");
   set_short("%^BOLD%^%^BLACK%^Re%^RESET%^a%^BOLD%^%^BLACK%^ch of the A%^RED%^b%^BLACK%^y%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^s%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^y %^RESET%^%^GREEN%^fe%^BOLD%^a%^RESET%^%^GREEN%^th%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^red %^BOLD%^%^BLACK%^longbow%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Crafted from an ancient %^RESET%^bone antler %^ORANGE%^stained %^BOLD%^%^BLACK%^dark %^RESET%^%^ORANGE%^with dried %^RED%^bl%^BOLD%^o%^RESET%^%^RED%^od %^ORANGE%^and %^RED%^vi%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^cera%^ORANGE%^, this longbow is adorned with %^GREEN%^m%^BOLD%^a%^BLACK%^l%^GREEN%^a%^RESET%^%^GREEN%^c%^BOLD%^h%^BLACK%^i%^GREEN%^t%^RESET%^%^GREEN%^e feathers%^ORANGE%^. It features no other decoration, though the %^RESET%^bone %^ORANGE%^has been nicked and scarred in various places, and a plain %^BOLD%^%^BLACK%^leather wrap %^RESET%^%^ORANGE%^provides a firm handhold. The bow thrums with %^CYAN%^energy%^ORANGE%^ that seems focused in the %^RESET%^s%^BOLD%^a%^BLACK%^l%^WHITE%^t%^RESET%^-%^BOLD%^a%^BLACK%^n%^WHITE%^d%^RESET%^-%^BOLD%^p%^BLACK%^e%^WHITE%^p%^RESET%^p%^BOLD%^e%^BLACK%^r hair %^RESET%^%^ORANGE%^that has been waxed and strung on the bow.%^RESET%^");
   set_lore("This bow has been crafted from the antler of Helle, the scourge of Kildare Glen. Some see this bow as evidence that she has been ultimately defeated, but sages warn that her kind is harder to kill than one might expect.");
   set_value(0);
   set_property("no curse",1);
   set_property("enchantment",3);
   set_lrhit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_overallStatus(220);
}


int wield_func(){
   tell_object(ETO, "%^BOLD%^%^BLACK%^As you grip the bow, you hear murmurs from the Abyss.%^RESET%^");
   tell_room(EETO, "%^BOLD%^%^BLACK%^A faint murmuring rises on the air as "+ETOQCN+" wields the bow.%^RESET%^",ETO);
   return 1;
}


int unwield_func(){
   tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the power of the %^BLACK%^Abyss %^WHITE%^fade as you unwield the bow.%^RESET%^");
   tell_room(EETO, ""+ETOQCN+" lowers "+ETO->QP+" bow as the area grows quieter.",ETO);
   return 1;
}

int hit_func(object target){
   object ob;
   if(!objectp(target)) { return 0; }
   if(!objectp(ETO)) { return 0; }
   if(!living(ETO)) { return 0; }
   if(random(1000) > 400) { return roll_dice(1,6)+random(4); }
   switch(random(10)){
      case 0..2:
         tell_room(EETO,"%^RESET%^%^GREEN%^With blinding speed, "+ETOQCN+" fires a second arrow at "+target->QCN+"!%^RESET%^",({target,ETO}));
         tell_object(ETO,"%^RESET%^%^GREEN%^With blinding speed, you fire a second arrow at "+target->QCN+"!");
         tell_object(target,"%^RESET%^%^GREEN%^"+ETO->QCN+"'s hands seem to blur as "+ETO->QS+" knocks another arrow and fires it at you!%^RESET%^");
         ETO->execute_attack();
         return roll_dice(2,4)+random(4);
         break;
      default:
         if(((int)target->query_stats("dexterity") + random(10)) < ((int)ETO->query_stats("dexterity") + random(10))){
            tell_object(target,"%^BOLD%^%^RED%^"+ETOQCN+"'s eyes blaze as "+ETO->QS+" fires an arrow that pierces your heart!%^RESET%^");
            tell_object(ETO,"%^BOLD%^%^RED%^Your eyes blaze as you fire an arrow that pierces "+target->QCN+"'s heart!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+"'s eyes blaze as "+ETO->QS+" fires an arrow that pierces "+target->QCN+"'s heart!%^RESET%^",({target,ETO}));
            if(member_array("torso",target->query_limbs())){
                tell_object(ETO,"%^BOLD%^It seems "+target->QCN+" does not have a torso! Contact a wiz if that seems weird.%^RESET%^");
               return 1;
            }
            target->cause_typed_damage(target,"torso",roll_dice(4,8),"piercing");
            target->set_paralyzed(4,"You are recovering from an arrow to your heart!");
            return roll_dice(2,4);
         }else{
            tell_object(target,"%^RESET%^%^RED%^"+ETOQCN+"'s eyes blaze as "+ETO->QS+" fires an arrow at you, but you dodge the worst of it!%^RESET%^");
            tell_object(ETO,"%^RESET%^%^RED%^Your eyes blaze as you fire an arrow at "+target->QCN+", but "+target->QS+" dodges the worst of it!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+"'s eyes blaze as "+ETO->QS+" fires an arrow at "+target->QCN+", but "+target->QS+" avoids the worst of it!%^RESET%^",({target,ETO}));
            if(member_array("torso",target->query_limbs())){
               tell_object(ETO,"%^BOLD%^It seems "+target-QCN+" does not have a torso! Contact a wiz if that seems weird.%^RESET%^");
               return 1;
            }
            target->cause_typed_damage(target,"torso",roll_dice(2,8),"piercing");
            return roll_dice(1,4);
         }
   }
   return random(4)+1;
}
