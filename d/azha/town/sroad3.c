// Imperial Northern Highway, near Verhedin Province
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(GRASSLANDS);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);
	set_short("Imperial Northern Highway, Azha Province");
  set_long(
@AZHA
%^BOLD%^At the edge of enormous cliff%^RESET%^
%^GREEN%^The road ends here abruptly, and you stand on the edge of a cliff. Looking far, you see an %^BOLD%^endless sea%^RESET%^%^GREEN%^ unnaturally, as if something just cut the land here. extending the landscape. The edge is perfect and smooth. Looking by the edge, you can see mountains, behind the forest, to the north west and south-east of here. Few signs of erosion from the seas can be seen, but they are here. A stone %^BOLD%^%^BLACK%^marker%^RESET%^%^GREEN%^ stand shere.
AZHA
    );
	set_exits(([
    "north" : "/d/azha/town/sroad2",
//	"south" : "verhedin_area"
  ] ));
	set_smell("default","The dust of this well-travelled road rises to your nose.");
	set_items(([
		"marker" : "%^BOLD%^%^WHITE%^Dedicated to the the memory of everyone who died in the year of Silence, in memory of the lost empire. May his divine grace watch over their souls.",
	] ));
}
