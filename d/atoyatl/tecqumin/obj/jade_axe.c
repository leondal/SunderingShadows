//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/large_battle_axe";

int rage_track;
int wimpy_track;
last_try;

void create()
{
    ::create();
    set_name("jade axe");
    set_id(({ "axe", "jade axe", "greataxe", "jade greataxe", "stone warhammer", "stone war hammer" }));
    set_short("%^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^a%^BOLD%^de axe of %^RED%^r%^RESET%^%^RED%^a%^BOLD%^ge%^RESET%^");
    set_obvious_short("%^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^a%^BOLD%^de g%^RESET%^%^GREEN%^re%^BOLD%^at%^RESET%^%^CYAN%^a%^BOLD%^%^GREEN%^xe");
    set_long((: TO, "long_desc" :));

    set_value(150000);
    set_wield((: TO, "wield_axe" :));
    set_unwield((: TO, "unwield_axe" :));
    set_property("enchantment", 6);
    set_hit((: TO, "hit_stuff" :));
    set_weapon_speed(1);

    set_lore("The %^CYAN%^Tecqumin%^RESET%^ were able to conquer and hold an"
             + " empire due in part to the fear with which their armies were regarded."
             + " They were often lead into battle by fearsome berserker squads who, once"
             + " unleashed, could barely be restrained from their %^BOLD%^%^RED%^bl"
             + "%^RESET%^%^RED%^oo%^BOLD%^dl%^RESET%^%^RED%^u%^BOLD%^st%^RESET%^. The"
             + " %^BOLD%^%^GREEN%^jN%^aN%^de g%^RESET%^%^GREEN%^re%^BOLD%^at%^RESET%^"
             + "%^CYAN%^a%^BOLD%^%^GREEN%^xe%^RESET%^ was the symbol of one such squad,"
             + " and was capable of cutting a swathe through friend and foe alike if not"
             + " properly directed.");
    set_property("lore difficulty", 35);
    set_item_bonus("attack bonus", 3);
    set_item_bonus("damage bonus", 3);
    set_item_bonus("endurance", 2);
    rage_track = 0;
    wimpy_track = 0;
}

void init()
{
    ::init();
    if (!objectp(ETO) || !interactive(ETO) || member_array("rage", (string*)ETO->query_temporary_feats()) == -1) {
        rage_track = 0;
    }
}

int rage(string str)
{
    object wielded;
    wielded = query_wielded();
    if (!objectp(wielded) || wielded != ETO) {
        return 0;
    }
    if (!str || (str != "off" && str != "on")) {
        return notify_fail("Try 'rage on' or 'rage off'");
    }
    if (str != "off") {
        return 0;
    }
    if (!TP->will_save(42) || time() < last_try + 2) {
        tell_object(TP, "The rage is too strong to let go");
        if (time() >= last_try + 2) {
            last_try = time();
        }
        return 1;
    }
    return 0;
}

string long_desc()
{
    string desc;
    desc = "This oversized battleaxe has a"
           + " %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a%^BOLD%^de %^RESET%^head"
           + " mounted on a wooden haft decorated with carvings and inlaid with"
           + " stones of %^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^u%^BOLD%^rq%^RESET%^"
           + "%^BLUE%^u%^CYAN%^o%^BOLD%^%^BLUE%^i%^CYAN%^se%^RESET%^ and"
           + " %^BOLD%^%^BLACK%^jet%^RESET%^. The carvings depict battle scenes"
           + " and the conquering armies of the %^CYAN%^Tecqumin%^RESET%^";
    if (FEATS_D->can_use_feat(ETO, "rage")) {
        desc += "\n%^BOLD%^%^YELLOW%^You realise that you would probably not"
                + " gain the full benefit of this weapon, as you already know how to"
                + " harness your rage.";
    } else {
        desc += "\n%^BOLD%^%^YELLOW%^This weapon would allow you to use the rage feat";
    }
    return desc;
}

