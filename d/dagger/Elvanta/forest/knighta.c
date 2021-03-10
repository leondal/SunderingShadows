#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "The Knightly Inn");
    set("long",
@MELNMARN
%^BOLD%^The gathering is large and mixed as you discover once your eyes get used to the light.  This comes chiefly from a blazing log-fire, for the three lamps hanging from the beam are dim and half veiled in smoke.  On the benches are various folk, hobbits, dwarves and other vague figures, difficult to make out in the shadows and corners.%^RESET%^
A list of drinks is on the wall.
MELNMARN
);
set_smell("default", "The odour of many bodies, stale beer and smoke fill the room.");
set_listen("default", "Laughter, song and loud voices fill the room.  The word ale is the most prevelant however.");

    set_items(
(["inn" : "The Knightly Inn",
"bar" : "The Knightly Inn",
	  "list" : "It looks like a list of drinks. Read it to see "
	    "what's available."]) );
set_exits(([
"north" : "/d/dagger/Elvanta/forest/knightc",
"up" : "/d/dagger/Elvanta/forest/knighti",
"west" : "/d/dagger/Elvanta/forest/room62"
]));
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
if(!present("gahzee"))
new("/d/dagger/Elvanta/forest/mon/gahzee")->move(this_object());
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

ob = present("diric");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
message("Ninfo", "This is a list of the drinks sold at Diric's Pub.\n", this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(melnmarn);
    }
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n", this_player());

    return 1;
}









