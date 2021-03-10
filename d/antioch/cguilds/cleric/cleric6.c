#include <std.h>
#include "../cleric.h"
inherit ROOM;

int uses;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",3);
	set_short("%^BOLD%^An altar room in the cleric guild");
	set_long(
	"This is a small room with a large altar on the far wall. The altar is"+
	" made out of gray marble and there is a depression in the center that"+
	" is filled with holy water. Beyond the water is a large silver cross."+
	" Engraved into the cross are the symbols of each god of the realms. The"+
	" good gods are on the top part of the cross, the evil gods are opposite"+
	" them and the neutral gods take up the horizontal cross section. There"+
	" are two pedestals on either side of the altar that hold empty vials."+
	" A cleric can dip a vial into the holy water and fill it up with the"+
	" blessing of their particular god. You can %^BOLD%^dip water%^RESET%^"+
	" from the altar. Near the walls are two braziers lit with dancing flames"+
	" that give light to the room."
	);
	set_smell("default","The faint scent of gardenias floats into the room.");
	set_listen("default","There is a peaceful silence to the room.");
	set_items(([
	({"altar","large altar","marble altar"}) : "A large gray marble altar is"+
	" on the far side of the room. In the center of the altar is a depression"+
	" that is filled with holy water. Beyond that is a large silver cross"+
	" that is engraved with all the symbols of the gods of the realms.",
	({"cross","silver cross"}) : "The signs of the good gods covers the top"+
	" part of the cross with the evil gods opposite them on the bottom. On"+
	" the middle cross part are the gods of neutrality and in the very center"+
	" of the cross is the Eye of Helm.",
	({"depression","water","holy water"}) : "There is a depression in the"+
	" center of the altar that is filled with holy water.",
	({"vial","vials"}) : "On top of the pedestals next to the altar are empty"+
	" vials that you can use to %^BOLD%^dip water%^RESET%^ from the altar.",
	({"pedestal","pedestals"}) : "On either side of the altar are two ornate"+
	" pedestals made of %^BOLD%^%^BLACK%^obsidian%^RESET%^ that have empty"+
	" vials on top of them.",
	"floor" : "The floor is made of gray stones and looks very clean.",
	"ceiling" : "The ceiling is flat and made of gray stone blocks.",
	({"wall","walls"}) : "The walls of the room are made of gray stones and"+
	" the fire light flickers across them, giving light to the room.",
	({"brazier","braziers"}) : "Two golden braziers are on either side of"+
	" the room. They are lit with yellow, red, and orange dancing flames.",
	({"flame","flames","fire","fires"}) : "Flames flicker within the braziers,"+
	" they almost seem to be dancing some intricate forgotten dance. As you"+
	" stare at them they seem to brighten and grow larger, but shrink back"+
	" to their normal size as you look away.",
	]));
	set_exits(([
	"west" : ROOMS+"cleric1",
	]));
	uses = 6;
}

void init()
{
	::init();
	add_action("dip","dip");
}

void dip(string str)
{
	if(TP->query_bound() || TP->query_paralyzed() || TP->query_tripped() || TP->query_unconcious()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}

	if(!str) return 0;
	if(str != "water" && str != "holy water") {
		write("Dip what?\n");
		return 1;
	}
	if(uses < 1) {
		write("There is no holy water left!\n");
		return 1;
	}
	else {
		tell_object(TP,"You take a vial and dip it into the depression,"+
		" filling it with holy water.");
		tell_room(TO,""+TP->query_cap_name()+" takes a vial and dips it into"+
		" the depression in the altar, filling it with holy water.",TP);
		new("/d/shadow/room/city/cguild/paladin/hlywater")->move(TP);
		uses -= 1;
		return 1;
	}
}

void reset()
{
	::reset();
	if(uses < 6) {
		tell_room(TO,"The %^BOLD%^%^RED%^flames%^RESET%^ flare brightly,"+
		" momentarily blinding you. When you can see you notice that the"+
		" holy water is once more full.");
		uses = 6;
		return 1;
	}
}
