#include <std.h>
#include <daemons.h>
inherit FEAT;

object* allies = ({}), * enemies = ({});


void create()
{
    ::create();
    feat_type("instant");
    feat_category("Chronicler");
    feat_name("lay of the exalted dead");
    feat_prereq("Chronicler L7");
    feat_syntax("lay_of_the_exalted_dead");
    feat_desc("With this feat, the chronicler retells an epic tale of incredible heroism in the face of insurmountable odds. This tale fills allies with hope and inspiration, and enemies with a deep-deated dread. This feat adds a bonus to AC, reflex saves, to hit, and extra attacks, while having the opposite effect on enemies.");
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("chronicler") < 7) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_temporal_displacement(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "lay of the exalted dead")) {
        obj = query_active_feat("lay of the exalted dead");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        dest_effect();
        return;
    }

    ::execute_feat();
    tell_object(caster, "%^RESET%^%^ORANGE%^With an %^CYAN%^a%^GREEN%^r%^CYAN%^c%^GREEN%^a%^CYAN%^n%^GREEN%^e %^ORANGE%^gesture, an %^CYAN%^et%^BOLD%^he%^WHITE%^r%^CYAN%^ea%^RESET%^%^CYAN%^l m%^BOLD%^u%^WHITE%^s%^CYAN%^i%^RESET%^%^CYAN%^c %^ORANGE%^rises up around you.%^WHITE%^");
    caster->set_property("active_feats", ({ TO }));
    return;
}

varargs void remove_effects(int ending)
{
    object myplace, * removing = ({});
    int i;

    if (!objectp(caster)) {
        place = 0;
    }

    for (i = 0; sizeof(enemies), i < sizeof(enemies); i++) {
        if (!objectp(enemies[i])) {
            continue;
        }
        myplace = environment(enemies[i]);
        if (!objectp(caster) || !objectp(place) || !objectp(myplace) || (myplace != place) || ending) {
            enemies[i]->set_property("fighter_attacks_mod", 2);
            enemies[i]->add_attack_bonus(2);
            enemies[i]->add_ac_bonus(2);
            enemies[i]->add_saving_bonus("reflex", 2);
            enemies[i]->remove_property_value("added short", ({ " %^BOLD%^(%^CYAN%^sur%^RESET%^%^CYAN%^rou%^BOLD%^nd%^WHITE%^ed %^CYAN%^by %^RESET%^%^CYAN%^mu%^BOLD%^sic%^WHITE%^)%^RESET%^" }));
            tell_object(enemies[i], "%^RESET%^%^MAGENTA%^You regain your composure as the music fades away.%^WHITE%^");
            removing += ({ enemies[i] });
        }
    }

    enemies -= removing;
    removing = ({});

    for (i = 0; sizeof(allies), i < sizeof(allies); i++) {
        if (!objectp(allies[i])) {
            continue;
        }
        myplace = environment(allies[i]);
        if (!objectp(caster) || !objectp(place) || !objectp(myplace) || (myplace != place) || ending) {
            allies[i]->set_property("fighter_attacks_mod", -2);
            allies[i]->add_attack_bonus(-2);
            allies[i]->add_ac_bonus(-2);
            allies[i]->add_saving_bonus("reflex", -2);
            allies[i]->remove_property_value("added short", ({ " %^BOLD%^(%^CYAN%^sur%^RESET%^%^CYAN%^rou%^BOLD%^nd%^WHITE%^ed %^CYAN%^by %^RESET%^%^CYAN%^mu%^BOLD%^sic%^WHITE%^)%^RESET%^" }));
            tell_object(allies[i], "%^RESET%^%^MAGENTA%^Your adrenaline ebbs as the music fades away.%^WHITE%^");
            removing += ({ allies[i] });
        }
    }

    allies -= removing;
}

