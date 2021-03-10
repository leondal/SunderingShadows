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
	set_short("A nice bedroom");
	set_long(
	"This is a cozy little bedroom. The carpet is thick and a bright"+
	" %^BOLD%^%^RED%^red%^RESET%^ color. The walls here have apple-print"+
	" wall paper. There is a large bed in the far corner of the room that"+
	" has a matching %^BOLD%^%^RED%^red%^RESET%^ bedspread. A large oak"+
	" dresser is on the north wall, it has several cute little ceramic"+
	" statues on it. Against the eastern wall is a large oak closet that"+
	" could fit a fair amount of clothes."
	);
	set_smell("default","The bedroom smells faintly of apples.");
	set_listen("default","The bedroom is quiet.");
	set_items(([
	({"floor","carpet","red carpet"}) : "%^BOLD%^%^RED%^A bright red carpet"+
	" covers the floor.",
	"ceiling" : "The ceiling is rather plain and boring.",
	({"wall","walls"}) : "The walls are covered in apple-print wall paper."+
	" You're not even sure you've ever seen apple-print wall paper before.",
	({"wall paper","wallpaper","apple-print wall paper","apple wall paper"}) : "%^BOLD%^The"+
	" wall paper is mostly white, with %^RED%^red%^WHITE%^ apples printed"+
	" on it in rows.",
	"bed" : "A large oak bed is tucked into the far corner of the room. It"+
	" has a bright %^BOLD%^%^RED%^red%^RESET%^ bedspread on it.",
	"bedspread" : "%^BOLD%^%^RED%^The bedspread has been dyed a bright red"+
	" color that reminds you of apples. It looks soft and warm.",
	({"dresser","oak dresser"}) : "A large oak dresser has been placed against"+
	" the north wall. It is approximately four and a half feet high and two"+
	" feet deep. Cute little ceramic statues have been placed on top of it.",
	({"closet","oak closet"}) : "A nice sized oak closet is on the eastern"+
	" wall. It could probably hold a fair amount of clothes.",
	({"statues","ceramic statues"}) : "Adorable little ceramic statues are"+
	" on top of the dresser. There is one of a cow, a horse, a pig, a bunny,"+
	" a duck, a dog, and a cute little kitten.",
	"bedroom door" : "A wooden door leads back into the main part of the house.",
	]));
	set_exits(([
	"house" : ROOMS+"house7",
	]));
	set_door("bedroom door",ROOMS+"house7","house",0);
}
