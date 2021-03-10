#include <std.h>
#include "../../newbie.h"
#define AVA_D "/daemon/avatar_d.c"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_short("The library in Offestry");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_long(
	"You are standing in the Offestry library, a quiet building on the north side of"+
	" town. There are few windows here, the room is mostly lit by oil lamps that hang"+
	" on the walls and from the ceiling. There are rows of shelves filled with books."+
	" Some of the books appear to be very ancient and worn, others seem much newer and"+
	" only have a thin lair of dust on them. It doesn't seem like this place gets many"+
	" visitors. From here you can <research> famous adventurers."
	);
	set_property("light",2);
	set_smell("default","You can smell the dust off old books.");
	set_listen("default","The library seems fairly quiet, just the rustle of a page turning now and then.");
	set_items(([
	({"books","scrolls"}) : "There are many books and scrolls on the shelves about the"+
	" room. Most of them seem to have a layer of dust covering them. The newer ones only"+
	" have a thin layer of dust, it seems.",
	"shelves" : "There are beautiful cedar shelves that are placed in rows about the"+
	" room, reaching from the floor almost to the ceiling. In places there are step"+
	" ladders so that you can reach the upper shelves. It doesn't look like anyone has"+
	" bothered to get up there recently, though.",
	({"lamps","oil lamps"}) : "Oil lamps have been fixed to the walls and hung from the"+
	" ceiling at intervals to help light the room, seeing as how there are few windows.",
	"walls" : "The walls seem to absorb any sound you make, helping to keep the room"+
	" quiet. Although not many people seem to come here, it's fairly empty other than"+
	" yourself and the librarian. There are oil lamps fixed to the walls in places to"+
	" help light the room.",
	"ceiling" : "A few oil lamps hang from chains at intervals around the room, helping"+
	" to give the place some light.",
	"floor" : "The floor is covered in a thick green carpet that hides the noises of you"+
	" moving about the room.",
	]));
	set_exits(([
	"south" : MAINTOWN"nstreet3",
	]));
}

void reset()
{
	::reset();
	if(!present("librarian")) {
                find_object_or_load("/d/newbie/mon/librarian.c")->move(TO);
	}
}


void init()
{
	::init();
	add_action("get_background","research");
}

int get_background(string str)
{
	string bkgrnd, avat;
	int isava, ispl;

	if(!present("librarian"))
		return notify_fail("The librarian is not here to help you. You would never be able"+
		" to find what you're looking for without help.\n");
	if(!str) {
		write("Correct syntax is: <research name>");
		return 1;
	}
	str = lower_case(str);
	if(user_exists(str))
		ispl = 1;
	if(!ispl && AVA_D->is_persona(str))
		isava = 1;

	if(!ispl && !isava)
		return notify_fail("That person does not exist in this reality.\n");
	if(ispl) {
		if(!file_exists("/d/save/background/"+str+".htm")) {
			write("%^MAGENTA%^Isabel says%^RESET%^: That person does not have a background on"+
			" record yet.");
			return 1;
		}
		write("Isabel sends a page off to look for the scroll.");
		write("The page returns quickly, despite the seeming lack of organization here.");
		write("%^MAGENTA%^Isabel says%^RESET%^: Here is the information you requested.");
		write("Isabel hands you a scroll and you move to one of the empty chairs to start reading.\n");
		write("%^BOLD%^"+capitalize(str)+"'s Background Information%^RESET%^\n");
		bkgrnd = "daemon/converter"->convertToInput(read_file("/d/save/background/"+str+".htm",6));
		TP->more(explode(bkgrnd,"\n"));
		return 1;
	}
	if(isava) {
		avat = ((string *)AVA_D->query_avatar_of_persona(str))[0];
		if(!file_exists("/avatar/"+avat+"/"+str+".htm")) {
			write("%^MAGENTA%^Isabel says%^RESET%^: That person does not have a background on record yet.");
			return 1;
		}
		write("Isabel sends a page off to look for the scroll.");
		write("The page returns quickly, despite the seeming lack of organization here.");
		write("%^MAGENTA%^Isabel says%^RESET%^: Here is the information you requested.");
		write("Isabel hands you a scroll and you move to one of the empty chairs to start reading.\n");
		write("%^BOLD%^"+capitalize(str)+"'s Background Information%^RESET%^\n");
		bkgrnd = "/daemon/converter"->convertToInput(read_file("/avatar/"+avat+"/"+str+".htm",6));
		TP->more(explode(bkgrnd,"\n"));
		return 1;
	}
	return notify_fail("Error. Talk to Grendel.");
}
