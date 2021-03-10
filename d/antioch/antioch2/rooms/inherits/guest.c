#include <std.h>
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("%^BOLD%^Guest Room");
	set_long(
	"This is a guest room in Antioch's palace. All the guest rooms are"+
	" identical so as not to upset any visiting diplomats, each one is"+
	" treated equally. The floor is covered in a %^GREEN%^dark green%^RESET%^"+
	" carpet. The walls have been painted beige and four crystal lamps have"+
	" been fixed to them, one on each wall. In the western corner of the"+
	" room is a large canopy bed. The bed is made out of polished walnut"+
	" with a %^GREEN%^forest%^RESET%^ bedspread and pillows. There is a"+
	" matching walnut chest at the foot of the bed for items to be stored in."+
	" Towards the back of the room is a walnut study desk with a padded"+
	" chair. On the eastern side of the room is a long walnut dresser. Next"+
	" to that in the corner is a large walnut closet. Attached to a door"+
	" on the front of the closet is a long silver mirror. This is an elegant"+
	" room that would be comfortable for a weeks stay."
	);
	set_smell("default","The soothing scent of vanilla floats in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	({"floor","carpet","rug","green carpet","dark green carpet"}) : "%^GREEN%^A"+
	" dark green carpet covers the floor. It is very thick and kept quite clean.",
	({"wall","walls"}) : "The walls are painted a soft beige. On each wall"+
	" is a crystal oil lamp that sheds light on the room.",
	({"oil lamp","oil lamps","crystal lamp","crystal lamps","crystal oil lamps","crystal oil lamp","lamp","lamps"}) : "%^BOLD%^%^GREEN%^Crystal"+
	" oil lamps are positioned around the room. The crystal is tented a"+
	" slight green shade and gives off a faint emerald light. The lamps"+
	" themselves give off a delightful vanilla fragarance that floats"+
	" around the room.",
	({"walnut dresser","dresser","long dresser","long walnut dresser"}) : "The"+
	" walnut dresser is approximately eight feet in length, reaching four"+
	" feet high. It is quite lovely, with %^YELLOW%^gold tinted%^RESET%^"+
	" handles on all the drawers. Delicate decorations are engraved along"+
	" the drawers and sides of the dresser.",
	({"mirror","silver mirror","long mirror","long silver mirror"}) : "A long"+
	" silver mirror is fixed to one of the doors on the closet. It has a"+
	" braided silver frame and is about seven feet high. It prefectly"+
	" reflects all images.",
	({"walnut closet","closet"}) : "This beautiful walnut closet is in the"+
	" far eastern corner of the room. It is engraved with ivy leaves and"+
	" has two doors that open in the front. Clothes can be hung within it."+
	" Attached to the front of one of the doors is a long silver mirror.",
	({"bed","walnut bed","canopy bed"}) : "In the western corner of the room"+
	" is a large canopy bed made of polished walnut wood. It looks very soft"+
	" and comfortable and it is quite large. It is covered in a %^GREEN%^forest%^RESET%^"+
	" bedspread.",
	({"bedspread","green bedspread","forest beadspread"}) : "%^GREEN%^A"+
	" bedspread of dark forest green covers the large canopy bed. It is"+
	" decorated with a pattern of different leaves and ferns and looks very"+
	" warm. It is made of cotton and has been carefully hand-dyed.",
	({"pillow","pillows","green pillows","forest pillows","feather pillows"}) : "%^GREEN%^Several"+
	" large feather pillows are on the canopy bed. They are covered in forest"+
	" green pillow cases, matching the bedspread.",
	({"desk","study desk","walnut desk","walnut study desk"}) : "An old but"+
	" sturdy walnut study desk has been placed in the back of the room. It"+
	" has probably been used by many visiting diplomats to make last minute"+
	" changes to treaties and make new drafts of proposed alliances. It comes"+
	" with a comfortable chair that is padded with a %^GREEN%^green%^RESET%^"+
	" cushion.",
	({"chair","walnut chair","padded chair"}) : "This chair matches perfectly"+
	" the little study desk. It is old, but sturdy, and has been padded with"+
	" a %^GREEN%^dark green%^RESET%^ cushion for added comfort.",
	({"chest","walnut chest"}) : "At the foot of the bed is a large walnut"+
	" chest that can be used to store the personal items of the palace guests."+
	" A forest has been carefully engraved onto the top and sides of the"+
	" chest, creating a lovely effect."
	]));
}
