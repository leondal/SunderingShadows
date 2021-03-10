#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Aketon Central Crossroad");
   set_long("%^GREEN%^Aketon Central Crossroad%^RESET%^
You are on a wide platform formed by the branching of the tree you are "
      "stepping on. There are broad ways on the branches of the tree "
      "leading into all different directions from here. Many people pass "
       "by you as they hurry to their business. Peering down the main roads "
      "from here you see many branchings and lots of people moving around. A "
      "lot of large houses are built on the giant tree. This is obviously "
      "the lowest level. The steps carried you up here continue twisting "
      "up and down the trunk.");
   set_items( (["platform":"It is formed by the main branching of this "
      "huge tree which this city is built on.",
      ({"ways","roads"}):"These broad pathways leads you to all different "
      "directions from here.",
      "branches":"Some branches on which the city is built.",
      ({"people","citizens"}):"There are all kinds of people here.",
      "houses":"These large houses are built on the branches of the tree.",
      "steps":"It coninues twist up and down the tree trunk.",
      "level":"This is the lowest level of this tree. There are more can "
      "seen from here."]) );
   set_exits( (["up":RPATH1+"1step4",
      "down":RPATH1+"1step3",
      "north":RPATH1+"1one28",
      "northeast":RPATH1+"1one29",
      "east":RPATH1+"1one34",
      "southeast":RPATH1+"1one40",
      "south":RPATH1+"1one39",
      "southwest":RPATH1+"1one38",
      "west":RPATH1+"1one33",
      "northwest":RPATH1+"1one27"]) );
}
