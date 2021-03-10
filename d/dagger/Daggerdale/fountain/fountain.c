#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("A ruined fountain");
    set_short("%^BOLD%^%^BLACK%^A ruined fountain%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This obviously was the center of Daggerdale's commerce and activity. The city "
"square is dominated by the rubble of a %^RESET%^%^WHITE%^giant fountain%^BOLD%^%^BLACK%^. The fiercest "
"fighting obviously took place here, as the large cobblestones are broken apart by %^RESET%^%^ORANGE%^la"
"%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^ge c%^WHITE%^ra%^ORANGE%^te%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s"
"%^BOLD%^%^BLACK%^, and %^RESET%^%^RED%^sc%^WHITE%^o%^RED%^rch m%^WHITE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^ks "
"%^BOLD%^%^BLACK%^mar every surface. The roads continue to the north, south, east and west.%^RESET%^\n\n");
    set_smell("default","%^ORANGE%^A breath of %^CYAN%^fresh air %^ORANGE%^briefly casts aside the acrid, burnt smell of the ruins.");
    set_listen("default","It is deathly quiet here.");
    set_items(([
      ({"fountain", "statue"}) : "%^BOLD%^%^BLACK%^Once a grand fountain dominated by a %^WHITE%^silver statue"
"%^BLACK%^, its image has been lost, and no water remains held within it. The %^WHITE%^silver%^BLACK%^ has "
"been melted, and even the stone warped until it resembles nothing more then a macabre wreck, complete with a "
"few %^RESET%^%^ORANGE%^copper coins%^BOLD%^%^BLACK%^ fused to the bottom of its insides.%^RESET%^",
    ]));

    set_exits(([
      "north" : STREETS"street28",
      "south" : STREETS"street15",
      "west" : STREETS"street21",
      "east" : STREETS"street22",
    ]));
}
