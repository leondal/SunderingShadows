//  /std/living/body.c
//  from the Nightmare mudlib
//  the code for the limbs system used by the Nightmare mudlib
//  based on the TMI LOS system by Brian with help from Buddha
//  written by Descartes of Borg september 1992
//added shieldMiss 2/27/13 ~Circe~

#include <std.h>
#include <daemons.h>
#include <objects.h>
#include <valid_bonuses.h>
#include <damage_types.h>
#include <dirs.h>
//#define SIZEDTYPES ({"chain","clothing","leather","armour"})
//#define MULTIPLE_WEAR ({"clothing","jewelry", "sheath"})
//#define PK_DAMAGE_PERCENTAGE 100

inherit CONTAINER;

mixed* deaths;
mapping player_data, magic, severed, healing;
nosave mapping body;
nosave mapping resistances;
nosave mapping MyAcArmour;
nosave mapping wielded_objects;
nosave string target_limb;
nosave string base_damage_type;
string* limbs;
nosave string* fake_limbs;
int all_my_fingers;
nosave int ac = 10;
nosave int monster_ac;
nosave int size;
nosave int size_bonus = 0;
nosave int num_wielded;
nosave int ac_bonus;
nosave int max_hp_bonus = 0;
private int heal_rate;
private nosave int stoneSkinned;
private nosave int missChance;
private nosave int shieldMiss;
int blindness;
private nosave object* ac_armour; // This is the armour being counted in AC
nosave int magic_attack, spell_attack;

//  This function initializes the variables
//  This should only be called when there is NO limb data yet

mapping query_body()
{
    return body;
}

void init_limb_data()
{
    int i;

    if (!player_data) {
        player_data = ([ "general" : ([ "hp" : 1, "extra_hp" : 0, "max_hp" : 30, "sp" : 1, "max_sp" : 1])]);
    }
    body = ([]);
    limbs = ({});
    fake_limbs = ({});
    wielded_objects = ([]);
    severed = ([]);
    if (!healing || healing == ([])) {
        healing = ([]);
    }
    if (!magic) {
        magic = ([ "points" : 0, "max points" : 0 ]);
    }
    ac_armour = ({});

    if (!mapp(resistances) || !sizeof(keys(resistances))) {
        resistances = ([]);
        resistances["resistance"] = ([]);
        resistances["resistance percents"] = ([]);

        for (i = 0; i < sizeof(VALID_DAMAGE_TYPES); i++) {
            resistances["resistance"] += ([ VALID_DAMAGE_TYPES[i] : 0 ]);
            resistances["resistance percents"] += ([ VALID_DAMAGE_TYPES[i] : 0 ]);
        }
    }
}

void set_general(mapping map)
{
    player_data["general"] = map;
}

void set_sp(int x)
{
}

int query_max_sp()
{
    return 1;
}

int query_sp()
{
    return 1;
}

void set_max_hp(int hp)
{
    player_data["general"]["max_hp"] = hp;
}

void set_max_hp_bonus(int hp)
{
    max_hp_bonus = hp;
}

int add_max_hp_bonus(int hp)
{
    max_hp_bonus += hp;

    if (max_hp_bonus >= (query_max_hp_base()) / 3) {
        max_hp_bonus = query_max_hp_base() / 3;
        return 0;
    }
    return 1;
}

int query_max_hp_bonus()
{
    return max_hp_bonus;
}

void set_diety(string str)
{
    player_data["general"]["diety"] = str;
}

string query_diety()
{
    return player_data["general"]["diety"];
}

void add_extra_hp(int x)
{
    player_data["general"]["extra_hp"] += x;
}

int query_extra_hp()
{
    return player_data["general"]["extra_hp"];
}

void set_hp(int hp)
{
    if (!query_max_hp()) {
        player_data["general"]["max_hp"] = hp;
    }
    if (hp > TO->query_max_hp()) {
        if (TO->is_player()) {
            player_data["general"]["hp"] = query_max_hp();
        }else {
            player_data["general"]["max_hp"] = hp;
            player_data["general"]["hp"] = hp;
        }
    }else {
        player_data["general"]["hp"] = hp;
    }
}

void set_stoneSkinned(int i)
{
    int num;
    if (i < 0) {
        return;
    }
    if (FEATS_D->usable_feat(TO, "tough skin")) {
        num = to_int(to_float(i) * 1.33);
        stoneSkinned = num;
    }else {
        stoneSkinned = i;
    }
}

int query_stoneSkinned()
{
    return stoneSkinned;
}

int fort_save(int save)
{
    return "/daemon/saving_throw_d.c"->fort_save(TO, (save * -1));
}

int reflex_save(int save)
{
    return "/daemon/saving_throw_d.c"->reflex_save(TO, (save * -1));
}

int will_save(int save)
{
    return "/daemon/saving_throw_d.c"->will_save(TO, (save * -1));
}

void set_missChance(int i)
{
    int num;
    if (i < 0) {
        return;
    }
/*
    if(FEATS_D->usable_feat(TO,"slippery caster"))
    {
        num = to_int(to_float(i) * 1.33);
        missChance = num;
    }
    else missChance = i;
 */
    missChance = i;
}

int query_missChance()
{
    return missChance;
}

void set_shieldMiss(int i)
{
    int num;
    if (i < 0) {
        return;
    }
    shieldMiss = i;
}

void add_shieldMiss(int i)
{
    if (!intp(i)) {
        return;
    }
    shieldMiss += i;
}

int query_shieldMiss()
{
    object shield, * equip;
    int i, chance, enchant;

    if (TO->is_wearing_type("shield") || TO->is_wearing_type("thiefshield")) {
        chance = (shieldMiss + EQ_D->gear_bonus(TO, "shieldMiss"));
        if (FEATS_D->usable_feat(TO, "deflection")) {
            chance += 15;
        }                                                           // +15% for deflection feat(might need tweaking)
        chance += (int)TO->query_property("shieldwall_bonus");

        equip = (object)TO->all_armour();
        if (sizeof(equip)) {
            for (i = 0; i < sizeof(equip); i++) {
                if (!objectp(equip[i])) {
                    continue;
                }
                if ((string)equip[i]->query_type() != "shield" && (string)equip[i]->query_type() != "thiefshield") {
                    continue;
                }
                shield = equip[i];
                break;
            }

            enchant = (int)shield->query_property("enchantment");

            chance += enchant * 2;
        }
        return chance;
    }else {
        return 0;
    }
}

int query_spellTurning() {
    int turnperc, reflection, flag;
    turnperc = 0;

    if (FEATS_D->usable_feat(TO, "spell reflection")) {
        turnperc = (int)TO->query_skill("spellcraft") / 4;
        flag = 1;
    }

    if (FEATS_D->usable_feat(TO, "reflection") && TO->is_wearing_type("shield")) {
        reflection = (int)TO->query_skill("athletics") / 4;
        turnperc = turnperc < reflection ? reflection : turnperc;
    }
    //This was on spell.c, i think it's for monsters that have the feat but no skill.
    if ((flag || reflection) && !turnperc) {
        turnperc = 15;
    }

    if ((int)TO->query_property("spellturning")) {
        reflection = (int)TO->query_property("spellturning");
        turnperc = turnperc < reflection ? reflection : turnperc;
    }

    if (turnperc < 0) {
        turnperc = 0;
    }

    if (!turnperc) {
        return 0;
    }

    if (turnperc > 85) {
        turnperc = 85;
    }
    return turnperc;
}

