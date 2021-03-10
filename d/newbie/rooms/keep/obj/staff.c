#include <std.h>
inherit "/d/common/obj/weapon/mstaff.c";

void create() {
   ::create();
   set_id(({"staff","fine staff","wooden staff","fine wooden staff","stave","drakeclaw stave","drakeclaw staff"}));
   set_short("%^RESET%^%^RED%^Drakeclaw Stave%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A fine wooden staff%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a fine wooden staff made out of "
"%^RED%^dark mahogany wood%^ORANGE%^.  %^BOLD%^%^CYAN%^Arcane symbols "
"%^RESET%^%^ORANGE%^have been etched artistically up its length in flowing "
"script.  Two %^YELLOW%^golden bands %^RESET%^%^ORANGE%^bind the staff, one at "
"its base and one halfway up its length.  The top is wrapped in the carved, "
"reptilian form of a %^BOLD%^%^RED%^dragon%^RESET%^%^ORANGE%^, which holds its "
"tail and both claws wrapped around a %^CYAN%^translucent "
"orb%^ORANGE%^.%^RESET%^\n");
   set_lore("From your studies you recall that the master of Keep Kilgore, "
"northeast of Offestry, was a man known as Davros.  He was reputed to be a mage "
"of some minor skill, and spent much of his time researching dragons and rumors "
"of their magical abilities.  Years later in 596, a strange sickness swept "
"through the Kilgore family, leaving no surviving relatives, and allowing the "
"keep to fall into disrepair.");
   set_property("lore difficulty",4);
   set_value(20);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"hitme":));
   set_weight(3); // to ensure no bugs with quest
}

int wieldme() {
    if (!ETO->query_property("silent_wield")) {
        tell_room(EETO, "%^ORANGE%^The staff's orb takes on a %^CYAN%^soft glow%^ORANGE%^.%^RESET%^");
    }
    return 1;
}

int removeme() {
    if (!ETO->query_property("silent_wield")) {
        tell_room(EETO, "%^ORANGE%^The orb atop the staff stops glowing again.%^RESET%^");
    }
    return 1;
}

int hitme(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(6)) {
     tell_object(ETO,"%^ORANGE%^The orb upon the staff glitters %^BOLD%^%^CYAN%^brightly %^RESET%^%^ORANGE%^as your "
"staff connects with "+targ->QCN+"!%^RESET%^");
     tell_object(targ,"%^ORANGE%^The orb upon "+ETO->QCN+"'s staff glitters %^BOLD%^%^CYAN%^brightly "
"%^RESET%^%^ORANGE%^as "+ETO->QS+" hits you!%^RESET%^");
     tell_room(EETO,"%^ORANGE%^The orb upon "+ETO->QCN+"'s staff glitters %^BOLD%^%^CYAN%^brightly "
"%^RESET%^%^ORANGE%^as "+ETO->QS+" hits "+targ->QCN+"!%^RESET%^",({ETO,targ}));
     return 1;
   }
}
