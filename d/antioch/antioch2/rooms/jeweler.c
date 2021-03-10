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
    set_short("%^BLUE%^Falling Stars Jewelry%^RESET%^");
    set_long(
        "%^WHITE%^This shop is very tiny but has a pleasant feeling of home. Silver %^CYAN%^wind %^BLUE%^ch%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^mes%^WHITE%^ hang in front of the window on the northern wall and their light melody is soothing. The %^BOLD%^%^BLACK%^roo%^WHITE%^m%^RESET%^%^WHITE%^ is only about ten feet in length, but you can see a door on the side that leads back to the rest of the house. You can smell a freshly baked apple pie that is probably cooling in the back somewhere. The %^ORANGE%^f%^BOLD%^%^BLACK%^l%^BLACK%^o%^RESET%^%^ORANGE%^or%^WHITE%^ is kept very clean and there is a large %^MAGENTA%^ru%^BOLD%^%^MAGENTA%^g%^RESET%^%^WHITE%^ in the center of the room with a pretty woven design on it. Around the edges of the room hang strands of %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^eads, %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^tring%^WHITE%^ and %^ORANGE%^m%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^tal,%^WHITE%^ materials that the %^ORANGE%^j%^BOLD%^%^ORANGE%^ewelry%^RESET%^%^WHITE%^ is made from. There are display %^ORANGE%^c%^BOLD%^%^BLACK%^a%^BLACK%^b%^RESET%^%^ORANGE%^inets%^WHITE%^ on the sides and a large one in the center of the room. The jewelry here ranges from simple strands of beads that little girls would wear to heavy gold chains for brave warriors or delicate bracelets set with precious gems for a lady. A cushioned %^ORANGE%^stoo%^BOLD%^%^BLACK%^l%^RESET%^%^WHITE%^ is positioned in a back corner of the room for the owner to sit and rest. Next to the stool is a small %^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^esk%^WHITE%^ with some broken jewelry on top. Several fine %^BOLD%^%^BLACK%^to%^RESET%^%^WHITE%^o%^WHITE%^l%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ are laid out there, probably used for fixing the jewelry. A couple clean %^WHITE%^cl%^BOLD%^%^WHITE%^o%^WHITE%^t%^RESET%^%^WHITE%^hs%^WHITE%^ are also on top and a %^ORANGE%^bottle%^WHITE%^ of some lemony scented polish that is used for cleaning.
"
        );
    set_smell("default", "The smell of a freshly baked apple pie hangs" +
              " in the air.");
    set_listen("default", "The wind chimes ring together like little" +
               " silver bells.");
    set_items(([
                   "floor" : "The floor is kept very clean and in the center is" +
                   " a rug with a pretty design on it.",
                   "rug" : "The rug appears to be hand woven by some sort of tribe" +
                   " and is done in rich fall colors, reds, oranged, browns, and" +
                   " yellows blend together wonderfully. Geometric patterns line" +
                   " the edges and there is a %^BOLD%^%^RED%^blazing phoenix%^RESET%^ in the center of the" +
                   " rug.",
                   "stool" : "This simple stool is rather short in height and is" +
                   " cushioned for comfort. It is placed in the back of the room" +
                   " near a small desk.",
                   "desk" : "The top of the small desk is covered in felt and" +
                   " broken jewelry is carefully lined out on top of it. Fine silver" +
                   " tools rest to one side, ready to fix the delicate pieces. A" +
                   " bottle of some lemony smelling polish is also there next to" +
                   " several clean cloths, probably for cleaning the jewelry.",
                   ({ "cabinet", "display", "display cabinet", "cabinets" }) : "There are" +
                   " numerous display cabinets dotting the room with the largest" +
                   " one in the center. They are carefully cleaned and the bases" +
                   " are a rich cedar wood with glass sides and tops. The jewelry" +
                   " within each has been carefully selected. One cabinet contains" +
                   " garnet pieces, ranging from rings to bracelets and necklaces." +
                   " Another cabinet consists only of silver jewelry that has been" +
                   " engraved with designs instead of encrusted with gems.",
                   ({ "room", "back room", "door", "back door" }) : "There is a door in" +
                   " the very back of the room that probably leads to the rest of" +
                   " the house but you can't get in there.",
                   "window" : "A square window with white trim is on the northern" +
                   " wall, just in front of it are some wind chimes.",
                   ({ "wind chime", "wind chimes" }) : "Silver wind chimes are hung" +
                   " from the ceiling and hang directly in front of the window." +
                   " They are in the shape of frogs and lilly pads and they sound" +
                   " like little silver bells as they clink together.",
                   "ceiling" : "The ceiling is high and well constructed, on the" +
                   " northern side some wind chimes hang down from it.",
                   ({ "tools", "fine tools", "silver tools" }) : "A set of fine silver" +
                   " tools are on top of the desk in the far back corner, probably" +
                   " used to fix jewelry with.",
                   ({ "bottle", "polish", "bottle of polish" }) : "A bottle of polish" +
                   " sits on top of the desk in the back, giving off a lemony scent.",
                   ({ "cloths", "clean cloths", "white cloths" }) : "Several clean white" +
                   " cloths rest on top of the desk in the back, ready to be used" +
                   " for cleaning.",
                   "felt" : "A piece of felt covers the top of the desk. It keeps" +
                   " the jewelry from rolling off of it or the owner from scratching" +
                   " the desk with the fine tools as she tries to fix the broken" +
                   " pieces of jewelry.",
                   "jewelry" : "Various pieces of jewelry line the store. Hanging" +
                   " up on the sides are the less expensive pieces, beaded necklaces" +
                   " that a young girl might wear and things like that. The more" +
                   " valuable pieces are carefully stored in display cabinets around" +
                   " the store.",
                   ({ "materials", "beads", "strings", "metal" }) : "All sorts of materials" +
                   " are stocked around the store, each used to make or help fix" +
                   " pieces of jewelry. Strands of beads and crystals hang on the" +
                   " walls and thin strips of metal and various types and lengths" +
                   " of string are placed on the edges.",
               ]));
    set_exits(([
                   "east" : ROOMS + "street9",
               ]));
    set_door("door", ROOMS + "street9", "east", 0);
}

void reset()
{
    ::reset();
    if (!present("kedaria")) {
        new(MONS + "kedaria")->move(TO);
    }
}
