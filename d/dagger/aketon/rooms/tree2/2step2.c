#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Steps around the giant tree");
   set_long("%^GREEN%^Steps around the giant tree%^RESET%^
You are on the steps around the giant tree. These steps leads you to the "
      "elven civilization hidden deep inside the Kilkean forest in the "
      "Dagger area, the elven city of Aketon. The steps continue circling "
      "up and down the huge tree trunk.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of a city coming from above the "
      "tree.");
   set_exits( (["up":RPATH2+"2step3",
      "down":RPATH2+"2step1"]) );
}
