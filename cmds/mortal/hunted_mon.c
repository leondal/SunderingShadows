// game animal for nwp hunt command
#include <std.h>
#include <daemons.h>

#define FOWL ({ "pheasant", "grouse", "quail", "turkey", "eagle", "ostrich", "peacock" })

inherit WEAPONLESS;
void do_body(string what, int level, int tough);

void create()
{
    ::create();
    set_name("game animal");
    set_id(({ "animal", "game", "game animal" }));
    set_gender(random(2) ? "male" : "female");
    set_base_damage_type("slashing");
    set_body_type("quadruped");
    set_attacks_num(1);
    set_moving(1);
    set_speed(40);
    set_hd(5, 5);
    set_exp(50);
    set_long("A game animal for the hunting nwp.  If you're seeing this description, something went wrong so please do a bug report.");
    set_short("An incomplete hunting animal - please bug report.");
}

void die(object ob)
{
    object targ;
    int hunted;
    targ = TO->query_current_attacker();
    if (targ->has_nwp("hunting")) {
        NWP_D->perform_nwp(targ, "hunting");
    }
    hunted = targ->get_static("hunted monsters");
    if (hunted > 0) {
        hunted--;
    }
    targ->set_static("hunted monsters", hunted);
    ::die(ob);
}

void do_desc(string what, int level)
{
    string type, age, size;
    int tough;
    level = level + 1;
    add_id(what);
    if (what == "fowl") {
        type = FOWL[random(sizeof(FOWL))];
        add_id(type);
        add_id("bird");
        set_race(type);
        set_name(type);
    }
    switch (random((level * 2) + 20)) {
    case 0..3:   age = "young";      tough = 1;  break;

    case 4..7:   age = "juvenile";   tough = 2;  break;

    case 8..12:  age = "mature";     tough = 4;  break;

    case 13..19: age = "old";        tough = 3;  break;

    case 20..35: age = "adult";      tough = 5;  break;

    case 36..40: age = "ancient";    tough = 3;  break;

    default:     age = "mature";     tough = 4;  break;
    }
    switch (random((level * 2) + 15)) {
    case 0..3:   size = "a small";   break;

    case 6..14:  size = "an average";    break;

    case 15..20: size = "a large";   break;

    case 21..25: size = "a giant";   break;

    case 26..30: size = "a magnificent"; break;

    case 31..40: size = "an enormous";   break;

    default:     size = "a large";   break;
    }

    set_short(capitalize(size) + ", " + age + " " + what);
    set_long("This is " + size + " " + age + " " + what + ", clearly a creature of the "
             "wild.  It is one of many that people hunt for sport, food, or "
             "useful body parts to use for other practical things like "
             "clothing or decoration.");
    if (what == "fowl") {
        set_short(capitalize(size) + ", " + age + " " + type);
        set_long("This is " + size + " " + age + " " + type + ", a game type bird.  "
                 "It is one of several types that people hunt for sport, for food, "
                 "or perhaps the feathers to use for things like pillow stuffing "
                 "or decorations.");
    }
    do_body(what, level, tough);
}

/* not using these arrays after all, but grouping them like this within the switch
 #define EQUINE ({"deer", "elk", "antelope", "mountain goat", "caribou", "moose", "reindeer" })
 #define TUSKS ({ "mammoth", "boar", "bison" })
 #define QUAD ({"wolf", "fox", "squirrel", "rabbit", "jackrabbit", "badger", "weasel", "lynx", "sloth", "wolverine", "groundhog", "prairie dog", "coyotte", "bear", "bobcat", "mink", "puma", "rat", "otter", "beaver", })
 */