void add_hp(int x)
{
    int num;

    player_data["general"]["hp"] += x;

    if (player_data["general"]["hp"] > query_max_hp()) {
        player_data["general"]["hp"] = query_max_hp();
    }

    //if(player_data["general"]["hp"] > player_data["general"]["max_hp"]) player_data["general"]["hp"] = player_data["general"]["max_hp"];
    // if(player_data["general"]["hp"] < 1) this_object()->die();
    //   player_data["general"]["hp"] = 0;
    if (x >= 0) {
        return;
    }
    if (query_max_hp()) {
        message("damage", "%^BOLD%^%^RED%^Hp: %^RESET%^" + query_hp() + " " + (query_hp() * 100) / query_max_hp() + "%", TO);
    } else {
        message("damage", "%^BOLD%^%^RED%^Hp: %^RESET%^" + query_hp() + " ERROR! Contact a Wiz!", TO);
    }
}

void set_max_sp(int x)
{
    player_data["general"]["max_sp"] = x;
}

void set_max_mp(int x)
{
    if (!magic) {
        magic = ([]);
    }
    magic["max points"] = x;
}

int query_max_mp()
{
    if (mapp(magic)) {
        return magic["max points"];
    }
    return 0;
}

void set_mp(int x)
{
    if (!query_max_mp()) {
        magic["max points"] = x;
    }
    if (x > query_max_mp()) {
        if (this_object()->is_player()) {
            magic["points"] = query_max_mp();
        } else {
            magic["max points"] = x;
            magic["points"] = x;
        }
    } else {
        magic["points"] = x;
    }

    if (magic["points"] < 0) {
        magic["points"] = 0;
    }
}

void add_mp(int x)
{
    if (!magic) {
        magic = ([ "points" : 0, "max points" : 0 ]);
    }
    magic["points"] += x;
    if (magic["points"] > magic["max points"]) {
        magic["points"] = magic["max points"];
    }
    if (magic["points"] < 0) {
        magic["points"] = 0;
    }
}

int query_mp()
{
    if (mapp(magic)) {
        return magic["points"];
    }else {
        return 0;
    }
}

//  This function is only for lazy wizzes to use when creating monsters!!
void set_overall_ac(int x)
{
    ac = x;
    monster_ac = x;
}

void set_ac(int x)
{
    /* if(userp(TO)) */
    /* { */
    /*  log_file("armor_class_changes", "\n\nAC SET : " + */
    /*  TO->query_name() + " : AC changed from "+ */
    /*  "(ac = "+ac+") to (new ac = "+x+") : set_ac() called by "+ */
    /*  identify(previous_object())+"."); */
    /* } */
    ac = x;
}

int add_limb(string limb_name, string limb_ref, int max_dam, int curr_dam, int limb_ac)
{
    body[limb_name] = ([ "limb_ref" : limb_ref, "max_dam" : max_dam, "damage" : curr_dam, "ac" : limb_ac ]);
    if (!limbs) {
        limbs = ({});
    }
    limbs += ({ limb_name });
    body[limb_name]["armour"] = ({});
    body[limb_name]["armour_ob"] = ({});
    body[limb_name]["weapons"] = 0;
    if (!severed) {
        return 1;
    }
    if (severed[limb_name]) {
        map_delete(severed, limb_name);
    }
    return 1;
}

int set_fake_limbs(string* limbs)
{
    if (!pointerp(limbs) || !sizeof(limbs)) {
        return 0;
    }
    fake_limbs = limbs;
    return 1;
}

int remove_fake_limbs()
{
    fake_limbs = ({});
}

string* query_fake_limbs()
{
    return fake_limbs;
}

void augment_body(int x)
{
    int tmp;
    int dam, i;
    string b_type;

    if ((string)this_object()->query_race() == "satyr") {
        if (member_array("left foot", limbs) != -1) {
            remove_limb("left foot");
            map_delete(severed, "left foot");
        }
        if (member_array("right foot", limbs) != -1) {
            remove_limb("right foot");
            map_delete(severed, "right foot");
        }
        if (severed && severed["left foot"]) {
            map_delete(severed, "left foot");
        }
        if (severed && severed["right foot"]) {
            map_delete(severed, "right foot");
        }
    }
    b_type = this_object()->query_body_type();
    if (b_type != 0) { // must be a monster  added by Val June 30, 1993
        for (i = 0, tmp = sizeof(limbs); i < tmp; i++) {
            body[limbs[i]]["max_dam"] =
                query_max_hp() / ((int)RACE_D->query_max_mon_dam(limbs[i], b_type));
        }
        return;
    }
    for (i = 0, tmp = sizeof(limbs); i < tmp; i++) {
        body[limbs[i]]["max_dam"] = query_max_hp() / ((int)RACE_D->query_max_dam(limbs[i], (string)this_object()->query_race()));
    }
}

//  This function removes a limb
int remove_limb(string limb_name)
{
    if (body[limb_name]) {
        severed[limb_name] = body[limb_name]["limb_ref"];
        map_delete(body, limb_name);
        limbs -= ({ limb_name });
        return 1;
    }
    return 0;
}

//  This function returns a random limb
string return_limb()
{
    if (sizeof(fake_limbs)) {
        return fake_limbs[random(sizeof(fake_limbs))];
    }
    return limbs[random(sizeof(limbs))];
}

//  This function returns a random limb
string return_target_limb()
{
    if (sizeof(limbs) < 1) {
        tell_object(TO, "You have no limbs. Please get a body");
        return "body";
    }

    if (sizeof(fake_limbs)) {
        return fake_limbs[random(sizeof(fake_limbs))];
    }

    if (!limbs) {
        return "body";
    }else {
        return limbs[random(sizeof(limbs))];
    }
}

string return_real_limb()
{
    if (!limbs || !pointerp(limbs) || !sizeof(limbs)) {
        return "body";
    }else {
        return limbs[random(sizeof(limbs))];
    }
}

string* query_limbs()
{
    if (sizeof(fake_limbs)) {
        return fake_limbs;
    }
    return limbs;
}

int query_is_limb(string limb)
{
    if (sizeof(fake_limbs)) {
        if (member_array(limb, fake_limbs) == -1) {
            return 0;
        }
        return 1;
    }
    if (member_array(limb, limbs) != -1) {
        return 1;
    }else {
        return 0;
    }
}

int query_true_max_hp()
{
    return player_data["general"]["max_hp"];
}

int query_max_hp_base()
{
    int num, mypsi;
    string file, myrace, subrace;

    if (!objectp(TO)) {
        return 0;
    }
    if (!userp(TO)) {
        num = player_data["general"]["max_hp"];
        num = WORLD_EVENTS_D->monster_modification_event(num, "health", TO);
        num = num < 1 ? 1 : num;
        return num;
    }

    if (TO->is_undead()) {
        num = "/daemon/bonus_d.c"->query_con_bonus((int)TO->query_stats("charisma"));
    }else {
        num = "/daemon/bonus_d.c"->query_con_bonus((int)TO->query_stats("constitution"));
    }

    num = num * (int)TO->query_highest_level();

    if (FEATS_D->usable_feat(TO, "toughness")) {
        num += ((int)TO->query_level()) / 2;
    }

    if (FEATS_D->usable_feat(TO, "improved toughness")) {
        num += TO->query_level();
    }

    if (FEATS_D->usable_feat(TO, "epic toughness")) {
        num += TO->query_level();
    }

    if (FEATS_D->usable_feat(TO, "psionic body")) {
        mypsi = 0;
        mypsi += FEATS_D->calculate_psionic_feats(TO);
        if (mypsi < 1) {
            mypsi = 1;
        }
        mypsi = mypsi * 5;
        if (FEATS_D->usable_feat(TO, "battle psyche")) {
            mypsi = mypsi * 3;
        }
        num += mypsi;
    }

    myrace = (string)TO->query_race();
    subrace = (string)TO->query("subrace");

    if (intp(USER_D->get_scaled_level(TO))) {
        num += sum_array(TO->query("hp_array"), (int)TO->query_base_character_level());
        num = WORLD_EVENTS_D->monster_modification_event(num, "health", TO);
        return num;
    }
    num += player_data["general"]["max_hp"];
    return num;
}

