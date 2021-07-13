#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <rooms.h>

inherit WEAPONLESS;

int MULT, HEAL;


void create()
{
    object ob;

    MULT = 65; //up from 50 - odin 5/8/2020

    ::create();
    set_name("Klauth");
    set_id(({ "dragon", "red dragon", "klauth", "wyrm" }));
    set_short("%^RESET%^%^RED%^Klauth, a great wyrm red dragon%^RESET%^ ");

/*  set_long(
        "%^RESET%^%^RED%^Klauth is known by several names depending on the area"+
        " you are in. To some he is known as the %^BOLD%^%^BLACK%^Terror of the Seas%^RESET%^%^RED%^ and to"+
        " others he is known by names such as %^BOLD%^%^BLACK%^The Bringer of Death%^RESET%^%^RED%^ or even %^BOLD%^%^BLACK%^The Tyrant of the skies.%^RESET%^%^RED%^"+
        " Regardless of who you are, one thing remains constant; Klauth is a force to"+
        " be reckoned with and feared. He resides on the top of this mountain and considers"+
        " all within his sight to be his property. This would explain his constant attacks on"+
        " ships in this area. Klauth is one of the oldest dragons known to"+
        " exist and his physical condition shows evidence of such a fact."+
        " He is at least 400 feet long and has a wing span of nearly 500 feet."+
        " His dull red scales are large, thick, and as hard as steel."+
        " His neck frill and wings are ash blue in color towards the edges."+
        " His pupiless eyes bring images of molten lava orbs to mind.");        */

// new crayoning, thanks Aurgloroasa! N, 11/17.
    set_long("%^RESET%^%^RED%^Depending on the area, this titan is known "
             "by many names - %^BLUE%^Terror of the %^BOLD%^%^BLUE%^S"
             "%^WHITE%^e%^GREEN%^a%^CYAN%^s%^RESET%^%^RED%^, the "
             "%^BOLD%^%^BLACK%^Bringer of Death%^RESET%^%^RED%^, even the "
             "%^BOLD%^%^BLACK%^Tyrant of the %^RESET%^%^WHITE%^S%^CYAN%^k"
             "%^BOLD%^%^WHITE%^i%^RESET%^es%^RED%^. Regardless of who you may "
             "be, however, his name is universally known and feared: "
             "%^YELLOW%^%^B_RED%^Klauth%^RESET%^%^RED%^. "
             "He is massive even by dragon standards, having survived to the "
             "age mortals regard as a %^BOLD%^%^RED%^great wyrm%^RESET%^%^RED%^."
             " At least four hundred feet in length, you can't even see the "
             "entirety of his bulk, partially hidden by his wings and neck "
             "frills. That he has lived to his age is impressive in itself. The "
             "most infamous of chromatics, red dragons seldom tolerate others of "
             "their kind, let alone other reds, seeking conflict whenever another's"
             " existence is discovered - a cowardly red dragon does not exist, and "
             "it is obvious that Klauth has faced many a wyrm. The battles that "
             "this ancient beast have faced are clearly evident. Though keen of "
             "claw and fang, and powerfully muscled, the scars of countless "
             "conflicts are scattered across his body, scales even torn away "
             "completely in places. Klauth's wings lay folded against his sides, "
             "and even relaxed as they are there is no doubt in your mind they "
             "would span at least five hundred feet. Pupilless eyes like "
             "%^BOLD%^%^RED%^bu%^BLACK%^r%^RED%^n%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n"
             "%^RED%^g %^BLACK%^c%^RED%^o%^WHITE%^a%^BLACK%^ls %^RESET%^%^RED%^glare"
             " upon you from his horselike head with unabated fury. A single pair "
             "of recurving %^BOLD%^%^WHITE%^iv%^RESET%^o%^BOLD%^ry h%^RESET%^or"
             "%^BOLD%^ns %^RESET%^%^RED%^sweep back from his head, set in a crown "
             "of frills that fade to an %^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^s%^WHITE%^h"
             "%^CYAN%^e%^RESET%^%^CYAN%^n b%^BLUE%^l%^BOLD%^%^BLUE%^u"
             "%^RESET%^%^CYAN%^e %^RED%^toward their edges. %^BOLD%^%^RED%^F"
             "%^RESET%^%^ORANGE%^l%^YELLOW%^a%^WHITE%^m%^RESET%^%^ORANGE%^e"
             "%^BOLD%^%^RED%^s %^RESET%^%^RED%^spew from between the wicked fangs of"
             " his snarling maw, igniting the ground even as he advances on you with"
             " earth-shattering steps.");

    set_gender("male");
    set_race("dragon");
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_guild_level("fighter", MULT);
    set_guild_level("mage", MULT);
    set_guild_level("cleric", MULT);
    set_mlevel("fighter", MULT);
    set_mlevel("mage", MULT);
    set_mlevel("cleric", MULT);
    set_alignment(9);

    set_hd(MULT, 10);
    set_hp(MULT * 2000);
    set_new_exp(MULT, "boss");
    set_overall_ac(-55); //up from 35

    set_body_type("dragon");
    set_attack_limbs(({ "right claw", "left claw", "mouth", "tail" }));

    set_hit_funcs(([ "right claw" : (: TO, "pounce" :), "left claw" : (: TO, "pounce" :), "mouth" : (: TO, "rush" :), "tail" : (: TO, "sweep" :) ]));

    set_attacks_num(2); // done via specials
    set_damage(10, 20);
    set_base_damage_type("slashing");

    set_property("weapon resistance", 0);
    set_mob_magic_resistance("average");
    set_property("no death", 1);
    set_property("no knockdown", 1);
    set_property("no trip", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 0);
    set_property("no stun", 0);
    set_property("no bows", 1);

    set_monster_feats(({
        "spell penetration", "greater spell penetration"
    }));

    set_property("added short", ({ "%^RESET%^%^BOLD%^%^BLUE%^ (%^BOLD%^%^YELLOW%^ Legendary Champion%^RESET%^%^BOLD%^%^BLUE%^ )%^RESET%^" }));

    set_funcs(({ "decision" }));

    set_func_chance(200);

    set_skill("perception", 50); //make it stabbable by a highly skilled thief so they're not useless. Nienne, 04/10.

    set_resistance("fire", MULT);
    set_property("cast and attack", 1);
    set_property("function and attack", 1);
    //set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^"); // use this for items for this quest.
    set_property("add quest", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("quest exp", 10000000);

    add_money("gold", random(100000) + (MULT * 1000));
    add_money("platinum", random(20000) + (MULT * 500));

    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("heart of an ancient wyrm");
    ob->move(TO);
}

void cm(string str)
{
    return CRAYON_D->color_string(str, "fire red");
}

int query_paralyzed()
{
    return 0;
}

int query_tripped()
{
    return 0;
}

void init()
{
    ::init();
    if (!objectp(TO)) {
        return;
    }

    add_action("no_cast", "toss");
    add_action("no_cast", "throw");

    if (base_name(TP) == "/d/token_hunt/token_monster") {
        TP->move("/d/shadowgate/void");
        TP->remove();
    }else {
        if (!avatarp(TP)) {
            TO->force_me("kill " + TP->query_name() + "");
        }
    }
}

int no_cast(string str)
{
    if (!objectp(TO) || !objectp(TP)) {
        return 0;
    }

    tell_object(TP, "The dragon sends you a frightful glare and freezes your action!");
    return 0;
}

// picks the highest health target when the dragon is above 15% health
// switches to the lowest health target when the dragon is below 15% health
// should be current hitpoints, not max hitpoints.
object pick_target()
{
    mapping health = ([]);
    int i, * hps;
    object* attackers, lowest, highest, * ppl;

    if (!objectp(TO)) {
        return;
    }

    attackers = get_attackers();
    if (!sizeof(attackers)) {
        return 0;
    }

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        health += ([ attackers[i] : attackers[i]->query_hp() ]);
    }

    ppl = keys(health);
    hps = values(health);

    if (!sizeof(ppl)) {
        return 0;
    }

    for (i = 0; i < sizeof(hps); i++) {
        if (!objectp(lowest)) {
            lowest = ppl[i];
        }
        if (!objectp(highest)) {
            highest = ppl[i];
        }
        if (hps[i] < lowest->query_hp()) {
            lowest = ppl[i];
        }
        if (hps[i] > highest->query_hp()) {
            highest = ppl[i];
        }
    }

    if (!objectp(highest)) {
        return 0;
    }
    if (!objectp(lowest)) {
        return 0;
    }

    if (TO->query_hp_percent() > 15) {
        return highest;
    }
    return lowest;
}

