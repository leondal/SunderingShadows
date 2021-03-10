#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPON;

void create() {
    ::create();
    set_id(({"katar","Katar","sacrificial katar","Sacrificial Katar","damascus katar","rune-etched katar","rune etched katar"}));
    set_name("katar");
    set_obvious_short("%^BLACK%^%^BOLD%^flawless %^RED%^r%^RESET%^%^RED%^un%^BOLD%^e-e%^RESET%^%^RED%^tc%^BOLD%^he%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^katar%^RESET%^");
    set_short("%^RESET%^%^RED%^Sac%^BOLD%^r%^RESET%^%^RED%^ifi%^BOLD%^c%^RESET%^%^RED%^ial "
"%^WHITE%^%^BOLD%^K%^RESET%^%^WHITE%^a%^BOLD%^t%^RESET%^%^WHITE%^a%^BOLD%^r%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^A "
"%^WHITE%^br%^RESET%^%^WHITE%^i%^BOLD%^gh%^RESET%^%^WHITE%^t%^BOLD%^ly%^BLACK%^ polished, eight-inch "
"long blade forms the central feature of this weapon, wider in the centre and gradually thinning to a "
"razor-sharp edge on either side.  Twin blades flank the first, mirror-images of each other, more "
"slender than the central blade but just as long and equally sharp.  All three blades are set seamlessly "
"within the base, which has been shaped to form a comfortable handle for the wielder to grip, and is "
"covered by a broad metal sheaf to protect the hand.  A metal of undetermined type forms both the blades "
"and base of this incredibly light weapon, which fades through %^WHITE%^lighter%^BLACK%^ and "
"%^RESET%^%^WHITE%^darker%^BLACK%^%^BOLD%^ shades of silver in a watery pattern.  Upon the protective "
"sheaf, several mysterious runes have been engraved, highlighted with "
"%^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^b%^BOLD%^y%^BLACK%^ dust. The blades have all been tinted a "
"%^RESET%^%^RED%^deep-red%^BLACK%^%^BOLD%^ hue, as if they were eternally stained with blood.%^RESET%^");
   set_type("slashing");
   set_prof_type("knuckles");
   set_lore("%^WHITE%^%^BOLD%^This katar was rumoured to be the sacred ritual weapon of a now-destroyed "
"cult, created for the human magus Archemond.  It was forged from the metal damascus, of which "
"knowledge of crafting has been lost to the ages.  Imbued within it was an enchantment which drew "
"strength from the wielder, allowing it to grow more powerful when carried by one of a %^BLACK%^dark "
"soul%^WHITE%^.%^RESET%^");
   set_property("lore difficulty",15);
   set_weight(5);
   set_size(1);
   set_wc(1,6);
   set_large_wc(1,4);
   set_weapon_speed(2);
   set_property("enchantment",2);
   set_value(1500);
   set_ac(1);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    int x;
    if(ETO->query_highest_level() < 15) {
        tell_object(ETO,"%^WHITE%^%^BOLD%^The katar repels your hand forcibly.%^RESET%^");
        return 0;
    }
    if(!ETO->query_invis()) {
        tell_room(environment(ETO),"%^WHITE%^%^BOLD%^"+ETOQCN+" slides "+ETO->QP+" hand around the "
"grip of the katar, and the patterned runes %^RED%^flash%^WHITE%^ momentarily.%^RESET%^",ETO);
    }
    x = TO->query_property("enchantment");

    if(ALIGN->is_good(ETO) && x > 0) {
      while((int)TO->query_property("enchantment") != 1) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",1);
      }
    }
    if(ALIGN->is_neutral(ETO) && x >= 0) {
      while((int)TO->query_property("enchantment") != 2) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",2);
      }
    }            
    if(ALIGN->is_evil(ETO) && x >= 0) {
      while((int)TO->query_property("enchantment") != 3) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",3);
      }
    }
    tell_object(ETO,"%^WHITE%^%^BOLD%^You slide your hand around the katar's grip, mesmerised as the "
"runes %^RED%^flash%^WHITE%^ momentarily.%^RESET%^");
    ETO->set_property("evil item",1);
    return 1;
}

int unwield_fun() {
   tell_room(environment(ETO),"%^WHITE%^%^BOLD%^The runes on the katar %^RED%^flash%^WHITE%^ once as "
+ETOQCN+" slides "+ETO->QP+" hand free.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The runes on the katar %^RED%^flash%^WHITE%^ once as you slide your "
"hand free.%^RESET%^");
   ETO->set_property("evil item",-1);
   return 1;
}

int hit_fun (object target) {
    int dam;
    if(!random(14)){
      switch(random(12)) {
        case 0..5:
        tell_room(EETO,"%^BLUE%^The katar's %^RED%^blood-red%^BLUE%^ blades glow as "+ETOQCN+" slashes "
"the weapon violently through "+target->QCN+"'s flesh!%^RESET%^",ETO);
        tell_object(ETO,"%^BLUE%^The katar's %^RED%^blood-red%^BLUE%^ blades glow as you slash it "
"violently through "+target->QCN+"'s flesh!%^RESET%^");
        tell_object(target,"%^BLUE%^The katar's %^RED%^blood-red%^BLUE%^ blades glow as "+ETOQCN+
" slashes the weapon violently through your flesh!%^RESET%^");
        target->do_damage(target->return_target_limb(),roll_dice(2,4)+2);
        break;

        case 6..8:
        tell_room(EETO,"%^RED%^The runes on "+ETOQCN+"'s katar flash %^BOLD%^brightly%^RESET%^%^RED%^ as "
"they hit "+target->QCN+", who seems to weaken from the attack!%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^The runes on your katar flash %^BOLD%^brightly%^RESET%^%^RED%^, as you "
"feel life drawn from "+target->QCN+" to you!%^RESET%^");
        tell_object(target,"%^RED%^The runes on "+ETOQCN+"'s katar flash "
"%^BOLD%^brightly%^RESET%^%^RED%^ as it hits you, draining your life!%^RESET%^");
        dam = random(5)+8;
        TO->set_property("magic",1);
        ETO->do_damage("torso",(-1)*dam);
        target->do_damage("torso",dam);
        TO->remove_property("magic");
        break;

        case 9..11:
        ETO->execute_attack();
        tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+"'s eyes glitter wickedly as "+ETO->QS+" turns "
+ETO->QP+" hand, bringing the katar back to slash %^RED%^viciously%^BLACK%^ at "+target->QCN+ " 
again!%^RESET%^",ETO);
        tell_object(ETO,"%^BLACK%^%^BOLD%^Sudden bloodlust fills your mind, and you turn your hand back "
"to slash %^RED%^viciously%^BLACK%^ at "+target->QCN+" a second time!%^RESET%^");
        tell_object(target,"%^BLACK%^%^BOLD%^"+ETOQCN+"'s eyes glitter wickedly as "+ETO->QS+" turns "
+ETO->QP+" hand, bringing the katar back to slash %^RED%^viciously%^BLACK%^ at you again!%^RESET%^");
        return 1;
        break;
      }
    }
}
