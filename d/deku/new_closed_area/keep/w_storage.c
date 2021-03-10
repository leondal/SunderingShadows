#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set("short", "Keep Blacktongue's Weapon Store Storage");
    set("long", "Only supplies and such here.\n");
    set_exits((["north": "/d/deku/keep/smithy"]));
}

void reset() {

::reset();
if(!present("bastard"))
 new(WEAPONDIR+"bastard")->move(this_object()); 
if(!present("longsword"))
 new(WEAPONDIR+"longsword")->move(this_object()); 
if(!present("shortsword"))
 new(WEAPONDIR+"shortsword")->move(this_object()); 
if(!present("two_hand_sword"))
 new(WEAPONDIR+"two_hand_sword")->move(this_object()); 
}

