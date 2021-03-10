//updated by Circe 6/1/04 with new desc, lore, etc by Shar
#include <std.h>

inherit "/d/common/obj/weapon/knife";
void create() {
    ::create();
    set_name("knife");
    set_id(({"knife","bone knife"}));
    set_short("%^BOLD%^%^WHITE%^Bone Knife%^RESET%^");
    set_long("%^BOLD%^Crafted from a rib bone, this curved dagger "+
       "has been sharpened on the outer edge.  The knife seems to be "+
       "used more for slashing than piercing, though it could possibly "+
       "do both.  A tattered and crumbling %^GREEN%^cotton%^WHITE%^ "+
       "scrap is wrapped around the pommel, bound with some crude "+
       "%^YELLOW%^leather cord%^WHITE%^.%^RESET%^");
    set_lore("The Bone Knife is made from the rib bone of a beast.  "+
       "The size of the blade rules out any humanoid creatures, as "+
       "it's too thick and long.  The Bone Knife is a favored weapon "+
       "of goblin rogues and assassins, for its deadly edge and ease "+
       "to wield.  Many an adventure's life has been cut short by his "+
       "underestimation of how deadly these types of knives can be.");
    set_property("lore difficulty",6);
    set_value(30);
    set_wield((: TO,"extra_wield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    tell_object(ETO,"%^BOLD%^WHITE%^You grip the knife and are ready "+
       "to slay!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^The knife held by "+ETOQCN+""+
	" grins evilly to you!%^RESET%^",ETO);
    return 1;
}

int extra_hit(object ob) {
    object vic;
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return 1;
    if(random(6) > 2) return 1;
    tell_object(ETO,"%^BOLD%^%^WHITE%^You deliver a piece of undead "+
       "wrath upon your foe!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" delivers a blow of "+
       "near death upon "+vic->QCN+"!%^RESET%^",(({ETO, vic})));
    tell_object(vic,"%^BOLD%^%^WHITE%^"+ETOQCN+" just tried to send "+
       "you to the land of the dead!%^RESET%^");
    return 1;
}