// picks a target completely at random
object pick_random_target()
{
    object* attackers;
    if (!objectp(TO)) {
        return 0;
    }

    attackers = get_attackers();

    if (!sizeof(attackers)) {
        return 0;
    }
    return attackers[random(sizeof(attackers))];
}

// picks the target with the most spells on it
object pick_spelled_target()
{
    object* attackers, obj;
    int i;
    if (!objectp(TO)) {
        return 0;
    }

    attackers = get_attackers();
    if (!sizeof(attackers)) {
        return 0;
    }

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        if (!objectp(obj)) {
            obj = attackers[i];
        }
        if (sizeof(attackers[i]->query_property("spelled")) > sizeof(obj->query_property("spelled"))) {
            obj = attackers[i];
        }
    }
    if (!objectp(obj)) {
        return 0;
    }
    return obj;
}

// returns 1 if obj has name spell active
int has_spell(object obj, string name)
{
    object* spells;
    int i;

    if (!objectp(obj)) {
        return 0;
    }

    if (!name || !stringp(name) || !strlen(name)) {
        return 0;
    }

    spells = obj->query_property("spelled");
    if (!sizeof(spells)) {
        return 0;
    }
    for (i = 0; sizeof(spells), i < sizeof(spells); i++) {
        if (!objectp(spells[i])) {
            continue;
        }
        if (spells[i]->query_spell_name() == name) {
            return 1;
        }
    }

    return 0;
}

