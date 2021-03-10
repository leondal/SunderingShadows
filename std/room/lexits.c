
//      /std/room/exits.c
//      from the Nightmare Mudlib
//      functions handling room exits
//      created by Descartes of Borg 18 june 1993

#include <rooms.h>
#include <daemons.h>
#include <std.h>
#define SIZE 20


inherit "/std/room/terrain";
int skip_obvious;
private mapping destinations;
private mapping invis_exits;
private mapping pre_exit_func;
private mapping post_exit_func;
private mapping blockedExits;
private string stupid;
private mapping climb_exits;
string fall_desc;
int invis_exit(string str);
int object_pre_exits(verb);
string *footprints;
//For buried exits
mapping orig_exits, buried;

int climb_ok(string verb);
void add_exit(string dest, string dir);
object query_blocked(string exit);
//For buried exits
void collapse_exit(string str, int collapse_amount);
void collapse_all_exits(int collapse_amount);
int dig_exit(string ext, int amount);
void set_buried_exit(string ext, int collapse_amount);
void open_buried_exit(string ext);
int add_digging(string ext, int amount);
int query_buried_amount(string ext);
//mixed *query_buried_exits();
//mixed *query_orig_exits();


#define MAX_TRACKS 3

#define NUMBER   ({ "two", "three", "four", "five", "six", "seven", "eight",\
                  "nine", "ten", "many" })

#define TMPLONG  ({ "north", "northeast", "east", "southeast", "south",\
                  "southwest", "west", "northwest", "up", "down", "in",\
                  "out", "enter","exit",})

#define TMPSHORT ({ "n", "ne", "e", "se", "s", "sw", "w", "nw", "u", "d",\
                  "in","out", "enter","exit",})

#define CLIMB ({"climb","descend"})


void create() {
    destinations = ([]);
    invis_exits = ([]);
    pre_exit_func = ([]);
    post_exit_func = ([]);
    climb_exits = ([]);
    //buried exits
    buried = ([]);
    orig_exits = ([]);
    footprints = allocate(SIZE);
    skip_obvious = 0;
}

// exitName:({"destination",dc-check,damageper fall, height})
//dc-check to match intended player level, damage is per fall, height is multiple of 100, each 100 takes a check.
void set_climb_exits(mixed dests) {
    if (mapp(dests))
    {
        //so we can clear climb_exits intentionally - Saide
        if(!sizeof(keys(dests)))
        {
            if(mapp(climb_exits))
            {
                if(sizeof(keys(climb_exits)))
                {
                    climb_exits = ([]);
                    TO->reinitiate();
                }
            }
            else climb_exits = ([]);
        }
        else
        {
            climb_exits = dests;
            TO->reinitiate();
        }
    }

}

mixed query_climb_exit(string str,int test) {
    if (str && climb_exits && climb_exits[str]) {
        if (test == 3) return climb_exits[str][3];
        else if (test == 2) return climb_exits[str][2];
        else if (test == 1) return climb_exits[str][1];
        else return climb_exits[str][0];
    } else return ROOM_VOID;
}

string query_exit(string str) {
    if (str && destinations && destinations[str]) return destinations[str];
    else return ROOM_VOID;
}

string query_direction(string str) {
    int i;

    if (str && destinations &&
        (i=member_array(str, values(destinations))) != -1)
        return keys(destinations)[i];
    else return ROOM_VOID;
}

void perform_post_exits(string str) {
    if (!str || !post_exit_func || !post_exit_func[str]) return;
    call_other(this_object(), post_exit_func[str]);
}

int perform_pre_exits(string str) {
    if (!str || !pre_exit_func || !pre_exit_func[str]) return 1;
    return(int)call_other(this_object(), pre_exit_func[str]);
}

int object_pre_exits(string str){
  object * obs;
  int i, count;
  obs = ({});
  if (objectp(TP)){
    obs = all_inventory(TP);
  }
  count = sizeof(obs);
  if (count<1) return 1;
  for (i=0;i<count;i++){
    if (obs[i]->pre_exit_fun(str)){
      return 0;
    }
  }
  return 1;
}

