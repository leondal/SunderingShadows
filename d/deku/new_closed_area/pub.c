#include <std.h>
inherit "/std/room";
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Sleeping Snake tavern");
    set("long",
@GRAY
        %^YELLOW%^Welcome to the Sleeping Snake tavern.%^RESET%^
This timber and stone structure is laid out like any typical
small tavern.  In normal times, the tavern serves as a gathering
place for the townsfolk after the day's chores.  Many residents
and adventurers come here for a relaxing bite to eat.  If the 
bartender is around, he will gladly fill your order.
%^RED%^There is a sign which appears to have the menu.
GRAY
);
    set_smell("default","You smell the odor of erotic alcohol.");
    set_items(
        (["tavern" : "The Sleeping Snake tavern",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should read the sign to see the menu."]));
    set_exits(
              (["south" : "/d/deku/new/town3"]) );
}
void reset() {
  ::reset();
  if(!present("barkeep")) {
    new("/d/deku/monster/thond")->move(this_object());
  }
  if(!present("drunk")) {
      new("/d/deku/monster/drunk")->move(this_object());
    }
}
int read(string str) {
    object ob;
    int i;
    ob = present("barkeep");
    if(!ob) {
        write("You cannot read the sign, as it is splattered with blood.");
        return 1;
    }
     write("The following drinks are served here at the Sleeping Snake Tavern.");
write("-------------------------------------------------------------------");
    write("House wine\t\t\t"+ (int)ob->get_price("wine") + " gold");
    write("Home_brewed beer\t\t"+(int)ob->get_price("home")+" gold");
    write("Bottle of beer\t\t\t"+(int)ob->get_price("beer")+" gold");
    write("Imported ale\t\t\t"+ (int)ob->get_price("ale")+" gold");
    write("Water\t\t\t\t"+ (int)ob->get_price("water")+" gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}
