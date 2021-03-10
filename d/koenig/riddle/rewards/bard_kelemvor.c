//bard_kelemvor.c - Bard of kelemvor reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("kelemvor instrument");
    set_id(({"flute","bone flute","flute of bone","instrument"}));
    set_obvious_short("A flute made of bone");
    set_short("%^RESET%^%^WHITE%^Flute of the Requiem's Lament%^RESET%^");
    set_long(
@CIRCE
%^RESET%^This small flute is carved from a bone of some strange creature.  Small holes are drilled into the flute to allow a musician to control the pitch and tone of the sound presented.  A rich %^GREEN%^tapestry%^RESET%^ band is wrapped around the flute, possibly to allow one firmer hand holds.  The tapestry's images is faded, looking like a relic of the past, though there appears to be a message that one can still make out with some effort woven into the fabric.  This flute tends to emit a low sorrow-filled tune, no matter how hard one tries to change the pitch or lighten the sound.
CIRCE
    );
    set_read("%^GREEN%^May this flute guide you to grant eternal rest "+
       "to all those whose time has come.  You may use this flute to "+
       "%^WHITE%^<%^GREEN%^calm%^WHITE%^> %^GREEN%^those wrapped up in anger or "+
       "%^WHITE%^<%^GREEN%^play%^WHITE%^> %^GREEN%^to create a "+
       "guiding light through the darkness.");
    set_weight(8);
    set_value(0);
    set_lore("This flute has been made from the bone of an undead creature "+
       "that was granted rest by Kelemvor himself.  The Lord of the Dead "+
       "took up the bone, hallowed it, and crafted this slender instrument "+
       "from it as a gift to his high priestess, Aria Lanyer.  She treasured "+
       "the flute all through her long life, and she was said to have donated "+
       "it as a gift to the church of Kelemvor at her parting.  Miraculously, "+
       "the flute seems to find its way into the hands of those most worthy and "+
       "most devoted to the cause of the Lord of the Dead.");
    set_property("lore difficulty",12);
}
