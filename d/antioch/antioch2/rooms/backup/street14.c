#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("An intersection");
	set_long(
	"You are standing at the intersection of Crescent, Cherry,"+
	" and Cedar street. Crescent runs to the southwest, back"+
	" towards the Antioch gates. Cedar travels northwest towards"+
	" the palace. Cherry street is the main street through town,"+
	" it runs to the west and has most of the shops on it. There"+
	" is a large section in the middle of the street at the"+
	" intersection of Cherry and Oak street. On the east is a"+
	" very large church with its doors open for all who wish to"+
	" enter. The church is very impressive, it reaches up"+
	" several stories in height and is crafted from blocks of"+
	" carefully carved stone. The entrance is a"+
	" large archway. The center block has a %^BOLD%^%^RED%^crimson"
      " rose %^RESET%^upon a %^BOLD%^%^YELLOW%^shield %^RESET%^of gold,"
      " the symbol of Jarmila."
	);
	set("night long",
	"The street light here helps to illuminate the area, but"+
	" the church also spills forth much light onto the shadowed"+
	" streets. The church here is new and was built very"+
	" carefully using perfectly sized stone blocks. It reaches"+
	" several stories up into the night. The entrance is a grand"+
	" stone archway. Engraved on the center stone of the arch is"+
	" the symbol of Jarmila, a %^BOLD%^%^RED%^crimson"
      " rose %^RESET%^upon a %^BOLD%^%^YELLOW%^shield %^RESET%^of gold."
      " It vigilantly watches those who enter the church."+
	" Crescent street runs southwest from here, heading back"+
	" towards the Antioch gates. Cedar street travels to the"+
	" northwest towards the palace. Cherry street runs to the"+
	" west, straight through the center of town. Most of the"+
	" shops are located on that street. There is a giant fountain"+
	" in the middle of it, where it intersects with Oak street."
	);
	set_smell("default","You smell a faint scent of incense.");
	set_listen("default","Gentle prayers float to your ears"+
	" on the breeze.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is the intersection of Crescent, Cherry,"+
	" and Cedar street.",
	"church" : "The church is the large building on the east,"+
	" reaching up several stories in height and it looks quite"+
	" impressive.",
	"fountain" : "There is a large fountain in the center of"+
	" Cherry street.",
	]));
	set_exits(([
	"east" : ROOMS+"church1",
	"west" : ROOMS+"street21",
	"north" : ROOMS+"street13",
	"south" : ROOMS+"street15"
	]));
}

void reset()
{
	::reset();
	if(!present("street_light")) {
		new(OBJ+"street_light")->move(TO);
	}
}
