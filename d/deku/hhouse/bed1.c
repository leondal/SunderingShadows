#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"bed2i";

int searched;
int open;

void create() {
   ::create();
   set_long(
@KAYLA
What was once a fine master bedroom now stands dirty and decayed.
Some of the floorboards are missing and there is rubbish scattered
around.  A four-poster bed, once a grand piece of furniture, is 
against the south wall.  A tall wooden cupboard stands against the
wall opposite the empty fireplace.
KAYLA
    );
    set_exits(([ "north" : HH_ROOMS+"hall7" ] ));
    set_items(([
      "bed":"Once a grand piece of furniture but now the wood has rotted away.",
      "cupboard": (: TO, "cupboard" :)
    ] ));
    hauntings();
}

void reset() {
  ::reset();
  searched = 0;
  open = 0;
}

void init() {
  ::init();
  add_action("search","search");
  add_action("open_it","open");
}

int search (string str) {
  if(!str) {
    write("Search what?");
    return 1;
  }
  if(present("skeleton") || present("ghost") || present("shadow")) {
    write("The creatures stand in your way!");
    return 1;
  }
  if(str != "cupboard") {
    write("You search the "+str+" and find nothing.");
    return 1;
  }
  if(!open) {
    write("You can't search effectively when it's still closed!");
    return 1;
  }
  if(searched) {
    write("A false back has been opened and apparently recently searched.");
    return 1;
  }
  write("%^BOLD%^You search the cupboard and find a false back with something "
    "someone has hidden there!\n");
  searched = 1;
  if(!present("shadow")) {
    write("The false back opens into the wall and %^BOLD%^%^BLACK%^shadows "
       "%^RESET%^emerge from the opening!");
    say(TPQCN+" awakens a couple of %^BOLD%^%^BLACK%^shadows%^RESET%^.");
    new("/d/deku/monster/shadow")->move(TO);
    new("/d/deku/monster/shadow")->move(TO);
  }
  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"rand");
  new("/d/tharis/obj/voucher.c")->move(TO);
  return 1;
}

int open_it (string str) {
  if(!str) {
    write("Open what?");
    return 1;
  }
  if(str != "cupboard") {
    write("You can't seem to open the "+str+".");
    return 1;
  }
  if(open) {
    write("It's already open.");
    return 1;
  }
  if(present("skeleton") || present("ghost") || present("shadow")) {
    write("The undead aren't going to let you open the cupboard!");
    return 1;
  }
  write("The doors creak loudly as you swing them open.");
  tell_room(ETO,"The cupboard doors creak loudly as "+TPQCN+" opens them.",TP);
  open = 1;
  return 1;
}

string cupboard(string str) {
   if(!open) 
   return("The cupboard doors are closed so you can't tell what might "
         "be in there.");
   else return("The doors are open so it's likely someone already searched it.");
}
