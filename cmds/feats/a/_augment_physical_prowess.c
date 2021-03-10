#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

#define VALIDSTATS ({ "strength","dexterity","constitution" })

void create()
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("MagusArcana");
    feat_name("augment physical prowess");
    feat_classes("magus");
    feat_syntax("augment_physical_prowess str|strength|dex|dexterity|con|constitution|check");
    feat_desc("You can expend 1 point from the arcane pool to draw upon yout magical abilities to strengthen yout limbs, sharpen your reflexes, or enhance your toughness for a number of rounds equal to your magus class level.
The bonus is equal to 1 plus one aditional for every 10 magus levels.");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_augment_physical_prowess(string str)
{
    object feat;
    if (!objectp(TP)) { return 0; }
    if (str) str = lower_case(str);
    if (str != "str" &&
        str != "dex" &&
        str != "con" &&
        str != "strength" &&
        str != "dexterity" &&
        str != "constitution") {
        str = "check";
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "dark black");
}

void execute_feat()
{
    object obj;
    int duration, stat_value, bonus, i;

    if (!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    switch (arg)
    {
    case "str":
    case "strength":
        i = 0;
        break;
    case "dex":
    case "dexterity":
        i = 1;
        break;
    case "con":
    case "constitution":
        i = 2;
        break;
    case "check":
        for (i = 0;i < sizeof(VALIDSTATS);i++) {
            if (bonus = (int)caster->query_property("augment " + VALIDSTATS[i])) {
                tell_object(caster, "%^BOLD%^%^GREEN%^Your arcana is improving your " + VALIDSTATS[i] + ".%^RESET%^");
                return;
                break;
            }
        }
        tell_object(caster, "%^BOLD%^%^RED%^You haven't used arcana to improve yourself.%^RESET%^");
        return;
        break;
    }
	
	if(!USER_D->can_spend_pool(caster, 1, "arcana")){
        tell_object(caster, "%^BOLD%^%^RED%^You can't improve your body.%^RESET%^");
		return;
	}	

    if (FEATS_D->is_active(caster, "augment physical prowess"))
    {
        obj = query_active_feat("augment physical prowess");
        obj->dest_effect();
    }
    ::execute_feat();
	
    duration = (int)caster->query_class_level("magus") * ROUND_LENGTH;
    bonus = 1 + (int)caster->query_class_level("magus") / 10;
    stat_value = (int)caster->query_stats(VALIDSTATS[i]);
    if (stat_value > 30) {
        bonus = 0;
        tell_object(caster, "%^BOLD%^%^RED%^You can't improve your " + VALIDSTATS[i] + " further this way.%^RESET%^");
        return;
    }else if (stat_value + bonus > 30) {
        bonus = 30 - stat_value;
    }
	USER_D->spend_pool(caster, 1, "arcana");

    tell_object(caster, cm("Your inner arcana flows through you improving your " + VALIDSTATS[i] + "."));
    caster->set_property("active_feats", ({ TO }));
    caster->set_property("augment " + VALIDSTATS[i], bonus);
    caster->add_stat_bonus(VALIDSTATS[i], bonus);
    call_out("dest_effect", duration);
    return;
}

void dest_effect()
{
    int bonus, i;
    if (objectp(caster))
    {
        caster->remove_property_value("active_feats", ({ TO }));

        for (i = 0;i < sizeof(VALIDSTATS);i++) {
            if (bonus = (int)caster->query_property("augment " + VALIDSTATS[i])) {
                caster->add_stat_bonus(VALIDSTATS[i], -bonus);
                caster->remove_property("augment " + VALIDSTATS[i]);
            }
        }
        tell_object(caster, cm("The arcana flows back at you."));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}