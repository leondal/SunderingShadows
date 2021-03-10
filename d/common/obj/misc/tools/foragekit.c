#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("forage tool kit");
	set_id(({ "kit", "forage tool kit" }));
	set_short("%^RESET%^%^GREEN%^A forage tool kit%^RESET%^");
	set_long("Wrapped carefully in a bag lined with %^BOLD%^"+
           "lamb's wool%^RESET%^ is a collection of %^BOLD%^%^GREEN%^glass"+
           " bottles%^RESET%^. Each one is empty, obviously ready to"+
           " be filled by something. A collection of thin %^ORANGE%^"+
           "copper sheets%^RESET%^ bound by a %^YELLOW%^leather cord"+
           "%^RESET%^ show easily recognizable %^GREEN%^plants%^RESET%^"+
           " and %^CYAN%^mushrooms%^RESET%^, each listing if they are "+
           "poisonous or not, how they must be prepared, and thier "+
           "effects on the body. Obviously this is the kit for someone"+
           " who needs to forage");
        set_weight(1);
	set_value(200);
         set_item_bonus("surival",2);
}
