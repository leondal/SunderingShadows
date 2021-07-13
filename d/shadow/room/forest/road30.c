/******** CRITICAL "/d/shadow/room/forest/road1"!!!!!! *******************
/******** If you fuck this room up, you will make people never
/******** able to get back to the game from the freezer or the void.
/******** please be careful! - Garrett. ******************/
// /d/shadow/room/forest/road30.c

#include "/d/shadow/room/forest/forest.h"
inherit "/d/shadow/room/forest/road1";

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("A Crossroads %^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_items(([
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
	]));
    set_long("%^RESET%^%^ORANGE%^On The Quiet Forest Road\n"+
"%^RESET%^%^GREEN%^A wide %^ORANGE%^dirt trail %^GREEN%^has been "+
"cut through the forest here, and shows signs of wear from the many "+
"travelers who have ventured this way over the years. The trees are "+
"not very dense, allowing glimpses of the %^BOLD%^%^BLUE%^sky "+
"%^RESET%^%^GREEN%^overhead through the swaying treetops, and summoning "+
"dappled %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^to dance across the path. "+
"The road is aptly named, as it is very quiet here beyond the pleasant songs "+
"from %^MAGENTA%^birds %^GREEN%^high overhead, and the sounds of your own passage.%^WHITE%^\n"+
"\n%^WHITE%^The path is split as it goes eastward here and there is a rough path north headed into the mountains.\n%^RESET%^");

     set_items(([
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song.",
	]));
    set_exits(([
   "north" : "/d/newbie/rooms/roadout/mtnroad49",
	"west" : FORESTDIR+"road31",
	"southeast" : FORESTDIR+"road29",
	"northeast" : FORESTDIR+"road28"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");
}
//Changed this sign to an area map as the info provided was obsolete since players start in Tabor now
void init(){
	::init();
	if(!present("sign"))
	new("/d/newbie/obj/misc/newroadsign1.c")->move(TO);
}