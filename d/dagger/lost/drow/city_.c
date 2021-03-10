#include <std.h>
inherit ROOM;
void create() {
::create();
set_property("light",1);
set_property("indoors",1);
set_short("%^BLUE%^City street%^RESET%^");
set_long(
"%^BLUE%^The city street is made of cobblestones winding through the existing structures around you. The wind blows back your hair as you wander through the city pathways."
" Two large towers made of black obsidian stone stand beside you to the east and the west. %^CYAN%^Fog%^BLUE%^ swirls around your feet as you travel along the street."
);
set_listen("default",
"The wind howls a strangled cry which causes you to feel nervous about being here."
);
set_smell("default",
"The smell of blood hangs thick in the air."
);
set_items(([
"cobblestone":"There are numerous cobblestones lining the city pathways.",
"tower":"A tower stands to either side of you on the east and west.",
"towers":"The two towers are formed of black obsidian stone and have no apparent entrance from this spot in the city.",
"fog":"%^CYAN%^The eerie fog swirls about your feet.%^RESET%^",
"cobblestones":"The city pathway is made up of various colored cobblestones which must have been mined in the caverns near here.",
"street":"The street is made up of cobblestones and winds through the buildings.",
"pathway":"The pathway winds through the city and is made up of cobblestones.",
"buildings":"There are buildings lining the city streets."
]));
set_exits(([
"south":"/d/dagger/drow/rooms/city1.c",
"north":"/d/dagger/drow/rooms/city15.c"
]));
}
