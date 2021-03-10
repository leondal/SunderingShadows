#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Road into Aketon");
   set_long("You have moved onto a long tunnel like path. Curving up and "
      "over the path the trees enclose it the entire way. A wall of "
      "brush keeps you from going any further.");
   set_items( ([ ({"tunnel","path"}):"This path is covered by tree crowns "
      "forming a tunnel shape.",
      "trees":"Different kinds of trees can be found.",
      ({"wall","brush"}):"An area to the north full of small trees and "
      "shrubs. There seems no way of passing it, looks like it was put "
      "here to stop you going further on the path."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear the beautiful song of the birds in the "
      "woods.");
   set_exits( (["north":RPATH+"path2",
      /* "southeast":"/d/dagger/road/road100" */ ]) );
}
