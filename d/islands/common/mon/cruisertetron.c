// code/difficulty update 03/19/17 -Ares
#include <std.h>
#include <daemons.h>
#include <rooms.h>

inherit MONSTER;
int rcount = 0;

void create()
{
    object obj;
    ::create();
    set_name("Cruiser Tetron");
    set_id(({ "Cruiser Tetron", "cruiser tetron", "cruisertetron", "tetron", "cruiser" }));
    set_short("%^BOLD%^%^BLUE%^Cruiser Tetron");
    set_long("Cruiser Tetron is an ancient warrior of immense power.  He was at one time "
             "the harbringer of Autarkis.  During a confrontation with Lord Thundercracker of the "
             "Dark Dominion, Cruiser Tetron was defeated as was eventually Autarkis.  Cruiser Tetron "
             "was banished to this netherworld to rot...  He has not the power to pass through the "
             "portal as it is sealed to his own heartbeat.");
    set_race("human");
    set_gender("male");
    set_class("fighter");
    set_hd(60, 6);
    set_size(3);
    set_overall_ac(-20);
    set_property("magic", 1);
    set_max_hp(14000);
    set_hp(14000);
    set_property("swarm", 1);
    set_property("no death", 1);
    set_property("no blind", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no knockdown", 1);
    set_property("magic", 1);
    set_stats("strength", 30);
    set_stats("dexterity", 30);
    set_stats("constitution", 30);
    set("aggressive", "aggfunc");
    set_mob_magic_resistance("very high");
    set_property("damage resistance", 20);
    set_property("spell damage resistance", 40);
    set_new_exp(60, "boss");
    set_funcs(({ "freeze",
                 "fire",
                 "kiss",
                 "light",
                 "light",
                 "light",
                 "impaler",
                 "tornado",
                 "healing",
                 "bolt",
                 "circle",
                 "circle",
                 "circle",
                 "desoul" }));
    set_func_chance(101);

    set_attacks_num(10);

    set_property("cast and attack", 1);
    set_property("function and attack", 1);

    add_money("gold", 80000 + random(60000));

    new("/d/islands/common/obj/harbinger.c")->move(TO);
    command("wear plate");

    new("/d/islands/common/obj/dragon_greaves.c")->move(TO);
    command("wear greaves");

    new("/d/attaya/obj/axe.c")->move(TO);
    command("wield axe");

    set_monster_feats(({ "spell reflection", "parry" }));

    set_property("add quest", "%^RESET%^%^YELLOW%^Returned the Dominion Warrior to eternal rest.%^RESET%^");
    set_property("quest exp", 5000000);
    set_skill("athletics", 20); //upping from 10, which makes parry chance seem low
}

object get_targ()
{
    object* attackers, obj;
    int i;
    attackers = TO->query_attackers();
    attackers = filter_array(attackers, "is_non_immortal_player", FILTERS_D);
    if (sizeof(attackers)) {
        while (!objectp(obj) && i < 10) {
            obj = attackers[random(sizeof(attackers))];
            i++;
        }
    }
    if (!objectp(obj)) {
        return TO->query_current_attacker();
    }
    return obj;
}

void die(object ob)
{
    int eventpower;

    if (!random(5)) {
        new("/d/common/obj/misc/tools/portable_scrying_mirror.c")->move(TO);
    }

    eventpower = 10 + random(15);
    tell_room(ETO, "%^BOLD%^%^RED%^Cruiser Tetron tells you: %^RESET%^Be warned...  After a time, death itself dies...");
    tell_room(ETO, "%^BOLD%^%^CYAN%^Cruiser Tetron whispers to you: %^RESET%^Perhaps, death is better.");
    ETO->set_had_players(10);
    message("info", "%^RESET%^%^BLUE%^A dull thud sends tremors through your body as the %^YELLOW%^Dominion Warrior%^RESET%^%^BLUE%^ is returned to rest.%^RESET%^", users());
    WORLD_EVENTS_D->kill_event("Disturbed The Dominion Warrior");
    WORLD_EVENTS_D->inject_event((["Laid The Dominion Warrior To Rest" : (["start message" : "%^RESET%^%^BLUE%^The %^YELLOW%^Dominion Warrior%^RESET%^%^BLUE%^ " +
                                                                           "has been laid to rest... %^BOLD%^%^BLACK%^for now%^RESET%^%^BLUE%^. Power seeps out into the world and you feel your knowledge increased!! " +
                                                                           "For the next three hours all experience gained will award an additional %^BOLD%^%^CYAN%^" + eventpower + "%%^RESET%^%^BLUE%^!",
                                                                           "event type" : "exp bonus", "length" : 180, "notification" : eventpower + "% Bonus Exp",
                                                                           "event name" : "Laid The Dominion Warrior To Reset", "modifier" : eventpower, "announce" : 1, "announce to" : "world" ]), ]));
    ::die(ob);
    return;
}

int no_cast(string str)
{
    object targ;
    if (!objectp(TP)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    targ = TP;

    command("say You are a weak, pathetic little fool, " + TP->QCN + ". ");
    command("say Proceed...  on your way to oblivion.");

    tell_object(targ, "%^BLUE%^Cruiser Tetron pulls out an ancient parchment with a pentagram burned into its surface.");
    tell_object(targ, "%^BOLD%^%^RED%^He presses it against your forehead and a horrible pain rips through your body");
    tell_room(ETO, "%^BLUE%^Cruiser Tetron pulls out an ancient parchment and presses it against the forehead of " + targ->QCN + "!", targ);
    tell_room(ETO, "" + targ->QCN + " screams in pain and reaches out to you for help!", targ);
    TO->set_property("noMissChance", 1);
    targ->do_damage("torso", roll_dice(30, 10));
    TO->set_property("noMissChance", -1);
    return 1;
}

int aggfunc()
{
    string mrace = TP->query_race();
    if (mrace == "undead") {
        force_me("say Greetings, kindred.");
        return 1;
    }else {
        TP->kill_ob(TO, 0);
        TO->kill_ob(TP, 0);
        force_me("say %^RED%^Asleep for five thousand years and not dead yet...  What makes you think that you can kill me?!");
        return 1;
    }
}

void impaler(object targ)
{
    string dam;
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (targ->fort_save(35)) {
        dam = "hurts";
    }else {
        dam = "impales";
    }

    tell_object(targ, "%^BOLD%^%^MAGENTA%^ Cruiser Tetron charges towards you and " + dam + " you with his battleaxe!");
    tell_room(ETO, "%^MAGENTA%^Cruiser Tetron charges with his battleaxe and impales " + targ->QCN + "!%^RESET%^", targ);
    if (dam == "impales") {
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(20, 15), "piercing");
        TO->set_property("noMissChance", -1);
        tell_object(targ, "%^RED%^You feel intense pain and your ability to fight has been compromised!");
        targ->set_paralyzed(8, "%^MAGENTA%^You are in too much agony..");
    }else {
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(10, 10), "piercing");
        TO->set_property("noMissChance", -1);
    }
    return 1;
}

