#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
    ::create();
    set_name("silvered chainmail");
    set_id( ({"silvered chain", "chain", "chainmail", "silvered chainmail", "armour", "armor"}) );
    set_short("%^BOLD%^%^WHITE%^s%^RESET%^il%^BOLD%^ve%^RESET%^re%^BOLD%^d %^RESET%^chainmail");
    set_long("%^RESET%^This chainmail is made of a %^BOLD%^%^WHITE%^si%^RESET%^"
"lve%^BOLD%^ry %^RESET%^metal with a brilliant sheen.  Its links are flawlessly "
"crafted and interlock smoothly, leaving no gap in their protection.  Despite "
"the armor's light weight and fine crafting, it is startlingly %^RED%^strong "
"%^RESET%^and impervious to blows.  A light layer of %^ORANGE%^padding "
"%^RESET%^lies beneath the armor itself, offering protection to the wearer.\n");
    set_lore("This armor was created within the Kinaro outpost, for the dwarven "
"guards of the town.  It was crafted by the master smith Gake, using the "
"ancient dwarven arts of working mithril, known also as true silver.  It is a "
"common misconception by outsiders that such metals are mined in Kinaro itself"
".  In actual fact, they are shipped through the mountains from deeper mines "
"subject to Barak Morndin, the great dwarven city hidden within the Dagger "
"Range, of which Kinaro is merely an outpost.");
    set_size(2);
    set_value(500);
    set_property("enchantment", 3);
    set_item_bonus("magic resistance",1);
}
