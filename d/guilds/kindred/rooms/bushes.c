#include <std.h>
inherit ROOM;

int count;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"Berry bushes are growing along the path here. Actually, it might be"+
	" more accurate to say that the path meanders between the berry bushes."+
	" There are several different types of berries here, ranging from"+
	" %^BOLD%^%^BLACK%^black berries%^RESET%^ to %^BOLD%^%^BLUE%^blueberries%^RESET%^"+
	" to %^BOLD%^%^RED%^raspberries%^RESET%^. The only berries that are in"+
	" reach, however, are a round little juicy red berry. They give off a light"+
	" fruity scent that drifts on the breeze."
	);
	set_smell("default","The berry bushes give off a wonderful fruity scent.");
	set_listen("default","A stream bubbles somewhere off to the north.");
	set_items(([
	"bushes" : "There are numerous bushes here, but only the ones closest"+
	" to the path are in reach to be picked. There are several handfuls of"+
	" of red juicy berries on them, you aren't sure what type they are but"+
	" they look delicious.",
	"path" : "A simple dirt path weaves its way through the berry bushes.",
	({"blackberries","black berries"}) : "%^BOLD%^%^BLACK%^Some mouth watering"+
	" black berries are towards the back of the bushes, out of reach.",
	"raspberries" : "%^BOLD%^%^RED%^Large, delicious looking raspberries are"+
	" just tantalizingly out of reach.",
	({"blue berries","blueberries"}) : "%^BOLD%^%^BLUE%^Huge blueberries are"+
	" on the farthest bushes in the back, they look great but are way out"+
	" of reach.",
	]));
	set_exits(([
	"northeast" : "/d/guilds/kindred/rooms/stream",
	"southeast" : "/d/guilds/kindred/rooms/stones",
	]));
	count = 5;
}

void init()
{
	::init();
	add_action("pick","pick");
}

int pick(string str)
{
	if(str != "berries") {
		tell_object(TP,"The only thing to pick here appear to be some berries.");
		return 1;
	}
	if(count < 1) {
		tell_object(TP,"All the berries have been picked already.");
		return 1;
	}
	else {
		tell_object(TP,"You pick a handful of ripe berries.");
		tell_room(ETP,""+TP->query_cap_name()+" picks a handful of ripe berries.",TP);
		count -= 1;
		new("/d/guilds/kindred/obj/berries.c")->move(TP);
		if(count < 1) {
			add_item("bushes","These are some large berry bushes, but they have"+
			" all been picked clean.");
		}
		return 1;
	}
}
