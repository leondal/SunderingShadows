#include <std.h>
inherit "/d/deku/plains/plains03i";

int searched;

void create() {
   ::create();
   set_long(TO->query_long()+"Some of the grass to the side of the path has "
     "been trampled down and looks like something may have been sleeping there.");
   set_exits(([
     "east" : "/d/deku/plains/plains19"
   ] ));
   set_items(([
     "grass" : "The grass is in a pile almost like it's been made into a bed.",
     "pile" : "There could easily be more than grass in it.",
   ] ));
}

void reset() {
   ::reset();
   if(!present("leucrotta"))  new("/d/deku/monster/leucrotta")->move(TO);
   searched = 0;
}

void init() {
  ::init();
  add_action("search","search");
}

int search (string str) {
  if(!str) {
    write("Search what?");
    return 1;
  }
  if(present("leucrotta")) {
    write("The leucrotta isn't going to let you search.");
    return 1;
  }
  if(str != "grass" && str != "pile") {
    write("You search the "+str+" and find nothing.");
    return 1;
  }
  if(searched) {
    write("It looks like the pile of grass has been recently disturbed.");
    return 1;
  }
  write("%^GREEN%^You search the pile of grass and find something useful!\n");
  searched = 1;
  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"rand");
  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"coins");
  if(!random(3))  new("/d/tharis/obj/voucher.c")->move(TO);
  return 1;
}

