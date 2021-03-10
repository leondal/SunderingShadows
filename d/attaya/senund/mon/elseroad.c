#include <std.h>
#include "../areadefs.h"
inherit MONSTER;

int FLAG = 0;
int FLAG2 = 0;

void create()
{
    object ob;
    ::create();
    set_name("elseroad");
    set_id(({ "mage", "lord", "mage lord", "mage lord elseroad", "elseroad",
              "lord
elseroad", "mage elseroad" }));
    set_short("%^BOLD%^%^RED%^Lord Mage Elseroad%^RESET%^");
    set_long("%^BLUE%^Lord Mage Elseroad stands before you.  He is a tall fragile looking man %^BLUE%^but the confidence he exudes more then makes up for such frailty. He %^BLUE%^wears flowing long green robes and a fine black cape over top of them. %^BLUE%^In his left hand he carries a grizzly looking longsword, and in his %^BLUE%^right he carries around an ancient looking book. His graying black %^BLUE%^hair waves in an unfelt wind and elseroad stares you down with a slight %^BLUE%^grin on his face.");
    set_race("human");
    set_alignment(9);
    set_hd(59, 4);
    set_class("mage");
    set_mlevel("mage", 59);
    set_guild_level("mage", 59);
    set_gender("male");
    add_search_path("/cmds/wizard");
    set("aggressive", 20);
    add_money("gold", random(10000) + 50000);
    set_stats("strength", 12);
    set_stats("constitution", 15);
    set_stats("dexterity", 16);
    set_stats("wisdom", 19);
    set_stats("intelligence", 30);
    set_stats("charisma", 17);
    set_body_type("human");
    set_max_hp(1500);
    set_hp(1500);
    set_size(2);
    set_func_chance(40);
    set_funcs(({ "special1" }));
    set_spell_chance(60);
    set_spells(({
        "meteor swarm",
        "magic missile",
        "lightning bolt",
        "acid arrow",
        "cone of cold"
    }));

    set_exp(185000);
    set_property("full attacks", 1);
    set_property("weapon resistance", 1);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("magic", 1);
    set_property("no hold", 1);
    set_monster_feats(({
        "spell penetration", "greater spell penetration"
    }));
    set_mob_magic_resistance("low");
    set_emotes(5, ({
        "The Mage Lord Elseroad chuckles and begins to chant: " +
        "%^BOLD%^%^GREEN%^AVER DER COETINY BOR",
        "%^BOLD%^%^YELLOW%^The air around Lord elseroad flashes brightly blinding you!",
        "%^BOLD%^%^MAGENTA%^Lord elseroad whispers to you:%^RESET%^ After 1000 years " +
        "of life I don't think one such as you will hurt me...",
        "Lord elseroad %^BOLD%^%^GREEN%^cackles%^RESET%^",
        "%^MAGENTA%^Lord elseroad states%^RESET%^: Your flesh " +
        "will burn, and your journey will end. You are all weaklings."
    }), 1);

    new(OBJ + "rubysword.c")->move(this_object());
    command("wield sword");
    new(OBJ + "blackcape.c")->move(this_object());
    command("wear cape");
    new(OBJ + "gate_key.c")->move(this_object());
    new(OBJ + "kinmask.c")->move(this_object());
    command("wear mask");
    ob = new("/d/magic/scroll");
    switch (random(4)) {
    case 0:
        ob->set_spell(6);
        break;

    case 1:
        ob->set_spell(8);
        break;

    case 2:
        ob->set_spell(8);
        break;

    case 3:
        ob->set_spell(9);
        break;
    }
}

int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim, which);
    if (hold) {
        tell_room(ETO,
                  "The Lord Elseroad looks over at you. \n" +
                  "%^MAGENTA%^Lord elseroad states%^RESET%^: So some adventurers " +
                  "have travelled past the assassin guild that finds haven in " +
                  "my caves.  Well look where you have come, to my personal home. " +
                  "This is too much an affront to me. You must be dealt with, you " +
                  "are petty trespassers. Your death shall be quick.\n" +
                  "The Lord elseroad begins his barrage of spells as %^RED%^%^BOLD%^fire " +
                  "engulfs the room!");
    }

    if (FLAG2 == 0) {
        new("/cmds/spells/d/_dispel_magic")->use_spell(TO, 0, 45, 100, "mage");
        //new("/cmds/spells/l/_lower_resistance")->use_spell(TO,victim->query_name(),50,100,"mage"); // upped his spell penetration instead
        new("/cmds/spells/f/_fireball")->use_spell(TO, victim->query_name(), 50, 100, "mage");
        new("/cmds/spells/m/_magic_missile")->use_spell(TO, victim->query_name(), 40, 100, "mage");
        new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO, 50, 100, "mage");
        new("/cmds/spells/m/_monster_summoning_v")->use_spell(TO, 0, 34, 100, "mage");
        FLAG2 = 1;
    }

    return hold;
}

