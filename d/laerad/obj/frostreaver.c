// fixed wield/special messages and set it to inherit a standard medium axe. Nienne, 2/05.
#include <std.h>
inherit "/d/common/obj/weapon/battle_axe";

void create(){
   ::create();
   set_name("FrostReaver");
   set_id(({"axe","frostreaver","frost reaver","FrostReaver","Frost Reaver"}));
   set_short("%^BOLD%^%^WHITE%^F%^RESET%^%^WHITE%^r%^BOLD%^o%^RESET%^%^WHITE%^s%^BOLD%^t%^RESET%^%^WHITE%^R%^BOLD%^e%^RESET%^%^WHITE%^a%^BOLD%^v%^RESET%^%^WHITE%^e%^BOLD%^r%^RESET%^%^WHITE%^ a%^BOLD%^x%^RESET%^%^WHITE%^e%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A medium axe%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^The head of this massive axe is made from a frost-white %^RESET%^%^WHITE%^c"
"%^BOLD%^r%^RESET%^%^WHITE%^y%^BOLD%^s%^RESET%^%^WHITE%^t%^BOLD%^a%^RESET%^%^WHITE%^l%^BOLD%^ that has been "
"chiseled on both ends to form serrated edges.  It connects seamlessly to an %^RED%^adamantite%^WHITE%^ "
"handle.  The handle has been laced with the scaly hide of some great reptilian beast in order to reinforce "
"the %^RED%^adamantite%^WHITE%^ and offer the wielder a superb grip.%^RESET%^");
   set_weight(10);
   set_value(8000);
   set_type("slashing");
   set_property("enchantment",4);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+TP->QCN+" readies the crystalline axe and suddenly "
"shivers!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^A cold chill runs through your body as you ready the crystalline "
"axe!%^RESET%^");
   ETO->do_damage("torso",random(4));
   return 1;
}

int unwield_func(){
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" releases the crystalline axe and stops shivering.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^The warmth returns to your body as you release the crystalline "
"axe!%^RESET%^");
   return 1;
}

int hit_func(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(random(1000) < 150){
     tell_room(EETO,"%^BOLD%^%^WHITE%^The crystalline axe wielded by "+ETOQCN+" %^YELLOW%^glows %^WHITE%^an "
"icy %^CYAN%^blue%^WHITE%^ as it sinks into "+targ->QCN+"'s flesh, causing "+targ->QO+" to shiver!%^RESET%^",({ETO,targ}));
     tell_object(ETO,"%^BOLD%^%^WHITE%^Your crystalline axe %^YELLOW%^glows %^WHITE%^an icy %^CYAN%^blue "
"%^WHITE%^as it sinks into "+targ->QCN+"'s flesh, causing "+targ->QO+" to shiver!%^RESET%^");
     tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s crystalline axe %^YELLOW%^glows %^WHITE%^an icy%^CYAN%^ "
"blue%^WHITE%^ as it sinks into your flesh, causing a deathly cold chill to run through your body!%^RESET%^");
     return roll_dice(1,12)+1;
   }
}