// File:      /std/Object.c
// Purpose:   Define functions and varibles to be used by all objects
// Mudlib:    Nightmare
// Credits:
// 92-10-**   Descartes of Borg created this, based on TMI's Object.c
// 93-06-16   Pallando reordered and commented it.
// 93-06-16   Pallando added create(), reset(), prop() and set_material()
// 93-06-21   Pallando added init()
// 93-06-23   Pallando added seteuid(getuid()) to create()
// traps will be based from here although room.c and bag_logic.c will cantain code that references these
// in an attempt to make traps as all encompassing and legitimate as possible
// two minor changes (noted) 8/29/2003 by *Styx*
// study stuff added by Circe 1/18/05
// added query_trap_func_map() by *Styx* 5/8/06, last chg. 1/17/05
// added check for "str" variable in the __Use() function to prevent bugs. Nienne 6/07.
// added player enchanted validation to set_wield() - Yves 12/18

// std contains the def of MOVE
#include <std.h>
#include <daemons.h>
#include <security.h>
#include <valid_bonuses.h>
// daemons contains the #define of ALCHEMIST_D
#include <daemons.h>
#include <move.h>
#include <magic.h>

// move contains the functions "move", "remove", "clean_up", "set_no_clean"
//   "set_last_location", "query_last_location", "set_weight", "query_weight"
inherit "/std/trap_data.c";
inherit MOVE;
inherit DECAY;
//    Global variables defined in this file
//   =======================================
mapping props;
// Object data that does get saved.
private string serial_number;
private mapping ob_data;   // Object data that does not get saved.
private string cap_name;   // kept in seperate variable for security
private string true_name;         // kept in seperate variable for security
private string creator;           // File name of the ob that created an object

string cursed;
private string* identified;
private string* studied;
private mapping studied_failed;
string material;                  // Substance object is made from.
string* magic_properties;  //  Allows all objects to have magic properties
//Added by Saide for use with the soulbound/item ownership functions
//3/19/2007
string* item_owners = ({});

//going to manipulate this string with
//the set_bit() and test_bit() efuns
//this string will determine if an item can have more than
//one owner, if the item owners will clear
//on death, if it will clear on
//fencing - the bits are,
//from left to right -
//clear on sale,
//clear on fence,
//clear single owner on death,
//clear all owners on death,
//multiple owners
string item_owner_props = "01100";

//hiding things..
nosave private int hidden, magic_hidden;
nosave private object* hidden_seen;

// To allow this item to use the unique item system
// Thorn@ShadowGate - 27 June 2000
int unique_item;
int unique_lease = 0;

//weilding
string wieldf, limbString, unwieldf, hit, lrhit;
object wielded;

//new var for property-set bonuses. N, 7/12.
mapping item_bonuses;

//for wielding
void set_hit(mixed val);
void set_lrhit(mixed val);
void set_wield(mixed val);
void set_unwield(mixed val);

int query_wc();
int query_property(string str);
int query_large_wc();
mixed query_hit();
mixed query_lrhit();
mixed query_wield();
mixed query_unwield();
int remove_property(string prop);

void unequip();
void __ActuallyUnwield();
void set_not_inhand();
int wieldable();
string* query_identified();
void add_identified(string str);
void set_identified(string* myidentified);
int is_identified(string name);
void add_studied(string str);
int is_studied(string name);
void add_studied_failed(string name, int level);
int is_studied_failed(string name, int level);
void remove_studied_failed(string name);
void set_read(string str);
void set_language(string str);
//void do_remove_stat(object myplayer, string mystat);
void run_item_bonuses(string mystatus, object myplayer, mapping itembonuses);

//Below added by Circe for faction-specific items.  11/24/07
void set_factionitem(string str);
string query_factionitem();
string factionitem;

//new functions for property-set bonuses. N, 7/12.
void set_item_bonus(string bonustype, int thebonus);
int query_item_bonus(string bonustype);
mapping query_item_bonuses();

//    Functions defined in this file
//   ================================
//
// a) Object property functions.
//   init_ob               - initalises the "ob_data" mapping
//   set                   - stores data in the "ob_data" mapping
//   add                   - alters data in the "ob_data" mapping
//   query                 - returns data from the "ob_data" mapping
//   set_property          - alters data in the "props" mapping
//   query_property        - returns data from the "props" mapping
//   remove_all_properties - initalises the "props" mapping
//   remove_property       - removes data from the "props" mapping
//   remove_property_value - alters data in the "props" mapping
//   regexp_query_property - returns data from the "props" mapping
///           New Functions as of 06/07/2008 - garrett
///   has_property            - tells if an object has this property/ies set.  If they _key_ is valid.
// b) One line set and query functions.
//   set_id,set_short,set_long,set_value,query_id,query_name,query_true_name
//   query_long,query_value,query_destroy,query_creator
// c) More complicated set and query functions.
//   id                    - queries if a str is an id
//   set_name              - also sets cap_name
//   query_short           - also inits ob
//   query_cap_name        - deals with invisibility and ghosts
//   query_light           - also checks if props exists
//   set_destroy           - also resets ob_data
//   set_material          - calls domain master object
// d) Main functions.
//   create                - initialises object
//   reset                 - handles temperature
//   init                  - future expansion - currently a dummy function
//   move                  - makes sure armor is unequipped
//   get                   - handles "keep" property

// To allow this item to use the unique item system
// Thorn@ShadowGate - 27 June 2000
varargs void set_unique(int x);
void set_lease(int x);
int query_unique();
string query_unique_id();
void reset_hidden_seen();
void set_hidden(int xxx);

int save_me(string fname)
{
    int x;
    if (query_property("temporary_item")) {
        return 1;
    }
    seteuid(UID_RESTORE);
    x = catch(save_object(fname, 1));
    return x;
}

varargs int query_id_no(string id_name)
{
    int i, limit;
    if (!objectp(ETO)) {
        return 0;
    }
    if (!stringp(id_name)) {
        id_name = "object";
    }
    limit = sizeof(all_inventory(ETO));
    for (i = 1; i < limit; i++) {
        if (present(id_name + " " + i) == TO) {
            return i;
        }
    }
    return 0;
}

int restore_me(string fname)
{
    int x;
    seteuid(UID_ROOT);
    x = catch(restore_object(fname, 1));
    return x;
}

// *** Object property functions ***
// I] That use the "ob_data" mapping

void init_ob()
{
    ob_data = ([ "id" : ({}) ]);
}

void set(string what, mixed arg)
{
    if (!stringp(what)) {
        return;
    }
    if (functionp(arg) && geteuid(this_object()) != geteuid(arg)) {
        return;
    }
    if (!ob_data) {
        init_ob();
    }
    if (what == "read" && !functionp(arg)) {
        set_read(arg);
        return;
    }
    if (what == "language") {
        set_language(arg);
        return;
    }
// changing so an aggessive of 0 doesn't automatically swarm  *Styx* 8/29/03
//    if(what == "aggressive") TO->set_property("swarm",1);
    if (what == "aggressive" && arg != 0) {
        TO->set_property("swarm", 1);
    }
    if (functionp(arg)) {
        if (TO->query_property("function_" + what)) {
            TO->remove_property("function_" + what);
        }
        TO->set_property("function_" + what, (*arg)(1));
    }
    if (ob_data[what]) {
        ob_data[what] = arg;
    }else {
        ob_data += ([ what:arg ]);
    }
    if (what == "value") {
        what = "cointype";
        if (ob_data[what]) {
            ob_data[what] = "gold";
        }else {
            ob_data += ([ what:"gold" ]);
        }
    }
}

protected void add(string what, mixed arg)
{
    if (!ob_data) {
        ob_data = ([]);
    }
    if (functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) {
        return;
    }
    if (stringp(arg) || intp(arg)) {
        arg = ({ arg });
    }
    if (!ob_data[what]) {
        ob_data += ([what:arg]);
        return;
    }

    if (!pointerp(ob_data[what]) && !mapp(ob_data[what])) {
        return;
    }
    ob_data[what] += arg;
}

void delete(string what)
{
    if (!stringp(what)) {
        return;
    }
    if (!ob_data) {
        init_ob();
    }
    if (what == "aggressive") {
        TO->remove_property("swarm");
    }
    if (ob_data[what]) {
        map_delete(ob_data, what);
    }
}

varargs mixed query(string what, mixed element)
{
    mixed res, tmp;
    int i, query_flag = 0;

    res = 0;
    if (!ob_data) {
        init_ob();
    }
    if (!stringp(what)) {
        return 0;
    }
    if (!ob_data[what]) {
        return 0;
    }
    if (!element) {
        res = ob_data[what];
    }else if (stringp(element)) {
        res = ob_data[what][element];
    }else if ((intp(element)) && pointerp(ob_data[what]) &&
              (element < sizeof(ob_data[what]))) {
        res = ob_data[what][element];
    }
    if (pointerp(res) && previous_object() != this_object()) {
        res += ({});
    }
    return res;
}

// II] That use the "props" mapping

void set_properties(mapping borg)
{
    props += borg;
}

mapping query_props()
{
    return props;
}

void UpdateBonuses(object possessor, string which)
{
    if (!stringp(which)) {
        return;
    }
    if (!objectp(possessor)) {
        return;
    }
    if (!living(possessor)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!living(TO)) {
        if (TO->is_armour()) {
            possessor->ApplyObjectBonuses(TO, possessor, which, "wear");
        }
        if (TO->is_weapon()) {
            possessor->ApplyObjectBonuses(TO, possessor, which, "wield");
        }else {
            if (TO->query_property("inanimate_bonus")) {
                possessor->ApplyObjectBonuses(TO, possessor, which, "move");
            }
        }
    }
}

void set_property(string prop, mixed value)
{
    object possessor;
    //Added to support the ability for an item that's worn/wielded/held
    //and adds a bonus to be updated by this - without having to
    //remove/wear/unwield/wield the object to take affect - Saide
    if (!TO->is_room()) {
        possessor = ETO;
    }
    if (member_array(prop, VALID_BONUSES) != -1) {
        if (!living(TO)) {
            UpdateBonuses(possessor, "remove");
        }
    }
    if (prop == "enchantment" && !random(20) && !query("no curse") && !query_property("no curse")) {
        value = -1 * value;
    }
    if (pointerp(value)) {
        if (!props) {
            props = ([]);
        }
        if (!props[prop] || !pointerp(props[prop])) {
            props[prop] = ({});
        }
        props[prop] += value;
        if (member_array(prop, VALID_BONUSES) != -1) {
            if (!living(TO)) {
                UpdateBonuses(possessor, "add");
            }
        }
        return;
    }else {
        if (!props || !mapp(props)) {
            props = ([]);
        }
        if (!props[prop]) {
            props[prop] = value;
        }
        //random treasure on that will appear on monsters - Saide
        else if (props[prop]) {
            //in the event of a property being something like an object
            //or maybe even a function then doing += will fail
            //hopefully this bit of code fixes that and pretty much retains
            //all properties except for the ones that might error - Saide June 2016
            if (intp(value) && intp(props[prop])) {
                props[prop] += value;
            }else if (stringp(value) && stringp(props[prop])) {
                props[prop] += value;
            }else if (floatp(value) && floatp(props[prop])) {
                props[prop] += value;
            }else {
                props[prop] = value;
            }
            if (member_array(prop, VALID_BONUSES) != -1) {
                if (!living(TO)) {
                    UpdateBonuses(possessor, "add");
                }
            }
            return;
        }
        props += ([ prop:value]);

        if (prop == "treasure_type" && !living(TO)) {
            "/daemon/random_monster_treasure_d.c"->add_treasure(TO);
        }
    }

    if (member_array(prop, VALID_BONUSES) != -1) {
        if (!living(TO)) {
            UpdateBonuses(possessor, "add");
        }
    }
}

int armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((string)ob->query_armor_prof() == "light") {
        return 1;
    }
    if ((string)ob->query_armor_prof() == "medium") {
        return 1;
    }
    if ((string)ob->query_armor_prof() == "heavy") {
        return 1;
    }
    return 0;
}

int light_armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((string)ob->query_armor_prof() == "heavy") {
        return 1;
    }
    if ((string)ob->query_armor_prof() == "medium") {
        return 1;
    }
    return 0;
}

mixed query_property(string prop)
{
// racial bonuses errored when querying from /std/races; had to apply manually
    object* worn;
    int num, mylevel, scaled, tmpval;
    string subrace, binding;

    if (!props) {
        props = ([]);
        return 0;
    }

    if (prop == "untrippable") {
        if (FEATS_D->usable_feat(TO, "shield master")) {
            num += TO->query_base_character_level();
            num += 25;
        }
    }

    if (prop == "empowered") {
        if (FEATS_D->usable_feat(TO, "greater spell power")) {
            num += 3;
        } else {
            if (FEATS_D->usable_feat(TO, "improved spell power")) {
                num += 2;
            } else {
                if (FEATS_D->usable_feat(TO, "spell power")) {
                    num += 1;
                }
            }
        }
        if(this_object()->is_class("psion") && this_object()->query("available focus"))
            num += 1;
    
        if ((string)TO->query_race() == "human") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (strsrch(subrace, "genasi") != -1) {
                    num += 0;
                }
            }
        }
        if ((string)TO->query_race() == "elf") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (subrace == "aquatic elf") {
                    num += 0;
                }
            }
        }
        num += props[prop];
        return (num + EQ_D->gear_bonus(TO, "caster level"));
    }
// tweaking a few bonuses here with feats overhaul. Nienne, 03/10
// basic DR from 3 to 2; spell pen changed from 10/20 to 15/15 to match MR

    if (prop == "spell penetration") {
        if (FEATS_D->usable_feat(TO, "spell penetration")) {
            num += 1;
        }
        if (FEATS_D->usable_feat(TO, "greater spell penetration")) {
            num += 2;
        }
        num += props[prop];
        return (num + EQ_D->gear_bonus(TO, "spell penetration"));
    }

    if (prop == "damage penetration") {
        if (FEATS_D->usable_feat(TO, "penetrating strike")) {
            num += 5;
        }
        if (FEATS_D->usable_feat(TO, "greater penetrating strike")) {
            num += 5;
        }
        num += props[prop];
        return num;
    }

    if (prop == "fast healing") {
        if (TO->is_vampire()) {
            if (!TO->is_in_sunlight()) {
                int blst = (20000 - (int)TO->query_bloodlust()) / 2000 - 1;
                num = props[prop] + 5;
                num -= blst < 0 ? 0 : blst;
                return num < 0 ? 0 : num;
            }
        }
        if (TO->query_race() == "shade" || this_object()->is_shade()) {
            num -= min( ({ 0, (total_light(environment(this_object())) - 1) / 2 }) );
        } else if (TO->query_race() == "troll") {
            num += 2;
        }
        
        if(FEATS_D->usable_feat(this_object(), "metabolic healing") && this_object()->query("available focus"))
            num += 1;
        
        num += props[prop];
        return (num + EQ_D->gear_bonus(TO, "fast healing"));
    }

// we want this to pick up item "empowered" bonuses only, without spell power feats. Manually applied.
    if (prop == "spell dcs") {
        if (FEATS_D->usable_feat(TO, "spell focus"))
            num += 1;
        
        if(FEATS_D->usable_feat(TO, "spell penetration"))
            num += 1;
        
        if(FEATS_D->usable_feat(TO, "greater spell penetration"))
            num += 1;
        
        //num += props["empowered"]; //doesn't seem to do anything
        return (num + TO->query_property("empowered"));
    }

    if (prop == "damage resistance") {
        if (FEATS_D->usable_feat(TO, "undead graft")) {
            num += 6;
        }
        if (FEATS_D->usable_feat(TO, "shadow master")) {
            if (ETO->query_light() < 1) {
                num += 8;
            }
        }
        if(this_object()->is_shade())
        {
            num -= (total_light(environment(this_object())) - 1);
        }
        if (FEATS_D->usable_feat(TO, "damage resistance")) {
            num += 2;
        }
        if (FEATS_D->usable_feat(TO, "damage reduction")) {
            worn = filter_array(distinct_array(TO->all_armour()), "light_armor_filter", TO);
            if (!sizeof(worn)) {
                num += (query_guild_level("barbarian") - 10) / 6 + 1;

                if(FEATS_D->usable_feat(this_object(), "unstoppable"))
                    num += 3;
            }
        }
        if (FEATS_D->usable_feat(TO, "shadow master") && objectp(ETO) && ETO->query_light() < 2) {
            num += 10;
        }
        if (FEATS_D->usable_feat(TO, "armor mastery")) {
            worn = filter_array(distinct_array(TO->all_armour()), "armor_filter", TO);
            if (sizeof(worn)) {
                num += query_guild_level("fighter") / 6 + 1;
            }
        }
        if (FEATS_D->usable_feat(TO, "improved damage resistance")) {
            num += 2;
        }
        if(FEATS_D->usable_feat(this_object(), "infused form"))
            num += 5;
        
        num += props[prop];
        return (num + EQ_D->gear_bonus(TO, "damage resistance"));
    }

    if (prop == "magic resistance") {
        if (FEATS_D->usable_feat(TO, "improved resistance")) {
            num += 1;
        }
        if (FEATS_D->usable_feat(TO, "increased resistance")) {
            num += 2;
        }
        if ((string)TO->query_race() == "human") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (strsrch(subrace, "genasi") != -1) {
                    num += 1;                                 // +10 MR all genasi
                }
            }
        }
        if ((string)TO->query_race() == "gnome") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (subrace == "deep gnome" || subrace == "svirfneblin") {
                    num += 1;
                }
            }
        }
        if ((string)TO->query_race() == "orc") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (subrace == "orog" || subrace == "tanarukk") {
                    num += 1;
                }
            }
        }
        if ((string)TO->query_race() == "elf") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (subrace == "fey'ri") {
                    num += 1;
                }
            }
        }
        if ((string)TO->query_race() == "deva") {
            num += 1;
        }
        if ((string)TO->query_race() == "yuan-ti") {
            num += 1;
        }
        if ((string)TO->query_race() == "drow" ||
            (string)TO->query("subrace") == "szarkai") {
            num += 1;
        }
        num += props[prop];
        return (num + EQ_D->gear_bonus(TO, "magic resistance"));
    }

    if (prop == "no death") {
        if (TO->is_undead()) {
            return 1;
        }
        if (FEATS_D->usable_feat(TO, "death ward")) {
            return 1;
        }
        if (FEATS_D->usable_feat(TO, "fated")) {
            return 1;
        }
        if (FEATS_D->usable_feat(TO, "earthen blood")) {
            return 1;
        }
    }

    if (prop == "no disarm") {
        if (FEATS_D->usable_feat(TO, "weapon mastery")) {
            return 1;
        }
    }

    if (prop == "sunlight_umbrella") {
        if (FEATS_D->usable_feat(TO, "mask of mortality")) {
            return 1;
        }
        num += props[prop];
        return num;
    }

    if (prop == "negative energy affinity") {
        if (TO->is_undead() || this_object()->is_shade()) {
            return 1;
        }
        //Unlike other racial bonuses this one must be valid for all
        //half-races as well.
        if (TO->query("subrace") == "dhampir") {
            return 1;
        }
        num += props[prop];
        return num;
    }

    if (prop == "verstandnis") {
        if (FEATS_D->usable_feat(TO, "tongue of the sun and moon")) {
            return 1;
        }
    }

    if (prop == "mind_immunity") {
        if (FEATS_D->usable_feat(TO, "unyielding soul")) {
            num += 6;
        }
        /*
        if (FEATS_D->usable_feat(TO, "mind partition")) {
            num += 14;
        }
        */
        if (TO->is_undead()) {
            return 20;
        }
        num += props[prop];
        if (num > 20) {
            return 20;
        }
        return num;
    }
    
    if(prop == "spectral hand")
    {
        if(PLAYER_D->check_familiar(this_object()))
            return 1;
        
        return 0;
    }


    if (prop == "spell damage resistance") {
        if (TO->is_vampire()) {
            if (!TO->is_in_sunlight()) {
                num += 10;
            }
        }
        if(this_object()->is_deva())
        {
            num += 30;
        }
        if(this_object()->is_shade())
        {
            num -= (2 * (total_light(environment(this_object())) - 1));
        }
            
        if ((string)TO->query_race() == "human") {
            subrace = (string)TO->query("subrace");
            if (subrace) {
                if (subrace == "maalish") {
                    num += 5;                          // +5 SR for human Maalish ethnicity
                }
            }
        }
        if (FEATS_D->usable_feat(TO, "resistance")) {
            num += 5;
        }
        if (FEATS_D->usable_feat(TO, "increased resistance")) {
            num += 7;
        }
        if (FEATS_D->usable_feat(TO, "improved resistance")) {
            num += 9;
        }
        num += props[prop];
        return (num + EQ_D->gear_bonus(TO, "spell damage resistance"));
    }

    //Added this to allow for a temporary enchantment property - Saide
    if (prop == "enchantment") {
        if (objectp(ETO) && props[prop] > 0) {
            if (intp(scaled = TO->query("scaledlevel")) && scaled > 0 && living(ETO)) {
                tmpval = props[prop];
                tmpval = to_int(to_float(scaled) / to_float(ETO->query_base_character_level()) * tmpval);
                if (tmpval < 1) {
                    tmpval = 0;
                }
                if (props["temporary enchantment"]) {
                    return tmpval + props["temporary enchantment"];
                }
                return tmpval;
            }
        }
        if (props["temporary enchantment"]) {
            return props[prop] + props["temporary enchantment"];
        }
    }
    if (stringp(prop) && strsrch(prop, "bonus_spell_slots") != -1) {
        num = props[prop];
        return (num + EQ_D->gear_bonus(TO, prop));
    }
    return props[prop];
}

