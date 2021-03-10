#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("soft boots");
    set_id(({"soft boots","boots","boots of soft leather"}));
    set_short("%^RESET%^%^ORANGE%^boots of soft leather%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^These soft leather boots are made "+
       "to rise to the knee.  They feature suede laces that can "+
       "cinch the boots as tight as the wearer desires.  Made with "+
       "soft soles, they are fantastic for walking around on city "+
       "streets in style and comfort, but they will not offer "+
       "much protection in battle.%^RESET%^");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(5);
}
