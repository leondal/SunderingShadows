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
	" The city road opens into a larger clearing here. To the north "
	"stands a regal looking building. The "
	"%^RED%^red banners%^BLUE%^ of Lloth hang from the building "
        "displaying her %^BOLD%^%^CYAN%^spider symbol%^RESET%^%^BLUE%^ "
	"proudly. An open doorway to the north leads into the building. "
	"To the east lies the %^GREEN%^temple%^BLUE%^ "
	"walls which tower twenty feet above you.\n%^YELLOW%^You feel "
	"sleepy and detect the presence of an entity tapping into "
	"your mind.%^RESET%^"
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
	"banners":"%^RED%^The red banners bearing the spider symbol of "
	"Lloth hang from the roof of the building.%^RESET%^",
	"building":"%^BLUE%^You suspect this building houses some form "
	"of elite Drow forces.%^RESET%^",
	"doorway":"Nothing can be seen through the doorway.",
	"temple":"The temple walls block your view of the temple.",
	"walls":"The temple walls tower twenty feet high and are unclimable.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/elite2",
	"northeast":"/d/dagger/drow/rooms/city30",
	"west":"/d/dagger/drow/rooms/city26",
	"south":"/d/dagger/drow/rooms/city8"
    ]));
}
