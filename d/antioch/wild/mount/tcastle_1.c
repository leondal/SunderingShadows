//Updated with Etarena's Desc - Cythera 7/06
#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create()
{
    ::create();
    set_light(2);
    set_indoors(1);
    set_smell("default", "%^RESET%^%^RED%^The %^BOLD%^%^WHITE%^l%^RESET%^i%^BOLD%^%^BLACK%^g%^BOLD%^%^WHITE%^h%^RESET%^t%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^ flicker unsteadily around you.%^RESET%^");
    set_listen("default", "%^RESET%^%^MAGENTA%^The roar of the %^BOLD%^%^BLUE%^w%^RESET%^%^BLUE%^i%^CYAN%^n%^BOLD%^%^CYAN%^d%^RESET%^%^MAGENTA%^ outside is quieted by a low, constant %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^m%^RESET%^b%^BOLD%^%^RED%^l%^RESET%^%^RED%^e%^RESET%^%^MAGENTA%^ coming from deeper in the temple.%^RESET%^");
    set_short("Temple of Talos");
    set_long("%^BOLD%^%^BLACK%^Eerie %^BOLD%^%^WHITE%^f%^RESET%^l%^BOLD%^%^BLACK%^i%^WHITE%^c%^RESET%^k%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^i%^BOLD%^n%^RESET%^g %^BOLD%^%^BLACK%^lights bring illumination to this otherwise dark and vast space. A large statue of the %^YELLOW%^L%^RESET%^%^ORANGE%^o%^RESET%^r%^BOLD%^%^BLACK%^d %^YELLOW%^o%^RESET%^%^ORANGE%^f %^RESET%^D%^BOLD%^%^BLACK%^e%^YELLOW%^s%^RESET%^%^ORANGE%^t%^RESET%^r%^BOLD%^%^BLACK%^u%^YELLOW%^c%^RESET%^%^ORANGE%^t%^RESET%^i%^BOLD%^%^BLACK%^o%^YELLOW%^n%^BOLD%^%^BLACK%^ dominates the center of the room, sitting atop a raised, marble platform. From this centralized point, %^RESET%^wh%^BOLD%^%^BLACK%^i%^RESET%^te li%^BOLD%^%^BLACK%^g%^RESET%^ht%^BOLD%^%^BLACK%^ cuts through jagged cracks in the floor, creeping toward the corners of this massive space. The back wall is shrouded by ominous black smoke which eternally rages in tumultuous rolls behind a large glass panel. Chaotic, %^RESET%^f%^BOLD%^l%^BOLD%^%^BLACK%^a%^RESET%^s%^BOLD%^h%^BOLD%^%^BLACK%^i%^WHITE%^n%^RESET%^g%^BOLD%^%^BLACK%^ orbs of light hidden deep within the thick fog create the illusion of lightning streaking through heavy storm clouds. Three colored windows in the shape of lightning bolts dominate both the eastern and western walls, stretching from the furthest corners of the floor to a central point high above in the shadowy confines of the ceiling. Dusky light spills onto the room, highlighting the carved, jagged stone walls into which the windows are embedded. Large %^YELLOW%^f%^RESET%^%^ORANGE%^l%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^e%^YELLOW%^s%^BOLD%^%^BLACK%^ from golden torches which line the walls summon to life frenzied shadows that scatter into every crevice, and wafts of smoke curl reverently toward the high ceiling to mingle with wisps of scented incense.%^RESET%^\n");
    set_exits(([
                   "out" : MOUNT + "pass_10",
                   "roof" : MOUNT + "tcastle_roof",
                   ]));
    set_items(([
                   "wall" : "%^BOLD%^%^BLACK%^Not unlike the inside of a cave, the walls of the temple " +
                   "appear jagged and sharp as if they were torn apart by natural forces rather than" +
                   " built with careful hands. The strange lighting of the room catches the awkward " +
                   "angles and forces %^BOLD%^%^WHITE%^s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^" +
                   "%^WHITE%^o%^BOLD%^%^BLACK%^w%^RESET%^s%^BOLD%^%^BLACK%^ to crawl into each tiny " +
                   "crevice. %^RESET%^",
                   "torches" : "%^RESET%^Lining the walls in distant intervals, the ornate golden torches" +
                   " are massive and allow for the %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^" +
                   "e%^BOLD%^%^RED%^r%^RESET%^%^RED%^y%^RESET%^ light to spread throughout the room." +
                   " The %^YELLOW%^f%^RESET%^%^ORANGE%^l%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^" +
                   "e%^YELLOW%^s%^RESET%^ reach toward the ceiling in %^BOLD%^%^WHITE%^sp%^RESET%^ir" +
                   "%^BOLD%^%^BLACK%^a%^RESET%^li%^BOLD%^%^WHITE%^ng%^RESET%^ tendrils, leaving off " +
                   "wafts of %^BOLD%^%^BLACK%^thick smoke%^RESET%^ which gather high above your head " +
                   "in %^BOLD%^%^BLACK%^heavy clouds%^RESET%^. The torches seem to burn eternally, " +
                   "never dimming or losing their flame.%^RESET%^",
                   "windows" : "%^BOLD%^%^BLACK%^The jagged %^YELLOW%^l%^RESET%^%^ORANGE%^i%^RESET%^g" +
                   "%^BOLD%^%^BLACK%^h%^YELLOW%^t%^RESET%^%^ORANGE%^n%^RESET%^i%^BOLD%^%^BLACK%^n" +
                   "%^YELLOW%^g%^BOLD%^%^BLACK%^ b%^RESET%^o%^YELLOW%^l%^RESET%^%^ORANGE%^t%^RESET%^" +
                   "s%^BOLD%^%^BLACK%^ streak from the ceiling to the floor allowing minimal light" +
                   " into the room. The furthest window is stained a d%^RESET%^%^RED%^a" +
                   "%^BOLD%^%^BLACK%^rk s%^BOLD%^%^RED%^h%^BOLD%^%^BLACK%^ade of %^RESET%^%^RED%^" +
                   "r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^, the middle a de%^BOLD%^" +
                   "%^BLUE%^e%^BOLD%^%^BLACK%^p %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^lu%^BOLD%^%^BLUE%^" +
                   "e%^BOLD%^%^BLACK%^, and the last a dim %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r" +
                   "%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^n%^BOLD%^%^BLACK%^. The " +
                   "massive lengths of the windows are fortified with crisscrossing %^RESET%^ir" +
                   "%^BOLD%^%^BLACK%^o%^RESET%^n %^BOLD%^%^BLACK%^bars.%^RESET%^",
                   ({ "panel", "back wall", "orbs" }) : "%^BOLD%^%^BLACK%^Heavy %^RESET%^clouds%^BOLD%^%^BLACK%^" +
                   " of black smoke eternally waft behind the glass divider, making the wall appear " +
                   "nearly solid upon first glance. Randomly placed orbs of light %^BOLD%^%^WHITE%^" +
                   "f%^RESET%^l%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^c%^RESET%^k%^BOLD%^%^BLACK%^e%^RESET%^" +
                   "r%^BOLD%^%^BLACK%^ chaotically from deep within the haze to appear as %^YELLOW%^l" +
                   "%^RESET%^%^ORANGE%^i%^RESET%^g%^BOLD%^%^BLACK%^h%^YELLOW%^t%^RESET%^%^ORANGE%^n%^RESET%^i" +
                   "%^BOLD%^%^BLACK%^n%^YELLOW%^g%^BOLD%^%^BLACK%^ raging through storm clouds.%^RESET%^",
                   ({ "statue", "platform" }) : "%^BOLD%^%^WHITE%^Carved from white marble, the statue makes" +
                   " a striking contrast against the otherwise %^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^r" +
                   "%^BLACK%^k s%^RESET%^t%^BOLD%^o%^BLACK%^n%^RESET%^e%^BOLD%^%^WHITE%^ from which " +
                   "the temple is built. The broad-shouldered man stands tall, with chiseled, strong " +
                   "features. His face is bearded and he possesses a single good eye, the other hidden" +
                   " beneath an eye patch. He is garbed in a half-suit of field plate armor and his " +
                   "hands are concealed within gloves. The surrounding %^RESET%^f%^BOLD%^l%^BOLD%^%^BLACK%^" +
                   "i%^RESET%^c%^BOLD%^k%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^i%^BOLD%^%^BLACK%^n%^RESET%^g" +
                   "%^BOLD%^%^WHITE%^ lights contort and twist around the statue in wavering, %^BOLD%^%^BLACK%^" +
                   "sh%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^wy%^BOLD%^%^WHITE%^ chaos. The " +
                   "statue sits upon a %^BOLD%^%^BLACK%^black m%^RESET%^a%^BOLD%^%^BLACK%^rb%^RESET%^l" +
                   "%^BOLD%^%^BLACK%^e platform%^BOLD%^%^WHITE%^, its surface jutting out in uneven, sharp" +
                   " peaks as if ravaged by an earthquake or some other force of nature.%^RESET%^",
                   ({ "floor", "cracks", "light" }) : "%^RESET%^From beneath the temple floor, %^BOLD%^white " +
                   "light%^RESET%^ pours through hairline cracks cut into the black marble. The dim light" +
                   " does little to brighten the %^BOLD%^%^BLACK%^glo%^RESET%^o%^BOLD%^%^BLACK%^my%^RESET%^" +
                   " atmosphere and instead lends it an eerie feeling. The cracks create instability beneath" +
                   " your feet, forcing you to step with care as you walk.%^RESET%^",
               ]));
}