int query_max_hp()
{
    return query_max_hp_base() + query_max_hp_bonus() + 1;
}

int query_hp()
{
    if (!player_data) {
        player_data = ([ "general" : ([ "hp" : 1, "extra_hp" : 0, "max_hp" : 30, "sp" : 1, "max_sp" : 1])]);
    }
    return player_data["general"]["hp"] + player_data["general"]["extra_hp"];
}

string query_reference(string limb)
{
    if (body[limb]) {
        return body[limb]["limb_ref"];
    }
}

/////////////////////////////
// resistance stuff below  //
/////////////////////////////


void clear_resistances()
{
    resistances = ([]);
    return;
}

int valid_resistance(string str)
{
    if (member_array(str, VALID_DAMAGE_TYPES) == -1) {
        return 0;
    }
    return 1;
}

void set_resistance(string res, int num)
{
    int value;

    if (!valid_resistance(res)) {
        return;
    }
    value = resistances["resistance"][res];
    value += num;
    resistances["resistance"][res] = value;
}

void set_resistance_percent(string res, int num)
{
    int value;

    if (!valid_resistance(res)) {
        return;
    }
    value = resistances["resistance percents"][res];
    value += num;
    resistances["resistance percents"][res] = value;
}

int query_resistance(string res)
{
    int myres;
    string *domains;
    
    if (!valid_resistance(res)) {
        return 0;                        // to avoid throwing errors on any invalid queries. N, 8/15.
    }
    myres = resistances["resistance"][res];
    if (((string)TO->query("subrace") == "aasimar" || (string)TO->query("subrace") == "feytouched") && (res == "acid" || res == "cold" || res == "electricity")) {
        myres += 5;
    }
    if ((string)TO->query("subrace") == "tiefling" && (res == "cold" || res == "fire" || res == "electricity")) {
        myres += 5;
    }
    if (FEATS_D->usable_feat(TO, "energy resistance")) {
        if ((string)TO->query("warlock heritage") == "celestial" && res == "acid") {
            myres += 10;
        }
        if ((string)TO->query("warlock heritage") == "fey" && res == "sonic") {
            myres += 10;
        }
        if ((string)TO->query("warlock heritage") == "demonic" && res == "electricity") {
            myres += 10;
        }
		if((string)TO->query("warlock heritage") == "star" && res == "psychic") {
            myres += 10;
        }
        if ((string)TO->query("warlock heritage") == "gloom" && res == "cold") {
            myres += 10;
        }
        if ((string)TO->query("warlock heritage") == "infernal" && res == "fire") {
            myres += 10;
        }
    }

    if (TO->query_race() == "squole") {
        string subrace = TO->query("subrace");
        if (stringp(subrace)) {
            if ((subrace == "ice" && res == "cold") ||
                (subrace == "magma" && res == "fire") ||
                (subrace == "ooze" && res == "acid")) {
                myres += TO->query_base_character_level();
            }
        }
    }
    
    //Cleric domain-specific resistances
    domains = TO->query_divine_domain();
    
    if(sizeof(domains))
    {
        switch(res)
        {
            case "fire":
            if(member_array("fire", domains) >= 0)
                myres += TO->query_class_level("cleric");
            break;
            
            case "cold":
            if(member_array("cold", domains) >= 0)
                myres += TO->query_class_level("cleric");
            break;
            
            case "acid":
            if(member_array("earth", domains) >= 0)
                myres += TO->query_class_level("cleric");
            break;
            
            case "electricity":
            if(member_array("air", domains) >= 0)
                myres += TO->query_class_level("cleric");
        }
    }              

    if (TO->query_race() == "shade") {
        if (res == "cold" || res == "electricity") {
            myres += 5;
        }
    }

    if (FEATS_D->usable_feat(TO, "no fear of the flame") && res == "fire") {
        myres += 10;
    }
    return (myres + EQ_D->gear_bonus(TO, res));
}

int query_resistance_percent(string res)
{
    int mod = 0;

    if (!valid_resistance(res)) {
        return 0;
    }
    if (TO->is_undead()) {
        if (res == "fire") {
            mod += -25;
        }
        if (res == "cold") {
            mod += 50;
        }
        if (TO->is_vampire()) {
            if (res == "electricity") {
                mod += 50;
            }
            if (res == "divine") {
                mod += -25;
            }
            if (res == "silver") {
                mod += -25;
            }
        }
    }

    if (res == "fire" && TO->query_race() == "troll") {
            mod += -15;
    }
    
    if(FEATS_D->usable_feat(TO, "perfection"))
    {
        if(res == "electricity" || res == "cold" || res == "acid")
            mod = 100;
    }

    if(TO->is_class("cleric"))
    {
        if(res == "fire" || res == "cold" || res == "acid" || res == "electricity")
        {
            if(member_array("elements", TO->query_divine_domain()) >= 0 )
                mod += 25;
        }
    }
    
    //Mage is invulnerable for duration of prismatic sphere
    if(TO->query_property("prismatic sphere"))
        mod = 100;

    return resistances["resistance percents"][res] + mod;
}

void set_resistances(mapping map)
{
    resistances["resistance"] = map;
}

void set_resistance_percents(mapping map)
{
    resistances["resistance percents"] = map;
}

mapping query_resistances()
{
    return resistances["resistance"];
}

mapping query_resistance_percents()
{
    return resistances["resistance percents"];
}

int initialized_resistances()
{
    if (!mapp(resistances) || !sizeof(keys(resistances))) {
        return 0;
    }
    return 1;
}

int cause_typed_damage(object targ, string limb, int damage, string type)
{
    object attacker;
    int amt;
    if (!objectp(attacker = targ->query_property("beingDamagedBy"))) {
        attacker = previous_object();
    }
    damage = (int)COMBAT_D->typed_damage_modification(attacker, targ, limb, damage, type);
    return targ->cause_damage_to(targ, limb, damage);
}

int query_magic_attack()
{
    return magic_attack;
}

int query_spell_attack()
{
    return spell_attack;
}

int set_magic_attack(int x)
{
    magic_attack = x;
}

int set_spell_attack(int x)
{
    spell_attack = x;
}

void set_base_damage_type(string str)
{
    if (!valid_resistance(str)) {
        base_damage_type = "bludgeoning"; //was untyped, changing default to bludgeoning - Odin 3/22/2020
    }
    base_damage_type = str;
}

void query_base_damage_type()
{
    object shape;

    if (!base_damage_type || base_damage_type == "" || base_damage_type == " ") {
        base_damage_type = "bludgeoning"; //was untyped, changing default to bludgeoning - Odin 3/22/2020
    }

    if (objectp(shape = TO->query_property("shapeshifted"))) {
        base_damage_type = (string)shape->get_new_damage_type();
    }

    return base_damage_type;
}

/////////////////////////////
// end resistance stuff    //
/////////////////////////////

int cause_damage_to(object vic, string limb, int damage)
{
    if (!objectp(vic)) {
        return 0;
    }
    return vic->do_damage(limb, damage);
}

