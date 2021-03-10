#include "../../newbie.h"
inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("The Oval Eye");
	set_short("%^BOLD%^The Oval Eye%^RESET%^");
	set_long("%^BOLD%^The Oval Eye%^RESET%^\n"+
"This oval-shaped room serves as the entryway for the psionic enclave in Offestry.  The rounded walls feature two "
"%^ORANGE%^doorways, %^RESET%^each with an onion shaped archway carved of deep mahogany.  The center of the floor is "
"dominated by a large oval %^CYAN%^pool %^RESET%^filled with crystalline blue waters.  %^BOLD%^Statues %^RESET%^in the "
"center of the fountain depict a human man and woman, each with a third eye in the center of his or her forehead.  "
"Curving stone %^RED%^benches %^RESET%^near the wall face the fountain, but the room has the bustling feeling of a "
"passageway rather than a place to relax.\n");
	set_smell("default","The aroma of incense mingles with the fragrance of water.");
	set_listen("default","Conversation and footsteps ring through the foyer.");
	set_items( ([
         ({"doorway","doorways","archway"}) : "%^ORANGE%^Outlined in deep mahogany set into onion shaped arches.  Each "
"open doorway leads into a separate room to the north and east.  The northern archway leads through to what appears to be "
"a shop of sorts.  Crystals can be seen separated into various glass containers on shelves just inside.  The opening in "
"the eastern portion of the wall reveals another shop, much simpler, that features dozens of large crystals hovering in "
"the air along the walls.%^RESET%^",
         ({"pool","fountain","statue","statues"}) : "%^CYAN%^The marble statues in the center of the pool are well-carved"
", depicting their subjects in an honest fashion.  The man and woman stand side by side, gazing ahead, and each seems to "
"radiate an aura of power.  The water within the pool is an eye-catching crystalline blue, giving relief to the pale "
"stone used in the construction of the enclave.%^RESET%^",
         ({"bench","benches"}) : "%^RED%^Slender curving benches line the wall, providing a place to sit for a brief "
"moment.%^RESET%^"
    ]) );
    set_exits(([
        "north" : MAINTOWN"psicomps",
        "east" : MAINTOWN"psistore",
        "south" : MAINTOWN"estreet3"
    ]) );
}
