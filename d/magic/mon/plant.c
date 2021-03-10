#include <std.h>
#include "summoned_monster.h"


inherit MONSTER;


varargs void setup_plant(string the_plant);


void create()
{
    ::create();
    set_name("a plant");
    set_id(({"plant"}));
    set_long("This is a plant.");
    set_attack_limbs(({"head"}));

    set_hd(2,1);
    set_hp(16);
    set_body_type("snake");
    set_damage(1,3);
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_gender("neuter");
    set_race("plant");
    
    setup_plant(); // call this again to reset it/change plant type
}


int is_plant() { return 1; }


// if you want a specific plant, just pass one of the plants on the list as an argument to setup_plant
varargs void setup_plant(string the_plant)
{
    string *plants = ({"assassin vine","battlebriar","bloodthorn","briarvex","dark tree","dread blossom","violet fungus",
        "shrieker fungus","gas spore","green warder","greenvise","ironmaw","myconid worker","myconid leader",
        "myconid elder","myconid guard","myconid sovereign","needlefolk","night twist","oaken defender",
        "phantom fungus","plague brush","red sundew","shambling mound","sporebat" });

    string plant;

    plant = plants[random(sizeof(plants))];

    if((stringp(the_plant)) && (the_plant != "") && (the_plant != " ") && (member_array(the_plant,plants) != -1)) { plant = the_plant; }

    switch(plant)
    {
    case "assassin vine":

        set_short("assassin vine");
        set_name("assassin vine");
        set_id(({"plant","assassin vine","vine"}));
        set_long("This is a vine-like creature, about twenty feet in length.  Smaller vines branch off from the body "
            "every few inches. These small vines bear clusters of leaves with small fruit that look like "
            "wild grapes.");
        set_fake_limbs(({"torso","head","vine"}));
        set_attack_limbs(({"torso","head""vine"}));
        break;

    case "battlebriar":

        set_short("battlebriar");
        set_name("battlebriar");
        set_id(({"plant","battlebriar"}));
        set_long("This six legged lionlike creature has a body made of writhing vines and thorns.  "
            "Each of its gorillalike pairs of limbs is slightly shorter than the pair in front of "
            "it, its forelimbs are the longest, the middle pair of limbs slightly shorter, and its "
            "rear pair of legs the shortest of all.  Long thorns protrude from every part of "
            "the creature's body, making it seem impossible to approach or move around the "
            "creature without risking serious injury.");
        set_fake_limbs(({"front right hand","front left hand","middle right hand","middle left hand","rear right hand","rear left hand","torso","head","spikes","tail"}));
        set_attack_limbs(({"front right hand","front left hand","middle right hand","middle left hand","rear right hand","rear left hand","spikes","tail"}));
        break;

    case "bloodthorn":

        set_short("bloodthorn");
        set_name("bloodthorn");
        set_id(({"plant","bloodthorn"}));
        set_long("This looks like a very large hornwood tree. The trunk is a" // borrowed from antioch
            " light brown shade and completely smooth. The leaves"
            " are pointed and double-lobed but are a little small for"
            " a hornwood, especially considering the size of the tree."
            " There are many vines and creepers growing in the tree, you"
            " can't imagine how it's stayed so healthy. Peering closer"
            " at the vines you can see some thorns on the very ends of"
            " them. This isn't a hornwood tree at all, but a bloodthorn!");
        set_fake_limbs(({"vine","trunk","limb","torso"}));
        set_attack_limbs(({"vine"}));
        break;

    case "briarvex":

        set_short("briarvex");
        set_name("briarvex");
        set_id(({"plant","briarvex"}));
        set_long("This creature appears to be a large humanoid-shaped plant,roughly the size of an ogre. "
            "Glistening with sticky amber sap, wicked spikes protrude from its body, and a pair of writhing, "
            "tentacular vines extend from its hips.");
        set_fake_limbs(({"right hand","left hand","torso","head","tentacles","spikes","vine"}));
        set_attack_limbs(({"right hand","left hand","tentacles","spikes","vine"}));
        break;

    case "dark tree":

        set_short("dark tree");
        set_name("dark tree");
        set_id(({"plant","dark tree","tree"}));
        set_long("This tree resembles a cypress tree, but in its bark is a fiendish, evil-looking face, and two of its "
            "branches are gnarled, wooded, spindly arms..");
        set_fake_limbs(({"trunk","right arm","left arm","face"}));
        set_attack_limbs(({"right arm","left arm"}));
        break;

    case "dread blossom":

        set_short("dread blossom");
        set_name("dread blossom");
        set_id(({"plant","dread blossom","blossom"}));
        set_long("This is a bed of hundreds of large red flowers speckled with gold and black.  "
            "The perfumed scent of the flowers is not quite strong enough to overcome the "
            "scent of rotting flesh coming from the plants.  They flit about on the breeze "
            "like grusome butterflies.");
        set_fake_limbs(({"flower"}));
        set_attack_limbs(({"flower"}));
        break;

    case "violet fungus":

        set_short("violet fungus");
        set_name("violet fungus");
        set_id(({"plant","violet fungus","fungus"}));
        set_long("This human-sized mushroom has four tendrillike tentacles and a mass of "
            "small rootlike feelers at its base that enable it to move slowly.");
        set_fake_limbs(({"cap","torso","tentacles","feelers","spores"}));
        set_attack_limbs(({"tentacles","spores"}));
        break;

    case "shrieker fungus":

        set_short("shrieker fungus");
        set_name("shrieker fungus");
        set_id(({"plant","shrieker fungus","fungus"}));
        set_long("This looks like an ordinary, but giant sized mushroom, as tall as a grown human.");
        set_fake_limbs(({"cap","torso","spores"}));
        set_attack_limbs(({"spores"}));
        break;

    case "gas spore":

        set_short("gas spore");
        set_name("gas spore");
        set_id(({"plant","gas spore","spore"}));
        set_long("This disturbing looking spore resembles a medium sized beholder.  Growths on the "
            "plant have formed to resemble eyes, perhaps for defense.");
        set_fake_limbs(({"eye","body","stalk","growth","spore"}));
        set_attack_limbs(({"stalk","spore"}));
        break;

    case "green warder":

        set_short("green warder");
        set_name("green warder");
        set_id(({"plant","green warder","warder"}));
        set_long("This creature looks like a seven foot tall elf made from bushes and leaves.  "
            "There is very little bulk to his wispy height, even though its limbs are made "
            "from solid wood.  Thorns adorn hand-like appendages at the end of long "
            "limbs, serving as the creature's claws.");
        set_fake_limbs(({"right claw","left claw","torso","head","right leg","left leg"}));
        set_attack_limbs(({"right claw","left claw"}));
        break;

    case "greenvise":

        set_short("greenvise");
        set_name("greenvise");
        set_id(({"plant","greenvise"}));
        set_long("This creature looks like a much larger version of a venus fly-trap.  "
            "It has a thick, green, trunklike stem and four sturdy tendrils that "
            "hang down like vines.");
        set_fake_limbs(({"mouth","trunk","vine"}));
        set_attack_limbs(({"mouth","vine"}));
        break;

    case "ironmaw":

        set_short("ironmaw");
        set_name("ironmaw");
        set_id(({"plant","maw"}));
        set_long("This huge creature is nearly twenty feet tall.  It looks almost like an  "
            "oak tree who's leaves are covered in tiny red speckles.  Tendrils are wrapped "
            "around the upper trunk, but they slowly move as if they have a life of their "
            "own.  A barely discernable face can be made out on the creature's trunk.");
        set_fake_limbs(({"trunk","face","tendrils","branches","maw"}));
        set_attack_limbs(({"tendrils","maw"}));
        break;

    case "myconid worker":

        set_short("myconid worker");
        set_name("myconid worker");
        set_id(({"plant","myconid worker","myconid","worker"}));
        set_long("This creature looks very much like a cross between a mushroom and a human.  "
            "Two arms extend from the upper portion of the talk, below the large mushroom cap.  "
            "Near the bottom of the stalk, the trunk splits into two legs.  Large eyes peer "
            "out at the world from a position roughly equivilent to where a face might "
            "be expected on a human.");
        set_fake_limbs(({"right hand","left hand","stalk","cap","spores"}));
        set_attack_limbs(({"right hand","left hand","spores"}));
        break;

    case "myconid leader":

        set_short("myconid leader");
        set_name("myconid leader");
        set_id(({"plant","myconid leader","myconid","leader"}));
        set_long("This creature looks very much like a cross between a mushroom and a human.  "
            "Two arms extend from the upper portion of the talk, below the large mushroom cap.  "
            "Near the bottom of the stalk, the trunk splits into two legs.  Large eyes peer "
            "out at the world from a position roughly equivilent to where a face might "
            "be expected on a human.");
        set_fake_limbs(({"right hand","left hand","stalk","cap","spores"}));
        set_attack_limbs(({"right hand","left hand","spores"}));
        break;

    case "myconid elder":

        set_short("myconid elder");
        set_name("myconid elder");
        set_id(({"plant","myconid elder","myconid","elder"}));
        set_long("This creature looks very much like a cross between a mushroom and a human.  "
            "Two arms extend from the upper portion of the talk, below the large mushroom cap.  "
            "Near the bottom of the stalk, the trunk splits into two legs.  Large eyes peer "
            "out at the world from a position roughly equivilent to where a face might "
            "be expected on a human.");
        set_fake_limbs(({"right hand","left hand","stalk","cap","spores"}));
        set_attack_limbs(({"right hand","left hand","spores"}));
        break;

    case "myconid guard":

        set_short("myconid guard");
        set_name("myconid guard");
        set_id(({"plant","myconid guard","myconid","guard"}));
        set_long("This creature looks very much like a cross between a mushroom and a human.  "
            "Two arms extend from the upper portion of the talk, below the large mushroom cap.  "
            "Near the bottom of the stalk, the trunk splits into two legs.  Large eyes peer "
            "out at the world from a position roughly equivilent to where a face might "
            "be expected on a human.");
        set_fake_limbs(({"right hand","left hand","stalk","cap","spores"}));
        set_attack_limbs(({"right hand","left hand","spores"}));
        break;

    case "myconid sovereign":

        set_short("myconid sovereign");
        set_name("myconid sovereign");
        set_id(({"plant","myconid sovereign","myconid","sovereign"}));
        set_long("This creature looks very much like a cross between a mushroom and a human.  "
            "Two arms extend from the upper portion of the talk, below the large mushroom cap.  "
            "Near the bottom of the stalk, the trunk splits into two legs.  Large eyes peer "
            "out at the world from a position roughly equivilent to where a face might "
            "be expected on a human.");
        set_fake_limbs(({"right hand","left hand","stalk","cap","spores"}));
        set_attack_limbs(({"right hand","left hand","spores"}));
        break;

    case "needlefolk":

        set_short("needlefolk");
        set_name("needlefolk");
        set_id(({"plant","needlefolk"}));
        set_long("This creature looks like a very thin, elf-like cactus.  It's green body is covered "
            "from head to foot with long, needle-like thorns.  The creature moves slowly when ambling "
            "along, but with disturbing quickness when startled.");
        set_fake_limbs(({"right hand","left hand","torso","head","spikes"}));
        set_attack_limbs(({"right hand","left hand","spikes"}));
        break;

    case "night twist":

        set_short("night twist");
        set_name("night twist");
        set_id(({"plant","night twist","twist"}));
        set_long("This is a large, black, leafless tree with unnatural, unsettling shapes "
            "spread throughout the trunk and limbs.  It radiates a gloomy twilight light "
            "and mornful sounds eminate from it when the wind passes by.");
        set_fake_limbs(({"trunk","branch"}));
        set_attack_limbs(({"branch"}));
        break;

    case "oaken defender":

        set_short("oaken defender");
        set_name("oaken defender");
        set_id(({"plant","oaken defender","defender","disk"}));
        set_long("This creature resembles an enormous disk made of dirt, wood, moss and dry leaves, with six vine-like "
            "tentacles protruding from the rim at roughly equal intervals. The topside of the disk has what looks "
            "like a huge, angry face made of stumps and roots set into it");
        set_fake_limbs(({"body","face","tentacles"}));
        set_attack_limbs(({"tentacles"}));
        break;

    case "phantom fungus":

        set_short("phantom fungus");
        set_name("phantom fungus");
        set_id(({"plant","phantom fungus","phantom","fungus"}));
        set_long("This creature looks like a brown and greenish-brown mass with a cluster of nodules atop the main mass.  "
            "There is a cluster of nodules atop the main mass and gaping maw lined with rows of teeth. Four stumpy legs "
            "support the creature and allow it to move about.");
        set_fake_limbs(({"nodule","maw","right fore leg","left fore leg","right rear leg","left rear leg","head"}));
        set_attack_limbs(({"maw","nodule"}));
        break;

    case "plague brush":

        set_short("plague brush");
        set_name("plague brush");
        set_id(({"plant","blague brush","brush"}));
        set_long("This creature looks like a gigantic tumbleweed.");
        set_fake_limbs(({"body"}));
        set_attack_limbs(({"body"}));
        break;

    case "red sundew":

        set_short("red sundew");
        set_name("red sundew");
        set_id(({"plant","red sundew","sundew"}));
        set_long("This creature is almost twenty feet wide and ten feet high.  Its body looks like a "
            "wide mound of tangled ropy rags in red, green and rust colors.");
        set_fake_limbs(({"rag","rope","body"}));
        set_attack_limbs(({"rag","rope"}));
        break;

    case "shambling mound":

        set_short("shambling mound");
        set_name("shambling mound");
        set_id(({"plant","shambling mound","mound","shambler"}));
        set_long("This creature looks like a heap of rotting vegetation about eight feet in girth "
            "and about six feet tall.");
        set_fake_limbs(({"mound","appendage"}));
        set_attack_limbs(({"appendage"}));
        break;

    case "sporebat":

        set_short("sporebat");
        set_name("sporebat");
        set_id(({"plant","sporebat","bat"}));
        set_long("This creature looks like a dark gray bat made up of some sort of spongy material.  "
            "A large, lidless orange eye gazes out from the center of the creature's body.");
        set_fake_limbs(({"right wing","left wing","torso","eye","mouth"}));
        set_attack_limbs(({"right wing","left wing","mouth"}));
        break;
    }
    return;
}