//added query_property("curseditem") on advice from Garrett
//in setting up curses on items that don't get enchantments
//until they are wielded
//Circe 9/26/04
int is_cursed()
{
    if (TO->query_property("curseditem")) {
        return 1;
    }
    return query_property("enchantment") && query_property("enchantment") < 0;
}

void remove_all_properties()
{
    if (!living(TO)) {
        if (objectp(ETO)) {
            if (sizeof(keys(props)) != sizeof(keys(props) - VALID_BONUSES)) {
                UpdateBonuses(ETO, "remove");
            }
        }
    }

    remove_property("shapeshifted");
    props = ([]);
}

int remove_property(string prop)
{
    //added this as a fix for bonuses not
    //being removed on removing armor
    //problem was the remove_property("wear_order")
    //in /cmds/mortal/_remove.c - which was throwing
    //off the sizeof() comparison -
    //this way if the bonuses aren't removed, no matter
    //the result of that comparison, then they wont be
    //re-added - Saide
    object shape;
    int tmp_flag = 0;

    if (prop == "shapeshifted") {
        if (objectp(shape = TO->query_property("shapeshifted"))) {
            shape->remove(); // hopefully to reverse shapeshifting effects if it disappears for whatever reason -Ares
        }
    }

    if (props && props[prop]) {
//              props[prop] = 0;
        if (member_array(prop, VALID_BONUSES) != -1) {
            if (!living(TO)) {
                tmp_flag = 1;
                if (objectp(ETO)) {
                    UpdateBonuses(ETO, "remove");
                }
            }
        }
        map_delete(props, prop);
        if (!living(TO)) {
            if (sizeof(keys(props)) != sizeof(keys(props) - VALID_BONUSES) && tmp_flag == 1) {
                if (objectp(ETO)) {
                    UpdateBonuses(ETO, "add");
                }
            }
        }
        return 1;
    }
    return 0;
}

int remove_property_value(string prop, mixed val)
{
    if (props && props[prop]) {
        props[prop] -= val;
        return 1;
    }
    return 0;
}

string* regexp_query_property(string pattern)
{
    string* vars, * prop;

    vars = keys(props);
    prop = regexp(vars, pattern);
    if (!prop) {
        prop = ({});
    }
    return prop;
}

int has_property(mixed val)
{
    if (mapp(val)) {
        return 0;
    }
    if (!pointerp(val)) {
        if (member_array(val, keys(props)) == -1) {
            return 0;
        }else {
            return 1;
        }
    } else {
        if (sizeof(keys(props)) == sizeof(keys(props) - (mixed*)val)) {
            return 0;
        }else {
            return 1;
        }
    }
}

// *** One line set and query functions ***
void   set_id(string str)
{
    set("id", str);
}

void   set_short(string str)
{
    set("short", str);
}

void   set_long(string str)
{
    set("long", str);
}

void   add_id(string str)
{
    add("id", str);
}

void remove_id(string str)
{
    string* tmp_ids;
    tmp_ids = (string*)TO->query_id();
    tmp_ids -= ({ str });
    TO->delete("id");
    TO->set("id", tmp_ids);
}

void   set_value(int x)
{
    set("value", x);
    if (!query("cointype")) {
        set("cointype", "gold");
    }
}

void   set_cointype(string str)
{
    set("cointype", str);
}

string* query_id()
{
    return query("id");
}

string query_name()
{
    /* adding a default in case one isn't set for bug prevention, found often with thrown objects *Styx*  12/24/03, last change 8/29/03  */
    if (!true_name) {
        return ("unnamed object");
    }
    return true_name;
}

string query_true_name()
{
    return true_name;
}

string query_long(string str)
{
    string tmd;
    function func;
    if (tmd = query_property("function_long")) {
        if (!tmd = call_other(TO, tmd)) {
            tmd = "A function messed up in query_long() in Object.c";
        }
    }else {
        tmd = ob_data["long"];
    }
    if (!TO->is_room() && !TO->is_armour() && !TO->is_weapon() && !living(TO)) {
        if (query_broken() != "") {
            tmd += " Condition appears to be" + query_broken() + "\n";
        }
        tmd += query_bonus_display();
    }
    return tmd;
}

int query_value()
{
    return (int)this_object()->query("value");
}

string query_cointype()
{
    string ret = (string)TO->query("cointype");
    if (stringp(ret)) {
        return ret;
    }else {
        return "gold";
    }
}

int query_destroy()
{
    return ob_data["destroy"];
}

string query_creator()
{
    return creator;
}

// *** More complicated set and query functions ***

int id(string str)
{
    int i, d, res;

    string* parts, what, where;

    if (!ob_data) {
        init_ob();
    }

    if (!stringp(str)) {
        return 0;
    }

    if (!objectp(TO)) {
        return 0;
    }

    if (sscanf(str, "my %s", what)) {
        if (ETO != TP) {
            return 0;
        }
        str = what;
    } else {
        res = sscanf(str, "%s on ground", what);
        if (res > 0) {
            if (ETO == TP) {
                return 0;
            }
            res = sscanf(what, "%s %d", what, d);
            str = what;
            if (res == 2) {
                str = str + " " + d;
            }
        }
    }

    if (lower_case(str) == true_name) {
        return 1;
    }

    if (!ob_data["id"]) {
        return 1;
    }

    if (member_array(str, ob_data["id"]) != -1) {
        return 1;
    }

    if (userp(TO) && objectp(TP)) {
        if (TP->knownAs(TO->query_true_name())) {
            if (lower_case(TP->knownAs(TO->query_true_name())) == lower_case(str)) {
                return 1;
            }
        }
    }
    if (str == "attacker" && objectp(TP) && !avatarp(TO) && (!TO->query_invis() ||
                                                             TP->detecting_invis())) {
        if (member_array(TO, TP->query_attackers()) != -1) {
            return 1;
        }
    }

    return 0;
}

void set_name(string str)
{
    if (!stringp(str)) {
        return;
    }
    cap_name = capitalize(str);
    true_name = str;
    if (creator) {
        return;
    }
    if (previous_object()) {
        creator = file_name(previous_object());
    }else {
        creator = "Unknown";
    }
}

int isMagic()
{
    int p = 0;
    if (query_property("enchantment") || query_property("magic") || query_property("spell") || query_property("spelled")) {
        p += query_property("enchantment");
        p += query_property("magic");
        if (intp(query_property("spell"))) {
            p += query_property("spell");
        }
    }
    p += query("uses");
    return p;
}

string addMagic(string theShort)
{
    int p;
    if (p = isMagic()) {
        switch (p) {
        case -1:
        case 1:
            theShort = theShort + " (surrounded by a faint blue glow)";
            break;

        case -2:
        case 2:
            theShort = theShort + " (surrounded by a blue glow)";
            break;

        case -3:
        case 3:
            theShort = theShort + " (surrounded by a bright blue glow)";
            break;

        case -4:
        case 4:
            theShort = theShort + " (surrounded by a very bright blue glow)";
            break;

        case -5:
        case 5:
            theShort = theShort + " (surrounded by an extremely bright blue glow)";
            break;

        default:
            theShort = theShort + " (surrounded by a nearly blinding blue glow)";
            break;
        }
    }
    return theShort;
}

string query_obvious_short()
{
    string tmd, theShort;
    if (tmd = query_property("function_general short")) {
        if (!theShort = call_other(TO, tmd)) {
            theShort = "A function messed up in query_short() in Object.c";
        }
    }else {
        theShort = query("general short");
    }
    return theShort;
}

string set_obvious_short(string str)
{
    set("general short", str);
}

string query_short()
{
    string theShort, * short_info, tmd;
    int i;
    function func;
    if (!ob_data) {
        init_ob();
    }
    if (!living(TO) && this_object()->query_invis()) {
        return 0;
    }
    theShort = query_obvious_short();
    if (!theShort || (objectp(TP) && is_identified((string)TPQN))) {
        if (tmd = query_property("function_short")) {
            if (!theShort = call_other(TO, tmd)) {
                theShort = "A function messed up in query_short() in Object.c";
            }
        }else {
            theShort = ob_data["short"];
        }
    }
    if (objectp(TP)) {
        if (TP->get_static("detecting magic")) {
            theShort = addMagic(theShort);
        }
    }

    if (query_property("added short")) {
        short_info = (string*)query_property("added short");
        if (pointerp(short_info) && sizeof(short_info)) {
            for (i = 0; i < sizeof(short_info); i++) {
                if (!stringp(short_info[i])) {
                    continue;
                }
                theShort += short_info[i];
            }
        }
    }

    if (objectp(TP) && !TO->is_room() && !living(TO)) {
        if (TP->query("is_auto_detecting_traps")) {
            if (sizeof(TO->query_trap_data())) {
                theShort = TO->get_trap_object_auto_detect(theShort, TP);
            }
        }
    }
    if (!TO->is_weapon() && objectp(wielded)) {
        theShort += limbString;
    }
    if (!TO->is_room() && !TO->is_weapon() && !TO->is_armour() && !living(TO)) {
        if (query_broken() != "" && stringp(theShort)) {
            theShort += query_broken();
        }
    }
    return theShort;
}

string query_eng_short()
{
    string str, s1, s2;
    if (!ob_data) {
        init_ob();
    }
    if (this_object()->query_invis()) {
        return 0;
    }

    str = query_obvious_short();
    if (!str || (objectp(TP) && is_identified((string)TPQN))) {
        if (functionp(ob_data["short"])) {
            str = (string)(*ob_data["short"])();
        } else {
            str = ob_data["short"];
        }
    }
    if (sscanf(str, "A %s", s1)) {
        return s1;
    }
    if (sscanf(str, "a %s", s1)) {
        return s1;
    }
    return str;
}

string query_cap_name()
{
    if (!true_name) {
        return 0;
    }
    if (!cap_name) {
        return 0;
    }
    if (this_object()->query_invis()) {
        return "Someone";
    }
    if (this_object()->query_ghost()) {
        return "A ghost";
    }
    return cap_name;
}

string query_vis_cap_name()
{
// This function is here to prevent objects that assume everything has a
// vis_cap_name set, has one, when users/monsters were the only previous ones.
    return query_cap_name();
// This should get properly overridden by the user.c object.
}

string query_vis_name()
{
    return query_name();
}

// Same logic as for query_vis_cap_name here. Bug Prevention.
int query_light()
{
    int light;
    if (!props) {
        return 0;
    }
    if (props["light"]) {
        light = props["light"];
    }

    if (light > 7) {
        light = 7;
    }
    if (light < -7) {
        light = -7;
    }

    return light;
}

void set_destroy()
{
    if (!ob_data) {
        ob_data = ([]);
    }
    ob_data["destroy"] = 1;
}

void add_hidden_seen(object obj)
{
    if (!pointerp(hidden_seen)) {
        hidden_seen = ({});
    }
    hidden_seen += ({ obj });
}