void add_tracks(object ob, string action, string direction)
{
    int i,j;
    string tmp,*feats;
    object shape;
	if(!objectp(ob)) return;
    if (!pointerp(footprints)) footprints = allocate(SIZE);
    if (ob->id("summoned monster")) return;
// adding to exclude true invis. immortals by *Styx* 9/24/03, last change was 8/2/03
    if (ob->query_true_invis()) return;
    if ((int)ob->query_property("untrackable")) return;
    if (FEATS_D->usable_feat(ob,"tracklessstep") && !FEATS_D->is_active(ob,"tracklessstep")) return;
    if (!stringp(ob->query_race())) return;
    for (i = SIZE-1;i>0;i--) {
        tmp = footprints[i-1];
        footprints[i] = tmp;
    }

    if(objectp(shape = ob->query_property("shapeshifted")))
    {
        footprints[0]=(string)shape->query_shape_race()+"&"+action+"&"+direction;
    }
    else
    {
        footprints[0]=(string)ob->query_race()+"&"+action+"&"+direction;
    }
}

string *query_tracks() {
    return footprints;
}

void wipe_prints() {
    footprints = allocate(SIZE);
}

int blocked(string exit) {
    int out, deny;
    object ob;
    if (!objectp(ob = query_blocked(exit))) return 0;
    if (query_blocked(exit) == TP) {
        map_delete(blockedExits,exit);
        return 0;
    }
    if (ob->query_paralyzed()) return 0;
    out = TP->query_highest_level();
    out += (int)TP->query_size()*5;
    out += (int)TP->query_stats("strength");
    out += (int)TP->query_stats("dexterity")*2;
    deny = ob->query_highest_level();
    deny += (int)ob->query_size()*5;
    deny += (int)ob->query_stats("strength")*2;
    deny += (int)ob->query_stats("dexterity");
    if (ob->query_invis())
        out = out/2;
    if (TP->query_invis())
        deny = deny/2;
    if (random(deny) >= random(out)) {
        write("You are blocked to the ground by "+ob->query_cap_name()+".");
        tell_room(TO,TPQCN+" is blocked to the ground by "+ob->query_cap_name()+".", ({TP,ob}));
        tell_object(ob,"You block "+TPQCN+" knocking "+TP->query_objective()+" to the ground.");
        TP->set_paralyzed(4,"You are getting up.");
        return 1;
    }
    return 0;
}

