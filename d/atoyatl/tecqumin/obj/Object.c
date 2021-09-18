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

// std contains the def of MOVE
#include <std.h>
#include <daemons.h>
#include <security.h>
#include <valid_bonuses.h>
// daemons contains the #define of ALCHEMIST_D
#include <daemons.h>
#include <move.h>

// move contains the functions "move", "remove", "clean_up", "set_no_clean"
//   "set_last_location", "query_last_location", "set_weight", "query_weight"
inherit "/std/trap_data.c";
inherit MOVE;
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
//nosave string d_master;           // File name of an object's domain master ob
private string * identified;
private string *studied;
private mapping studied_failed;
string material;                  // Substance object is made from.
string *magic_properties;  //  Allows all objects to have magic properties
//Added by Saide for use with the soulbound/item ownership functions
//3/19/2007
string *item_owners = ({});

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
private nosave int hidden, magic_hidden;
private nosave object * hidden_seen;

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
int remove_property (string prop);

void unequip();
void __ActuallyUnwield();
void set_not_inhand();
int wieldable();
string * query_identified();
void add_identified(string str);
int is_identified(string name);
void add_studied(string str);
int is_studied(string name);
void add_studied_failed(string name,int level);
int is_studied_failed(string name,int level);
void remove_studied_failed(string name);
void set_read(string str);
void set_language(string str);
//void do_remove_stat(object myplayer, string mystat);
void run_item_bonuses(string mystatus,object myplayer,mapping itembonuses);

//Below added by Circe for faction-specific items.  11/24/07
void set_factionitem(string str);
string query_factionitem();
string factionitem;

//new functions for property-set bonuses. N, 7/12.
void set_item_bonus(string bonustype,int thebonus);
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

int save_me(string fname) {
    int x;
     if (query_property("temporary_item"))  return 0;
    seteuid(UID_RESTORE);
    x=catch(save_object(fname, 1));
    return x;
}

int restore_me(string fname) {
    int x;
    seteuid(UID_ROOT);
    x = catch(restore_object(fname, 1));
    return x;
}


// *** Object property functions ***
// I] That use the "ob_data" mapping

void init_ob() {
    ob_data = ([ "id": ({}) ]);

}

void set(string what, mixed arg)
{
    if( !stringp(what) ) return;
    if(functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) return;
    if(!ob_data) init_ob();
    if (what == "read" && !functionp(arg))
    {
        set_read(arg);
        return;
    }
    if(what == "language")
    {
        set_language(arg);
        return;
    }
// changing so an aggessive of 0 doesn't automatically swarm  *Styx* 8/29/03
//    if(what == "aggressive") TO->set_property("swarm",1);
    if(what == "aggressive" && arg != 0)  TO->set_property("swarm",1);
    if(functionp(arg))
    {
        if(TO->query_property("function_"+what)) TO->remove_property("function_"+what);
        TO->set_property("function_"+what, arg[1]);
    }
    if(ob_data[what]) ob_data[what] = arg;
    else ob_data += ([ what: arg ]);
    if(what == "value")
    {
        what = "cointype";
        if(ob_data[what]) ob_data[what] = "gold";
        else ob_data += ([ what: "gold" ]);
    }
}

protected void add(string what, mixed arg) {
    if(!ob_data) ob_data = ([]);
    if(functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) return;
    if(stringp(arg) || intp(arg)) arg = ({ arg});
    if(!ob_data[what]) {
        ob_data += ([what:arg]);
        return;
    }

    if(!pointerp(ob_data[what]) && !mapp(ob_data[what])) return;
    ob_data[what] += arg;
}

void delete(string what) {
    if( !stringp(what) ) return;
    if(!ob_data) init_ob();
    if(what == "aggressive") TO->remove_property("swarm");
    if(ob_data[what]) map_delete(ob_data,what);
}

varargs mixed query(string what, mixed element) {
    mixed res, tmp;
    int i, query_flag = 0;

    res = 0;
    if(!ob_data) init_ob();
    if(!stringp(what)) return 0;
    if(what == "negative levels")
    {
        what = "negative level";
        query_flag = 1;
    }
    if(!ob_data[what]) return 0;
    if(!element)
    {
        if(what == "negative level")
        {
            if(!query_flag) { res = ob_data[what]; }
            else if(query_flag && mapp(ob_data[what]))
            {
                tmp = values(ob_data[what]);
                for(i = 0;i < sizeof(tmp);i++)
                {
                    if(intp(tmp[i])) res += tmp[i];
                    continue;
                }
            }
        }
        else res = ob_data[what];
    }
    else if( stringp(element) ) res = ob_data[what][element];
    else if( (intp(element)) && pointerp(ob_data[what]) &&
             (element < sizeof(ob_data[what])) ) res = ob_data[what][element];
    if( pointerp(res) && previous_object() != this_object() ) res += ({});
    return res;
}


// II] That use the "props" mapping

void set_properties(mapping borg) {
    props += borg;
}

