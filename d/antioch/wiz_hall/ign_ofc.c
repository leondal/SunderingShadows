//  Created by Ignatius, for ShadowGate
//  Coded 13 02 95
//  Ignatius Antioch office

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "/std/vault";

void create() {
    object ob;
  ::create();
  set_property("light", 2);
  set_property("no steal", 1);
  set_property("no fight", 1);
  set_property("indoors", 1);
  set_short(
    "Ignatius' Antioch Office"
    );
set_long(
@IGNATIUS


  All that remains here is dust, for Ignatius has left ths realm.  Once 
this place was full of life and energy, but now all that remains is a 
single empty room, testament to Ignatius' vain struggle against what he 
saw as inequality among the wizards.

  Perhaps, for a time, this place will serve as a reminder that all 
good things must come to an end.  Perhaps you will also learn that while 
some fights cannot be won, they must be fought.

  Ignatius would have liked to have seen Antioch open, but that was not 
meant to be.  Perhaps he will return one day.  Perhaps he is here now, in 
some new area.
IGNATIUS
);
  set_exits( ([
    "west": ANTIOCH+"wiz_hall/wizard_rm2"
  ]) );
}