object* get_attackers()
{
    object* attackers;

    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    attackers = all_living(ETO);
    attackers = filter_array(attackers, "is_non_immortal", FILTERS_D);
    attackers -= ({ TO });
    attackers -= ({ 0 });

    return attackers;
}

// scales up the dragon's health, another 1k hitpoints for
// each player in the room
//upping to 2k - Odin 5/8/2020
void scale_me(int num)
{
    if (!objectp(TO)) {
        return;
    }
    if (!num) {
        return;
    }

    if (TO->query_property("scale") >= num) {
        return;
    }

    TO->remove_property("scale");
    TO->set_property("scale", num);

    TO->set_max_hp(TO->query_max_hp() + (2000 * num));
    TO->add_hp((2000 * num));
    HEAL = num;
    return;
}

void db(string str)
{
    object ob;
    ob = find_object_or_load("/realms/nuwisha/workroom.c");
    if (objectp(ob)) {
        tell_room(ob, str);
    }
    return;
}

// decides what to do.  If there is more fodder in the room
// than there are players, the dragon will focus on AoE abilities
// Otherwise, the dragon will focus on single target abilities and melee
void decision()
{
    object* attackers, * players = ({}), * fodder = ({});
    int i;

    if (!objectp(TO)) {
        return;
    }
    if (!sizeof(TO->query_attackers())) {
        return;
    }

    attackers = get_attackers();

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        if (interactive(attackers[i])) {
            players += ({ attackers[i] });
            continue;
        }

        fodder += ({ attackers[i] });
        continue;
    }

    scale_me(sizeof(players));

    if (!has_spell(TO, "fire storm")) {
        fire_storm();
        return;
    }

    if (sizeof(fodder) > sizeof(players)) { // AoE specials
        switch (random(3)) {
        case 0:

            if (TO->query_property("breath timer") < time()) {
                breath_weapon();
                return;
            }
        // this falls through intentionally

        case 1:

            if (TO->query_property("earthquake timer") < time()) {
                earthquake();
                return;
            }
        // this falls through intentionally

        default:

            aoe_spell();
            return;
        }
        return;
    }else {
        single_target_spell();
    }

    return;
}

