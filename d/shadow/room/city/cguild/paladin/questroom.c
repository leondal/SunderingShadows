#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+
inherit ROOM;
void init() {
    ::init();
    add_action("read_func","read");
}
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
//    set_property("no teleport", 1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The aura of might and power surrounds you."
    );
    set_listen("default","A slight chanting fills your ears.");

    set_items(([
	"chamber":"%^CYAN%^You have entered a chamber within the Paladin Keep "
	"which is used by the Gods of the Paladins to detail quests, deeds "
	"and tasks which they desire Paladins to achieve and "
	"fulfill.%^RESET%^",
	"altar":"%^CYAN%^A large %^WHITE%^stone altar%^CYAN%^ is in "
	"the direct center of "
	"the room. Upon the %^WHITE%^altar%^CYAN%^ lays a "
	"%^MAGENTA%^glowing book%^CYAN%^.%^RESET%^",
        "book":"%^CYAN%^The %^MAGENTA%^glowing book%^CYAN%^ lays open. "
	"Perhaps you should read it.%^RESET%^",
	"stone":"The stone has a large glowing cross stuck into it.",
	"rock":"The rock has a large glowing cross stuck into it.",
	"cross":"%^WHITE%^The cross glows in a holy light and is stuck "
	"into the stone.%^RESET%^"
    ]));
    set_exits(([
        "east": RPATH "sanctum"
    ]));
}
string lng_fun(string str) {
    str =
	"%^CYAN%^You have entered a chamber within the Paladin Keep "
	"which is used by the Gods of the Paladins to detail quests, deeds "
	"and tasks which they desire Paladins to achieve and fulfill. "
	"A large %^WHITE%^stone altar%^CYAN%^ is in the direct center of "
	"the room. Upon the %^WHITE%^altar%^CYAN%^ lays a "
	"%^MAGENTA%^glowing book%^CYAN%^. "
	"The %^MAGENTA%^glowing book%^CYAN%^ lays open. Beside the %^WHITE%^"
	"altar%^CYAN%^ is a large stone with a %^YELLOW%^glowing cross"
	"%^RESET%^%^CYAN%^ stuck into it."
        "%^CYAN%^ ";
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presense of Grazzt."
	       "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    str =
        "%^CYAN%^The Chamber of Questing%^RESET%^";
    return str;
}
int read_func(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "book") {
	notify_fail("Read what?\n");
        return 0;
    }
    if((int)TP->query_level() < 6) {
	notify_fail("You do not understand the writing.");
	return 0;
    }
    write(
        "%^BLUE%^The passage reads:\n"
	"%^YELLOW%^There are three deeds the Gods have requested of all "
	"Paladins throughout the mortal realms. Once these deeds are "
	"completed you will be granted the power to remove the Holy Cross "
	"of Might. These deeds are:\n"
	"%^RESET%^%^CYAN%^        1) Destroy the evil demonic being which "
	"plagues the realms known as\n"
	"           The Krykoth.\n"
	"%^RESET%^%^CYAN%^        2) Prevent the evil Drow from freeing "
	"Lloth from her home plane in\n"
	"           the Abyss through the destruction "
	"of the Nodeus.\n"
	"%^RESET%^%^CYAN%^        3) Travel to the Abyss and defeat the "
	"evil DemonQueen Lloth and\n"
	"           her minions.\n%^RESET%^"
    );
    say(
        "%^CYAN%^"+TPQCN+" reads a passage from the book."
        "%^RESET%^"
    ,TP);
    return 1;
}