void add_all_to_hidden_seen(object* objs)
{
    if (!pointerp(hidden_seen)) {
        hidden_seen = ({});
    }
    hidden_seen += objs;
}

object* query_hidden_seen()
{
    return hidden_seen;
}

void reset_hidden_seen()
{
    if (hidden_seen) {
        hidden_seen = ({});
    }
}

void set_hidden(int xxx)
{
    if (xxx) {
        hidden_seen = ({});
    }
    hidden = xxx;
}

void set_magic_hidden(int xxx)
{
    magic_hidden = xxx;
}

int query_real_hidden()
{
    return hidden;
}

int query_hidden()
{
    return hidden && (objectp(TP) ? (member_array(TP, hidden_seen) == -1) : 1);
}

int query_magic_hidden()
{
    return magic_hidden;
}

int is_detectable()
{
    return 1;
}

void set_read(string str)
{
    string* read;
    read = ob_data["read"];
    if (!pointerp(read)) {
        read = ({});
    }
    read += ({ str });
    ob_data["read"] = read;
}

void set_language(string str)
{
    string* read;
    read = ob_data["language list"];
    if (!pointerp(read)) {
        read = ({});
    }
    read += ({ str });
    ob_data["language list"] = read;
}

void set_factionitem(string str)
{
    factionitem = str;
}

string query_factionitem()
{
    return factionitem;
}

void sign(object signer, string sign_as, int skill)
{
    if (!arrayp(ob_data["signature"])) {
        ob_data["signature"] = ({});
    }

    ob_data["signature"] += ({ ({ signer->query_name(), sign_as, skill }) });
}

int __Read(string str)
{
    int i;
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(TP)) {
        return 0;
    }
    if (!str) {
        return notify_fail("Read what?\n");
    }
    if (objectp(ETO)) {
        if (present(str, ETO) != TO) {
            return 0;                       //notify_fail("You do not notice that here.\n");
        }
    }
    if (query_hidden() || query_magic_hidden()) {
        return 0;                                           //return notify_fail("You do not notice that here.\n");
    }
    if (!ob_data || !ob_data["read"]) {
        return notify_fail(living(this_object()) ? "Read a living thing?\n" :
                           "There is nothing on it to read.\n");
    }
    if (functionp(ob_data["read"])) {
        if (query_property("sealed")) {
            tell_object(TP, "That seems to be sealed.  You will need " +
                        "to break the seal first.");
            return 1;
        }
        return call_other(TO, (*ob_data["read"])(0), (str));
    }else if (stringp(ob_data["read"]) || pointerp(ob_data["read"])) {
        if (query_property("sealed")) {
            tell_object(TP, "That seems to be sealed.  You will need " +
                        "to <seal break> first.");
            return 1;
        }
        if (stringp(ob_data["read"])) {
            message("reading", ob_data["read"], TP);
        } else if (pointerp(ob_data["read"])) {
            for (i = 0; i < sizeof(ob_data["read"]); i++) {
                if (pointerp(ob_data["language list"]) && sizeof(ob_data["language list"]) > i) {
                    ob_data["language"] = ob_data["language list"][i];
                }
                message("reading", ob_data["read"][i], TP);
            }
        }
        if (pointerp(ob_data["signature"])) {
            string signature;
            message("info", "Signatures: ", TP);

            for (i = 0; i < sizeof(ob_data["signature"]); i++) {
                if (stringp(ob_data["signature"][i])) {
                    signature = ob_data["signature"][i];
                } else if (arrayp(ob_data["signature"][i])) {
                    signature = ob_data["signature"][i][1];
                }

                if (!TP->knownAs(signature)) {
                    message("info", "Signed by someone you don't know.", TP);
                } else {
                    message("info", "Signed by: " + capitalize(TP->knownAs(signature)), TP);
                }

                if (arrayp(ob_data["signature"][i])) {
                    if (ob_data["signature"][i][1] != ob_data["signature"][i][0]) {
                        if (TP->query_skill("academics") >= ob_data["signature"][i][2]) {
                            message("info", "You are sure signature had been forged.", TP);
                        }
                    }
                }
            }
        }
        message("other_action", (string)TPQCN + " reads the " + query_name() + ".", ETP, ({ TP }));
        return 1;
    }else {
        return notify_fail("It looks all jumbled.\n");
    }
}

int __Use(string str)
{
    string command, obj;
    string effect;
    int uses;
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(TP)) {
        return 0;
    }
    if (!str) {
        return 0;
    }
    if (sscanf(str, "%s %s", obj, command) != 2) {
        obj = str;
    }
    if (!id(obj)) {
        return 0;
    }

    if (!TO->query_wielded() && !TO->query_worn()) {
        return notify_fail("You must wield or wear an item to use it.\n");
    }
    if (TP->query_casting() && objectp(TP->query_property("spell_casting"))) {
        return notify_fail("You are already doing something!\n");
    }
    if ((int)TO->query_use_delay() + query("used") > time()) {
        return notify_fail("That can't be used again yet.\n");
    }
    if (TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", TP);
        return 0;
    }
    effect = query("effect");
    if (!effect) {
        return 0;
    }
    uses = query("uses");
    if (!uses) {
        return 0;
    }
    uses--;
    set("used", time());
    set("uses", uses);
    if (uses < 1) {
        delete("uses");
        delete("effect");
    }
    return call_other(find_object_or_load(EFFECTS_D), effect, TP, TO, command);
}

void set_use_delay(int sec)
{
    set("use delay", sec);
}

int query_use_delay()
{
    if (!query("use delay")) {
        return 1;
    }
    return query("use delay");
}

void reset()
{
    // do temperature
    //attempt to fix random_monsters.c placement error - Saide, June 2017
    return;
}

void create()
{
    seteuid(getuid());   // ensures all objects have an euid.

    // Once all objects call ::create(), many of the checks that
    // ob_data and props exist can be removed, saving on cpu.
    ob_data = (["id" : ({}), "condition" : 100, "updated time" : time()]);
    props = ([]);
    item_bonuses = ([]);
    if (previous_object()) {
        creator = file_name(previous_object());
    }else {
        creator = "Unknown";
    }

    identified = ({});
    studied = ({});
    studied_failed = ([]);
    decay::create();
    //trying to see if this call might
    //fix some lingering/weird bugs - Saide, November 2016
    //if((int)TO->is_room()) TO->reset();
    return;
}

int query_updated_time()
{
    if (!ob_data["updated time"]) {
        ob_data += (["updated time" : time() - 1000]);
    }
    return ob_data["updated time"];
}

void init()
{
    string* actions;
    int i, j;

    // If this item is unique and someone else has it, then
    // remove it.
    // Thorn@ShadowGate - 28 June 2000
    if (unique_item == 1) {
        if (sizeof(children(query_unique_id())) > 2) {
            if (objectp(ETO) && (base_name(ETO) != "/d/shadowgate/void")) {
                move("/d/shadowgate/void");
            }
            return;
        }else {
            if (!objectp(ETO)) {
                ;
            }else if (!UNIQUE_D->ok_to_clone(TO->query_unique_id(), ETO)) {
                move("/d/shadowgate/void");
            }else if (userp(ETO)) {
                UNIQUE_D->issue_lease(TO->query_unique_id(), ETOQN, unique_lease);
            }else {
                UNIQUE_D->clear_lease(TO->query_unique_id());
            }
        }
    }
    add_action("__Read", "read");
    add_action("__Use", "use");
    if (!TO->query_property("repairtype")) {
        if (!TO->is_instrument() && !TO->is_armour() && !TO->is_weapon()) {
            TO->set_property("repairtype", ({ "tailor", "jewel", "woodwork", "leatherwork" }));
        }
    }
}

int move(mixed dest)
{
    int i, scaled;
    if (!objectp(TO)) {
        return MOVE_NOT_ALLOWED;
    }

    if (objectp(TO)) {
        TO->unequip();
    }
    if (!objectp(TO)) {
        return MOVE_NOT_ALLOWED;
    }
    if (TO->query("scaledlevel") && !living(TO)) {
        TO->delete("scaledlevel");
    }
    i = move::move(dest);
    if (objectp(TO)) {
        if (objectp(ETO) && living(ETO)) {
            if (intp(scaled = USER_D->get_scaled_level(ETO)) && (string)TO->query("scaledfor") == (string)ETO->query_true_name()) {
                TO->set("scaledlevel", scaled);
            }
        }

        if (!i && !living(TO)) {
            if (query_real_hidden()) {
                reset_hidden_seen();
                set_hidden(0);
            }
        }
    }
    return i;
}

int drop()
{
    if (query_property("monsterweapon")) {
        return 1;
    }
    if(query_property("no drop"))
        return 1;
    
    if (unique_item == 1) {
        UNIQUE_D->clear_lease(TO->query_unique_id());
    }
    return 0;
}

int get()
{
    string who;
    int pd;

    if (this_object()->query_property("monsterweapon") && userp(TP)) {
        return 0;
    }
    who = (string)this_object()->query_property("keep");
    if (stringp(who) && who != (string)TPQN) {
        write("A magical force prevents you from taking it!\n");
        say("A magical force prevents " + (string)TPQCN +
            " from taking the " + query_name() + ".\n", TP);
        return 0;
    }
    POISON_D->is_object_poisoned(TO, TP, "get", 1);
    if (TO->is_trapped("get")) {
        TO->execute_trap("get", TP);
    }
    if (TO->query_hidden() || TO->query_magic_hidden()) {
        return TP->detecting_invis();
    }
    return 1;
}

void set_magic_properties(string* temp)
{
    magic_properties = temp;
}

string* query_magic_properties(int a)
{
    string* temp;
    int x;

    temp = ({});
    if (!a) {
        return magic_properties;
    }
    if (a >= sizeof(magic_properties)) {
        return magic_properties;
    }
    for (x = 0; x < a; x++) {
        temp += ({ magic_properties[x] });
    }
    return temp;
}

string get_serial_number()
{
    serial_number = "SG" + time();
    return serial_number;
}

string query_serial_number()
{
    return serial_number;
}

// To allow this item to use the unique item system
// Thorn@ShadowGate - 27 June 2000
varargs void set_unique(int x)
{
    if (undefinedp(x)) {
        unique_item = 1;
    }else {
        unique_item = x;
    }
}

// To allow a custom lease period to be set by the
// coder.  There is no query function for this since
// the information will be stored in the UNIQUE_D
// Thorn@ShadowGate - 27 June 2000
void set_lease(int x)
{
    unique_lease = x;
}

// Checks if this item is unique.
// Thorn@ShadowGate - 27 June 2000
int query_unique()
{
    return unique_item;
}

// Sets this object's unique_id.
// Thorn@ShadowGate - 27 June 2000
string query_unique_id()
{
    return base_name(TO) + ".c";
}

//For wielding...

void set_limbString(string what)
{
    limbString = what;
}

