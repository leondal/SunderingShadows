//updated 8/13/2019 by Odin to include the Godslayer
// 7/3/20 Nienne updated so green boots show at all times, not just when armor2 is active.
#include <std.h>
#include "mountain.h";

#define ITEM "/d/islands/common/obj/new/"

inherit BASE;

int weapons1 = 0, weapons2 = 0, armor1 = 0, armor2 = 0, other1 = 0, other2 = 0, gold = 0, platinum = 0;

void create()
{
    ::create();
    set_terrain(NAT_CAVE);
    set_property("indoors", 1);
    set_short("Treasure room");

    set_long(
        "%^BOLD%^%^RED%^This is a small cave that is obviously used for a horde room for" +
        " the dragon. There is %^BOLD%^%^YELLOW%^gold%^BOLD%^%^RED%^, %^BOLD%^%^WHITE%^platinum%^BOLD%^%^RED%^, and all sorts of treasures everywhere you look." +
        " There is an assortment of %^BOLD%^%^WHITE%^weapons%^BOLD%^%^RED%^, %^BOLD%^%^WHITE%^armor%^BOLD%^%^RED%^, and %^BOLD%^%^WHITE%^other%^BOLD%^%^RED%^ things piled over ten feet high" +
        " all over the room.");

    set_exits(([
                   "out" : MOUNTAIN + "mountain11",
                   "portal" : MOUNTAIN + "mountain01",
               ]));

    set_items(([
                   "gold" : (: TO, "gold_desc" :),
                   "platinum" : (: TO, "platinum_desc" :),
                   "weapons" : (: TO, "weapons_desc" :),
                   "armor" : (: TO, "armor_desc" :),
                   "other" : (: TO, "other_desc" :),
               ]));

    set_search("default", "There is treasure everywhere!");
    set_had_players(12);
    if (!present("guardian")) {
        new(MON + "guardian")->move(TO);
    }
}

void init()
{
    ::init();
    if (!objectp(TP)) {
        return;
    }
    if (!userp(TP)) {
        return;
    }
    add_action("take_fun", "take");
    add_action("quit_func", "quit");
}

void activate_lewt()
{
    weapons1 = 2; weapons2 = 2; armor1 = 2; armor2 = 2; other1 = 2; other2 = 2; gold = 1; platinum = 1;
}

int quit_func(string str)
{
    TP->move(MOUNTAIN "mountain11");
    tell_object(TP, "%^BOLD%^%^BLUE%^You realise the lair of a dragon is not a wise place to remain for long.  You "
                "carefully make your way out of the lair before taking a rest.%^RESET%^");
    TP->force_me("quit");
}

string gold_desc()
{
    if (gold) {
        return "There are piles of gold all around. You could %^YELLOW%^take%^RESET%^ as much as you can carry!";
    }
    return "Most of the gold seems to have been taken already.";
}

string platinum_desc()
{
    if (platinum) {
        return "There are piles of platinum all around. You could %^YELLOW%^take%^RESET%^ as much as you can carry!";
    }
    return "Most of the platinum seems to have been taken already.";
}

