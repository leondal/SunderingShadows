#include <std.h>;
inherit "/std/room";

void create() {
  ::create();
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
  set_property("indoors", 1);
  set_property("light", 3);
  set_short("An Old Abandoned Warehouse");
  set_long(
"%^BOLD%^This is an old abandoned warehouse.%^RESET%^\n"+
"The dim lighting does this place good, it hides the filth left by its\n"+
"previous owner. There is a crack in the far wall."
          );
  set_items(([
"crack":"It looks almost big enough to go through.",
"filth":"It looks rathy disgusting and nasty."
           ]));
  set_exits(([
      "temple":"/d/magic/temples/mask",
      "crack" : "/d/tharis/Tharis/cguilds/fighter/entrance",
"north":"/d/tharis/Tharis/wstreet6"
           ]));
    set_invis_exits(({"crack"}));
}