// execute melee attacks in a function, so we can better control how often
// they happen, since each limb is tied to a pretty nasty special when
// the dragon attacks.
void attacks()
{
    if (!objectp(TO)) {
        return;
    }

    if (!sizeof(TO->query_attackers())) {
        return;
    }
    TO->execute_attack();
    TO->execute_attack();
    TO->execute_attack();
    TO->execute_attack();
    return;
}

// should try to keep fire storm going throughout the battle
// it should be cast at high enough level that the players will
// have a hard time dispelling it.  It should also do enough
// damage that the player is going to need some substantial
// healing over time just to keep up with firestorm and bladebarrier damage
void fire_storm()
{
    if (!objectp(TO)) {
        return;
    }
    new("/cmds/spells/f/_fire_storm.c")->use_spell(TO, 0, MULT, 100, "cleric");  //both of these were static 50, set to MULT - Odin 5/8/2020
    new("/cmds/spells/b/_blade_barrier.c")->use_spell(TO, 0, MULT, 100, "cleric");
    attacks();
    return;
}

// puts the exit back after the dragon finishes murdering the shit out of people
void restore_exit()
{
    object obj;

    if (!objectp(TO)) {
        return;
    }
    if (TO->query_hp() > 0 && sizeof(TO->query_attackers())) {
        return;
    }

    obj = find_object_or_load("/d/islands/common/aramanth/mountain10");
    if (obj->query_exit("top") == ROOM_VOID) {
        tell_room(obj, "%^CYAN%^Some mighty force from within the mountaintop sends the heaped stones "
                  "flying, revealing an entry to a lair at the very peak.");
        obj->add_exit("/d/islands/common/aramanth/mountain11", "top");
    }

    return;
}

// heals the dragon each round based on the number of players in the room
// amount healed is currently 100 hp per round, per player.  Might have
// to do some tweaking
void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }

    if (TO->query_hp() < 0) {
        return;
    }

    if (TO->query_hp() < TO->query_max_hp()) {
        TO->add_hp(HEAL * 100); // heals hp per round for each player in the room
    }

    TO->force_me("get kit");
    TO->force_me("drink kit");
    TO->force_me("drink kit");
    TO->force_me("drink kit");
    TO->force_me("drink kit");

    if (!sizeof(TO->query_attackers())) {
        call_out("restore_exit", ROUND_LENGTH * 3);
    }
}

