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
set("short", "The Wrath of Grapes Inn");
    set("long",
@MELNMARN
%^MAGENTA%^Welcome to The Grapes of Wrath Inn.  The place is very noisy, crowded to the eaves with elves of every shape and size.  Music, laughter and loud voices reach you before you have a chance to look around.  Large sconces with candles light the bar, which is about thirty feet long and formed from the floor up to about four and a half feet high.  A large rotund elf rushes back and forth filling food and drink orders.  You read the list before ordering and try to find an empty chair and table.
This is a favourite stopping place for all in Elvanta.
Sometimes it gets pretty noisy, so you'll have to speak up.
MELNMARN
);
set_smell("default", "\nYou can smell pipe smoke, food, wine and other drinks mingling in the air.");
set_listen("default", "Music, singing and laughter fills the air, the music old, the singing intriguing and the laughter catching.");
set_exits (([
"south" : "/d/dagger/Elvanta/forest/room37",
"west" : "/d/dagger/Elvanta/forest/Inn2",
"east" : "/d/dagger/Elvanta/forest/Inn3",
"up" : "/d/dagger/Elvanta/forest/Inn4",
"down" : "/d/dagger/Elvanta/forest/Inn5"
]));
set_items
(([
"tables" : "Over twenty tables fill this room, each is polished to a gleam each day, but still look old, due to spilled wine, beer, and food.  Pipe burns cover each table as well, give the tables character.",
"counter" : "The counter is thirty feet long and wiped constantly bye the owner.  Large platters of food and drink rest upon it.  Several stains made by elf and age cover the counter as well.  It rises from the floor to stand about four and a half feet, and no carpentry marks mar it.",
"list" : "It looks like a list of drinks.  Read it to see what is available.",
"sconces" : "Wall sconces of beaten metal are placed every eight to ten feet around the room.  They hold large candles made of beeswax to light the inn on a dark night."
]));
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
if(!present("berton"))
new("/d/dagger/Elvanta/forest/mon/berton")->move(this_object());
if(!present("elf"));
new("/d/dagger/Elvanta/forest/mon/elf")->move(TO);
if(!present("dwarf"));
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(TO);
if(!present("human"))
new("/d/dagger/Elvanta/forest/mon/human")->move(TO);
if(!present("archer"));
new("/d/dagger/Elvanta/forest/mon/archer")->move(TO);
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

ob = present("berton");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
message("Ninfo", "This is a list of the drinks sold\n",this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(melnmarn);
    }
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n", this_player());

    return 1;
}
