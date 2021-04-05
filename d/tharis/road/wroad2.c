//wroad stuff - /d/tharis/road/wroad2.c

#include <std.h>

inherit ROOM;

//string * features = ({
//"%^GREEN%^A %^BLUE%^small creek%^GREEN%^ meanders through the forest.%^RESET%^",
//            "%^BOLD%^%^BLACK%^The ancient bricks have severely eroded here, and only a few can be seen.%^RESET%^",
//            "%^GREEN%^A %^ORANGE%^wooden bridge%^GREEN%^ crosses a %^BLUE%^small river%^GREEN%^ that flows from the mountains.%^",
//            "%^WHITE%^A mountain range with %^BOLD%^snowy peaks%^RESET%^ towers over the landscape.",
//            "%^GREEN%^The ancient ruins of a stone %^BOLD%^%^BLACK%^watchtower%^RESET%^%^GREEN%^ loom in the trees.%^RESET%^",
//            "%^GREEN%^The road passes through a %^MAGENTA%^flowery meadow%^GREEN%^.",
//            "%^GREEN%^A %^BOLD%^%^BLACK%^lonely gravestone%^RESET%^%^GREEN%^ rests at the forest's edge.%^RESET%^",
//            "%^GREEN%^An abandoned %^ORANGE%^wagon cart%^GREEN%^ sits off to the side with some %^BOLD%^%^WHITE%^human bones%^RESET%^%^GREEN%^ next to it.%^RESET%^",
//            "%^GREEN%^Some traces of %^RED%^blood%^GREEN%^ smear over the ground.%^RESET%^",
//            "%^GREEN%^A disfigured, fresh human corpse lies next to the forest with its head bitten off. %^RED%^Blood%^GREEN%^ covers the grass.%^RESET%^",
//            "%^GREEN%^The %^BOLD%^canopy%^RESET%^%^GREEN%^ is especially dense here.%^RESET%^",
//            "%^GREEN%^Some riders passed through here recently.%^RESET%^",
//            "%^WHITE%^A %^BOLD%^%^BLACK%^fortress%^RESET%^%^WHITE%^ can be seen far in the mountains.%^RESET%^",
//            "%^GREEN%^The towering %^BOLD%^%^BLACK%^trees%^RESET%^%^GREEN%^ are very old here.%^RESET%^",
//            });

void create(){
	::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);

        set_properties((["light":2,"indoors":0]));
	set("short","Road between Tharis and the Tsarven Empire");
     set("long",
"%^BOLD%^%^GREEN%^The road connecting Tharis and the Tsarven Empire%^RESET%^\n "+
"%^RESET%^%^ORANGE%^You are on an %^BOLD%^%^BLACK%^ancient stone "+
"road %^RESET%^%^ORANGE%^that trails along the foothills of the "+
"mountains which loom to the south. To the north grows an "+
"%^BOLD%^%^GREEN%^ol%^RESET%^%^GREEN%^d %^BOLD%^for%^RESET%^%^ORANGE%^e%^GREEN%^s%^BOLD%^t "+
"%^RESET%^%^ORANGE%^so thick and dense with %^GREEN%^undergrowth%^ORANGE%^, "+
"you see no easy way to breech it. The %^BOLD%^%^BLACK%^bricks "+
"%^RESET%^%^ORANGE%^beneath your feet are aged, crumbling in places, "+
"and covered in %^GREEN%^dark green moss%^ORANGE%^. It is lonely here, and "+
"only once in awhile do you pass another traveller going about their business.%^WHITE%^\n");

	set_exits(([
                "east": "/d/tharis/newtharis/rooms/wgate2",
		"west":"/d/tharis/road/wroad3"
		]));
	set_items(([]));

	set_smell("default","The forest smells fragrant and alive.");
	set_listen("default","A bird calls, a tree toad chirps, the wind rustles the trees.");
}

//string make_fdesc()
//{
//    int *featurearr;
//    int i;
//    string fdesc;
//    fdesc = "";
//    featurearr = distinct_array(
//        map_array(
//            explode(
//                crypt(file_name(TO),
//                      "$1$")[4..7],
//                ""),
//            (:atoi(sprintf("%d",$1[0]))%$2:),
//            sizeof(features)));
//    for (i=0; i<sizeof(featurearr); ++i)
//        fdesc+=" "+features[featurearr[i]];
//    return fdesc;
//
//}