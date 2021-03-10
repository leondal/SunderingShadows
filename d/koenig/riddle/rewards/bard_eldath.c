//bard_eldath.c - Bard of eldath reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("eldath instrument");
    set_id(({"tambourine","instrument"}));
    set_obvious_short("A tambourine");
    set_short("%^BOLD%^%^BLUE%^Tambourine of Singing Waters%^RESET%^");
    set_long(
@CIRCE
%^BOLD%^%^BLUE%^Soft blue dye has been used to color the willow wood that makes the frame of this tambourine. Across the willow frame a translucent hide has been stretched taut, giving the tambourine a soothing sound when struck.  %^WHITE%^Silver%^BLUE%^ miniature cymbals are stacked against each other and inlaid through out the willow frame.  The cymbals provide a soft low soothing melody that echos off the taut membrane.  The base of this tambourine is set with %^WHITE%^clear quartz%^BLUE%^ gems, to reflect the light softly.  Holding the tambourine up to the light, one can make out a message written into the translucent membrane.
CIRCE
    );
    set_read("%^BOLD%^%^BLUE%^May the sweetness of the water's stillnees "+
       "aid you in your quest for peace.  You may use this tambourine to "+
       "%^CYAN%^<%^BOLD%^%^BLUE%^calm%^CYAN%^> %^BOLD%^%^BLUE%^those who are angry or "+
       "%^CYAN%^<%^BOLD%^%^BLUE%^play%^CYAN%^> %^BOLD%^%^BLUE%^to create a "+
       "mystical light to shine on the world.");
    set_weight(8);
    set_value(0);
    set_lore("Followers of the Green Goddess prize peace and harmony "+
       "above all else.  As such, one would think bards would be common "+
       "among them.  While this was true in centuries past, bards of recent "+
       "times seem much more bent on combat and stories of dramatic battles than "+
       "the simple pastoral melodies that used to please them.  For those rare "+
       "bards who still sing the praises of the peaceful natural world, this "+
       "tambourine is considered a sign of the Green Goddess's favor.  It is said "+
       "to have been originally crafted from the wood of a still-living willow "+
       "growing alongside the river by which the Green Goddess herself lives.");
    set_property("lore difficulty",12);
}
