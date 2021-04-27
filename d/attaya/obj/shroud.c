//updated by Circe 4/15/04 to current code, new desc, etc.
//moved AC point to enchant, nienne 05/07
#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("shroud");
    set_id(({"shroud","armor","armour","death shroud","death shroud of C'Taro"}) );
    set_short("%^BOLD%^%^BLACK%^The death shroud of C'Taro%^RESET%^");
    set_obvious_short("a thin black shroud");
    set_long("%^BOLD%^%^BLACK%^This thin black shroud is "+
       "made of a %^RESET%^gauzy material %^BOLD%^%^BLACK%^"+
       "through which %^YELLOW%^light %^BLACK%^easily penetrates.  "+
       "The shroud can be layered and has a strange "+
       "pin fashioned out of %^RESET%^%^ORANGE%^ancient "+
       "brass%^BOLD%^%^BLACK%^.  The %^RESET%^%^ORANGE%^pin "+
       "%^BOLD%^%^BLACK%^is in the shape of a strangely winding knot "+
       "that seems almost to move and shift when you "+
       "are not looking.  Otherwise, the shroud is "+
       "rather plain, but an impressive %^RESET%^%^CYAN%^"+
       "aura of power %^BOLD%^%^BLACK%^seems to emanate from it.%^RESET%^"
    );
    set_lore("This thin shroud possesses great magical "+
       "properties.  It was designed to eternally preserve "+
       "the remains of Emperor C'Taro of the Kinnesaruda "+
       "on the island of Attaya.  How it came to be in "+
       "your hands...well, only you can tell that tale.");
    set_weight(9);
    set_value(10000);
     set_type("clothing");
     set_size(2);
    set_limbs(({"torso"}));
    set_property("enchantment",5);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"unwearit":));


}
int wearit() {
    if((int)ETO->query_level() < 25) {  // changed to 25 while fixing a bug *Styx* 6/9/06
        tell_object(ETO,"You may not wear such a powerful item!");

	return 0;
    } else {
      tell_object(ETO,"%^BOLD%^You wrap the death shroud "+
         "around you and feel a cold chill.");
      tell_room(EETO,"%^BOLD%^A chilling breeze rushes "+
         "into the area, centering on "+ETOQCN+".",ETO);
	return 1;
    }
}

int unwearit() {
      tell_object(ETO,"You feel the coldness of death "+
         "leave you as you step out of the shroud.");
      tell_room(EETO,"The area warms as "+ETOQCN+" "+
         "steps out of "+ETO->QP+" strange robe.",ETO);
	return 1;
}
