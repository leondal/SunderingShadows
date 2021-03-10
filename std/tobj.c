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

// std contains the def of MOVE
#include <std.h>
#include <security.h>
// daemons contains the #define of ALCHEMIST_D
#include <daemons.h>

// move contains the functions "move", "remove", "clean_up", "set_no_clean"
//   "set_last_location", "query_last_location", "set_weight", "query_weight"
inherit MOVE;

//    Global variables defined in this file
//   =======================================
mapping props;                    // Object data that does get saved.
private string serial_number;
private mapping ob_data;   // Object data that does not get saved.
private string cap_name;   // kept in seperate variable for security
private string true_name;         // kept in seperate variable for security
private string creator;           // File name of the ob that created an object
nosave string d_master;           // File name of an object's domain master ob
string material;                  // Substance object is made from.
string *magic_properties;  //  Allows all objects to have magic properties
mapping set_trap_func, trap_set, trap_trigger, trap_ref;  //these will contain the informantion require to run traps

//hiding things..
nosave int hidden, magic_hidden;

// To allow this item to use the unique item system
// Thorn@ShadowGate - 27 June 2000
int unique_item;
int unique_lease = 0;


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

mapping query_traps();
mapping query_traps();
int query_trap_status(string trap_loc);
int toggle_trap(string trap_loc);
void set_trap_functions(string *what, string *funcs, string *trigger);
int temp_find_trap(string str);
int temp_remove_trap(string str);

// To allow this item to use the unique item system
// Thorn@ShadowGate - 27 June 2000
int unique_item;
int unique_lease = 0;

