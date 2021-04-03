#include <std.h>
inherit ROOM;

string * features = ({
            "%^GREEN%^A small creek meanders through the forest, gently burbling away.%^RESET%^",
            "%^GREEN%^The dirt beneath your feet has eroded enough to reveal some crumbling ancient bricks.%^RESET%^",
            "%^GREEN%^A wooden bridge rises over a small river that flows from the forest.%^RESET%^",
            "%^GREEN%^A mountain range, its snowy peaks stretching toward the clouds, towers over the trees in the south.%^RESET%^",
            "%^GREEN%^The dense trees form a ceiling overhead, blotting out the light.%^RESET%^",
            "%^GREEN%^Dozens of goblins footprints scramble all over the road, they must live nearby.%^RESET%^",
            "%^GREEN%^There is an enchanting melody coming from the forest, calling to you.%^RESET%^",
            "%^GREEN%^You pass by the crumbling ruins of an ancient stone watchtower.%^RESET%^",
            "%^GREEN%^The road curves through a wide meadow.%^RESET%^",
            "%^GREEN%^A lone gravestone is tucked back in some foliage alongside the road.%^RESET%^",
            "%^GREEN%^Some fresh blood is smeared across the road here, but there are no signs of where it came from.%^RESET%^",
            "%^GREEN%^The foliage is quite dense here, making it difficult to see through the trees.%^RESET%^",
            "%^GREEN%^Some riders passed through here recently, their horses leaving behind heavy hoof marks.%^RESET%^",
            "%^GREEN%^The trees tower ever upwards, ancient and awe-inspiring.%^RESET%^",
            });


void create()
{
   ::create();
   set_light(2);
   set_travel(PAVED_ROAD);
   set_terrain(BARREN);
   set_short("Road between Azha and Tabor");
   set_long(
   "%^BOLD%^%^GREEN%^On the Northern Highway, connecting Azha and Tabor%^RESET%^\n"+
   "%^GREEN%^This road is large enough for two wagons to travel side by side, and it has obviously seen a lot of use. The dirt is hard and compacted, and has baked in the often blistering heat of the sun. It has apparently fallen into a bit of disrepair over the last several years. Several of the stones that border the road are missing or completely covered in mud."+make_fdesc()+"%^WHITE%^

%^WHITE%^"
   );
   set_listen("default","The road is fairly quiet with few traveling along it.");
   set_smell("default","The dust you've kicked up on the road hangs in the air.");
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
                      "$1$")[4..6],
                ""),
            (:atoi(sprintf("%d",$1[0]))%$2:),
            sizeof(features)));
    for (i=0; i<sizeof(featurearr); ++i)
        fdesc+=" "+features[featurearr[i]];
    return fdesc;

}
