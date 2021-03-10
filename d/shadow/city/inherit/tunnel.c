//Titania 2/2/2020
//Shadow Sewers : Rat Tunnel Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("An underground tunnel");
   set_short("%^RESET%^%^MAGENTA%^An underground tunnel%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^An underground tunnel%^RESET%^\n%^BOLD%^%^ORANGE%^The walls of this narrow tunnel are shaped of heavy "+ 
	"%^RESET%^%^RED%^red clay %^BOLD%^%^ORANGE%^and %^RESET%^%^WHITE%^stone%^BOLD%^%^ORANGE%^. The roof is high "+ 
	"enough that most creatures could pass unimpeded. The entire structure is "+ 
	"sturdy and smooth, as if carefully shaped by mortal hands. The passage is "+ 
	"narrow, however, and a bit claustrophobic. Otherwise, the walls are so "+ 
	"remarkably smooth, and the floor so carefully kept, that travel is "+ 
	"not difficult. You seem to be on a slight downward slope.\n%^WHITE%^");
	set_smell("default","There is a rich, earthy smell of old stones and dirt.");
	set_listen("default","The shrieks and squeaks of rats darting underfoot echo through the tunnel.");
	set_items(([
	({"walls","wall","floor","roof"}) : "%^MAGENTA%^Despite being narrow, this tunnel is so carefully "+ 
	"crafted, and the walls and roof are so sturdy, and the ground so flat and clean, "+ 
	"you walk easily and without any fear of being crushed "+ 
	"by the weight of the ground above you.%^WHITE%^"
	]));
	set_monsters(({MON"rat.c"}),({1 + random(2)}));
	set_repop(40);
}
