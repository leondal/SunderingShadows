//Changed over to spawn the mounts in /d/common/mounts
//Added clydesdale as a basic mount for large-size players. Nienne, 11/04.

#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
#include "/d/common/common.h"
inherit STABLE;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Antioch Stables");
    set_long(
        "%^WHITE%^This is part of the Antioch Stables. Horses are kept in the %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^al%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^s%^WHITE%^ around you. The stalls fill three quarters of the room, only the southern passage way to the rest of the stable is free. They look to be kept very clean. There is a %^BOLD%^%^BLACK%^bucket%^RESET%^%^WHITE%^ of grain attached to the front of each stall so the %^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^se%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ can munch on that if they want. Water %^ORANGE%^trou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ are in the back of each stall for the %^ORANGE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^rses%^WHITE%^ to drink from. Fresh %^ORANGE%^h%^ORANGE%^a%^ORANGE%^y%^WHITE%^ is also piled into a corner of every stall and extra hay is sprinkled on the floors so the horses won't chip their hooves. The horses look to be well groomed and well fed. Some of them are contentedly munching on hay while others appear to be dozing. The %^ORANGE%^grou%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^d%^WHITE%^ here is all dirt for easier footing. No lamps are used, instead a few magically enchanted light stones hang down from the ceiling. That way there will never be a problem with fires here.
"
        );
    set_smell("default", "You can smell the sweat of horses mingled" +
              " with hay.");
    set_listen("default", "You can hear the animals stomping around in" +
               " their stalls.");
    set_items(([
                   "sign" : "There is a little sign here for you to read.",
                   "hay" : "%^YELLOW%^Fresh hay is piled into a corner of every stall, some is" +
                   " also sprinkled on the ground to keep the horses from chipping" +
                   " their hooves.",
                   ({ "ground", "floor", "dirt" }) : "The floor here is simply dirt. It" +
                   " is easier on the horses hooves that way.",
                   ({ "light", "stone", "enchanted stone", "light stone", "enchanted stones", "light stones", "stones" }) : "%^BOLD%^Stones that have been enchanted" +
                   " with a continual light spell are hung from the ceiling. It gives" +
                   " easy and constant light to the area without having to worry" +
                   " about the possibilities of fires.",
                   "ceiling" : "The ceiling is high with an arched roof. Enchanted" +
                   " light stones hang down from it on chains.",
                   ({ "stall", "stalls" }) : "The stalls are made out of sturdy wood." +
                   " They are high so that the horses can't jump over them but the" +
                   " front of the stalls aren't solid wood after half way up so that" +
                   " you can pet the horses and even feed them a treat or two. A" +
                   " bucket of grain is hung on the inside of each stall for the" +
                   " horses to munch on.",
                   ({ "trough", "troughs", "water trough", "water troughs" }) : "%^BOLD%^%^BLUE%^Water" +
                   " troughs are in the back of every stall so that the horses can" +
                   " drink from them whenever they like.",
                   ({ "horse", "horses" }) : "There are several different types of" +
                   " horses in the stalls here. There even appears to be a mountain" +
                   " pony in one of them. Some of the horses are eating, others are" +
                   " dozing off on their feet. They look relaxed, if a little bored.",
                   ({ "bucket", "grain" }) : "A bucket of grain is attached to the" +
                   " front of each stall for the horses to munch on.",
                   ]));
    set_exits(([
                   "south" : ROOMS + "stables",
                   ]));
    set_animal(({ "mare", "stallion", "gelding", "charger", "pony", "workhorse" }),
               ({ MOUNTS "mare", MOUNTS "stallion", MOUNTS "gelding", MOUNTS "charger", MOUNTS "pony", MOUNTS "clydesdale" }));
    set_animal_price(({ "mare", "stallion", "gelding", "charger", "pony", "workhorse", }), ({ 50, 150, 75, 200, 80, 125, }));
    set_stalls(30);
    ::fill_stalls();
}

void init()
{
    ::init();
    add_action("read_sign", "read");
}

int read_sign(string str)
{
    if (!present("stable hand")) {
        write("Someone appears to have knocked over the sign and it" +
              " is covered in dirt and can't be read.\n");
        return 1;
    }
    if (str == "sign") {
        write("%^BOLD%^This sign tells which horses are for sale.%^RESET%^\n\n" +
              "		A gentle gray mare\t\t 50 gold\n"+
              "		%^BOLD%^%^RED%^A fiery %^BLACK%^black%^RED%^ stallion%^RESET%^\t\t150 gold\n"+
              "		%^BOLD%^A white charger%^RESET%^\t\t\t200 gold\n"+
              "		%^ORANGE%^A shaggy mountain pony%^RESET%^\t\t 80 gold\n"+
              "		%^YELLOW%^A dun colored gelding%^RESET%^\t\t 75 gold\n"+
              "		%^ORANGE%^A sturdy clydesdale workhorse%^RESET%^\t125 gold\n\n"+
              "You can buy whichever horse you want, but the mountain" +
              " pony should only be ridden by children or very small people." +
              "  Larger riders may wish to purchase the more sturdy workhorse.\n");
        if (!TP->query_invis()) {
            say("" + TP->query_cap_name() + " reads a sign.");
        }
        return 1;
    }
}

void reset()
{
    if (!present("stable hand")) {
        new("/d/antioch/antioch2/mons/stable")->move(TO);
    }
}
