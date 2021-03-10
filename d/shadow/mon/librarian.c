#include <std.h>
inherit NPC;

void create(){
   ::create();
   set_name("Belaria Sanral");
   set_short("%^RESET%^%^BLUE%^Belaria Sanral, Shadow City librarian");
   set_id(({"Belaria Sanral","Belaria","belaria","librarian"}));
   set_long("Belaria Sanral is the new librarian of the Shadow City library.  "
"She had been an assistant in a nearby library for a few months, then was "
"hired by Shadow upon the untimely demise of Armise.  She is in charge of "
"organizing the scrolls that contain the backgrounds of many adventurers that "
"fill the shelves.  It seems to take an experienced person such as her to "
"help anyone research another.");
   set_race("elf");
   set_gender("female");
   set_class("mage");
   set_level(1);
//   set("aggressive",0);  setting this even to 0 also sets swarm per /std/Object.c so removing it *Styx*  3/16/03
   set_alignment(5);
   set_size(2);
   set_exp(1);
  set_nwp("studying",12);
}
