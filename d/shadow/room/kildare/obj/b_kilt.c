#include <std.h>
#include "../kildare.h"

#define COLORA ({"%^BOLD%^%^RED%^red%^RESET%^","%^RESET%^%^ORANGE%^orange%^RESET%^","%^YELLOW%^gold%^RESET%^"})
#define COLORB ({"%^GREEN%^green%^RESET%^","white","%^MAGENTA%^purple%^RESET%^"})
#define COLORC ({"%^BOLD%^%^BLUE%^blue%^RESET%^","%^BOLD%^%^BLACK%^black%^RESET%^","gray"})

inherit DAEMON;

int i, j, k;
string str, HUE, SHADE;

void create()
{
        ::create();
}

void create_kilt(object obj)
{
   j = random(sizeof(COLORA));
        str = COLORA[j];
   i = random(sizeof(COLORB));
        HUE = COLORB[i];
   k = random(sizeof(COLORC));
        SHADE = COLORC[k];

        obj->set_long("This kilt has been fashioned from high quality "+
         "closely woven wool.  The plaid design has been dyed to use "+
         "shades of "+str+", "+HUE+", and "+SHADE+", distinguishing this "+
         "tartan from those of other clans.  The kilt is designed to "+
         "reach just above the wearer's knees, and the plaid material "+
         "has many pleats.  The kilt may be worn over the right or "+
         "left shoulder, and is belted to keep it in place.");
        obj->set_lore("Worn by the people of Kildare Glen, these kilts "+
         "are considered a mark of the family who wears them.  Each "+
         "family has its own unique pattern.");
        obj->set_property("lore difficulty",3);
        obj->set_value(30);
obj->set_weight(3);
        obj->set_name("kilt");
        obj->set_short("A plaid kilt");
        obj->set_id(({"kilt","plaid kilt","wool kilt"}));
obj->set_limbs(({"waist"}));
obj->set_type("ring");
        obj->set_ac(0);
        obj->set_size(2);
}
