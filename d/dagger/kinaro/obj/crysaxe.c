#include <std.h>
inherit "/d/common/obj/weapon/battle_axe";

void create() {
  ::create();
  set_name("crystal axe");
  set_id( ({"axe", "crysaxe", "crystal axe"}) );
  set_short("%^BOLD%^%^CYAN%^cr%^WHITE%^yst%^CYAN%^al a%^WHITE%^x%^CYAN%^e%^RESET%^");
  set_long("%^BOLD%^%^CYAN%^Made entirely from glittering crystal, this axe seems to first appearances to be "
"utterly impractical.  Light glitters off its single blade, honed to a razor-sharp edge.  But a closer "
"inspection reveals that the fragile-looking crystal is in fact as sturdy as steel.  Pale white leather wraps "
"the hilt, and along the head of the weapon run carved dwarven runes.%^RESET%^");
  set_lore("This axe was created within the Kinaro outpost, for the dwarven guards of the town.  It was "
"created using secret dwarven rune magics, shaped from the useless crystals that are unearthed in the mining "
"of the mountains there.  The weapon itself was made in the weaponshop of the great dwarven warrior, Sheas, "
"and is her weapon of choice in combat.  Long retired from that rough and vigorous life, she still smiths such "
"items in defense of the town.  The axe is magically sharp, and amazingly light.");
  set("value", 250);
  set_property("enchantment", 2);
}
