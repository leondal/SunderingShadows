#include <std.h>
#include "../../newbie.h"
inherit ARMOUR;

#define DESIGNS ({"%^BOLD%^%^BLACK%^spider%^RESET%^",\
"%^YELLOW%^lion%^RESET%^",\
"%^RESET%^%^ORANGE%^bear%^RESET%^",\
"%^RESET%^%^BLUE%^wolf%^RESET%^",\
"%^RESET%^%^CYAN%^hawk%^RESET%^",\
"%^BOLD%^%^BLUE%^falcon%^RESET%^",\
"%^RESET%^%^RED%^wolverine%^RESET%^",\
"%^RESET%^%^ORANGE%^squirrel%^RESET%^",\
"%^RESET%^%^ORANGE%^chipmunk%^RESET%^",\
"%^YELLOW%^cougar%^RESET%^",\
"%^BOLD%^%^BLACK%^lynx%^RESET%^",\
"%^BOLD%^%^BLACK%^panther%^RESET%^",\
"%^BOLD%^%^RED%^bobcat%^RESET%^",\
"%^BOLD%^%^WHITE%^bald eagle%^RESET%^",\
"%^BOLD%^%^MAGENTA%^sunpeacock%^RESET%^",\
"%^BOLD%^%^MAGENTA%^gloomwing moth%^RESET%^",\
"%^RESET%^%^RED%^tressym%^RESET%^",\
"%^BOLD%^%^WHITE%^drake%^RESET%^",\
"%^BOLD%^%^CYAN%^dolphin%^RESET%^",\
"%^BOLD%^%^BLACK%^skunk%^RESET%^",\
"%^RESET%^%^MAGENTA%^faerie dragon%^RESET%^",\
"%^BOLD%^%^GREEN%^deer%^RESET%^",\
"%^RESET%^%^BLUE%^vulture%^RESET%^",\
"%^BOLD%^%^BLACK%^raven%^RESET%^"})

int i, j, val;
string DESIGN;

void create_pendant()
{
   j = random(sizeof(DESIGNS));
   DESIGN = DESIGNS[j];
   val = random(5)+5;
   set_value(val+1);
   set_cointype("silver");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_name("quartz pendant");
   set_id(({"pendant","quartz pendant","smokey quartz pendant",""+DESIGN+" pendant"}));
   set_short("%^BOLD%^%^BLACK%^smokey quartz pendant%^RESET%^");
   set_long("The pendant is strung on a gray silk cord with a"+
   " silver loop. The smokey quartz is only slightly cut, with the"+
   " bottom end being left naturally jagged. In the very center of"+
   " the crystal there appears to be the shadowy image of a "+DESIGN+""+
   " trapped within it.");
}


void create()
{
   ::create();
   create_pendant();
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
