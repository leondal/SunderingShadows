// /d/shadow/room/forest/road1.c

#include "forest.h"
inherit ROOM;

//string * features = ({
//        "%^GREEN%^Pebbles are strewn alongside the road, washed out by recent rains.%^RESET%^",
//        "%^GREEN%^An abandoned farm sits back in an overgrown field, the buildings decrepit and in disrepair.%^RESET%^",
//        "%^GREEN%^A fallen tree partially blocks the road.%^RESET%^",
//        "%^GREEN%^The road passes through a pretty meadow.%^RESET%^",
//        "%^GREEN%^Deep horse tracks mark the road where riders have recently passed through.%^RESET%^",
//        "%^GREEN%^A dirty creek meanders alongside the road.%^RESET%^",
//        "%^GREEN%^The road curves around some huge boulders.%^RESET%^",
//        "%^GREEN%^Nettle grows on the sides of the road.%^RESET%^",
//        "%^GREEN%^Hornets swarm around their hive, high in the trees.%^RESET%^",
//        "%^GREEN%^A couple of rabbits watch you from the bushes.%^RESET%^",
//        "%^GREEN%^The road curves sharply around an ancient stone pillar.%^RESET%^",
//        "%^GREEN%^Birds sing from high up in the tree's branches.%^RESET%^",
//        "%^GREEN%^A menacing growl comes from somewhere deeper into the trees.%^RESET%^",
//        "%^GREEN%^The foliage of the forest is suddenly stirred as something darts off the road and vanishes.%^RESET%^",
//        "%^GREEN%^An old carcass, long past the point of being recognizable, lays withering in the weeds.%^RESET%^",
//        "%^GREEN%^Smoke can be seen above the trees from somewhere deep in the forest.%^RESET%^",
//        "%^GREEN%^Some of the forest has been cleared away, opening into a dirt field.%^RESET%^",
//        "%^GREEN%^You see deer tracks passing from the one side of the road to the other.%^RESET%^",


void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^BOLD%^%^GREEN%^Quiet Forest Road%^RESET%^%^GREEN%^");

set_long("%^RESET%^%^ORANGE%^On The Quiet Forest Road\n"+
"%^RESET%^%^GREEN%^A wide %^ORANGE%^dirt trail %^GREEN%^has been "+
"cut through the forest here, and shows signs of wear from the many "+
"travelers who have ventured this way over the years. The trees are "+
"not very dense, allowing glimpses of the %^BOLD%^%^BLUE%^sky "+
"%^RESET%^%^GREEN%^overhead through the swaying treetops, and summoning "+
"dappled %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^to dance across the path. "+
"The road is aptly named, as it is very quiet here beyond the pleasant songs "+
"from %^MAGENTA%^birds %^GREEN%^high overhead, and the sounds of your own passage.%^WHITE%^\n");

set_items(([
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
	]));

    set_exits(([
        "east" : VILLAGEDIR+"mainroad6",
	"west" : FORESTDIR+"road2"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");

    if (!random(8)) {
        new(MONDIR + "bandits")->move(TO);
    }
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
//}