int use_exit()
{
    string verb,paths;
    string *tmpstrs;
    object incoming,effect,obj;
    int val,stmp, flee_delay;

    if (!objectp(TP)) return 1;
    if (this_player()->query_paralyzed() || TP->query_bound() || TP->query_tripped() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return notify_fail("");
    }

    if ( this_player()->query_disable()  ) {
        write("You can not exit while doing something else.");
        return 1;
    }

    if ((int)TP->query_condition_percent() < 1) {
        return notify_fail("You are too tired to go on. (This is temperary, ultimately you will pass out at this stage. Think about how you move and comment on it to the wizes.)\n");
    }

    if (!(verb = query_verb())) return 0;


    if ((paths = query_exit(verb)) == ROOM_VOID)
        if ((paths = query_climb_exit(verb,0)) == ROOM_VOID) {
            write("Error:  Set to VOID.  Notify creator of room.");
            return 1;
        }

    if (blocked(verb)) {
        return 1;
    }
    if (sizeof(TP->query_attackers()) &&  verb != (string)TP->query_property("true moving"))
    {
        flee_delay = random(2) + 2;
        effect = new("/std/room/exiteffect");
        effect->set_tp(TP);
        effect->set_dir(verb);
        effect->set_env(TO);

        if(TP->is_player())
        {
            if(TP->query_property("my_exiteffect"))
            {
                TO->removeObjectFromCombatCycle((object)TP->query_property("my_exiteffect"));
                obj = (object)TP->query_property("my_exiteffect");
                TP->remove_property("my_exiteffect");
                if(objectp(obj))
                {
                    flee_delay += ((int)obj->query_delay()/2);
                    obj->remove();
                }
            }
            effect->set_delay(flee_delay);
            TP->set_property("my_exiteffect",effect);
            TP->remove_property("running_away_time");
            TP->set_property("running_away_time",time() + random(2) + 2);
            TO->addObjectToCombatCycle(effect,(int)effect->query_delay(), 1);
        }
        else
        {
            TO->addObjectToCombatCycle(effect,random(3)+1, 1);
        }
        tell_room(TO,"%^BOLD%^"+TPQCN+" makes a run for the "+verb+" exit.",TP);
        tell_object(TP,"%^BOLD%^You make a run for the "+verb+" exit.");
        return 1;
    }

    if (!object_pre_exits(verb)) return 1;

    if (!perform_pre_exits(verb)) return 1;

    if ((verb == "climb") || (verb == "descend"))
        if (!climb_ok(verb))
            return 1;
	//leaving this in until I get the rest of the lib
	//updated to support new traps - Saide
    	if (TO->trapped(verb))
        if (TO->do_spec_trap(verb)) return 1;
	if(TO->is_trapped(verb))
	{
		if(TO->execute_trap(verb, TP)) return 1;
	}

    if (TP->query_blind() && !random(20) && !FEATS_D->usable_feat(TO,"blindfight")) {
        write("You stumble over something in your path.");
        TP->set_tripped(1,"You are getting back to your feet.");
        return 1;
    }

    if (!objectp(TP)) return 1;

      TP->pre_exit_func();
    this_player()->move_player(paths, verb);
//    if((objectp(TP)) && (!wizardp(TP))) {
    if (objectp(TP)) {
        incoming = TP;
        if (TP->query_in_vehicle()) {
            incoming = TP->query_in_vehicle();
            stmp = query_stamina_usage();
            if(TP->query_property("endurance"))
            {
                stmp = stmp - (int)TP->query_property("endurance");
                if(stmp < 0) { stmp = 0; }
            }
            TP->use_stamina(stmp);
        } else {
            stmp = query_stamina_usage() + 1;
            if(TP->query_property("endurance"))
            {
                stmp = stmp - (int)TP->query_property("endurance");
                if(stmp < 0) { stmp = 0; }
            }
            TP->use_stamina(stmp);
        }
        add_tracks(incoming,"left",verb);
    }
    if(!objectp(TP)) { return 1; }
      TP->post_exit_func();

/*
    if(TP->query_in_vehicle()) {
        TP->use_stamina();
    }
    else {
        TP->use_stamina(2);
    }
*/
    if (TP->query_property("fled") > time())
          TP->set_property("fled",time()+210);
    if (intp(TP->query_property("PKfled")) && (TP->query_property("PKFled") > time()) ) {
       TP->remove_property("PKFled");
      TP->set_property("PKFled",time()+TP->query_property("PKfled_delay")+20);
      }
    perform_post_exits(verb);
    return 1;
}

void setupExits()
{
    string *borg;
    int i;
    i = sizeof(CLIMB);
    while (i--) add_action("use_stupid_exit",CLIMB[i]);
    if (climb_exits)
	{
    	i = sizeof(borg = keys(climb_exits));
        while (i--) add_action("use_exit", borg[i]);
    }
    i = sizeof(TMPLONG);
    while (i--) add_action("use_stupid_exit", TMPLONG[i]);
    if (!destinations) return;
    i = sizeof(borg = keys(destinations));
    while (i--) add_action("use_exit", borg[i]);

}