void set_wielded(object who)
{
    wielded = who;
    cursed = who->query_name();
    if (TO->query_property("player enchanted")) {
        CHECK_D->validate(TO);
    }
}

string query_cursed()
{
    return cursed;
}

void set_hit(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return;
    }
    if (functionp(val)) {
        set_property("fhit", 1);
        hit = (*val)(1);
    }else {
        hit = val;
    }
}

void set_lrhit(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return;
    }
    if (functionp(val)) {
        set_property("flrhit", 1);
        lrhit = (*val)(1);
    }else {
        lrhit = val;
    }
}

void set_wield(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return;
    }
    if (functionp(val)) {
        set_property("fwield", 1);
        wieldf = (*val)(1);
    }else {
        wieldf = val;
    }
}

void set_unwield(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val)) {
        return;
    }
    if (functionp(val)) {
        set_property("funwield", 1);
        unwieldf = (*val)(1);
    }else {
        unwieldf = val;
    }
}

int query_damage()
{
    return 1;
}

int query_large_damage()
{
    return 1;
}

void db(string str)
{
    return;
}

void temp_hit()
{
    object item;
    mapping info;
    string file, func_name;
    int ret;

    if (!objectp(TO)) {
        return;
    }
    if (!TO->is_weapon() && !TO->is_lrweapon()) {
        return;
    }

    if (!info = TO->query_property("temp_hit_bonus")) {
        return;
    }
    if (!mapp(info) || !sizeof(keys(info))) {
        return;
    }

    file = info["file"];
    func_name = info["func name"];

    if (!file_exists(file + ".c")) {
        return;
    }
    if (!stringp(func_name)) {
        return;
    }

    if (!objectp(item = TO->query_property("temp_hit_item"))) {
        item = find_object_or_load(file);
        TO->set_property("temp_hit_item", item);
    }

    call_other(item, func_name, TO);
    return;
}

//varargs int property_special(mixed arg, object enemy_weapon, object attacker)
mixed query_hit()
{
    function f;
    temp_hit();
    if (query_property("hit")) {
        f = (: TO, "property_special" :);
        set_property("fhit", 1);
        return (*f)(1);
    }
    return hit;
}

mixed query_lrhit()
{
    function f;
    temp_hit();
    if (query_property("hit")) {
        f = (: TO, "property_special" :);
        set_property("flrhit", 1);
        return (*f)(1);
    }
    return lrhit;
}

mixed query_wield()
{
    return wieldf;
}

mixed query_unwield()
{
    return unwieldf;
}

object query_wielded()
{
    return wielded;
}

void unequip()
{
    if (wielded && objectp(wielded)) {
        __ActuallyUnwield();
    }
}

void __ActuallyUnwield()
{
    function f;
    string catchbug;
    int answer;
    mapping itembonuses;

    if (!objectp(wielded)) {
        return;
    }
    if (TO->query_property("funwield")) {
        unwieldf = TO->query_unwield();
        f = (: call_other, TO, unwieldf :);
        if ((!"/adm/daemon/shutdown_d"->shuttingDown()) && (query_verb() != "quit") && interactive(ETO)) {
            catchbug = catch(answer = (*f)());
            if (catchbug) {
                write(catchbug);
            }
            if (!answer) {
                return 1;
            }
        }else {
            if (!(*f)()) {
                return 1;
            }
        }
    }
    if (itembonuses = TO->query_item_bonuses()) {
        run_item_bonuses("remove", wielded, itembonuses);
    }

    wielded->remove_weapon_from_limb(this_object());
    if (stringp(unwieldf) && !query_property("funwield")) {
        message("my_action", unwieldf, wielded);
    }else {
        if (!wielded->query_property("silent_wield")){
            message("my_action", "You unwield " + query_short() + ".",
                wielded);
        }
    }
    if (objectp(environment(wielded))) {
        if (!wielded->query_property("silent_wield")) {
            message("other_action", (string)wielded->query_cap_name() +
                " unwields " + query_short() + ".", environment(wielded),
                ({ wielded }));
        }
    }
    set_not_inhand();
}

void set_not_inhand()
{
    wielded = 0;
    limbString = "";
}

int wieldable()
{
    return 1;
}

int reaction_to_hit(object target, int damage)
{
    return 0;
}

int thrown()
{
    return 1;
}

int thrown_hit(object target)
{
    return 0;
}

mapping* query_studied_failed()
{
    return studied_failed;
}

int is_studied_failed(string name, int level)
{
    if (!studied_failed || studied_failed == ([])) {
        return 0;
    }
    return studied_failed[name];
}

void add_studied_failed(string name, int level)
{
    if (!studied_failed) {
        studied_failed = ([]);
    }
    if (!studied_failed[name]) {
        studied_failed[name] = level;
        return;
    }
    studied_failed[name] = level;
}

void remove_studied_failed(string str)
{
    map_delete(studied_failed, str);
}

string* query_studied()
{
    return studied;
}

void add_studied(string str)
{
    studied += ({ str });
    map_delete(studied_failed, str);
}

int is_studied(string name)
{
    return (member_array(name, query_studied()) != -1);
}

string* query_identified()
{
    if (!pointerp(identified)) {
        identified = ({});
    }
    return identified;
}

void set_identified(string* myidentified)
{
    if (!pointerp(identified)) {
        identified = ({});
    }
    if (!pointerp(myidentified)) {
        return;
    }
    identified = myidentified;
    return;
}

void add_identified(string name)
{
    if (!pointerp(identified)) {
        identified = ({});
    }
    identified += ({ name });
}

int is_identified(string name)
{
    return (member_array(name, query_identified()) != -1);
}

void set_lore(string lore)
{
    set("lore", lore);
}

string query_lore()
{
    return (string)query("lore");
}

string query_language()
{
    if (!query("language")) {
        return "wizish";
    }
    return query("language");
}

void set_item_owner_prop(string str, int flag)
{
    int which_bit = -1;
    switch (str) {
    case "sale_clear":
        which_bit = 0;
        break;

    case "fence_clear":
        which_bit = 6;
        break;

    case "death_remove":
        which_bit = 12;
        break;

    case "death_clear":
        which_bit = 18;
        break;

    case "multiple_owners":
        which_bit = 24;
        break;

    default:
        break;
    }
    if (which_bit == -1) {
        return;
    }
    switch (flag) {
    case 0:
        item_owner_props = clear_bit(item_owner_props, which_bit);
        break;

    case 1:
        item_owner_props = set_bit(item_owner_props, which_bit);
        break;

    default:
        break;
    }
}

int query_item_owner_prop(string str)
{
    if (!str) {
        return 0;
    }
    //changing this so that the default will be 01000
    //which means the item owner will only clear
    //when an item is being fenced - and only have 1 owner
    //since gear is now kept on pk death
    //this wouldn't benefit someone who is killing
    //bob for his ownered sword of rabbit
    //slaying - maybe change "death_remove" to be
    //strip_remove or something? //Saide
    if (!item_owner_props) {
        item_owner_props = "01000";
    }

    switch (str) {
    case "sale_clear":
        return test_bit(item_owner_props, 0);

        break;

    case "fence_clear":
        return test_bit(item_owner_props, 6);

        break;

    case "death_remove":
        return test_bit(item_owner_props, 12);

        break;

    case "death_clear":
        return test_bit(item_owner_props, 18);

        break;

    case "multiple_owners":
        return test_bit(item_owner_props, 24);

        break;

    default:
        return 0;

        break;
    }
}

int add_item_owner(string str)
{
    if (!objectp(find_player(str))) {
        return 0;
    }
    if (avatarp(find_player(str))) {
        return 1;
    }
    if (sizeof(item_owners) >= 1 &&
        !query_item_owner_prop("multiple_owners")) {
        return 0;
    }
    if (member_array(str, item_owners) == -1) {
        item_owners += ({ str });
        return 1;
    }
    return 0;
}

string query_item_owners()
{
    return item_owners;
}

int query_owns_item(string str)
{
    if (!objectp(find_player(str))) {
        return 0;
    }
    if (avatarp(find_player(str))) {
        return 1;
    }
    if (member_array(str, item_owners) != -1) {
        return 1;
    }
    return 0;
}

void remove_item_owner(string str)
{
    if (member_array(str, item_owners) != -1) {
        item_owners = item_owners - ({ str });
    }
}

void clear_item_owners()
{
    item_owners = ({});
}

//following two functions are retained but are now defunct
//equipment bonuses are handled now with /daemon/equipment_d - allowing
//bonuses to degrade with equipment condition - Saide, February 2017
void add_the_bonus(object myplayer, string bonustype, int bonusvalue)
{
    return;

    if (!objectp(myplayer)) {
        return;
    }
    if (!stringp(bonustype)) {
        return;
    }
    if (!bonusvalue) {
        return;
    }

    switch (bonustype) {
    // stats
    case "strength":
    case "dexterity":
    case "constitution":
    case "intelligence":
    case "wisdom":
    case "charisma":
        myplayer->add_stat_bonus(bonustype, bonusvalue);
        break;

    // saving throws
    case "fortitude":
    case "will":
    case "reflex":
        myplayer->add_saving_bonus(bonustype, bonusvalue);
        break;

    // skills
    case "academics":
    case "athletics":
    case "craft, armorsmith":
    case "craft, jeweller":
    case "craft, leatherworker":
    case "craft, tailor":
    case "craft, weaponsmith":
    case "craft, woodworker":
    case "disguise":
    case "dungeoneering":
    case "endurance":
    case "healing":
    case "influence":
    case "perception":
    case "rope use":
    case "stealth":
    case "spellcraft":
    case "survival":
    case "thievery":
        myplayer->add_skill_bonus(bonustype, bonusvalue);
        break;

    case "attack bonus":
        myplayer->add_attack_bonus(bonusvalue);
        break;

    case "damage bonus":
        myplayer->add_damage_bonus(bonusvalue);
        break;

    case "armor bonus":
        myplayer->add_ac_bonus(bonusvalue);
        break;

    case "sight bonus":
        if (member_array((string)myplayer->query_race(), LIVING_D->night_races()) != -1) {
            myplayer->add_sight_bonus(-bonusvalue);
        }else {
            myplayer->add_sight_bonus(bonusvalue);
        }
        break;

    // misc bonuses held in set_property()
    case "magic resistance":
    case "spell damage resistance":
    case "damage resistance":
    case "spell penetration":
        myplayer->set_property(bonustype, bonusvalue);
        break;

    case "bonus spell slots":
        myplayer->set_property("bonus_spell_slots", bonusvalue);
        break;

    case "caster level":
        myplayer->set_property("empowered", bonusvalue);
        break;

    case "shieldMiss":
        myplayer->set_shieldMiss(bonusvalue);
        break;

// so we have a bunch of extra non-existent types here, I'm going to remove them... N, 8/15.
// and percentages aren't supported in any sourcebooks & don't really work in a d20 system so removing entirely.
    case "fire resistance":
    case "cold resistance":
    case "water resistance":
    case "air resistance":
    case "earth resistance":
    case "bludgeoning resistance":
    case "piercing resistance":
    case "slashing resistance":
    case "silver resistance":
    case "cold iron resistance":
    case "electricity resistance":
    case "acid resistance":
    case "sonic resistance":
    case "positive energy resistance":
    case "negative energy resistance":
    case "force resistance":
    case "divine resistance":
    case "untyped resistance":
    case "mental resistance":
    case "light resistance":
    case "darkness resistance":
    case "nature resistance":
        myplayer->set_resistance(replace_string(bonustype, " resistance", ""), bonusvalue);
        break;

    case "fire resistance percent":
    case "cold resistance percent":
    case "water resistance percent":
    case "air resistance percent":
    case "earth resistance percent":
    case "bludgeoning resistance percent":
    case "piercing resistance percent":
    case "slashing resistance percent":
    case "silver resistance percent":
    case "cold iron resistance percent":
    case "electricity resistance percent":
    case "acid resistance percent":
    case "sonic resistance percent":
    case "positive energy resistance percent":
    case "negative energy resistance percent":
    case "force resistance percent":
    case "divine resistance percent":
    case "untyped resistance percent":
    case "nature resistance percent":
    case "mental resistance percent":
    case "light resistance percent":
    case "darkness resistance percent":
        myplayer->set_resistance_percent(replace_string(bonustype, " resistance percent", ""), bonusvalue);
        break;

// functional resistance code here!! Contains sourcebook 5x energy types, 3x physical types, 4x divine types, plus untyped. N, 8/15.
    // case "fire resistance": case "cold resistance": case "electricity resistance": case "acid resistance": case "sonic resistance":
    case "bludgeoning resistance":
    case "piercing resistance":
    case "slashing resistance":
    case "positive energy resistance":
    case "negative energy resistance":
    case "force resistance":
    case "divine resistance":
    case "untyped resistance":
        myplayer->set_resistance(replace_string(bonustype, " resistance", ""), bonusvalue);
        break;
    }
}

