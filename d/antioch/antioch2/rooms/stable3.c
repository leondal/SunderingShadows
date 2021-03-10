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
    set_short("Antioch Stables");
    set_long(
        "%^WHITE%^This appears to be the room where they shoe horses and give them any additional medical attention. There are several horse %^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^e%^WHITE%^s%^WHITE%^ that have been pre-made, along with strips of %^WHITE%^i%^BOLD%^%^BLACK%^ron%^RESET%^%^WHITE%^ that can be fashioned for new shoes. There is also a bucket of %^BOLD%^%^BLACK%^nails%^RESET%^%^WHITE%^ for the shoes and various %^ORANGE%^to%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ls%^WHITE%^ for fixing the shoes in place. There are clippers to trim the horses hooves before shoeing them as well. A small %^BOLD%^%^BLACK%^furna%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^ is set up with a %^ORANGE%^b%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^llows%^WHITE%^ next to it for heating up the shoes and there is a %^CYAN%^trou%^BOLD%^%^CYAN%^g%^CYAN%^h%^RESET%^%^WHITE%^ of water next to that for cooling the hot iron down. On the back wall are a few %^ORANGE%^shel%^BOLD%^%^BLACK%^v%^RESET%^%^ORANGE%^es%^WHITE%^ with %^ORANGE%^ba%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^dages%^WHITE%^ and %^ORANGE%^ointme%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^ts%^WHITE%^ for cleaning any wounds the horses may have. The %^BOLD%^%^BLACK%^f%^BLACK%^loor%^RESET%^%^WHITE%^ here is made of dirt but is kept free from hay and the area around the furnace is %^BOLD%^%^BLACK%^ston%^WHITE%^e%^BLACK%^,%^RESET%^%^WHITE%^ you also notice that it is kept further away from the wall to minimize the risk of fire. To the north there are some more stalls and to the south is a door that leads to the storage room.
"
        );
    set_smell("default", "There is a slightly burnt scent in this room.");
    set_listen("default", "The horses can be heard stomping about in" +
               " the stalls around you.");
    set_items(([
                   ({ "ground", "floor", "dirt" }) : "The floor here is simply dirt so" +
                   " that the horses won't hurt their feet.",
                   "ceiling" : "The ceiling is high with an arched roof. Chains" +
                   " hang down from it that hold light stones.",
                   ({ "light", "stone", "enchanted stone", "light stone", "enchanted stones", "light stones", "stones" }) : "%^BOLD%^Stones that have been enchanted" +
                   " with a continual light spell are hung from the ceiling. It gives" +
                   " easy and constant light to the area without having to worry" +
                   " about the possibilities of fires.",
                   ({ "trough", "water trough" }) : "There is a trough of water not" +
                   " far from the furnace for cooling down the hot horse shoes.",
                   ({ "shoes", "horse shoes", "horse shoe" }) : "There are several" +
                   " pre-made horse shoes here that will be adjusted as necessary" +
                   " to perfectly fit the horse's feet.",
                   ({ "nail", "nails", "bucket" }) : "There is a bucket full of the type" +
                   " of nails used to shod horses.",
                   ({ "stone", "stones" }) : "The floor and area around the furnace" +
                   " is made of stone to minimize the possibility of fires.",
                   ({ "shelf", "shelves" }) : "Along the back wall are shelves of" +
                   " ointments and bandages to treat horse injuries.",
                   ({ "ointment", "ointments" }) : "There are bottles of different" +
                   " types of ointments on the back shelves. Some of them don't" +
                   " smell so great.",
                   ({ "bandage", "bandages" }) : "There are very large clean bandages" +
                   " on the back shelves in case a horse gets a cut.",
                   ({ "tool", "tools" }) : "There are several black smithing tools here" +
                   " that are used to shod horses.",
                   "clippers" : "These are basically a pair of very large nail" +
                   " clippers for horses. They are used to trim the horses hooves" +
                   " before you shoe them.",
                   "bellows" : "A bellows is laying near the furnace.",
                   "furnace" : "A small furnace is set up on one side of the room." +
                   " It is placed away from the wall and anything that might catch" +
                   " on fire. The area around it is stone to minimize the chance of" +
                   " burning. It is used to heat up the iron so that the horse shoer" +
                   " can mold it to fit the horse's hooves precisely.",
                   ({ "iron", "strips of iron" }) : "Straight lengths of iron are" +
                   " stacked in a pile. They can be bent and molded when they're hot" +
                   " to be formed into shoes for horses.",
                   "door" : "This is a strong looking wooden door that leads to the" +
                   " storage room.",
               ]));
    set_exits(([
                   "east" : ROOMS + "stables",
                   "north" : ROOMS + "stable4",
                   "south" : ROOMS + "stable5",
               ]));
    set_door("door", ROOMS + "stable5", "south", 0);
}
