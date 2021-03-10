#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("%^YELLOW%^Palace of Antioch");
	set_long(
	"This is a hallway on the second floor of Antioch's palace. The floor is"+
	" covered in a %^RED%^crimson%^RESET%^ and %^YELLOW%^gold%^RESET%^ rug"+
	" that stretches back to the west. To the south is a cedar door that"+
	" leads to the guest room. On the walls are portraits of some of the"+
	" ancient royalty of Antioch. On the south wall hangs a portrait of a"+
	" dark haired queen. On the north wall are two paintings, one of a sandy"+
	" haired prince and the other of a beautiful young woman with white hair."
	);
	set_smell("default","The soothing scent of vanilla floats in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to west. It"+
	" is finely woven and quite thick and sturdy. %^RED%^Crimson%^RESET%^"+
	" is the primary color of the rug, and a few slender %^YELLOW%^crimson%^RESET%^"+
	" stripes line the edges.",
	({"lamp","lamps","oil lamp","oil lamps","crystal lamps","crystal oil lamps"}) : "%^BOLD%^Crystal"+
	" oil lamps are hung at intervals along the walls. The light shines"+
	" through the crystal, expanding and sparkling about the room. They give"+
	" off a pleasant vanilla scent.",
	"ceiling" : "The ceiling is rather unremarkable, but it is fun to stare"+
	" at the dancing lamp light.",
	"floor" : "The floor is covered in a large rug.",
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a pale tan"+
	" color. Paintings are hung on the walls and oil lamps are fastened at"+
	" fixed intervals.",
	({"door","south door","wolf door"}) : "The door is made of sturdy cedar wood. In the"+
	" center of the door the image of a wolf is carved in the center of it.",
	({"portrait 1","south wall","south portrait","southern portrait","south painting","southern painting","queen","dark haired queen","queen portrait","queen painting"}) : "Set in an obsidian frame and hung on the"+
	" southern wall is a portrait of a an %^BOLD%^%^BLACK%^ebony%^RESET%^"+
	" haired queen. Engraved on the bottom of the frame is the name 'Queen"+
	" Esmerelda.' Her dark hair is pulled back into a braid that falls over"+
	" her shoulders. She is wearing a %^MAGENTA%^dark purple%^RESET%^ dress"+
	" and a delicate silver crown. Her eyes are a warm brown and her lips"+
	" have been painted %^RED%^red%^RESET%^ with her eyes highlighted by"+
	" %^MAGENTA%^violet%^RESET%^ powder. She is probably in her late thirties,"+
	" but is still very attractive. Queen Esmerelda was said to have been"+
	" a natural healer. She kept Antioch alive during the time of the plagues"+
	" and very few of the citizens were lost. If it were not for her efforts"+
	" Antioch may have been wiped off the map.",
	({"portrait 2","prince","prince portrait","painting 1"}) : "On the north"+
	" wall is a portrait in a ornate silver frame. An inscription on the"+
	" bottom of the frame reads: Prince Adrian. The portrait is that of"+
	" a young prince with sandy blonde hair. He is standing proudly with"+
	" a sword in his hand. He is dressed in a %^BOLD%^%^RED%^red silk%^RESET%^"+
	" shirt that is tied with a %^BOLD%^white sash%^RESET%^ with %^BOLD%^white%^RESET%^"+
	" tights underneath and a pair of %^BOLD%^%^BLACK%^black%^RESET%^ shoes."+
	" He is quite handsome, though obviously young. Legend says that hundreds"+
	" of years ago Prince Adrian was lost at sea while traveling on a"+
	" diplomatic mission to an island nation. Only one person from the voyage"+
	" survived and his tale was rather odd. He swore that the ship had been"+
	" caught in a bad storm and that they had crashed into the side of a"+
	" large castle that was just barely sticking up out of the water. With"+
	" the ship sinking, the crew climbed aboard the strange castle. But with"+
	" dawn, the castle started to sink back into the ocean. The sailor tried"+
	" to wake the others, but he couldn't, they were all under some enchanted"+
	" sleep. The sailor swam away, watching the castle sink, and was eventually"+
	" found by another crew of sailors. Though no one really believed his"+
	" odd tale, the legend has remained in Antioch.",
	({"painting 2","portrait 3","woman","young woman"}) : "Hung on the north"+
	" wall and set in a coral frame is the portrait of an angelic young woman"+
	" with flowing %^BOLD%^white%^RESET%^ hair. The name on the bottom of the"+
	" portrait reads: Princess Sylvanna. In the portrait she is happily"+
	" picking flowers near the shore of a lake. The clouds above her are"+
   " shaped like running unicorns. It is said that this sweet girl befriended"+
	" the unicorns in the mountains, and that she was even allowed to ride"+
	" them. Princess Sylvanna was born ill, however, and although she lived"+
	" much longer than the doctors expected, she died at the age of seventeen."+
	" Her father had her burried at a secret place up in the mountains and"+
	" ordered a unicorn statue as a marker for her grave.",
	]));
	set_exits(([
	"west" : ROOMS+"pal8",
	"south" : ROOMS+"pal14",
	]));
	set_door("wolf door",ROOMS+"pal14","south",0);
}
