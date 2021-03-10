//std/armour.c , 13256 bytes:
//      the basic inherited armour object
//      created by Descartes of Borg 25 june 1993
// added player enchanted validation to set_worn() - Yves 12/18

#include <std.h>
#include <balance.h>
#include <daemons.h>
#include <magic.h>

inherit OBJECT;

private string *actualLimbs, type, wear, struck, unwear,armor_prof;
private string *possibleLimbs;
nosave private int originalAc,max_dex_bonus;
private object wornBy;
int block_chance;

int is_armor()
{
    return 1;
}

void init()
{
    ::init();
}

void create()
{
    Object::create();
    possibleLimbs = allocate(10);
    actualLimbs = allocate(10);
    set_property("armor", 1);
}

void set_ac(int x)
{
    ::set_ac(x);
    if (!originalAc) {
        originalAc = x;
    }
}

int query_measure()
{
    return query_ac();
}

int repairMe(int percent)
{
    int add, diff;
    add = query_overallStatus() + percent;
    if (add >= 100) {
        add = 100;
    }
    if (add <= 0) {
        add = 0;
    }
    diff = percent;
    if (query_worn()) {
        ETO->set_ac((int)ETO->query_base_ac() + (int)TO->query_ac());
        set_overallStatus(add);
        ETO->set_ac((int)ETO->query_base_ac() - (int)TO->query_ac());
    }else {
        set_overallStatus(add);
    }
    return diff;
}

int decayMe()
{
    int diff, newval;

    diff = random(5) + 1;
    newval = query_overallStatus() - diff;
    if (newval >= 100) {
        newval = 100;
    }
    if (newval <= 0) {
        newval = 0;
    }
    if (query_worn()) {
        ETO->set_ac((int)ETO->query_base_ac() + (int)TO->query_ac());
        set_overallStatus(newval);
        ETO->set_ac((int)ETO->query_base_ac() - (int)TO->query_ac());
    } else {
        set_overallStatus(newval);
    }
    return (-1 * diff);
}

void unwear()
{
    function f;
    string catchbug;
    int answer;
    mapping itembonuses;

    if (!objectp(wornBy)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (sizeof(wornBy->query_attackers()) > 0 && (!this_object()->query_property("combat_remove")) && (member_array(query_type(), ({ "ring", "shield", "thiefshield", "body shield" })) == -1)) {
        message("my_action", "You can not remove that during combat.", wornBy);
        return;
    }
    if (query_property("funwear")) {
        f = (: call_other, TO, unwear:);
        if (!"/adm/daemon/shutdown_d"->shuttingDown() && (query_verb() != "quit") && interactive(ETO)) {
            if (!(*f)()) {
                return 1;
            }
        } else {
            catchbug = catch(answer = (*f)());
            if (catchbug) {
                write(catchbug);
            }
            if (!answer) {
                return 1;
            }
        }
    }
    if (!(int)ETO->query_property("silent_equip")) {
        if (stringp(unwear) && !query_property("funwear")) {
            message("my_action", unwear, wornBy);
            if (query_broken() != "" && !random(3)) {
                message("my_action", "You notice your " + ::query_short() + " is" + query_broken() + ".", wornBy);
            }
        }else {
            message("my_action", "You remove your " + query_short() + ".", wornBy);
        }
    }

    if (itembonuses = TO->query_item_bonuses()) {
        run_item_bonuses("remove", wornBy, itembonuses);
    }

    wornBy->remove_armour_from_limb(this_object(), actualLimbs);
    if (objectp(environment(wornBy))) {
        message("other_action", (string)wornBy->query_cap_name() + " removes " + (string)wornBy->query_possessive() + " " + query_name() + ".", environment(wornBy), ({ wornBy }));
    }

    wornBy = 0;
    actualLimbs = allocate(1);
}

void unequip()
{
    if (objectp(wornBy)) {
        unwear();
        return;
    }
    ::unequip();
}

void set_not_equipped()
{
    if (query_worn()) {
        wornBy = 0;
    }
    if (actualLimbs) {
        actualLimbs = allocate(0);
    }
}

void set_limbs(mixed* borg)
{
    possibleLimbs = borg;
}

void set_struck(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return 0;
    }
    if (functionp(val)) {
        set_property("fstruck", 1);
        struck = (*val)(1);
    } else {
        struck = val;
    }
}

