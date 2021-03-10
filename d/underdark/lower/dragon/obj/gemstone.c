#include <std.h>
#include <daemons.h>
inherit OBJECT;

int type,type2;
#define IDZ ({"a raw","a step-cut","a jagged","a rough","a spherical","a faceted","a cabochon-cut","an oval","a square"})
#define TYPES ({"%^RED%^agate","%^MAGENTA%^amethyst","%^CYAN%^aquamarine","%^GREEN%^beryl","%^BOLD%^%^BLACK%^bloodstone","%^RED%^carnelian","%^ORANGE%^citrine","%^BOLD%^%^CYAN%^diamond","%^BOLD%^%^GREEN%^emerald","%^RED%^garnet","%^GREEN%^jade","%^RED%^jasper","%^BOLD%^%^BLUE%^lapis lazuli","%^GREEN%^malachite","%^BOLD%^%^WHITE%^moonstone","%^BOLD%^%^BLACK%^onyx","%^MAGENTA%^opal","%^BOLD%^%^WHITE%^pearl","%^BOLD%^%^GREEN%^peridot","%^BOLD%^%^MAGENTA%^rose quartz","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sapphire","%^BOLD%^%^RED%^spinel","%^YELLOW%^sunstone","%^ORANGE%^topaz","%^CYAN%^turquoise"})

void create(){
   ::create();
   type = random(sizeof(IDZ));
   type2 = random(sizeof(TYPES));
   set_name("gem");
   set_id(({"gem",FILTERS_D->filter_colors(TYPES[type2])}));
   set_short("%^RESET%^"+IDZ[type]+" "+TYPES[type2]+"%^RESET%^");
   set_long("%^RESET%^This "+TYPES[type2]+" %^RESET%^gemstone is of considerable size and quality.  It gleams brightly, catching the light and reflecting it back.  Many people would likely pay good money for a solid gem of this size.");
   set_weight(1);
   set_value(2000+random(800));
}