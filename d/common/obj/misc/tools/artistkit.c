#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("artists kit");
	set_id(({ "kit", "artists kit" }));
	set_short("%^RESET%^%^MAGENTA%^An artists kit%^RESET%^");
	set_long("This medium sized %^ORANGE%^leather pouch%^RESET%^"+
         " appears to contain a variety of art supplies.  There appears"+
         " to be a set of %^RED%^c%^ORANGE%^o%^YELLOW%^l%^GREEN%^o"+
         "%^BLUE%^r%^MAGENTA%^e%^RESET%^%^MAGENTA%^d%^RESET%^ "+
         "pencils, some %^BOLD%^%^BLACK%^charcoal%^RESET%^, a"+
         "few %^RED%^paintbrushes%^RESET%^, a small tin painter's"+
         " palette, and a basic set of both %^CYAN%^oil%^RESET%^"+
         " and %^BLUE%^tempera%^RESET%^ paints.  It also contains"+
         " a selection of solvents and thinners that a true artist"+
         " would need.");
        set_weight(1);
	set_value(300);
         set_item_bonus("academics",2);
}
