#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create() {
    ::create();
    set_name("mace");
    set_id(({"mace","dark mace","flanged mace","dark flanged mace","steel rose"}));
    set_short("%^BOLD%^%^BLACK%^Guar%^RESET%^d%^BOLD%^%^BLACK%^ian's Steel R%^RESET%^o%^BOLD%^%^BLACK%^se%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^dark flanged mace%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A thick hardwood shaft of %^BOLD%^%^BLACK%^"
"black w%^RESET%^%^ORANGE%^al%^BOLD%^%^BLACK%^nut %^RESET%^%^ORANGE%^offers a "
"sturdy grasp to this mace, with a smooth and glossy finish.  Covered at the "
"end of the grip with a shaped butt of %^BLUE%^darkste"
"el%^ORANGE%^, matching metal also forms the main head of the "
"weapon.  The central shaft narrows into four flanged ridges, all perfectly "
"symmetrical as they radiate out from the centre to allow for equally %^RED%^dev"
"%^ORANGE%^a%^RED%^sta%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^i%^RED%^ng %^ORANGE%^"
"blows from any side.  A perforated pattern of knobs forms each ridge, almost "
"like a spread of petals reaching outwards.  A decorative etching on the inside "
"edge of each has been highlighted with %^BOLD%^%^WHITE%^pl%^RESET%^at%^BOLD%^"
"%^WHITE%^inum%^RESET%^%^ORANGE%^, brightening the otherwise dark weapon"
".%^RESET%^\n");
   set_value(5200);
   set_property("enchantment",5);
   set_item_bonus("attack bonus",2);
   set_lore("Llasbela is perhaps the least well known of the group of "
"adventurers that were betrayed by Sylren the Lordless Knight. Or perhaps it is "
"simply that records of the Akadian are just scarce. It is known that she was "
"part of the heroic adventuring group that was well known for their spectacular "
"discoveries of lost or unknown treasure. What is best known about Llasbela is "
"that she is the one credited for their ability to find these hidden locations, "
"having a strong sense of wander lust that was guided by her faith in the Lady "
"of the Winds. Unfortunately, her choice to follow the ill fated quest into the "
"deep earthen caverns of Ibrandul beside the Knight who claimed no fidelity to "
"either god or liege, far away from the guiding winds of her goddess, resulted "
"in her destruction. Some amongst the Akadian faith will speak of Llasbela as a "
"lesson into what happens when one doesn't follow their own heart but lets the "
"words and deeds of others be the driving force behind them. These same "
"akadians also tell that Llasbela was visited with visions several times by her "
"goddess and it was because of this that it took twenty years to gather the "
"components need to craft the items that would protect them. Akadi was trying "
"to guide her priestess from the ill fated journey. Yet many others say that "
"Akadi would never have done this, for as foolish as Llasbela was in committing "
"to the task, it was her choice and Akadi would never have taken that freedom "
"from her. In the end, the entire party was betrayed by the Knight and it is "
"said that their bodies and their treasures remain deep in the lair of Ibrandul.");
   set_property("lore difficulty",18);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    tell_object(ETO,"%^BOLD%^%^BLACK%^The dark wooden haft fits smoothly in "
"your hand.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" takes up the smooth haft of the "
"mace.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You release hold of the mace.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" releases hold of the mace.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   int tmp;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 1;

   if(!random(8)){
     tell_object(ETO,"%^BOLD%^%^BLACK%^The %^WHITE%^platinum etchings %^BLACK%^on the mace begin to %^BLUE%^glow "
"%^BLACK%^as the flanged ridges extend outward from the center point.  The illusion of a %^RESET%^%^RED%^flower blooming "
"%^BOLD%^%^BLACK%^lasts only a moment as you strike "+targ->QCN+", and the extended ridges drive deeper and cut through "
+targ->QP+" protections!%^RESET%^");
     tell_object(targ,"%^BOLD%^%^BLACK%^The %^WHITE%^platinum etchings %^BLACK%^on the mace begin to %^BLUE%^glow "
"%^BLACK%^as the flanged ridges extend outward from the center point.  The illusion of a %^RESET%^%^RED%^flower blooming "
"%^BOLD%^%^BLACK%^lasts only a moment as "+ETO->QCN+" strikes you, and the extended ridges drive deeper and cut through "
"your protections!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^The %^WHITE%^platinum etchings %^BLACK%^on the mace begin to %^BLUE%^glow "
"%^BLACK%^as the flanged ridges extend outward from the center point.  The illusion of a %^RESET%^%^RED%^flower blooming "
"%^BOLD%^%^BLACK%^lasts only a moment as "+ETO->QCN+" strikes "+targ->QCN+", and the extended ridges drive deeper and cut "
"through "+targ->QP+" protections!%^RESET%^",({ETO,targ}));
     return roll_dice(2,4);
   }

   if(!random(17)){
     tell_object(ETO,"%^CYAN%^A cool invigorating feeling passes through you as you hold the mace aloft, allowing the "
"winds to pass around and through it.  A soft humming noise accompanies the sensation and you feel as though you have "
"been cleansed.%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" looks invigorated as "+ETO->QS+" hold the mace aloft, allowing the winds to "
"pass around and through it.%^RESET%^",ETO);
     TO->set_property("magic",1);
     ETO->do_damage("torso",(-1)*roll_dice(3,6));
     ETO->add_poisoning(-1*(int)ETO->query_poisoning());
     if(ETO->query_condition() < ETO->query_max_stamina()) {
       tmp = 2 * ((int)ETO->query_max_stamina() - (int)ETO->query_condition());
       if(tmp > 10) tmp = 10;
       ETO->use_stamina(-1*tmp);
     }
   }
   return 1;
}