void die(object obj)
{
    object* ppl, room, * killers = ({});
    int i;
    int eventpower = 1; // Yes, one.

    message("info", "%^BOLD%^%^RED%^A mighty roar follows the rumble of the earth as Klauth has fallen from his mountain!%^RESET%^", users());
    WORLD_EVENTS_D->kill_event("Klauth has been defeated");
    WORLD_EVENTS_D->inject_event((["Klauth has been defeated" : (["start message" : "%^BOLD%^%^RED%^The great wyrm has been defeated!", "event type" : "exp bonus", "length" : 720, "notification" : eventpower + "% Bonus Exp", "event name" : "Klauth has been defeated", "modifier" : eventpower, "announce" : 1, "announce to" : "world" ]), ]));

    ppl = all_living(ETO);
    ppl -= ({ TO });
    for (i = 0; sizeof(ppl), i < sizeof(ppl); i++) {
        if (!objectp(ppl[i])) {
            continue;
        }
        if (!interactive(ppl[i])) {
            continue;
        }
        if (avatarp(ppl[i])) {
            continue;
        }
        killers += ({ ppl[i] });
    }

    log_file("player/klauth", "Klauth was killed by: " + identify(killers) + "\n");

    tell_room(ETO, "\n%^BOLD%^%^RED%^A thrilling sense of accomplishment runs through you as you realise "
              "the great red wyrm Klauth has fallen to your hand!%^RESET%^\n");

    room = find_object_or_load("/d/islands/common/aramanth/treasurevault");
    tell_room(ETO, "At the death of the dragon, a portal opens up, leading elsewhere, but it looks unstable as if it will close at any time.");
    ETO->set_had_players(72 * 4); // 72 hours, hopefully, not sure our resets are actually 15 minutes each
    room->set_had_players(71 * 4);
    ETO->add_exit("/d/islands/common/aramanth/treasurevault", "portal");
    room->activate_lewt();
    ::die(obj);
    return;
}

////////////////////////////
// Single Target Specials //
////////////////////////////

void single_target_spell() // always cast two
{
    object targ, obj;
    int i;

    if (!objectp(TO)) {
        return;
    }
    targ = pick_target();
    if (!objectp(targ)) {
        return;
    }

    // these cases fall through on purpose in the event that they don't find an
    // appropriate target
    switch (random(16)) {
    case 0: // fog cloud

        if (TO->query_hp_percent() < 10) {
            new("/cmds/spells/f/_fog_cloud.c")->use_spell(TO, 0, MULT, 65, "mage");
            break;
        }

    case 1: // phantom guardians

        if (!has_spell(TO, "phantom guardians")) {
            new("/cmds/spells/p/_phantom_guardians.c")->use_spell(TO, "soldiers", MULT, 100, "mage");
            break;
        }

    case 2: // shield

        if (!has_spell(TO, "shield")) {
            new("/cmds/spells/s/_shield.c")->use_spell(TO, TO, MULT, 100, "mage");
            break;
        }

    case 3: // spell turning

        if (!has_spell(TO, "spell turning")) {
            new("/cmds/spells/s/_spell_turning.c")->use_spell(TO, TO, MULT, 100, "mage");
            break;
        }

    case 4: // berserker

        if (!has_spell(TO, "frightful aspect")) {
            new("/cmds/spells/f/_frightful_aspect.c")->use_spell(TO, TO, MULT, 100, "mage");
            break;
        }

    case 5: // blindness

        i = 0;
        while (objectp(targ) && targ->query_blind() && i < 10) {
            i++;
            targ = pick_random_target();
        }

        if (!objectp(targ)) {
            targ = pick_target();
        }

        if (objectp(targ) && !targ->query_blind()) {
            new("/cmds/spells/b/_blindness.c")->use_spell(TO, targ, MULT, 100, "mage");
            break;
        }

    case 6: // ray of enfeeblement

        i = 0;
        while (objectp(targ) && targ->query_property("enfeebled") && i < 10) {
            i++;
            targ = pick_random_target();
        }

        if (!objectp(targ)) {
            targ = pick_target();
        }

        if (objectp(targ) && !targ->query_property("enfeebled")) {
            new("/cmds/spells/r/_ray_of_enfeeblement.c")->use_spell(TO, targ, MULT, 100, "mage");
            break;
        }

    case 7: // powerword stun

        i = 0;
        obj = new("/cmds/spells/p/_powerword_stun.c");
        while (objectp(targ) && targ->query_paralyzed() && i < 10 && obj->mind_immunity_check(targ, "silent")) {
            i++;
            targ = pick_random_target();
        }

        if (!objectp(targ)) {
            targ = pick_target();
        }

        if (objectp(targ) && !targ->query_paralyzed() && !obj->mind_immunity_check(targ, "silent")) {
            new("/cmds/spells/p/_powerword_stun.c")->use_spell(TO, targ, MULT, 100, "mage");
            obj->dest_effect();
            break;
        }

        if (objectp(obj)) {
            obj->dest_effect();
        }

    case 8: // lightning bolt

        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/l/_lightning_bolt.c")->use_spell(TO, targ, MULT, 100, "cleric");
        break;

    case 9: // was flameburst, changing to polar ray

        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/p/_polar_ray.c")->use_spell(TO, targ, MULT, 100, "mage");
        break;

    case 10: // mind fog

        targ = pick_spelled_target();
        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/m/_mind_fog.c")->use_spell(TO, targ, MULT, 100, "mage");
        break;

    case 11: // greater dispel magic

        targ = pick_spelled_target();
        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/g/_greater_dispel_magic.c")->use_spell(TO, targ, MULT - 15, 100, "mage");
        break;

    case 12: // chill touch

        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/c/_chill_touch.c")->use_spell(TO, targ, MULT, 100, "mage");
        break;

    case 13: // resonating word

        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/r/_resonating_word.c")->use_spell(TO, targ, MULT, 100, "mage");
        break;

    default: // disintegrate

        if (!objectp(targ)) {
            targ = pick_target();
        }
        if (!objectp(targ)) {
            break;
        }
        new("/cmds/spells/d/_disintegrate.c")->use_spell(TO, targ, MULT, 100, "mage");
        break;
    }

    attacks();
    return;
}

