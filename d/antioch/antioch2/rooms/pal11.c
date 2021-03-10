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
	set_short("%^BOLD%^The King's Bedroom");
	set_long(
	"This is the royal bed chamber of the King of Antioch. The carpet"+
	" is plush, a %^RED%^deep red%^RESET%^ color and quite thick."+
	" The walls have been painted a pale red color and crystal oil"+
	" lamps are fixed to the walls, shedding light. In the southern"+
	" corner of the room is a large cherry wood closet that contains"+
	" the royal wardrobe of the king. Next to it on the southern"+
	" wall is a matching cherry dresser. On the western wall near"+
	" the dresser is a large mirror that is fixed to the wall. In the"+
	" middle of the eastern wall is the king's royal bed. It is very"+
	" large with a canopy on top and curtains of %^BOLD%^%^RED%^red"+
	" silk%^RESET%^ hanging down, cloaking the bed from view. There"+
	" is a little cherry wood nightstand next to the bed for the king"+
	" to put things on. On the north wall is a large couch, also"+
	" made from cherry wood, with %^RED%^crimson cushions%^RESET%^"+
	" for padding. In the north corner is a chair that matches the"+
	" couch with a small cherry table next to it, probably for a"+
	" scribe to take notes on should his services be required."
	);
	set_smell("default","There is a pleasant smell of roses here.");
	set_listen("default","This room is peacefully silent.");
	set_items(([
	({"carpet","floor","red carpet","deep red carpet","plush carpet","thick carpet"}) : "%^RED%^A very thick carpet covers the"+
	" floor here. It is a deep red color and is made from expensive"+
	" materials. It is soft, allowing one to move quietly across"+
	" the room.",
	({"wall","walls"}) : "The walls have been painted a pale red"+
	" color that goes well with the rest of the room. Crystal oil"+
	" lamps are fixed at intervals to each of the four walls.",
	"ceiling" : "The ceiling is plain and rather unremarkable, it is"+
	" painted the same pale red as the walls.",
	({"lamp","lamps","oil lamps","oil lamp","crystal lamp","crystal lamps","crystal oil lamps","crystal oil lamp"}) : "Crystal oil"+
	" lamps are fixed to each of the four walls. They give off a"+
	" dim light, lighting the room but not making it too bright."+
	" They are tinted a slight %^BOLD%^%^RED%^red%^RESET%^ shade"+
	" and give off a wondeful rose fragrance.",
	({"cherry couch","couch","cherry wood couch","large couch"}) : "Against"+
	" the northern wall is a large cherry wood couch. The back is"+
	" carved in a curving pattern that is quite pretty. It is padded"+
	" with %^RED%^crimson cushions%^RESET%^ for comfort.",
	({"chair","matching chair","cherry wood chair","cherry chair"}) : "In"+
	" the northern corner of the room is a cherry wood chair that"+
	" matches the couch. The back of the chair is carved in the same"+
	" manner as the couch and it has the same %^RED%^crimson cushions%^RED%^"+
	" for padding.",
	({"cushions","crimson cushions"}) : "%^RED%^Crimson cushions"+
	" pad the couch and chairs, making them comfortable.",
	({"small table","table","cherry table","cherry wood table"}) : "Next"+
	" to the chair is a small cherry table. It is rather simple and"+
	" is placed back near the wall. It is probably for a scribe to"+
	" sit at, in case there needs to be a conference in the king's"+
	" bedchambers.",
	({"nightstand","cherry nightstand","cherry wood nightstand"}) : "On"+
	" the left hand side of the king's royal bed is a simple cherry"+
	" nightstand for the king to place things on, like a book or"+
	" glass of water.",
	({"dresser","cherry dresser","cherry wood dresser"}) : "Against"+
	" the southern wall is a long cherry wood dresser. It is carved"+
	" with ornate designs of cherry blossoms and cherry leaves. The"+
	" handles of the drawers are tinted %^YELLOW%^gold%^RESET%^"+
	" creating a nice effect. The dresser itself is about nine feet"+
	" in length and approximately five feet high.",
	({"closet","royal closet","cherry closet","cherry wood closet"}) : "Tucked"+
	" into the far eastern corner of the room is a large cherry"+
	" wood closet that holds the king's royal wardrobe. The closet"+
	" doors have been carefully shut. It looks capable of holding"+
	" quite a large amount of clothing in it.",
	({"mirror","long mirror","large mirror","ebony mirror"}) : "On"+
	" the western wall of the room, near the dresser, is a large"+
	" mirror that has been fixed to the wall. It is spotless,"+
	" perfectly reflecting its surroundings. An ebony frame is carved"+
	" in a flame like pattern around it.",
	({"bed","canopy bed","royal bed","large bed","king's bed"}) : "On"+
	" the eastern wall, sticking out into the room, is the king's"+
	" bed. It is a large canopy bed, with %^BOLD%^%^RED%^red silk"+
	" curtains%^RESET%^ hanging down, creating privacy.",
	({"curstain","curtains","red silk curtains","red curtains","silk curtains"}) : "%^BOLD%^%^RED%^Curtains"+
	" of red silk hang down around the king's bed, creating privacy"+
	" for the king.",
	]));
	set_exits(([
	"west" : ROOMS+"throne",
	]));
	set_door("door",ROOMS+"throne","west","antioch king's key");
	set_string("door","open","The door silently opens, revealing the"+
	" throne room.");
	if(query_night() == 1) {
		set_open("door",0);
		set_locked("door",1);
	}
}

// Removing the NPC from spawning; kids think it's appropriate to waltz in, kill him, and claim to have taken over Antioch.
// Seems an easier solution if they want to play it through that they can avmail and do it appropriately. N, 11/14.
/* void reset()
{
    ::reset();
    if(query_night())
    {
        if(!present("king"))
        {
            new(MONS+"king")->move(TO);
        }
        if(!present("guard"))
        {
            new(MONS+"royal_guard")->move(TO);
            new(MONS+"royal_guard")->move(TO);
        }
    }
    return;
} */
