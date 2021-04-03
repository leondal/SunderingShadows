#include "forest.h"
inherit ROOM;

string * features = ({
        "%^ORANGE%^Pebbles are strewn alongside the road, washed out by recent rains.%^RESET%^",
        "%^ORANGE%^An abandoned farm sits back in an overgrown field, the buildings decrepit and in disrepair.%^RESET%^",
        "%^ORANGE%^A fallen tree partially blocks the road.%^RESET%^",
        "%^ORANGE%^The road passes through a pretty meadow.%^RESET%^",
        "%^ORANGE%^Deep horse tracks mark the road where riders have recently passed through.%^RESET%^",
        "%^ORANGE%^A dirty creek meanders alongside the road.%^RESET%^",
        "%^ORANGE%^The road curves around some huge boulders.%^RESET%^",
        "%^ORANGE%^Nettle grows on the sides of the road.%^RESET%^",
        "%^ORANGE%^Hornets swarm around their hive, high in the trees.%^RESET%^",
        "%^ORANGE%^A couple of rabbits watch you from the bushes.%^RESET%^",
        "%^ORANGE%^The road curves sharply around an ancient stone pillar.%^RESET%^",
        "%^ORANGE%^Birds sing from high up in the tree's branches.%^RESET%^",
        "%^ORANGE%^A menacing growl comes from somewhere deeper into the trees.%^RESET%^",
        "%^ORANGE%^The foliage of the forest is suddenly stirred as something darts off the road and vanishes.%^RESET%^",
        "%^ORANGE%^An old carcass, long past the point of being recognizable, lays withering in the weeds.%^RESET%^",
        "%^ORANGE%^Smoke can be seen above the trees from somewhere deep in the forest.%^RESET%^",
        "%^ORANGE%^Some of the forest has been cleared away, opening into a dirt field.%^RESET%^",
        "%^ORANGE%^You see deer tracks passing from the one side of the road to the other.%^RESET%^",
    });


void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^BOLD%^%^GREEN%^Quiet Forest Road%^RESET%^%^GREEN%^");

set_long("%^GREEN%^A wide %^ORANGE%^dirt trail %^GREEN%^has been cut through the forest here, and shows signs of wear "+
	 "from the many travellers who have passed this way before you. The %^BOLD%^trees %^RESET%^%^GREEN%^are not "+
	 "very dense, allowing glimpses of the %^CYAN%^sky %^GREEN%^overhead through the swaying treetops."+make_fdesc());
    set_items(([
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
	]));

    set_exits(([
        "east" : VILLAGEDIR+"mainroad6",
	"west" : FORESTDIR+"road2"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","You can hear birds singing.");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");

    if (!random(8)) {
        new(MONDIR + "bandits")->move(TO);
    }
}

string make_fdesc()
{
    int *featurearr;
    int i;
    string fdesc;
    fdesc = "";
    featurearr = distinct_array(
        map_array(
            explode(
                crypt(file_name(TO),
                      "$1$")[4..7],
                ""),
            (:atoi(sprintf("%d",$1[0]))%$2:),
            sizeof(features)));
    for (i=0; i<sizeof(featurearr); ++i)
        fdesc+=" "+features[featurearr[i]];
    return fdesc;
}
