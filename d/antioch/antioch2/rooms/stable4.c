#include <std.h>
#include "../antioch.h"
//  inherit "/d/antioch/antioch2/animals.c";
inherit ROOM;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("Antioch Stables");
    set_long(
        "%^WHITE%^These %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^alls%^WHITE%^ are where the young colts and fillies are kept. They are looked after a little more than the older horses and some of the older ones have begun to be trained. Instead of %^BOLD%^%^BLACK%^buckets%^RESET%^%^WHITE%^ of grain, some of them have mush in their stalls. A few of the stalls are padded on the sides so the young horses won't hurt themselves. There is more %^ORANGE%^hay%^WHITE%^ on the bottom of the stalls here as well, and also piles of fresh %^ORANGE%^hay%^WHITE%^ in the back of each stall. The stalls are a bit smaller than regular ones, on the back wall is a much larger stall with a mare still nursing her baby in it. You can see a few bits of %^RED%^c%^ORANGE%^a%^RED%^r%^ORANGE%^r%^RED%^ots%^WHITE%^ and %^GREEN%^appl%^RED%^e%^GREEN%^s%^WHITE%^ on the %^BOLD%^%^BLACK%^g%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^oun%^RESET%^%^WHITE%^d%^WHITE%^ in the stalls of the younger ones where the stable hands have given them treats. In the right hand side of the room just in front of one of the stalls is a %^ORANGE%^box%^WHITE%^ of cute little %^CYAN%^kit%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^s.
"
        );
    set_smell("default", "The smell of horses and hay mingles" +
              " together here.");
    set_listen("default", "You can hear little kittens meowing and" +
               " horses whinnying.");
    set_items(([
                   "kittens" : "These cute little kittens are for sale. There are" +
                   " several different types, some black, a few with stripes, at" +
                   " least one is a calico. They are adorable.",
                   ({ "box", "box of kittens" }) : "There is a little wooden box here" +
                   " that is lined with blankets. Several kittens are curled up" +
                   " inside of it, a few of them playing and others sleeping. The" +
                   " box is too high for any of them to jump out of just yet.",
//    " There is a sign next to the box telling what types of kittens there are.",
                   "sign" : "This little sign is resting next to the box of kittens" +
                   " and has been written by a child. It appears none are for sale right now.",
                   ({ "ground", "floor", "dirt" }) : "The floor here is simply dirt so" +
                   " that the horses won't hurt their feet.",
                   "ceiling" : "The ceiling is high with an arched roof. Chains" +
                   " hang down from it that hold light stones.",
                   ({ "light", "stone", "enchanted stone", "light stone", "enchanted stones", "light stones", "stones" }) : "%^BOLD%^Stones that have been enchanted" +
                   " with a continual light spell are hung from the ceiling. It gives" +
                   " easy and constant light to the area without having to worry" +
                   " about the possibilities of fires.",
                   "hay" : "%^YELLOW%^There is a bundle of hay in the back of each" +
                   " stall and it thickly coats the floors of the stalls here.",
                   ({ "trough", "water trough", "troughs", "water troughs" }) : "%^BOLD%^%^BLUE%^There" +
                   " is a water trough on the back wall of every stall, filled with" +
                   " fresh cool water.",
                   ({ "apple", "apples", "carrot", "carrots" }) : "Bits of apples and" +
                   " carrots are on the floors of some of the stalls, treats to the" +
                   " younger horses from the stable hands.",
                   ({ "stall", "stalls" }) : "The stalls are made out of sturdy wood." +
                   " They are high so that the horses can't jump over them but the" +
                   " front of the stalls aren't solid wood after half way up so that" +
                   " you can pet the horses and even feed them a treat or two. These" +
                   " stalls are a little smaller than the ones in the rest of the" +
                   " stables, except for the one against the far wall which is large." +
                   " Some of the stalls even have blankets or padding along the walls" +
                   " so the little horses don't hurt themselves.",
                   ({ "bucket", "mush bucket", "buckets", "mush buckets" }) : "A bucket" +
                   " of mush is attached to each stall for the horses to eat.",
                   "mush" : "The mush is a gruel like substance that is easier on" +
                   " the digestive track of young horses. It is also an easy way" +
                   " to hide the vitamins in the meals, and it can be heated to help" +
                   " warm them up on cold nights.",
                   ]));
    set_exits(([
                   "south" : ROOMS + "stable3",
                   ]));
//     set_animal(({"kitten"}),({MONS+"kitten"}));
//     set_animal_price(({"kitten"}),({5}));
}

void reset()
{
    object ob;

    ::reset();
    if (!present("vendor")) {
        new(MONS + "cindy")->move(TO);
    }
}

void init()
{
    ::init();
//     add_action("read","read");
}

int read(string str)
{
    if (str == "sign") {
        if (!present("vendor")) {
            notify_fail("The sign appears to have been stolen.\n");
            return 0;
        }else {
            write("The sign reads (in rather bad handwriting):\n\n" +
                  "%^BOLD%^%^MAGENTA%^These little kittens are all in need of a" +
                  " good home. Every kitten is 5 gold, my mother insists I" +
                  " have to make up for the feeding costs. Please pick out" +
                  " which one you like best.%^RESET%^\n\n" +
                  "	A fiesty %^YELLOW%^c%^RED%^a%^YELLOW%^l%^RED%^i%^YELLOW%^c%^RED%^o%^RESET%^ kitten that always wants to play with you\n" +
                  "	An adorable gray and %^BOLD%^white%^RESET%^ striped cat that loves to eat\n" +
                  "	%^BOLD%^A cute white kitty that loves to purr and cuddle all day%^RESET%^\n" +
                  "	%^ORANGE%^An orange and %^BOLD%^%^WHITE%^white%^RESET%^%^ORANGE%^ kitten who just wants to sleep a lot\n" +
                  "	%^BOLD%^%^BLACK%^A pure black kitty that slinks around and surprises people\n\n" +
                  "		   %^RESET%^%^BOLD%^All of them are adorable!!\n");
            say("" + TP->query_cap_name() + " reads the sign.\n");
            return 1;
        }
    }
}
