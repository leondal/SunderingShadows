//bard_grumbar.c - Bard of grumbar reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("grumbar instrument");
    set_id(({"drum","earthen drum","instrument"}));
    set_obvious_short("An earthen drum");
    set_short("%^RESET%^%^ORANGE%^Drum of the Steady Earth%^RESET%^");
    set_long(
@CIRCE
%^RESET%^%^ORANGE%^This large drum has been carved and colored to look like a rock taken straight from the surface of the earth.  Were it not for the shape, which is a perfect cylinder, it might easily be mistaken for one.  It seems even to have lines of dirt and aged cracks that suggest the endless weathering the earth endures and remains strong.  The drumhead itself is a deep brown color and is tied with criscrossed cords fashioned from twine that has a natural look.  The drum seems to produce a steady, constant beat no matter what tempo the musician has in mind.  Burned around the edge of the drumhead is a message in blocky letters.
CIRCE
    );
    set_read("%^ORANGE%^May this drum provide a steady beat for all that you do. "+
       "You may use the drum to "+
       "%^GREEN%^<%^ORANGE%^calm%^GREEN%^> %^ORANGE%^those who are too excitable or "+
       "%^GREEN%^<%^ORANGE%^play%^GREEN%^> %^ORANGE%^to create a "+
       "light to brighten the darkest places of the earth so you may admire its beauty "+
       "and constancy.");
    set_weight(8);
    set_value(0);
    set_lore("This drum produces only one note, and it seems to do so "+
       "in only one rhythm.  The steady, unerring beat echoes the vibrations "+
       "of the earth, filling the minstrel and those around him with the "+
       "strength of dirt and rock.  This particular drum is rumored to have "+
       "been found deep within the heart of the earth by a gnomish follower "+
       "of the Earthlord who was ever burrowing deeper to find the secrets "+
       "hidden therein.  Willoughby Stonedweller was his name, and he was "+
       "the most steadfast gnome to ever live.  He had an insatiable curiosity "+
       "about rock and earth, and he spent his entire life without seeing "+
       "the sun.  As a reward for his efforts, the Earthlord granted him this "+
       "unique drum, so that he might hear its steady beat and never feel alone.");
    set_property("lore difficulty",12);
}
