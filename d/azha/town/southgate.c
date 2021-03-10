// South Gate of Azha
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);
	set_short("The South Gate of Azha");
  set_long(
@AZHA
%^BOLD%^South Gates of Azha%^RESET%^
You are standing in front of the south gates of the Tsarvani frontiertown of Azha. Made of stout hardwood timbers and braced with iron,these gates are very impressive, easily comparable with the gates ofsome major cities in the interior. The walls themselves are alsotimber, packed with tamped earth, and some stone. Although thiswould never stand up to an organized force, it is more than adequateto ward off even the most powerful bandits. Day and night, wagonsline up to be checked over by imperial soldiers before entering thewalls. The gates are shut close.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/south3",
  ] ));
	set_items(([
		"walls" : "Though rough, the walls are flawlessly kept up.  Still, they could be climbed....\n",
		"sign" : "It reads: 'By Imperial Ordinance, there are no weapons allowed in the town.'\n",
		"wagons" : "These are trade wagons laden with goods, and extremely well guarded.\n",
	] ));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "gate");
	AOVER->add_monster(TO, "/d/azha/mon/ibnshia", 1);
}
