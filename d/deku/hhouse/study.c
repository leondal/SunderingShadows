#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"living_1i";
int found;

void create() {
    ::create();
    set_long(
@KAYLA
This room was once a writing room or study.  Against the wall under
the windows is a large wooden writing desk partially broken and
riddled with damp rot.  There are three drawers in each pedestal and
a large center drawer.  The center drawer is closed but the others are
open, two obviously broken open forcibly.
KAYLA
    );
    set_exits(([  "south" : HH_ROOMS+"hall1i"  ] ));
    set_items(([
       ({"drawer", "drawers", "center drawer" }): "The center drawer is the only "
          "one that doesn't seem broken.  Perhaps you can open it."
    ] ));
    hauntings();
}

void init() {
  ::init();
  add_action("open","open");
}

int open(string str) {
  if(!str) {
    write("Open what?");
    return 1;
  }
  if(present("skeleton") || present("ghost")) {
    write("The creatures seem to be guarding the desk.");
    return 1;
  }
  if(found) {
    write("You open the drawer and find it looks like someone has removed "
       "something from it recently.");
    return 1;
  }
  if(str == "drawer" || "center drawer") {
    write("You force the center drawer open and find some odd looking papers.");
    tell_room(ETO,TPQCN+" opens the center drawer and finds some papers.",TP);
    switch(random(3)) {
      case 0: new("/d/tharis/obj/voucher.c")->move(TO);
      case 1: new("/d/tharis/obj/voucher.c")->move(TO);
      case 2: new("/d/tharis/obj/voucher.c")->move(TO);
    }
  	 found = 1;
    return 1;
  }
}

void reset() {
  ::reset();
  if(!random(2))  found = 0;
}
