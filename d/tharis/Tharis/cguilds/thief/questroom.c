//Questroom for assassins by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_property("no teleport",1);
    set_name("Dark room");
    set_short("A dark room");
    set_long(
	"You are standing in a dark office room.  The windows have been painted "+
	"over with black paint allowing very little light in.  A few people "+
	"are standing along a wall chatting very quietly.  A desk sits near "+
	"the northern end of the room."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The room smells a little musty.");
    set_listen("default","The room is strangely quiet.");
    set_exits(([
	"up":"/d/tharis/Tharis/tstore"
    ]));
}
void reset(){
    ::reset();
//    if(!present("thief")){
//	new("/d/tharis/Tharis/cguilds/thief/thief")->move(this_object());
//    }
}
