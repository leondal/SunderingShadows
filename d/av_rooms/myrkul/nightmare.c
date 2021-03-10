// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("nightmare");
    set_property("indoors",2);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("meadows");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Inside a N%^RED%^i%^BLACK%^ght%^RED%^m%^BLACK%^are%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^You feel yourself suspended over an %^BOLD%^%^BLACK%^infinite void%^RESET%^%^MAGENTA%^ into which you %^GREEN%^feel%^MAGENTA%^ that there is no return. A sense of %^BOLD%^%^CYAN%^w"
	"ailing %^RED%^c%^YELLOW%^h%^WHITE%^a%^MAGENTA%^o%^RED%^s%^RESET%^%^MAGENTA%^ from below fills you with a %^BOLD%^%^BLACK%^dread%^RESET%^%^MAGENTA%^ which can only be experienced in %^GREEN%^dream%^MAG"
	"ENTA%^. Surrounding you is a cylindrical nothingness full of a gray light that seems to dance around you in a featureless blur. The only solid objects appear in front of you -- %^RESET%^%^ORANGE%^a ri"
	"ckety desk%^RESET%^%^MAGENTA%^ and a %^RESET%^%^ORANGE%^chair%^MAGENTA%^.%^RESET%^"
	);

    set_smell("default","
You smell nothing, taste nothing. Everything is eerily empty.");
    set_listen("default","The only sounds breaking the silence are those which you make yourself.");

    set_search("chair","The chair is plain old rickety wood. Nothing surprising or interesting.");
    set_search("desk","%^BOLD%^%^WHITE%^The desk has a stack of cryptic papers beside which is a quill pen and ink. The papers have writing on them, but it seems to have the blurred emptiness of this place on them. You read them but gain no understanding of the words or meaning.%^RESET%^");
    
set_items(([ 
	"void" : "%^BOLD%^%^BLACK%^It is a deep pit over which you are floating. You cannot see the bottom or how deep it is. Yet you %^RESET%^%^MAGENTA%^feel%^BOLD%^%^BLACK%^ that there is some %^BOLD%^%^MAGENTA%^madness%^BLACK%^ down there. No light can pierce its darkness, but you just %^BOLD%^%^WHITE%^KNOW%^BLACK%^ that something lurks, waiting, hungrily -- for %^GREEN%^you!%^RESET%^",
	"chair" : "The chair is plain old rickety wood. Nothing surprising or interesting.",
	"desk" : "%^BOLD%^%^WHITE%^The desk has a stack of cryptic papers beside which is a quill pen and ink. The papers have writing on them, but it seems to have the blurred emptiness of this place on them. You read them but gain no understanding of the words or meaning.%^RESET%^",
	]));
}