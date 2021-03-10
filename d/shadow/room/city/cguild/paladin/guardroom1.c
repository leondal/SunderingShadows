#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
//    set_property("no teleport", 1);
    set_short("%^CYAN%^Guardian's chamber%^RESET%^");
    set_long(
      "You are in a dark chamber somewhere in shadow.  You arrived here when you tried to drink the sacred water of the pool of the Paladins, and the statues sent you elsewhere!  Upwards you can see a way out...  it looks like it's covered in water.  To the north a shimmering portal is blocked by two gigantic stone statues."
    );
    set_items( ([
      "statues" : "As you examine them, they start to move!",
      "statue" : "As you look at it, you can see it starting to move!",
      "portal" : "It looks like a pool of water on its side.",
      "water" : "you can see through what looks like water up through the Paladin's fountain!",
    ]) );
    set_exits( ([
      "portal" : "/d/shadow/room/city/cguild/paladin/sanctum",
      "up" : "/d/shadow/room/city/cguild/paladin/fountain",
    ]) );
    set_listen("default", "You can hear rock grinding on rock in the direction of the statues.");
    set_pre_exit_functions( ({"portal"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
    if(!TP->is_class("paladin") && !wizardp(TP)) {
      tell_object(TP, "You suddenly feel weak and woozy as the statues "
         "disapprove of your passing.");
      TP->use_stamina(150);
    }
    return 1;
}
