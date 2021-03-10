//updated by Circe 10/04
#include "/d/dagger/aketon/short.h"

inherit TREEOUT;

void create() {
   ::create();
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^\n"
      "You are on a wide platform formed by the branching of the tree you are "
      "stepping on. There are broad ways on the branches of the tree "
      "leading into all different directions from here. Steps continue "
      "leading up and down the tree.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear the sounds of the city all around you.");
   set_exits( (["up":RPATH5+"5two1",
      "north":RPATH5+"5one15",
      "northeast":RPATH5+"5one16",
      "east":RPATH5+"5one23",
      "south":RPATH5+"5one28",
      "southwest":RPATH5+"5one27",
      "northwest":RPATH5+"5one14"]) );
}