////////////////////////////////
// End Single Target Specials //
////////////////////////////////


//////////////////
// AoE Specials //
//////////////////

// this does several small doses of fire instead of one bit fire hit
// damages equipment on a failed save
void do_inferno(int count)
{
    object* attackers, targ, * inv;
    int i, j, x, damage;

    if (!objectp(TO)) {
        remove_call_out("do_inferno");
        return;
    }

    if (count > 12) {
        tell_room(ETO, cm("The whole world must be on fire!  Flames burn everything in sight and it's almost impossible to see or to breathe!"));
        tell_room(ETO, cm("The colossal ancient wyrm's maw snaps shut with such force that you can feel the shockwave hit your chest!"));
        tell_room(ETO, cm("Mercifully, the cataclysmic fire has stopped...  until he breathes again!"));
        return;
    }

    attackers = get_attackers();

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }

        targ = attackers[i];
        damage = (MULT + roll_dice(1, MULT)); // fire resistance is very high so I'm dramatically increasing the damage of this

        if (targ->reflex_save(MULT/5 + 23)) {
            if (FEATS_D->usable_feat(targ, "evasion")) {
                tell_object(targ, cm("You dive and twist, dodge and evade for everything you're worth, and you manage to avoid the flames!"));
                continue;
            }

            tell_object(targ, cm("You dive out of the way of the worst of the conflagration, but are still burned!"));
            targ->cause_typed_damage(targ, targ->return_target_limb(), damage / 2, "fire");
            continue;
        }

        /*inv = all_inventory(targ);
           for (j = 0; sizeof(inv), j < sizeof(inv); j++) {
            if (!objectp(inv[j])) {
                continue;
            }
            if (!inv[j]->query_short()) {
                continue;
            }
            if (inv[j]->query_property("no detect")) {
                continue;
            }
            for (x = 0; x < roll_dice(1, 6); x++) {
                inv[j]->decay();
            }
           }*/

        tell_object(targ, cm("You can't get out of the way in time and you are burned by the full force of the inferno!"));
        targ->cause_typed_damage(targ, targ->return_target_limb(), damage, "fire");
        continue;
    }

    count++;
    call_out("do_inferno", 0.3, count);
    return;
}

