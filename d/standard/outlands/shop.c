#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The supply shop of Outland");
    set("long",
        "Outlaws from all over Nightmare do their business selling "
        "and buying ill-gotten goods here at the Outland Supply Shop.  "
	"When the shop keeper is in, you can make offers for whatever "
        "she has to sell.");
    set_items(
        (["shop" : "You can buy and sell things here."]) );
    set_exits( (["south" : "/d/standard/outlands/dust1"]) );
}

void reset() {
    ::reset();
      if(!present("bertha")) 
	new("d/standard/obj/mon/bertha")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
        write("The magic of Bertha stops you.");
        say(this_player()->query_cap_name()+" is stopped by the magic of Bertha.", this_player());
        return 1;
    }
    write("You cannot be stopped by Bertha's magic.");
    say(this_player()->query_cap_name()+" cannot be stopper by Bertha's magic.", this_player());
    this_player()->move_player("/d/standard/outlands/storage", "north");
    return 1;
}

