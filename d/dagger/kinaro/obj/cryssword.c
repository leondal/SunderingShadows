#include <std.h>
inherit "/d/common/obj/weapon/shortsword";

void create() {
  ::create();
  set_name("crystal sword");
  set_id( ({"sword", "cryssword", "crystal sword", "crystal", "shortsword", "crystal shortsword"}) );
  set_short("%^BOLD%^%^CYAN%^cr%^WHITE%^yst%^CYAN%^al sho%^WHITE%^rtsw%^CYAN%^ord%^RESET%^");
  set_long("%^BOLD%^%^CYAN%^Made entirely from glittering crystal, this sword seems to first appearances to be "
"utterly impractical.  Light glitters off its short leaf-shaped blade, each side honed to a razor-sharp edge.  "
"But a closer inspection reveals that the fragile-looking crystal is in fact as sturdy as steel.  Pale white "
"leather wraps the hilt, and along the centre of the blade run carved dwarven runes.%^RESET%^");
  set_lore("This sword was created within the Kinaro outpost, for the dwarven guards of the town.  It was "
"created using secret dwarven rune magics, shaped from the useless crystals that are unearthed in the mining "
"of the mountains there.  The weapon itself was made in the weaponshop of the great dwarven warrior, Sheas.  "
"Long retired from that rough and vigorous life, she still smiths such items in defense of the town.  The "
"sword is magically sharp and very well-balanced.");
  set_value(250);
  set_property("enchantment", 2);
}
