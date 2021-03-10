#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <skills.h>

inherit OBJECT;

string *INSPIRATION_TYPES = ({
        "nothing",
            "courage",
            "competence",
            "greatness",
            "heroics"
    });

object caster;
object *allies;
int clevel;
string active_inspiration;

void create()
{
    ::create();
    set_name("inspiration_obj");
    set("id", ({"inspiration_obj"}));

    set_property("no animate", 1);
    set_weight(0);
}

int is_inspiration()
{
    return 1;
}

object setup_inspiration(object mycaster, int myclevel, string inspiration)
{
    object insprtion;

    insprtion = new(base_name(TO));

    if (!objectp(insprtion)) {
        return;
    }

    if (!objectp(mycaster)) {
        return;
    }

    {
        object* inv;

        inv = all_inventory(mycaster);
        inv = filter_array(inv, (: $1->is_inspiration() :));

        if (sizeof(inv)) {
            if (inspiration == "nothing") {
                inv[0]->remove();
            } else if (inspiration && inspiration != inv[0]->query_active_inspiration()) {
                inv[0]->change_inspiration(inspiration);
            } else if (inspiration && inspiration == inv[0]->query_active_inspiration()) {
                tell_object(mycaster,"%^MAGENTA%^You m%^WHITE%^u%^MAGENTA%^se, but composition doesn't change.");
                tell_room(mycaster,"%^MAGENTA%^" +mycaster->QCN+" m%^WHITE%^u%^MAGENTA%^ses, keeping the melody.", mycaster);
            }
            return 0;
        }
    }

    if (inspiration == "nothing") {
        if (objectp(inspiration)) {
            inspiration->remove();
        }

        return 0;
    }

    insprtion->move(mycaster);
    insprtion->activate_inspiration(mycaster, myclevel, inspiration);
    return insprtion;
}

void activate_inspiration(object mycaster, int myclevel, string inspiration)
{
    caster = mycaster;
    clevel = myclevel;

    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    if (member_array(inspiration, INSPIRATION_TYPES) == -1) {
        TO->remove();
        return;
    }

    allies = ({});

    active_inspiration = inspiration;

    tell_room(ENV(caster), "%^CYAN%^The r%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^p%^BOLD%^t%^WHITE%^u%^CYAN%^r%^BLACK%^e %^RESET%^%^MAGENTA%^o%^BOLD%^f %^WHITE%^m%^MAGENTA%^u%^RESET%^%^MAGENTA%^s%^BOLD%^i%^WHITE%^c %^MAGENTA%^f%^RESET%^%^MAGENTA%^ills %^CYAN%^the a%^BOLD%^i%^RESET%^%^CYAN%^r %^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^d%^CYAN%^%^BOLD%^ " + caster->QCN + "%^RESET%^%^CYAN%^.");

    allies_watch();
}

void change_inspiration(string inspiration)
{
    object ally;

    remove_call_out("allies_watch");

    if (sizeof(allies)) {
        foreach(ally in allies) {
            inspire_ally(ally, -1, 1);
        }
    }

    allies = ({});

    active_inspiration = inspiration;

    tell_room(ENV(caster),"%^BOLD%^%^MAGENTA%^T%^RESET%^%^MAGENTA%^he %^BOLD%^%^BLACK%^t%^MAGENTA%^o%^WHITE%^n%^MAGENTA%^e %^RESET%^%^MAGENTA%^of " +caster->QCN + "'s %^BOLD%^%^WHITE%^m%^MAGENTA%^e%^WHITE%^l%^MAGENTA%^o%^WHITE%^d%^MAGENTA%^y %^RESET%^%^MAGENTA%^changes.%^WHITE%^");

    if (!objectp(caster)) {
        TO->remove();
    }

    allies_watch();
}

void allies_watch()
{
    object * new_allies;
    object * old_allies;
    object * diffout, diffin;
    object ally;

    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    old_allies = allies;

    new_allies = get_present_allies();

    foreach(ally in new_allies)
    {
        object foreign_inspiration = ally->query_property("inspiration");

        if (!objectp(foreign_inspiration)) {
            ally->remove_property("inspiration");
        } else if (foreign_inspiration != TO) {
            new_allies -= ({ally});
        }
    }

    diffout = old_allies - new_allies;

    if (sizeof(diffout)) {
        foreach(ally in diffout) {
            inspire_ally(ally, -1);
        }
    }

    diffin = new_allies - old_allies;

    if (sizeof(diffin)) {
        foreach(ally in diffin) {
            inspire_ally(ally, 1);
        }
    }

    allies = new_allies;

    call_out("allies_watch", ROUND_LENGTH);
}

