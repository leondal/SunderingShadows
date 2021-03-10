#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Road into Aketon");
   set_long("You have moved onto a long tunnel like path. Curving up and "
      "over the path the trees enclose it the entire way. Kilkean forest "
      "lies ahead of you.");
   set_items( ([ ({"tunnel","path"}):"This path is covered by tree crowns "
      "forming a tunnel shape.",
      "trees":"Different kinds of trees can be found.",
      "forest":"This is the Kilkean forest in Dagger area."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear the beautiful song of the birds in the "
      "woods.");
   set_exits( (["south":RPATH+"path1",
      "north":RPATH+"path3"]) );
   set_pre_exit_functions( ({"south"}),({"no_go"}) );
}

int no_go() {
   string *tmp,path;
   path = base_name(TP);
   tmp = explode(path,"/");
   if(tmp[0] != "d") return 1;
   if(tmp[1] != "dagger") return 1;
   if(!tmp[2]) return 1;
   if(!tmp[3]) return 1;
   if(tmp[2] == "aketon" && tmp[3] == "mon") return 0;
   return 1;
}
