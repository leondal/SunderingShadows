#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark and dreary cave. The room slopes down "+
	"even more in this cavern. Water rushes in from the southern and "+
	"western caves. You stand almost 2 feet deep in the black sewage."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","A horrible smell comes from the water in the room.");
    set_listen("default","The sound of rushing water is deafening.");
    set_exits( ([
	"west":"/d/tharis/caverns/cavern26",
	"south":"/d/tharis/caverns/cavern25",
	"northwest":"/d/tharis/caverns/cavern28",
	"northeast":"/d/tharis/caverns/cavern29"
    ]) );
}
