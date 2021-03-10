//changed to use the common inherit weapons file for easier upkeep with changes
//Styx 7/29/01

#include "/d/dagger/tonovi/town/short.h"

inherit "/d/common/inherit/wpn_storage_full.c";

void create() {
  ::create();
    set_properties( ([
      "light" : 2,
      "indoors" : 1,
      "no teleport" : 1,
    ]) );
    set_short("Weapon storage room");
    set_long("You aren't supposed to be here, so get out and notify a wiz." );
    set_exits( ([ "up" : RPATH "weapon.c" ]) );
}

void reset() {
  ::reset();
}

