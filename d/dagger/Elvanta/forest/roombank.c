// Writen by Fire Dragon. (Disciptions by Melnmarn)

#include <std.h>

inherit BANK;

void create() 
{
  ::create();
set_short ("The Elvanta Bank of Commerce");
set_long ("%^BOLD%^Welcome to the Elvanta Bank of Commerce.%^RESET%^\n"
           "This is one of many banks connected to the network. As you "
           "look around the room, you notice there is a counter "
           "on the far wall, with a teller behind it. He looks bored. "
           "The rest of the bank is busy with customers."
           "A sign by the teller details all commands.");
  set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "teller" : "The teller looks at you impatiently.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street."]));
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/room115"
]) );
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
}
