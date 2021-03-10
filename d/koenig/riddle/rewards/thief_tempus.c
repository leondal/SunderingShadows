//thief_tempus.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("red boots");
	set_id(({ "boots", "boots of the battlescout" }));
	set_short("%^RESET%^%^RED%^Boots of the Battlescout%^RESET%^");
	set_obvious_short("A pair of deep red leather boots");
	set_long(
@AVATAR
%^RED%^Made of soft leather, these deep red boots rise up to one's knees.  The boots are made in a fashion where fit close to one's legs, offering solid protection.  The soles of the boots are made from a neutral grey leather and heavily padded, possibly to aid against rocks, caltrops and thorns.  The boots are simple in design, but what they lack in form they make up for in function and protection.

AVATAR
	);
	set_lore(
@AVATAR
The Boots of the Battlescout are used by a band of rogues dedicated to Tempus.  Usually the Lord of Battles holds not love for rogues who use silver tongues and sneaky tactics to aid them in battle, though he has seem to taken favor on a band of rogues dedicated to his cause.  The Battlescouts are sent ahead of an army to spy on the enemy's camps and observe their patorls and forces.  The Battlescout's job is also to search the battlefield for any traps or dirty tactics that their enemies might have prepared, for the followers of Tempus and the Battlelord hold no love for those who use coward's tactics to win the battle.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" pulls of the red leather boots.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You pull the boots off, but know that your service to Tempus' army is not done yet.");
	return 1;
}
