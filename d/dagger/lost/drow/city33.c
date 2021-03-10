#include <std.h>
inherit ROOM;
void create() {
::create();
set_property("light",1);
set_property("indoors",1);
set_short("%^BLUE%^City street%^RESET%^");
set_long(
"%^BLUE%^The city street is made of cobblestones winding through the existing structures around you. The wind blows back your hair as you wander through the city pathways."
" To the north lies the northern border of the %^BOLD%^lake%^RESET%^%^BLUE%^ which "
"surrounds the city. To the south lies the %^CYAN%^temple wall%^BLUE%^.%^RESET%^"
);
set_listen("default",
"The wind howls a strangled cry which causes you to feel nervous about being here."
);
set_smell("default",
"The smell of blood hangs thick in the air."
);
set_items(([
"cobblestone":"There are numerous cobblestones lining the city pathways.",
"cobblestones":"The city pathway is made up of various colored cobblestones which must have been mined in the caverns near here.",
"temple":"You cannot see the temple from here due to the temple walls.",
"lake":"The lake is deep, black and dark. You decide not to take a dip.",
"wall":"%^RED%^%^BOLD%^Upon the wall here is a single giant %^YELLOW%^golden rune%^RED%^.%^RESET%^",
"rune":"%^BOLD%^%^YELLOW%^As you gaze upon the rune you gasp in horror. It is clearly the rune of invulnerability inscribable by only one being...%^RED%^Grazzt.\n%^BLUE%^Horror sinks in as you realise that the Drow have the aid of this God.%^RESET%^",
"street":"The street is made up of cobblestones and winds through the buildings.",
"pathway":"The pathway winds through the city and is made up of cobblestones.",
"buildings":"There are buildings lining the city streets."
]));
set_exits(([
"west":"/d/dagger/drow/rooms/city32.c",
"east":"/d/dagger/drow/rooms/city34.c"
]));
}