void do_body(string what, int level, int tough)
{
    string type;
    int dam;
    dam = (level / 5) + 1;
    if (what != "fowl") {
        set_race(what);
        set_name(what);
        add_id(what);
    }
    switch (what) {
    case "fowl":
        set_hd(1 + (tough / 2), 2 + dam);
        set_stats("dexterity", 25);
        set_exp(10 * level);
        set_speed(5);
        // race set above for these with type for description
        set_body_type("fowl");
        set_attack_limbs(({ "beak", "right claw", "left claw" }));
        set_damage(1, 2 + dam);
        break;

    case "alligator":
    case "crocodile":
        set_hd(5 + tough, 8 + dam);
        set_stats("strength", 25);
        set_exp(40 * level);
        set_speed(40);
        set_body_type("reptile");
        add_limb("mouth", "head", 0, 0, 0);
        add_limb("torso", "head", 0, 0, 0);
        add_limb("tail", "torso", 0, 0, 0);
        add_limb("teeth", "mouth", 0, 0, 0);
        set_attack_limbs(({ "mouth", "tail", "teeth" }));
        set_damage(2, 4 + dam);
        set_attacks_num(2);
        break;

    case "turtle":
        set_hd(1 + (tough / 2), 4 + dam);
        set_stats("strength", 18);
        set_exp(20 * level);
        set_speed(80);
        set_body_type("reptile");
        add_limb("mouth", "head", 0, 0, 0);
        add_limb("right claws", "right forefoot", 0, 0, 0);
        add_limb("left claws", "left forefoot", 0, 0, 0);
        set_attack_limbs(({ "mouth", "left claws", "right claws" }));
        set_damage(1, 2 + dam);

    case "snapping turtle":
        add_id("turtle");
        set_hd(2 + tough, 4 + dam);
        set_damage(1, 4 + dam);
        break;

    case "giant frog":
        add_id("frog");

    case "frog":
        set_hd(1 + (tough / 2), 2 + dam);
        set_stats("dexterity", 20);
        set_exp(20 * level);
        set_speed(20);
        set_body_type("reptile");
        add_limb("mouth", "head", 0, 0, 0);
        add_limb("tongue", "mouth", 0, 0, 0);
        set_attack_limbs(({ "mouth", "head", "tongue" }));
        set_damage(1, 2 + dam);
        break;

    case "polar bear":
        add_id("bear");

    case "bear":
        set_hd(4 + tough, 8 + dam);
        set_stats("strength", 20);
        set_exp(40 * level);
        set_speed(40);
        set_body_type("quadruped");
        add_limb("teeth", "head", 0, 0, 0);
        add_limb("right claws", "right forepaw", 0, 0, 0);
        add_limb("left claws", "left forepaw", 0, 0, 0);
        set_attack_limbs(({ "teeth", "left claws", "right claws" }));
        set_damage(3, 5 + dam);
        set_attacks_num(2);
        break;

    case "water snake":
        add_id("water snake");

    case "snake":
        set_body_type("snake");
        set_hd(1 + tough, 2 + dam);
        set_exp(10 * level);
        set_speed(30);
        add_limb("fangs", "mouth", 0, 0, 0);
        set_attack_limbs(({ "fangs" }));
        set_base_damage_type("piercing");
        set_damage(1, 2 + dam);
        break;

    case "mammoth":
    case "boar":
    case "bison":
        set_body_type("equine");
        set_hd(5 + tough, 10 + dam);
        set_stats("strength", 25);
        set_exp(50 * level);
        set_speed(60);
        add_limb("tusks", "head", 0, 0, 0);
        set_attack_limbs(({ "tusks", "head", "right fore hoof", "left fore hoof" }));
        set_base_damage_type("bludgeoning");
        set_damage(3, 4 + dam);
        set_attacks_num(2);
        break;

    case "mountain goat":
        add_id("goat");

    case "deer":
    case "elk":
    case "antelope":
    case "moose":
    case "caribou":
    case "reindeer":
        set_hd(3 + tough, 6 + dam);
        set_stats("strength", 19);
        set_stats("dexterity", 22);
        set_exp(30 * level);
        set_speed(20);
        set_body_type("equine");
        add_limb("antlers", "head", 0, 0, 0);
        set_attack_limbs(({ "antlers", "head", "right fore hoof", "left fore hoof" }));
        set_base_damage_type("bludgeoning");
        set_damage(2, 3 + dam);
        set_attacks_num(2);
        break;

    case "bat":
        set_hd(1 + (tough / 2), 2 + dam);
        set_exp(10 * level);
        set_speed(6);
        set_body_type("quadruped");
        add_limb("teeth", "mouth", 0, 0, 0);
        set_attack_limbs(({ "teeth" }));
        set_base_damage_type("piercing");
        set_damage(1, 2 + dam);

    case "giant bat":
        add_id("bat");
        set_hd(2 + tough, 3 + dam);
        set_damage(1, 4 + dam);
        break;

    case "walrus":
        set_body_type("quadruped");
        set_hd(2 + tough, 10 + dam);
        set_stats("strength", 20);
        set_exp(20 * level);
        set_speed(60);
        add_limb("tusks", "head", 0, 0, 0);
        set_attack_limbs(({ "tusks", "head" }));
        set_base_damage_type("bludgeoning");
        set_damage(2, 4 + dam);
        set_attacks_num(1);
        break;

    case "mountain lion":
        add_id("lion");

    case "wolverine":
    case "lynx":
    case "bobcat":
    case "puma":
    case "mink":
    case "weasel":
    case "sloth":
    case "armadillo":
        set_hd(5 + tough, 5 + dam);
        set_exp(30 * level);
        set_speed(30);
        set_body_type("quadruped");
        add_limb("teeth", "mouth", 0, 0, 0);
        add_limb("right claws", "right forepaw", 0, 0, 0);
        add_limb("left claws", "left forepaw", 0, 0, 0);
        set_attack_limbs(({ "teeth", "right claws", "left claws" }));
        set_damage(2, 4 + dam);
        break;

    case "rabbit":
    case "squirrel":
    case "prairie dog":
    case "rat":
        set_hd(1 + (tough / 2), 1 + dam);
        set_exp(10 * level);
        set_speed(20);
        set_body_type("quadruped");
        add_limb("teeth", "mouth", 0, 0, 0);
        set_attack_limbs(({ "teeth", "head", "right forepaw", "left forepaw" }));
        set_base_damage_type("bludgeoning");
        set_damage(1, 2 + dam);
        break;

    default:
        set_hd(3 + tough, 3 + dam);
        set_exp(20 * level);
        set_speed(20);
        set_body_type("quadruped");
        add_limb("teeth", "mouth", 0, 0, 0);
        set_attack_limbs(({ "teeth", "head", "right forepaw", "left forepaw" }));
        set_base_damage_type("bludgeoning");
        set_damage(2, 3 + dam);
        break;
    }
    set_max_hp(query_hp() + (tough * 2));
    set_hp(query_max_hp());
}