protected void initiate()
{
    object ob,incoming;
    string *borg,verb, tmp;
    int i;
    setupExits();
    if (!objectp(TP)) return;
	if(!objectp(TO)) return;
    if (TP->query_true_invis())  return;
    verb = query_verb();
    if (!objectp(TP)) return;
    ob = TP->query_last_location();
    if (TP->is_animal()) return;

    incoming = TP;
    if (TP->query_in_vehicle())
	{
        incoming = TP->query_in_vehicle();
	}
	if(!objectp(incoming)) return;

    //I'm going try it this way and see what breaks... err happens :P
    //Property is set when you sneak successfully - Saide

    if(TP->query_property("sneaking_from"))
	{
        tmp = TP->query_property("sneaking_from");
        TP->remove_property("sneaking_from");
        tmp = query_direction(tmp);
        if(tmp != ROOM_VOID)
		{
            add_tracks(incoming,"entered",tmp);
        	return;
        }
    }

    //Debug msgs below - trying to figure out what exactly
    //happens here when I sneak and it turns out... well, all
    //of them happen sometimes.... Saide

    if (!objectp(ob))
	{
        add_tracks(incoming,"appeared",0);
        return;
    }
    if (!destinations) {
        add_tracks(incoming,"appeared",0);
        return;
    }
    borg = values(destinations);
    if (member_array(base_name(ob),borg) == -1 && member_array(base_name(ob)+".c",borg) == -1) {
        add_tracks(incoming,"appeared",0);
        return;
    }
    borg = ob->query_exits();
    if (member_array(verb,borg) == -1) {
        add_tracks(incoming,"appeared",0);
        return;
    }
    borg = ob->query_destinations();
    if (member_array(base_name(TO),borg) == -1 && member_array(base_name(TO)+".c",borg) == -1) {
        add_tracks(incoming,"entered","unknown");
        return;
    }
    verb = 0;
    verb = query_direction(base_name(ob));
    if (verb == ROOM_VOID) {
        verb = query_direction(base_name(ob)+".c");
    }
    if (verb == ROOM_VOID)
        verb = "unknown";
    add_tracks(incoming,"entered",verb);
}

varargs void set_exits(mixed dests, string *dirs)
{
    int i;
    string result,where,how;

    if (mapp(dests))
    {
        destinations = ([]);
        destinations = dests;
        if (!result = "daemon/room_d"->query_new_dest(base_name(TO)))
            if (!result = "daemon/room_d"->query_new_dest(base_name(TO)+".c")) {
                TO->reinitiate();
                return;
            }
        sscanf(result,"%s&%s",where,how);
        add_exit(where,how);
        return;
    }
    if (!dests || !dirs || ((i = sizeof(dests)) != sizeof(dirs))) return;
    destinations = ([]);
    while (i--) destinations[dirs[i]] = dests[i];
    if (!result = "daemon/room_d"->query_new_dest(base_name(TO)))
        if (!result = "daemon/room_d"->query_new_dest(base_name(TO)+".c"))
            return;
    sscanf(result,"%s&%s",where,how);
    add_exit(where,how);
}


void add_exit(string dest, string dir)
{
    if (!dest || !dir) return;
    if (!destinations) destinations = ([]);
    destinations[dir] = dest;
    this_object()->reinitiate();
	//Adding check for traps here - Saide
}

void clear_exits()
{
    destinations = ([]);
    TO->reinitiate();
}

void remove_exit(string dir)
{
    if (!dir || !destinations || !destinations[dir]) return;
    map_delete(destinations, dir);
    this_object()->reinitiate();
}

string *query_exits() {
    return(destinations ? keys(destinations) : ({}));
}

string query_full_direction(string str) {
    int i;

    if ((i=member_array(str, TMPSHORT)) == -1) return str;
    else return TMPLONG[i];
}

string *query_destinations() {
    return(destinations ? values(destinations) : ({}));
}

string *query_obvious_exits() {
    string *exits, *sorties;
    int i;

    if (!destinations) return({});
    else i = sizeof(sorties = keys(destinations));
    exits = ({});
    while (i--)
        if (!invis_exit(sorties[i])) exits += ({ sorties[i]});
    return(exits);
}

