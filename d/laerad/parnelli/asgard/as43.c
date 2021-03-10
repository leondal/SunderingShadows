//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_name("Forest hideaway");
    set_short("Forest hideaway");
    set_long(
	"%^BOLD%^%^GREEN%^A small forest hideaway%^RESET%^
%^GREEN%^You are standing in a small hidden forest alcove. Trees and "+
	"bushes surround you completely. The area is very dark and dreary. "+
	"Magic seems to radiate from everywhere making you wonder where you "+
	"really are."
    );
    set_property("no teleport",1);
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A %^CYAN%^cool%^ORANGE%^ breeze blows through the forest.");
    set_listen("default","You hear a few crickets in the forest.");
    set_exits( ([
    ]) );
}
void reset(){
    ::reset();
    if(!present("estal")){
	new("/d/laerad/mon/estal")->move(this_object());
    }
}
void init(){
   ::init();
   add_action("no_quit","quit");
}
int no_quit(string str){
   write("You are not allowed to quit here!");
   TP->force_me("out");
   if(base_name(ETP) != "/d/laerad/parnelli/asgard/as43")
      TP->force_me("quit");
   return 1;
}
