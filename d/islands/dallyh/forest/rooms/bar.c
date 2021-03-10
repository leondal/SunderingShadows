#include "/d/islands/dallyh/fways.h"
inherit "/std/room";
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set("short", "The Water hole");
    set("long",
        "This is the place where the Amazons go to get water. There are small cup type things with various drinks in them. There must be something special in the drinks because all the amazons appear to be young beautiful women.  They must have something special to keep their youth.\nA menu hangs on the wall."
);
    set_items(
        (["hole" : "A watering hole.",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should read the sign to see the menu."]));
    set_exits(
              (["west" : FRPATH "road4"]) );
}
void reset() {
  ::reset();
  /*if(!present("barkeep")) {
    new( FMPATH "barkeep")->move(this_object());
  }*/
}
int read(string str) {
    object ob;
    int i;
  ob = present("barkeep");
    if(!ob) {
        write("You cannot read the sign, as it is splattered with blood.");
        return 1;
    }
      write("The following drinks are served here at the Water Hole.");
    write("-----------------------------------------------------------");
    write("Water\t\t\t"+(int)ob->get_price("water")+" gold");
    write("Mysterious Water\t\t\t"+ (int)ob->get_price("mysterious water") + " gold");
    write("Blood\t\t\t"+(int)ob->get_price("blood")+" gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the drink.");
    return 1;
}