void next_target(object ob)
{
    object* enemies, * critters, removals;
    string race;
    int r, i, count;
    if (!objectp(ob) || !interactive(ob) || !objectp(ETO) || ob != ETO || !objectp(EETO)) {
        return;
    }
    critters = all_living(EETO);
    if (sizeof(critters) < 2) {
        return;
    }
    removals = ({});
    for (i = 0; i < sizeof(critters); i++) {
        if (critters[i]->query_true_invis() || critters[i] == ob) {
            removals += ({ critters[i] });
        }
    }
    if (sizeof(removals) > 0) {
        critters -= removals;
    }
    if (sizeof(critters) < 1) {
        return;
    }
    enemies = ob->query_attackers();
    if (sizeof(enemies) < 1) {
        if (ob->will_save(42)) {
            tell_object(ob, "The %^RED%^red mist%^RESET%^ fades slightly, and you"
                        + " realise that there are no enemies left before you, for now");
            return;
        }
        if (ob->query_paralyzed()) {
            tell_object(ob, "%^RED%^The red mist blurs your vision and you try to launch an attack, but cannot");
            tell_object(ob, ob->query_paralyze_message());
            call_out("next_enemy", 3);
            return;
        }
        tell_object(ob, "%^RED%^The red mist blurs your vision and you launch"
                    + " yourself back into battle, screaming for"
                    + " %^BOLD%^bl%^RESET%^%^RED%^oo%^BOLD%^d");
        tell_room(EETO, ob->QCN + "%^RESET%^ lets out a"
                  + " %^BOLD%^%^RED%^bl%^RESET%^%^RED^%^oo%^BOLD%^dc%^RESET%^u%^BOLD%^rd"
                  + "l%^RESET%^%^RED%^i%^BOLD%^ng %^RESET%^battle cry", ob);
        race = critters[random(sizeof(critters))]->query_race();
        ob->force_me("kill " + race);

        if ("/daemon/feat_d.c"->can_use_feat(ob, "impale") && ob->query_size() == query_size()) {
            ob->force_me("impale " + race);
            ob->force_me("kill " + race);
            return;
        }
        if ("/daemon/feat_d.c"->can_use_feat(ob, "rush")) {
            ob->force_me("rush " + race);
            ob->force_me("kill " + race);
            return;
        }
        if (member_array("rush", (string*)ETO->query_temporary_feats()) != -1) {
            ob->force_me("rush " + race);
            ob->force_me("kill " + race);
            return;
        }
        if ("/daemon/feat_d.c"->can_use_feat(ob, "charge")) {
            ob->force_me("charge " + race);
            ob->force_me("kill " + race);
            return;
        }
        if ("/daemon/feat_d.c"->can_use_feat(ob, "shield charge")) {
            ob->force_me("shield charge " + race);
            ob->force_me("kill " + race);
            return;
        }

        if ("/daemon/feat_d.c"->can_use_feat(ob, "shield bash")) {
            ob->force_me("shield bash " + race);
            ob->force_me("kill " + race);
            return;
        }
        ob->force_me("kill " + race);
    }
}

int hit_stuff(object ob)
{
    if (!objectp(TO) || !objectp(ETO) || !objectp(ob)) {
        return 0;
    }
    call_out("next_target", 2, ETO);
    return 0;
}

int wield_axe()
{
    if (!objectp(TO) || !objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    if (member_array("Fettered the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^red", ETO->query_quests()) == -1 && member_array("Drove %^MAGENTA%^The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d %^RESET%^back into the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^%^BLACK%^d%^RESET%^!", ETO->query_quests()) == -1 && member_array("%^RED%^Defeated %^RESET%^%^BLUE%^The%^MAGENTA%^ U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d", ETO->query_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have not earned the right to use this item!%^RESET%^");
        return 0;
    }
    if (FEATS_D->can_use_feat(TP, "rage")) {
        tell_object(ETO, "As you wield the " + query_short() + "%^RESET%^, you feel a fierce rage"
                    + " building, and a resolve not to flee battle.");
    } else {
        tell_object(ETO, "As you wield the " + query_short() + "%^RESET%^, you feel a fierce rage"
                    + " building, and a resolve not to flee battle. You can focus the rage into combat with the <rage> command.");
        if (member_array("rage", (string*)ETO->query_temporary_feats()) == -1) {
            ETO->add_temporary_feat("rage");
            rage_track = 1;
        }
    }
    tell_room(EETO, (string)ETO->query_cap_name() + " wields "
              + (string)ETO->QP + " " + query_short(), ETO);
    if (ETO->query_wimpy() > 0) {
        wimpy_track = ETO->query_wimpy();
        ETO->set_wimpy(0);
    }
    add_action("rage", "rage");
    add_action("wimpy", "wimpy");
    add_action("flee", "flee");
    return 1;
}

int pre_exit_fun()
{
    object* enemies, wielder;
    wielder = query_wielded();
    if (!objectp(wielder)) {
        return 0;
    }
    enemies = wielder->query_attackers();
    if (sizeof(enemies) > 0) {
        tell_object(wielder, "Your " + query_short() + "%^RESET%^"
                    + " stiffens your result, and you decide not to leave battle");
        return 1;
    }
    return 0;
}

int wimpy(string str)
{
    tell_object(TP, "Your " + query_short() + " %^RESET%^stiffens your resolve, and you decide not to leave combat.");
    return 1;
}

int flee(string str)
{
    tell_object(TP, "Your " + query_short() + " %^RESET%^stiffens your resolve, and you decide not to leave combat.");
    return 1;
}

int unwield_axe()
{
    object* enemies, critters;
    enemies = TP->query_attackers();
    if (TP->query_property("raged") && !TP->will_save(42)) {
        tell_object(TP, "Your rage is too strong to release your grip on the axe");
    }
    if (rage_track == 1) {
        ETO->remove_temporary_feat("rage");
        rage_track = 0;
    }
    if (wimpy_track > 0) {
        ETO->set_wimpy(wimpy_track);
        wimpy_track = 0;
    }
    remove_action("wimpy", "wimpy");
    remove_action("flee", "flee");
    remove_action("rage", "rage");

    return 1;
}
