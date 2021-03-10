#include <std.h>
#include "../../newbie.h"
inherit "/d/common/inherit/hitching_post";

// Offestry Tether Post Area - Created February 2009 by Ari
// Installed and/or Edited by Nienne

void create()  {
	::create();

		set_indoors(0);
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		set_short("Offestry Stables");
		set_long("%^RESET%^This area of the stables is designed for "+
			"those riders who wish to temporarily tether their "+
			"mounts while they shop or visit friends in the "+
			"city.  A long %^ORANGE%^wooden post %^RESET%^has been "+
			"set up in the middle of a large, cleared area, giving "+
			"ample room to %^YELLOW%^tether %^RESET%^several "+
			"mounts as well as give those mounts room to move "+
			"around a little.  Below the post a narrow %^CYAN%^"+
			"water trough %^RESET%^has been set for the animals "+
			"to drink from.  Fresh water is added regularly by "+
			"the stable hands.  Though not a proper stall, this "+
			"large area does have a set of doors that close it off "+
			"from the main part of the stable, thus ensuring that "+
			"the animals don't escape in case their tethers become "+
			"loose. \n"
			"%^YELLOW%^You may %^WHITE%^tether mount%^YELLOW%^ "+
			"here once you have %^WHITE%^dismount%^YELLOW%^ed your "+
			"animal.  It will no longer follow you and will "+
			"remain at the tether spot much longer then if just "+
			"left standing around outside.%^RESET%^");
		
		set_smell("default","The room smells strongly of horses.");
		set_listen("default","You can hear the animals stamping "+
			"about in their stalls.");
		
		set_items( ([
			({"post","wooden post"}):"This large wooden post is "+
				"nearly wall to wall, giving lots of room for "+
				"several horses to be tethered side by side.",
			({"water trough","trough"}):"The narrow trough is "+
				"regularly filled with fresh water to give the "+
				"tired animals a refreshing drink.",
		]) );
				
		set_exits(([
			"north":MAINTOWN"stable",
		]));
		
		set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}
