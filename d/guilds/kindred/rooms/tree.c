#include <std.h>
inherit ROOM;

int count;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(FOOT_PATH);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Kindred Meeting Hall");
	set_long(
	"You are standing inside the hollow trunk of a living tree. It is rather"+
	" awe inspiring just to be here. The hollow trunk that you're standing"+
	" in is huge, about as big as a regular room. The wood around you is"+
	" still alive and growing. Shelves around the walls are made from natural"+
	" contours of the tree, as though it knew what the people living here"+
	" needed. The chairs and stools that are scattered about the room have"+
	" been carved from the wood of the tree, but from dead branches that"+
	" needed to be removed. There is a table on the eastern side with a"+
	" platter laid out on it. From the center of the ceiling a little tendril"+
	" of wood that serves as a hook for a chandelier made of iron. From"+
	" the iron chandelier hangs softly glowing moss that lights the room."
	);
	set_smell("default","The scent of honey lingers in the room.");
	set_listen("default","You can hear the branches above you creaking in"+
	" the wind.");
	set_items(([
	"floor" : "The hard dirt floor has a woven straw matt stretched out"+
	" across it.",
	({"straw matt","matt"}) : "%^YELLOW%^A woven straw matt has been stretched"+
	" out across the floor. It has been kept fairly clean from dust, well, as"+
	" clean as can be expected.",
	"ceiling" : "The ceiling is domed and smooth, made from solid wood. In"+
	" the center a tendril of wood curves down, forming a perfect hook for"+
	" a chandelier to be hung from.",
	"chairs" : "Several chairs hand carved from fallen branches of the tree"+
	" are scattered across the room.",
	"table" : "A table that was carefully hand carved out of a solid branch"+
	" of this magnificent tree is on the east. A platter has been laid out"+
	" on the table.",
	"platter" : "A platter of honey comb has been thoughtfully laid out. You"+
	" can take a piece if you wish.",
	({"shelves","walls"}) : "Natural grooves in the walls form shelves for"+
	" books, statues, and other items. The tree created them in the most"+
	" convenient of places, as though it were alive and sentient. But that's"+
	" rather silly...isn't it?",
	({"chandelier","iron chandelier"}) : "A large wrought iron chandelier"+
	" hangs from a natural hook in the ceiling. Softly glowing moss clings"+
	" to the chandelier, slowly eating it away. Every now and then the"+
	" chandelier itself must be replaced, but that is much cheaper than the"+
	" constant cost of lamp oil.",
	({"moss","glowing moss"}) : "%^BOLD%^%^CYAN%^The moss glows a soft blue"+
	" color and sheds light on the rest of the room. It is a wonderful source"+
	" of light for it does not have heat to hurt the tree, and it grows only"+
	" along the length of the iron chandelier. The light that it sheds is"+
	" constant and soft on the eyes.",
	]));
	set_exits(([
	"south" : "/d/guilds/kindred/rooms/trail3",
	]));
	count = 5;
}

void reset()
{
	::reset();
	if(count < 5) {
		tell_room(ETO,"%^BOLD%^A little sprite flutters into the room, quickly"+
		" refilling the platter with honey comb and then leaving just as"+
		" quickly.");
		add_item("platter","A platter of honey comb has been thoughtfully laid"+
		" out. You can take a piece if you wish.");
		count = 5;
	}
}

void init()
{
	::init();
	add_action("take_honey","take");
	add_action("sit","sit");
}

int take_honey(string str)
{
	if(str != "honey comb") {
		tell_object(TP,"Try take honey comb.");
		return 1;
	}
	if(count < 1) {
		tell_object(TP,"There is no more honey comb left, it's all been taken.");
		return 1;
	}
	else {
		tell_object(TP,"%^YELLOW%^You reach out and take a piece of honey"+
		" comb from the platter.");
		tell_room(ETP,"%^YELLOW%^"+TP->query_cap_name()+" reaches out and"+
		" takes a piece of honey comb from the platter.",TP);
		count -= 1;
		new("/d/guilds/kindred/obj/honey.c")->move(TP);
		if(count < 1) {
			add_item("platter","The platter is empty save for a few sticky"+
			" globs of honey.");
		}
		return 1;
	}
}	

int sit(string str)
{
	if(str == "chair") {
		tell_object(TP,"%^BOLD%^A tiny shiver runs up your spine as you"+
		" take a seat in one of the chairs.");
		tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" takes a seat in one"+
		" of the chairs.",TP);
		return 1;
	}
	if(str == "floor" || str == "matt") {
		tell_object(TP,"You sit down and get comfortable on the floor.");
		tell_room(ETP,""+TP->query_cap_name()+" sits down and situates"+
		" "+TP->query_objective()+"self on the floor.",TP);
		return 1;
	}
	if(str == "at table") {
		tell_object(TP,"You take a seat at one of the chairs at the table.");
		tell_room(ETP,""+TP->query_cap_name()+" takes a seat at one of the"+
		" chairs at the table.",TP);
		return 1;
	}
}
