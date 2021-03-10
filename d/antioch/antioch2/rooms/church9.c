#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Second floor of a Grand Church");
	set_long(
	"The hallway comes to an end at the base of a large stair case"+
	" that spirals upwards and out of sight. Just before the stair"+
	" case is an %^BOLD%^ivory door%^RESET%^ on the eastern wall. The symbol of Jarmila is"+
	" carved into the upper part of the doorway with %^BOLD%^%^RED%^"+
	"r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^i%^BOLD%^e%^RESET%^%^RED%^s"
      " %^RESET%^for the rose petals. The %^YELLOW%^shield %^RESET%^of the symbol has been "
      "gilded with gold leaf, making for an impressive door."
      " Strangely enough there is no handle to it."
	);
	set_smell("default","The room smells deliciously of spiced apples.");
	set_listen("default","It is peacefully quiet here.");
	set_items(([
	({"rug","thin rug","floor"}) : "A thin rug stretches down the length of"+
	" the hallway. It is decorated in concentric rectangular shapes"+
	" of multiple colors and is kept very clean.",
	({"lamp","lamps","oil lamp","oil lamps"}) : "Oil lamps hang from"+
	" small metal circles that are placed in the ceiling at intervals"+
	" all the way down the hallway, giving light to the place.",
	"incense" : "Sticks of incense are placed in holders on the western"+
	" wall. They are a rich cinammon color and smell of of spiced"+
	" apples.",
	"ceiling" : "Metal circles are placed at intervals along the"+
	" ceiling and oil lamps hang from them.",
	({"incense holder","incense holders"}) : "Pewter incense holders"+
	" are placed at intervals along the western wall.",
	({"stairs","stone stairs","stair case","staircase"}) : "The large"+
	" stone stair case here spirals up to the third level. It is made"+
	" out of large stone blocks that look very sturdy.",
	"door" : "%^BOLD%^The door is made out of solid ivory. It is arched"+
	" to fit the shape of the doorway and seems to radiate a sense of power, making it"+
	" is rather intimidating. Oddly enough there is no door knob.%^RESET%^"
	]));
	set_exits(([
	"north" : ROOMS+"church8",
	"up" : ROOMS+"church14",
	"east" : ROOMS+"church10"
	]));
	set_door("door",ROOMS+"church10","east",0);
	set_string("door","open","%^BOLD%^The ivory door shimmers and"+
	" disappears.");
      set_string("door","close","%^BOLD%^The doorway shimmers and the ivory door appears.");
	set_post_exit_functions(({"east"}),({"go_east"}));
      set_door_description("door","%^BOLD%^The door is made out of solid ivory. It is arched"+
	" to fit the shape of the doorway and seems to radiate a sense of power, making it"+
	" is rather intimidating. Oddly enough there is no door knob.%^RESET%^");
}

void init()
{
	::init();
	add_action("sneak","sneak");
}

void sneak(string str)
{
	if(str == "east" || str == "e") {
		tell_object(TP,"You can't seem to sneak through that doorway.");
		return 1;
	}
}

int go_east()
{
	object myspl, obx;

	if(TP->query_invis()) {
		if(present("invisobx999",TP)) {
			obx = present("invisobx999",TP);
			obx->show_up();
		}
		if(present("TSR80",TP)) {
			obx = present("TSR80",TP);
			obx->cancel_inv();
		}
		if(TP->query_invis() && !avatarp(TP)) {
			TP->set_invis();
		}
	}
	if(TP->query_stoneSkinned() > 0) {
		while(objectp(myspl = MAGIC_D->get_spell_from_array(TP->query_property("spelled"),"stoneskin"))) {
			remove_property_value("spelled", ({myspl}));
			myspl->dest_effect();
		}
//		tell_object(TP,"You feel the stoneskin fall away from your skin.");
//		TP->set_stoneSkinned(0);
	}
	if(ALIGN->is_evil(TP)) {
		tell_object(TP,"%^RED%^You feel a pain so horrible rip through your body that"+
		" you can't stifle the scream that swells within your throat!");
		tell_room(ROOMS+"church10","%^BOLD%^"+TP->query_cap_name()+" screams in agony as "+TP->query_subjective()+" walks through the door.",TP);
		tell_room(ROOMS+"church9","%^BOLD%^"+TP->query_cap_name()+" screams in agony as "+TP->query_subjective()+" exits through the ivory door.",TP);
		set_property("magic",1);
		TP->cause_typed_damage(TP, "torso", roll_dice(1, 20) + 29, "divine");
		remove_property("magic");
	}
	return 1;
}
