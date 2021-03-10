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
	" that stretches back to the east. To the north and south are doors"+
	" leading to the guest rooms. On the walls are portraits of some of the"+
	" ancient royalty of Antioch. The portrait on the south wall is of a"+
	" young blonde princess. The north wall has a picture of a red-headed"+
	" king. On either side of the portraits are crystal lamps that shed"+
	" light on the hallway."
	);
	set_smell("default","The soothing scent of vanilla floats in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to east"+
	" It is finely woven and quite thick and sturdy. %^RED%^Crimson%^RESET%^"+
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
	({"north door","fox door"}) : "The door to the north is identical to the one on the"+
	" south except that it has the image of a fox carved into the center of"+
	" it. It is made of cedar wood and leads to a guest room.",
	({"south door","hawk door"}) : "The door to the south is identical to the one on the"+
	" north except that it has the image of a hawk carved into the center of"+
	" it. It is made of cedar wood and leads to a guest room.",
	({"south painting","south portrait","princess","young princess","blonde princess","young blonde princess","princess painting","princess portrait","portrait 1","south wall"}) : "%^BOLD%^The"+
	" painting on the south wall is set in a lovely ivory frame. It is a"+
	" portrait of an ancient princess in Antioch's royal family. There is a"+
	" name on the bottom of the painting, it says Princess Alyssia. Luxurious %^YELLOW%^golden%^WHITE%^"+
	" hair spills over her shoulders, her eyes are the color of %^BLUE%^sapphires%^WHITE%^"+
	" and her lips are a perfect %^RED%^ruby red,%^WHITE%^ curved into a"+
	" half-smile. This is the same girl that was on one of the tapestries"+
	" downstairs. It is rumored that she was accepted among the bird maidens"+
	" and left to join their cause. She would often return to the palace"+
	" for visits, but her home was among the bird maidens in the sky.",
	({"north painting","north portrait","portrait 2","red-headed king","king portrait","king","north wall","king painting"}) : "%^YELLOW%^Hung on the north wall"+
	" is an exquisite portrait with a golden frame. Written on the frame are"+
	" the words: King Fabian. He is a tall fellow with a strong jaw line"+
   " and %^RED%^fiery red%^YELLOW%^ hair. His eyes are a gentle %^GREEN%^hazel%^YELLOW%^"+
	" and he wears a golden crown on his head. He was said to have led"+
	" Antioch's army in the Ogre-wars, hundreds of years ago. He died during"+
	" the final battle, but the War was won thanks to him.",
	]));
	set_exits(([
	"north" : ROOMS+"pal12",
	"east" : ROOMS+"pal8",
	"south" : ROOMS+"pal13",
	]));
	set_door("fox door",ROOMS+"pal12","north",0);
	set_door("hawk door",ROOMS+"pal13","south",0);
}
