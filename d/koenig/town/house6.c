#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_door("door", "/d/koenig/town/house5.c", "door", "open_door");
  set_open("door", 0);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Library");
 set_long("%^RESET%^%^CYAN%^You have entered the library. Plan on doing some reading and relaxing adventurer? *smirk* Upon entering the library you notice that %^ORANGE%^shelves%^RESET%^%^CYAN%^ line the walls and contain thousands of %^GREEN%^books%^RESET%^%^CYAN%^. On the far wall is a very large %^BOLD%^painting%^RESET%^%^CYAN%^ framed in by the shelves. The closer you look at the painting the more eerie it appears. It sends shivers down your spine.\n");
  set_smell("default", "You smell the mustiness of books.");
  set_listen("default", "There is nothing but silence here.");
  set_items( ([
     "shelves" : "They are lined with thousands of books. It looks like you could find information on almost anything here.",
     "books" : "There are thousands of titles to see here - all subjects, all types - and almost every language possible.",
     "painting" : "This painting resembles the manlike snake thing carved on the door. He is the only thing residing in the painting."
]) );
  set_exits( ([
     "enter" : "/d/koenig/town/snakeman",
     "door" : "/d/koenig/town/house5"
]) );
  set_invis_exits( ({"enter"}) );
  set_pre_exit_functions( ({"enter"}),({"go_enter"}) );
}
int go_enter() {
tell_room(environment(this_player()), "%^CYAN%^"+ this_player()->query_cap_name() +" looks long and hard at the painting then disappears!");
tell_object(this_player(),"%^BOLD%^%^CYAN%^You look long and hard at the painting, and to your dismay discover that you have become a part of it!");

set_items( ([
   "painting" : "The figure in the painting resembles the manlike snake thing carved on the door. He looks to be fighting "+ this_player()->query_cap_name() +"!"
]) );
return 1;
}
