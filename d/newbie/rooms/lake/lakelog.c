#include <std.h>
#include "../../newbie.h"
inherit WATER;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

void create(){
  ::create();
  set_property("light",1);
  set_terrain(DEEP_WATER);
  set_travel(FRESH_BLAZE);

  set_name("Cor'Alu Lake");
  set_short("%^BOLD%^%^BLACK%^Inside of an Old Log%^RESET%^");
  set_long("%^BOLD%^%^BLUE%^You swim inside the hollowed out shell "+
"of an old sunken tree and are immediately aware that this must be "+
"the lair of some large, sentient creature.  Bits of old %^BLACK%^"+
"junk %^BLUE%^are hung about the hollow, %^CYAN%^g%^BOLD%^l%^RESET%^"+
"%^BLUE%^i%^BOLD%^n%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^i%^RESET%^"+
"%^CYAN%^n%^BLUE%^g %^BOLD%^%^BLUE%^in whatever light manages to "+
"make its way down here.  There is even a pile of %^RESET%^"+
"%^ORANGE%^twigs %^BOLD%^%^BLUE%^and %^BLACK%^mud %^BLUE%^that "+
"looks like it is meant to be a throne, complete with two tiny "+
"%^RESET%^fish skulls %^BOLD%^%^BLUE%^on either makeshift "+
"armrest.  Covering the bottom of the log is a thick bed of "+
"%^RESET%^%^CYAN%^algae %^BOLD%^%^BLUE%^that makes a mangy looking "+
"carpet leading up to this underwater throne.%^RESET%^");


  set_smell("default","\nThe water tastes crisp with a little "+
"earthy undertone.");
  set_listen("default","You hear water moving about you as you "+
"swim along.");

  set_items(([
    ({"junk","old junk"}):"%^BOLD%^%^BLACK%^Cast off bits of "+
"junk and useless garbage have been collected here and set about "+
"like precious treasures.  Most of them have reflective surfaces "+
"that glint in whatever available light can be found.  Amongst "+
"the trash you see an old boot, a tarnished belt buckle and a "+
"broken sword hilt.%^RESET%^",
    ({"buckle","belt buckle"}):"%^ORANGE%^There's not much left "+
"of this copper belt buckle.  A few tattered scraps of leather "+
"still cling to its loops, but the water has damaged it to the "+
"point of uselessness.%^RESET%^",
    ({"boot","old boot"}):"%^BOLD%^%^BLACK%^It appears to be a "+
"very old boot with a hole in the toe.  You wonder why anyone "+
"would want to keep such a piece of trash.%^RESET%^",
    ({"sword hilt","broken hilt","hilt"}):"%^BOLD%^%^WHITE%^"+
"Maybe the most valuable bit of trash collected.  The hilt might "+
"once have belonged to a fine sword, but the blade was long "+
"ago snapped off, leaving only the hilt and its small, cracked "+
"tiger-eye jeweled pommel.%^RESET%^",
    ({"twigs","mud","throne"}):"%^RESET%^%^ORANGE%^A pile of old "+
"twigs, logs, mud and bones has been shaped up into a rough "+
"representation of a human throne.  The major difference, besides "+
"the shoddiness of the craftsmanship, is that the seat is very "+
"wide and accommodating.%^RESET%^",
    ({"fish skulls","skulls"}):"%^BOLD%^%^WHITE%^A pair of fish "+
"skull have been arranged on the end of each armrest.  They look "+
"a bit hapazardly placed and only one faces straight on.  "+
"Combined with the other shoddy work of the stick throne, this "+
"seems a parody on a human king's throne room.%^RESET%^",
    ({"carpet","algae"}):"%^CYAN%^Stretching across the bottom "+
"of the old log is a carpet of slippery algae.  Uneven and "+
"rather patchy, the dark brown and green of the water-mold "+
"looks to be somewhat tended to keep it from growing up the "+
"walls.%^RESET%^"
  ]));

  set_exits(([
    "out":"lake9"
  ]));
}

void reset() {
  ::reset();
  if(!present("bufo")) new("/d/newbie/rooms/lake/bufo.c")->move(TO);
}

