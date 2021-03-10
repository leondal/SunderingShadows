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
    set_property("no castle", 1);
    set("short", "The Brigand's Pub");
    set("long",
        "You are in the Brigand's Pub.\n"
        "The pub can get a bit rowdy at times, but you can still manage "
        "to sit down and have a drink, and maybe even grab some grub.");
    set_items(
        (["pub" : "The most hoppin' place in Outland.",
	  "bar" : "The Brigand's Pub.",
	  "foo" : "bar"]) );
    set_exits( (["south" : "/d/standard/outlands/dust2"]) );
}

void reset() {
  ::reset();
    if(!present("rocko")) 
      new("d/standard/obj/mon/rocko")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("rocko");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    write("The following drinks and food are served at the Brigand's Pub!");
    write("-----------------------------------------------------------");
    write("Whiskey\t\t\t"+ (int)ob->get_price("whiskey")+" gold");
    write("Assassin's ale\t\t"+(int)ob->get_price("ale")+" gold");
    write("Pretzel\t\t\t"+(int)ob->get_price("pretzel")+" gold");
    write("-----------------------------------------------------------");
    write("<buy item_name> gets you an item.");
    return 1;
}

