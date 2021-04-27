#include "forest.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^On The Quiet Forest Road\n"+
"%^RESET%^%^GREEN%^A wide %^ORANGE%^dirt trail %^GREEN%^has been "+
"cut through the forest here, and shows signs of wear from the many "+
"travelers who have ventured this way over the years. The trees are "+
"not very dense, allowing glimpses of the %^BOLD%^%^BLUE%^sky "+
"%^RESET%^%^GREEN%^overhead through the swaying treetops, and summoning "+
"dappled %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^to dance across the path. "+
"The road is aptly named, as it is very quiet here beyond the pleasant songs "+
"from %^MAGENTA%^birds %^GREEN%^high overhead, and the sounds of your own passage. There is a %^BOLD%^BLUE%^sign%^RESET%^%^GREEN%^ alongside the road.%^RESET%^\n"
);

    set_items(([
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song.",
	"sign":"This sign looks as if it has stood in this spot for a few ages. It has an arrow pointing eastward, and in worn letters is written %^BOLD%^Shadow City%^RESET%^.%^RESET%^",
	]));

    set_exits(([
	"east" : FORESTDIR+"road6",
//	"south" : PLAYERVILLAGEDIR+"pvroad9",
	"west" : FORESTDIR+"road8"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");
    set_climate(CLIMATE);

}

//Blanking this out for coherency. Players can look at the sign instead (similar to the sign west of here)
//void init(){
//    ::init();
//	add_action("read_sign","read");
//}
//int read_sign(string str){
//     if(!str) return notify_fail("Read what?\n");
//     if(str != "sign") return notify_fail("Read what?\n");
//	tell_room(environment(TP),TPQCN+" reads the sign.",TP);
//	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
//	write("%^BOLD%^%^GREEN%^The Player Village lies south of here.");
//	write("%^BOLD%^%^GREEN%^      Shadow lies east of here.");
//	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
//	return 1;
//}