mixed query_exits_string(int hidden)
{
	int x, max;
	string *sorties;
	string str = "";
	if(!destinations) return 0;
	if(hidden)
	{
		sorties = query_exits();
	}
	else
	{
		sorties = query_obvious_exits();
	}
	if(!(max = sizeof(sorties))) return 0;
	if(max == 1) return TO->get_trap_room_auto_detect(sorties[0], TP, 0) + ".";
	for(x = 0;x < max;x++)
	{
		if(x == max-1) str += "and ";
		str += TO->get_trap_room_auto_detect(sorties[x], TP, 0);
		if(x == max-1) str += ".";
		else if(x >= 0 && max > 2) str += ", ";
		else str += " ";
	}
	return str;
}

string query_long_exits() {
    int i, max;
    string str;
    string *sorties;

    if (skip_obvious) return "";
    if (!(i=sizeof(sorties = query_obvious_exits())))
        return "There are no obvious exits.";
    if (i==1)
        return "The only obvious exit is: "+TO->get_trap_room_auto_detect(sorties[0], TP, 0)+".";
    if ((max=i) > sizeof(NUMBER) + 1) max = sizeof(NUMBER)+1;
    str = ("There are " + NUMBER[max - 2] + " obvious exits: ");
    for (max = i, i = 0; i<max; i++) {
        if (i == max-1) str += "and ";
        str += TO->get_trap_room_auto_detect(sorties[i], TP, 0);
        if (i == max -1) str += ".";
        else if (max > 2) str += ", ";
        else str += " ";
    }
    return str;
}

string query_short_exits() {
    int i, x, max;
    string s;
    string *lx, *sx;

    s = "";
    sx = allocate(max = sizeof(lx = query_obvious_exits()));
    for (x=0; x< max; x++) {
        if ( (i=member_array(lx[x], TMPLONG)) != -1)
            sx[x] = TMPSHORT[i];
        else sx[x] = lx[x];
    }
    if (!sizeof(sx)) return "[no exits]";
    if (max == 1) return "[1: "+sx[0]+"]";
    s = ("[" + max + ": ");
    for (x=0; x<max; x++) {
        if (x) s += ", ";
        s += sx[x];
    }
    return s + "]";
}

protected void set_post_exit_functions(string *dirs, string *funcs) {
    int i;

    if (!dirs || !funcs || ((i=sizeof(dirs)) != sizeof(funcs))) return;
    post_exit_func = ([]);
    while (i--) post_exit_func[dirs[i]] = funcs[i];
}

protected void add_post_exit_function(string dir, string func) {
    if (!post_exit_func) post_exit_func = ([]);
    post_exit_func[dir] = func;
    this_object()->reinitiate();
}

protected void remove_post_exit_function(string dir) {
    if (!dir || !post_exit_func || !post_exit_func[dir]) return;
    map_delete(post_exit_func, dir);
    this_object()->reinitiate();
}

protected void set_pre_exit_functions(string *dirs, string *funcs) {
    int i;

    if (!dirs || ! funcs || (sizeof(dirs) != sizeof(funcs))) return;
    if (!pre_exit_func) pre_exit_func = ([]);
    i = sizeof(dirs);
    while (i--) pre_exit_func[dirs[i]] = funcs[i];
}

protected void add_pre_exit_function(string dir, string func) {
    if (!dir || !func) return;
    if (!pre_exit_func) pre_exit_func = ([]);
    pre_exit_func[dir] = func;
    this_object()->reinitiate();
}

protected void remove_pre_exit_function(string dir) {
    if (!pre_exit_func || !pre_exit_func[dir]) return;
    map_delete(pre_exit_func, dir);
    this_object()->reinitiate();
}

void set_invis_exits(string *dirs) {
    int i;

    invis_exits = ([]);
    i = sizeof(dirs);
    while (i--) invis_exits[dirs[i]] = 1;
}

void add_invis_exit(string dir) {
    if (!invis_exits) invis_exits = ([]);
    invis_exits[dir] = 1;
}

void remove_invis_exit(string dir) {
    if (!invis_exits) return;
    if (!invis_exits[dir]) return;
    map_delete(invis_exits, dir);
}

int invis_exit(string dir) {
    if (!invis_exits) return 0;
    else return invis_exits[dir];
}

void skip_obvious() {
    skip_obvious = 1;
}

