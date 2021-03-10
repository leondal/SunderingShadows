//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
#include <std.h>

inherit "/d/common/obj/weapon/club";
void create() {
    ::create();
    set_name("club");
    set_id(({"club","goblin club","baton","baton of bashing"}));
    set_obvious_short("%^ORANGE%^a wooden baton%^RESET%^");
    set_short("%^ORANGE%^Baton of Bashing%^RESET%^");
    set_long("%^ORANGE%^This length of cypress wood makes a very "+
       "effective club.  The club is unpolished and untreated, "+
       "instead left in its raw form.  The head of the baton though "+
       "has been dipped numerous times in what looks to be %^RESET%^"+
       "lead%^ORANGE%^, allowing for one to deal a more brutal blow.%^RESET%^");
    set_lore("The Baton of Bashing was at first just a simple club "+
       "that all races have used at one time.  It was not until the "+
       "goblins discovered that if they dip the clubs in metal to give "+
       "them added weight, that they are more deadly.  Such a "+
       "discovery and insight is unique among the goblins.");
    set_property("lore difficulty",3);
    set_value(10);
    set_property("enchantment",random(2));
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}

int extra_wield() {
    tell_object(ETO,"%^MAGENTA%^You yell:%^RESET%^ It's skull bashing time!!!"
	    "%^RESET%^" );
    tell_room(EETO,"%^MAGENTA%^"+TPQCN+" yells:%^RESET%^ It's skull bashing time!!!"
       "%^RESET%^",ETO);
    return 1;
}

int extra_unwield() {
    tell_object(ETO,"%^MAGENTA%^As you unwield the club, you bonk "+
       "yourself on the head for a laugh!%^RESET%^");
    tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" bonks "+ETO->QO+"self on "+
       "the head with a club!%^RESET%^",ETO);
    ETO->do_damage("head",random(1)+1);
    return 1;
}

int extra_hit(object vic){
    int dam;
    if(random(6) < 2) return 1;
    tell_object(ETO,"%^MAGENTA%^Giggling like a fool you bonk your "+
       "opponent with the club!%^RESET%^");
    tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" giggles like an idiot "+
       "while swinging a club at "+vic->QCN+"!%^RESET%^",(({ETO, vic})));
    tell_object(vic,"%^MAGENTA%^"+ETOQCN+" giggles like an idiot "+
       "while swinging a club at you!%^RESET%^");
    dam = random(2)+2;
    return dam;
}
