
#include <std.h>
inherit "std/room";
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Mage storage");
    set("long", "Mage stuff is kept here.\n");

}

void reset(){
    if(!present("climbing tool")){
	new("/d/shadow/obj/misc/climb_tool")->move(this_object());
    }
    if(!present("mage robe")){
	new("/d/attaya/seneca/cguilds/mage/mrobe")->move(this_object());
    }
    if(!present("rope")){
	new("/d/shadow/obj/misc/rope")->move(this_object());
    }
}