void fire(object targ)
{
    string dam;
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (targ->reflex_save(35)) {
        dam = "singes";
    }else {
        dam = "incenerates";
    }

    tell_object(targ, "%^BOLD%^%^RED%^Cruiser Tetron begins to glow.  Phantom fire flashes about you and " + dam + " you!%^RESET%^");
    tell_room(ETO, "Cruiser Tetron casts %^RED%^phantom fire at " + targ->QCN + "!%^RESET%^", targ);
    if (dam == "incenerates") {
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(20, 10), "fire");
        TO->set_property("noMissChance", -1);
        tell_object(targ, "%^BOLD%^You are blinded by a brilliant light and intense heat!");
        targ->set_paralyzed(random(3) * 8, "%^YELLOW%^You cannot see your opponent and stumble around blindly!%^RESET%^");
        targ->set_blind(1);
    }else {
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(10, 10), "fire");
        TO->set_property("noMissChance", -1);
    }

    return;
}

void healing(object ob)
{
    object* live;
    int count;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }

    live = all_living(ETO);
    live -= ({ TO });
    live = filter_array(live, "is_non_immortal", FILTERS_D);
    count = sizeof(live);
    count = count > 5 ? 5 : count;

    tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ I did not sleep for five thousand years to be taken down that easily..%^RESET%^");
    tell_room(ETO, "%^GREEN%^Cruiser Tetron touches his fingers to his forehead and mutters a chant.");

    switch (count) {
    case 0..2:

        tell_room(ETO, "%^BOLD%^Cruiser Tetron's wounds begin to heal themselves.");
        TO->add_hp(1000);
        break;

    default:
        tell_room(ETO, "%^B_BLUE%^%^BOLD%^Crusier Tetron draws on the strength of the life around him and his wounds heal rapidly%^RESET%^");
        TO->add_hp(400 * count);
        break;
    }
    return;
}