void inspire_ally(object ally, int direction, int changeflag)
{
    if (!objectp(ally)) {
        return;
    }

    if (direction == 1) {
        tell_object(ally, "%^MAGENTA%^The p%^BOLD%^e%^RESET%^%^MAGENTA%^r%^BOLD%^m%^RESET%^%^MAGENTA%^u%^BOLD%^t%^RESET%^%^MAGENTA%^a%^BOLD%^t%^RESET%^%^MAGENTA%^i%^BOLD%^o%^RESET%^%^MAGENTA%^n of music e%^BOLD%^l%^WHITE%^at%^MAGENTA%^e%^RESET%^%^MAGENTA%^s you with " +active_inspiration+".%^WHITE%^");
        ally->set_property("inspiration", TO);
    }
    if (direction == -1) {
        ally->remove_property("inspiration");
    }
    if (direction == -1 && !changeflag) {
        tell_object(ally, "%^BOLD%^%^BLACK%^Colors of the world turn d%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^ll as the m%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^c l%^RESET%^%^MAGENTA%^ea%^BOLD%^%^BLACK%^v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s you.%^RESET%^");
    }

    if (function_exists("inspire_" + active_inspiration, TO)) {
        call_other(TO, "inspire_" + active_inspiration, ally, direction);
    }

}

void dest_all_effects()
{
    object ally;

    remove_call_out("allies_watch");

    if (sizeof(allies)) {
        foreach(ally in allies)
        {
            if (!objectp(ally)) {
                continue;
            }
            inspire_ally(ally, -1);
        }
    }

    if (objectp(caster) && objectp(ENV(caster))) {
        tell_room(ENV(caster), "%^BOLD%^%^BLACK%^The s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^nc%^RESET%^e %^BOLD%^%^BLACK%^d%^RESET%^ea%^BOLD%^%^BLACK%^f%^RESET%^e%^BOLD%^%^BLACK%^ns as " +caster->QCN+"'s m%^RESET%^u%^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^BLACK%^c comes to an %^RESET%^e%^BOLD%^%^BLACK%^nd.%^RESET%^");
    }
}

void remove_ally(object ally)
{

    allies -= ({ally});

    if (!objectp(ally)) {
        return;
    }

    if (function_exists("inspire_" + active_inspiration, TO)) {
        call_other(TO, "inspire_" + active_inspiration, ally, -1);
    }

    ally->remove_property("inspiration");
}

void inspire_courage(object ally, int direction)
{
    int power;
    power = clevel / 6 + 1;
    power = power > 6 ? 6 : power;

    ally->add_attack_bonus(power * direction);
    ally->add_damage_bonus(power * direction);

    if (direction == 1) {
        ally->set_property("fear_immunity", 1);
    } else {
        ally->remove_property("fear_immunity");
    }
}

void inspire_competence(object ally, int direction)
{
    int power;

    int i;

    power = clevel / 8 + 1;
    power = power > 6 ? 6 : power;

    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        ally->add_skill_bonus(CORE_SKILLS[i], power * direction);
    }
}

void inspire_greatness(object ally, int direction)
{
    int power;

    power = clevel / 8 + 1;
    power = power > 6 ? 6 : power;

    ally->add_max_hp_bonus((clevel * 3 / 2) * direction);
    ally->add_attack_bonus(power * direction);
    ally->set_property("spell penetration", power * direction);
    ally->add_saving_bonus("fortitude", power * direction);
}

void inspire_heroics(object ally, int direction)
{
    int power;

    power = clevel / 4 + 1;
    power = power > 8 ? 8 : power;

    ally->add_saving_bonus("all", power * direction);
    ally->add_ac_bonus(power * direction);
}

object *get_present_allies()
{
    object * pa;

    if (!objectp(caster)) {
        return;
    }

    pa = caster->query_followers();

    {
        string pname;
        object * party;

        pname = caster->query_party();

        if (pname) {
            party = PARTY_D->query_party_members(pname);
            party = filter_array(party, (:objectp($1):));
            party = filter_array(party, (:objectp(ENV($1)):));
            pa += party;
        }
    }

    pa = filter_array(pa, (:ENV($1) == ENV($2):), caster);

    pa += ({caster});

    pa = distinct_array(pa);

    return pa;
}

int countersong(int lvl)
{
    int roll = roll_dice(1, 20);

    if (lvl + roll> clevel || roll == 20 && roll != 1) {
        if (objectp(caster)) {
            tell_object(caster,"%^BOLD%^%^BLACK%^Hostile c%^RESET%^%^RED%^ou%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^rs%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ng d%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^sr%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^pts the harmony of your melodies.%^RESET%^");
            tell_room(ENV(caster),"%^BOLD%^%^BLACK%^Hostile c%^RESET%^%^RED%^ou%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^rs%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ng d%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^sr%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^pts the harmony of " + caster->QCN + " melodies.%^RESET%^", caster);
        }
        TO->remove();
    } else {
            tell_object(caster,"%^BOLD%^%^BLACK%^Hostile c%^RESET%^%^RED%^ou%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^rs%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ng %^WHITE%^fails%^BLACK to disrupt your melodies.%^RESET%^");
            tell_room(ENV(caster),"%^BOLD%^%^BLACK%^Hostile c%^RESET%^%^RED%^ou%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^rs%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ng %^WHITE%^fails%^BLACK%^ to disrupt the harmony of " + caster->QCN + "'s melodies.%^RESET%^", caster);
    }
}

string *query_inspiration_types()
{
    return INSPIRATION_TYPES;
}

int query_clevel()
{
    return clevel;
}

object query_caster()
{
    return caster;
}

void remove()
{
    dest_all_effects();
    ::remove();
}

void save_me()
{
    return;
}

string query_active_inspiration()
{
    return active_inspiration;
}
