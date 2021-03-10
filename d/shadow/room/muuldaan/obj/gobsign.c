#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("painted sign");
   set_id(({"sign","wooden sign","gobsign"}));
   set_short("A shabbily painted wooden sign");
   set_weight(1000000);
   set_property("no animate", 1);
   set_long("A %^ORANGE%^large wooden sign%^RESET%^ has been crudely nailed to the remains of a broken tree "
"stump beside the trail.  Upon it are %^RED%^painted%^RESET%^ and %^BLACK%^%^BOLD%^scrawled %^RESET%^various "
"goblinoid runes in several languages, smudged with fingerprints of paint and barely ledgible.  You could "
"probably attempt to read the sign.");
   set_read("%^ORANGE%^\nYou can barely make out the meaning of a line of painted symbols:\n\n"
"  %^RED%^All yous ones that tha yumins an others dun like, kin stay wit us insteads in tha hole!  No elfies "
"or dwarfs or stuff else we smash ya!\n\n"
"%^ORANGE%^Beneath has been scrawled in what looks like charcoal:\n\n"
"  %^BLACK%^%^BOLD%^Comes ta Muul'daan, we gots lotsa stuff, brings ya shineys!\n\n"
"%^RESET%^%^ORANGE%^The rest of the sign is too illegible to comprehend.%^RESET%^");
    set_value(0);
}