void circle(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }
    tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ Die, insect.%^RESET%^");
    tell_room(ETO, "Cruiser Tetron unwields Battleaxe of the Dominion (wielded in right hand and left hand).");
    tell_room(ETO, "%^RED%^Cruiser Tetron gives a smug smile as a dagger " +
              "in his possession begins screaming.%^RESET%^");
    tell_room(ETO, "Cruiser Tetron wields %^BOLD%^%^RED%^Horrible screaming dagger%^RESET%^");
    tell_room(ETO, "%^RED%^The dagger wielded by Cruiser Tetron screams horribly " +
              "as it slashes " + targ->QCN + "'s body, spattering blood everywhere!%^RESET%^", ({ targ }));
    tell_object(targ, "%^BOLD%^%^RED%^The horrible dagger wielded by Cruiser Tetron " +
                "lets out a haunting scream as it tears into you!");

    if (random(45) + 30 > targ->query_skill("perception")) {
        tell_object(targ, "%^RESET%^%^BOLD%^Cruiser Tetron stabs you in the back!%^RESET%^");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(40, 6), "piercing");
        TO->set_property("noMissChance", -1);
    }else {
        tell_object(targ, "%^RESET%^%^BOLD%^You catch Cruiser Tetron trying to stab you.");
        tell_room(ETO, "%^RESET%^%^BOLD%^" + targ->QCN + " catches Cruiser Tetron trying to stab " + targ->QO + ".", targ);
    }

    tell_room(ETO, "Cruiser Tetron unwields %^BOLD%^%^RED%^Horrible screaming dagger%^RESET%^ (wielded in right hand).");

    tell_object(targ, "%^BOLD%^%^RED%^As Cruiser Tetron stabs you, he quickly releases the weapon!");
    tell_room(ETO, "%^BOLD%^%^RED%^As Cruiser Tetron stabs " + targ->QCN + ", he quickly releases the weapon!", ({ targ }));
    tell_room(ETO, "%^BOLD%^%^RED%^Cruiser Tetron then flicks his wrists and a new weapon appears in his hand!");
    tell_room(ETO, "%^BOLD%^%^RED%^Cruiser Tetron quickly stabs again at " + targ->QCN + "!", ({ targ }));
    tell_object(targ, "%^BOLD%^%^RED%^Cruiser Tetron quickly stabs again at you!");

    tell_room(ETO, "%^RED%^Cruiser Tetron gives a smug smile as a dagger " +
              "in his possession begins screaming.%^RESET%^");
    tell_room(ETO, "Cruiser Tetron wields %^BOLD%^%^RED%^Horrible screaming dagger%^RESET%^");
    tell_room(ETO, "%^RED%^The dagger wielded by Cruiser Tetron screams horribly " +
              "as it slashes " + targ->QCN + "'s body, spattering blood everywhere!%^RESET%^", ({ targ }));
    tell_object(targ, "%^BOLD%^%^RED%^The horrible dagger wielded by Cruiser Tetron " +
                "lets out a haunting scream as it tears into you!");

    if (random(45) + 30 > targ->query_skill("perception")) {
        tell_object(targ, "%^RESET%^%^BOLD%^Cruiser Tetron stabs you in the back!%^RESET%^");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(60, 6), "piercing");
        TO->set_property("noMissChance", -1);
    }else {
        tell_object(targ, "%^RESET%^%^BOLD%^You catch Cruiser Tetron trying to stab you.");
        tell_room(ETO, "%^RESET%^%^BOLD%^" + targ->QCN + " catches Cruiser Tetron trying to stab " + targ->QO + ".", targ);
    }

    tell_room(ETO, "Cruiser Tetron unwields %^BOLD%^%^RED%^Horrible screaming dagger%^RESET%^ (wielded in right hand).");
    tell_room(ETO, "Cruiser Tetron wields Battleaxe of the Dominion.");

    return;
}

