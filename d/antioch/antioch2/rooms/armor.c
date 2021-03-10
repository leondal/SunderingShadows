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
    set_short("The %^BOLD%^Silver%^RESET%^ Gauntlet");
    set_long(
        "%^WHITE%^The %^BOLD%^%^WHITE%^armor%^RESET%^%^WHITE%^ shop is kept nice and tidy. Suits of %^BOLD%^%^WHITE%^armo%^RESET%^%^WHITE%^r%^WHITE%^ are set up on wooden displays around the room so that the customers can get a good view of them before deciding what they wish to purchase. %^ORANGE%^He%^BOLD%^%^ORANGE%^l%^RESET%^%^ORANGE%^m%^BOLD%^%^ORANGE%^s%^RESET%^%^WHITE%^ are placed on the tops of the wooden frames and %^ORANGE%^shie%^BOLD%^%^ORANGE%^l%^RESET%^%^ORANGE%^d%^BOLD%^%^ORANGE%^s%^RESET%^%^WHITE%^ are carefully hung on the walls. Different types of %^ORANGE%^b%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^ots%^WHITE%^ line the bottoms of the walls and a few robes and cloaks are hung on a rack on the side of the room. A cherry %^ORANGE%^desk%^WHITE%^ sits towards the back of the room with a matching cherry wood %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^hair%^WHITE%^ behind it. On top of the desk are several %^BOLD%^%^BLACK%^bott%^WHITE%^l%^WHITE%^e%^BLACK%^s%^RESET%^%^WHITE%^ of polish and a few %^ORANGE%^r%^BOLD%^%^BLACK%^ags%^RESET%^%^WHITE%^ with oil on them, all used to keep the armor nice and clean. The %^ORANGE%^f%^BOLD%^%^BLACK%^l%^BLACK%^o%^RESET%^%^ORANGE%^or%^WHITE%^ looks as though it has been recently swept and a %^ORANGE%^w%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^lcome %^ORANGE%^ma%^BOLD%^%^ORANGE%^t%^RESET%^%^WHITE%^ is laid out at the %^ORANGE%^d%^ORANGE%^o%^ORANGE%^o%^ORANGE%^r%^WHITE%^ for customers to wipe their feet on. There's a %^CYAN%^win%^BOLD%^%^BLUE%^d%^RESET%^%^CYAN%^ow%^WHITE%^ on the eastern wall allowing a cool breeze to drift in.
"
        );
    set_smell("default", "The many oils used to keep the armor in good" +
              " shape permeat the air.");
    if (query_night() == 1) {
        set_listen("default", "The night is quiet.");
    }else {
        set_listen("default", "Shoppers are busy trying to get good" +
                   " deals on various items.");
    }
    set_items(([
                   ({ "door", "cherry door" }) : "The lovely cherry wood door leads" +
                   " north to %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
                   "window" : "A window on the eastern wall allows a cool breeze" +
                   " to drift in and helps carry away the strong smell of the oils.",
                   "floor" : "The hardwood floor looks as though it has been recently" +
                   " swept. A welcome mat is laid out at the entrance way for" +
                   " customers to wipe their feet on.",
                   ({ "mat", "welcome mat" }) : "A brown rug woven out of course" +
                   " material serves as the welcome mat.",
                   "ceiling" : "The ceiling is well constructed and won't be" +
                   " leaking any rain in.",
                   ({ "armor", "armour", "armors", "suits of armor" }) : "Suits of armor" +
                   " are hung on wooden frames, allowing the customers a full view" +
                   " of the armor so they can carefully select which type to purchase." +
                   " There is a wide variety from which to choose, ranging from" +
                   " leather to full plate. On the tops of the frames are various" +
                   " types of helms.",
                   ({ "helm", "helms", "helmets" }) : "Helmets of all sorts rest" +
                   " on the tops of the wooden frames.",
                   ({ "boot", "boots" }) : "All sorts of boots are neatly placed along" +
                   " the edges of the walls.",
                   ({ "shield", "shields" }) : "Shields are carefully hung along the" +
                   " walls of the room. They range from bucklers to full body shields.",
                   ({ "clothing", "cloaks", "robes", "rack" }) : "On the back wall is" +
                   " a rack on which different cloaks and robes are hung.",
                   ({ "desk", "cherry desk" }) : "A large cherry wood desk sits" +
                   " towards the back of the room. Several bottles of polish and" +
                   " a few oily rags are on top of it. Behind it sits a matching" +
                   " cherry wood chair.",
                   ({ "chair", "cherry chair", "cherry wood chair" }) : "The cherry" +
                   " wood chair perfectly matches the desk that is before it. It" +
                   " looks comfortable and is kept well polished, whether on purpose" +
                   " or accident is hard to say.",
                   ({ "rag", "rags" }) : "Several rags that have oil on them sit atop" +
                   " the desk. They're used to keep the armor around you well polished.",
                   ({ "bottles", "polish", "bottles of polish" }) : "A couple different" +
                   " bottles of polish are scattered on top of the desk. Leather" +
                   " and steel need different types of polish to keep them in good" +
                   " shape. This armorer knows his work.",
               ]));
    set_exits(([
                   "north" : ROOMS + "street20",
               ]));
    set_door("cherry door", ROOMS + "street20", "north", 0);
}

void reset()
{
    ::reset();
    if (!present("trendamas")) {
        find_object_or_load(MONS + "trendamas.c")->move(TO);
    }
}
