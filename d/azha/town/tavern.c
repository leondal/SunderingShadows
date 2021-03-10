// Azha Tavern (The Celestial Emperor)
// Thorn@ShadowGate
// 970309
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "The Celestial Emperor Tavern, Azha");
  set("long",
@AZHA
%^BOLD%^The Celestial Emperor Tavern%^RESET%^
  Named for the ancient ruler of the Tsarvani Empire, The
Celestial Emperor Tavern is one of the busiest places in Azha. 
While the merchants do their work within the walls of the
market, the teamsters and laborers rest here and revel in the
social life of the town.
  Gambling is usually not tolerated in the Empire, but for this
frontier post, it has been overlooked by the authorities, who
disdainfully understand the needs of their cruder neighbors to
the north.
%^RED%^There is a sign which appears to have the menu.%^RESET%^
AZHA
);
  set_smell("default","You smell the odor of spirits and dirty men.");
  set_items(
    (["tavern" : "The Celestial Emperor Tavern",
      "sign" : "The menu is posted there.",
      "menu" : "Maybe you should read the sign to see the menu."]));
  set_exits(
        (["west" : "/d/azha/town/center2"]) );
}

init() 
{
  ::init();
  add_action("read", "read");
}

reset() 
{
        ::reset();
        AOVER->setup_monsters(TO, "public");
        AOVER->always_add_monster(TO, AMONDIR+"alradin",1);
        AOVER->always_add_monster(TO, AMONDIR+"tetra",1);

}

int read(string str) {
  object ob;
  int i;
  ob = present("barkeep");
  if(!ob) {
    write("You cannot read the sign, as it is splattered with blood.");
    return 1;
  }
  write(
@BAR
The following great drinks are served here at the The Celestial Emperor Tavern.
%^BOLD%^  The Celestial Emperor Tavern%^RESET%^
%^YELLOW%^------------------------------------------------------------%^RESET%^
BAR
  );
  write("Shatterstar\t\t\t"+ (int)ob->get_price("shatterstar") + "gold");
  write("Flamestrike\t\t\t"+(int)ob->get_price("flamestrike")+" gold");
  write("Purple Stuff\t\t\t"+(int)ob->get_price("purple stuff")+" gold");
  write("Water\t\t\t"+ (int)ob->get_price("water")+" gold");
  write(
  "%^YELLOW%^-----------------------------------------------------------%^RESET%^"
  );
  write("<buy drink_name> gets you the drink.");
  return 1;
}
