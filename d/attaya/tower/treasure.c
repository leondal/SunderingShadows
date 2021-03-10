
#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create()
{
    ::create();
    set_name("Treasure vault.");
    set_short("Treasure vault.");
    set_property("indoors", 1);
    set_property("light", 3);
    set_long("%^ORANGE%^T%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^asure %^RESET%^%^ORANGE%^v%^ORANGE%^a%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^t%^RESET%^
%^ORANGE%^This is the treasure vault of the Kinnesaruda Empire. The %^ORANGE%^wa%^WHITE%^l%^WHITE%^l%^WHITE%^s%^ORANGE%^ are sandstone with %^BOLD%^%^MAGENTA%^jew%^GREEN%^e%^MAGENTA%^ls%^RESET%^%^ORANGE%^ and %^BOLD%^%^ORANGE%^gold%^RESET%^%^ORANGE%^ set into them. A brilliant luster shines upon everything. This is a dream unfolded and realized.
%^ORANGE%^A %^WHITE%^mirror%^ORANGE%^ before you fades into a doorway. Beyond it, you can see Ironklaw the healer working dilligently to heal a screaming patient.
");
    set_exits(([
                   "healer" : "/d/attaya/healer"
                   ]));

    set_smell("default", "The air smells of rain and humidity");
    set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna");
    set_items(([
                   "walls" : "They are made from sandstone.  Gold and jewels are built into them.  The walls alone are worth a fortune.",
                   "jewels" : "They are firmly set into the walls.",
                   "gold" : "It is magnificent.",
                   "mirror" : "As the back door vanished, the mirror transformed into a doorway.  If you walk around it, however, it is flat!",
                   "floor" : "The floor is made from gold bricks!",
                   ]));
}

void reset()
{
    int num, i;
    ::reset();

    if (!present("brick")) {
        num = roll_dice(4, 4);
        for (i = 0; i < num; i++) {
            new("/d/attaya/obj/goldbrick")->move(TO);
        }
    }
}
