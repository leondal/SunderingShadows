#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("The Second Floor Landing");
  set_long("%^RESET%^%^CYAN%^This landing has a door to your east, and another to your west. They doors are open, and lead into bedrooms. There is also a %^BOLD%^painting%^RESET%^%^CYAN%^ here.%^RESET%^\n");
  set_smell("default", "There is a powerful scent of incense here.");
  set_listen("default", "You can hear chanting.");
  set_listen("chanting", "As you listen closly to the chanting it appears to be coming from the bedroom to the west.");
  set_items( ([
     "painting" : "This painting looks out of place here. It is a painting of a unicorn."
]) );
  set_exits( ([
     "down" : "/d/koenig/town/house5",
     "east" : "/d/koenig/town/house9",
     "west" : "/d/koenig/town/house10",
     "enter" : "/d/koenig/town/unicorn.c"
]) );
  set_invis_exits( ({"enter"}) );
  set_pre_exit_functions( ({"enter"}),({"go_enter"}) );
}
int go_enter() {
  if(!present("life angel key", TP)) {
  write("You do not hold the key for entrance here!");
  say(TPQCN+" tries to enter the painting but fails and remains in place.");
  return 0;
}
  say(TPQCN+" %^CYAN%^peers disbelievingly at the painting then disappears before your eyes!");
  write("%^BOLD%^%^CYAN%^The angel key in your hand grows warm, and you feel yourself fade and become solid again. You realize that you have now become part of the painting!");
set_items( ([
   "painting" : "This painting looks out of place here. It is a painting of a unicorn and it appears to be healing "+ this_player()->query_cap_name() +"!"
]) );
return 1;
}