string weapons_desc()
{
    if (weapons1 && weapons2) {
        return "Various weapons are strewn about. One pile consists of a gemmed %^YELLOW%^dagger%^RESET%^, a razor-sharp %^YELLOW%^battleaxe%^RESET%^, a %^YELLOW%^whip%^RESET%^ with fiery strands, a clawed %^YELLOW%^gauntlet%^RESET%^, a %^YELLOW%^small hammer%^RESET%^, a %^YELLOW%^sickle%^RESET%^, an aged yew %^YELLOW%^longbow%^RESET%^, and a %^YELLOW%^pistol%^RESET%^.\n\nOff to the side is another stack, all varied types of blades that include a %^YELLOW%^beautiful scimitar%^RESET%^, a runed %^YELLOW%^dark scimitar%^RESET%^, a %^YELLOW%^crimson longsword%^RESET%^, a %^YELLOW%^golden longsword%^RESET%^, a crystal %^YELLOW%^sabre%^RESET%^, an %^YELLOW%^elven curved blade%^RESET%^ an ominous %^YELLOW%^black bastard sword %^RESET%^and an equally ominous %^YELLOW%^black and silver falcata%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...";
    }
    if (weapons1) {
        return "Various weapons are strewn about. One pile consists of a gemmed %^YELLOW%^dagger%^RESET%^, a razor-sharp %^YELLOW%^battleaxe%^RESET%^, a %^YELLOW%^whip%^RESET%^ with fiery strands, a clawed %^YELLOW%^gauntlet%^RESET%^, a %^YELLOW%^small hammer%^RESET%^, a %^YELLOW%^sickle%^RESET%^, an aged yew %^YELLOW%^longbow%^RESET%^, and a %^YELLOW%^pistol%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...\n\nOff to the side is another stack, all varied types of blades, but a dull red ward flickers above them that prevents you from reaching out to take one.";
    }
    if (weapons2) {
        return "Various weapons are strewn about. Off to the side is a stack of varied types of blades that include a %^YELLOW%^beautiful scimitar%^RESET%^, a runed %^YELLOW%^dark scimitar%^RESET%^, a %^YELLOW%^crimson longsword%^RESET%^, a %^YELLOW%^golden longsword%^RESET%^, a crystal %^YELLOW%^sabre%^RESET%^, an %^YELLOW%^elven curved blade%^RESET%^, an ominous %^YELLOW%^black bastard sword%^RESET%^, and an equally ominous %^YELLOW%^black and silver falcata%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...\n\nOff to the side is another pile, this time of more exotic weaponry, but a dull red ward flickers above them that prevents you from reaching out to take one.";
    }
    return "Most of the weapons appear to have been taken already, and the few that are left are screened by some sort of "
           "dull crimson ward that prevents you from getting close to them.";
}

string armor_desc()
{
    if (armor1 && armor2) {
        return "Various armor is strewn about. One pile consists of an ornate %^YELLOW%^chainshirt"
               "%^RESET%^, dull blue %^YELLOW%^fullplate%^RESET%^, a crystal-like %^YELLOW%^breastplate%^RESET%^, a mass of %^YELLOW%^shadows%^RESET%^, a crystal %^YELLOW%^mail shirt%^RESET%^ , a black leather %^YELLOW%^carapace%^RESET%^, and a silver %^YELLOW%^headband%^RESET%^\n\nA second stack, off to the side, holds a few smaller pieces including an iron %^YELLOW%^helm%^RESET%^, a %^YELLOW%^colorful cloak%^RESET%^, a shimmering %^YELLOW%^cape%^RESET%^, a hooded black %^YELLOW%^cloak%^RESET%^, a %^YELLOW%^robe%^RESET%^ decorated with stars, some dark red %^YELLOW%^boots%^RESET%^, some forest %^YELLOW%^green boots%^RESET%^, and a pair of heavy %^YELLOW%^gauntlets%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...";
    }
    if (armor1) {
        return "Various armor is strewn about. One pile consists of an ornate %^YELLOW%^chainshirt%^RESET%^, dull blue %^YELLOW%^fullplate%^RESET%^, a crystal-like %^YELLOW%^breastplate%^RESET%^, a mass of %^YELLOW%^shadows%^RESET%^, a crystal %^YELLOW%^mail shirt%^RESET%^, a black leather %^YELLOW%^carapace%^RESET%^, and a silver %^YELLOW%^headband%^RESET%^.\nYou could try to %^YELLOW%^take %^RESET%^something...\n\nOff to the side is another stack, this time of smaller accessories, but a dull red ward flickers above them that prevents you from reaching out to take one.";
    }
    if (armor2) {
        return "Various armor is strewn about. Off to the side is a stack that holds a few small pieces including an iron %^YELLOW%^helm%^RESET%^, a %^YELLOW%^colorful cloak%^RESET%^, a shimmering %^YELLOW%^cape%^RESET%^, a hooded black %^YELLOW%^cloak%^RESET%^, a %^YELLOW%^robe%^RESET%^ decorated with stars, some dark red %^YELLOW%^boots%^RESET%^, some %^YELLOW%^forest green boots%^RESET%^, and a pair of heavy %^YELLOW%^gauntlets%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...\n\nOff to the side is another pile, these much larger items, but a dull red ward flickers above them that prevents you from reaching out to take one.";
    }
    return "Most of the armor appears to have been taken already, and the few items that are left are screened by some "
           "sort of dull crimson ward that prevents you from getting close to them.";
}

