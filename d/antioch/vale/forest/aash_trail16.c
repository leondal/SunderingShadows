// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("aash_trail16");
    set_property("indoors",0);
    set_property("light",0);
    set_terrain(BRANCHES);
    set_travel(RUTTED_TRACK);
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^I%^BLACK%^n a %^RED%^D%^BLACK%^e%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^p R%^RED%^a%^BLACK%^v%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ne%^RESET%^");

    set_long("%^RESET%^%^RED%^Inside this %^MAGENTA%^deep ravine%^RED%^, nothing %^BOLD%^%^GREEN%^grows%^RESET%^%^RED%^. The husks of %^ORANGE%^once great trees%^RED%^ now stand as %^ORANGE%^petrified remnants%^RED"
	"%^ to a glorious past. Now all thats left are rocks, blasted by %^BOLD%^fire magicks%^RESET%^%^RED%^ so fierce that the %^BOLD%^i%^BLACK%^n%^RED%^f%^YELLOW%^e%^RED%^r%^BLACK%^n%^RED%^o%^RESET%^%^RED%^"
	" turned them into %^BOLD%^%^BLACK%^obsidian sculptures%^RESET%^%^RED%^. At the center of the wreckage is a %^BOLD%^%^WHITE%^staff%^RESET%^%^RED%^ standing upright from the ground, the gleaming %^RESET"
	"%^%^ORANGE%^w%^YELLOW%^o%^RESET%^%^ORANGE%^od%^RED%^ the only semblance of that which once lived. Nearby are three figures of %^CYAN%^elves%^RED%^, all %^BOLD%^%^BLACK%^solid obsidian%^RESET%^%^RED%^,"
	" all posed with %^CYAN%^sword,%^BOLD%^%^GREEN%^ bow%^RESET%^%^RED%^, and %^BOLD%^%^CYAN%^spear%^RESET%^%^RED%^ as if engaged in %^BOLD%^mighty battle%^RESET%^%^RED%^ protecting whatever once held the "
	"staff. Oddly, there is a a pile of rocks and shards of glass heaped together to form a chair, or %^BOLD%^%^BLACK%^t%^RESET%^h%^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^RED%^, which watc"
	"hes over the scene.%^RESET%^ "
	);

    set_smell("default","
You smell rocks, silence, and sorrow.");
    set_listen("default","The silence here is that of a tomb, though it be outdoors.");

    set_search("staff","The staff is stuck solidly to the ground and is warm to the touch. Perhaps an eon or so would have to pass before the magick would wane enough for it to be removed.");
    set_search("elves","These are statues now and all that once was dear is now glass.");
    set_search("trees","These are statues now and all that once was dear is now glass.");
    set_search("sword","These are statues now and all that once was dear is now glass.");
    set_search("needles","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    set_search("path","A search of the path reveals that it seems no one has walked this way in a very long time. Somehow the creatures beyond have not been able to find this place.");
    set_search("animals","There are no animals around.");
    set_search("spear","These are statues now and all that once was dear is now glass.");
    set_search("throne","The throne is made out of a pile of rocks and bits of obsidian from around the ravine.");
    set_search("underbrush","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    set_search("bow","These are statues now and all that once was dear is now glass.");
    
set_items(([ 
	"darkness" : "The light is gritty and its hard to see much of anything.",
	"light" : "The light is gritty and its hard to see much of anything.",
	"branches" : "The branches overhead for an incomplete arch that shields the path from view.",
	"shadows" : "The light is gritty and its hard to see much of anything.",
	"path" : "The path seems to wind between the gaps in the towering trees.",
	"staff" : "The staff seems to be the staff of a magi of unspeakable power, the strength of an aeon past when the powers of creation still roamed unchecked. It is solid wood of an unknown sort, perhaps a variant of walnut. Strange runes and glyphs are carved into the staff, and it glows with its own light. The staff is firmly stuck in the ground as if the striking of the earth were some final stroke to release a spell of a great magis last stand.",
	"elves" : "The elves seem to be once mighty warriors. Its hard to tell much of their features as it is more their silhouette that has been preserved. Nothing remains of their foes. All of their gear and indeed of them is solid glass now.",
	"limbs" : "The branches overhead for an incomplete arch that shields the path from view.",
	"trees" : "The trees seem ancient, almost timeless. They are extremely large and it would take five or six human men to link arms to be able to complete surround one.",
	]));

    set_exits(([ 
		"up" : "/d/antioch/vale/forest/aash_trail7",
	]));

}