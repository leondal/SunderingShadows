#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A log cabin");
	set_long(
	"This is a lovely log cabin. The floors and walls are made out of"+
	" pine logs. The bark has been removed from them and they have"+
	" been varnished to help them last longer. The logs making up"+
	" the floor have been cut flat and have been swept recently. To"+
	" the east is a little dining area. The table and chairs have been"+
	" hand carved from more pine wood. A vase of %^BOLD%^%^RED%^geraniums%^RESET%^"+
	" rests on the center of the table. South from the dining area is"+
	" the kitchen. It is rather simple with a stone stove and just a"+
	" few cabinets and drawers. On the western side of the room is"+
	" a small living room that surrounds a fireplace. A large %^GREEN%^green%^RESET%^"+
	" couch sits facing the fireplace. Off to the side of the couch"+
	" are two padded chairs. The bedroom is in the southwestern corner."+
	" Some thin pine walls surround it, but the doorway to it is open."+
	" You can see a bed crafted from pine logs and covered in a %^GREEN%^dark"+
	" green%^RESET%^ bedspread. A large pine dresser is in one corner"+
	" of the room with a lamp sitting on top of it."
	);
	set_smell("default","The cabin smells of pine.");
	set_listen("default","The cabin is quiet.");
	set_items(([
	"floor" : "The floor is made of pine logs that have been cut"+
	" flat, it appears quite clean.",
	({"wall","walls"}) : "The walls are made of pine logs. The bark"+
	" has been removed from them and they've been varnished to help"+
	" maintain them.",
	"ceiling" : "The ceiling is made from pine logs like the rest of"+
	" the house. Shaded oil lamps hang down in a few places to keep"+
	" the room well lit.",
	"door" : "A lovely pine wood door leads to the front yard.",
	({"lamps","oil lamp","oil lamps","shaded oil lamps","shaded lamp"}) : "Shaded oil lamps hang down from the ceiling, helping to keep the"+
	" house brightly lit.",
	({"lamp shade","lamp shades"}) : "%^GREEN%^The lamp shades are"+
	" green, matching the color scheme in the rest of the house.",
	"lamp" : "An oil lamp burns on top of the dresser in the bedroom.",
	"dresser" : "A pine dresser is in one corner of the bedroom. It"+
	" is rather plain and has a lamp on top of it.",
	({"bed","pine bed"}) : "A bed made of pine logs is in the far"+
	" corner of the bedroom. A %^GREEN%^dark green%^RESET%^ bedspread"+
	" has been carefully folded over it.",
	({"bedspread","dark green bedspread","green bedspread"}) : "%^GREEN%^A thick wool bedspread has been dyed a dark green color. It"+
	" looks very soft and warm.",
	"vase" : "%^BOLD%^A simple glass vase holds a boquet of lovely"+
	" %^RED%^geraniums%^WHITE%^.",
	"geraniums" : "%^BOLD%^%^RED%^Several bright red geraniums sit"+
	" in a vase on top of the dining table.",
	({"green couch","couch"}) : "%^GREEN%^A large green couch is in"+
	" the living room, facing the fireplace.",
	"fireplace" : "The fireplace is made of carefully cut gray stones."+
	" A flat metal sheet extends from it and has been secured to the"+
	" floor. It's probably to help prevent the house catching on fire"+
	" from sparks and such. You can see ashes in the fireplace, it"+
	" doesn't appear to have been lit for some time.",
	({"chairs","padded chairs"}) : "Two rather large chairs sit on"+
	" either side of the couch. They've been padded with thick %^GREEN%^green%^RESET%^"+
	" cushions to make them more comfortable.",
	({"table","dining table","pine table"}) : "A small dining table"+
	" that appears to have been hand carved from pine wood is on the"+
	" eastern side of the room. Four pine chairs surround it and a"+
	" vase of %^BOLD%^%^RED%^geraniums%^RESET%^ sits on top of it.",
	({"pine chairs","dining chairs"}) : "Four hand carved pine chairs"+
	" have been placed around the table.",
	({"stove","stone stove"}) : "A small and very basic stone stove"+
	" is placed in the far corner of the kitchen.",
	({"cabinets","drawers"}) : "There are a few cabinets and drawers"+
   " in the kitchen that most likely hold the dishes and silver ware.",
	]));
	set_exits(([
	"north" : ROOMS+"yard3",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard3","north",0);
	new(MONS+"citizend")->move(TO);
	if(query_night() == 1) {
		set_locked("door",1);
	}
}
