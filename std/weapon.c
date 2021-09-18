//  Do *NOT* alter this file without permission from
//  Melnmarn or Aragorn @ Shadowgate!
#include <config.h>
#include <std.h>
#include <daemons.h>
#include <damage_types.h>

inherit OBJECT;

private int originalWc, wc_num, wc_dice, large_wc_num, large_wc_dice, original_wc_dice, original_large_wc;
int poisoning;
string profType, type, weapon_prof;
int maxAtLevel = 1;
int Weapon_speed = -1;
nosave string damage_type;
string special_material_type;

#ifdef __OLD_ROOM_BEHAVIOUR

#include <old_weapon.h>

#endif /* __OLD_ROOM_BEHAVIOUR */


// New critical hit related functions -Ares

protected int threat_range;
protected int crit_multiplier;

// This should be a small interger.  The number 2 would indicate a critical hit on
// a roll of 19-20, a 3 would be 18-20
void set_critical_threat_range(int num);

// Returns the critical threat range of the weapon
int query_critical_threat_range();

// Sets the critical hit multiplier of the weapon.  The damage rolled is multiplied

// by this number if they get a successful critical hit
void set_critical_hit_multiplier(int num);

// Returns the critical hit multiplier of the weapon
int query_critical_hit_multiplier();

// ****************************************

void set_special_material_type(string type);
string query_special_material_type();

void create()
{
    Object::create();
    set_decay_rate(300);
    set_property("weapon", 1);
}

void set_wc(int num, int dice)
{
    wc_num = num;
    wc_dice = dice;
    originalWc = num * dice;
}

void set_large_wc(int num, int dice)
{
    large_wc_num = num;
    large_wc_dice = dice;
    if (!original_large_wc) {
        original_large_wc = dice * num;
    }
}

void set_type(string str)
{
    type = str;
}

void add_poisoning(int x)
{
    poisoning += x;
    TO->set("PoisonDoses", poisoning);
    if (poisoning <= 0) {
        poisoning = 0;
        TO->delete("PoisonDoses");
        TO->delete("PoisonType");
    }
}

string query_pois()
{
    //I don't care much about the concept of this - seems like it would
    //really give it away if you look over someone and their weapons are
    //poisoned. - Saide
    return "";

    if (!poisoning) {
        return "";
    }
    if (!TO->query("PoisonType")) {
        return "";
    }
    return " (%^BOLD%^%^GREEN%^poisoned with " + TO->query("PoisonType") + "%^RESET%^) ";
/*
    if(poisoning < 5) return " (slightly poisoned)";
    if(poisoning < 15) return " (poisoned)";
    if(poisoning < 25) return " (strongly poisoned)";
    if(poisoning < 35) return " (very poisoned)";
    return " (deathly poisoned)";
 */
}

string query_short()
{
    string str, enc, poi;
    int bonus;

    bonus = query_property("enchantment");
    if (living(ETO) && !userp(ETO) && bonus < 0) {
        bonus = bonus * -1;
    }
    str = "";
    if (bonus) {
        if (bonus > 0) {
            enc = " +" + bonus;
        }else {
            enc = " " + bonus;
        }
    }else {
        enc = "";
    }
    poi = query_pois();
    //    if(wc_dice < original_wc_dice) str = " (broken)";
//    if(wc_dice < original_wc_dice) str = query_broken();
    str = query_broken();
    if (objectp(TP) && member_array(TPQN, query_identified()) != -1 && PO->query_property("information")) {
        if (!wielded) {
            return ::query_short() + enc + poi + str;
        }else {
            return ::query_short() + enc + poi + str + limbString;
        }
    }else {
        if (!wielded) {
            return ::query_short() + poi + str;
        }else {
            return ::query_short() + poi + str + limbString;
        }
    }
}

// adding a query_long so it can show size & condition like the armor does
// last change 7/19/05 *Styx* 10/14/05
string query_long(string str)
{
    string ret;
    int myenchant;
    ret = ::query_long(str);
    if (!ret) {
        ret = "this weapon is broken";
    }

    switch (TO->query_size()) {
    case SIZE_SMALL: ret += "(size small)";       break;

    case SIZE_NORMAL: ret += "(size medium)";      break;

    case SIZE_LARGE: ret += "(size large)";       break;

    case SIZE_GIANT: ret += "(size giant)";       break;

    case SIZE_UNIVERSAL: ret += "(size universal)";       break;

    default: ret += "(size not set/unknown)";    break;
    }

    // adding decay condition to long *Styx* 10/14/05, last change 7/19/05
    if (query_broken() != "") {
        ret += "\nCondition appears to be" + query_broken() + "\n";
    }else {
        ret += "\n";
    }
    if (wielded) {
        ret += limbString + "\n";
    }
    ret += query_bonus_display();
    if (query_property("soulbound")) {
        ret += "%^RESET%^%^CYAN%^This item gives off a faintly glowing aura of binding.%^RESET%^";
    }
    return ret;
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
    set_overallStatus(newval);
    return (-1 * diff);
}