void run_item_bonuses(string mystatus, object myplayer, mapping itembonuses)
{
// listing of currently functional bonuses: stats (strength, dexterity, constitution, intelligence, wisdom, charisma),
// magic resistance, spell damage resistance, damage resistance, armor bonus, attack bonus, damage bonus, sight bonus,
// saving throws (will, reflex, fortitude), caster level, bonus spell slots, skills (academics; athletics; craft, armorsmith;
// craft, jeweller; craft, leatherworker; craft, tailor; craft, weaponsmith; craft, woodworker; disguise; dungeoneering;
// endurance; healing; influence; perception; rope use; stealth; spellcraft; survival; thievery); spell penetration; shieldMiss
// adding resistance, and resistance perc -Ares

    int myhighest, i, j, mycurrent, mydifference, mymod, scaled;
    object* myarmors, * myweapons;
    string* mykeys;
    return;

    if (!objectp(myplayer)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!mapp(itembonuses)) {
        return;
    }
    if (!stringp(mystatus)) {
        return;
    }
    if (mystatus != "equip" && mystatus != "remove") {
        return;
    }

    mykeys = ({});
    mykeys += keys(itembonuses);
    if (!sizeof(mykeys)) {
        return;
    }

    for (j = 0; j < sizeof(mykeys); j++) {
        mymod = itembonuses[mykeys[j]];
        if (!mymod) {
            continue;
        }

        if (mymod < 0) {        //negative bonus; always add or remove without a check.
            if (mystatus == "equip") {
                add_the_bonus(myplayer, mykeys[j], itembonuses[mykeys[j]]);
            }else {
                add_the_bonus(myplayer, mykeys[j], (-1 * (itembonuses[mykeys[j]])));
            }
        }else { // if positive bonus, check through inven for other of the same bonus, and find the highest
            myarmors = myplayer->all_armour();
            myweapons = myplayer->query_wielded();
            myhighest = 0;
            if (intp(scaled = TO->query("scaledlevel")) && scaled > 0) {
                mymod = to_int(to_float(scaled) / to_float(myplayer->query_base_character_level()) * mymod);
                if (mymod < 1) {
                    mymod = 0;
                }
            }
            if (sizeof(myweapons)) {
                for (i = 0; i < sizeof(myweapons); i++) {
                    //make sure this is a valid object - Saide
                    if (!objectp(myweapons[i])) {
                        continue;
                    }
                    mycurrent = (int)myweapons[i]->query_item_bonus(mykeys[j]);
                    if ((mycurrent > myhighest) && myweapons[i] != TO) {
                        myhighest = mycurrent;
                    }
                }
            }
            if (sizeof(myarmors)) {
                for (i = 0; i < sizeof(myarmors); i++) {
                    if (!objectp(myarmors[i])) {
                        continue;
                    }
                    mycurrent = (int)myarmors[i]->query_item_bonus(mykeys[j]);
                    if ((mycurrent > myhighest) && myarmors[i] != TO) {
                        myhighest = mycurrent;
                    }
                }
            }

            // if the mod is the same or less than the highest already equipped, do nothing. If it is greater, modify.
            //changed to continue because this is returning before it loops through the all item bonuses on items
            //with more than one bonus
            if (myhighest >= mymod) {
                continue;                                //return;
            }
            mydifference = myhighest - mymod;
//                      tell_object(myplayer,"Doing run_item_bonuses with myhighest: "+myhighest+" and mymod: "+mymod+" and mydifference: "+mydifference+".");
            //changing here as well - Saide 7/2/2016
            if (!mydifference) {
                continue;                           //return;
            }
            if (mystatus == "equip") {
                add_the_bonus(myplayer, mykeys[j], (-1 * mydifference));
            }else {
                add_the_bonus(myplayer, mykeys[j], mydifference);
            }
        }
    }
}

//Added for support of items that have special circumstances around
//their adding of bonuses - Saide
int BonusCheck(string BonusName)
{
    return 1;
}

//function get_obfunc(string str) { return (: TO,str :); }

//new functionality to replace old stat bonuses with all magical bonuses
void set_item_bonus(string bonustype, int thebonus)
{
    if (!item_bonuses) {
        item_bonuses = ([]);
    }
    if (!thebonus) {
        if (item_bonuses[bonustype]) {
            map_delete(item_bonuses, bonustype);
        }
    }                                                                                // a "zero" needs to revoke the bonus entirely now for enchanting. N, 7/18
    else {
        item_bonuses[bonustype] = thebonus;
    }
}

int query_item_bonus(string bonustype)
{
    if (!item_bonuses) {
        item_bonuses = ([]);
    }
    if (!item_bonuses[bonustype]) {
        return 0;
    }
    return item_bonuses[bonustype];
}

void clear_item_bonus()
{
    item_bonuses = ([]);
}

mapping query_item_bonuses()
{
    if (!item_bonuses) {
        item_bonuses = ([]);
    }
    return item_bonuses;
}

string query_bonus_display()
{
    string ret = "";
    string* mykeys;
    int mytracker, i;
    mapping mybonuses;
    mybonuses = query_item_bonuses();
    if (!mapp(mybonuses) || !objectp(TP)) {
        return ret;
    }
    if (!sizeof(mybonuses)) {
        return ret;
    }
    mykeys = keys(mybonuses);

    if (is_identified((string)TPQN)) {
        mytracker = 0;
        for (i = 0; i < sizeof(mykeys); i++) {
            if (mybonuses[mykeys[i]]) {
                mytracker = 1;
            }
        }
        if (!mytracker) {
            return ret;            // skip out if it has nothing but zero (conditional) bonuses. N, 8/12.
        }
        ret += "\n%^BOLD%^%^WHITE%^You are aware of the following %^RESET%^%^WHITE%^(base)%^BOLD%^ innate magical properties of this item:%^RESET%^ ";
        if (mybonuses[mykeys[0]]) {
            if (!pointerp(mybonuses[mykeys[0]])) {
                ret += "" + mybonuses[mykeys[0]] + " " + mykeys[0] + "";
            }else {
                ret += "" + implode(mybonuses[mykeys[0]], ", ") + " " + mykeys[0] + "";
            }

            if (sizeof(mykeys) > 1) {
                for (i = 1; i < sizeof(mykeys); i++) {
                    if (mybonuses[mykeys[i]]) {
                        if (!pointerp(mybonuses[mykeys[i]])) {
                            ret += ", " + mybonuses[mykeys[i]] + " " + mykeys[i] + "";
                        }else {
                            ret += ", " + implode(mybonuses[mykeys[i]], ", ") + " " + mykeys[i] + "";
                        }
                    }
                }
            }
        }
        ret += ".\n";
    }
    return ret;
}

