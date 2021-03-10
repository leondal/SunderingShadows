#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
	set_property("indoors",1);
	set_property("no sticks",1);
	set_property("light",2);
	set_short("A beautiful house");
	set_long(
	"The eastern side of the hardwood floor is covered by a thick"+
	" %^GREEN%^green%^RESET%^ rug. The western half is made up of a dining"+
	" room and kitchen, the floor itself looks neatly swept. The dining"+
	" room set is made out of walnut. There is an oval table surrounded by"+
	" six chairs. To the northwest is a servicable kitchen. An island is set"+
   " up in the center of it, containing drawers for silver ware and a"+
	" counter top with a large cutting board on it. Several jars of herbs"+
	" are scattered about the kitchen. A stove is tucked into the far"+
	" corner. A couple of pots hang on the wall from pegs. The eastern half"+
	" of the house is a large living room. There is a large %^GREEN%^emerald"+
	" green%^RESET%^ couch placed against the back wall. A low walnut coffee"+
	" table is positioned in front of it. A vase of %^BOLD%^roses%^RESET%^"+
	" sits elegantly on the coffee table. A smaller couch is on the southern"+
	" wall with a matching love seat across from it. In the northeastern"+
	" corner is a set of stairs that leads up to the second story."
	);
	set_smell("default","The scent of roses drifts in from outside.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"rug","carpet","floor","green carpet"}) : "%^GREEN%^A dark forest"+
	" green rug stretches over the eastern half of the floor, blending well"+
	" with the living room.",
	"ceiling" : "The ceiling is plain and not very interesting.",
	"hardwood floor" : "A well swept hardwood floor is on the western side"+
	" of the room where the dining room and kitchen are.",
	"kitchen" : "The kitchen is on the northwest. An island is set"+
   " up in the center of it, containing drawers for silver ware and a"+
	" counter top with a large cutting board on it. Several jars of herbs"+
	" are scattered about the kitchen. A stove is tucked into the far"+
	" corner. A couple of pots hang on the wall from pegs.",
	"living room" : "The living room takes up the eastern side of the house."+
	" There is a large %^GREEN%^emerald green%^RESET%^ couch placed against"+
	" the back wall. A low walnut coffee table is positioned in front of it."+
	" A vase of %^BOLD%^roses%^RESET%^ sits elegantly on the coffee table. A"+
	" smaller couch is on the southern wall with a matching love seat across"+
	" from it.",
	"dining room" : "On the southwestern part of the house is the dining"+
	" room. The dining room set is made out of walnut. There is an oval table"+
	" surrounded by six matching chairs.",
	({"dining table","table","oval table","walnut table"}) : "This is a large"+
	" walnut dining table. It has been highly polished and the surface shines"+
	" without a scratch on it.",
	({"chair","chairs","walnut chairs"}) : "Six matching walnut chairs surround"+
	" the dining room table. There is one at either end of the table, with"+
	" two on each side of it.",
	({"coffee table","walnut coffee table","low table"}) : "A low lying"+
	" walnut coffee table is in front of the couch. People can set drinks"+
	" and things on it. In the center is a crystal vase with a lovely"+
	" arrangement of %^BOLD%^white%^RESET%^ roses.",
	"vase" : "%^BOLD%^A pretty crystal vase sits on top of the coffee table,"+
	" diamond patterns are engraved on it, helping it to reflect the light"+
	" and sparkle.",
	({"roses","white roses"}) : "%^BOLD%^Several beautiful white roses have"+
	" been placed in the vase. Their scent fills the room.",
	({"couch","green couch","emerald couch","emerald green couch","large couch"}) : "%^GREEN%^A large emerald green couch has been placed against"+
	" the back wall. It looks like it could fit four large people comfortably.",
	({"small couch","smaller couch"}) : "%^GREEN%^Placed against the southeastern"+
	" wall of the house is a slightly smaller matching couch that could"+
	" hold approximately three people.",
	({"love seat","loveseat"}) : "%^GREEN%^Across from the smaller couch and"+
	" next to the large one is a matching love seat that looks like it's"+
	" gotten its fair share of use.",
	"stairs" : "In the northeastern corner of the room a set of stairs leads"+
	" up to the second floor of the house.",
	({"island","counter"}) : "An island is set up in the center of the"+
	" kitchen, with a long counter and drawers surrounding the bottom part."+
	" There is a cutting board on top of it.",
	"drawers" : "There are many drawers in the kitchen that hold cooking"+
   " utensils, silver ware, and probably some ingredients.",
	"counters" : "The kitchen has several counter sections that can be used.",
	"cutting board" : "A large wooden cutting board sits on top of the island"+
	" in the center of the kitchen.",
	({"herbs","jars"}) : "Several jars of herbs are scattered about the"+
	" kitchen.",
	({"pots","pans"}) : "Pots and pans are hung on the western wall of the"+
	" kitchen from pegs.",
	"pegs" : "There are a few wooden pegs on the western wall of the kitchen"+
	" from which pots and pans hang.",
	({"wall","walls"}) : "%^BOLD%^%^GREEN%^The walls are painted a light"+
	" mint green. Several oil lamps are placed at intervals along them,"+
	" lighting the room.",
	({"lamp","lamps","oil lamp","oil lamps"}) : "Oil lamps are placed at"+
	" intervals along the walls to keep the house well lit.",
	"door" : "%^BOLD%^%^GREEN%^A mint green door leads out the front of the"+
	" house.",
	]));
	set_exits(([
	"south" : ROOMS+"yard4",
	"up" : ROOMS+"upstairs1",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard4","south",0);
	if(query_night() == 1) {
		set_locked("door",1);
		new(MONS+"citizene")->move(TO);
		new(MONS+"citizenf")->move(TO);
	}
}