set_stupid_exit(string str) {
    stupid = str;
}

int use_stupid_exit() {
    if (stupid)
        write(stupid);
    else
        write("You cannot go that way.\n");
    return 1;
}

string *query_pre_exit_functions() {
    if (pre_exit_func) return keys(pre_exit_func);
    else return({});
}

string query_pre_exit_function(string sortie) {
    if (!pre_exit_func) return 0;
    else return pre_exit_func[sortie];
}

string *query_post_exit_functions() {
    if (!post_exit_func) return({});
    else return keys(post_exit_func);
}

string query_post_exit_function(string sortie) {
    if (!post_exit_func) return 0;
    else return post_exit_func[sortie];
}

int climb_ok(string verb) {
    int success,damage,inc,inc2,loop;
    string dir,opp;
/*  removing until T agrees and we make it reasonable to have this restriction
// adding to preclude climbing climb exits if mounted
    if (TP->query_in_vehicle()) {
	write("You aren't going to be able to do that while mounted.");
        return 0;
    }
*/
/*    if (!TP->is_class("thief") && !TP->is_class("assassin") && !TP->is_class("bard") &&
        (!present("climbing tool",this_player())) ) {
        write("Only thieves and bards can climb, un-aided.");
        return 0;
    } */
    if (verb == "climb") {
        dir = "up"; opp = "down";
    } else {
        dir = "down"; opp = "up";
    }
    loop = climb_exits[verb][3] / 100;
    if (loop  <= 0 ) loop = 1;
    tell_room(this_object(),this_player()->query_cap_name()+" attempts to "+verb+" "+dir+".",this_player());
    for (inc = 0; inc < loop; inc ++) {
        success = CLIMB_D->check_climb(climb_exits[verb][1],this_player());
        if (success == -1) {
            tell_room(this_object(),this_player()->query_cap_name()+" falls.",this_player());
            write("You have fallen!!");
            if (fall_desc) write(fall_desc);
            damage = 0;
            for (inc2 = loop;inc2 > inc; inc2 --)
                damage += random(climb_exits[verb][2]);
            damage += random(climb_exits[verb][2]) + 1;
            this_player()->cause_typed_damage(this_player(), this_player()->return_target_limb(), damage, "bludgeoning");
            this_player()->add_attacker(this_object());
            this_player()->continue_attack();
            this_player()->remove_attacker(this_object());
            if (verb == "climb") return 0;
            else return 1;
        }
        if (success == 0) {
            if (inc < 1) {
                tell_room(this_object(),this_player()->query_cap_name()+" fails to "+verb+" "+dir+".",this_player());
                write("You can't even get started!");
            } else {
                tell_room(this_object(),this_player()->query_cap_name()+" gets part way "+dir+", and gets stuck, so "+nominative(this_player())+" climbs back "+opp+".",this_player());
                write("You get "+dir+" part way, and get stuck, so you climb back "+opp+".");
            }
            return 0;
        }
    }
    return 1;
}
void set_fall_desc(string str) {
    fall_desc = str;
}

int set_blocked(string exit, object blocker) {
    if (member_array(exit, query_exits()) == -1) {

        return 0;
    }
    if (!blockedExits) blockedExits = ([]);
    if (member_array(blocker, values(blockedExits)) != -1)
        return -1;
    if (blockedExits[exit]) return -2;
    blockedExits[exit] = blocker;
    return 1;
}

object query_blocked(string exit) {
    if (!blockedExits) {
        return 0;
    }
    if (!blockedExits[exit]) {
        return 0;
    }
    if (!objectp(blockedExits[exit]) || !present(blockedExits[exit],TO)) {
        map_delete(blockedExits, exit);
        return 0;
    }
    return blockedExits[exit];
}

void remove_blocker(string exit) {
    if (!blockedExits) return 0;
    if (!blockedExits[exit]) return 0;
    map_delete(blockedExits,exit);
    return 1;
}

mapping query_blockers() {
    if (!blockedExits) return([]);
    return blockedExits;
}


//Buried exits

