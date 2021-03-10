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
	set_property("no teleport",1);
	set_short("%^BOLD%^Room of the High Cleric");
	set_long(
	"This very impressive room probably belongs to the High Cleric of"+
	" the church. The ceiling is domed slightly and has been enchanted"+
	" with an image of the stars at night. The image is absolutely"+
	" breath taking, the colors are vivid blacks, purples, and reds"+
	" and they seem somehow alive. The stars shed a soft light about"+
	" the room. The bed is on the right hand wall. It is covered with"+
	" an ivory fleece blanket with matching satin sheets and two"+
	" large feather pillows, it looks comfortable. The carpet is a"+
	" spotless white and very thick, it muffles your footsteps. On"+
	" the left hand side of the room is a cedar wood study desk. Next"+
	" to it in the corner is a book shelf. Against the far wall on"+
	" the left is a large silver mirror. The mirror is approximately"+
	" seven feet tall and oval shaped. It has a frame and base made"+
	" of shadowtop wood and it is fixed to the back wall. At the foot"+
	" of the bed is a large chest."
	);
	set_smell("default","The room smells fresh and clean.");
	set_listen("default","A heavy silence hangs in the room.");
	set_items(([
	({"mirror","silver mirror"}) : "%^BOLD%^Fixed to the left side of the"+
	" back wall is a silver mirror. It is about seven feet tall and"+
	" oval shaped. The frame and base of the mirror are made out of"+
	" dark shadowtop wood.%^RESET%^",
	"chest" : "At the foot of the bed is a large wooden chest. It is made out of"+
	" shadowtop wood and matches the bed. On the top of the chest a symbol of"+
	" Jarmila has been carved. You can't imagine anyone stupid enough to face Jarmila's"+
	" wrath in trying to open the chest without permission.",
	"ceiling" : "The ceiling of the room is domed and has been"+
	" enchanted with a magical image of a night sky. The colors are"+
	" vibrantly beautifully, they seem to pulse and shift like real"+
	" stars. The stars themselves fill the room with a silvery"+
	" light. The scene is absolutely breath taking.",
	({"floor","rug","carpet","white carpet"}) : "%^BOLD%^The floor"+
	" is covered in a spotless white rug. It is very thick and soft,"+
	" muffling footsteps.",
	({"desk","study desk"}) : "The desk is made out of a cedar wood"+
	" that has been varnished darker. A matching cushioned chair is"+
	" with it and a beeswax candle on the desk top shows the long"+
	" hours that the high cleric has sat there reading.",
	({"book shelf","book shelves","bookshelf"}) : "A cedar book shelf"+
	" sits in the left hand corner of the room, next to the desk. It"+
	" is filled with ancient tomes of sacred scriptures as well as"+
	" poetry and other writings.",
	"books" : "All the books on the book shelf look quite old. Their"+
	" covers are worn with age although they look to have been well"+
	" cared for.",
	"bed" : "The bed is on the right hand side of the room. It is"+
	" covered in an %^BOLD%^ivory fleece bedspread%^RESET%^ with"+
	" matching %^BOLD%^white satin sheets%^RESET%^ and two large"+
	" feather pillows.",
	({"blankets","covers","bed spread","bedspread","fleece covers"}) : "%^BOLD%^The"+
	" bedspread is made of white fleece. It is incredibly soft to the"+
	" touch and will keep you warm during the winter, or cool in the"+
	" summer time.",
	({"sheets","white satin sheets","satin sheets","white sheets"}) : "%^BOLD%^White"+
	" satin sheets are beneath the fleece bedspread, they're silky"+
	" smooth.",
	({"candle","beeswax candle"}) : "A beeswax"+
	" candle sits in a holder on top of the desk. It once was large"+
	" but has now been burned down to almost nothing.",
	({"holder","candle holder"}) : "The candle holder is in the shape"+
	" of a flower blossom, it is made of pewter and is rather pretty.",
	({"pillow","pillows","feather pillow","feather pillows"}) : "Two"+
	" large feather pillows are on top of the bed. They look very"+
	" fluffy and comfortable."
	]));
	set_exits(([
	"west" : ROOMS+"church9"
	]));
	set_door("door",ROOMS+"church9","west",0);
	set_string("door","open","%^BOLD%^The ivory door shimmers and"+
	" disappears.");
   set_string("door","close","%^BOLD%^The doorway shimmers and the ivory door appears.");
	set_post_exit_functions(({"west"}),({"go_west"}));
	new(MONS+"sebastian")->move(TO);
}

void init()
{
	::init();
}


int GoThroughDoor()
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
		tell_room(ROOMS+"church9","%^BOLD%^"+TP->query_cap_name()+" screams in agony as "+TP->query_subjective()+" walks through the door.",TP);
		tell_room(ROOMS+"church10","%^BOLD%^"+TP->query_cap_name()+" screams in agony as "+TP->query_subjective()+" exits through the ivory door.",TP);
		set_property("magic",1);
		TP->cause_typed_damage(TP, "torso", roll_dice(1, 20) + 29, "divine");
		remove_property("magic");
	}
    return ::GoThroughDoor();
}
