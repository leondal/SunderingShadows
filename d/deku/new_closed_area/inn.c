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
    set("short", "The Maiden's Tears");
    set("long",
@GRAY
        %^YELLOW%^Welcome to the Maiden's Tears tavern.%^RESET%^
This timber and stone structure is laid out like any typical
small tavern.  In normal times, the tavern serves as a gathering
place for the townsfolk after the day's chores.  Many residents
and adventurers come here for a relaxing bite to eat.  If the 
barmaid is around, she will gladly fill your order.
%^RED%^There is a sign which appears to have the menu.
GRAY
);
    set_smell("default","You smell the odor of cooking food.");
    set_items(
        (["tavern" : "The Maiden's Tears tavern",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should read the sign to see the menu."]));
    set_exits(
              (["south" : "/d/deku/new/town2"]) );
}
void reset() {
  ::reset();
  if(!present("waitress")) {
    new("/d/deku/monster/shilarn")->move(this_object());
  }
}
int read(string str) {
    object ob;
    int i;
    ob = present("waitress");
    if(!ob) {
        write("You cannot read the sign, as it is splattered with blood.");
        return 1;
    }
    write("The following great foods are served here at the Maiden's Tears Tavern.");
write("-------------------------------------------------------------------");
    write("Mutton\t\t\t"+ (int)ob->get_price("mutton") + " gold");
    write("Stew\t\t\t"+(int)ob->get_price("stew")+" gold");
    write("Gruel\t\t\t"+(int)ob->get_price("gruel")+" gold");
    write("Hardroll\t\t"+ (int)ob->get_price("hardroll")+" gold");
    write("Water\t\t\t"+ (int)ob->get_price("water")+" gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}