void set_wear(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return 0;
    }
    if (functionp(val)) {
        set_property("fwear", 1);
        wear = (*val)(1);
    } else {
        wear = val;
    }
}

void set_remove(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return;
    }
    if (functionp(val)) {
        set_property("funwear", 1);
        unwear = (*val)(1);
    } else {
        unwear = val;
    }
}

void set_type(string str)
{
    if (member_array(str, ARMOUR_TYPES, 0) == -1) {
        str = sprintf("armour");
    }
    type = str;
}

// don't let people repair magic armour
int query_ac()
{
    if ((string)TO->query_armor_prof() == "shield" || (string)TO->query_type() == "thiefshield") {
        return 0;
    }
    if (::query_overallStatus() / 100.0 > 1) {
        return (to_int((::query_ac()) + query_property("enchantment") + 0.5));
    }
    return (to_int((::query_ac() * ::query_overallStatus() / 100.0) + query_property("enchantment") + 0.5));
}

int query_original_ac()
{
    return originalAc;
}

mixed* query_limbs()
{
    return possibleLimbs;
}

mixed query_wear()
{
    return wear;
}

mixed query_struck()
{
    return struck;
}

mixed query_unwear()
{
    return unwear;
}

string query_type()
{
    return type;
}

int query_size()
{
    if (member_array((string)TO->query_type(), SIZEDTYPES) == -1) {
        return SIZE_UNIVERSAL;
    }else {
        return ::query_size();
    }
}

void set_worn(object who)
{
    wornBy = who;
    cursed = who->query_name();
    if (TO->query_property("player enchanted")) {
        CHECK_D->validate(TO);
    }
}

object query_worn()
{
    return wornBy;
}

string query_short()
{
    string str, enc;
    int bonus;
    object env;

    bonus = query_property("enchantment");
    env = ETO;
    if (env) {
        if (living(env) && !userp(env) && (bonus < 0)) {
            bonus = bonus * -1;
        }
    }
    str = "";
    if (bonus) {
        if (bonus > 0) {
            enc = " +" + bonus;
        }else {
            enc = " " + bonus;
        }
    } else {
        enc = "";
    }
    str = query_broken();
    if (objectp(TP) && member_array(TPQN, query_identified()) != -1 && PO->query_property("information")) {
        if (!wornBy) {
            return ::query_short() + enc + str;
        }else {
            return ::query_short() + enc + str + " (worn)";
        }
    } else {
        if (!wornBy) {
            return ::query_short() + str;
        }else {
            return ::query_short() + str + " (worn)";
        }
    }
}

string query_long(string str)
{
    string ret;
    int myenchant, i;

    ret = ::query_long(str);
    switch (TO->query_size()) {
    case SIZE_SMALL: ret += "(size small)";      break;
    case SIZE_LARGE: ret += "(size large)";      break;
    case SIZE_NORMAL: ret += "(size normal)";      break;
    case SIZE_UNIVERSAL: ret += "(size universal)";      break;
    default: ret += "(size unknown)";      break;
    }
    // adding decay condition to long *Styx* 10/14/05, last change 7/19/05
    if (query_broken() != "") {
        ret += "\nCondition appears to be" + query_broken() + "\n";
    }else {
        ret += "\n";
    }
    if (wornBy) {
        i = sizeof(actualLimbs);
        ret += "Worn on: " + actualLimbs[--i];
        if (i > -1) {
            while (i--) {
                ret += ", " + actualLimbs[i];
            }
        }
        ret += ".\n";
    }
    //moved item bonus display code into Object.c in the new query_bonus_display() function - Saide, March 2017.
    ret += query_bonus_display();
    if (query_property("soulbound")) {
        ret += "%^RESET%^%^CYAN%^This item gives off a faintly glowing aura of binding.%^RESET%^";
    }
    return ret;
}

