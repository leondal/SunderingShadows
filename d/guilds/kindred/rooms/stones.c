#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"You have come to a ring of large stones. There are eight long, flat"+
	" stones that have sunk into the ground here, set in a circle and spaced"+
	" at equal intervals. They are quite large and would be about impossible"+
	" to move, you aren't sure how they got here in the first place. They are"+
	" each about three feet tall and five feet long. It is here where the"+
	" Kindred come on occassion to hold meetings of the entire guild and"+
	" seek advice from their gods and guardians. Symbols of each diety that"+
	" help the Kindred are carved into the rocks."
	);
	set_smell("default","The fresh scent of pine drifts in the air.");
	set_listen("default","The rustling of the pine leaves is soothing.");
	set_items(([
	"symbols" : "The symbols of Silvanus, Mielikki, Eldath, Lathander, Grumbar,"+
	" Istishia, and Akadi are each carved onto the rocks.",
	"rocks" : "Eight incredibly large, flat, gray stones are laid out in a circular"+
	" pattern around this clearing. They are approximately three feet in"+
	" height and five feet long. Each has symbols of the patron gods of the"+
	" Kindred engraved into it.",
	"ground" : "The ground here is covered in a thick matt of vibrant grass.",
	"grass" : "%^BOLD%^%^GREEN%^The grass stretches out over the entire ground,"+
	" a cool and lush carpet for bare feet.",
	]));
	set_exits(([
	"east" : "/d/guilds/kindred/rooms/trail3",
	"northwest" : "/d/guilds/kindred/rooms/bushes",
	]));
}

void init()
{
	::init();
	add_action("sit","sit");
}

int sit(string str)
{
	if(str == "stone" || str == "stones" || str == "rock" || str == "rocks") {
		tell_object(TP,"%^BOLD%^You carefully sit down on one of the large"+
		" stones.");
		tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" carefully sits down"+
		" on one of the large stones.",TP);
		return 1;
	}
	if(str == "ground" || str == "floor" || str == "grass") {
		tell_object(TP,"%^BOLD%^%^GREEN%^You sit down on the cool grass.");
		tell_room(ETP,"%^BOLD%^%^GREEN%^"+TP->query_cap_name()+" sits down"+
		" on the cool grass.",TP);
		return 1;
	}
}
