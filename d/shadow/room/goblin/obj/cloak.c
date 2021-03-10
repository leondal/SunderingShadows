//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
#include <std.h>

inherit ARMOUR;
void create() {
    ::create();
    set_name("russet cloak");
    set_id(({"cloak","russet cloak","halfling cloak"}));
    set_short("%^RED%^Ru%^ORANGE%^ss%^RED%^et Cloak%^RESET%^");
    set_obvious_short("a russet colored cloak");
    set_long("%^RED%^Ru%^ORANGE%^ss%^RED%^et%^RESET%^ colored wool "+
       "is used in the creation of this cloak.  The cloak looks as if "+
       "it might have been made for a humanoid child at first.  Though "+
       "on a closer look one can spot a very subtle pattern woven into "+
       "the cloak of twisted and interwoven lines, a %^GREEN%^"+
       "geometrical pattern%^RESET%^ typical of the Halfling race.  "+
       "The cloak has a hood attached to the back of it, more than "+
       "likely to allow one to remain toasty and dry when it rains.  "+
       "The cloak looks to be in poor shape and has a musty smell to it."
    );
    set_lore("The Russet Cloak is indeed a Halfling made cloak.  The "+
       "Halfling race is one that excels at the domestic arts like none "+
       "other.  While elves and humans many argue between them who "+
       "makes the best clothing, it is the Halflings that win this "+
       "competition.  Though they might not follow the sense of style "+
       "of an elf or human, Halfling made garments are well known to "+
       "last many, many, many years and hardly every need repaired.  "+
       "That is, when they are used in normal Halfling activities.  "+
       "If there is anyone who could get this cloak clean it again, "+
       "it would be the Halflings.");
    set_property("lore difficulty",6);
    set_weight(3);
    set_value(100);
    set_type("clothing");
    set_limbs(({"neck"}));
    set_ac(0);
    set_property("enchantment",random(2));
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    tell_object(ETO,"%^RED%^The cloak fits snug to your body and you "
	"feel more protected.%^RESET%^");
    tell_room(EETO,"%^RED%^"+ETOQCN+" wraps a well fitting cloak over "
	""+ETO->QP+" body.%^RESET%^",ETO);
    return 1;
}
int removeit() {
    tell_object(ETO,"%^CYAN%^You feel a cold shiver pass through you"+
       "as you take off the cloak.%^RESET%^");
    tell_room(EETO,"%^CYAN%^"+ETOQCN+" unwraps a cloak from "
	""+ETO->QP+" body.%^RESET%^",ETO);
    return 1;
}
