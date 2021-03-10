//updated by Circe 6/1/04 with new desc, lore, etc by Shar
//made it a true long range weapon and changed wield message to check for
//actually having arrows.  Styx 7/14/01
//updated to the new ranged combat. N, 12/13.

#include <std.h>
inherit "/d/common/obj/lrweapon/shortbow";

void create() {
    ::create();
    set_name("bow");
    set_id(({"bow","goblin bow","headhunter's bow","shortbow","short bow","warped bow","wooden bow","warped wooden shortbow"}));
    set_short("%^RESET%^%^ORANGE%^Headhunter's Bow%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^warped wooden shortbow%^RESET%^");
    set_long("%^ORANGE%^This slightly warped short bow looks well aged and old, "
"and it's obvious the bow has not been cared for.  With the grime and mud that "
"covers the bow, the wood used in its construction is hard to determine.  "
"Goblinoid fetishes hang from the top of the bow, a %^BOLD%^%^WHITE%^finger bone"
"%^RESET%^%^ORANGE%^ from a gnome here, an %^GREEN%^elven ear%^RESET%^%^ORANGE%^ "
"there, and even what looks to be the preserved %^BLUE%^eyeball%^RESET%^%^ORANGE%^ "
"of some kind of humanoid.");
    set_lore("The Headhunter's Bow is used by the trained archers of the goblins.  "
"These goblin rangers, as they are called (though they possess no ranger skills or "
"respect for nature) are the hunters and trappers for a goblin community.  In times "
"of warfare, the goblin archers are able to provide a brutal and savage rain of arrows "
"down onto their foes.  They have earned the name of headhunters, because they often "
"aim for one's head.");
    set_property("lore difficulty",6);
    set_property("enchantment",1);
    set_value(40);
    set_wield((: TO,"extra_wield" :));
    set_lrhit((:TO,"extra_lrhit":));
}

int extra_wield() {
    tell_object(ETO,"%^ORANGE%^You slide an arrow into the fine shortbow.%^RESET%^");
    tell_room(EETO,"%^ORANGE%^"+TPQCN+" slips an arrow into the fine shortbow.%^RESET%^",ETO);
    return 1;
}

int extra_lrhit(object targ) {
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(random(9) > 3) return 1;

   tell_object(ETO,"%^ORANGE%^You land a lucky shot!%^RESET%^");
   tell_object(targ,"%^ORANGE%^"+ETOQCN+" lands a lucky shot! Unlucky for you, though... seems you were the target!%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" seems surprised as an arrow finds its mark!%^RESET%^",({ETO,targ}));
   return random(2)+2;
}
