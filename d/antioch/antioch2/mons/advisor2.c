#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

void create()
{
	::create();
	set_name("Sedrin");
	set_short("Sir Sedrin, a royal advisor");
	set_id(({"sedrin","Sedrin","advisor","royal advisor","second advisor","sir sedrin"}));
	set_long(
	"Sir Sedrin is a knight of high ranking. He has retired from adventuring"+
	" to advise the king of Antioch. He is dressed in a suit of spotless"+
	" armor with a rearing unicorn engraved onto the breastplate. He wears"+
	" no helm in respect of the court, and his dark hair is trimmed short"+
	" and is slowly turning gray. He wears a belt with a sword sheath on it,"+
	" but it is empty for only the guards are allowed to have weapons in the"+
	" throne room. He is a rather handsome man, though is only about five and"+
	" a half feet tall. He is still in excellent shape and looks alert for"+
	" any danger."
	);
	set_gender("male");
	set_race("human");
	set_alignment(1);
	set_hd(40,9);
	set_max_hp(420);
	set_hp(query_max_hp());
	set_overall_ac(-17);
	set_class("cavalier");
	set_mlevel("cavalier",40);
	set_level(30);
	set_stats("strength",19);
	set_stats("constitution",18);
	set_stats("dexterity",15);
	set_stats("wisdom",13);
	set_stats("intelligence",17);
	set_stats("charisma",15);
	set_exp(100);
	set("aggressive",0);
	set_property("swarm",1);
}
