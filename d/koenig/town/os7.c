#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors",0);
  set_name("The grounds of the Tower.");
  set_short("The Tower Courtyard");
  set_long("%^RESET%^%^GREEN%^You are wandering around the grounds that surround "+
     "the tower just inside the %^BOLD%^%^BLACK%^wrought iron fencing%^RESET%^%^GREEN%^. In some parts "+
     "the grounds are well cared for, while in others it appears to be "+
     "somewhat neglected. The fence appears to be just as solid here "+
     "as anywhere else, but you can't be completely certain of this "+
     "due to %^BOLD%^bushes%^RESET%^%^GREEN%^ and such having grown over and around sections of it.%^RESET%^\n");
  set_smell("default", "You can smell the sweet fragrance of roses and other things here.");
  set_listen("default", "You can hear a soft keening for help.");
  set_listen("keening","It appears to be coming somewhere from the southeast.");
  set_items( ([
     "fence" : "You feel in your bones there has to be a way through, if you can only find it.",
     "plants" : "You can see roses to the northeast and the southwest, but you also notice some rather large weeds.",
     "bushes" : "Some of these have been trimmmed into the shapes of animals. At least you think its the form of animals."
]) );
  set_exits( ([
     "north" : "/d/koenig/town/os6",
     "south" : "/d/koenig/town/os8"
]) );
}
