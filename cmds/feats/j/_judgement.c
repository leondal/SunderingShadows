#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

string* JUDGEMENT_TYPES;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Inquisition");
    feat_name("judgement");
    feat_syntax("judgement FIRST [SECOND [THIRD]]");
    feat_prereq("Inquisitor L1");
    feat_classes("inquisitor");
    feat_desc("Inquisitors have an unusual affinity to pronounce a judgement on their foes, to strengthen themselves with channeled power. At the beginning they can choose just one power to pronounce, but as inquisitor grows in power he learns to control up to three such powers. Changing the power is a free action, but any powers an inquisitor has will retreat after the combat and can not be summoned unless already in the combat.

The list of judgements to choose from:

%^BOLD%^Destruction:%^RESET%^ The inquisitor is filled with divine wrath, giving them a damage bonus point plus an additional damage bonus point per every six levels.

%^BOLD%^Healing:%^RESET%^ The inquisitor is surrounded by a healing light, gaining a fast healing pointplus an additional fast healing point per every eighteen levels.

%^BOLD%^Justice:%^RESET%^ This judgment spurs the inquisitor to seek justice, gaining a sacred bonus point to attack plus an additional bonus point to attack per every five levels.

%^BOLD%^Piercing:%^RESET%^ This judgment gives the inquisitor great focus and makes his spells more potent. This grants a point of spell penetration and a caster level, plus an additonal point of spell penetrationn and caster level for every twelve levels.

%^BOLD%^Protection:%^RESET%^ The inquisitor is surrounded by a protective aura, granting a sacred armor class point plus an additional sacred armor class point per every five levels.

%^BOLD%^Purity:%^RESET%^ The inquisitor is protected from the vile taint of her foes, gaining a sacred bonus point to all saves plus an additional point to saves per every five levels.

%^BOLD%^Resiliency:%^RESET%^ This judgment makes the inquisitor resistant to harm, granting him one point of spell damage resistance plus an additional point of spell damage resistance per two levels.

%^BOLD%^See also:%^RESET%^ status effects
");
//    set_required_for(({"second judgement","third judgement"}));
    set_target_required(0);
    allow_blind(1);
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
    if (!ob->is_class("inquisitor")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_judgement(string str)
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
    object controller;
    int i;
    string j;
    string* jtoactivate = ({}), * args;
    ::execute_feat();

    if (!objectp(TP)) {
        return 0;
    }

    if (!FEATS_D->usable_feat(TP, query_feat_name())) {
        return 0;
    }

    if (!arg) {
        return help();
    }

    args = explode(arg, " ");
    JUDGEMENT_TYPES = "/cmds/feats/obj/judgement"->query_judgement_types();

    if (FEATS_D->usable_feat(TP, "third judgement")) {
        i = 3;
    } else if (FEATS_D->usable_feat(TP, "second judgement")) {
        i = 2;
    } else {
        i = 1;
    }

    foreach(j in args)
    {
        if (member_array(j, JUDGEMENT_TYPES) != -1) {
            jtoactivate += ({ j });
        }else {
            tell_object(TP, "Wrong judgement type: " + j);
        }
        i--;
        if (i < 1) {
            break;
        }
    }

    {
        object inv;

        inv = all_inventory(TP);
        inv = filter_array(inv, (:$1->is_judgement():));

        if (sizeof(inv)) {
            controller = inv[0];
        }else {
            controller = new("/cmds/feats/obj/judgement");
            controller->move(TP);
            controller->setup_judgement(TP, flevel);
        }
        jtoactivate = distinct_array(jtoactivate);
        controller->activate_judgements(jtoactivate);

    }
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
