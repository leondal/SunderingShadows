#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/bastard"; // really just a heavy shortsword, but needed a med exotic for the area. Meh.

void create() {
    ::create();
    set_name("steel gladius");
    set_id(({"sword","gladius","steel gladius","shining gladius","shining steel gladius","resolve","Resolve"}));
    set_short("%^BOLD%^%^BLACK%^Re%^RESET%^s%^BOLD%^%^WHITE%^o%^RESET%^l%^BOLD%^%^BLACK%^ve%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^sh%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^WHITE%^ng s%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^%^WHITE%^l gl%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^i%^BOLD%^%^WHITE%^us%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Lying somewhere in design between a shortsword and a bastard sword, this gladius lacks the "
"reach of the longer weapon but is crafted with its %^RESET%^%^BLUE%^solid %^BOLD%^%^WHITE%^base and much of its weight.  "
"A smooth cylindrical grip is wrapped in bands of %^RESET%^%^ORANGE%^tan%^BOLD%^%^BLACK%^ne%^RESET%^%^ORANGE%^d leather"
"%^BOLD%^%^WHITE%^, to allow a better hold for the wielder, as the pommel is streamlined with the grip rather than raised "
"to prevent the hand's slipping.  The crossguard lifts to a rounded point upon either side, able to catch and deflect blows "
"within the niche between guard and blade, and meeting in the centre with %^RESET%^ri%^BOLD%^%^BLACK%^dg%^RESET%^ed "
"%^BOLD%^%^WHITE%^bands of steel. From this point descends an extended chappe, which seems to have been designed as much to "
"reinforce the blade as to serve as a rainguard.  The fuller extends in a fine line nearly to the tip of the blade, embossed "
"with %^RESET%^%^CYAN%^o%^BOLD%^r%^RESET%^%^CYAN%^na%^BOLD%^t%^RESET%^%^CYAN%^e %^BOLD%^%^WHITE%^markings that might have once "
"held meaning in some ancient tongue.  Initially drawing inwards, the blade itself flares abruptly outwards to a raised edge "
"upon either side near the tip of the blade, and then narrows to meet at an abrupt point.  The entire piece is made of finely "
"polished %^BOLD%^%^BLACK%^ste%^RESET%^e%^BOLD%^%^BLACK%^l%^WHITE%^, with a razor sharp edge from base to tip.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^Blades such as this were favored by the weaponmasters of the Zin'Charu, accustomed as they "
"were to combat in relatively close quarters.  Masters of primarily defensive combat, their style made use of shields and "
"the magical protections offered by their wizards, to get close enough to a foe to take them apart personally.  "
"In the modern age, this combat technique is all but obsolete, given the required patience and tenacity to master such a "
"guarded style.  Most blades of this craft were created with a matching shield, designed as a counterbalance to the weapon's "
"weight.%^RESET%^\n");
   set("no curse",1);
   set_prof_type("gladius");
   set_property("lore difficulty",27);
   set_property("enchantment",4);
   set_value(5500);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    if(userp(ETO) && member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(userp(ETO) && (int)ETO->query_level() < 25) {
      tell_object(ETO,"%^BOLD%^You must train further before you can attempt to use a weapon of this calibre.%^RESET%^");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^Despite its weight, the sword sits easily in your grip.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" takes up the gladius in an easy grip.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You release hold of the gladius' grip and flex your fingers.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" releases hold of the gladius' grip and flexes "+ETO->QP+" fingers.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   object *mytargs;
   int rollchance, myhits, skinned, i;
   targ = ETO->query_current_attacker();
   mytargs = ETO->query_attackers();
   if(random(2500)<500){
     switch(random(400)){
       case 0..99:
       tell_object(ETO,"%^CYAN%^The sword leaves an afterimage of %^RESET%^gl%^BOLD%^e%^RESET%^aming wh%^BOLD%^i%^RESET%^"
"te %^CYAN%^in its wake as you strike out at "+targ->QCN+" with startling speed!%^RESET%^");
       tell_object(targ,"%^CYAN%^The sword leaves an afterimage of %^RESET%^gl%^BOLD%^e%^RESET%^aming wh%^BOLD%^i%^RESET%^"
"te %^CYAN%^in its wake as "+ETO->QCN+" strikes out at you with startling speed!%^RESET%^");
       tell_room(EETO,"%^CYAN%^The sword leaves an afterimage of %^RESET%^gl%^BOLD%^e%^RESET%^aming wh%^BOLD%^i%^RESET%^"
"te %^CYAN%^in its wake as "+ETO->QCN+" strikes out at "+targ->QCN+" with startling speed!%^RESET%^",({ETO,targ}));
       return 5;
       break;

       case 100..199:
       tell_object(ETO,"%^CYAN%^The sword leaves an afterimage of %^RESET%^gl%^BOLD%^e%^RESET%^aming wh%^BOLD%^i%^RESET%^"
"te %^CYAN%^in its wake as you strike out at "+targ->QCN+" with startling speed!%^RESET%^");
       tell_object(targ,"%^CYAN%^The sword leaves an afterimage of %^RESET%^gl%^BOLD%^e%^RESET%^aming wh%^BOLD%^i%^RESET%^"
"te %^CYAN%^in its wake as "+ETO->QCN+" strikes out at you with startling speed!%^RESET%^");
       tell_room(EETO,"%^CYAN%^The sword leaves an afterimage of %^RESET%^gl%^BOLD%^e%^RESET%^aming wh%^BOLD%^i%^RESET%^"
"te %^CYAN%^in its wake as "+ETO->QCN+" strikes out at "+targ->QCN+" with startling speed!%^RESET%^",({ETO,targ}));
       if((int)ETO->is_wearing_type("shield")) {
         tell_object(ETO,"%^BOLD%^%^GREEN%^You follow up your strike with an unexpected blow from your shield, knocking "
+targ->QCN+" offbalance!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+" follows up "+ETO->QP+" strike with an unexpected blow from "
+ETO->QP+" shield, knocking you offbalance!%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" follows up "+ETO->QP+" strike with an unexpected blow from "
+ETO->QP+" shield, knocking "+targ->QCN+" offbalance!%^RESET%^",({ETO,targ}));
         targ->set_paralyzed((random(5)+20),"%^BOLD%^%^GREEN%^You're trying to regain your balance!%^RESET%^");
       }
       return 5;
       break;

       case 200..299:
       ETO->execute_attack();
       tell_object(ETO,"%^BOLD%^%^BLUE%^You use the momentum of your strike to step past "+targ->QCN+" and pivot, "
"delivering a vicious backhand slash!%^RESET%^");
       tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" uses the momentum of "+ETO->QP+" strike to step past you and pivots, "
"delivering a vicious backhand slash!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" uses the momentum of "+ETO->QP+" strike to step past "+targ->QCN+" and "
"pivots, delivering a vicious backhand slash!%^RESET%^",({ETO,targ}));
       return 1;
       break;

       case 300..399:
       tell_object(ETO,"%^RED%^A short leap lifts your feet from the ground as you bring the sword down in an overhead arc, "
"putting all of your weight behind the blow!%^RESET%^");
       tell_object(targ,"%^RED%^A short leap lifts "+ETO->QCN+"'s feet from the ground as "+ETO->QS+" brings the sword down in "
"an overhead arc, putting all of "+ETO->QP+" weight behind the blow!  The sheer force of the impact leaves you seeing %^YELLOW%^s"
"%^WHITE%^t%^YELLOW%^ars%^RESET%^%^RED%^!%^RESET%^");
       tell_room(EETO,"%^RED%^A short leap lifts "+ETO->QCN+"'s feet from the ground as "+ETO->QS+" brings the sword down in "
"an overhead arc, putting all of "+ETO->QP+" weight behind the blow!%^RESET%^",({ETO,targ}));
       targ->set_temporary_blinded(1);
       return 10;
       break;
     }
   }
   return 1;
}