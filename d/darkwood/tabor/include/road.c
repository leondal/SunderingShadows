// /d/darkwood/tabor/include/road.c

#include <std.h>
inherit ROOM;

//string * features = ({
//        "%^GREEN%^A small %^BLUE%^creek%^GREEN%^ meanders through the forest.%^RESET%^",
//            "%^BOLD%^%^BLACK%^The ancient bricks here have severely eroded, and only a few can be seen.%^RESET%^",
//            "%^GREEN%^A %^ORANGE%^wooden bridge%^GREEN%^ crosses a small %^BLUE%^river%^GREEN%^ that flows from the forest.%^RESET%^",
//            "%^WHITE%^A mountain range with %^BOLD%^snowy peaks%^RESET%^ towers over the trees in the south.",
//            "%^GREEN%^Dense forest surrounds you on all sides.",
//            "%^GREEN%^The road bears distinctive dirty %^ORANGE%^goblin footprints%^RESET%^.",
//            "%^GREEN%^You hear a beautiful melody coming from the forest.",
//            "%^GREEN%^Ancient ruins of a stone %^BOLD%^%^BLACK%^watchtower%^RESET%^%^GREEN%^ stand off to the side.%^RESET%^",
//            "%^GREEN%^The road passes through a %^MAGENTA%^flowery meadow%^GREEN%^.",
//            "%^GREEN%^A %^BOLD%^%^BLACK%^gravestone%^RESET%^%^GREEN%^ stands on the side of the road.%^RESET%^",
//            "%^GREEN%^An abandoned %^ORANGE%^wagon cart%^GREEN%^ is on the side of the road. You see some %^BOLD%^%^WHITE%^human bones%^RESET%^%^GREEN%^ by it.%^RESET%^",
//            "%^GREEN%^You see %^RED%^a pool of blood%^GREEN%^ on the ground.%^RESET%^",
//            "%^GREEN%^A disfigured fresh human corpse lies on the forest side with its head bitten off. %^RED%^Blood%^GREEN%^ covers the grass.%^RESET%^",
//            "%^GREEN%^The %^BOLD%^canopy%^RESET%^%^GREEN%^ is especially dense here.%^RESET%^",
//            "%^GREEN%^Some riders passed through here recently.%^RESET%^",
//            "%^GREEN%^The surrounding %^BOLD%^%^BLACK%^tall trees%^RESET%^%^GREEN%^ are very old.%^RESET%^",
//            });


void create()
{
   ::create();
   set_light(2);
   set_travel(PAVED_ROAD);
   set_terrain(BARREN);
   set_short("Road between Azha and Tabor");
   set_long(
   "%^BOLD%^%^GREEN%^On the Northern Highway, connecting Azha and Tabor%^RESET%^\n"+
   "%^GREEN%^This %^BOLD%^%^BLACK%^old road %^RESET%^%^GREEN%^is large "+
   "enough for two wagons to travel along it, side by side. The "+
   "%^ORANGE%^dirt %^GREEN%^is compacted and hard, and has been baked "+
   "in the often blistering heat of the %^YELLOW%^sun%^RESET%^%^GREEN%^. "+
   "It has obviously seen much use over the years, and now has started to "+
   "fall into %^BOLD%^%^BLACK%^di%^RESET%^%^ORANGE%^s%^GREEN%^r%^BOLD%^%^BLACK%^ep%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ir%^RESET%^%^GREEN%^. "+
   "%^BOLD%^M%^BLACK%^o%^RESET%^%^GREEN%^s%^BOLD%^s-c%^RESET%^%^GREEN%^ov%^BOLD%^e%^BLACK%^r%^RESET%^%^GREEN%^e%^BOLD%^d %^BLACK%^s%^GREEN%^t%^BLACK%^o%^RESET%^%^GREEN%^n%^BOLD%^e%^BLACK%^s "+
   "%^RESET%^%^GREEN%^line the sides of the road, but have begun to crumble as "+
   "nature seeks to claim back its space.%^WHITE%^\n");
   set_listen("default","The road is fairly quiet with few traveling along it.");
   set_smell("default","The dust you've kicked up on the road hangs in the air.");
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
//                      "$1$")[4..6],
//                ""),
//            (:atoi(sprintf("%d",$1[0]))%$2:),
//            sizeof(features)));
//    for (i=0; i<sizeof(featurearr); ++i)
//        fdesc+=" "+features[featurearr[i]];
//    return fdesc;
//
//}
