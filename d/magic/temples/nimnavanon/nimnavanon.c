#include <std.h>
inherit "/std/temple";

void create()
{
    string season, col;
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_light(2);
    set_indoors(0);
    set_temple("nimnavanon");
    set_name("Temple of Nimnavanon");
    set_short("%^BOLD%^%^GREEN%^Temple of Nim'navanon%^RESET%^");

    season = season(time());

    switch (season) {
    case "spring":
        col = "%^GREEN%^";
        break;
    case "winter":
        col = "%^WHITE%^";
        break;
    case "autumn":
        col = "%^ORANGE%^";
        break;
    default:
        col = "%^GREEN%^";
        break;
    }

    set_long("%^BOLD%^" + col + "The Temple of Nim'navanon%^RESET%^\n%^RESET%^" + col + "You have entered a large clearing deep in the heart of the forest, where a single ancient %^RESET%^%^ORANGE%^oak tree %^RESET%^" + col + "rises to incredible heights at its heart, its gnarled limbs clawing eternally skyward. %^BOLD%^%^CYAN%^L%^RESET%^%^CYAN%^ig%^BOLD%^%^CYAN%^ht %^RESET%^" + col + "dapples the clearing, cast between its leaves as they wave overhead in the breeze. At the base of the tree stands a rough-hewn altar, a single piece of jade with %^RESET%^%^ORANGE%^du%^RED%^l%^ORANGE%^l %^RESET%^" + col + "and rugged sides. Its surface has been polished smooth, displaying the letters of Nim'navanon's charge in g%^YELLOW%^l%^RESET%^" + col + "ow%^YELLOW%^i%^RESET%^" + col + "ng amber against the %^RESET%^%^GREEN%^%^BOLD%^rich mossy hue %^RESET%^" + col + "of the stone. Around the oak, much of the rest of this area looks to be new growth, with %^RESET%^%^GREEN%^%^BOLD%^young grass %^RESET%^" + col + "underfoot that is relatively clear of brush and leaves. A circle of new %^BOLD%^%^GREEN%^sa%^YELLOW%^p%^BOLD%^%^GREEN%^lings %^RESET%^" + col + "questing upwards from the soil at the clearing's edges, beneath the eaves of the older trees that lie beyond. Occasionally, a hint of company is suggested by the %^RESET%^%^MAGENTA%^rustling %^RESET%^" + col + "of undergrowth within their depths, a t%^BOLD%^%^CYAN%^r%^RESET%^" + col + "ill of birdsong, or a distant %^RESET%^%^BLUE%^howl %^RESET%^" + col + "carried upon the wind. \n%^RESET%^");


    set_smell("default", "The air is filled with the smell of the forest that surrounds you.");
    set_listen("default", "The wind rustles gently through the trees.");
    set_exits(([
                   "out" : "/d/tharis/conforest/rooms/path26",
                   "south":"/d/magic/temples/nimnavanon/pond",
                   "east":"/d/magic/temples/nimnavanon/mound"
                   ]));
}

void init()
{
    ::init();
    add_action("read_charge", "read");
}

int read_charge(string str)
{
    if (!str || str != "charge") {
        return __Read_me(str);
    }
    write(
        "%^BOLD%^Nim'navanon charges his followers with this message:%^RESET%^%^CYAN%^
Strive to live in harmony with the wilds, for we are each part of the eternal cycle.  Seek to perceive the greater balance in all things, and do not fear the forces of nature, for where destruction, decay and death clear a passage, life springs forth anew.  Intervene where you must, whether it be to cull or to plant anew.  Work actively against those who would disturb the natural order, and teach the ways of the wilderness to any who will listen.  Though civilisations may rise and fall, in the end nature will always reclaim its own.

%^BOLD%^Nim'navanon has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^Seija
%^CYAN%^Enemies: %^RESET%^Nilith, Khyron");
    return 1;
}
