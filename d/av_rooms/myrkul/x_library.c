// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_library");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^YELLOW%^Library%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This vaulted chamber is dimly lit by hanging %^YELLOW%^magical orbs%^BLACK%^ that cast a glow over thousands and thousands of books. The books fill curving shelves that are arranged i"
	"n circles like a %^RESET%^%^MAGENTA%^w%^BOLD%^e%^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^. All paths lead to the center of the web of books where the %^WHITE%^desk%^BLACK%^ of the chief librarian can be f"
	"ound directing all research in the House.%^RESET%^ "
	);

    set_smell("default","
%^BOLD%^%^GREEN%^You smell the %^MAGENTA%^must%^GREEN%^ of dust and ancient tomes.");
    set_listen("default","The library is quiet but for the sound of footsteps in the book stacks.");

    set_search("tools","Hammer, tongs, chisels... what you need, they got.");
    set_search("symbols","The symbols are arcane in nature perhaps indicating a magical alarm.");
    set_search("glyphs","These ancient symbols are inscrutable, but you can see some symbols for -fire- and -air- and -protection- that sort of makes things clear.");
    set_search("vortex","Good thing it only sucks in smoke into that orb...");
    set_search("wards","These ancient symbols are inscrutable, but you can see some symbols for -fire- and -air- and -protection- that sort of makes things clear.");
    set_search("sigils","These ancient symbols are inscrutable, but you can see some symbols for -fire- and -air- and -protection- that sort of makes things clear.");
    set_search("books","You search the books and find many ancient tomes on poison and Lloth.");
    set_search("ore","Hot damn, these Drow are rich!! This ore is mithril, and there are barrels of it!");
    set_search("shelves","You search the books and find many ancient tomes on poison and Lloth.");
    set_search("orb","Would the drow be crazy enough to put a sphere of annihiliation in their house? Or maybe its just a case of drow humor. In any event touching it would be an extremely bad idea.");
    
set_items(([ 
	({ "symbols", "glyphs", "wards" }) : "The symbols, glyphs, and wards are glowing and moving about the ceiling. Its somewhat distracting but with time the novelty wears off.",
	"floor" : "The floor is solid rock and not much to look at.",
	"bookshelves" : "The bookshelves are loaded with books, both new and ancient. The section on poisons is vast.",
	"tools" : "These are implements of the smithy used to forge anything of metal.",
	"vortex" : "The smoke is sucked up in a funnel into an orb where it disappears.",
	"table" : "The table is clear and quite clean.",
	"books" : "The books are written in all languages but the really old ones seem to be written in some ancient form of elven -- or drow?",
	"ore" : "The ore looks like silver, steel, and darksteel.",
	"orb" : "The orb at the apex of the room is totally black and about two feet in diameter. All of the soot that touches it disappears.",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/myrkul/x_nhall",
	]));

}