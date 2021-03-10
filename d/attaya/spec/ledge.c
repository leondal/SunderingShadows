#include <std.h>

inherit "/d/attaya/spec/cliff";

void create()
{
	::create();
	set_name("Ledge on the Obsidian Staircase.");
	set_short("%^RESET%^%^BOLD%^%^BLACK%^Ledge on %^WHITE%^Obsidian %^BLACK%^s%^WHITE%^tair%^BLACK%^c%^BLACK%^a%^WHITE%^se%^RESET%^");
	set_property("indoors",0);
	set_property("light",1);
    set_long("%^RESET%^%^BOLD%^%^BLACK%^Ledge on %^WHITE%^Obsidian %^BLACK%^s%^WHITE%^tair%^BLACK%^c%^BLACK%^a%^WHITE%^se%^RESET%^
%^RESET%^%^BOLD%^%^BLACK%^You are on a ledge on the %^WHITE%^O%^BLACK%^b%^BLACK%^s%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^a%^WHITE%^n %^WHITE%^S%^BLACK%^t%^WHITE%^a%^BLACK%^i%^WHITE%^rca%^BLACK%^s%^WHITE%^e.%^BLACK%^ The ledge is fairly narrow here, and you are at constant risk of falling off. This ledge is enshrouded by thick black smoke, making it impossible to see. You are almost forced to crawl in places to ensure that you can feel where the ledge ends.
");
    set_smell("default", "The air smells of smoke and ash");
    set_listen("default", "The quiet whistle of the wind here is the only sound");
}

void init()
{
    ::init();
    add_action("jump_off", "jump");
}
int jump_off(string str) {
    write("You scream in agony as you jump from the staircase!\n");
    say((string)this_player()->query_cap_name()+" screams in agony as they jump from the staircase!\n");
    this_player()->move_player("/d/attaya/cliffdock.c");
    write("You bounce off the cliff face and slam into the dock!\n");
    say((string)this_player()->query_cap_name()+" Slams into the ground after careening over the cliff face!\n");
    this_player()->do_damage((random(250)));
    return 1;
}