string query_base_long(string str)
{
    return ::query_long(str);
}                                                                //adding a way to pick up the base description

void set_actualLimbs(string* stuff)
{
    actualLimbs = stuff;
}

string* query_actual_limbs()
{
    return actualLimbs;
}

int is_armour()
{
    return 1;
}

void set_armor_prof(string prof)
{
    if (member_array(prof, ({ "light", "medium", "heavy", "shield" })) == -1) {
        return;
    }
    armor_prof = prof;
    return;
}

string query_armor_prof()
{
    if (!stringp(armor_prof)) {
        if (query_type() == "leather") {
            return "light";
        }
        if (query_type() == "chain") {
            return "medium";
        }
        if (query_type() == "thiefshield") {
            return "light";
        }
        if (query_type() == "armour") {
            return "heavy";
        }
    }
    return armor_prof;
}

int wearable()
{
    if (!interactive(ETO)) {
        return 1;
    }
    if (strsrch(base_name(TO), "/d/attaya/newseneca/obj/tattoos/") != -1) {
        set_overallStatus(100);
    }

    if (member_array((string)TO->query_type(), ({ "clothing", "ring", "sheath", "jewelry", "bracer" })) != -1) {
        return 1;
    }
    if (avatarp(ETO)) {
        return 1;
    }
    switch (query_armor_prof()) {
    case "light":
        if (FEATS_D->usable_feat(ETO, "light armor proficiency")) {
            return 1;
        }
        break;
    case "medium":
        if (FEATS_D->usable_feat(ETO, "medium armor proficiency")) {
            return 1;
        }
        break;
    case "heavy":
        if (FEATS_D->usable_feat(ETO, "heavy armor proficiency")) {
            return 1;
        }
        break;
    case "shield":
        if (FEATS_D->usable_feat(ETO, "shield proficiency")) {
            return 1;
        }
        break;
    default:
        return 0;
    }
    //gets here return 0;
    return 0;
}

int mixable()
{
    return 1;
}

int drop()
{
    if (query_property("enchantment") && query_property("enchantment") < 0) {
        if (base_name(PO) != "/std/user") {
            if (query_worn() == TP) {
                return 1;
            }
        }
    }
    if (objectp(wornBy) && (sizeof(wornBy->query_attackers()) > 0)) {
        return 1;
    }
    return ::drop();
}

void set_property(string prop, mixed value)
{
    ::set_property(prop, value);
}

int do_struck(int damage, object weapon, object attacker)
{
    object who = query_worn();
    if (!objectp(who)) {
        return 0;
    }
    if (query_property("struck")) {
        return call_other(TO, "property_special", damage, weapon, attacker);
    }
    if (!stringp(struck)) {
        return 0;
    }
    if (!query_property("fstruck")) {
        message("combat", struck, environment(who));
        return 0;
    }
    return call_other(TO, struck, damage, weapon, attacker);
}

int is_cursed()
{
    return ::is_cursed() && query_worn();
}

int query_value()
{
    int cost;
    cost = to_int(
        (::query_value() * ::query_overallStatus() / 100.0)
        );
    if (cost > 0) {
        return cost;
    }else {
        return 0;
    }
}

string query_wear_order()
{
    mixed trapper;
    if (!objectp(TO)) {
        return trapper;
    }
    if (undefinedp(trapper = query_property("wear_order"))) {
        return trapper;
    }else {
        return trapper + "##" + file_name(TO);
    }
}

void set_max_dex_bonus(int num)
{
    if (!intp(num)) {
        return;
    }
    max_dex_bonus = num;
    return;
}

int query_max_dex_bonus()
{
    if (!max_dex_bonus) {
        return 10;
    }
    return max_dex_bonus;
}

void set_block_chance(int num)
{
    block_chance = num; // sets the percent chance to block an attack
}

int query_block_chance()
{
    object tp;

    if (!objectp(tp = TO->query_worn())) {
        return 0;
    }
    return (int)tp->query_shieldMiss();
}
