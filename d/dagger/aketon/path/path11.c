#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_short("Before Aketon");
   set_long("You have moved onto a long tunnel like path. Curving up and "
      "over the path the trees enclose it the entire way. All the trees "
      "around you are the Kilkean forest. A few giant trees towering just "
      "in front of you.");
   set_items( ([ ({"tunnel","path"}):"This path is covered by tree crowns "
      "forming a tunnel shape.",
      "trees":"Different kinds of trees can be found. There are several "
      "immensely huge trees towering generally north of here.",
      "forest":"This is the Kilkean forest in Dagger area."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear the beautiful song of the birds in the "
      "woods.");
   set_exits( (["southwest":RPATH+"path10",
      "north":RPATH1+"1ground",
      "northwest":RPATH2+"2ground",
      "northeast":RPATH3+"3ground"]) );
}

void reset() 
{
   object obj;
    ::reset();
   if( !present("aketon board") ) {
      obj = new("std/bboard");
      obj->set_name("aketon board");
      obj->set_id( ({"board","bulletin board","aketon board" }) );
      obj->set_board_id("aketon_board");
      obj->set("short","Aketon City Board");
      obj->set("long","An old cork board where the adventurers who pass "
          "through Aketon post information and suggestions on the things "
          "they have discovered.\n");
      obj->set_max_posts(30);
      obj->set_location(RPATH+"path11");
   }
}
