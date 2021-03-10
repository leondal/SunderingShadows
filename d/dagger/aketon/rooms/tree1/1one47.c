#include "/d/dagger/aketon/short.h"

inherit BANK;

void create() {
   ::create();
   set_property("light",2);
   set_short("Bank of Shadow, Aketon Branch");
   set_long("%^BOLD%^Welcome to the Aketon Branch of the Banks of Shadow%^RESET%^
This is one of many banks connected to the network. As you look around the "
      "room, you notice there is a counter on the far wall, with a teller "
      "behind it. He looks bored. The rest of the bank is busy with "
      "customers.\nA sign by the teller details all commands.");
   set_items( (["bank":"You are in its huge lobby. There is a counter in "
      "front of you and and exit behind you.",
      "customers":"They are wandering about aimlessly.",
      "sign":"Reading it will give you a list of commands.",
      "teller":"The teller looks at you impatiently.",
      "counter":"A teller waits behind it for you to do something.",
      "exit":"It leads out into the street through heart of Aketon."]) );
   set_smell("default","The smell of money fills your nostrils.");
   set_listen("default","The sounds of rustling coins fill your ears.");
   set_exits( (["north":RPATH1+"1one39"]) );
}
