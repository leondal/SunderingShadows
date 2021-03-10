#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_nwp("riding",5);
   set_short("%^RESET%^%^ORANGE%^A %^BLUE%^well-dressed %^ORANGE%^tsarven man%^RESET%^");
   set_id(({"well-dressed man","tsarvan man","stable keeper","keeper","man","stable hand"}));
   set_gender("male");
   set_race("human");
   set_name("stable hand");
   set_body_type("human");
   set_long("This short man is impeccably dressed, in traditional Tsarven "
"style, and with a turban upon his head.  His dark hair rests lighty upon his "
"brow, and his skin is deeply tanned.  His deep black eyes are constantly "
"watching over the stableboys as they run to and fro about their tasks.  "
"Somehow he is clean despite the messy surroundings, obviously he doesn't "
"take part in caring for the animals himself.");
}
