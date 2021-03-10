#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create() {
    ::create();
    set_name("silvered fullplate");
    set_id( ({"silvered plate", "plate", "silvered fullplate", "fullplate", "armour", "armor"}) );
    set_short("%^BOLD%^%^WHITE%^s%^RESET%^il%^BOLD%^ve%^RESET%^re%^BOLD%^d %^RESET%^fullplate");
    set_long("%^RESET%^This fullplate is made of a %^BOLD%^%^WHITE%^si%^RESET%^"
"lve%^BOLD%^ry %^RESET%^metal with a brilliant sheen.  Each plate is flawlessly "
"crafted and interlock smoothly with the rest, leaving no gap in their "
"protection.  Despite the fragile appearance of the plates, the armor is "
"startlingly %^RED%^strong %^RESET%^and impervious to blows.  A light layer of "
"%^ORANGE%^padding %^RESET%^lies beneath the armor itself, offering protection "
"to the wearer.\n");
    set_lore("This armor was created within the Kinaro outpost, for the dwarven "
"guards of the town.  It was crafted by the master smith Gake, using the "
"ancient dwarven arts of working mithril, known also as true silver.  It is a "
"common misconception by outsiders that such metals are mined in Kinaro itself"
".  In actual fact, they are shipped through the mountains from deeper mines "
"subject to Barak Morndin, the great dwarven city hidden within the Dagger "
"Range, of which Kinaro is merely an outpost.");
    set_size(2);
    set("value", 100);
    set_property("enchantment", 3);
    set_item_bonus("magic resistance",1);
}
