#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The large chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. The stone here seems drained and lifeless. "
	"A large %^ORANGE%^throne of leering skulls%^RED%^ is positioned in the "
	"center of the room. On the west wall is a %^CYAN%^mirror%^RED%^. The mirror "
	"has been smashed and shards lay below it leaving just the frame upon the wall. "
	"The opening leading south is covered with hanging %^BLUE%^cobwebs%^RED%^."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Throne Room%^RESET%^");
    set_listen("default",
        "Outside the tower, somewhere in the darkness, an animal howls in agony."
    );
    set_smell("default",
        "A faint smell of oil fills the room."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"candles":"%^GREEN%^A few small black %^CYAN%^candles%^GREEN%^ "
	"lay flickering on the floor creating an array of shadows which dance "
	"wildly upon the walls.%^RESET%^",
	"walls":"Shadows dance upon the walls.",
	"shadows":"The shadows sway in and about...almost as though they were alive.",
	"mirror":"The mirror has been smashed and the broken shards lay below it.",
 	"frame":"The empty brass frame hangs empty on the wall.",
	"shards":"The many shards lay in splinters as though whatever smashed the mirror also "
	"stomped upon the shards to crush them as small as possible.",
	"cobwebs":"The ancient cobwebs cover the opening to the south...whatever spider made "
	"the web has long since passed away.",
	"throne":"%^ORANGE%^The throne in the center of the room is made of leering skulls and would "
	"only be suitable for an utterly evil being or undead king to use.%^RESET%^",
	"skulls":"The skulls are of various animals and humanoids and all have a sadistic grin "
	"etched upon their faces.",
    ]));
    set_exits(([
        "south": RPATH "b4",
        "north": RPATH "b1",
        "southwest": RPATH "b3",
	"southeast": RPATH "b5",

    ]));

    set_pre_exit_functions(({"south"}),({"exita_fun"}));
    set_pre_exit_functions(({"north"}),({"exitb_fun"}));
    set_pre_exit_functions(({"southwest"}),({"exitb_fun"}));
    set_pre_exit_functions(({"southeast"}),({"exitb_fun"}));
}
int exita_fun() {
    if(present("vampyre")) {
        write("The vampyre blocks your way!\n");
        return 0;
    }
    write(
	"%^BLUE%^You brush back the cobwebs and head south.%^RESET%^"
    );
    say(
	"%^BLUE%^"+TPQCN+" brushes back the cobwebs and heads south.%^RESET%^"
    ,TP);
    return 1;
}
int exitb_fun() {
   if(present("vampyre")) {
        write(
	    "%^BOLD%^%^RED%^Vampyre shouts: Run in fear, "+TPQCN+" you maggot child!%^RESET%^"
	    "\n%^RED%^Vampyre swipes you across the back with his claws as you flee!%^RESET%^"
	);
	say(
	    "%^BOLD%^%^RED%^Vampyre tells you: %^RESET%^You would be wise to "
	    "flee as "+TPQCN+" the maggot child just did!"
	,TP);
	TP->do_damage(TP->return_target_limb(),random(40));
        return 1;
    }
    return 1;
}
