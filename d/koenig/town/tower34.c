#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
   set_property("no teleport",1);
  set_short("At the Top of the Tower");
  set_long("%^BOLD%^%^WHITE%^I don't really think you mean to be here, but seeing as "
           "how you are, look around. It appears to be a sitting room. The "
           "%^RESET%^%^ORANGE%^furniture%^BOLD%^%^WHITE%^ is oddly shaped and rather large. It is definatly not "
           "designed for a normal man by any means. There are %^RESET%^%^ORANGE%^shelves%^BOLD%^%^WHITE%^ along "
           "one wall containing nothing but %^RESET%^books%^BOLD%^%^WHITE%^, and beneath a small "
           "window you notice a %^CYAN%^chest%^BOLD%^%^WHITE%^.%^RESET%^\n");
  set_smell("default", "It smells of books and something you can't identify.");
  set_listen("default", "It is very quiet in here.");
  set_exits( ([
     "south" : "/d/koenig/town/tower29"
]) );
}

void reset() {
    object ob;
  ::reset();

    if(ob = present("chest"))
      ob->remove();
    new("/d/koenig/town/items/twrchest.c")->move(this_object());

}