int save_me(string fname) {
  int x;
  seteuid(UID_RESTORE);
  catch(save_object(fname, 1));
  return x;
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

void init_ob() { ob_data = ([ "id": ({}) ]); }

void set(string what, mixed arg) {
    if( !stringp(what) ) return;
    if(functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) return;
    if(!ob_data) init_ob();
   if(what == "aggressive") TO->set_property("swarm",1);
    if(ob_data[what]) ob_data[what] = arg;
    else ob_data += ([ what: arg ]);
    if(what == "value") {
      what = "cointype";
      if(ob_data[what]) ob_data[what] = "gold";
      else ob_data += ([ what: "gold" ]);
    }
}

protected void add(string what, mixed arg) {
    if(!ob_data) ob_data = ([]);
    if(functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) return;
    if(stringp(arg) || intp(arg)) arg = ({ arg });
    if(!ob_data[what]) {
	ob_data += ([what:arg]);
	return;
    }
    if(!pointerp(ob_data[what]) && !mapp(ob_data[what])) return;
    ob_data[what] += arg;
}

varargs mixed query(string what, mixed element) {
    mixed res;

    res = 0;
    if(!ob_data) init_ob();
    if(!stringp(what)) return 0;
    if(!ob_data[what]) return 0;
    if(!element) res = ob_data[what];
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

void set_property(string prop, mixed value) {

	if(pointerp(value)){
		if(!props) props = ([]);
    	if(!props[prop] || !pointerp(props[prop])) props[prop] = ({});
      	props[prop] += value;
    	return;
    } else {
    	if(!props) props = ([]);
    	if(!props[prop]) props[prop] = value;
    	else
    		if(props[prop]) {
        		props[prop] += value;
        		return;
    		}
    	props += ([ prop : value]);
    }
}

mixed query_property(string prop) {
    if(!props)
    {
        props = ([]);
        return 0;
    }
    return props[prop];
}

int is_cursed(){
       return query_property("enchantment") && query_property("enchantment") < 0;
}
void remove_all_properties() {
    props = ([]);
}

int remove_property (string prop)
{
    if(props && props[prop])
    {
        props[prop] = 0;
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

string * regexp_query_property (string pattern)
{
   string *vars, *prop;

   vars = keys(props);
   prop = regexp (vars, pattern);
   if (!prop)
        prop = ({});
   return prop;
}





// *** One line set and query functions ***
void   set_id(string str)        { set("id", str); }
void   set_short(string str)     { set("short", str); }
void   set_long(string str)      { set("long", str); }
void   add_id(string str)        { add("id",str);}
void   set_value(int x)          {
 set("value", x);
 if(!query("cointype")) {
   set("cointype","gold");
 }
}
void   set_cointype(string str)  { set("cointype",str); }
string *query_id()               { return query("id"); }
string query_name()              { return true_name; }
string query_true_name()         { return true_name; }
string query_long(string str) {
    if(functionp(ob_data["long"]))
      return (string)(*ob_data["long"])(str);
    else return ob_data["long"];
}
int    query_value()             { return (int)this_object()->query("value"); }

string query_cointype()          { return (string)this_object()->query("cointype"); }
int    query_destroy()           { return ob_data["destroy"]; }
string query_creator()           { return creator; }





// *** More complicated set and query functions ***

int id(string str) {
    int i;

    string *parts;

    if(!ob_data) init_ob();
    if( !stringp(str) ) return 0;
    if( lower_case(str) == true_name) return 1;
    if(member_array(str, ob_data["id"]) != -1) return 1;
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

string query_short() {
    if(!ob_data) init_ob();
   if(!living(TO) && this_object()->query_invis()) return 0;
    if(functionp(ob_data["short"]))
      return (string)(*ob_data["short"])();
    else return ob_data["short"];
}

string query_eng_short() {
  string str,s1,s2;
  if(!ob_data) init_ob();
  if(this_object()->query_invsi()) return 0;
  if(functionp(ob_data["short"]))
      str = (string)(*ob_data["short"])();
  else str = ob_data["short"];
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

int query_light() {
    if(!props) return 0;
    if(props["light"]) return props["light"];
    return 0;
}

void set_destroy() {
    if(!ob_data) ob_data = ([]);
    ob_data["destroy"] = 1;
}

void set_hidden(int xxx){
   hidden = xxx;
}

void set_magic_hidden(int xxx){
   magic_hidden = xxx;
}

int query_hidden() {
   return hidden;
}


int query_magic_hidden(){
   return magic_hidden;
}

int is_detectable(){
   return 1;
}

mixed prop( string str )
{
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

void set_material( string str )
{
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
  if( d_master )
  {
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





int __Read(string str) {
    if(!str) return notify_fail("Read what?\n");
    if(!ob_data || !ob_data["read"])
      return notify_fail(living(this_object()) ? "Read a living thing?\n" :
        "There is nothing on it to read.\n");
    if(functionp(ob_data["read"]))
      return (int)(*ob_data["read"])(str);
    else if(stringp(ob_data["read"])) {
        if(!id(str)) return notify_fail("You do not notice that here.\n");
        message("info", ob_data["read"], this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " reads the "+query_name()+".", environment(this_player()),
          ({ this_player() }));
        return 1;
    }
    else return notify_fail("It looks all jumbled.\n");
}


void reset()
{
    // do temperature
}

void create() {
    seteuid( getuid() ); // ensures all objects have an euid.

    // Once all objects call ::create(), many of the checks that
    // ob_data and props exist can be removed, saving on cpu.
   ob_data = (["id": ({}), "condition":100]);
    props = ([]);
    if(previous_object()) creator = file_name(previous_object());
    else creator = "Unknown";

  	reset();
}

void init() {
	string *actions;
	int i,j;

    // If this item is unique and someone else has it, then
    // remove it.
    // Thorn@ShadowGate - 27 June 2000
    if(unique_item == 1) {
        if(!UNIQUE_D->ok_to_clone(TO->query_unique_id(), ETO)) {
            tell_object(find_player("thorn"), "You can't use this item.\n");
            TO->move("/d/shadowgate/void");
            TO->remove();
            return;
        }
        if(userp(ETO)) {
            UNIQUE_D->issue_lease(
                TO->query_unique_id(),ETO->query_name(),unique_lease);
            tell_object(find_player("thorn"), "Lease issued.\n");
        }

        else {
            UNIQUE_D->clear_lease(TO->query_unique_id());
            tell_object(find_player("thorn"), "Lease cleared.\n");
        }
    }

    add_action("__Read", "read");
    add_action("temp_find_trap","find");
    add_action("temp_remove_trap","remove");
    if(trap_trigger && trap_trigger != ([])){
   	 	actions = keys(trap_trigger);
    	j = sizeof(actions);
    	if(j){
    		for(i = 0;i<j;i++){
    			if(TO->is_room() && member_array(actions[i],(string *)TO->query_exits()) != -1)
    				continue;
    			if(member_array(actions[i], ({"pick","unlock","open","close"})) != -1 && TO->is_container())
    				continue;
    			add_action("do_trap",actions[i]);
    		}
    	}
    }
}


int move(mixed dest) {
    this_object()->unequip();
    // If this item is moved, clear the lease on it to allow
    // the destination to possess it.
    // Thorn@ShadowGate - 28 June 2000
    if(unique_item == 1) {
      UNIQUE_D->clear_lease(TO->query_unique_id());
      tell_object(find_player("thorn"), "Lease cleared in move().\n");
    }
    return ::move(dest);
}

int drop() {
	if(query_property("monsterweapon"))
		return 1;
    // If this item is dropped, clear the lease on it to allow
    // the destination to possess it.
    // Thorn@ShadowGate - 28 June 2000
    if(unique_item == 1) {
      UNIQUE_D->clear_lease(TO->query_unique_id());
      tell_object(find_player("thorn"), "Lease cleared in drop().\n");
    }
	return 0;
}

int get() {
    string who;

  if(this_object()->query_property("monsterweapon")) return 0;
    who = (string)this_object()->query_property("keep");
    if(!who) return 1;
    if(who != (string)this_player()->query_name()) {
        write("A magical force prevents you from taking it!\n");
        say("A magical force prevents "+(string)this_player()->query_cap_name()+
            " from taking the "+query_name()+".\n", this_player());
	return 0;
    }

    if(TO->trapped("get"))
    	return TO->do_special_trap("get");
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
		temp += ({ magic_properties[x] });
	}
	return temp;
}

string get_serial_number() {
  serial_number = "SG"+time();
  return serial_number;
}

string query_serial_number() { return serial_number; }

void clear_all_traps(string *action){
	//special for blanket clearing of all traps
	//if action is empty ({}) will clear for all members if otherwise

	int num, j;

	if(!(num = sizeof(action))) {
		trap_trigger = ([]);
		set_trap_func = ([]);
		return;
	}
	for(j=0;j<num;j++){
		trap_trigger[action[j]] = 0;
	}
	return;
}

void set_trap_functions(string *what, string *funcs, string *trigger){
    int i,num;
	if(!trap_set) trap_set = ([]);
	if(!trap_trigger) trap_trigger = ([]);
	if(!trap_ref) trap_ref = ([]);
    if(!what || !funcs || (sizeof(what) != sizeof(funcs))) return;
 	if(!set_trap_func) set_trap_func = ([]);
   	num= sizeof(what);
   	while(num--) {
	  	set_trap_func[what[num]] = funcs[num];
	  	trap_set[funcs[num]] = 1;
     	trap_trigger[trigger[num]] = funcs[num];
	}
}

int toggle_trap(string trap_loc){
   if(!set_trap_func || !set_trap_func[trap_loc]) return 0;
   if(!trap_set[set_trap_func[trap_loc]]){
     trap_set[set_trap_func[trap_loc]] = 1;
     return 1;
   }
   if(trap_set[set_trap_func[trap_loc]] == 1){
     trap_set[set_trap_func[trap_loc]] = 0;
     return 1;
   }
   if(trap_set[set_trap_func[trap_loc]] == 0){
     trap_set[set_trap_func[trap_loc]] = 1;
     return 1;
   }
}

int query_trap_status(string trap_loc){
  if(!set_trap_func) set_trap_func = ([]);
  if(!trap_set) trap_set = ([]);
  if(!trap_set[set_trap_func[trap_loc]]) return 0;
  return trap_set[set_trap_func[trap_loc]];
}

mapping query_traps() { return trap_trigger;}

mapping query_trapped() {return set_trap_func;}

int trapped(string action){
	if(!trap_trigger || trap_trigger == ([]) ) return 0;
	if(trap_set[trap_trigger[action]])
		return trap_set[trap_trigger[action]];
	return 0;
}

int do_trap(string str){
	string verb;


	verb = query_verb();
	if(!trap_set[trap_trigger[verb]]) return 0;
	if(trap_trigger[verb]);
		return call_other(TO,trap_trigger[verb],str);
	return 0;
}

int do_spec_trap(string verb){
	mapping traps;

	traps = query_traps();

	if(!traps || traps == ([]) || !traps[verb]) return 0;
	return call_other(TO,traps[verb]);
}

int temp_find_trap(string str){
  	int num;
  	string what;
  	if(!str) return 0;

  	if(sscanf(str,"traps in %s",what)!=1) return 0;
	if(!TO->is_room())
		if(!id(what)) return 0;
	if(!trap_trigger || trap_trigger == ([])) return 0;
  	num = "/daemon/trap_d.c"->find_func(set_trap_func,TO,TP,what);
  	return num;
}

int temp_remove_trap(string str){
        int num;
	string what;
	if(!str) return 0;

	if(sscanf(str,"traps in %s",what)!=1) return 0;
	if(!TO->is_room())
		if(!id(what)) return 0;
	if(!trap_trigger || trap_trigger == ([])) return 0;
    num = "/daemon/trap_d.c"->remove_trap(set_trap_func,TO,TP,what);
    return num;
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
int query_unique() { return unique_item; }

// Sets this object's unique_id.
// Thorn@ShadowGate - 27 June 2000
string query_unique_id() { return base_name(TO)+".c"; }

/* EOF */
