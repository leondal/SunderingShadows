#include <std.h>
inherit ROOM;

void create(){
       ::create();
       set_property("indoors",1);
       set_property("light",2);
       set_property("no teleport",1);
       set_terrain(STONE_BUILDING);
       set_travel(PAVED_ROAD);
       set_name("A Dirt Pit");
       set_short("%^ORANGE%^A Dirt Pit%^RESET%^");
       set_long("%^ORANGE%^This is a dirt pit.  It is obvious by the "+
          "lack of decor and the general messiness of the dirt that is present, "+
          "this place is only meant for one person.  Piles of dried out, "+
          "sandy pieces of dung and a damp, still wet area in one corner, "+
          "leads you to believe that area is the bathroom.%^RESET%^");
       set_smell("default","%^MAGENTA%^The air is filled with the smell dirt, urine and feces.%^RESET%^");
       set_listen("default","%^GREEN%^Deafening silence....%^RESET%^");
       set_items(([
          ({"dirt"}) : "%^ORANGE%^Piles and piles of dirt, as far as "+
             "you can see.. or at least till you hit the edges of the "+
             "pit.%^RESET%^",
          ({"dung", "corner" }) : "%^ORANGE%^Firm yet sandy pieces of "+
             "shit and smelly, urine-soaked dirt is what you see here.%^RESET%^",
       ]));
       set_exits(([
          "lounge" : "/d/dagger/avalounge"
       ]));
}
