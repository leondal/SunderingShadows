// Writen by Fire Dragon. (Disciptions by Melnmarn)

#include <std.h>

#include "/d/ptalkin/ptalkin.h"
inherit BANK;

void create() 
{
  ::create();
set_short("The Elven Bank of Ptalkin");
set_long("%^BOLD%^GREEN%^You have entered the Elven Bank of Ptalkin.  While it appears to be rather small, several efficient looking elves are writing in large books.  The owner of the bank, D'repal walks around checking out everyone and everything.  There is a sign upon the wall which details all the transactions.");
set_property("no attack", 1);
  set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "teller" : "The teller looks at you impatiently.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street."]));
set_exits( ([
"out" : PROOM+"room65.c"
]) );
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
if(!present("d'repal"))
new("/d/ptalkin/mon/d'repal")->move(TO);
}