// Designed so that you can use set_property to create most common specials on armors and weapons.  This should make crafted armor,
// weapons and random item generators much more simple to use.
//
// struck function set via property, IE:
// set_property("struck","stun, trip, heal, attack, repair, disarm, cast, summon, reflect, poison, bleed, blind");
// all of the above functions are supported for armors
//
// hit functions are set by using:
// set_property("hit","stun, trip, heal, attack, repair, cast, summon, reflect, poison, bleed, blind");
// all of the above functions are supported for weapons..  note that the only difference is you can't use disarm on a weapon
//
// separate functions with comma and a space if you want more than one struck or hit special, specials are chosen at random
// but you could increase the chances of a special to occur if you entered the same one MORE THAN ONCE.
// damage and level of the specials are determined based on the enchantment of the item or the magic property
// of the item, whichever is higher
//
// set_property("struck frequency");  and set_property("hit frequency") determine how frequently the
// struck or hit function will fire.  Default is for armor is 30% of the time plus enchantment * 10.
// Note that struck only fires when the limb that the item is worn on is hit, and only then when it doesn't strike another
// thing also worn on that limb, like a piece of non magical equipment
// Default for a weapon is enchantment *5 + 10 with a cap of 40% currently
//
// set_property("struck spell","/cmds/spells/s/_sticks_into_snakes.c");
// set_property("hit spell","/cmds/spells/h/_hideous_laughter.c");  // struck and hit spells can be any spell you want
// this is required if you are using the set_property("struck","cast") or set_property("hit","cast") special
// spells that are set as helpful will target the wearer or wielder of the item, other spells will target
// the attacker
//
// set_property("struck summon", "/d/magic/mon/skeleton.c"); set_property("hit summon", "/d/magic/mon/bat.c"); // can be whatever mob
// this is required if you are using the set_property("struck","summon") or set_property("hit","summon"); special
// this will summon the monster and add it to the users's followers and make it protect the user
// just like whatever summon spell would do.
//
// All of the specials have default messages that will fire if you don't provide them.  In order to get
// the struck and hit specials to work via property, all you have to do is set_property("struck","stun") or set_property("hit","stun") for example.
// Note:  If you don't provide your own specials, the color codes for the default specials are done via CRAYON_D
// If you want to, however, you can provide custom messages for each special.  It is done by using:
// set_property("stun message", ([ "user"   : "As $T strikes your $O, $TS receives a jolt of magical energy, stunning $TO!",
//                                 "target" : "As you strike $U's $O, you are jolted by magical energy, stunning you!",
//                                 "room"   : "As $T strikes $U's $O, $TS receives a jolt of magical energy, stunning $TO!" ]) );
// $T  = attacker->QCN
// $TS = attacker->QS
// $TO = attacker->QO
// $TP = attacker->QP
//
// $U  = ETO->QCN
// $US = ETO->QS
// $UO = ETO->QO
// $UP = ETO->QP
//
// $O  = TO->query_short();
// $W  = weapon->query_short();
// $S  = summon->query_short();
varargs int property_special(mixed arg, object enemy_weapon, object attacker)
{
    string* specials, special, * ids, spell, * classes, the_class, summon, wound, poison, * poisons;
    int frequency, enchantment, min_level, damage;
    object spell_ob, target, summon_ob, bleed_ob;
    mapping messages = ([]), map = ([]);

    if (!objectp(ETO) || !living(ETO) || !objectp(EETO)) {
        return 0;
    }

    if (objectp(arg) || (!enemy_weapon && !attacker && !intp(arg))) {
        attacker = arg;
        messages["special"] = "weapon";
    }else {
        if (intp(arg)) {
            damage = arg;
        }
        messages["special"] = "armor";
    }

    if (!objectp(attacker)) {
        attacker = ETO->query_current_attacker();
    }
    if (!objectp(attacker)) {
        return 0;
    }

    if (query_property("struck")) {
        specials = explode(query_property("struck"), ", ");
    }
    if (query_property("hit")) {
        specials = explode(query_property("hit"), ", ");
    }
    if (!sizeof(specials)) {
        return 0;
    }

    special = specials[random(sizeof(specials))];

    enchantment = query_property("enchantment");
    if (enchantment < 1) {
        enchantment = 1;
    }
    if (query_property("magic") > enchantment) {
        enchantment = query_property("magic");
    }

    min_level = enchantment * 7;

    if (query_property("struck frequency")) {
        frequency = query_property("struck frequency");
    }
    if (query_property("hit frequency")) {
        frequency = query_property("hit frequency");
    }

    if (messages["special"] == "weapon") {
        if (!frequency) {
            frequency = (enchantment * 2) + 8;
        }
        if (frequency > 20) {
            frequency = 20;
        }
        damage = roll_dice(1, enchantment);
        messages["weapon"] = TO;
    }else {
        if (!frequency) {
            frequency = (enchantment * 5) + 10;
        }
        if (frequency > 40) {
            frequency = 40;
        }
        messages["weapon"] = enemy_weapon;
    }

    if (!damage) {
        damage = roll_dice(1, enchantment);
    }
    if (frequency < 10) {
        frequency = 10;
    }
    if (random(100) > frequency) {
        return damage;
    }

    messages["attacker"] = attacker;


    switch (special) {
    case "poison":

        messages["type"] = "poison";
        send_messages(messages);
        if ((!poison = query_property("struck poison")) && (!poison = query_property("hit poison"))) {
            poisons = get_dir("/d/common/obj/poisons/base/");
            poison = poisons[random(sizeof(poisons))];
            poison = "/d/common/obj/poisons/base/" + poison;
        }
        POISON_D->ApplyPoison(attacker, poison, ETO, "injury");
        break;

    case "bleed":

        messages["type"] = "bleed";
        send_messages(messages);
        if ((wound = query_property("struck wound")) || (wound = query_property("hit wound"))) {
            bleed_ob = new(wound);
        }
        if (!objectp(bleed_ob)) {
            bleed_ob = new("/d/magic/obj/bleeding_wound.c");
        }
        bleed_ob->set_level(min_level);
        bleed_ob->set_target(attacker);
        attacker->do_damage(attacker->return_target_limb(), min_level);
        break;

    case "blind":

        messages["type"] = "blind";
        send_messages(messages);
        attacker->set_temporary_blinded(enchantment);
        break;

    case "stun":

        messages["type"] = "stun";
        send_messages(messages);
        attacker->set_paralyzed(enchantment, "%^MAGENTA%^You are stunned can cannot move!%^RESET%^");
        break;

    case "trip":

        messages["type"] = "trip";
        send_messages(messages);
        attacker->set_tripped(roll_dice(1, enchantment), "%^YELLOW%^You are trying to get your feet back under you!%^RESET%^");
        break;

    case "heal":

        messages["type"] = "heal";
        send_messages(messages);
        ETO->do_damage("torso", -1 * (roll_dice(1, min_level) + enchantment + 5));
        break;

    case "attack":

        messages["type"] = "attack";
        send_messages(messages);
        if (sizeof(ETO->query_attackers())) {
            ETO->execute_attack();
        }
        break;

    case "repair":

        messages["type"] = "repair";
        send_messages(messages);
        TO->repairMe(roll_dice(1, enchantment));
        break;

    case "disarm": // don't use this with weapon specials, it would happen too often

        if (objectp(enemy_weapon)) {
            messages["type"] = "disarm";
            send_messages(messages);
            if (!attacker->will_save(min_level)) {
                ids = enemy_weapon->query_id();
                attacker->force_me("unwield " + ids[0]);
                attacker->remove_property("disarm time");
                attacker->set_property("disarm time", time() + (ROUND_LENGTH * roll_dice(1, enchantment)));
            }
            break;
        } // falls through intentionally if no valid weapon

    case "cast":

        if ((query_property("struck spell")) || (query_property("hit spell"))) {
            if (query_property("struck spell")) {
                spell = query_property("struck spell");
            }
            if (query_property("hit spell")) {
                spell = query_property("hit spell");
            }
            spell_ob = new(spell);
            classes = keys(spell_ob->query_spell_level_map());
            the_class = classes[random(sizeof(classes))];
            if (objectp(spell_ob)) {
                messages["type"] = "cast";
                send_messages(messages);
                if (spell_ob->query_helpful()) {
                    target = ETO;
                }else {
                    target = attacker;
                }
                spell_ob->use_spell(ETO, target, min_level, 100, the_class);
            }
            break;
        } //  falls through intentionally, if no valid spell to cast

    case "summon": // should be cautious using this with weapons, or there might be a ton of summoned stuff eventually

        if ((query_property("struck summon")) || (query_property("hit summon"))) {
            if (query_property("struck summon")) {
                summon = query_property("struck summon");
            }
            if (query_property("hit summon")) {
                summon = query_property("hit summon");
            }
            if (objectp(summon_ob = new(summon))) {
                if (summon_ob->query_name()) {
                    messages["summon"] = summon_ob->query_name();
                }else {
                    messages["summon"] = summon_ob->query_short();
                }
                messages["type"] = "summon";
                send_messages(messages);
                summon_ob->set("aggressive", 1);
                summon_ob->remove_property("swarm");
                summon_ob->set_property("minion", ETO);
                summon_ob->add_id("summoned monster");
                summon_ob->move(EETO);
                ETO->add_follower(summon_ob);
                ETO->add_protector(summon_ob);
                ETO->query_attackers()->add_attacker(summon_ob);
                break;
            }
        } // falls through intentionally if no summon property

    case "reflect": // falls through intentionally, reflect will be default behavior
    case "damage":
    default:

        if (messages["special"] == "armor") {
            messages["type"] = "reflect";
            send_messages(messages);
            attacker->do_damage("torso", damage);
        }else {
            messages["type"] = "damage";
            send_messages(messages);
            damage = roll_dice(1, min_level) + min_level / 2;
            attacker->do_damage(attacker->return_target_limb(), damage);
        }
        break;
    }

    if (messages["special"] == "weapon") {
        return roll_dice(1, enchantment);
    }
    return damage;
}

string color_me(string str)
{
    return CRAYON_D->color_string(str, "random");
}