int query_wc()
{
    //put a cap at 100% durability on the damage scaling for repair status - token items are doing 150% damage! N, 12/16.
    if (query_overallStatus() / 100.0 > 1) {
        return roll_dice(wc_num, to_int(0.5 + wc_dice));
    }
    return roll_dice(wc_num, to_int(0.5 + (wc_dice * query_overallStatus() / 100.0)));

    //Changed so weapons are not doing the maximum damage every hit, Saide, November 2016
    //return roll_dice(wc_num, to_int(0.5+(wc_dice * query_overallStatus()/100.0)));
}

int query_large_wc()
{
    //put a cap at 100% durability on the damage scaling for repair status - token items are doing 150% damage! N, 12/16.
    if (query_overallStatus() / 100.0 > 1) {
        return roll_dice(large_wc_num, to_int(0.5 + large_wc_dice));
    }
    return roll_dice(large_wc_num, to_int(0.5 + (large_wc_dice * query_overallStatus() / 100.0)));

    //return roll_dice(large_wc_num, to_int(0.5+(large_wc_dice * query_overallStatus()/100.0)));
}

int query_damage()
{
    int pois, wepstatus;
    float damfloat;
    //pois = poisoning;
    //add_poisoning(-4);
    wepstatus = query_overallStatus();
    if (wepstatus > 100) {
        wepstatus = 100;
    }

    damfloat = roll_dice(wc_num, wc_dice) + query_property("enchantment");
    damfloat = damfloat * wepstatus / 100.0;
    return to_int(damfloat);
}

int query_large_damage()
{
    int pois, wepstatus;
    float damfloat;
    //pois = poisoning;
    //add_poisoning(-4);
    wepstatus = query_overallStatus();
    if (wepstatus > 100) {
        wepstatus = 100;
    }

    if (large_wc_dice) {
        damfloat = roll_dice(large_wc_num, large_wc_dice) +
                   query_property("enchantment");
    }else {
        damfloat = roll_dice(wc_num, wc_dice) +
                   query_property("enchantment");
    }
    damfloat = damfloat * wepstatus / 100.0;
    return to_int(damfloat);
}

string query_type()
{
    return type;
}

void set_property(string prop, mixed value)
{
    ::set_property(prop, value);
}

int query_poisoning()
{
    return poisoning;
}

int is_weapon()
{
    return 1;
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
    set_overallStatus(add);
    return diff;
}

void set_weapon_prof(string str)
{
    if (member_array(str, ({ "simple", "martial", "exotic" })) == -1) {
        return;
    }
    weapon_prof = str;
}

string query_weapon_prof()
{
    if (!weapon_prof) {
        return "simple";
    }
    return weapon_prof;
}

int is_ok_wield()
{
    int isok, fi, th, ma, cl;
    object who;

    who = query_wielded();
    if (!objectp(who)) {
        return 1;
    }

    if (!userp(who)) {
        return 1;
    }
    if (who->query("new_class_type")) {
        switch (query_weapon_prof()) {
        case "simple":  if (FEATS_D->usable_feat(who, "simple weapon proficiency")) {
                return 1;
        }

        case "martial": if (FEATS_D->usable_feat(who, "martial weapon proficiency")) {
                return 1;
        }

        case "exotic":  if (FEATS_D->usable_feat(who, "exotic weapon proficiency")) {
                return 1;
        }

        default: return 0;
        }
    } else {
        return 1;
    }
}

void init()
{
    ::init();
/*********** taking this out for autowear on login of last worn stuff.
    if(ETO == TP) {
        if(query_property("enchantment") && query_property("enchantment") < 0) {
            if(cursed == (string)TPQN) {
                if(query_size() > TP->query_size())
                    TP->force_me("wield "+query_id()[0]+" in right hand and left hand");
                else
                    TP->force_me("wield "+query_id()[0]);
            }
        }
    }

 ****************** Garrett - 02/22/2007 */
}