void breath_weapon()
{
    if (!objectp(TO)) {
        return;
    }

    if (TO->query_property("breath timer") > time()) {
        decision();
        return;
    }
    TO->remove_property("breath timer");
    TO->set_property("breath timer", (ROUND_LENGTH * 10) + time());

    tell_room(ETO, cm("Klauth raises his head and the whole mountain seems to shake along with his mighty form."));
    tell_room(ETO, cm("The ancient wyrm lowers his head as his huge maw opens wide and a steel melting inferno of fire pours forth!"));
    tell_room(ETO, cm("The whole mountaintop boils in a cauldron of liquid fire, small stones pop and explode into dust and boulders melt into magma!"));

    call_out("do_inferno", 0.2, 0); // several small doses of fire for visual effect and to make fire resistance more important
    return;
}

void earthquake()
{
    object* attackers, targ, ob;
    int i, damage;

    if (!objectp(TO)) {
        return;
    }

    TO->remove_property("earthquake timer");
    TO->set_property("earthquake timer", (ROUND_LENGTH * 10) + time());

    attackers = get_attackers();

    tell_room(ETO, "%^RESET%^%^ORANGE%^The dragon jumps up and lands hard on the mountain, causing a violent rumble%^RESET%^!");

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        targ = attackers[i];
        damage = roll_dice(MULT, 5);

        if (targ->reflex_save(MULT/5 + 23)) {
            if (FEATS_D->usable_feat(targ, "evasion")) {
                tell_object(targ, "%^RESET%^%^ORANGE%^You jump and spin in the air, managing to avoid the worst of the tumbling rubble and shaking ground!");
                continue;
            }

            tell_object(targ, "%^RESET%^%^ORANGE%^You manage to avoid the worst of the shaking earth, but still loose your footing!");
            targ->set_tripped(1, "%^BOLD%^%^BLUE%^You are shaken and trying to regain your footing!%^RESET%^", 1);
            targ->cause_typed_damage(targ, targ->return_target_limb(), damage / 2, "bludgeoning");
            continue;
        }
        tell_object(targ, "%^BOLD%^%^RED%^The rumble sends you flying to the ground!%^RESET%^");
        targ->set_tripped(3, "%^BOLD%^%^BLUE%^You are shaken and trying to regain your footing!%^RESET%^", 3);
        targ->cause_typed_damage(targ, targ->return_target_limb(), damage, "bludgeoning");
    }

    if (!query_property("exit")) {
        ob = find_object_or_load("/d/islands/common/aramanth/mountain10");
        ob->remove_exit("top");
        tell_room(ETO, "%^BOLD%^%^RED%^The violent rumbling causes rocks to split apart and tumble down!!!%^RESET%^");
        tell_room(ob, "The stairs leading up are suddenly covered in rubble.");
        TO->set_property("exit", 1);
    }

    return;
}

// cast a ton of spells at MULT / 2 to scare the shit out of the players
void spell_frenzy(int count)
{
    object targ;

    if (!objectp(TO)) {
        remove_call_out("spell_frenzy");
        return;
    }
    targ = pick_target();
    if (!objectp(targ)) {
        remove_call_out("spell_frenzy");
        return;
    }

    TO->remove_property("frenzy timer");
    TO->set_property("frenzy timer", (ROUND_LENGTH * 10) + time());

    if (count == 0) {
        TO->force_me("speech growl in a thunderous roar");
        TO->force_me("say I WILL END YOU, MORTALS!");
    }

    if (count > 10) {
        TO->force_me("speech growl in a thunderous roar");
        TO->force_me("say FEAR MY WRATH!");
        return;
    }

    switch (random(20)) {
    case 0..8:      new("/cmds/spells/b/_burning_hands.c")->use_spell(TO, targ, (MULT / 2), 100, "mage");        break;

    case 9..10:     new("/cmds/spells/c/_chain_lightning.c")->use_spell(TO, targ, (MULT / 2), "mage"); break;

    case 11..16:    new("/cmds/spells/l/_lightning_bolt.c")->use_spell(TO, targ, (MULT / 2), "mage");    break;

    default:        new("/cmds/spells/p/_prismatic_spray.c")->use_spell(TO, targ, (MULT / 2), "mage"); break;
    }

    count++;
    call_out("spell_frenzy", 0.3, count);
    return;
}