void freeze(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (targ->will_save(35)) {
        tell_room(ETO, "%^CYAN%^Cruiser Tetron draws in the energy around him and congeals it into a dagger of ice.");
        tell_room(ETO, "%^CYAN%^Cruiser Tetron casts a dagger of compressed ice at " + targ->QCN + "!", targ);
        tell_object(targ, "%^BOLD%^%^CYAN%^Cruiser Tetron's dagger of compressed ice rips into you and the surrounding blood freezes!");
        tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ Feel the icy chill of death upon your heart!%^RESET%^");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(30, 6), "cold");
        TO->set_property("noMissChance", -1);
        targ->set_paralyzed(random(4) * 8, "You are frozen solid!");
        return;
    }else {
        tell_room(ETO, "Cruiser Tetron loses his concentration while attempting to draw in the energy around him");
    }
}

void fireball(object targ)
{
    object* live;
    int i;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }

    live = all_living(ETO);
    live -= ({ TO });
    live = filter_array(live, "is_non_immortal", FILTERS_D);
    tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ By fire be purged!%^RESET%^");
    for (i = 0, sizeof(live) > 0; i < sizeof(live); i++) {
        if (!objectp(live[i])) {
            continue;
        }
        if (!live[i]->reflex_save(35)) {
            tell_room(ETO, "%^BOLD%^%^RED%^Cruiser Tetron hurls a fireball at " + live[i]->QCN + "!", live[i]);
            tell_object(live[i], "%^BOLD%^%^RED%^Cruiser Tetron hurls a fireball at you!");
            TO->set_property("noMissChance", 1);
            live[i]->cause_typed_damage(live[i], "torso", roll_dice(45, 6), "fire");
            TO->set_property("noMissChance", -1);
        }else {
            tell_object(live[i], "%^RED%^Cruiser Tetron's fireball speeds past you and slams into the wall in a shower of sparks!");
        }
    }
    return;
}

void bolt(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }
    tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ Suffer the storm's wrath!%^RESET%^");
    if (!targ->reflex_save(35)) {
        tell_room(ETO, "%^YELLOW%^Cruiser Tetron shoots lightning from his fingertips and blasts " + targ->QCN + "!", targ);
        tell_object(targ, "%^YELLOW%^Cruiser Tetron shoots lightning from his fingertips and blasts you!");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(60, 6), "electricity");
        TO->set_property("noMissChance", -1);
        return;
    }else {
        tell_object(targ, "%^YELLOW%^Cruiser Tetron shoots lightning from his fingertips and it strikes all around you!");
        tell_room(ETO, "%^YELLOW%^Cruiser Tetron shoots lightning from his fingertips and it strikes all around " + targ->QCN + "!", targ);
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(30, 6), "electricity");
        TO->set_property("noMissChance", -1);
    }
    return;
}

void tornado(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (targ->reflex_save(35)) {
        tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ Your end is nigh.%^RESET%^");
        tell_room(ETO, "Cruiser Tetron kneels and touches his palms against the floor.");
        tell_room(ETO, "%^BOLD%^A tornado rises beneath " + targ->QCN + "!", targ);
        tell_object(targ, "%^BOLD%^A tornado rises beneath you and thrusts you upwards against the ceiling!");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(30, 6), "bludgeoning");
        TO->set_property("noMissChance", -1);
        targ->set_tripped(roll_dice(1, 2), "%^YELLOW%^You are trying to regain your footing.");
        return;
    }else {
        tell_room(ETO, "Cruiser Tetron kneels and touches his palms against the floor.");
        tell_room(ETO, "%^CYAN%^The ground beneath your feet shakes violently");
    }
    return;
}