void collapse_exit(string ext, int collapse_amount) {
    string *exits;
    string otherroom, exit;

    if (!buried) buried = ([ ]);
    if (!orig_exits) orig_exits = ([ ]);
    exits = query_exits();
    if (member_array(ext, exits) == -1) return;

    if (collapse_amount <= 0) collapse_amount = 200;
    otherroom = query_exit(ext);
    set_buried_exit(ext, collapse_amount);

    exit = otherroom->query_direction(base_name(TO));
    if (exit == "/d/shadowgate/void")
        exit = otherroom->query_direction(base_name(TO)+".c");
    if (exit != "/d/shadowgate/void") {
        otherroom->set_buried_exit(exit, collapse_amount);
        otherroom->remove_exit(exit);
    }
    remove_exit(ext);
}

void collapse_all_exits(int collapse_amount) {
    string *exits;
    string exit;
    int i;

    exits = query_exits();
    for (i=0;i<sizeof(exits);i++) {
        collapse_exit(exits[i], collapse_amount);
    }
}

int dig_exit(string ext, int amount) {
    int i = -1, j = -1, x = -1, y = -1;
    string targroom;
    mapping tmpmap;

    if (!orig_exits) orig_exits = ([ ]);
    if (!buried) buried = ([ ]);
    i = add_digging(ext, amount);

    targroom = orig_exits[ext];
    tmpmap = targroom->query_orig_exits();
    x = member_array(base_name(TO), values(tmpmap));
    y = member_array(base_name(TO)+".c", values(tmpmap));
    if (x != -1 && y != -1)
        return -5;
    if (x == -1 && y == -1) {
        open_buried_exit(ext);
        return -1;
    } else {
        if (x == -1)
            x = y;
        j = targroom->add_digging(keys(tmpmap)[x], amount);
    }

    if (buried[ext] <= 0) {
        open_buried_exit(ext);

        targroom = query_exit(ext);
        tmpmap = targroom->query_orig_exits();
        x = member_array(base_name(TO), values(tmpmap));
        y = member_array(base_name(TO)+".c", values(tmpmap));
        if ( (x != -1 && y != -1) || (x == -1 && y == -1) )
            return -5;
        else {
            if (x == -1)
                x = y;
            targroom->open_buried_exit(keys(tmpmap)[x]);
        }
    }

    if (i != j)
        return -3;

    return j;

}



void set_buried_exit(string ext, int collapse_amount) {
    orig_exits[ext] = query_exit(ext);
    buried[ext] = collapse_amount;
}

void open_buried_exit(string ext) {
    if (member_array(ext, keys(orig_exits)) == -1) return;
    add_exit(orig_exits[ext], ext);
    map_delete(orig_exits, ext);
    map_delete(buried, ext);
}

int add_digging(string ext, int amt) {
    int oldamount;
    int i;
    string targroom;
    mapping tmpmap;

    if (member_array(ext, keys(buried)) == -1) return -1;

    oldamount = buried[ext];
    oldamount -= amt;
    buried[ext] = oldamount;
    if (buried[ext] <= 0)
        return 0;

    return oldamount;
}



int query_buried_amount(string ext) {
    if (!buried) buried = ([ ]);
    if (member_array(ext, keys(buried)) == -1) return -1;
    return buried[ext];
}

mapping query_buried_exits() {
    if (!buried) buried = ([ ]);
    return buried;
}

mapping query_orig_exits() {
    if (!orig_exits) orig_exits = ([ ]);
    return orig_exits;
}

string query_buried_long_addition() {
    string *exits;
    int i;
    string lg;

    if (!buried) buried = ([ ]);
    if (!orig_exits) orig_exits = ([ ]);

    exits = keys(buried);
    if (sizeof(exits) == 0) return "";
    lg = "\n\nRubble is blocking the ";

    if (sizeof(exits) == 1) {
        lg += exits[0]+" exit.";
        return lg;
    }

    for (i = 0;i<sizeof(exits);i++) {
        lg += exits[i]+" ";
    }
    lg += "exits.";
    return lg;
}
