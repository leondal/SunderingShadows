//  /d/dragon/town/bank.c
// Writen by Fire Dragon. (Disciptions by Melnmarn)

#include <std.h>

inherit BANK;

void create() {
  ::create();
   set_short("The Bank of Sanctuary");
  set_long("%^BOLD%^%^BLUE%^
This is the only bank in the town of %^CYAN%^Sanctuary%^BLUE%^.  It is one
of the many banks connected to the network.  You notice that the 
roof of this modest building seems to have been replaced recently,
as evidenced by its weather-worthy appearance.  You notice there 
is a counter on the north wall, with a bank teller behind it.
A sign on the counter details all the bank commands.
  ");
  set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "teller" : "The teller looks at you impatiently.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street."]));
  set_exits(([ "west":"/d/dragon/town/roadSW2" ]));
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sound of rustling coins fills your ears.");
}

string getBankId(){
   return "deku";
}
