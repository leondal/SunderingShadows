#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("skinning kit");
	set_id(({ "kit", "skinning kit" }));
	set_short("%^RESET%^%^ORANGE%^A skinning kit%^RESET%^");
	set_long("This small tool kit, obviously for %^RED%^skinning%^RESET%^,"+
             " is dominated by an impressive collection of %^BOLD%^knives%^RESET%^"+
             ". Some are easily recognizable and thier use obvious, others are "+
             "stranger, long blades with %^CYAN%^thin flat blades%^RESET%^ for"+
             " getting under %^RED%^skin%^RESET%^, and %^CYAN%^large oval shaped"+
             " blades%^RESET%^ that are dull for scraping %^RED%^flesh%^RESET%^ "+
             "from %^ORANGE%^skins%^RESET%^. Pouches of %^MAGENTA%^fine powder"+
             "%^RESET%^ and bottles of %^BLACK%^%^BOLD%^ointment%^RESET%^ for "+
             "preparing skin are secured within as well.");
        set_weight(1);
	set_value(300);
}