void UpdateBonuses(object possessor, string which)
{
	if(!stringp(which)) return;
	if(!objectp(possessor)) return;
	if(!living(possessor)) return;
	if(!objectp(TO)) return;
 	if(!living(TO))
	{
		if(TO->is_armor())
		{
			possessor->ApplyObjectBonuses(TO, possessor, which, "wear");
		}
		if(TO->is_weapon())
		{
			possessor->ApplyObjectBonuses(TO, possessor, which, "wield");
		}
		else
		{
			if(TO->query_property("inanimate_bonus"))
			{
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
    if(!TO->is_room()) { possessor = ETO; }
    if(member_array(prop, VALID_BONUSES) != -1)
    {
        if(!living(TO)) { UpdateBonuses(possessor, "remove"); }
    }
    if(prop == "enchantment"  && !random(20) && !query("no curse") && !query_property("no curse"))
    {
        value = -1* value;
    }
    if(pointerp(value))
    {
        if(!props) props = ([]);
        if(!props[prop] || !pointerp(props[prop])) props[prop] = ({});
        props[prop] += value;
        if(member_array(prop, VALID_BONUSES) != -1)
        {
            if(!living(TO)) { UpdateBonuses(possessor, "add"); }
        }
        return;
    }
    else
    {
        if(!props || !mapp(props)) props = ([]);
        if(!props[prop]) props[prop] = value;
        //random treasure on that will appear on monsters - Saide
        else if(props[prop])
        {
            //in the event of a property being something like an object
            //or maybe even a function then doing += will fail
            //hopefully this bit of code fixes that and pretty much retains
            //all properties except for the ones that might error - Saide June 2016
            if(intp(value) && intp(props[prop])) props[prop] += value;
            else if(stringp(value) && stringp(props[prop])) props[prop] += value;
            else if(floatp(value) && floatp(props[prop])) props[prop] += value;
            else props[prop] = value;
            if(member_array(prop, VALID_BONUSES) != -1)
            {
                if(!living(TO)) { UpdateBonuses(possessor, "add"); }
            }
            return;
        }
        props += ([ prop : value]);

        if(prop == "treasure_type" && !living(TO)) "/daemon/random_monster_treasure_d.c"->add_treasure(TO);
    }

    if(member_array(prop, VALID_BONUSES) != -1)
    {
        if(!living(TO)) { UpdateBonuses(possessor, "add"); }
    }
}

int armor_filter(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(ob->query_armor_prof("light")) { return 1; }
    if(ob->query_armor_prof("medium")) { return 1; }
    if(ob->query_armor_prof("heavy")) { return 1; }
    return 0;
}

mixed query_property(string prop)
{
// racial bonuses errored when querying from /std/races; had to apply manually
    object *worn;
    int num, mylevel;
    string subrace, binding;

  	if(!props)
	{
      	props = ([]);
       	return 0;
   	}

    if(prop == "empowered")
    {
// rearranging this so it only runs through the query chain once; cuts down on recursion. N, 5/15.
        if(FEATS_D->usable_feat(TO,"greater spell power")) num += 6;
        else {
            if(FEATS_D->usable_feat(TO,"improved spell power")) num += 4;
            else {
                if(FEATS_D->usable_feat(TO,"spell power")) num += 2;
            }
        }

        if((string)TO->query_race() == "human") {
          subrace = (string)TO->query("subrace");
          if(subrace) {
            if(strsrch(subrace,"genasi") != -1) num += 1; // +1 clevel to genasi planetouched
          }
        }
        num += props[prop];
        return num;
    }
// tweaking a few bonuses here with feats overhaul. Nienne, 03/10
// basic DR from 3 to 2; spell pen changed from 10/20 to 15/15 to match MR

    if(prop == "spell penetration")
    {
        if(FEATS_D->usable_feat(TO,"spell penetration"))         { num += 15; }
        if(FEATS_D->usable_feat(TO,"greater spell penetration")) { num += 15; }
        num += props[prop];
        return num;
    }

    if(prop == "spell dcs") { // we want this to pick up item "empowered" bonuses only, without spell power feats. Manually applied.
        if(FEATS_D->usable_feat(TO,"spell focus"))         { num += 2; }
        num += props["empowered"];
        return num;
    }

    if(prop == "damage resistance")
    {
        if(FEATS_D->usable_feat(TO,"damage resistance"))          { num += 2; }
        if(FEATS_D->usable_feat(TO,"improved damage resistance")) { num += 3; }
        num += props[prop];
        return num;
    }

    if(prop == "magic resistance")
    {
        if(FEATS_D->usable_feat(TO,"improved resistance"))  { num += 15; }
        if(FEATS_D->usable_feat(TO,"increased resistance")) { num += 15; }
        if((string)TO->query_race() == "human") {
          subrace = (string)TO->query("subrace");
          if(subrace) {
            if(strsrch(subrace,"genasi") != -1) num += 10; // +10 MR all genasi
          }
        }
        if((string)TO->query_race() == "gnome") {
          subrace = (string)TO->query("subrace");
          if(subrace) {
            if(subrace == "deep gnome" || subrace == "svirfneblin") num += 10;
          }
        }
        if((string)TO->query_race() == "orc") {
          subrace = (string)TO->query("subrace");
          if(subrace) {
            if(subrace == "orog" || subrace == "tanarukk") num += 10;
          }
        }
        if((string)TO->query_race() == "elf") {
          subrace = (string)TO->query("subrace");
          if(subrace) {
            if(subrace == "fey'ri") num += 10;
          }
        }
        if((string)TO->query_race() == "yuan-ti") num += 10;
// check for raised resistance prop - spells & plat bands both give self-level MR & should NOT stack with drow/shade racial. N, 9/15.
        if(((string)TO->query_race() == "drow" || (string)TO->query_race() == "shade") && !TO->query_property("raised resistance")) {
          mylevel = (int)TO->query_level()+10;
          num += mylevel; // drow/shade racial, MR of overall character level +10.
        }
        num += props[prop];
        return num;
    }
    if(prop == "no death")
    {
        if(FEATS_D->usable_feat(TO,"death ward")) return 1;
        if(FEATS_D->usable_feat(TO,"chronicler")) return 1;
    }
// spellturning is now handled in spell.c to prevent stacking feats.
/*    if(prop == "spellturning")
    {
        if(FEATS_D->usable_feat(TO,"spell reflection")) { num += 15; }
        num += props[prop];
        return num;
    }*/
    if(prop == "spell damage resistance")
    {
        if((string)TO->query_race() == "human") {
          subrace = (string)TO->query("subrace");
          if(subrace) {
            if(subrace == "maalish") num += 5; // +5 SR for human Maalish ethnicity
          }
        }
        if(FEATS_D->usable_feat(TO,"resistance")) num+= 2;
        if(FEATS_D->usable_feat(TO, "increased resistance")) num += 4;
        if(FEATS_D->usable_feat(TO, "improved resistance")) num += 6;
        num += props[prop];
        return num;
    }

	//Added this to allow for a temporary enchantment property - Saide
	if(prop == "enchantment")
	{
		if(props["temporary enchantment"])
		{
			return props[prop] + props["temporary enchantment"];
		}
	}
      if(prop == "soulbound"){
            if(TO->is_sheath()) {
                worn = ({});
                worn = all_inventory(TO);
                if(sizeof(worn)) {
                    if((int)worn[0]->query_property("soulbound")) return 1;
                }
            }
      }
    	return props[prop];
}

//added query_property("curseditem") on advice from Garrett
//in setting up curses on items that don't get enchantments
//until they are wielded
//Circe 9/26/04
int is_cursed() {
    if(TO->query_property("curseditem")){
       return 1;
    }
    return query_property("enchantment") && query_property("enchantment") < 0;
}

void remove_all_properties()
{
	if(!living(TO))
	{
		if(objectp(ETO))
		{
			if(sizeof(keys(props)) != sizeof(keys(props) - VALID_BONUSES))
			{
				UpdateBonuses(ETO, "remove");
			}
		}
	}

    remove_property("shapeshifted");
    props = ([]);
}

int remove_property (string prop)
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

    if(prop == "shapeshifted")
    {
        if(objectp(shape = TO->query_property("shapeshifted")))
        {
            shape->remove(); // hopefully to reverse shapeshifting effects if it disappears for whatever reason -Ares
        }
    }

    if(props && props[prop])
	{
//        	props[prop] = 0;
		if(member_array(prop, VALID_BONUSES) != -1)
		{
			if(!living(TO))
			{
				tmp_flag = 1;
				if(objectp(ETO)) { UpdateBonuses(ETO, "remove"); }
			}
		}
		map_delete(props,prop);
		if(!living(TO))
		{
			if(sizeof(keys(props)) != sizeof(keys(props) - VALID_BONUSES) && tmp_flag == 1)
			{
				if(objectp(ETO)) { UpdateBonuses(ETO, "add"); }
			}
		}
        	return 1;
    	}
    	return 0;
}

int remove_property_value(string prop, mixed val) {
    if(props && props[prop]) {
        props[prop] -= val;
        return 1;
    }
    return 0;
}

string * regexp_query_property (string pattern) {
    string *vars, *prop;

    vars = keys(props);
    prop = regexp (vars, pattern);
    if(!prop)
        prop = ({});
    return prop;
}

int has_property(mixed val) {
   if (mapp(val)) return 0;
    if(!pointerp(val)) {
       if (member_array(val,keys(props)) == -1) return 0;
       else return 1;
    } else {
    if (sizeof(keys(props)) == sizeof(keys(props)-(mixed *)val) ) return 0;
      else return 1;
    }
}

// *** One line set and query functions ***
void   set_id(string str) {
    set("id", str);
}
void   set_short(string str) {
    set("short", str);
}
void   set_long(string str) {
    set("long", str);
}
void   add_id(string str) {
    add("id",str);
}

void remove_id(string str)
{
    string *tmp_ids;
    tmp_ids = (string*)TO->query_id();
    tmp_ids -= ({ str });
    TO->delete("id");
    TO->set("id",tmp_ids);
}

void   set_value(int x) {
    set("value", x);
    if(!query("cointype")) {
        set("cointype","gold");
    }
}

void   set_cointype(string str) {
    set("cointype",str);
}
string *query_id() {
    return query("id");
}
string query_name() {
   /* adding a default in case one isn't set for bug prevention, found often with thrown objects *Styx*  12/24/03, last change 8/29/03  */
    if(!true_name)
	return("unnamed object");
    return true_name;
}
string query_true_name() {
    return true_name;
}

string query_long(string str)
{
	string tmd;
	function func;
    //support for old stuff - so it doesn't break - Saide
    if(functionp(ob_data["long"]))
    {
        return(string)(*ob_data["long"])(str);
    }
    //new method of being able to use
    //a functionp for a long description
    //in an object that saves to a player/etc - Saide
    if(tmd = query_property("function_long"))
    {
        func = (:TO, tmd:);
        if(!tmd = (*func)())
        {
            tmd = "A function messed up in query_long() in Object.c";
        }
    }
    else
    {
        tmd = ob_data["long"];
    }
    return tmd;
}

int query_value() {
    return(int)this_object()->query("value");
}

string query_cointype() {
    return(string)this_object()->query("cointype");
}
int query_destroy() {
    return ob_data["destroy"];
}
string query_creator() {
    return creator;
}

// *** More complicated set and query functions ***

int id(string str) {
    int i, d, res;


    string *parts, what, where;

    if(!ob_data) init_ob();
    if( !stringp(str) ) return 0;
   if (!objectp(TO)) return 0;
 // If it's not a valid object, why are we trying? - Garrett 05/10/2002.
////////////////////////////////////////////////////////////////////////
// This section added to allow players to use 'my'  or 'on ground' to //
// accurately id stuff in their inventory or on the ground, respectively.
/////////////////////////////////////////////////////                 //
    if (sscanf(str, "my %s", what)){               //                 //
      if (ETO != TP){ return 0;}                   //                 //
      str = what;                                  //  Lujke  2016    //
    } else {                                       //                 //
      res = sscanf(str, "%s on ground", what);     /////////////////////
      if (res > 0){                                //
        if ( ETO == TP){                           //
          return 0;                                //
        }                                          //
        res = sscanf(what, "%s %d", what, d);      //
        str = what;                                //
        if (res == 2){                             //
          str = str + " " + d;                     //
        }                                          //
      }                                            //
    }                                              //
/////////////////////////////////////////////////////

    if( lower_case(str) == true_name) return 1;

    if(member_array(str, ob_data["id"]) != -1) return 1;

    if(userp(TO) && objectp(TP)) {
        if(TP->knownAs(TO->query_true_name())) {
            if(lower_case(TP->knownAs(TO->query_true_name())) == lower_case(str)) {
                return 1;
            }
        }
    }
    if(str == "attacker" && objectp(TP) && !avatarp(TO) && (!TO->query_invis() || TP->detecting_invis())){
       if(member_array(TO,TP->query_attackers()) != -1) return 1;
     }

    return 0;
}

void set_name(string str) {
    if( !stringp(str) ) return;
    cap_name = capitalize(str);
    true_name = str;
    if(creator) return;
    if(previous_object()) creator = file_name(previous_object());
    else creator = "Unknown";
}


int isMagic(){
    int p = 0;
    if (query_property("enchantment") || query_property("magic") || query_property("spell") || query_property("spelled")){

        p += query_property("enchantment");
        p += query_property("magic");
        if (intp(query_property("spell")))
        p += query_property("spell");
    }
    p += query("uses");
    return p;
}


string addMagic(string theShort){

    int p;
    if (p = isMagic()) {
        switch (p) {
        case -1:
        case 1:
            theShort = theShort+" (surrounded by a faint blue glow)";
            break;
        case -2:
        case 2:
            theShort = theShort+" (surrounded by a blue glow)";
            break;
        case -3:
        case 3:
            theShort = theShort+" (surrounded by a bright blue glow)";
            break;
	case -4:
	case 4:
            theShort = theShort+" (surrounded by a very bright blue glow)";
	    break;
	case -5:
	case 5:
            theShort = theShort+" (surrounded by an extremely bright blue glow)";
            break;
        default:
            theShort = theShort+" (surrounded by a nearly blinding blue glow)";
            break;
        }
    }
    return theShort;
}

string query_obvious_short(){
    return query("general short");
}

string set_obvious_short(string str){
    set("general short",str);
}


string query_short()
{
    string theShort,*short_info, tmd;
    int i;
    function func;
    if(!ob_data) init_ob();
    if(!living(TO) && this_object()->query_invis()) return 0;
    theShort = query_obvious_short();
    if(!theShort || (objectp(TP) && is_identified((string)TPQN))) {
        if(functionp(ob_data["short"])) {
            theShort = (string)(*ob_data["short"])();
        } else {
            theShort =  ob_data["short"];
        }
    }
    if (objectp(TP)) {
        if (TP->get_static("detecting magic")) {
            theShort = addMagic(theShort);
        }
    }

    if(query_property("added short"))
    {
        short_info = (string *)query_property("added short");
        if(pointerp(short_info) && sizeof(short_info))
        {
            for(i=0;i<sizeof(short_info);i++)
            {
                if(!stringp(short_info[i])) { continue; }
                theShort += short_info[i];
            }
        }
    }

    if(objectp(TP) && !TO->is_room() && !living(TO))
    {
        if(TP->query("is_auto_detecting_traps"))
        {
            if(sizeof(TO->query_trap_data()))
            {
                theShort = TO->get_trap_object_auto_detect(theShort, TP);
            }
        }
    }
    if(tmd = query_property("function_short"))
    {
        func = (:TO, tmd:);
        if(!theShort = (*func)())
        {
            theShort = "A function messed up in query_short() in Object.c";
        }
    }
    if(TO->is_weapon() || !wielded) return theShort;
    else return theShort+limbString;
}

string query_eng_short() {
    string str,s1,s2;
    if(!ob_data) init_ob();
    if(this_object()->query_invis()) return 0;

    str = query_obvious_short();
    if(!str || (objectp(TP) &&  is_identified((string)TPQN))){
        if(functionp(ob_data["short"])) {
            str = (string)(*ob_data["short"])();
        } else {
            str =  ob_data["short"];
        }
    }
    if(sscanf(str,"A %s",s1)) {
        return s1;
    }
    if(sscanf(str,"a %s",s1)) {
        return s1;
    }
    return str;
}

string query_cap_name() {
    if(!true_name) return 0;
    if(!cap_name) return 0;
    if(this_object()->query_invis()) return "Someone";
    if(this_object()->query_ghost()) return "A ghost";
    return cap_name;
}

string query_vis_cap_name() {
// This function is here to prevent objects that assume everything has a
// vis_cap_name set, has one, when users/monsters were the only previous ones.
    return query_cap_name();
// This should get properly overridden by the user.c object.
}

string query_vis_name() { return query_name(); }
// Same logic as for query_vis_cap_name here. Bug Prevention.
int query_light() {
    if(!props) return 0;
    if(props["light"]) return props["light"];
    return 0;
}

void set_destroy() {
    if(!ob_data) ob_data = ([]);
    ob_data["destroy"] = 1;
}

void add_hidden_seen(object obj){
     if(!pointerp(hidden_seen)){
          hidden_seen = ({});
     }
     hidden_seen += ({obj});
}

void add_all_to_hidden_seen(object * objs){
    if(!pointerp(hidden_seen)){
      hidden_seen = ({});
    }
    hidden_seen += objs;
}

object * query_hidden_seen(){
     return hidden_seen;
}
void reset_hidden_seen(){
    if (hidden_seen) {
        hidden_seen = ({});
    }
}
void set_hidden(int xxx) {
    if (xxx) {
        hidden_seen = ({});
    }
    hidden = xxx;
}

void set_magic_hidden(int xxx) {
    magic_hidden = xxx;
}

int query_real_hidden(){
    return hidden;
}

int query_hidden() {
     return hidden && (objectp(TP)?(member_array(TP,hidden_seen) == -1):1);
}

int query_magic_hidden() {
    return magic_hidden;
}

int is_detectable() {
    return 1;
}
/*
mixed prop( string str ) {
    mixed tmp;

    // first check if an override has been set in the object
    // (allows unique objects with properties different from the default)
    if( !undefinedp( tmp = query( str ) ) ) return tmp;
    // check all is set that should be
    if( !d_master || !str || !material ) return tmp;
    // convert, eg  "hardness"-> "hardness/metal/steel"
    // To not have the material added, start str with a /
    if( str[0..0] != "/" ) str += material;
    // If the object comes from a domain without a master, use alchemist
    if( d_master == ALCHEMIST_D ) return ALCHEMIST_D-> get( str );
    // call the object's domain master ob to get the property.
    return d_master-> query( str );
}

void set_material( string str ) {
    mixed parts, domain;
    int size;

    // make sure "material" exists and starts with a /
    if( !str ) material = "/default";
    else material = (  (str[0..0] == "/") ? str : ("/" + str)  );

    // The next few lines do the equivalent of
    //   sscanf( material, "%s/%s", type, name );
    // except they search for the / from the other end first.
    parts = explode( material, "/" );
    size = sizeof( parts );
    set( "material_name", parts[size-1] );
    set( "material_type", ((size==1) ? "none" : implode(parts[0..size-2],"/")));

    // set_material can be called either on creation of an object or later
    // the first time it is called, previous_object() is passed to setup_object()
    // so things like finding the temperature of the creating object can be done
    // later times only properties relating to the material need to be altered.
    if( d_master ) {
        d_master-> setup_object( this_object() );
        return;
    }
    // objects in /wizard/ not /d/ directories need to set the property
    // "domain" so we know where to look for the domain master ob.
    if( !( domain = query("domain") ) ) domain = this_object();
    // If the domain doesn't have a master ob, use ALCHEMIST_D
    if( !( d_master = domain_master( domain ) ) ) d_master = ALCHEMIST_D;
    d_master-> setup_object( this_object(), previous_object() );
}
*/

void set_read(string str){
    string *read;
    read = ob_data["read"];
    if (!pointerp(read)) {
        read = ({});
    }
    read += ({str});
    ob_data["read"]=read;
}

void set_language(string str){
    string *read;
    read = ob_data["language list"];
    if (!pointerp(read)) {
        read = ({});
    }
    read += ({str});
    ob_data["language list"]=read;
}

void set_factionitem(string str){
   factionitem = str;
}

string query_factionitem(){
   return factionitem;
}

void sign(object signer){
    if(!pointerp(ob_data["signature"])) {
      ob_data["signature"] = ({capitalize(signer->query_name())});
      } else {
     ob_data["signature"] += ({capitalize(signer->query_name())});
    }
}

int __Read(string str) {
    int i;
	if(!objectp(TO)) return 0;
	if(!objectp(TP)) return 0;
    if(!str) return notify_fail("Read what?\n");
    if(objectp(ETO))
    if(present(str,ETO) != TO) return 0;//notify_fail("You do not notice that here.\n");
    if(query_hidden() || query_magic_hidden()) return 0;//return notify_fail("You do not notice that here.\n");
    if(!ob_data || !ob_data["read"])
        return notify_fail(living(this_object()) ? "Read a living thing?\n" :
                           "There is nothing on it to read.\n");
    if(functionp(ob_data["read"])){
       if(query_property("sealed")){
          tell_object(TP,"That seems to be sealed.  You will need "+
             "to break the seal first.");
          return 1;
       }
        return(int)(*ob_data["read"])(str);
    }
    else if(stringp(ob_data["read"]) || pointerp(ob_data["read"])) {
       if(query_property("sealed")){
          tell_object(TP,"That seems to be sealed.  You will need "+
             "to break the seal first.");
          return 1;
       }
        if(stringp(ob_data["read"])) {
            message("reading", ob_data["read"], TP);
        } else if (pointerp(ob_data["read"])) {
            for(i=0;i<sizeof(ob_data["read"]);i++){
                if (pointerp(ob_data["language list"]) && sizeof(ob_data["language list"]) > i) {
                    ob_data["language"] = ob_data["language list"][i];
                }
                message("reading", ob_data["read"][i], TP);
            }
        }
// moving the signature info. line down so it doesn't show unless there is one *Styx* 8/29/03
//        message("info", "-=-=-=-=-=-=-=-=-=Signature Info=-=-=-=-=-=-=-=-=-",TP);
        if (pointerp(ob_data["signature"])){
           message("info", "-=-=-=-=-=-=-=-=-=Signature Info=-=-=-=-=-=-=-=-=-",TP);

            for(i=0;i<sizeof(ob_data["signature"]);i++){
                message("info","Signed by: "+ob_data["signature"][i],TP);
            }
        }
        message("other_action", (string)TPQCN+" reads the "+query_name()+".", ETP,
                ({ TP}));
        return 1;
    }
    else return notify_fail("It looks all jumbled.\n");
}

int __Use(string str){

    string command, obj;
    string effect;
    int uses;
	if(!objectp(TO)) return 0;
	if(!objectp(TP)) return 0;
if(!str) { return 0; }
    if(sscanf(str, "%s %s", obj, command)!= 2) {    obj = str;    }
    if (!id(obj)) {        return 0;    }

    if (!TO->query_wielded() && !TO->query_worn()) {
        return notify_fail("You must wield or wear an item to use it.\n");
    }
    if (TP->query_casting() && objectp(TP->query_property("spell_casting"))) {
        return notify_fail("You are already doing something!\n");
    }
    if ((int)TO->query_use_delay()+query("used") > time()) {
        return notify_fail("That can't be used again yet.\n");
    }
    if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() ) {
        TP->send_paralyzed_message("info",TP);
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
    set("used",time());
    set("uses",uses);
     if(uses < 1){
		delete("uses");
		delete("effect");
	}
    return call_other(find_object_or_load(EFFECTS_D),effect,TP,TO,command);
}

void set_use_delay(int sec){
    set("use delay",sec);
}

int query_use_delay(){
    if (!query("use delay")) {
        return 1;
    }
    return query("use delay");
}

void reset()
{
    // do temperature
    //attempt to fix random_monsters.c placement error - Saide, June 2017
}

void create() {
    seteuid( getuid() ); // ensures all objects have an euid.

    // Once all objects call ::create(), many of the checks that
    // ob_data and props exist can be removed, saving on cpu.
    ob_data = (["id": ({}), "condition":100]);
    props = ([]);
    item_bonuses = ([]);
    if(previous_object()) creator = file_name(previous_object());
    else creator = "Unknown";

    identified = ({});
    studied = ({});
    studied_failed = ([]);
    reset();
	//do not comment this out - the world WILL break - Saide
}

void init()
{
    string *actions;
    int i,j;

    // If this item is unique and someone else has it, then
    // remove it.
    // Thorn@ShadowGate - 28 June 2000
    if(unique_item == 1)
    {
        if(sizeof(children(query_unique_id())) > 2)
        {
            if (objectp(ETO) && (base_name(ETO) != "/d/shadowgate/void") )
            move("/d/shadowgate/void");
            return;
        }
        else
        {
            if(!objectp(ETO));
            else if(!UNIQUE_D->ok_to_clone(TO->query_unique_id(), ETO))
            {
                move("/d/shadowgate/void");
            }
            else if(userp(ETO))
            {
                UNIQUE_D->issue_lease(TO->query_unique_id(),ETOQN,unique_lease);
            }
            else
            {
                UNIQUE_D->clear_lease(TO->query_unique_id());
            }
        }
    }
    add_action("__Read", "read");
    add_action("__Use","use");
}

int move(mixed dest)
{
    int i;
    if(!objectp(TO)) { return MOVE_NOT_ALLOWED; }

    if(objectp(TO)) { TO->unequip(); }

    if(!objectp(TO)) { return MOVE_NOT_ALLOWED; }

    if(objectp(ETO))
    {
		if(living(ETO))
		{
    		ETO->ApplyObjectBonuses(TO, ETO, "remove", "move");
		}
	}

	i = move::move(dest);


	if(objectp(TO))
	{
		if(objectp(ETO) && living(ETO))
		{
			ETO->ApplyObjectBonuses(TO, ETO, "add", "move");
		}

		if (!i && !living(TO))
		{
			if (query_real_hidden())
			{
				reset_hidden_seen();
				set_hidden(0);
			}
		}
	}
    return i;
}

int drop() {
    if(query_property("monsterweapon"))
        return 1;
    if(query_property("soulbound"))
        return 1; // trying out new binding property, N 3/15
    // If this item is dropped, clear the lease on it to allow
    // the destination to possess it.
    // Thorn@ShadowGate - 28 June 2000
    if(unique_item == 1) {
        UNIQUE_D->clear_lease(TO->query_unique_id());
    }
    return 0;
}

int get()
{
    string who;
    int pd;

    if(this_object()->query_property("monsterweapon") && userp(TP)) return 0;
    who = (string)this_object()->query_property("keep");
    if(stringp(who) && who != (string)TPQN) {
        write("A magical force prevents you from taking it!\n");
        say("A magical force prevents "+(string)TPQCN+
            " from taking the "+query_name()+".\n", TP);
        return 0;
    }
    POISON_D->is_object_poisoned(TO, TP, "get", 1);
    if(TO->is_trapped("get"))
        TO->execute_trap("get", TP);
      if(TO->query_hidden() || TO->query_magic_hidden()) return TP->detecting_invis();
    return 1;
}

void set_magic_properties(string *temp) {
    magic_properties = temp;
}

string *query_magic_properties(int a) {
    string *temp;
    int x;

    temp = ({});
    if(!a) return magic_properties;
    if(a >= sizeof(magic_properties)) return magic_properties;
    for(x=0;x<a;x++) {
        temp += ({ magic_properties[x]});
    }
    return temp;
}

string get_serial_number() {
    serial_number = "SG"+time();
    return serial_number;
}

string query_serial_number() {
    return serial_number;
}

// To allow this item to use the unique item system
// Thorn@ShadowGate - 27 June 2000
varargs void set_unique(int x) {
    if(undefinedp(x)) unique_item = 1;
    else unique_item = x;
}

// To allow a custom lease period to be set by the
// coder.  There is no query function for this since
// the information will be stored in the UNIQUE_D
// Thorn@ShadowGate - 27 June 2000
void set_lease(int x) {
    unique_lease = x;
}

// Checks if this item is unique.
// Thorn@ShadowGate - 27 June 2000
int query_unique() {
    return unique_item;
}

// Sets this object's unique_id.
// Thorn@ShadowGate - 27 June 2000
string query_unique_id() {
    return base_name(TO)+".c";
}

//For wielding...

void set_limbString(string what) {
    limbString = what;
}


void set_wielded(object who) {
    wielded = who;
    cursed = who->query_name();
}
string query_cursed() { return cursed; }


void set_hit(mixed val) {
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    if(functionp(val)) {
        set_property("fhit",1);
        hit = val[1];
    }
    else
        hit = val;
}

void set_lrhit(mixed val) {
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    if(functionp(val)) {
        set_property("flrhit",1);
        lrhit = val[1];
    }
    else
        lrhit = val;
}

void set_wield(mixed val)
{
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    if(functionp(val)) {
        set_property("fwield",1);
        wieldf = val[1];
    }
    else
        wieldf = val;
}

void set_unwield(mixed val) {
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    if(functionp(val)) {
        set_property("funwield",1);
        unwieldf = val[1];
    }
    else
        unwieldf = val;
}


int query_damage() {
    return 1;
}


int query_large_damage() {
    return 1;
}

mixed query_hit() {
    return hit;
}

mixed query_lrhit() {
    return lrhit;
}

mixed query_wield() {
    return wieldf;
}

mixed query_unwield() {
    return unwieldf;
}


object query_wielded() {
    return wielded;
}


void unequip() {
    if(wielded && objectp(wielded)) __ActuallyUnwield();
}

void __ActuallyUnwield() {
    function f;
	string catchbug;
	int answer;
    mapping itembonuses;

    if(!objectp(wielded)) {
        return;
    }

    if(TO->query_property("funwield")) {
		unwieldf = TO->query_unwield();
		f = (:TO,unwieldf:);
		if ((!"/adm/daemon/shutdown_d"->shuttingDown()) && (query_verb() != "quit") && interactive(ETO)) {
			catchbug=catch(answer=(*f)());
			if (catchbug) write(catchbug);
			if (!answer) return 1;
		} else {
			if (!(*f)()) return 1;
		}
	}

// hijacking stat removal code to here instead. Nienne, 04/08
/*   if((int)TO->query("strbonus")) do_remove_stat(wielded,"strbonus");
   if((int)TO->query("dexbonus")) do_remove_stat(wielded,"dexbonus");
   if((int)TO->query("conbonus")) do_remove_stat(wielded,"conbonus");
   if((int)TO->query("intbonus")) do_remove_stat(wielded,"intbonus");
   if((int)TO->query("wisbonus")) do_remove_stat(wielded,"wisbonus");
   if((int)TO->query("chabonus")) do_remove_stat(wielded,"chabonus");
*/
    // new code for item bonus properties to replace all existing props/funcs. Nienne, 7/12.
    if(itembonuses = TO->query_item_bonuses()) run_item_bonuses("remove",wielded,itembonuses);

    wielded->remove_weapon_from_limb(this_object());
    if(stringp(unwieldf) && !query_property("funwield"))
        message("my_action", unwieldf, wielded);
    else message("my_action", "You unwield "+query_short()+".",
                 wielded);
    message("other_action", (string)wielded->query_cap_name() +
            " unwields "+query_short()+".", environment(wielded),
            ({ wielded}));
    set_not_inhand();
}

void set_not_inhand() {
    wielded = 0;
    limbString = "";
}


int wieldable() {
    return 1;
}

int reaction_to_hit(object target, int damage) {
    return 0;
}

int thrown() {
    return 1;
}

int thrown_hit(object target) {
    return 0;
}

mapping *query_studied_failed(){
   return studied_failed;
}

int is_studied_failed(string name,int level){
   if(!studied_failed || studied_failed == ([])){
      return 0;
   }
   return studied_failed[name];
}

void add_studied_failed(string name, int level) {
    if(!studied_failed) studied_failed = ([]);
    if(!studied_failed[name]) {
        studied_failed[name] = level;
        return;
    }
    studied_failed[name] = level;
}

void remove_studied_failed(string str){
   map_delete(studied_failed,str);
}

string *query_studied(){
   return studied;
}

void add_studied(string str){
   studied += ({str});
   map_delete(studied_failed,str);
}

int is_studied(string name){
   return (member_array(name,query_studied()) != -1);
}

string * query_identified(){
    return identified;
}


void add_identified(string name)
{
    if(!pointerp(identified)) { identified = ({}); }
    identified += ({name});
}

int is_identified(string name){
    return (member_array(name, query_identified()) != -1);
}

void set_lore(string lore){
    set("lore",lore);
}

string query_lore(){
  return (string) query("lore");
}

string query_language(){
    if (!query("language")) {
        return "wizish";
    }
    return query("language");
}

void set_item_owner_prop(string str, int flag)
{
	int which_bit = -1;
	switch(str)
	{
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
	if(which_bit == -1) return;
	switch(flag)
	{
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
	if(!str) return 0;
	//changing this so that the default will be 01000
	//which means the item owner will only clear
	//when an item is being fenced - and only have 1 owner
	//since gear is now kept on pk death
	//this wouldn't benefit someone who is killing
	//bob for his ownered sword of rabbit
	//slaying - maybe change "death_remove" to be
	//strip_remove or something? //Saide
    	if(!item_owner_props) { item_owner_props = "01000"; }

	switch(str)
	{
		case "sale_clear":
			return test_bit(item_owner_props,0);
			break;
		case "fence_clear":
			return test_bit(item_owner_props,6);
			break;
		case "death_remove":
			return test_bit(item_owner_props,12);
			break;
		case "death_clear":
			return test_bit(item_owner_props,18);
			break;
		case "multiple_owners":
			return test_bit(item_owner_props,24);
			break;
		default:
			return 0;
			break;
	}
}

int add_item_owner(string str)
{
	if(!objectp(find_player(str))) return 0;
	if(avatarp(find_player(str))) return 1;
	if(sizeof(item_owners) >= 1 &&
	!query_item_owner_prop("multiple_owners"))
	{
		return 0;
	}
	if(member_array(str, item_owners) == -1)
	{
		item_owners += ({str});
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
	if(!objectp(find_player(str))) return 0;
	if(avatarp(find_player(str))) return 1;
	if(member_array(str, item_owners) != -1)
	{
		return 1;
	}
	return 0;
}

void remove_item_owner(string str)
{
	if(member_array(str, item_owners) != -1)
	{
		item_owners = item_owners - ({str});
	}
}

void clear_item_owners()
{
	item_owners = ({});
}

void add_the_bonus(object myplayer,string bonustype,int bonusvalue) {
	if(!objectp(myplayer)) return;
	if(!stringp(bonustype)) return;
	if(!bonusvalue) return;

	switch(bonustype) {
		// stats
     		case "strength": case "dexterity": case "constitution": case "intelligence": case "wisdom": case "charisma":
			myplayer->add_stat_bonus(bonustype,bonusvalue);
			break;
		// saving throws
		case "fortitude": case "will": case "reflex":
			myplayer->add_saving_bonus(bonustype,bonusvalue);
			break;
		// skills
		case "academics": case "athletics": case "craft, armorsmith": case "craft, jeweller": case "craft, leatherworker":
		case "craft, tailor": case "craft, weaponsmith": case "craft, woodworker": case "disguise": case "dungeoneering":
		case "endurance": case "healing": case "influence": case "perception": case "rope use": case "stealth":
		case "spellcraft": case "survival": case "thievery":
			myplayer->add_skill_bonus(bonustype,bonusvalue);
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
			if(member_array((string)myplayer->query_race(),PLAYER_D->night_races()) != -1) myplayer->add_sight_bonus((-1)*bonusvalue);
			else myplayer->add_sight_bonus(bonusvalue);
			break;
		// misc bonuses held in set_property()
		case "magic resistance": case "spell damage resistance": case "damage resistance": case "spell penetration":
			myplayer->set_property(bonustype,bonusvalue);
			break;
		case "bonus spell slots":
			myplayer->set_property("bonus_spell_slots",bonusvalue);
			break;
		case "caster level":
			myplayer->set_property("empowered",bonusvalue);
			break;
		case "shieldMiss":
			myplayer->set_shieldMiss(bonusvalue);
			break;
// so we have a bunch of extra non-existent types here, I'm going to remove them... N, 8/15.
// and percentages aren't supported in any sourcebooks & don't really work in a d20 system so removing entirely.
/*        case "fire resistance": case "cold resistance": case "water resistance": case "air resistance":
        case "earth resistance": case "bludgeoning resistance": case "piercing resistance": case "slashing resistance":
        case "silver resistance": case "cold iron resistance": case "electricity resistance": case "acid resistance": case "sonic resistance":
        case "positive energy resistance": case "negative energy resistance": case "force resistance": case "divine resistance": case "untyped resistance":
        case "mental resistance": case "light resistance": case "darkness resistance": case "nature resistance":
            myplayer->set_resistance(replace_string(bonustype," resistance",""),bonusvalue);
            break;
        case "fire resistance percent": case "cold resistance percent":
        case "water resistance percent": case "air resistance percent": case "earth resistance percent":
        case "bludgeoning resistance percent": case "piercing resistance percent": case "slashing resistance percent":
        case "silver resistance percent": case "cold iron resistance percent": case "electricity resistance percent": case "acid resistance percent":
        case "sonic resistance percent": case "positive energy resistance percent": case "negative energy resistance percent": case "force resistance percent":
        case "divine resistance percent": case "untyped resistance percent": case "nature resistance percent":
        case "mental resistance percent": case "light resistance percent": case "darkness resistance percent":
            myplayer->set_resistance_percent(replace_string(bonustype," resistance percent",""),bonusvalue);
            break; */
// functional resistance code here!! Contains sourcebook 5x energy types, 3x physical types, 4x divine types, plus untyped. N, 8/15.
        case "fire resistance": case "cold resistance": case "electricity resistance": case "acid resistance": case "sonic resistance":
        case "bludgeoning resistance": case "piercing resistance": case "slashing resistance":
        case "positive energy resistance": case "negative energy resistance": case "force resistance": case "divine resistance": case "untyped resistance":
            myplayer->set_resistance(replace_string(bonustype," resistance",""),bonusvalue);
            break;
	}
}

void run_item_bonuses(string mystatus,object myplayer,mapping itembonuses){
// listing of currently functional bonuses: stats (strength, dexterity, constitution, intelligence, wisdom, charisma),
// magic resistance, spell damage resistance, damage resistance, armor bonus, attack bonus, damage bonus, sight bonus,
// saving throws (will, reflex, fortitude), caster level, bonus spell slots, skills (academics; athletics; craft, armorsmith;
// craft, jeweller; craft, leatherworker; craft, tailor; craft, weaponsmith; craft, woodworker; disguise; dungeoneering;
// endurance; healing; influence; perception; rope use; stealth; spellcraft; survival; thievery); spell penetration; shieldMiss
// adding resistance, and resistance perc -Ares

	int myhighest, i, j, mycurrent, mydifference, mymod;
   	object *myarmors, *myweapons;
      string *mykeys;

	if(!objectp(myplayer)) return;
	if(!objectp(TO)) return;
      if(!mapp(itembonuses)) return;
      if(!stringp(mystatus)) return;
      if(mystatus != "equip" && mystatus != "remove") return;

      mykeys = ({});
      mykeys += keys(itembonuses);
      if(!sizeof(mykeys)) return;

      for(j = 0;j<sizeof(mykeys);j++) {
	   	mymod = itembonuses[mykeys[j]];
   		if(!mymod) continue;

	   	if(mymod < 0) { //negative bonus; always add or remove without a check.
			if(mystatus == "equip") add_the_bonus(myplayer,mykeys[j],itembonuses[mykeys[j]]);
			else add_the_bonus(myplayer,mykeys[j],(-1*(itembonuses[mykeys[j]])));
	   	}

		else { // if positive bonus, check through inven for other of the same bonus, and find the highest
			myarmors = myplayer->all_armour();
		   	myweapons = myplayer->query_wielded();
		   	myhighest = 0;
		   	if(sizeof(myweapons)) {
		     		for(i = 0; i < sizeof(myweapons); i++) {
					//make sure this is a valid object - Saide
					if(!objectp(myweapons[i])) continue;
		       		mycurrent = (int)myweapons[i]->query_item_bonus(mykeys[j]);
       				if((mycurrent > myhighest) && myweapons[i] != TO) myhighest = mycurrent;
     				}
   			}
   			if(sizeof(myarmors)) {
     				for(i = 0; i < sizeof(myarmors); i++) {
					if(!objectp(myarmors[i])) continue;
       				mycurrent = (int)myarmors[i]->query_item_bonus(mykeys[j]);
       				if((mycurrent > myhighest) && myarmors[i] != TO) myhighest = mycurrent;
     				}
   			}

   			// if the mod is the same or less than the highest already equipped, do nothing. If it is greater, modify.
            //changed to continue because this is returning before it loops through the all item bonuses on items
            //with more than one bonus
		   	if(myhighest >= mymod) continue; //return;
		   	mydifference = myhighest - mymod;
//			tell_object(myplayer,"Doing run_item_bonuses with myhighest: "+myhighest+" and mymod: "+mymod+" and mydifference: "+mydifference+".");
            //changing here as well - Saide 7/2/2016
			if(!mydifference) continue; //return;
			if(mystatus == "equip") add_the_bonus(myplayer,mykeys[j],(-1*mydifference));
			else add_the_bonus(myplayer,mykeys[j],mydifference);
		}
	}
}

/*void do_remove_stat(object myplayer, string mystat)
{
	int myhighest, i, mycurrent, mydifference, mymod;
   	object *myarmors, *myweapons;
	//was no check to make sure myplayer is valid
	//I'm thinking wielded above gets cleared at some point
	//and causes this to be an invalid object - Saide
	if(!objectp(myplayer)) return;
	if(!objectp(TO)) return;
	//tell_object(find_player("saide"), "myplayer = "+identify(myplayer));
	//tell_object(find_player("saide"), "TO = "+identify(TO));
   	mymod = (int)TO->query(mystat);
   	if(!mymod) return;
   	if(mymod < 0)
	{ // if negative stat, add directly.
     		switch(mystat)
		{
       		case "strbonus":
				myplayer->add_stat_bonus("strength",(-1)*mymod);
				break;
       		case "dexbonus":
				myplayer->add_stat_bonus("dexterity",(-1)*mymod);
				break;
       		case "conbonus":
				myplayer->add_stat_bonus("constitution",(-1)*mymod);
				break;
       		case "intbonus":
				myplayer->add_stat_bonus("intelligence",(-1)*mymod);
				break;
       		case "wisbonus":
				myplayer->add_stat_bonus("wisdom",(-1)*mymod);
				break;
       		case "chabonus":
				myplayer->add_stat_bonus("charisma",(-1)*mymod);
				break;
       		default:
				tell_object(myplayer,"Your armor has a stat "+
				"bonus error, please inform a wiz.");
     		}
     		return;
   	}
	//Added just to be safe - Saide
	if(!stringp(mystat)) return;

	//tell_object(find_player("saide"), "myplayer = "+identify(myplayer));
	//tell_object(find_player("saide"), "TO = "+identify(TO));
   // if positive, check through inven for other bonuses to same stat, and find the highest
   	//tell_object(find_player("saide"), "mystat = "+mystat);
	myarmors = myplayer->all_armour();
   	myweapons = myplayer->query_wielded();
   	myhighest = 0;
	//tell_object(find_player("saide"), "myarmors = "+identify(myarmors));
	//tell_object(find_player("saide"), "myweapons = "+identify(myweapons));
   	if(sizeof(myweapons))
	{
     		for(i = 0; i < sizeof(myweapons); i++)
		{
			//make sure this is a valid object - Saide
			if(!objectp(myweapons[i])) continue;
       		mycurrent = (int)myweapons[i]->query(mystat);
       		if((mycurrent > myhighest) && myweapons[i] != TO) myhighest = mycurrent;
     		}
   	}
   	if(sizeof(myarmors))
	{
     		for(i = 0; i < sizeof(myarmors); i++)
		{
			//also make sure this is valid - Saide
			if(!objectp(myarmors[i])) continue;
       		mycurrent = (int)myarmors[i]->query(mystat);
       		if((mycurrent > myhighest) && myarmors[i] != TO) myhighest = mycurrent;
     		}
   	}

   	// if the mod is the same or less than the highest worn, do nothing.
	//If it is greater, modify.
   	if(myhighest >= mymod) return;
   	mydifference = myhighest - mymod;
   	switch(mystat)
	{
     		case "strbonus":
			myplayer->add_stat_bonus("strength",mydifference);
			break;
     		case "dexbonus":
			myplayer->add_stat_bonus("dexterity",mydifference);
			break;
     		case "conbonus":
			myplayer->add_stat_bonus("constitution",mydifference);
			break;
     		case "intbonus":
			myplayer->add_stat_bonus("intelligence",mydifference);
			break;
     		case "wisbonus":
			myplayer->add_stat_bonus("wisdom",mydifference);
			break;
     		case "chabonus": myplayer->add_stat_bonus("charisma",mydifference);
			break;
     		default:
			tell_object(myplayer,"Your armor has a stat bonus error, "+
			"please inform a wiz.");
   	}
} */


//Added for support of items that have special circumstances around
//their adding of bonuses - Saide
int BonusCheck(string BonusName) { return 1; }

function get_obfunc(string str) { return (: TO,str :); }

//new functionality to replace old stat bonuses with all magical bonuses
void set_item_bonus(string bonustype,int thebonus) {
   if(!item_bonuses) item_bonuses = ([]);
   item_bonuses[bonustype] = thebonus;
}

int query_item_bonus(string bonustype) {
   if(!item_bonuses) item_bonuses = ([]);
   if(!item_bonuses[bonustype]) return 0;
   return item_bonuses[bonustype];
}

void clear_item_bonus() { item_bonuses = ([]); }


mapping query_item_bonuses() {
   if(!item_bonuses) item_bonuses = ([]);
   return item_bonuses;
}
