#include <std.h>
#include "../antioch.h"
inherit BANK;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    remove_property("light");
    set_property("light", 2);
    set_short("The New Bank of Antioch");
    set_long(
        "%^WHITE%^This is the bank of Antioch. It is a sturdy building constructed of large grey %^BOLD%^%^BLACK%^st%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^nes.%^RESET%^%^WHITE%^ Even the floor is paved with stones, only the ceiling is made of wood. This would be a very hard place to break into and the guards on duty seem to be alert and ready for any trouble. Behind a large wooden %^ORANGE%^desk%^WHITE%^ on the eastern wall sits a bank teller, papers are neatly filed and organized. Ink and a quill sit ready for him to make notes of transactions. The desk appears to be made out of mahogany and it is quite sturdy, with many drawers and compartments for filing things away. Very heavy metal %^BOLD%^%^BLACK%^grates%^RESET%^%^WHITE%^ are on the southern side, behind them is where the money is stored and there is someone back there carefully counting the deposits. On the western wall are a few %^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^ain%^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^ings,%^WHITE%^ probably to add some life to this drab room. %^ORANGE%^Torches%^WHITE%^ line the %^BOLD%^%^WHITE%^w%^BLACK%^a%^WHITE%^lls,%^RESET%^%^WHITE%^ adding light to the room. From here you can see that the %^ORANGE%^door%^WHITE%^ is heavily fortified with steel and would be nearly impossible to break down.
"
        );
    set_smell("default", "It smells like money in here.");
    set_listen("default", "You can hear the clink of coins as someone" +
               " counts them in the back.");
    set_items(([
                   ({ "door", "bank door" }) : "This large door is fortified by thick" +
                   " steel, it would not break easily.",
                   ({ "torch", "torches" }) : "Torches are placed in sconces about the" +
                   " walls, always lit to bring light to the room since there are" +
                   " no windows here.",
                   "walls" : "The walls are crafted from sturdy grey stone.",
                   "floor" : "The floor could use some sweeping, dust has been" +
                   " tracked in by the many customers. It is also paved with the" +
                   " same stone that the rest of the building is made of.",
                   ({ "roof", "ceiling" }) : "The ceiling is the only part of this" +
                   " building that is made from wood. Several large beams support" +
                   " it and it is unlikely someone could get in through it.",
                   ({ "painting", "paintings" }) : "A few paintings hang on the western" +
                   " wall in an attempt to bring some color to this dull room. One" +
                   " painting that catches your eye is of a unicorn standing on the" +
                   " top of a cliff, with a waterfall pouring down into a lake below." +
                   " The other painting is of the Charu Mountains. Both are done" +
                   " with impeccable detail and color.",
                   ({ "desk", "mahogany desk" }) : "This large desk is made out of" +
                   " mahogany and it contains many drawers for the teller to file" +
                   " away papers. The top of the desk has neatly stacked piles of" +
                   " papers and some ink with a quill sitting next to it and empty" +
                   " sheets of paper off to one side for new transactions. Behind" +
                   " the desk is a matching mahogany chair that is padded and looks" +
                   " very comfortable.",
                   ({ "chair", "mahogany chair" }) : "The mahogany chair perfectly" +
                   " matches the desk. It is padded for extra comfort, probably" +
                   " because the teller spends so much time sitting in it.",
                   "sconces" : "There are sconces placed along the walls of the room" +
                   " and lit torches are in them to light the dark bank.",
                   ({ "grate", "grates", "metal grates", "metal grate" }) : "The metal" +
                   " grates are very thick and would be almost impossible to break" +
                   " through. Behind them someone is carefully counting the bank's" +
                   " money.",
                   ({ "stone", "stones", "grey stones" }) : "The building is constructed" +
                   " from blocks of heavy grey stones to insure security.",
               ]));
    set_exits(([
                   "north" : ROOMS + "fountain",
               ]));
    set_door("bank door", ROOMS + "fountain", "north", 0);
    if (query_night() == 1) {
        set_open("bank door", 0);
        "/d/antioch/antioch2/rooms/fountain"->set_open("bank door", 0);
    }
    if (query_night() != 1) {
        set_open("bank door", 1);
        "/d/antioch/antioch2/rooms/fountain"->set_open("bank door", 1);
    }
}

void reset()
{
    ::reset();
    if (!present("bank guard")) {
        new(MONS + "bank_guard")->move(TO);
    }
    if (!present("bank teller")) {
        new(MONS + "bank_teller")->move(TO);
    }
    return;
}