int drop()
{
    if (query_property("enchantment") && query_property("enchantment") < 0) {
        if (base_name(PO) != "/std/user") {
            if (query_wielded() == TP) {
                return 1;
            }
        }
    }
    return ::drop();
}

void set_prof_level(int xxx)
{
    maxAtLevel = xxx;
}

void set_prof_type(string prof)
{
    profType = prof;
}

string query_basic_prof_type()
{
    string type;
    switch (query_size()) {
    case 1:
        type = "small";    break;

    case 2:
        type = "medium";   break;

    case 3:
        type = "large";     break;

    case 4:
        type = "giant";     break;

    default:
        break;
    }

    switch (query_type()) {
    case "slashing":
        type += " blades";        break;

    case "thiefslashing":
        type += " blades";       break;

    case "slash":
        type += " blades";       break;

    case "thiefslash":
        type += " blades";      break;

    case "piercing":
        type += " blades";      break;

    case "thiefpiercing":
        type += " blades";      break;

    case "pierce":
        type += " blades";       break;

    case "magepiercing":
        type += " blades";      break;

    case "bludgeon":
        type += " clublike";     break;

    case "magebludgeon":
        type += " clublike";            break;

    case "magicslashing":
        type = "magic weapons";    break;

    default:
        type = "unknown";      break;
    }
    return type;
}

string query_prof_type()
{
    if (!stringp(profType)) {
        return query_basic_prof_type();
    }
    return profType;
}

int query_level_max()
{
    return maxAtLevel;
}

void set_weapon_speed(int x)
{
    Weapon_speed = x;
}

int query_weapon_speed()
{
    if (objectp(ETO)) {
        if (interactive(ETO)) {
            if (FEATS_D->usable_feat(ETO, "light weapon")) {
                if (query_size() > (int)ETO->query_size()) {
                    if (Weapon_speed == -1) {
                        return query_size();
                    }
                    return Weapon_speed / 5;
                }
            }
        }
    }
    if (Weapon_speed == -1) {
        return 3 * query_size();
    }
    return Weapon_speed;
}

int is_cursed()
{
    return ::is_cursed() && query_wielded();
}

int is_broken()
{
    return wc_dice < original_wc_dice;
}

int query_size()
{
    if (!objectp(ETO)) {
        return ::query_size();
    }
    if (query_property("lance") && living(ETO)) {
        return ETO->query_size();
    }
    return ::query_size();
}

int query_value()
{
    int cost;
    cost = to_int((::query_value() * ::query_overallStatus() / 100.0));
    if (cost > 0) {
        return cost;
    }else {
        return 0;
    }
}

int query_wc_num()
{
    return wc_num;
}

int query_wc_dice()
{
    return wc_dice;
}

int query_large_wc_num()
{
    return large_wc_num;
}

int query_large_wc_dice()
{
    return large_wc_dice;
}

// Critical hit stuff
void set_critical_threat_range(int num)
{
    if (!num || num < 1) {
        threat_range = 1;
    }else {
        threat_range = num;
    }
}

// doing a temporary override here for now -Ares
// removing override to allow medium and large weapons with expanded critical hit range - Odin
int query_critical_threat_range()
{
    if (!threat_range) {
        threat_range = 1;
    }

    //  if(query_size() > 1) { return 2; }
    //  else { return 3; }

    return threat_range;
}

void set_critical_hit_multiplier(int num)
{
    if (!num || num < 2) {
        crit_multiplier = 2;
    }else {
        crit_multiplier = num;
    }
}

// changing this to 2 for the present time -Ares
int query_critical_hit_multiplier()
{
    if (!crit_multiplier) {
        crit_multiplier = 2;
    }
    return crit_multiplier;
    //return 2;
}

void set_damage_type(string str)
{
    if (member_array(str, VALID_DAMAGE_TYPES) == -1) {
        damage_type = "untyped";
    }
    damage_type = str;
}

void query_damage_type()
{
    if (!damage_type || damage_type == "" || damage_type == " ") {
        damage_type = "untyped";
    }
    if (query_special_material_type() == "none") {
        return damage_type;
    }
    return query_special_material_type();
}

void set_special_material_type(string type)
{
    if (type != "silver" || type != "cold iron") {
        special_material_type = "none";
    }
    special_material_type = type;
}

string query_special_material_type()
{
    if (!special_material_type || special_material_type == "" || special_material_type == " ") {
        return "none";
    }
    return special_material_type;
}
