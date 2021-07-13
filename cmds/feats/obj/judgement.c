#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

string* JUDGEMENT_TYPES = ({
    "destruction",
    "healing",
    "justice",
    "piercing",
    "protection",
    "purity",
    "resiliency",
    "resistance",
//            "smiting"
});

string* active_judgements = ({});
object caster;
int clevel;
object lendingto;

int ticker = 0;

void create()
{
    ::create();
    set_name("judgement_obj");
    set_id(({"judgement_obj"}));
    set_property("no animate", 1);
    set_hide(1);
    set_weight(0);
}

void setup_judgement(object mycaster, int myclevel)
{
    caster = mycaster;
    clevel = myclevel;
}

void activate_judgements(string* judgements)
{
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    if (sizeof(active_judgements)) {
        apply_judgements(active_judgements, -1);
    }
    active_judgements = judgements;

    lendingto = caster->query_property("lend_judgement");

    apply_judgements(judgements, 1);
    tell_object(caster, "%^BOLD%^%^WHITE%^You with a mere will you call out to the arcane for the strength.");
    call_out("check", ROUND_LENGTH);
}

string* query_active_judgements()
{
    return active_judgements;
}

string* query_judgement_types()
{
    return JUDGEMENT_TYPES;
}

void apply_judgements(string* judgements, int direction)
{
    string j;
    int power;
    int maxtolend, i;

    if (objectp(lendingto)) {
        power = clevel;
        maxtolend = caster->query_property("greater_lend_judgement") ? 3 : 1;
        if(maxtolend > sizeof(judgements)) {
            maxtolend = sizeof(judgements);
        }
        
        if (direction > 0) {
            tell_object(caster, "%^BOLD%^%^WHITE%^" + lendingto->QCN + " is infused with your zeal.");
            tell_object(lendingto, "%^BOLD%^%^WHITE%^You are infused with power of the zeal!");
        }

        for (i = 0; i < maxtolend; i++) {
            if (member_array(judgements[i], JUDGEMENT_TYPES) != -1) {
                call_other(TO, "judgement_" + judgements[i], lendingto, direction, power);
            }
        }
    }


    foreach(j in judgements)
    {
        if (member_array(j, JUDGEMENT_TYPES) != -1) {
            power = clevel;
            if (FEATS_D->usable_feat(caster, "slayer")) {
                if (caster->query("slayer_judgement") == j) {
                    power += 5;
                }
            }
            if (function_exists("judgement_" + j, TO)) {
                call_other(TO, "judgement_" + j, caster, direction, power);
            }
            if (direction == -1) {
                active_judgements -= ({j});
            }
        }
    }
}

void judgement_destruction(object targ, int direction, int power)
{
    int bonus;
    bonus = power / 9 + 1;
    targ->add_damage_bonus(bonus * direction);
}

void judgement_healing(object targ, int direction, int power)
{
    int bonus;
    bonus = power / 18 + 1;
    targ->set_property("fast healing", bonus * direction);
}

void judgement_justice(object targ, int direction, int power)
{
    int bonus;
    bonus = power / 9 + 1;
    targ->add_attack_bonus(bonus * direction);
}

void judgement_piercing(object targ, int direction, int power)
{
    targ->set_property("spell penetration", (power / 12 + 1) * direction);
    targ->set_property("empowered", (power / 12 + 1) * direction);
}

void judgement_protection(object targ, int direction, int power)
{
    int bonus;
    bonus = power / 9 + 1;
    bonus = bonus > 5 ? 5 : bonus;
    targ->add_ac_bonus(bonus * direction);
}

void judgement_purity(object targ, int direction, int power)
{
    int bonus;
    bonus = power / 9 + 1;
    bonus = bonus > 5 ? 5 : bonus;
    targ->add_saving_bonus("all", bonus * direction);
}

void judgement_resiliency(object targ, int direction, int power)
{
    int bonus;
    bonus = power / 2 + 1;
    targ->set_property("spell damage resistance", bonus * direction);
}

void check()
{
    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    if (sizeof(caster->query_attackers())) {
        ticker = 0;
    }

    ticker++;

    if (ticker == 2) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You sense you begin to loose the grip on your arcane zeal.%^RESET%^");
    }

    if (!sizeof(caster->query_attackers()) && ticker > 3) {
        tell_object(caster, "%^BOLD%^%^CYAN%^As the battle comes to an end your arcane zeal recedes.%^RESET%^");
        apply_judgements(active_judgements, -1);
        TO->remove();
        return;
    }
    if (caster->query_property("effect_frightened") ||
        caster->query_property("effect_panicked")) {
        tell_object(caster, "%^BOLD%^%^CYAN%^As you're in panic you can no longer maintain your zeal.%^RESET%^");
        apply_judgements(active_judgements, -1);
        TO->remove();
        return;
    }
    call_out("check", ROUND_LENGTH);
}

void remove()
{
    if (sizeof(active_judgements)) {
        apply_judgements(active_judgements, -1);
    }
    ::remove();
}

int is_judgement()
{
    return 1;
}

void save_me()
{
    return;
}