string other_desc()
{
    if (other1 && other2) {
        return "Various other items are strewn about. One pile consists of a medium %^YELLOW%^shield%^RESET%^ and many pairs of bracers - %^YELLOW%^reddish bracers%^RESET%^, %^YELLOW%^bluish bracers%^RESET%^, %^YELLOW%^white bracers%^RESET%^ and %^YELLOW%^bracers of jade%^RESET%^.\n\nA second stack, off to the side, a %^YELLOW%^ring%^RESET%^ of platinum and gold, a runed blue %^YELLOW%^bag%^RESET%^, a scarlet %^YELLOW%^sash%^RESET%^ a short heavy %^YELLOW%^rod%^RESET%^ and a %^YELLOW%^chemise%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...";
    }
    if (other1) {
        return "Various other items are strewn about. One pile consists of a medium %^YELLOW%^shield%^RESET%^ and many pairs of bracers - %^YELLOW%^reddish bracers%^RESET%^, %^YELLOW%^bluish bracers%^RESET%^, %^YELLOW%^white bracers %^RESET%^and %^YELLOW%^bracers of jade%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...\n\nMore sit in a stack off to the side, but a dull red ward flickers above them that prevents you from reaching out to take one.";
    }
    if (other2) {
        return "Various other items are strewn about. Off to the side is a stack that holds a set of a %^YELLOW%^ring%^RESET%^ of platinum and gold, a runed blue %^YELLOW%^bag%^RESET%^, a scarlet %^YELLOW%^sash%^RESET%^ a short heavy %^YELLOW%^rod%^RESET%^ and a %^YELLOW%^chemise%^RESET%^.\nYou could try to %^YELLOW%^take%^RESET%^ something...\n\nOff to theside is another pile, mostly bracers, but a dull red ward flickers above them that prevents you from reaching out to take one.";
    }
    return "Most of the other items appear to have been taken already, and the few that are left are screened by some "
           "sort of dull crimson ward that prevents you from getting close to them.";
}

