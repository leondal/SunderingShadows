#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Town of Sanctuary");
    set_long("%^BOLD%^%^CYAN%^
This is the main street through the town of %^GREEN%^Sanctuary%^CYAN%^. Buildings
seem to line the street to the west.  To the east, is the evil looking
forest that surrounds the city of %^GREEN%^Sanctuary%^CYAN%^.  Westward is the more
residence side of the city.  But you would never know that, because
of how bare the streets are except for the few strange people walking
around, majority of those strangers are most likely drunk.
    ");
    set_exits(([
        "exit" : "/d/dragon/mts/forest01",
       "west" : "/d/dragon/town/roadE3"
    ] ));
    set_items(([
       "cart" : "You know from rummors that Ezekiel wants to leave the town\n"+
                 "but cannot afford to buy horses from the local traders to \n"+
                 "pull the cart that sits in the front yard.\n"
    ] ));
    set_pre_exit_functions(({"exit"}),({"GoThroughDoor"}));
}

void reset() {
  ::reset();
  if(!present("sfighter")) {
    new("/d/dragon/mon/guard")->move(this_object());
  }
  if(!present("smage")) {
    new("/d/dragon/mon/mage")->move(this_object());
    new("/d/dragon/mon/mage")->move(this_object());
  }
}

int GoThroughDoor() {
  write("The Gates leading outside of Sanctury are closed.");
  return 0;
}