void aoe_spell()
{
    object targ;

    if (!objectp(TO)) {
        return;
    }
    targ = pick_target();
    if (!objectp(targ)) {
        return;
    }

    switch (random(24)) {
    case 0..8:      new("/cmds/spells/f/_fireball.c")->use_spell(TO, targ, MULT, 100, "mage");        break;

    case 9..10:     new("/cmds/spells/c/_chain_lightning.c")->use_spell(TO, targ, MULT, 100, "mage"); break;

    case 11..16:    new("/cmds/spells/w/_web.c")->use_spell(TO, targ, MULT, 100, "mage");    break;

    case 17..18:    new("/cmds/spells/p/_prismatic_spray.c")->use_spell(TO, targ, MULT, 100, "mage"); break;

    case 19..21:    new("/cmds/spells/w/_wail_of_the_banshee.c")->use_spell(TO, 0, MULT, 100, "mage");            break;

    default:
        if (TO->query_property("frenzy timer") < time()) {
            call_out("spell_frenzy", 0.2, 0);
        }else {
            single_target_spell(0);
            attacks();
        }
        break;
    }

    attacks();
    return;
}

//////////////////////
// End AoE Specials //
//////////////////////


///////////////////////////
// melee attack specials //
///////////////////////////

void pounce() // claw attack
{
    object targ;
    int i;

    targ = pick_target();

    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }

    tell_room(ETO, "%^BOLD%^%^BLACK%^Klauth leaps off the ground and pounces over " + targ->QCN + " and delivers several slashes with his claws!%^RESET%^", targ);
    tell_object(targ, "%^BOLD%^%^BLACK%^The dragon leaps off the ground and pounces over you!%^RESET%^");

    for (i = 0; i < roll_dice(1, 3) + 1; i++) {
        tell_object(targ, "%^BOLD%^%^BLACK%^The dragon slashes you!%^RESET%^");
        targ->do_damage(targ->return_target_limb(), roll_dice(6, 10) + MULT);
    }
    return roll_dice(3, 20);
}

void rush() // mouth attack
{
    object targ;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }


    tell_room(ETO, "%^BOLD%^%^WHITE%^Klauth snaps his huge maw around and clamps visciously down on " + targ->QCN + "!%^RESET%^", targ);
    tell_object(targ, "%^BOLD%^%^WHITE%^Klauth snaps his huge maw around and clamps visciously down on you!%^RESET%^");
    targ->do_damage(targ->return_target_limb(), random(90) + 90 + MULT);

    return roll_dice(3, 20);
}

void sweep() // tail
{
    object* attackers, targ;
    int i, damage;

    if (!objectp(TO)) {
        return;
    }

    attackers = get_attackers();

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        targ = attackers[i];
        damage = roll_dice(3, 40) + 40 + MULT;

        if (targ->reflex_save(MULT/5 + 23)) {
            if (FEATS_D->usable_feat(targ, "evasion")) {
                tell_object(targ, "You dive out of the way, avoiding the dragon's dangerous tail!");
                continue;
            }

            tell_object(targ, "You dive over the dragon's tail but are clipped at the last instant, sending you flying!");
            targ->cause_typed_damage(targ, targ->return_target_limb(), damage / 2, "bludgeoning");
            continue;
        }

        tell_object(targ, "%^BOLD%^%^CYAN%^The dragon snaps it's tail like a whip, then strikes out at you with lightning quickness!%^RESET%^");
        targ->do_damage(targ->return_target_limb(), damage);
    }
    return roll_dice(3, 20);
}

///////////////////////////////
// end melee attack specials //
///////////////////////////////