void light(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (!targ->will_save(35)) {
        tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ These are your final moments!%^RESET%^");
        tell_room(ETO, "Cruiser Tetron thrusts his hands foreward, then upwards.");
        tell_room(ETO, "%^BLUE%^The shadows compress to form a ball of energy in his hands.");
        tell_room(ETO, "%^MAGENTA%^His body trembles as dark lightning tears down his arms and his eyes begin to glow.");
        tell_room(ETO, "%^BOLD%^%^BLACK%^Cruiser Tetron lowers his hands and blasts a horrible beam of %^B_BLUE%^%^BOLD%^%^BLACK%^BLACK LIGHT%^RESET%^%^BOLD%^%^BLACK%^ "
                  "at " + targ->QCN + "!", targ);
        tell_object(targ, "%^BOLD%^%^BLACK%^Cruiser Tetron lowers his hands and blasts you with a horrible beam of %^B_BLUE%^%^BOLD%^%^BLACK%^BLACK LIGHT!%^RESET%^");
        tell_object(targ, "%^B_RED%^%^BOLD%^%^BLACK%^It utterly destroys you!%^RESET%^");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(60, 12), "untyped");
        TO->set_property("noMissChance", -1);
        return;
    }else {
        tell_object(targ, "Cruiser Tetron grabs you by the throat and slams you against the wall!");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(30, 6), "bludgeoning");
        TO->set_property("noMissChance", -1);
        tell_room(ETO, "Cruiser Tetron grabs " + targ->QCN + " and slams " + targ->QP + " head against the wall.", targ);
        tell_room(ETO, "%^MAGENTA%^Cruiser Tetron says:%^BOLD%^%^RED%^ Pathetic!%^RESET%^");
    }
    return;
}

void kiss(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (!targ->will_save(35)) {
        tell_room(ETO, "%^BOLD%^YELLOW%^Cruiser Tetron sends several arcing beams of light at " + targ->QCN + " and they are absorbed by " + targ->QP + " body!", targ);
        tell_object(targ, "%^BOLD%^YELLOW%^Cruiser Tetron sends several arcing beams of light at you!\n" "%^RED%^Your eyes burn as your body absorbs the beams!");
        tell_object(targ, "%^BOLD%^%^RED%^The energies work to damage your cell structure!");
        TO->set_property("noMissChance", 1);
        targ->cause_typed_damage(targ, "torso", roll_dice(30, 6), "electricity");
        TO->set_property("noMissChance", -1);
        POISON_D->ApplyPoison(targ, "dark reaver powder", TO, "injury");
        return 1;
    }else {
        tell_object(targ, "%^RED%^Cruiser Tetron cleaves you with his battleaxe!");
        targ->cause_typed_damage(targ, "torso", roll_dice(20, 6), "slashing");
        tell_room(ETO, "Cruiser Tetron cleaves " + targ->QCN + " with his axe.", targ);
    }
}

