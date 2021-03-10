#include <std.h>
#include "../defs.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);  
    set_property("light",1);
    set_travel(FOOT_PATH);
    set_terrain(ROCKY);
    set_name("A dusty passage under the earth");    
    set_short("%^ORANGE%^A dusty passage under the earth%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Hard packed earth has been shorn up here "
"by numerous beams of wood.  The thick timber looks in good repair but an "
"occasional shifting of %^BOLD%^%^BLACK%^soil %^RESET%^%^ORANGE%^falls "
"from the ceiling or walls despite the care to keep the space open for "
"passage.  Looking about you can see in a few places where extra wood has "
"been added to protect against collapse.  Hanging for a few of the thick "
"ropes that join the beams together, globes of %^CYAN%^blown glass "
"%^ORANGE%^can be seen.  Within each globe an unearthly light glimmers.  "
"The dusky, pale hue casting the whole of the tunnel into shifting, "
"moving %^BOLD%^%^BLACK%^shadows%^RESET%^%^ORANGE%^.%^RESET%^\n");
    set_smell("default","Dust fills the air, clogging your sense of smell.");
    set_listen("default","The creak and groan of the timbers carries through the dark passage.");

    set_items(([
      ({"earth","stone"}) : "%^RESET%^%^ORANGE%^There is very little "
"stone here as most of the walls are made up of hard packed earth that is "
"secured by thick wooden beams.  What stone you can see appears in slabs "
"and shorn off formations that have been smoothed in order to help form "
"this tunnel.%^RESET%^",
      ({"soil","dirt"}) : "%^RESET%^%^ORANGE%^The occasional shifting of "
"loose soil can be seen falling from the ceiling or floors.  Clogging the "
"air with dust and causing you to wonder if this passage is indeed "
"safe.%^RESET%^",
      ({"beams","wood","timbers","timber","beam"}) : "%^RESET%^%^ORANGE%^"
"Apparently new, the wooden timbers have been carefully arranged to "
"provide structural support to the walls and ceiling of this passage.  "
"Thick bindings of rope attach these timbers to one another in some "
"places while others are held by wooden peg or tongue-n-groove "
"fastening.%^RESET%^",
      ({"walls","ceiling","floor"}) : "%^RESET%^%^ORANGE%^Carved from the "
"hard pack earth of the walls, floor and ceiling have been smoothed by "
"use of some tool or another.  Wooden beams are set ever dozen feet or so "
"with support beams crossing back and forth adding additional support to "
"the earth all around you.%^RESET%^",
      ({"ropes","rope"}) : "%^RESET%^%^ORANGE%^The %^BOLD%^%^BLACK%^"
"ropes%^RESET%^%^ORANGE%^ that have been used to secure some of the "
"wooden beams together appear to be new and are of a thick girth.  "
"Lathered in a %^BOLD%^%^BLACK%^tar like paste %^RESET%^%^ORANGE%^that "
"has formed a glue of sorts, they don't appear to be likely to slip any "
"time soon.  From a few of the ropes, glass globes have been strung, "
"their unearthly light casting %^BOLD%^%^BLACK%^shadows "
"%^RESET%^%^ORANGE%^into the passage way.%^RESET%^",
      ({"globes","globe","light","glass"}) : "%^RESET%^%^MAGENTA%^Glass "
"globes hang from several of the ropes which have been used to secure "
"some of the wooden beams.  Caught within the blown glass are orbs of "
"purple light that glow deeply and cast an unusual pallor over the tunnel "
"you travel within.  Despite their dark glow they provide a little light, "
"maybe enough to see by for those unaccustomed to the brighter light of "
"the surface.%^RESET%^",
      ({"shadow","shadows"}) : "%^BOLD%^%^BLACK%^Shadows dance and "
"flicker against the wall as you pass and disrupt the faint light issuing "
"from the globes of glass.%^RESET%^",
    ]));
    set_exits(([
      "north" : TUNNEL"newtunnel2"
    ]));
}
