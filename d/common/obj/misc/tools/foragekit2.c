#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("foraging kit");
	set_id(({ "kit", "foraging kit" }));
	set_short("%^BOLD%^%^GREEN%^A foraging kit%^RESET%^");
	set_long("This is a small %^ORANGE%^leather pouch%^RESET%^"+
            " holding what few things one would need for %^BOLD%^"+
            "%^GREEN%^foraging%^RESET%^.  Contained within is a "+
            "%^BOLD%^%^BLACK%^small shovel%^RESET%^ for digging"+
            " roots, a %^BOLD%^%^CYAN%^sharp knife%^RESET%^ for "+
            "cutting away foliage, and a %^GREEN%^field guide%^RESET%^"+
            " detailing what plants are edible.");
        set_weight(1);
	set_value(200);
         set_item_bonus("survival",2);
}