void special1(object targ)
{
    string name;
    int count, rand, dam, num;


    num = random(4);
    new("/cmds/spells/d/_dispel_magic")->use_spell(TO, targ->query_name(), 50, 100, "mage");
//new("/cmds/spells/l/_lower_resistance")->use_spell(TO,targ->query_name(),50,100,"mage");

    if (num == 0) {
        TO->force_me("say Let me brighten the mood real quick!");
        new("/cmds/spells/f/_fireball")->use_spell(TO, targ->query_name(), 30, 100, "mage");
    }else if (num == 1) {
        TO->force_me("say Why must you bother me!");
        TO->force_me("say For this, you all shall perish!");
        tell_object(targ, "%^BOLD%^%^BLUE%^The Mage Lord Elseroad reaches out toward you" +
                    " and you feel a great %^RED%^burning%^BLUE%^!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^BLUE%^The Mage Lord Elseroad inflicts a great pain upon"
                  + targ->QCN + "!%^RESET%^", targ);
        dam = roll_dice(10, 10) + 30;
        targ->do_damage("torso", dam);
        targ->set_paralyzed(random(10) + 3, "%^RED%^You are stunned by the blow and" +
                            " are unable to move!%^RESET%^");
        TO->force_me("smirk " + targ->query_name());
        TO->force_me("say This pain is only a small bit of what i have" +
                     " in store for you.");
    }else if (num == 2) {
        rand = random(20);
        name = targ->query_cap_name();
        TO->force_me("say Hazrak obejita!");
        tell_object(targ,
                    "%^BOLD%^%^RED%^Fire begins to rapidly shoot " +
                    "out of Lord elseroad's hands!%^RESET%^");
        tell_room(ETO,
                  "%^BOLD%^%^RED%^Lord Elseroad begins pounding "
                  + name + " with flame after flame!%^RESET%^", targ);
        targ->do_damage("head", roll_dice(4, 5));
        for (count = 0; count < rand; count++) {
            tell_object(targ, "%^RED%^Sizzle!");
            tell_room(ETO, "%^RED%^" + name + " gets burned!", targ);
            targ->do_damage("head", roll_dice(1, 5));
        }
    }else if (num == 3) {
        tell_room(ETO, "%^BOLD%^%^RED%^Lord Elseroad chants a spell, causing" +
                  " his wounds to mend.");
        add_hp(random(500));
    }

    return 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if ((TO->query_hp() < 200) && (FLAG != 1)) {
        FLAG = 1;
        TO->force_me("say %^BOLD%^%^RED%^YOU WON'T WIN THIS EASILY!");
        new("/cmds/spells/m/_monster_summoning_v")->use_spell(TO, 0, 34, 100, "mage");
        new("/cmds/spells/m/_monster_summoning_vi")->use_spell(TO, 0, 34, 100, "mage");
        new("/cmds/spells/m/_monster_summoning_i")->use_spell(TO, 0, 34, 100, "mage");
        new("/cmds/spells/m/_monster_summoning_ii")->use_spell(TO, 0, 34, 100, "mage");
        new("/cmds/spells/m/_monster_summoning_iii")->use_spell(TO, 0, 34, 100, "mage");
        new("/cmds/spells/m/_monster_summoning_iv")->use_spell(TO, 0, 34, 100, "mage");
        new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO, 50, 100, "mage");
        new("/cmds/spells/b/_blink")->use_spell(TO, TO, 50, 100, "mage");
        TO->add_hp(random(300) + 175);
    }
    return;
}