int take_fun(string str)
{
    object ob;

    if (present("fire giant")) {
        write("The guardian will not give you time to look.");
        return 1;
    }
    if (!str) {
        tell_object(TP, "What do you want to take?");
        return 0;
    }
    switch (str) {
    case "dagger":
    case "battleaxe":
    case "whip":
    case "gauntlet":
    case "small hammer":
    case "sickle":
    case "longbow":
    case "pistol":
        if (!weapons1) {
            tell_object(TP, "You reach out for a weapon and are stung sharply by the crimson ward around it!");
            return 1;
        }
        write("%^BOLD%^%^GREEN%^You take a thorough look around the room for a weapon and select one of interest.");
        tell_room(TO, "%^BOLD%^%^GREEN%^" + TPQCN + " takes a thorough look around the room for a weapon and selects one of interest.", TP);
        switch (str) {
        case "dagger":             ob = new(ITEM + "jdagger")->move(TO);         break;

        case "battleaxe":          ob = new(ITEM + "dragonaxe")->move(TO);       break;

        case "whip":               ob = new(ITEM + "enrapture")->move(TO);       break;

        case "gauntlet":           ob = new(ITEM + "claw")->move(TO);            break;

        case "small hammer":       ob = new(ITEM + "blight_hammer.c")->move(TO); break;

        case "sickle":             ob = new(ITEM + "raven_sickle.c")->move(TO);  break;

        case "pistol":             ob = new(ITEM + "mpistol.c")->move(TO);  break;

        case "longbow":             ob = new(ITEM + "deathfromafar.c")->move(TO);  break;
        }
        weapons1--;
        break;

    case "beautiful scimitar":
    case "dark scimitar":
    case "crimson longsword":
    case "golden longsword":
    case "sabre":
    case "black bastard sword":
    case "black and silver falcata":
    case "elven curved blade":                                                                             //weapon2
        if (!weapons2) {
            tell_object(TP, "You reach out for a weapon and are stung sharply by the crimson ward around it!");
            return 1;
        }
        write("%^BOLD%^%^GREEN%^You take a thorough look around the room for a weapon and select one of interest.");
        tell_room(TO, "%^BOLD%^%^GREEN%^" + TPQCN + " takes a thorough look around the room for a weapon and selects one of interest.", TP);
        switch (str) {
        case "beautiful scimitar":
            ob = new(ITEM + "esword")->move(TO);
            break;

        case "dark scimitar":
            ob = new(ITEM + "shefflix")->move(TO);
            break;

        case "crimson longsword":
            ob = new(ITEM + "rdblade")->move(TO);
            break;

        case "sabre":
            ob = new(ITEM + "csabre")->move(TO);
            break;

        case "golden longsword":
            ob = new(ITEM + "gdblade")->move(TO);
            break;

        case "black bastard sword":
            ob = new(ITEM + "ragnarok")->move(TO);
            break;

        case "black and silver falcata":
            ob = new(ITEM + "tasword")->move(TO);
            break;

        case "elven curved blade":
            ob = new(ITEM + "godslayer")->move(TO);
            break;
        }
        weapons2--;
        break;

    case "chainshirt":
    case "fullplate":
    case "breastplate":
    case "shadows":
    case "mail shirt":
    case "carapace":
    case "headband":                                                                                            //armor1
        if (!armor1) {
            tell_object(TP, "You reach out for a piece of armor and are stung sharply by the crimson ward around it!");
            return 1;
        }
        write("%^BOLD%^%^GREEN%^You take a thorough look around the room for some armor and select one of interest.");
        tell_room(TO, "%^BOLD%^%^GREEN%^" + TPQCN + " takes a thorough look around the room for some armor and selects one of interest.", TP);
        switch (str) {
        case "chainshirt":
            ob = new(ITEM + "e_chain.c")->move(TO);
            break;

        case "fullplate":
            ob = new(ITEM + "e_plate.c")->move(TO);
            break;

        case "breastplate":
            ob = new(ITEM + "iceplate.c")->move(TO);
            break;

        case "shadows":
            ob = new(ITEM + "n_cover.c")->move(TO);
            break;

        case "mail shirt":
            ob = new(ITEM + "p_mail.c")->move(TO);
            break;

        case "carapace":
            ob = new(ITEM + "sarmor.c")->move(TO);
            break;

        case "headband":
            ob = new(ITEM + "headband_o_mp.c")->move(TO);
            break;
        }
        armor1--;
        break;

    case "helm":
    case "colorful cloak":
    case "cape":
    case "cloak":
    case "robe":
    case "red boots":
    case "green boots":
    case "gauntlets":                                                                                                                    //armor2
        if (!armor2) {
            tell_object(TP, "You reach out for a piece of armor and are stung sharply by the crimson ward around it!");
            return 1;
        }
        write("%^BOLD%^%^GREEN%^You take a thorough look around the room for some armor and select one of interest.");
        tell_room(TO, "%^BOLD%^%^GREEN%^" + TPQCN + " takes a thorough look around the room for some armor and selects one of interest.", TP);
        switch (str) {
        case "helm":
            ob = new(ITEM + "helm.c")->move(TO);
            break;

        case "cape":
            ob = new(ITEM + "shimmeringcape2.c")->move(TO);
            break;

        case "cloak":
            ob = new(ITEM + "seeker.c")->move(TO);
            break;

        case "colorful cloak":
            ob = new(ITEM + "naturecloak.c")->move(TO);
            break;

        case "robe":
            ob = new(ITEM + "starrobes.c")->move(TO);
            break;

        case "red boots":
            ob = new(ITEM + "boots.c")->move(TO);
            break;

        case "green boots":
            ob = new(ITEM + "rangerboots.c")->move(TO);
            break;

        case "gauntlets":
            ob = new(ITEM + "o_gauntlets.c")->move(TO);
            break;
        }
        armor2--;
        break;

    case "shield":
    case "reddish bracers":
    case "bluish bracers":
    case "white bracers":
    case "bracers of jade":                                                                                      //other1
        if (!other1) {
            tell_object(TP, "You reach out for an item and are stung sharply by the crimson ward around it!");
            return 1;
        }
        write("%^BOLD%^%^GREEN%^You take a thorough look around the room for an item and select one of interest.");
        tell_room(TO, "%^BOLD%^%^GREEN%^" + TPQCN + " takes a thorough look around the room for an item and selects one of interest.", TP);
        switch (str) {
        case "shield":
            ob = new(ITEM + "shield")->move(TO);
            break;

        case "bracers of jade":
            ob = new(ITEM + "snakebracers")->move(TO);
            break;

        case "bluish bracers":
            ob = new(ITEM + "waveguards")->move(TO);
            break;

        case "reddish bracers":
            ob = new(ITEM + "flameguards")->move(TO);
            break;

        case "white bracers":
            ob = new(ITEM + "windguards")->move(TO);
            break;
        }
        other1--;
        break;

    case "ring":
    case "bag":
    case "sash":
    case "rod":
    case "chemise":                                                                      //other2
        if (!other2) {
            tell_object(TP, "You reach out for an item and are stung sharply by the crimson ward around it!");
            return 1;
        }
        write("%^BOLD%^%^GREEN%^You take a thorough look around the room for an item and select one of interest.");
        tell_room(TO, "%^BOLD%^%^GREEN%^" + TPQCN + " takes a thorough look around the room for an item and selects one of interest.", TP);
        switch (str) {

        case "ring":
            ob = new(ITEM + "healring")->move(TO);
            break;

        case "bag":
            ob = new(ITEM + "bag")->move(TO);
            break;

        case "sash":
            ob = new(ITEM + "firesash")->move(TO);
            break;

        case "rod":
            ob = new(ITEM + "rodIV")->move(TO);
            break;

        case "chemise":
            ob = new(ITEM + "chemise")->move(TO);
            break;
        }
        other2--;
        break;

    case "gold":
        if (!gold) {
            tell_object(TP, "The gold seems to have been taken!");
            return 1;
        }
        write("%^BOLD%^%^YELLOW%^You gather up all the gold that has not been melted from intense heat.");
        tell_room(TO, "%^BOLD%^%^YELLOW%^" + TPQCN + " gathers up all the gold that has not been melted from intense heat.", TP);
        ob = new("/std/obj/coins");
        ob->set_money("gold", random(250000) + 250000);
        ob->move(TO);
        gold = 0;
        return 1;

        break;

    case "platinum":
        if (!platinum) {
            tell_object(TP, "The platinum seems to have been taken!");
            return 1;
        }
        write("%^BOLD%^%^WHITE%^You gather up all the platinum that has not been melted from intense heat.");
        tell_room(TO, "%^BOLD%^%^WHITE%^" + TPQCN + " gathers up all the platinum that has not been melted from intense heat.", TP);
        ob = new("/std/obj/coins");
        ob->set_money("platinum", random(100000) + 50000);
        ob->move(TO);
        platinum = 0;
        return 1;

        break;

    default:
        tell_object(TP, "You can't see that item here!");
        return 1;

        break;
    }
    tell_room(TO, "%^RED%^As the item is taken, a dull ward of crimson flickers into being over the pieces nearby.");
    return 1;
}
