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
	"The stream widens into a little pool here, probably fed by another"+
	" underground spring. It probably gets about four feet deep at the most,"+
	" just enough for a quick bath. With the water being as cold as it is,"+
	" no one in their right mind would want to stay in for much longer than"+
	" that. A few large rocks stand out above the water, occasionally"+
	" people will sit on the large ones and dangle their feet in for as long"+
	" as they can stand to. The river slowly turns to the southeast after"+
	" the pool. Wildflowers grow along the bank and on either side of the"+
	" path here."
	);
	set_smell("default","The sweet scent of honey seems to be coming from the"+
	" south.");
	set_listen("default","The water splashes gently against the rocks.");
	set_items(([
	({"pond","pool","stream","river","brook"}) : "%^BOLD%^%^BLUE%^A shallow"+
	" pond has formed here thanks to a bend in the stream where it starts"+
	" to run southeast. It must be fed by another underground stream to"+
	" get this large, and the stream grows faster and deeper from this"+
	" point on. It is still only about four feet deep at the lowest point,"+
	" enough for a quick bath, no one would want to stay in much longer"+
	" than that due to the extreme cold of the water.",
	"rocks" : "Large gray rocks stand above part of the water. People sometimes"+
	" sit on them and dangle their feet and legs in the water for as long"+
	" as they can stand it.",
	"wildflowers" : "Wildflowers grow along the the bank of the stream and"+
	" on either side of the path. They range in color from %^MAGENTA%^purple%^RESET%^"+
	" to %^BOLD%^%^RED%^red%^RESET%^ to %^YELLOW%^gold%^RESET%^ and %^BOLD%^white%^RESET%^"+
	" and all the colors in between. They are very lovely, some are small and"+
	" others are larger, they are all very delicate.",
	]));
	set_exits(([
	"west" : "/d/guilds/kindred/rooms/campfire",
	"southeast" : "/d/guilds/kindred/rooms/bees",
	]));
}

void init()
{
	::init();
	add_action("drink","drink");
	add_action("sit","sit");
	add_action("dangle","dangle");
	add_action("dip","dip");
	add_action("dive","dive");
	add_action("swim","swim");
	add_action("wade","wade");
	add_action("jump","jump");
}

int drink(string str)
{
	if(str == "stream" || str == "pond" || str == "brook" || str == "river") {
		tell_object(TP,"You wouldn't want to drink from this water, it is"+
		" best to drink from the fresh spring.");
		return 1;
	}
}

int sit(string str)
{
	if(str == "rock" || str == "rocks") {
		tell_object(TP,"You hop out to one of the rocks in the pond and sit"+
		" down on it.");
		tell_room(ETP,""+TP->query_cap_name()+" hops out to one of the rocks"+
		" in the pond and sits down on it.",TP);
		return 1;
	}
	if(str == "bank") {
		tell_object(TP,"%^BOLD%^%^GREEN%^You sit down at the river bank.");
		tell_room(ETP,"%^BOLD%^%^GREEN%^"+TP->query_cap_name()+" sits down at"+
		" the river bank.",TP);
		return 1;
	}
	if(str == "ground") {
		tell_object(TP,"You take a seat on the cold, hard ground.");
		tell_room(ETP,""+TP->query_cap_name()+" take a seat on the cold, hard"+
		" ground.",TP);
		return 1;
	}
}

int dangle(string str)
{
	if(str == "feet") {
		tell_object(TP,"%^BOLD%^%^BLUE%^You dangle your feet in the ice cold"+
		" water.");
		tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->query_cap_name()+" dangle your"+
		" feet in the ice cold water.",TP);
		return 1;
	}
	if(str == "leg" || str == "legs") {
		tell_object(TP,"%^BOLD%^%^BLUE%^You bravely dangle your legs in the"+
		" icey water, they become numb rather quickly.");
		tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->query_cap_name()+" bravely"+
		" dangles "+TP->query_possessive()+" legs in the icey water, and they"+
		" slowly turn blue.",TP);
		return 1;
	} 
}

int dip(string str)
{
	if(str == "hand" || str == "hands") {
		tell_object(TP,"%^BOLD%^%^CYAN%^You dip your hand into the cold pool.");
		tell_room(ETP,"%^BOLD%^%^CYAN%^"+TP->query_cap_name()+" dips "+TP->query_possessive()+""+
		" hand into the cold pool.",TP);
		return 1;
	}
	if(str == "foot") {
		tell_object(TP,"%^BOLD%^%^CYAN%^You dip your foot into the pool to"+
		" test the water. It's cold!");
		tell_room(ETP,"%^BOLD%^%^CYAN%^"+TP->query_cap_name()+" dips "+TP->query_possessive()+""+
		" foot in the pool to test the water.",TP);
		return 1;
	}
}

int dive(string str)
{
	if(str == "pool" || str == "pond") {
		if(TP->query_stats("dexterity") > 17) {
			tell_object(TP,"%^BOLD%^You swan dive into the pool, hardly making"+
			" a splash.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" swan dives into the"+
			" pool, hardly making a splash.",TP);
			return 1;
		}
		if(TP->query_stats("dexterity") > 14) {
			tell_object(TP,"%^BOLD%^You dive into the pool, making a bit of"+
			" a splash.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" dives into the"+
			" pool, making a bit of a splash.",TP);
			return 1;
		}
		if(TP->query_stats("dexterity") < 5) {
			tell_object(TP,"%^BOLD%^You attempt to dive into the pool, but it"+
			" ends up as more of a belly flop.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" attempts to dive"+
			" into the pool, but it ends up as more of a belly flop.",TP);
			return 1;
		}
		else {
			tell_object(TP,"%^BOLD%^You perform a rather mediocre dive into"+
			" the pool.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" performs a rather"+
			" mediocre dive into the pool.",TP);
			return 1;
		}
	}
}

int swim(string str)
{
	if(str == "pool" || str == "stream" || str == "pond" || str == "river") {
		tell_object(TP,"%^BLUE%^You take a quick swim in the frigid water.");
		tell_room(ETP,"%^BLUE%^"+TP->query_cap_name()+" takes a quick swim"+
		" in the frigid water.",TP);
		return 1;
	}
}

int wade(string str)
{
	if(str == "pool" || str == "river" || str == "pond" || str == "stream" || str == "water" || str == "waters") {
		tell_object(TP,"%^BOLD%^%^BLUE%^You slowly wade into the freezing"+
		" cold waters of the pool.");
		tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->query_cap_name()+" slowly wades"+
		" into the freezing cold waters of the pool.",TP);
		return 1;
	}
}

int jump(string str)
{
	if(str == "pond" || str == "pool") {
		tell_object(TP,"%^CYAN%^You get a running start and jump into the pool,"+
		" splashing everyone around you.");
		tell_room(ETP,"%^CYAN%^"+TP->query_cap_name()+" gets a running start"+
		" and jumps into the pool, splashing everyone around "+TP->query_objective()+".",TP);
		return 1;
	}
}
