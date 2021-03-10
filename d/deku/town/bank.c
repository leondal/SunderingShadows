// Writen by Fire Dragon. (Descriptions by Melnmarn)

#include <std.h>

inherit BANK;

void create() {
  ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(PAVED_ROAD);
  set_short("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^he %^BOLD%^B%^RESET%^%^GREEN%^ank of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^");
  set_long("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^he %^BOLD%^B%^RESET%^%^GREEN%^ank of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^
%^CYAN%^You see that the roof of this modest building seems to have been replaced recently, as evidenced by its weather-worthy appearance. You notice there is a %^BOLD%^counter%^RESET%^%^CYAN%^ integrated into the north wall, with a bank %^BOLD%^teller %^RESET%^%^CYAN%^behind its iron bars. Some %^BOLD%^customers%^RESET%^%^CYAN%^ wander around the hall. A %^BOLD%^sign %^RESET%^%^CYAN%^on the counter details all the %^BOLD%^bank %^RESET%^%^CYAN%^commands%^WHITE%^
  ");
  set_items(	([
     "bank" : "You are in its huge lobby. There is a counter in "
	    "front of you and an exit behind you.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "teller" : "The teller looks at you impatiently.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street."]));
  set_exits(([ "west":"/d/deku/town/road9" ]));
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
}
