#include "forest.h"
inherit ROOM;

string * features = ({
        "%^GREEN%^Someone replaced washed out dirt with %^BOLD%^%^BLACK%^pebbles%^RESET%^%^GREEN%^ here.%^RESET%^",
            "%^GREEN%^An abandoned farm sits back in an overgrown field. The buildings have collapsed on themselves.",
            "%^GREEN%^A %^ORANGE%^fallen tree%^GREEN%^ partially blocks the road.%^GREEN%^",
            "%^GREEN%^The road passes through a %^MAGENTA%^flowery meadow%^GREEN%^.",
            "%^GREEN%^Some riders passed through here recently. Deep horse tracks mark the road.%^RESET%^",
            "%^ORANGE%^A dirty creek meanders alongside the road.%^GREEN%^",
            "%^ORANGE%^The road curves around some %^BOLD%^%^BLACK%^huge boulders%^RESET%^%^GREEN%^.%^RESET%^",
            "%^ORANGE%^A newly constructed %^ORANGE%^wooden watchtower%^GREEN%^ stands erect here. Nobody seems to be inside.%^RESET%^%^",
            "%^ORANGE%^Nettle grows on the sides of the road.%^RESET%^",
            "%^GREEN%^A wooden sign with the emblem of Shadow City pokes up from the ground.%^RESET%^",
            "%^ORANGE%^Hornets swarm around their hive, high in the trees.%^RESET%^",
            "%^ORANGE%^A couple of bunnies watch you from the bushes.%^RESET%^",
            "%^ORANGE%^The road curves around an ancient stone pillar here.%^RESET%^",
            "%^ORANGE%^Some bird nests are built into the trees.%^RESET%^",
            "%^ORANGE%^Yellow %^WHITE%^animal bones%^GREEN%^ are strewn alongside the road.%^RESET%^",
            "%^ORANGE%^Smoke can be seen above the trees from somewhere deep in the forest.%^RESET%^",
            "%^ORANGE%^Someone cleared back the forest to make a small field. It looks as if they have planted some peas.%^RESET%^",
            "%^ORANGE%^You see deer tracks passing from the one side of the road to the other.%^RESET%^",
    });


void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_long("
%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^
%^RESET%^%^GREEN%^A %^ORANGE%^dirty road %^GREEN%^leads through f%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^st und%^BOLD%^e%^RESET%^%^GREEN%^rg%^BOLD%^row%^RESET%^%^GREEN%^th. The forest is not very dense here, and the path is visible for a good distance."+make_fdesc());

    set_items(([
	"road":"A new road through the forest.",
	"forest":"A quiet forest, for sure. Only the sounds of birds."
	]));

    set_exits(([
        "east" : VILLAGEDIR+"mainroad6",
	"west" : FORESTDIR+"road2"
   	]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_smell("flowers","The odor of the flowers is overwhelming, you nearly pass out.");
    set_listen("default","You can hear birds singing.");
    set_listen("birds","They seems to sing songs of love.");

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
