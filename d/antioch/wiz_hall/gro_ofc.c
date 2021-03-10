//  Created by Ignatius, for ShadowGate
//  Coded 28 June, 1995
//  Grolim's Antioch office

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
    "The office of Grolim, Antioch Overseer"
    );
set_long(
@IGNATIUS
  Looking around, you realize that this is a new office.  The walls have 
just been covered in a handsome forest green wallpaper, and the hardwood 
floor seems to be freshly waxed.  Even the furniture is new.  
  The desk that stands before you is quite impressive.  It seems to have 
been hewn whole from a pine tree.  Behind it sits a large leather chair. 
designed to hold its occupant in pure luxury.  A small conference table 
stands perpendicular from the desk.  Large, ornate candelabra ornament the 
table, and the chairs that sit around it are smaller replicas of the beast 
behind the desk.
  A discrete plaque on the wall dedicates this room to Grolim.  The plaque 
seems to have some other writing on it, as well.
IGNATIUS
);
  set_exits( ([
    "workroom": "/realms/grolim/workroom",
    "east": ANTIOCH+"wiz_hall/wizard_rm2"
  ]) );
  set_door("pine door", ANTIOCH+"wiz_hall/wizard_rm2", "east",
           "grolimofficekey");
}
