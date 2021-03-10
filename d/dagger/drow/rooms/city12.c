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
	" A simple soldier's barracks lies to the east. The road to the "
	"west leads along the south side of the temple."
    );
    set_listen("default",
	"You hear the sound of voices talking gibberish in the air."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"barracks":"The soldier's barracks are made of black obsidian stone.",
	"doorway":"The doorway lies to the west and hangs open leading "
	"into the barracks.",
	"trap":"There is a scythe trap hanging to the frame of the doorway.",
	"frame":"The scythe trap attached to the frame is of the "
	"unremovable type that the drow are famous for using. However "
	"they are terrible at concealing them.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_pre_exit_functions(({"east"}),({"scythe"}));
    set_exits(([
	"north":"/d/dagger/drow/rooms/city13",
	"south":"/d/dagger/drow/rooms/city11",
	"east":"/d/dagger/drow/rooms/brk3",
	"west":"/d/dagger/drow/rooms/city19"
    ]));
}
int scythe() {
    message("my_action",
	"A %^RED%^%^BOLD%^scythe%^RESET%^ swings down on you as you "
	"pass through the doorway!"
    ,TP);
    message("other_action",
	"A %^RED%^%^BOLD%^scythe%^RESET%^ swings "
	"down on "+TPQCN+" as they pass "
	"through the doorway!"
    ,environment(TP),TP);
    TP->do_damage("head",roll_dice(4,4));
    return 1;
}