int do_damage(string limb, int damage)
{
    object myspl, attacker;
    int i, num, layers, lvladj, mypsi, mod;
    string real_limb, file, myrace, subrace;
    mapping logdata;

    real_limb = return_real_limb(); // used for armor decay when shifted

    if (sizeof(fake_limbs)) {
        if (member_array(limb, fake_limbs) == -1) {
            limb = TO->return_target_limb();
        }
    }else if (member_array(limb, limbs) < 0) {
        limb = TO->return_target_limb();
        real_limb = limb;
    }else {
        real_limb = limb;
    }

    /*if (damage > 0 && TO->isPkill())
       {
       damage = ((damage*PK_DAMAGE_PERCENTAGE)/100);
       }*/

    // added to stop doing damage in pkills when a player is at -100% health.  Should prevent
    // MOST accidental pkills -Ares 4/12/06
    if (query_hp() < (-1 * query_max_hp())) {
        if (damage > 0) {
            damage = 0;
        }                              // stuck this here so they'll heal if they're knocked out below -100% -Ares
    }
    if (!objectp(attacker = TO->query_property("beingDamagedBy"))) {
        attacker = previous_object();
    }
    damage = (int)COMBAT_D->damage_adjustment(attacker, TO, damage);

    TO->set_magic_attack(0); // needed to keep track of bypassing stoneskin for the typed damage function -Ares
    TO->set_spell_attack(0);

    if (query_property("memorizing") && (damage > 0)) {
        remove_property("memorizing");
        message("damage", "%^BOLD%^%^GREEN%^Your foe interrupts your mental activity!", TO);
    }

    if (query_extra_hp() && damage > 0) {
        add_extra_hp(-1 * damage);
        //if(query_extra_hp() < 0)    player_data["general"]["hp"] += query_extra_hp();
        if (query_extra_hp() < 0) {
            player_data["general"]["hp"] += query_extra_hp();
            add_extra_hp(0 - query_extra_hp());
        }
    }else {
        if (!intp(player_data["general"]["hp"])) {
            init_limb_data();
        }
        player_data["general"]["hp"] -= damage;
    }

    if (damage > 0 && userp(TO)) {
        if (!mapp(body) || !mapp(body[real_limb]) || !pointerp(body[real_limb]["armour_ob"])) {
            augment_body(0);
        }
        if (body[real_limb]["armour_ob"]) {
            body[real_limb]["armour_ob"]->decay();
        }
    }

    num = TO->query_max_hp();

    if (num < player_data["general"]["hp"]) {
        player_data["general"]["hp"] = num;
    }

    if (query_max_hp()) {
        message("damage", "%^BOLD%^%^RED%^Hp: %^RESET%^" + query_hp() + "    " + (query_hp() * 100) / query_max_hp() + "%", TO);
    }else {
        message("damage", "%^BOLD%^%^RED%^Hp: %^RESET%^" + query_hp() + "    ERROR! Contact a Wiz!", TO);
    }
    if (TO->query_property("damage tester")) {
        tell_object(TO, "%^BOLD%^%^RED%^You took " + damage + " damage and received melee DR of " + mod + ".");
    }
    return damage;
}

int query_base_ac()
{
    return ac;
}

int query_ac()
{
    int myac, raceac, shifted_ac, myLev;
    string myfile, myrace, mysubrace;
    object shape, attacker;

    if (!userp(TO) && !TO->query_property("full ac")) {
        return monster_ac;
    }
    myac = (ac_bonus + EQ_D->gear_bonus(TO, "armor bonus"));
    if (FEATS_D->usable_feat(TO, "unarmored defense") && TO->is_ok_armour("barb")) {
        myac += 6;
    }
    if (TO->is_class("monk")) {
        myac += (int)"/daemon/bonus_d.c"->query_stat_bonus(TO, "wisdom");
    }
    if (FEATS_D->usable_feat(TO, "indomitable")) {
        myac += 2;
    }
    if (FEATS_D->usable_feat(TO, "mobility") && !TO->query_paralyzed() &&
        !TO->query_tripped() && !TO->query_bound() && TO->is_ok_armour("thief")) {
        myac += 4;
    }

    if(FEATS_D->usable_feat(TO, "canny defense") && !TO->query_paralyzed() &&
       !TO->query_tripped() && !TO->query_bound() && TO->is_ok_armour("thief"))
           myac += BONUS_D->query_stat_bonus(TO, "intelligence");
       
    if(FEATS_D->usable_feat(TO, "spiritual body") && !TO->query_paralyzed() &&
       !TO->query_tripped() && !TO->query_bound())
           myac += BONUS_D->query_stat_bonus(TO, "charisma");

    if (TO->query_blind() || TO->query_temporary_blinded()) {
        myac -= TO->query_level() / 12 + 1;
    }

    attacker = TO->query_current_attacker();

    if(attacker && FEATS_D->usable_feat(TO, "resist undead") && attacker->is_undead())
        myac += 8;

    if (!userp(TO)) {
        return ac - myac;
    }

    // adding racial bonus here for players
    myrace = (string)TO->query_race();
    if (!myrace) {
        return ac - myac;
    }
    mysubrace = (string)TO->query("subrace");
    myfile = "/std/races/" + myrace + ".c";
    if (!file_exists(myfile)) {
        return ac - myac;
    }
    raceac = (int)myfile->natural_AC(mysubrace);

    if (objectp(shape = TO->query_property("shapeshifted"))) {
        shifted_ac = (int)shape->query_bonus_ac();
    }

    return ac - myac - raceac - shifted_ac;
}

int query_ac_bonus()
{
    int myac;
    myac = ac_bonus;
    if (FEATS_D->usable_feat(TO, "indomitable")) {
        myac += 2;
    }
    if (FEATS_D->usable_feat(TO, "mobility") &&
        !TO->query_paralyzed() &&
        !TO->query_tripped() &&
        !TO->query_bound() &&
        TO->is_ok_armour("thief")) {
        myac += 4;
    }
    return (myac + EQ_D->gear_bonus(TO, "armor bonus"));
}

int set_ac_bonus(int x)
{
    ac_bonus = x;
}

void add_ac_bonus(int x)
{
    ac_bonus += x;
}

void reset_ac_bonus()
{
    ac_bonus = 0;
}

