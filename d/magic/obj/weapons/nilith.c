//Nilith weapon spell

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create(){
   ::create();
   set_name("Deathblow");
   set_id(({"mace","bone mace","steel mace","deathblow","weapon"}));
   set_short("%^BOLD%^%^BLACK%^De%^RED%^a%^RESET%^%^ORANGE%^t"
"%^BOLD%^%^BLACK%^hb%^YELLOW%^l%^GREEN%^o%^BLACK%^w");
   set_obvious_short("%^BOLD%^%^BLACK%^A %^GREEN%^g%^RESET%^%^GREEN%^"
"h%^WHITE%^a%^BOLD%^%^GREEN%^s%^WHITE%^t%^RESET%^%^GREEN%^l"
"%^BOLD%^%^GREEN%^y %^BLACK%^mace of %^RESET%^%^WHITE%^b%^BOLD%^o"
"%^RESET%^ne %^BOLD%^%^BLACK%^and %^RESET%^%^CYAN%^s"
"%^BOLD%^%^WHITE%^t%^RESET%^e%^CYAN%^el%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Gruesome as its intended use, the "
"opulence of this weapon disregards awe in favor of %^RED%^"
"intimidation%^WHITE%^. A simple rod of %^RESET%^%^ORANGE%^le"
"%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ther-wrap%^BOLD%^%^BLACK%^p"
"%^RESET%^%^ORANGE%^ed %^CYAN%^s%^WHITE%^t%^CYAN%^e%^BOLD%^%^WHITE%^e"
"%^RESET%^%^CYAN%^l %^BOLD%^%^WHITE%^forms the shaft of this weapon, "
"about a foot in length. However, starting near the middle upward, it "
"inexplicably twists into a column of vertebrae, curving slightly back"
" to end with a %^RESET%^%^ORANGE%^ye%^YELLOW%^l%^RESET%^%^ORANGE%^lo"
"%^YELLOW%^w%^RESET%^%^ORANGE%^ed %^BOLD%^%^WHITE%^skull. A pair of "
"skeletal hands are fused together with the skull through the palms, "
"grasping fingers of each pointing up or down and tapering to wicked "
"claws. Upon the fore of the skull is etched the image of a "
"%^RESET%^%^ORANGE%^wil%^WHITE%^t%^ORANGE%^ed %^BOLD%^%^WHITE%^flower "
"within the grip of a bony fist, unholy emblem of the %^BLACK%^L"
"%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^dy of B%^WHITE%^o%^RESET%^n"
"%^BOLD%^%^BLACK%^es.%^RESET%^");
   set_value(0);
   set_damage_type("bludgeoning");
   set_hit((:TO,"hit_func":));
   set_property("able to cast",1);
}

int hit_func(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(10)){
     tell_object(ETO,"%^BOLD%^%^RED%^Bile-green fire flares from "
"the eye sockets of the skull to envelope the head of the weapon"
" as you slam it into "+targ->QCN+"!");
     tell_object(targ,"%^BOLD%^%^RED%^Sickly green fire envelopes"
" the head of "+ETO->QCN+"'s mace as it slams into you!");
     tell_room(environment(ETO),"%^BOLD%^%^RED%^The head of "+ETO->QCN+"'s mace "
"bursts into bile-green flames as it slams into "
""+targ->QCN+"!",({ETO,targ}));

     return random(4)+8;
   }
}
