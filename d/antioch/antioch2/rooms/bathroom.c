#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("The wash room of the %^BOLD%^White Dragon Inn");
    set_long(
        "The Wash Room\n" +
        "%^WHITE%^This is a rather lavish wash room. There is a %^CYAN%^ba%^BOLD%^%^CYAN%^t%^CYAN%^h%^RESET%^%^WHITE%^ tub nestled into the far left corner of the room. It seems that the %^CYAN%^pipes%^WHITE%^ have been magically enchanted to bring up heated water from the kitchen to fill the tub with. There is a little %^BOLD%^%^CYAN%^s%^CYAN%^i%^RESET%^%^CYAN%^nk%^WHITE%^ on the right side of the room with a spigot pump to get cold water from the well for washing your face and hands with. Fluffy towels are stacked in one corner of the room for the guests and there are several washclothes. %^CYAN%^Shelv%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s%^WHITE%^ line the back wall and they are full of fine %^CYAN%^so%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^ps%^WHITE%^ and %^MAGENTA%^oil%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ of all sorts. A thick cream %^BOLD%^%^BLACK%^rug%^RESET%^%^WHITE%^ has been placed here, stretching from one end of the room to the other. The rest of the %^BOLD%^%^CYAN%^f%^RESET%^%^CYAN%^loor%^WHITE%^ is covered in some sort of tiling so that the wooden floors don't erode due to the water. There is no window in this room, so nobody can see in. In the far back right corner of the room is a little %^BOLD%^%^BLACK%^latrine%^RESET%^%^CYAN%^.%^WHITE%^ It also appears to be the more expensive magical kind, whisking away everything to a different spot for dumping, a small but permanent gate spell. In the center of the room hangs a little %^CYAN%^ston%^BOLD%^%^CYAN%^e%^RESET%^%^WHITE%^ that has been enchanted with a permanent light spell to bring light to the room. This really is a nice inn.
"
        );
    set_smell("default", "The scents of different soaps and oils fill" +
              " the room.");
    set_listen("default", "You can hear a faint clatter of dishes" +
               " from down below.");
    set_items(([
                   "floor" : "The floor is covered in some sort of tile and a large" +
                   " cream rug is laid over it, reaching from the door to the back" +
                   " of the wall by the tub.",
                   "rug" : "%^YELLOW%^This cream rug is rather narrow, it is laid" +
                   " down to cover the floor between the sink and the bath tub. It" +
                   " will keep your feet from getting cold on the tile while you dry" +
                   " off.",
                   ({ "tile", "tiles" }) : "%^BOLD%^Tile covers the bathroom floor, probably to" +
                   " keep the water off of the wood. It is mostly white with a few" +
                   " blue stripes and checkers on each large tile.",
                   ({ "shelf", "shelves" }) : "Wooden shelves line the back wall of the" +
                   " room and they are filled with fine soaps and oils for washing.",
                   "sink" : "The little porcelain sink is tucked into the right hand" +
                   " corner of the room. It has a spigot type pump and you can use" +
                   " it to fill the sink with water for washing. There is a handle" +
                   " release to allow the sink to drain out through the pipes.",
                   ({ "bathtub", "bath tub", "tub" }) : "The tub is placed in the back" +
                   " left corner of the room, and takes up about half the wall. It" +
                   " is very large and luxurious, with a pillow on the top for you" +
                   " to rest your head against. There is a soap tray on the side of" +
                   " it and plenty of room to place oils and perfumes. It appears to" +
                   " be kept quite clean. The water drains out at the bottom if you" +
                   " remove the plug. To fill it with water you'd have to tell the" +
                   " kitchen staff that you wanted to take a bath and then they" +
                   " would start heating water in the kitchen. Once the water was" +
                   " ready there is a handle that you can turn that would magically" +
                   " bring the water up to the tub, filling it. There is also a" +
                   " handle for cold water so that you can mix the two, it probably" +
                   " taps into a well somewhere nearby.",
                   "pillow" : "There is a little satin pillow at the back of the" +
                   " bath tub for you to lean your head back against as you soak.",
                   ({ "soap", "soaps" }) : "There are many fine soaps on the back shelves." +
                   " Some are in cute shapes such as a flower or a star. They are" +
                   " in all different colors and they smell wonderful.",
                   ({ "oil", "oils" }) : "Bottles of expensive looking oils line the" +
                   " back shelves. You can add them to your bath tub so that you" +
                   " smell good and it also makes your skin softer.",
                   "latrine" : "This is one of the new magical latrines with a small" +
                   " permanent gate spell, taking the waste to a designated area" +
                   " for elimination. It is quite convenient.",
                   ({ "pipe", "pipes" }) : "Pipes lead from the sink down outside. One" +
                   " is from the well and pumps water up into the sink, the other" +
                   " carries it away.",
                   ({ "handle", "handles" }) : "There are two handles at the bath tub" +
                   " that you can turn. One is %^BOLD%^%^RED%^red%^RESET%^ for hot" +
                   " water and the other %^BOLD%^%^BLUE%^blue%^RESET%^ for cold" +
                   " water.",
                   ({ "stone", "light", "enchanted stone" }) : "%^BOLD%^A stone that has been" +
                   " enchanted with a continuous light spell hangs down from the" +
                   " ceiling. It is perfectly round and glows white.",
               ]));
    set_exits(([
                   "west" : ROOMS + "inn5",
               ]));
    set_door("door", ROOMS + "inn5", "west", 0);
}
