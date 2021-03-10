#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The wind blows back your "
	"hair as you wander through the city pathways."
	" Further to the east you see an enormous "
	"%^BOLD%^%^WHITE%^black obsidian tower%^RESET%^%^BLUE%^. Above "
	"the tower hangs a large "
	"%^CYAN%^blackened cloud%^BLUE%^ that hovers as if it is "
	"awaiting the arrival of something unknown. "
	"The %^RED%^red banners%^BLUE%^ of Lloth hang from the roof "
	"of the tower blowing in the wind down the tower's "
	"walls.\n%^YELLOW%^%^BOLD%^"
	"The cloud whispers, `Come closer "+TPQCN+", you will join "
	"in our agony'.%^RESET%^"
    );
    set_listen("default",
	"The wind howls a strangled cry which causes you to feel nervous "
	"about being here."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"tower":"%^BOLD%^%^WHITE%^The large black obsidian tower is made "
	"of a perfectly smooth polished stone. Other than "
	"the %^RED%^banners%^WHITE%^ there are no discernable markings "
	"or openings on the tower.%^RESET%^",
	"banners":"%^RED%^The banners bear the %^WHITE%^%^BOLD%^spider "
	"symbol%^RESET%^%^RED%^ of Lloth.",
   "cloud":"The cloud hangs dark and heavy and casts its doom upon "
	"the surrounding area.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/city39",
	"west":"/d/dagger/drow/rooms/city9",
	"east":"/d/dagger/drow/rooms/city41"
    ]));
}
