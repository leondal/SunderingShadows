#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create() {
    ::create();
    set_id(({ "sword","short sword","shortsword","stone sword","stone short sword","stone shortsword" }));
    set_name("stone shortsword");
    set_short("%^BOLD%^%^BLACK%^rough stone shortsword%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This narrow dagger is made from dull, "
"unremarkable %^BOLD%^%^BLACK%^stone%^RESET%^%^ORANGE%^.  Its surface is rough "
"and ridged, and a curved claw-like mark has been carved into it.  While it "
"bears a %^RESET%^sharpened %^ORANGE%^edge, a few chips are visible along the "
"blade.  The short hilt is wrapped in thin, ragged scraps of %^RED%^leather"
"%^ORANGE%^, to serve a slightly better grip to for the weapon.%^RESET%^\n");
   set_lore("This dagger bears the mark of a clan of kobolds known to dwell in "
"the Offestry region, over the mountains in the northwest of Shadowgate.  The "
"Clan of the Talon dwell in a series of caves that border the edge of this "
"mountain range, often coming into conflict with a group of rock gnomes that "
"inhabit the nearby hills.  They are known to make forays into the nearby "
"forest for food, and on rare occasions are daring enough to approach the town "
"of Offestry itself.");
    set_property("lore difficulty",6);
    set_value(10);
    set_hit((:TO,"hitme":));
}

int hitme(object targ)  {
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(!random(6)) {
     tell_room(EETO,"%^BOLD%^%^BLACK%^The chipped edge of the shortsword "
"leaves a vicious mark in its wake!%^RESET%^");
     return (1+random(2));
   }
}
