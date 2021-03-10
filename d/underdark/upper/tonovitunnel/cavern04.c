#include <std.h>
#include "../defs.h"
inherit ROOM;

int issearched;

void create() {
    ::create();
    set_property("indoors",1);  
    set_property("light",0);
    set_travel(FOOT_PATH);
    set_terrain(ROCKY);
    set_name("A dark cavern");    
    set_short("%^RESET%^%^BLUE%^A dark cavern%^RESET%^");
    set_long("%^RESET%^%^BLUE%^A vast natural cavern opens around you.  "
"Formed centuries ago, this cave has likely been sealed away for ages "
"only recently having been breeched by the tunnel system that passes "
"through it.  Giant %^BOLD%^%^BLACK%^stalactites %^RESET%^%^BLUE%^and "
"%^BOLD%^%^BLACK%^stalagmites %^RESET%^%^BLUE%^reach toward each other "
"from floor and ceiling.  Between them, %^CYAN%^lichen%^BLUE%^, "
"%^BOLD%^%^BLACK%^fungi%^RESET%^%^BLUE%^ and %^GREEN%^moss %^BLUE%^grow "
"thickly wherever enough minerals have gathered to support life.  An "
"occasional %^WHITE%^glitter%^BLUE%^, reflected back from your lights, "
"alerts you to the presence of precious metals or gems, but the vastness "
"of the cavern prevents you from exploring them further and the uneven "
"ground demands your attention as you progress.  Unlike the connecting "
"tunnels, no source of light has been placed within this cavernous place, "
"leading you to wonder what might be here to object to the otherwise "
"faint light.%^RESET%^\n");
    set_smell("default","An acidic, coppery smell lingers in the air.");
    set_listen("default","Silence pervades this cavern but for the occasional drop of water falling.");

    set_items(([
      ({"cavern","cave"}) : "%^BOLD%^%^BLACK%^Naturally formed by time "
"and the forces of nature, this vast cavern stretches away into the "
"darkness, well beyond any form of light you've brought with you.  Thick "
"spires of stalactites and stalagmites rise from the floor and ceiling "
"filling all that you can see with their massive forms.%^RESET%^",
      ({"tunnel","tunnels","tunnel system"}) : "%^BOLD%^%^BLACK%^To the "
"north and south of this immense cavern can be seen the entrances and "
"exit of a tunnel system.  The faint light from their passages provides "
"the only source of contrast in this otherwise dark place.%^RESET%^",
      ({"stalactites","stalagmites","rocks","formations","spire","spires"}) : "%^BOLD%^%^BLACK%^Thick spires of stone lift from the floor and jut "
"toward the ceiling, their bases as thick as any tree and their reach "
"toward the ceiling nearly as tall.  Likewise, the matching spires of "
"stalactites loom down from the ceiling like fingers stretching into the "
"darkness ready to grasp intruders within their domain.%^RESET%^",
      ({"lichen","moss","fungi","minerals","mineral","fungus","mushrooms"}) : "%^BOLD%^%^BLACK%^Growing in small clumps amongst the stalagmites are "
"small patches of growing fungi, lichen and moss.  It seems strange that "
"they could grow on the stone until you look a bit closer and realize "
"that there is something buried there.  It almost looks like the remains "
"of a body!%^RESET%^",
      ({"body","bodies","remains"}) : "%^BOLD%^%^BLACK%^Deteriorated "
"beyond recognition, the remains are covered in moss, lichen, fungi and a "
"strange white pasted that looks mineral like.  Maybe if you searched a "
"little more you could discover something about the body.%^RESET%^",
      ({"glitter","metals","metal","gem","gems"}) : "%^BOLD%^%^BLACK%^"
"Every now and again your light or the light from the tunnels catches on "
"something %^RESET%^%^WHITE%^sp%^CYAN%^a%^WHITE%^r%^BOLD%^k%^RESET%^"
"%^WHITE%^l%^CYAN%^i%^WHITE%^ng %^BOLD%^%^BLACK%^out in the darkness.  "
"Too bad the cavern is filled with so many rock formations that make the "
"footing nearly impossible, there could easily be untold riches out there "
"just waiting to be plucked from the stone and carried away by a brave "
"soul.%^RESET%^",
      ({"ground","floor","path"}) : "%^BOLD%^%^BLACK%^Uneven and very "
"dangerous except for a small path carved out between the various jutting "
"stalagmites the ground shows the same tool markings as can be found in "
"some of the tunnel system leading into this cavern.%^RESET%^",
    ]));

    set_exits(([
      "south" : TUNNEL"cavern03",
      "north" : TUNNEL"cavern05",
    ]));
    issearched = 0;
}

void reset() {
    ::reset();
    if(random(3))
      tell_room(TO,"%^BLUE%^A faint gust of air stirs the hair on your head as something passes close by.%^RESET%^");
    if(issearched) issearched = 0;
}