void send_messages(mapping map)
{
    string type, user_message, target_message, room_message, summon, * to_replace, special;
    object weapon, attacker;
    mapping messages = ([]), replace = ([]);
    int i, user_messages, ranged;

    if (!mapp(map) || !sizeof(keys(map))) {
        return;
    }

    type = map["type"];
    attacker = map["attacker"];
    weapon = map["weapon"];
    special = map["special"];
    if (TO->is_lrweapon()) {
        ranged = 1;
    }

    switch (type) {
    case "poison":

        if (query_property("poison message") && mapp(query_property("poison message"))) {
            messages = query_property("poison message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, $TS is infected by a dangerous poison!";
            messages["target"] = "As you strike $U's $O, you are infected by a dangerous poison!";
            messages["room"] = "As $T strikes $U's $O, $TS is infected by a dangerous poison!";
        }else if (ranged) {
            messages["user"] = "As you shoot $T with your $O, you infect $TO with a dangerous poison!";
            messages["target"] = "As $U shoots you with $UP $O, $US infects you with a dangerous poison!";
            messages["room"] = "As $U shoots $U with $UP $O, $US infects $TO with a dangerous poison!";
        }else {
            messages["user"] = "As you strike $T with your $O, you infect $TO with a dangerous poison!";
            messages["target"] = "As $U strikes you with $UP $O, $US infects you with a dangerous poison!";
            messages["room"] = "As $U strikes $T with $UP $O, $USin fects $TO with a dangerous poison!";
        }
        break;

    case "bleed":

        if (query_property("bleed message") && mapp(query_property("bleed message"))) {
            messages = query_property("bleed message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, it tears a jagged wound in $TO!";
            messages["target"] = "As you strike $U's $O, it tears a jagged wound in you!";
            messages["room"] = "As $T strikes $U's $O, it tears a jagged wound in $TO!";
        }else if (ranged) {
            messages["user"] = "As you shoot $T with your $O, it opens up a jagged wound in $TO!";
            messages["target"] = "As $U shoots you with $UP $O, it opens up a jagged wound!";
            messages["room"] = "As $U shoots $T with $UP $O, it opens up a jagged wound!";
        }else {
            messages["user"] = "As you strike $T with your $O, it opens up a jagged wound in $TO!";
            messages["target"] = "As $U strikes you with $UP $O, it opens up a jagged wound!";
            messages["room"] = "As $U strikes $T with $UP $O, it opens up a jagged wound in $TO!";
        }
        break;


    case "blind":

        if (query_property("blind message") && mapp(query_property("blind message"))) {
            messages = query_property("blind message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, a sudden blinding flash of magical energy steals $TP sight!";
            messages["target"] = "As you strike $U's $O, a sudden blinding flash of magical energy steals your sight!";
            messages["room"] = "As $T strikes $U's $O, a sudden blinding flash of magical energy steals $TP sight!";
        }else if (ranged) {
            messages["user"] = "Your shoot $T right across the eyes, blinding $TO!";
            messages["target"] = "$U shoots right across your eyes, blinding you!";
            messages["room"] = "$U shoots right across $T's eyes, blinding $TO!";
        }else {
            messages["user"] = "Your attack hits $T right in the eyes, blinding $TO!";
            messages["target"] = "$U's attack hits you right in the eyes, blinding you!";
            messages["room"] = "$U's attack hits $T right in the eyes, blinding $TO!";
        }
        break;

    case "stun":

        if (query_property("stun message") && mapp(query_property("stun message"))) {
            messages = query_property("stun message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, $TS receives a jolt of magical energy, stunning $TO!";
            messages["target"] = "As you strike $U's $O, you are jolted by magical energy, stunning you!";
            messages["room"] = "As $T strikes $U's $O, $TS receives a jolt of magical energy, stunning $TO!";
        }else if (ranged) {
            messages["user"] = "You shoot $T right in the temple with your $O, stunning $TO!";
            messages["target"] = "$U shoots you right in the temple with $UP $O, stunning you!";
            messages["room"] = "$U shoots $T right in the temple with $UP $O, stunning $TO!";
        }else {
            messages["user"] = "You strike $T stoutly in the head with your $O, stunning $TO!";
            messages["target"] = "$U strikes you stoutly in the head with $UP $O, stunning you!";
            messages["room"] = "$U strikes $T stoutly in the head with $UP $O, stunning $TO!";
        }
        break;

    case "trip":

        if (query_property("trip message") && mapp(query_property("trip message"))) {
            messages = query_property("trip message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, $TS is knocked off balance and looses $TP footing!";
            messages["target"] = "As you strike $U's $O, you are knocked off balance and loose your footing!";
            messages["room"] = "As $T strikes $U's $O, $TS is knocked off balance and looses $TP footing!";
        }else if (ranged) {
            messages["user"] = "You shoot the front of $T's knee, knocking $TO to the ground!";
            messages["target"] = "$U shoots the front of your knee, knocking you to the ground!";
            messages["room"] = "$U shoots the front of $T's knee, knocking $TO to the ground!";
        }else {
            messages["user"] = "You sweep your $O at $T, knocking $TO to the ground!";
            messages["target"] = "$U sweeps $UP $O at you, knocking you to the ground!";
            messages["room"] = "$U sweeps $UP $O at $T, knocking $TO to the ground!";
        }
        break;

    case "heal":

        if (query_property("heal message") && mapp(query_property("heal message"))) {
            messages = query_property("heal message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, a surge of healing energy replenishes your health!";
            messages["target"] = "As you strike $U's $O, a sudden surge of healing energy replenishes $UP health!";
            messages["room"] = "As $T strikes $U's $O, a sudden surge of healing energy replenishes $UP health!";
        }else if (ranged) {
            messages["user"] = "As you shoot $T with your $O, a wave of healing energy washes over you!";
            messages["target"] = "As $U shoots you with $UP $O, a wave of healing energy washes over $UO!";
            messages["room"] = "As $U shoots $T with $UP $O, a wave of healing energy washes over $UO!";
        }else {
            messages["user"] = "As you strike $T with your $O, a wave of healing energy washes over you!";
            messages["target"] = "As $U strikes you with $UP $O, a wave of healing energy washes over $UO!";
            messages["room"] = "As $U strikes $T with $UP $O, a wave of healing energy washes over $UO!";
        }
        break;

    case "attack":

        if (query_property("attack message") && mapp(query_property("attack message"))) {
            messages = query_property("attack message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "You take advantage of the opening when $T strikes your $O, quickly executing another attack!";
            messages["target"] = "$U takes advantage of the opening when you strike $UP $O, quickly executing another attack!";
            messages["room"] = "$U takes advantage of the opening when $T strikes $U's $O, quickly executing another attack!";
        }else if (ranged) {
            messages["user"] = "You quickly fire another time with your $O!";
            messages["target"] = "$U quickly fires another time with $UP $O!";
            messages["room"] = "$U quickly fires another time with $UP $O!";
        }else {
            messages["user"] = "You take advantage of the opening left by your attack, striking again!";
            messages["target"] = "$U takes advantage of the opening left by $UP attack, striking again!";
            messages["room"] = "$U takes advantage of the opening left by $UP attack, striking again!";
        }
        break;

    case "repair":

        if (query_property("repair message") && mapp(query_property("repair message"))) {
            messages = query_property("repair message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "Your $O seems to absorb the energy of $T's attack and uses it to repair itself!";
            messages["target"] = "$U's $O seems to absorb the energy of your attack and uses it to repair itself!";
            messages["room"] = "$U's $O seems to absorb the energy of $T's attack and uses it to repair itself!";
        }else if (ranged) {
            messages["user"] = "Your $O seems to draw energy from $T and uses it to repair itself!";
            messages["target"] = "$U's $O seems to drawn energy from you and uses it to repair itself!";
            messages["room"] = "$U's $O seems to drawn energy from $T and uses it to repair itself!";
        }else {
            messages["user"] = "Your $O seems to draw energy from $T and uses it to repair itself!";
            messages["target"] = "$U's $O seems to draw energy from you and uses it to repair itself!";
            messages["room"] = "$U's $O seems to draw energy from $T and uses it to repair itself!";
        }
        break;

    case "disarm":

        if (query_property("disarm message") && mapp(query_property("disarm message"))) {
            messages = query_property("disarm message");
            user_messages = 1;
        }else if (special == "armor") { // should ONLY be possible with armor
            messages["user"] = "As $T strikes your $O, a jolt of magical energy knocks the $W out of $TP hand!";
            messages["target"] = "As you strike $U's $O, a jolt of magical energy knocks your $W out of your hand!";
            messages["room"] = "As $T strikes $U's $O, a jolt of magical energy knocks $TP $W out of $TP hand!";
        }else if (ranged) {
            messages["user"] = "This special should not be happening, please contact a wiz";
            messages["target"] = "This special should not be happening, please contact a wiz";
            messages["room"] = "This special should not be happening, please contact a wiz";
        }else {
            messages["user"] = "This special should not be happening, please contact a wiz";
            messages["target"] = "This special should not be happening, please contact a wiz";
            messages["room"] = "This special should not be happening, please contact a wiz";
        }
        break;

    case "cast":

        if (query_property("cast message") && mapp(query_property("cast message"))) {
            messages = query_property("cast message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, you begin casting a spell!";
            messages["target"] = "As you strike $U's $O, $US begins casting a spell!";
            messages["room"] = "As $T strikes $U's $O, $US begins casting a spell!";
        }else if (ranged) {
            messages["user"] = "As you shoot $T with your $O, magic flows through you and you begin casting a spell!";
            messages["target"] = "As $U shoots you with $UP $O, magic flows through $UO and $US begins casting a spell!";
            messages["room"] = "As $U shoots $T with $UP $O, magic flows through $UO and $US begins casting a spell!";
        }else {
            messages["user"] = "As you strike $T with your $O magic flows through you and you begin casting a spell!";
            messages["target"] = "As $U strikes you with $UP $O, magic flows through $UO and $US begins casting a spell!";
            messages["room"] = "As $U strikes $T with $UP $UO, magic flows through $UO and $US begins casting a spell!";
        }
        break;

    case "summon":

        summon = map["summon"];

        if (query_property("summon message") && mapp(query_property("summon message"))) {
            messages = query_property("summon message");
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, a $S appears at your side and protects you!";
            messages["target"] = "As you strike $U's $O, a $S appears at $UP side and protects $UO!";
            messages["room"] = "As $T strikes $U's $O, a $S appears at $UP side and protects $UO!";
        }else if (ranged) {
            messages["user"] = "As you shoot $T with your $O, a $S appears at your side and protects you!";
            messages["target"] = "As $U shoots you with $UP $O, a $S appears at $UP side and protects $UO!";
            messages["room"] = "As $U shoots $T with $UP $O, a $S appears at $UP side and protects $UO!";
        }else {
            messages["user"] = "As you strike $T with your $O, a $S appears at your side and protects you!";
            messages["target"] = "As $U strikes you with $UP $O, a $S appears at $UP side and protects $UO!";
            messages["room"] = "As $U strikes $T with $UP $O, a $S appears at $UP side and protects $UO!";
        }
        break;

    case "reflect":
    case "damage":
    default:

        if ((query_property("reflect message") && mapp(query_property("reflect message"))) || (query_property("damage message") && mapp(query_property("damage message")))) {
            messages = query_property("reflect message");
            if (!mapp(messages)) {
                messages = query_property("damage message");
            }
            user_messages = 1;
        }else if (special == "armor") {
            messages["user"] = "As $T strikes your $O, a surge of energy runs back into $T, hurting $TO!";
            messages["target"] = "As you strike $U's $O, a surge of energy hurts you!";
            messages["room"] = "As $T strikes $U's $O, a surge of energy runs back into $T, hurting $TO!";
        }else if (ranged) {
            messages["user"] = "You shoot $T painfully with your $O, dealing extra damage!";
            messages["target"] = "$U shoots you painfully with $UP $O, dealing extra damage!";
            messages["room"] = "$U shoots $T painfully with $UP $O, dealing extra damage!";
        }else {
            messages["user"] = "You strike $T painfully with your $O, dealing extra damage!";
            messages["target"] = "$U strikes you painfully with $UP $O, dealing extra damage!";
            messages["room"] = "$U strikes $T painfully with $UP $O, dealing extra damage!";
        }
        break;
    }

    user_message = messages["user"];
    target_message = messages["target"];
    room_message = messages["room"];

    if (objectp(ETO)) {
        replace["$U"] = ETO->QCN;
        replace["$UO"] = ETO->QO;                           // him/her
        replace["$US"] = ETO->QS;                           // he/she
        replace["$UP"] = ETO->QP;
    }                                                       // his/hers
    if (objectp(attacker)) {
        replace["$T"] = attacker->QCN;
        replace["$TO"] = attacker->QO;
        replace["$TS"] = attacker->QS;
        replace["$TP"] = attacker->QP;
    }
    if (objectp(TO)) {
        replace["$O"] = TO->query_short();
    }                                                                   // used for the wearer/wielder's weapon or armor
    if (objectp(weapon)) {
        replace["$W"] = weapon->query_short();
    }                                                                   // used for the attacker's weapon with armor specials
    if (summon) {
        replace["$S"] = summon;
    }

    to_replace = keys(replace);
    to_replace = sort_array(to_replace, "descending_size", CRAYON_D); // shorter strings organized last

    for (i = 0; i < sizeof(to_replace); i++) {
        user_message = replace_string(user_message, to_replace[i], replace[to_replace[i]]);
        target_message = replace_string(target_message, to_replace[i], replace[to_replace[i]]);
        room_message = replace_string(room_message, to_replace[i], replace[to_replace[i]]);
    }

    if (!user_messages) {
        user_message = color_me(user_message);
        target_message = color_me(target_message);
        room_message = color_me(room_message);
    }

    tell_object(ETO, user_message);
    tell_object(attacker, target_message);
    if (objectp(EETO)) {
        tell_room(EETO, room_message, ({ attacker, ETO }));
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////////
// END OF PROPERTY SPECIAL STUFF ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