//Function to Apply/Remove bonuses to items - things such
//as attack/damage/light, etc.  On wear/unwear/wield/unwield
//and possibly when a static object - such as an orb -
//is moved. - Saide
//                      item           player
void ApplyObjectBonuses(object ob, object targ, string which, string type)
{
    mapping info;
    string bonus_name, bonus_extra, * items = ({}), * bskills;
    mixed prop;
    int cur_bonus = 0, x, i, num = 0;
    if (!objectp(ob)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    if (type == "wield" && !ob->is_weapon()) {
        return;
    }
    if (type == "wear" && !ob->is_armor()) {
        return;
    }
    if ((type == "move" && ob->is_weapon()) || (type == "move" && ob->is_armor())) {
        return;
    }
    if ((type == "move" && !ob->is_weapon()) || (type == "move" && !ob->is_armor())) {
        if (!ob->query_property("inanimate_bonus")) {
            return;
        }
    }
    if (targ->query_property("no bonuses")) {
        return;
    }
    if (!stringp(which)) {
        return;
    }
    if (!stringp(type)) {
        return;
    }
    for (x = 0; x < sizeof(VALID_BONUSES); x++) {
        bonus_name = VALID_BONUSES[x];
        if (!ob->BonusCheck(bonus_name)) {
            continue;
        }
        prop = ob->query_property(bonus_name);
        if (!prop) {
            continue;
        }
        if (bonus_name == "skill bonus") {
            if (!mapp(prop)) {
                continue;
            }
            bskills = keys(prop);
            for (i = 0; i < sizeof(bskills); i++) {
                bonus_extra = bskills[i];
                if (!stringp(bonus_extra)) {
                    continue;
                }
                cur_bonus = prop[bskills[i]];
                if (!intp(cur_bonus)) {
                    continue;
                }
                if (which == "remove") {
                    cur_bonus = 0 - cur_bonus;
                }
                targ->add_skill_bonus(bonus_extra, cur_bonus);
                continue;
            }
            continue;
        }else {
            cur_bonus = to_int(prop);
        }
        if (!intp(cur_bonus)) {
            continue;
        }
        if (which == "remove") {
            cur_bonus = 0 - cur_bonus;
        }
        if (bonus_name == "attack bonus") {
            targ->add_attack_bonus(cur_bonus);
            continue;
        }
        if (bonus_name == "damage bonus") {
            targ->add_damage_bonus(cur_bonus);
            continue;
        }
        if (bonus_name == "sight bonus") {
            targ->add_sight_bonus(cur_bonus);
            continue;
        }
        //making set_property("skill bonus") on items
        //to function as a mapping - and moving this up -
        //this way we can have objects that might
        //give 2 or 3 skill bonuses - Saide
        /*if(bonus_name == "skill bonus")
           {
            targ->add_skill_bonus(bonus_extra, cur_bonus);
            continue;
           }*/
        if (bonus_name == "ac bonus") {
            if (which == "remove") {
                cur_bonus = 0;
            }
            targ->set_ac_bonus(cur_bonus);
            continue;
        }
        if (bonus_name == "magic resistance" || bonus_name == "magic" ||
            bonus_name == "empowered" || bonus_name == "spell penetration" ||
            strsrch(bonus_name, "bonus_spell_slots") != -1) {
            targ->set_property(bonus_name, cur_bonus);
            continue;
        }
    }
    return;
}

//END OF BONUS APPLYING FUNCTION


string equip_weapon_to_limb(object weap, string limb1, string limb2)
{
    if (member_array(limb1, limbs) == -1) {
        return "You have no " + limb1 + "!\n";
    }
    if (wielded_objects[limb1]) {
        return "You are already wielding something in your " + limb1 + "!\n";
    }
    if (member_array("shield", body[limb1]["armour"]) != -1
        || member_array("thiefshield", body[limb1]["armour"]) != -1) {
        return "You cannot wield a weapon while wearing a shield in your " + limb1 + ".\n";
    }
    if (!body[limb1]["wieldable"]) {
        return "You cannot wield a weapon with a " + limb1 + "!\n";
    }
    if (limb2) {
        if (!body[limb2]) {
            return "You do not have a " + limb2 + "!\n";
        }
        if (wielded_objects[limb2]) {
            return "You are wielding something with your " + limb2 + ".\n";
        }
        if (member_array("shield", body[limb2]["armour"]) != -1
            || member_array("thiefshield", body[limb2]["armour"]) != -1) {
            return "You cannot wield a weapon where you wear a shield.\n";
        }
        if (!body[limb2]["wieldable"]) {
            return "You cannot wield anything with your " + limb2 + ".\n";
        }
        //ac -= (int)weap->query_ac();
        body[limb2]["weapons"] = weap;
        wielded_objects[limb2] = weap;
    }
    ac -= (int)weap->query_ac();
    body[limb1]["weapons"] = weap;
    wielded_objects[limb1] = weap;
    if (TO->is_player()) {
        ApplyObjectBonuses(weap, TO, "add", "wield");
    }
    num_wielded++;

    if (sizeof(wielded_objects) > 1) {
        if (wielded_objects[limb1] == wielded_objects[limb2]) {
            TO->set_combat_stance("two hander");
        }else {
            TO->set_combat_stance("dual wield");
        }
    } else if (limb1) {
        if (TO->validate_combat_stance("unarmed and shield")) {
            TO->set_combat_stance("weapon and shield");
        }
        else {
            TO->set_combat_stance("one hander");
        }
    }
    check_weapon_active_feats(num_wielded);

    return 0;
}

int remove_weapon_from_limb(object ob)
{
    int i;
    string* ind;

    ind = keys(wielded_objects);
    for (i = 0; i < sizeof(ind); i++) {
        if (wielded_objects[ind[i]] == ob) {
            map_delete(wielded_objects, ind[i]);
            body[ind[i]]["armour"] -= ({ "weapon" });
            body[ind[i]]["armour_ob"] -= ({ ob });
            body[ind[i]]["weapons"] = 0;
            //ac += (int)ob->query_ac();
        }
    }
    ac += (int)ob->query_ac();
    num_wielded--;

    if (TO->is_player()) {
        ApplyObjectBonuses(ob, TO, "remove", "wield");
    }

    if (num_wielded) {
        TO->set_combat_stance("one hander");
    }else if (TO->validate_combat_stance("weapon and shield")) {
        TO->set_combat_stance("unarmed and shield");
    }else {
        TO->set_combat_stance("unarmed");
    }
    check_weapon_active_feats(num_wielded);

    return 1;
}

void check_weapon_active_feats(int numwielded) {
    int bonus_value;
    object deactivate_feat, * active_feats;
    int i;
    //positioning
    bonus_value = (int)TO->query_property("tactical_positioning");
    if (bonus_value) {
        message("my_action", "You can only benefit from positioning with a single one-handed weapon.", TO);
        TO->set_property("tactical_positioning", -bonus_value);
        TO->add_ac_bonus(-bonus_value);
        TO->add_attack_bonus(bonus_value);
    }
    //magus options
    if ((int)TO->query_property("enruned offhand")) {
        active_feats = TO->query_property("active_feats");
        for (i = 0;sizeof(active_feats), i < sizeof(active_feats);i++) {
            if (!objectp(active_feats[i])) { continue; }
            if (active_feats[i]->query_feat_name() != "enruned offhand") { continue; }
            deactivate_feat = active_feats[i];
            break;
        }
        deactivate_feat->dest_effect();
    }
    if ((int)TO->query_property("enruned great weapon")) {
        active_feats = TO->query_property("active_feats");
        for (i = 0;sizeof(active_feats), i < sizeof(active_feats);i++) {
            if (!objectp(active_feats[i])) { continue; }
            if (active_feats[i]->query_feat_name() != "enruned great weapon") { continue; }
            deactivate_feat = active_feats[i];
            break;
        }
        deactivate_feat->dest_effect();
    }
    //spell combat
    if ((int)TO->query_property("magus cast") && numwielded != 1) {
        active_feats = TO->query_property("active_feats");
        for (i = 0;sizeof(active_feats), i < sizeof(active_feats);i++) {
            if (!objectp(active_feats[i])) { continue; }
            if (active_feats[i]->query_feat_name() != "spell combat") { continue; }
            deactivate_feat = active_feats[i];
            break;
        }
        deactivate_feat->dest_effect();
        message("my_action", "You can only benefit from spell combat with a single one-handed melee weapon.", TO);
    }
    //enhance, not a feat
    if ((int)TO->query_property("weapon enhancement timer") && numwielded == 0) {
        "/cmds/mortal/_enhance.c"->off_enhances(TO, "weapon");
    }
}

string size_ok(string type, object arm)
{
    if (!userp(TO)) {
        arm->set_size(TO->query_size());
        return 0;
    }
    if (member_array(type, SIZEDTYPES) == -1) {
        return 0;
    }
    // Support for universal size here...
    if ((int)arm->query_size() == SIZE_UNIVERSAL) {
        return 0;
    }
    // End Universal Size...
    if ((int)arm->query_size() > (int)TO->query_size()) {
        return "That is too large for you.";
    }
    if ((int)arm->query_size() < (int)TO->query_size()) {
        return "That is too small for you.";
    }
    return 0;
}

string type_ok(string type, string limb)
{
    int worn, x, i;

    if (!body[limb]) {
        return "You have no " + limb + "!\n";
    }
    if (type == "jewelry" || type == "clothing") {
        if (member_array("jewelry", body[limb]["armour"]) != -1 || member_array("clothing", body[limb]["armour"]) != -1) {
            worn = 1;
        }else {
            worn = 0;
        }
    } else {
        if (member_array(type, body[limb]["armour"]) != -1) {
            worn = 1;
        }else {
            worn = 0;
        }
    }
    switch (type) {
    case "shield":
    case "thiefshield":
        if (worn || member_array("thiefshield", body[limb]["armour"]) != -1 || member_array("shield", body[limb]["armour"]) != -1) {
            return "You are already wearing a shield!\n";
        }else if (wielded_objects[limb]) {
            return "You cannot wear a shield while you are wielding a weapon in your " + limb + ".\n";
        }else {
            return 0;
        }
        break;

    case "leather":
        if (member_array("armour", body[limb]["armour"]) != -1 || (member_array("chain", body[limb]["armour"]) != -1)) {
            return "You cannot wear regular armour with leather armour.\n";
        }else if (worn) {
            return "You are already wearing leather armour!\n";
        }else {
            return 0;
        }
        break;

    case "bracer":
        if (member_array("armour", body[limb]["armour"]) != -1 || member_array("chain", body[limb]["armour"]) != -1) {
            return "You cannot wear regular armour or chain armour with bracers.\n";
        }else if (worn) {
            return "You are already wearing leather armour!\n";
        }else {
            return 0;
        }
        break;

    case "chain":
        if (member_array("armour", body[limb]["armour"]) != -1 || member_array("leather", body[limb]["armour"]) != -1 || member_array("bracer", body[limb]["armour"]) != -1) {
            return "You cannot wear regular armour or bracers with chain armour.\n";
        }else if (worn) {
            return "You are already wearing leather armour!\n";
        }else {
            return 0;
        }
        break;

    case "ring":
        i = 0;
        x = sizeof(body[limb]["armour_ob"]);
        while (x--) {
            if (!objectp(body[limb]["armour_ob"][x])) {
                continue;
            }
            if (body[limb]["armour_ob"][x]->query_type() == "ring") {
                i++;
            }
        }
        if (i > all_my_fingers - 1) {
            return "You do not have that many fingers on your " + limb + ".\n";
        }else {
            return 0;
        }
        break;

    case "armour":
        if ((member_array("leather", body[limb]["armour"]) != -1) || (member_array("chain", body[limb]["armour"]) != -1) || (member_array("bracer", body[limb]["armour"]) != -1)) {
            return "You may not wear leather or chain armour and armour at the same time.\n";
        }else if (worn) {
            return "You may only wear one piece of body armour at a time.\n";
        }else {
            return 0;
        }
        break;

    case "jewelry":
    case "clothing":
        if (worn) {
            return "You may only wear one of those at a time.\n";
        }else {
            return 0;
        }
        break;

    case "sheath":
        return 0;

        break;

    default:
        if (worn) {
            return "You may only wear one armour of type " + type + " at a time.\n";
        }else {
            return 0;
        }
        break;
    }
    return "Error in wearing armour.\n";
}

string stack_ok(string type, string limb)   //new function to moderate 3.5 style armor slots & stacking
// new slots are only: head, neck, torso, wrists (bracers/gloves), hands (rings), waist, legs, feet - 2 for hands gives 9 slots total.
{
    object* limbarmor;
    int i, ringcounter;

    if (type == "shield" || type == "thiefshield") {
        return 0;                                          //shields are on arms; should stack with gloves/bracers.
    }
    ringcounter = 0;
    limbarmor = ({});
    limbarmor += body[limb]["armour_ob"];
    if (!sizeof(limbarmor)) {
        return 0;
    }
    for (i = 0; i < sizeof(limbarmor); i++) {
        if ((string)limbarmor[i]->query_type() == "shield" || (string)limbarmor[i]->query_type() == "thiefshield") {
            continue;
        }
        if ((int)limbarmor[i]->query_property("enchantment") || sizeof(limbarmor[i]->query_item_bonuses()) || (int)limbarmor[i]->query_property("magic nonstacking")) {
            if ((limb != "left hand" && limb != "right hand") || ringcounter) {
                return "You are already wearing equipment with magical properties on your " + limb + ".\n";
            }
            if (limb == "left hand" || limb == "right hand") {
                ringcounter = 1;                                        // to allow 2 ring slots; if one is found and tracked here, the next will deny any further.
            }
        }
    }
    return 0;
}

string equip_armour_to_limb(object arm, string* limb)
{
    int i, j, flag;
    function f;
    string y, type, * tmp;

    type = (string)arm->query_type();
    i = sizeof(limb);
    while (i--) {
        if ((y = type_ok(type, limb[i]))) {
            return y;
        }
    }

// new loop to prevent stacking of magical items in the same slot! N, 7/12
    if ((int)arm->query_property("enchantment") || sizeof(arm->query_item_bonuses()) || (int)arm->query_property("magic nonstacking")) {
        i = sizeof(limb);
        while (i--) {
            if ((y = stack_ok(type, limb[i]))) {
                return y;
            }
        }
    }

    f = (: call_other, arm, (string)arm->query_wear() :);
    if ((y = size_ok(type, arm))) {
        return y;
    }
    if (arm->query_property("fwear") && !(*f)()) {
        return "NO";
    }
    body[limb[0]]["armour"] += ({ type });
    body[limb[0]]["armour_ob"] += ({ arm });
    /* if(userp(TO)) */
    /* { */
    /*  log_file("armor_class_changes", "\n\nAC Change : " + TO->query_name() +" "+ */
    /*  "gained AC from "+identify(arm) + " - Ac went from ("+ */
    /*  ac +") to ("+(ac-(int)arm->query_ac())+").  Function "+ */
    /*  "equip_armour_to_limb() called from "+ */
    /*  identify(previous_object()) +"."); */
    /* } */

    if (type == "shield") {
        if (TO->validate_combat_stance("one hander")) {
            TO->set_combat_stance("weapon and shield");
        }else {
            TO->set_combat_stance("unarmed and shield");
        }
    }
    check_armor_active_feats(TO, type, (string)limb[0], "equip");

    ac -= (int)arm->query_ac();
    return 0;
}

int remove_armour_from_limb(object arm, string* limb)
{
    int i;
    string type;

    type = (string)arm->query_type();
    for (i = 0; i < sizeof(limb); i++) {
        if (!body) {
            continue;
        }
        if (!body[limb[i]]) {
            continue;
        }
        if (member_array(type, body[limb[i]]["armour"]) != -1) {
            body[limb[i]]["armour"] -= ({ type });
        }
        body[limb[i]]["armour_ob"] -= ({ arm });
    }

    if (type == "shield") {
        if (TO->validate_combat_stance("weapon and shield")) {
            TO->set_combat_stance("one hander");
        }else {
            TO->set_combat_stance("unarmed");
        }
    }
    check_armor_active_feats(TO, type, (string)limb[0], "remove");

    ac += (int)arm->query_ac();
    if (ac > 10) {
        ac = 10;
    }
    if (TO->is_player()) {
        ApplyObjectBonuses(arm, TO, "remove", "wear");
    }
    return 1;
}

void check_armor_active_feats(object wornBy, string type, string limb, string action) {
    int bonus_value;
    object deactivate_feat, * active_feats;
    int i;
    if (type == "shield") {
        if (action == "remove") {
            //shieldwall
            bonus_value = (int)wornBy->query_property("shieldwall");
            if (bonus_value) {
                message("my_action", "You can't benefit from shieldwall without a shield.", wornBy);
                wornBy->set_property("shieldwall", -bonus_value);
                wornBy->set_property("damage resistance", -bonus_value);
                wornBy->set_property("shieldwall_bonus", -bonus_value);
                wornBy->set_property("empowered", bonus_value);
            }

            if ((int)wornBy->query_property("enruned shield")) {
                active_feats = wornBy->query_property("active_feats");
                for (i = 0;sizeof(active_feats), i < sizeof(active_feats);i++) {
                    if (!objectp(active_feats[i])) { continue; }
                    if (active_feats[i]->query_feat_name() != "enruned shield") { continue; }
                    deactivate_feat = active_feats[i];
                    break;
                }
                deactivate_feat->dest_effect();
            }
        }else {
            //positioning
            bonus_value = (int)wornBy->query_property("tactical_positioning");
            if (bonus_value) {
                message("my_action", "You can't benefit from positioning with a shield.", wornBy);
                wornBy->set_property("tactical_positioning", -bonus_value);
                wornBy->add_ac_bonus(-bonus_value);
                wornBy->add_attack_bonus(bonus_value);
            }
            //spell combat
            if ((int)wornBy->query_property("magus cast")) {
                active_feats = wornBy->query_property("active_feats");
                for (i = 0;sizeof(active_feats), i < sizeof(active_feats);i++) {
                    if (!objectp(active_feats[i])) { continue; }
                    if (active_feats[i]->query_feat_name() != "spell combat") { continue; }
                    deactivate_feat = active_feats[i];
                    break;
                }
                deactivate_feat->dest_effect();
                message("my_action", "You can't benefit from spell combat with a shield.", wornBy);
            }
        }
    }

    if (action == "remove" &&
        (int)wornBy->query_property("armor enhancement timer") &&
        (type == "armour" || type == "chain" || type == "leather") &&
        limb == "torso") {
        "/cmds/mortal/_enhance.c"->off_enhances(wornBy, "armor");
    }
}

/*
   int get_ac_armour(string limb) {
   int i, j;
   int num, holdac, hold;
   object *tmp;

   num = 0;
   holdac = -10;
   hold = -1;
   tmp = query_armour(limb);
   for(j=0;j<sizeof(tmp);j++) {
      if(member_array((string)tmp[j]->query_type(),MULTIPLE_WEAR) == -1) continue;
      if((int)tmp[j]->query_ac() > holdac) {
         holdac = (int)tmp[j]->query_ac();
         hold = j;
      }
   }
   if (hold != -1) {
      num = holdac;
      ac_armour += ({tmp[hold]});
   }
   return num;
   }
 */

object* all_armour()
{
    object* str;
    object* tmp;
    int x, i;

    str = ({});
    for (x = 0; x < sizeof(limbs); x++) {
        tmp = query_armour(limbs[x]);
        for (i = 0; i < sizeof(tmp); i++) {
            if (!objectp(tmp[i])) {
                continue;
            }
            str += tmp;
        }
    }
    return str;
}

object* all_armours_of_type(string type)
{
    int i;
    object* ret;
    object* armors = all_armour();
    ret = ({});
    for (i = 0; i < sizeof(armors); i++) {
        if (!objectp(armors[i])) {
            continue;
        }
        if ((string)armors[i]->query_type() == type) {
            ret += ({ armors[i] });
        }
    }
    return ret;
}

int is_wearing_type(string type)
{
    return sizeof(all_armours_of_type(type)) != 0;
}

mixed is_wielding(string type)
{
    object* weapons;
    int i;

    weapons = TO->query_wielded();
    if (type == "unarmed" && !sizeof(weapons)) {
        return 1;
    }
    if (!sizeof(weapons)) {
        return 0;
    }

    switch (type) {
    case "dual wielding":
        if (sizeof(weapons) < 2) {
            return 0;
        }
        if (weapons[0] == weapons[1] || !weapons[0]->is_weapon() || !weapons[1]->is_weapon()) {
            return 0;
        }
        return 1;

    case "weapon":
        for (i = 0; i < sizeof(weapons); i++) {
            if (weapons[i]->is_weapon()) {
                return 1;
            }
        }
        return 0;

    case "lrweapon":
        for (i = 0; i < sizeof(weapons); i++) {
            if (weapons[i]->is_lrweapon()) {
                return 1;
            }
        }
        return 0;

    case "one handed":
        if (sizeof(weapons == 1) && (weapons[0]->query_size() <= TO->query_size())) {
            return 1;
        }
        return 0;

    case "size":
        return weapons->query_size();

    case "small":
        for (i = 0; i < sizeof(weapons); i++) {
            if (weapons[i]->query_size() > 1) {
                return 0;
            }
        }
        return 1;

    case "medium":
        for (i = 0; i < sizeof(weapons); i++) {
            if (weapons[i]->query_size() != 2) {
                return 0;
            }
        }
        return 1;

    case "large":
        for (i = 0; i < sizeof(weapons); i++) {
            if (weapons[i]->query_size() < 3) {
                return 0;
            }
        }
        return 1;

    case "giant":
        for (i = 0; i < sizeof(weapons); i++) {
            if (weapons[i]->query_size() < 4) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

object* query_ac_armour()
{
    if (ac_armour) {
        return ac_armour;
    }else {
        return 0;
    }
}

object* query_armour(string limb)
{
    if (body[limb]) {
        return body[limb]["armour_ob"];
    }else {
        return 0;
    }
}

void set_fingers(int x)
{
    all_my_fingers = x;
}

int query_fingers()
{
    return all_my_fingers;
}

int query_size()
{
    int val;
    string race;

    if (!size) {
        val = 2;
        race = this_object()->query_race();
        val = RACE_D->query_size(race);
        return val + size_bonus;
    } else {
        return size + size_bonus;
    }
}

void set_size(int x)
{
    size = x;
}

int query_size_bonus()
{
    return size_bonus;
}

void set_size_bonus(int x)
{
    size_bonus = x;
}

void add_size_bonus(int x)
{
    size_bonus += x;
}

void set_wielding_limbs(string* str)
{
    int i;

    for (i = 0; i < sizeof(str); i++) {
        if (member_array(str[i], limbs) == -1) {
            continue;
        }
        body[str[i]]["wieldable"] = 1;
    }
}

void add_wielding_limb(string str)
{
    if (member_array(str, limbs) == -1) {
        return;
    }
    body[str]["wieldable"] = 1;
}

string* query_wielding_limbs()
{
    string* tmp;
    int i;
    tmp = ({});

    if (TO->query_property("shapeshifted")) {
        return ({});
    }

    for (i = 0; i < sizeof(limbs); i++) {
        if (body[limbs[i]]["wieldable"]) {
            tmp += ({ limbs[i] });
        }
    }
    return tmp;
}

void fix_limbs()
{
    int i;

    for (i = 0; i < sizeof(limbs); i++) {
        body[limbs[i]]["armour"] = ({});
        body[limbs[i]]["armour_ob"] = ({});
        body[limbs[i]]["weapon"] = 0;
    }
    wielded_objects = ([]);
}

string* query_severed_limbs()
{
    if (!severed) {
        return ({});
    }else {
        return keys(severed);
    }
}

object* query_wielded()
{
    return (wielded_objects ? values(wielded_objects) : ({}));
}

object query_weapon(string limb)
{
    if (!wielded_objects) {
        return 0;
    }
    if (!wielded_objects[limb]) {
        return 0;
    }
    return wielded_objects[limb];
}

//  initialize the variables

void init_complex_body()
{
    target_limb = "";
    if (!heal_rate) {
        heal_rate = 2;
    }
}

void heal(int x)
{
    int i;

    //if(player_data["general"]["hp"] < 1) return;
    TO->do_damage("torso", -1 * x);
    for (i = 0; i < sizeof(limbs); i++) {
        body[limbs[i]]["damage"] -= x;
        if (body[limbs[i]]["damage"] < 0) {
            body[limbs[i]]["damage"] = 0;
        }
    }
}

void heal_limb(string str, int x)
{
    if (member_array(str, limbs) == -1) {
        return;
    }
    if (!body[str]) {
        return;
    }
    body[str]["damage"] -= x;
    if (body[str]["damage"] < 0) {
        body[str]["damage"] = 0;
    }
}

int set_heal_rate(int x)
{
    heal_rate = x;
    return x;
}

int query_heal_rate()
{
    return heal_rate;
}

int severed_limb(string limb)
{
    int temp;
    string childlimb;

    if (!body[limb]) {
        return 0;
    }
    childlimb = body[limb]["limb_ref"];
    if (childlimb == "FATAL") {
        player_data["general"]["hp"] = -1;
        return 2;
    }
    if (childlimb == "") {
        remove_limb(limb);
        return 1;
    }
    if (!body[childlimb]) {
        remove_limb(limb);
        return 1;
    }
    temp = body[childlimb]["damage"];
    if (temp < body[childlimb]["max_dam"]) {
        do_damage(childlimb, body[childlimb]["max_dam"] + 25);
        check_on_limb(childlimb);
    }
    remove_limb(limb);
    return 1;
}

int check_on_limb(string limb)
{
    object weap;
    object* arm;
    string* locations;
    int i;

    object old_limb;

    if (!body[limb]) {
        return 0;
    }
    if (body[limb]["damage"] > body[limb]["max_dam"]) {
        if (wizardp(this_object())) {
            message("my_combat", sprintf("If you were not immortal, you would lose your %s right now!", limb), this_object());
            body[limb]["damage"] = body[limb]["max_dam"] - 1;
            return 1;
        }
        if (limb == "torso") {
            message("my_combat", "A mortal blow is dealt to your body!", this_object());
        }else {
            message("my_combat", sprintf("Your %s is severed!", limb), this_object());
        }
        if (limb == "torso") {
            tell_object(environment(this_object()), this_object()->QCN + " is dealt a mortal blow to the torso!", this_object());
        }else {
            tell_room(environment(this_object()), this_object()->QCN + " has " + this_object()->QP + " " + limb + " severed!", this_object());
        }
        weap = wielded_objects[limb];
        if (weap) {
            remove_weapon_from_limb(weap);
            weap->set_not_equipped();
        }
        arm = body[limb]["armour_ob"];
        if (arm) {
            for (i = 0; i < sizeof(arm); i++) {
                remove_armour_from_limb(arm[i], (string*)arm[i]->query_actual_limbs());
                arm[i]->set_not_equipped();
            }
        }
        old_limb = new(OB_BODY_PART);
        old_limb->set_limb(QCN, limb);
        old_limb->move(environment(this_object()));
        if (weap) {
            weap->move(old_limb);
        }
        if (arm) {
            for (i = 0; i < sizeof(arm); i++) {
                arm[i]->move(old_limb);
            }
        }
        player_data["general"]["hp"] -= 25;
        heal_rate = -3;
        return severed_limb(limb);
    }
    return 1;
}

void add_kill(string str)
{
    int x;

    if (!str) {
        return;
    }
    if (!player_data["kills"]) {
        player_data["kills"] = ({});
    }
    if (member_array((x = (int)PLAYER_D->add_kill(str)), player_data["kills"]) !=
        -1 || x == -1) {
        return;
    }
    player_data["kills"] += ({ x });
}

void remove_kill(string str)
{
    int x;

    if (!str) {
        return;
    }
    if (!player_data["kills"]) {
        player_data["kills"] = ({});
    }
    if (member_array((x = (int)PLAYER_D->add_kill(str)), player_data["kills"]) == -1 || x == -1) {
        return;
    }
    player_data["kills"] -= ({ x });
}

int* query_kills()
{
    return player_data["kills"];
}

void remove_deaths_by(string str)
{
    int i, j;
    mixed* tmp = ({});
    j = sizeof(deaths);
    for (i = 0; i < j; i++) {
        if (deaths[i][0] == str) {
            tmp += ({ deaths[i] });
        }
    }
    deaths -= tmp;
}

void add_death(string str)
{
    if (!str) {
        return;
    }

    if (!deaths) {
        deaths = ({ ({ str, time() }) });
    }else {
        deaths += ({ ({ str, time() }) });
    }

}

mixed* query_deaths()
{
    return deaths;
}

void clear_kills()
{
    player_data["kills"] = ({});
}

void set_target_limb(string str)
{
    if (!stringp(str)) {
        return;
    }
    if (member_array(str, limbs) == -1) {
        return;
    }
    target_limb = str;
}

int query_blind()
{
    return blindness;
}

void set_blind(int i)
{
    if (i) {
        blindness += i;
    }else {
        blindness = 0;
    }
    if (blindness < 0) {
        blindness = 0;
    }
}

int query_internal_encumbrance()
{
    int ic = ::query_internal_encumbrance();
//   if(TO->is_class("ranger") && sizeof(query_wielded()) > 1) {

//      if((int)query_wielded()[0]->query_size() == query_size() && (int)query_wielded()[1]->query_size() == query_size())
//         ic = ic + query_max_internal_encumbrance()/6;
//   }
    return ic;
}

int query_true_internal_encumbrance()
{
    return ::query_internal_encumbrance();
}

int is_on_limb(string theLimb, string type)
{
    object* armors;
    int i;

    if (!body[theLimb]) {
        return 0;
    }
    armors = query_armour(theLimb);
    for (i = 0; i < sizeof(armors); i++) {
        if ((string)armors[i]->query_type() == type) {
            return 1;
        }
    }
    return 0;
}

void add_exp(int x)
{
    int exp_diff, tot_exp;
    if (TO->query("new_class_type")) {
        if (!intp(player_data["general"]["new_experience"])) {
            player_data["general"]["new_experience"] = 0;
        }
        //should allow a player to get enough total experience to be 1 point away from 51 - a level above the current cap - Saide - May 2017
        tot_exp = player_data["general"]["new_experience"];
        if (tot_exp >= (total_exp_for_level((CHARACTER_LEVEL_CAP + 1)) - 1) && x > 0) {
            return;
        }
        exp_diff = (total_exp_for_level((CHARACTER_LEVEL_CAP + 1)) - 1) - tot_exp;
        if (x > exp_diff && x > 0) {
            x = exp_diff;
        }
        //if(x <= 0) x = 0;
        player_data["general"]["new_experience"] += x;
        return;
    }

    player_data["general"]["experience"] += x;
}

int query_exp()
{
    if (TO->query("new_class_type")) {
        if (!intp(player_data["general"]["new_experience"])) {
            player_data["general"]["new_experience"] = 0;
        }
        return player_data["general"]["new_experience"];
    }

    return player_data["general"]["experience"];
}

void set_exp(int x)
{
    if (TO->query("new_class_type")) {
        if (!intp(player_data["general"]["new_experience"])) {
            player_data["general"]["new_experience"] = 0;
        }
        player_data["general"]["new_experience"] = x;
        return;
    }

    if (!mapp(player_data)) {
        init_limb_data();
    }
    if (!sizeof(keys(player_data))) {
        init_limb_data();
    }

    player_data["general"]["experience"] = x;
}

void set_general_exp(string type, int x)
{
    if (TO->query("new_class_type")) {
        if (!intp(player_data["general"]["new_experience"])) {
            player_data["general"]["new_experience"] = 0;
        }
        player_data["general"]["new_experience"] = x;
        return;
    }

    if (intp(player_data["general"]["experience"]) && player_data["general"]["experience"] > 0) {
        error("Tried to reset the experience of " + query_name() + " without clearing the existing exp");
    }
    if (!mapp(player_data["general"]["experience"])) {
        player_data["general"]["experience"] = ([]);
    }
    player_data["general"]["experience"][type] = x;
}

void add_general_exp(string type, int x)
{
    if (TO->query("new_class_type")) {
        if (!intp(player_data["general"]["new_experience"])) {
            player_data["general"]["new_experience"] = 0;
        }
        player_data["general"]["new_experience"] += x;
        return;
    }

    if (intp(player_data["general"]["experience"]) && player_data["general"]["experience"] > 0) {
        error("Tried to reset the experience of " + query_name() + " without clearing the existing exp");
    }
    if (!mapp(player_data["general"]["experience"])) {
        player_data["general"]["experience"] = ([]);
    }
    player_data["general"]["experience"][type] += x;
}

int get_general_exp(string type)
{
    if (TO->query("new_class_type")) {
        if (!intp(player_data["general"]["new_experience"])) {
            player_data["general"]["new_experience"] = 0;
        }
        return player_data["general"]["new_experience"];
    }

    if (intp(player_data["general"]["experience"]) && player_data["general"]["experience"] > 0) {
        error("Tried to reset the experience of " + query_name() + " without clearing the existing exp");
    }
    if (!mapp(player_data["general"]["experience"])) {
        player_data["general"]["experience"] = ([]);
    }
    return player_data["general"]["experience"][type];
}

mapping query_player_data()
{
    return player_data;
}
