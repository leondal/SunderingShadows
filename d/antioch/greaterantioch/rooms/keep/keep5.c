#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit HEALER;

void create()
{
    ::create();
    set_name("keep5");
    set_property("indoors", 1);
    set_property("light", 3);
    set_property("no teleport", 0);

    set_short("%^BOLD%^%^YELLOW%^A Small Shrine%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This beautiful room is obviously a place of worship for those within this keep" +
             " and some of the villages around it. The carpet here is a dull %^RESET%^%^RED%^red %^BOLD%^%^WHITE%^and" +
             " covers the floor evenly. A well-sculpted statue stands in the back, dominating the majority of this room. A" +
             " few sets of %^RESET%^%^ORANGE%^pews %^BOLD%^%^WHITE%^sit in front of a %^BOLD%^%^YELLOW%^statue%^BOLD%^%^WHITE%^.");

    set_smell("default", "\n%^BOLD%^%^MAGENTA%^The smell of incense fills the air.%^RESET%^");
    set_listen("default", "%^BOLD%^%^YELLOW%^You hear the sound of villagers praying here.%^RESET%^");
    set_items(([
                   "pews"    : "%^RESET%^%^YELLOW%^The few pews are positioned to allow for ease of movement in the place of worship.",
                   "statue" : "%^BOLD%^%^CYAN%^This magnificent golden statue is an example of masterwork artistry. It" +
                   " stands roughly four feet tall and is set atop a marble base that measures" +
                   " roughly one foot cubed. Atop the base is a statue of Jarmila, Lady of" +
                   " Light.  She is a tall, lean woman clad in gold-trimmed bluish-white" +
                   " clothing. Hanging from her belt is a morning star, the head of which is" +
                   " made of solid gold. Her fiery red hair is long and flowing." +
                   " Skin the color of light bronze can be seen on her arms and" +
                   " her lovely face. She stands proudly facing the east, holding a" +
                   " bronze-skinned infant in her outstretched arms. A smile of radiance and" +
                   " love is on her face as she gazes at the infant and the east with peaceful" +
                   " blue eyes."]));
    set_exits(([
                   "west" : KEEP "keep3",
                   ]));
    set_name("Brother Torin");
}

void reset()
{
    ::reset();
    if (!present("brother torin")) {
        new(MON + "brothertorin")->move(this_object());
    }
}
