#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Road into Aketon");
   set_long("You have moved onto a long tunnel like path. Curving up and "
      "over the path the trees enclose it the entire way. Kilkean forest "
      "lies ahead of you. A few giant trees are towards north.");
   set_items( ([ ({"tunnel","path"}):"This path is covered by tree crowns "
      "forming a tunnel shape.",
      "trees":"Different kinds of trees can be found. There are several "
      "immensely huge trees to the north.",
      "forest":"This is the Kilkean forest in Dagger area."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear the beautiful song of the birds in the "
      "woods.");
   set_exits( (["south":RPATH+"path7",
      "north":RPATH+"path9"]) );
}
