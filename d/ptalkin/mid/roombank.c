//rooms by the House of Svaha
// Writen by Fire Dragon. (Disciptions by Melnmarn)

#include <std.h>

#include "/d/ptalkin/ptalkin.h"
inherit BANK;

void create() 
{
  ::create();
set_short("%^ORANGE%^F'relks, the moneyman");
set_long(
@DESC
%^ORANGE%^F'relk sits behind a beaten up, rickety, scarred old table.
Chunks appear to have been taken out of it by axes and knives.  The
sylvan elf, F'relk, doesn't seem look much better off than the table.
He has a long, ragged scar that runs from over his left eye down to
the right side of his chin.  He has one rounded ear, compliments of a
dwarfs axe, and is missing several fingers.  As he looks up at you,
you realize missing fingers or not, he would be a welcome ally, or a
vicious foe.  There is a sign hanging from a rusting peg on the wall.
DESC
);
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
"out" : "/d/ptalkin/mid/room80"
]) );
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
if(!present("f'relck"))
new("/d/ptalkin/mon/f'relck")->move(TO);
}