void desoul(object targ)
{
    targ = get_targ();
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (fodder_check()) {
        fireball(targ); return;
    }

    if (!targ->will_save(35) && !targ->query_property("no death") && !FEATS_D->usable_feat(targ, "death ward")) {
        tell_room(ETO, "%^BOLD%^%^B_BLUE%^Cruiser Tetron calls to powers greater than any you have ever known.");
        tell_room(ETO, "%^CYAN%^Cruiser Tetron's hair begins to fly around, moved by a sudden wind.");
        tell_room(ETO, "%^MAGENTA%^Cruiser Tetron points to  " + targ->QCN + "!", targ);
        force_me("say I SHALL DESTROY YOUR VERY SOUL!");
        tell_room(ETO, "%^B_RED%^Cruiser Tetron's eyes glow red and he screams loudly.");
        tell_room(ETO, "%^BOLD%^%^BLACK%^Cruiser Tetron casts desoul on  " + targ->QCN + "!", targ);
        tell_object(targ, "%^BOLD%^%^BLACK%^Cruiser Tetron casts desoul on you!");
        tell_object(targ, "%^BOLD%^%^RED%^Your soul has been destroyed!");
        force_me("say May whatever god you believe in have mercy on your soul...");
        TO->set_property("noMissChance", 1);
        targ->set_hp(-1 * roll_dice(400000, 400000));
        targ->do_damage("torso", roll_dice(900000, 900000));
        TO->set_property("noMissChance", -1);
        return 1;
    }else {
        tell_object(targ, "Cruiser Tetron thrusts his right leg upwards and hooks it around your neck.");
        tell_object(targ, "Cruiser Tetron drops, slamming your face against the floor beneath his weight.");
        TO->set_property("noMissChance", 1);
        targ->do_damage("torso", roll_dice(25, 6));
        TO->set_property("noMissChance", -1);
        tell_room(ETO, "Cruiser Tetron thrusts his right leg upward and hooks it around  " + targ->QCN + ".  He then drops, "
                  "slamming  " + targ->QP + " face into the floor.", targ);
        targ->set_paralyzed(8, "%^GREEN%^You are gathering your wits about you. Your face really hurts.");
    }
}

int fodder_check()
{
    object* live;
    int i, count;

    live = all_living(ETO);
    live -= ({ TO });
    live = filter_array(live, "is_non_immortal", FILTERS_D);

    for (i = 0, sizeof(live) > 0; i < sizeof(live); i++) {
        if (!objectp(live[i])) {
            continue;
        }
        if (interactive(live[i])) {
            continue;
        }
        if (live[i]->is_merc()) {
            continue;
        }
        count++;
    }
    if (count > 5) {
        return 1;
    }
    return 0;
}

void heart_beat()
{
    int i;
    object* live;

    ::heart_beat();

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!sizeof(TO->query_wielded())){
      command("wield axe");
    }


    live = all_living(ETO);
    live -= ({ TO });
    live = filter_array(live, "is_non_immortal", FILTERS_D);

    for (i = 0, sizeof(live) > 0, sizeof(TO->query_attackers()) > 0; i < sizeof(live); i++) {
        rcount = 0;
        if (!objectp(live[i])) {
            continue;
        }
        if ((int)live[i]->query_hp() > 750) {
            int dmg;
            if ((dmg = (abs(550 - (int)live[i]->query_hp())) + roll_dice(20, 5)) < 0) {
                dmg = roll_dice(18, 6);
            }
            tell_object(live[i], "%^RESET%^%^BOLD%^Cruiser Tetron cuts through your defenses!%^RESET%^");
            TO->set_property("noMissChance", 1);
            live[i]->cause_typed_damage(live[i], "torso", dmg, "piercing");
            TO->set_property("noMissChance", -1);
        }

        if (live[i]->query_race() == "snake") {
            tell_room(ETO, "Cruiser Tetron casts a spell on the " + live[i]->QCN + "!");
            tell_room(ETO, "The " + live[i]->QCN + " crumbles into a pile of dust and blows away!");
            live[i]->move(ROOM_VOID);
            live[i]->remove();
        }else if (live[i]->is_merc()) {
            live[i]->say("Fuck this shit, I'm out.");
            live[i]->force_me("emote runs to the portal.");
            live[i]->fire_me();
        }
    }
    if (sizeof(TO->query_attackers()) < 1) {
        rcount++;
        if (rcount > 60) {
            TO->set_hp((int)TO->query_max_hp());
        }
    }
    if ((int)TO->query_hp() > 8000) {
        TO->add_hp(roll_dice(4, 12));
    }
}

int set_paralyzed(int time, string message)
{
    return 1;
}

int set_tripped(int x, string s)
{
    return 0;
}
