#include <std.h>
inherit "/std/room";

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Blacktongue Tavern");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
    set("long",
@GRAY
        %^YELLOW%^Welcome to the Blacktongue Tavern.%^RESET%^
This large stone structure is laid out like any typical tavern.  It
caters to the guards of Keep Blacktongue.  Many guards and adventurers
come here for a relaxing drink.  If the bartender is around, he will
gladly fill your order.  
%^RED%^There is a sign which appears to be the menu.
GRAY
);
    set_smell("default","You smell the odor of exotic alcohol.");
    set_items(
        (["tavern" : "The Keep Blacktongue Tavern",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should read the sign to see the menu."]));
    set_exits( (["south" : "/d/deku/keep/keepW1"]) );
}

void reset() {
  ::reset();
  if(!present("barkeep")) {
    new("/d/deku/keep/monster/indra")->move(TO);
  }
  if(!present("drunk")) {
    new("/d/deku/keep/monster/drunk1")->move(TO);
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
   write("The following alcohols are served here at the Blacktongue Tavern.");
write("-------------------------------------------------------------------");
    write("Burningdeath\t\t\t"+ (int)ob->get_price("burningdeath") + " gold");
    write("Imported wine\t\t\t"+(int)ob->get_price("wine")+" gold");
    write("Bottle of beer\t\t\t"+(int)ob->get_price("beer")+" gold");
    write("Shot of vodka\t\t\t"+ (int)ob->get_price("vodka")+" gold");
    write("Pale ale\t\t\t"+ (int)ob->get_price("ale")+" gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}
