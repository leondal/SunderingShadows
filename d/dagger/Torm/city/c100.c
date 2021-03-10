#include <std.h>
#include "../tormdefs.h"
inherit BANK;
void create()
  {
  ::create();
  set_property("indoors",1);
  set_property("light",2);
    set_short("Torm's bank");
  set_long(
  "  This building looks well used and efficient."
  "  The tellers behind their counters deal with the customers and you can see a few very competent guards standing near them."
  "  There is a feeling that a great deal of money passes through hands here, even if only through transfers rather than vast wagonfulls of gold."
  );
  set_exits(([
  "north":TCITY+"c63",
  ]));
}
void reset(){
  ::reset();
  if(!present("teller")) {
     new(MON+"teller")->move(TO);
  }
//  if(!present("bank guard")) {
//     new(MON+"bankguard")->move(TO);
//  }
// This bank guard is fucked up.
// garrett
// (And Cyric.)
// -
}