void add_effects(object* party, object* attackers)
{
    object myplace;
    int i;

    place = environment(caster);

    for (i = 0; sizeof(party), i < sizeof(party); i++) {
        if (!objectp(party[i])) {
            continue;
        }
        if (member_array(party[i], allies) != -1) {
            continue;
        }
        myplace = environment(party[i]);
        if (myplace != place) {
            continue;
        }
        party[i]->set_property("fighter_attacks_mod", 2);
        party[i]->add_attack_bonus(2);
        party[i]->add_ac_bonus(2);
        party[i]->add_saving_bonus("reflex", 2);
        party[i]->set_property("added short", ({ " %^BOLD%^(%^CYAN%^sur%^RESET%^%^CYAN%^rou%^BOLD%^nd%^WHITE%^ed %^CYAN%^by %^RESET%^%^CYAN%^mu%^BOLD%^sic%^WHITE%^)%^RESET%^" }));
        tell_object(party[i], "%^RESET%^%^MAGENTA%^The %^CYAN%^e%^BOLD%^th%^WHITE%^er%^CYAN%^ea%^RESET%^%^CYAN%^l m%^BOLD%^u%^WHITE%^s%^CYAN%^i%^RESET%^%^CYAN%^c %^MAGENTA%^coalesces around you into %^BOLD%^%^RED%^proud d%^RESET%^%^RED%^ru%^BOLD%^m%^RESET%^%^RED%^be%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^s %^RESET%^%^MAGENTA%^and %^ORANGE%^h%^BOLD%^er%^WHITE%^o%^ORANGE%^i%^RESET%^%^ORANGE%^c %^MAGENTA%^trills of %^ORANGE%^v%^WHITE%^i%^ORANGE%^oli%^WHITE%^n%^ORANGE%^s%^MAGENTA%^... you feel invigorated, destined for %^YELLOW%^greatness%^WHITE%^!%^RESET%^");
        allies += ({ party[i] });
    }

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        if (member_array(attackers[i], enemies) != -1) {
            continue;
        }
        myplace = environment(attackers[i]);
        if (myplace != place) {
            continue;
        }
        attackers[i]->set_property("fighter_attacks_mod", -2);
        attackers[i]->add_attack_bonus(-2);
        attackers[i]->add_ac_bonus(-2);
        attackers[i]->add_saving_bonus("reflex", -2);
        attackers[i]->set_property("added short", ({ " %^BOLD%^(%^CYAN%^sur%^RESET%^%^CYAN%^rou%^BOLD%^nd%^WHITE%^ed %^CYAN%^by %^RESET%^%^CYAN%^mu%^BOLD%^sic%^WHITE%^)%^RESET%^" }));
        tell_object(attackers[i], "%^RESET%^%^MAGENTA%^The %^CYAN%^e%^BOLD%^th%^WHITE%^er%^CYAN%^ea%^RESET%^%^CYAN%^l m%^BOLD%^u%^WHITE%^s%^CYAN%^i%^RESET%^%^CYAN%^c %^MAGENTA%^coalesces into a %^BOLD%^%^RED%^d%^RESET%^%^RED%^ul%^BOLD%^l p%^RESET%^%^RED%^er%^BOLD%^c%^RESET%^%^RED%^us%^BOLD%^s%^RESET%^%^RED%^io%^BOLD%^n %^RESET%^%^MAGENTA%^with screaming %^ORANGE%^v%^WHITE%^i%^ORANGE%^ol%^WHITE%^i%^ORANGE%^ns%^MAGENTA%^... it fills you with %^BOLD%^%^BLACK%^dread %^RESET%^%^MAGENTA%^and %^BOLD%^%^BLACK%^foreboding%^RESET%^%^MAGENTA%^!%^WHITE%^");
        enemies += ({ attackers[i] });
    }
}

void execute_attack()
{
    object* party = ({}), * attackers = ({});
    int i;

    enemies -= ({ 0 });
    allies -= ({ 0 });

    remove_effects();

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }

    place = environment(caster);
    party = ob_party(caster);
    attackers = caster->query_attackers();
    add_effects(party, attackers);

    if (!random(20)) {
        tell_room(place, "%^RESET%^%^MAGENTA%^The %^CYAN%^e%^BOLD%^th%^WHITE%^er%^CYAN%^ea%^RESET%^%^CYAN%^l m%^BOLD%^u%^WHITE%^s%^CYAN%^i%^RESET%^%^CYAN%^c %^MAGENTA%^surrounding %^WHITE%^" + caster->QCN + " %^RESET%^%^MAGENTA%^fades and trails off into a %^BOLD%^%^BLACK%^f%^RESET%^ra%^BOLD%^%^BLACK%^gme%^RESET%^n%^BOLD%^%^BLACK%^te%^RESET%^d m%^BOLD%^%^BLACK%^em%^RESET%^o%^BOLD%^%^BLACK%^ry%^RESET%^%^MAGENTA%^.%^WHITE%^", enemies + allies);
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
}

void dest_effect()
{
    remove_effects(1);
    if (objectp(caster)) {
        tell_object(caster, "%^B_BLUE%^The tale fades from your presence.%^RESET%^");
        caster->remove_property_value("active_feats", ({ TO }));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}

