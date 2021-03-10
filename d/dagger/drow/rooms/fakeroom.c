#include <std.h>
inherit "/std/room";

void init() {
    ::init();
    add_action ("touch", "touch");
}
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property ("light",-2);
    set_property ("indoors",1);
    set_property("no teleport",1);
    set_short ("Grazzt's Workroom");
    set_long (
      "%^RED%^%^BOLD%^The large room stuns your senses as you look "
      "about you. A veil of %^YELLOW%^swirling fog%^RED%^%^BOLD%^ "
      "envelops you causing your eyes to play tricks on you. In and "
      "out of the %^YELLOW%^fog%^BOLD%^%^RED%^ shadows and shapes "
      "dance slowly to music whose origin you cannot determine.  "
      "\nA large %^WHITE%^ivory monolith%^BOLD%^%^RED%^ towers "
      "above you in the center of the chamber."
    );
    set_smell ("default","The air reeks of chaotic odors.");
    set_listen ("default","You are overpowered by the hypnotic music.");
    set_items(([
	"fog":"The fog swirls all about you colored in various "
	"shades of %^BLACK%^%^BOLD%^gray%^RESET%^.",
	"shadows":"You are not sure if the shadows are alive, dead, "
	"undead or just your imagination.",
	"monolith":"The monolith stands twenty feet high and is covered "
	"in blazing %^RED%^red runes%^RESET%^.",
	"runes":"The %^RED%^red runes%^RESET%^ are upon closer "
	"inspection actually %^MAGENTA%^glyphs%^RESET%^ of some unknown "
	"type.",
	"glyphs":"You are not sure the meaning of these "
	"%^MAGENTA%^glyphs%^RESET%^, but are quite sure touching the "
	"monolith would be dangerous."
    ]));
    set_exits(([
	"down": "/d/dagger/drow/rooms/tower3",
    "cell": "/d/dagger/drow/rooms/fakecell"
    ]));
}
int touch(string str) {
    if(!str || str !="monolith") {
	notify_fail("Touch what?\n");
	return 0;
    }
    write(
	"%^RED%^You touch the glyphs and are burned by a "
	"%^YELLOW%^bolt of %^RED%^%^BOLD%^flame%^RED%^!%^RESET%^"
    );
    say(
	"%^RED%^"+TPQCN+ " is suddenly burned from a bolt after touching "
	"the %^MAGENTA%^glyps%^RESET%^!"
    ,TP);
    this_player()->add_hp(-10);
    return 1;
}
