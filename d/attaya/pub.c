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
    set("short", "Attaya Tavern");
    set_long("%^ORANGE%^Attaya Tavern%^RESET%^
%^MAGENTA%^Your eyes slowly adjust to the lighting in here. Somewhat surprisingly, this is an operating tavern on this all but deserted island. A long sandstone slab serves as the %^ORANGE%^bar%^MAGENTA%^. It is lined with well crafted oaken stools from the mainland. The walls are %^ORANGE%^decor%^MAGENTA%^ated with parts of old sailing ships. %^WHITE%^Pillars%^MAGENTA%^ carved to resemble mermaids support the ceiling that has been patched with palm fronds.
A %^CYAN%^menu%^MAGENTA%^ hangs on the wall.
");
    set_items(
	(["pillars" : "They have been carved to embody sexy blonde mermaids, their arms raised to support the ceiling beams.",
	  "bar" : "It is a large slab of sandstone that has been polished to be incredibly smooth.",
	  "decor" : "There are old steering wheels, name planks, and various ropes and pulleys.",
	  "menu" : "It looks like a list of drinks.  Read it to see "
	    "what's available."]) );
    set_exits( 
	      (["south" : "/d/attaya/seneca2",
		"east" : "/d/attaya/seneca7"]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
    if(!present("barkeep")) 
new("/d/attaya/mon/barkeep")->move(TO);
}

int read(string str) {
    object ob;
    int i;

    if(str != "menu") return 0;
    ob = present("barkeep");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    message("Ninfo", "The following specials are available today at the Attaya Tavern!\n", this_player());
    message("Ninfo", "%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n", TP);
    message("Ninfo", "A firebreather\t\t\t"+ (int)ob->get_price("firebreather")+" gold\n", this_player());
    message("Ninfo", "A felcold\t\t"+(int)ob->get_price("felcold")+" gold\n", this_player());
    message("Ninfo", "A glistening forcewave\t\t\t"+(int)ob->get_price("forcewave")+" gold\n", this_player());
    message("Ninfo", "A mug of water\t\t\t"+(int)ob->get_price("water")+" gold\n", this_player());
    message("Ninfo", "%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n", TP);
    message("Ninfo", "<buy drink_name> gets you a drink.\n", this_player());
    return 1;
}









