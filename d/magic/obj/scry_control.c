// Scry Control
// For use with /daemon/ic_scry_locate_d
// Controls a scry object which collects information and passes
// it back to the observer.   This control allows the user to
// control the scrying that the object is doing, as well as to
// allow any spells to be cast though the scrying device.
// Thorn@ShadowGate
// 2 January 2001
// scry_control.c
// Scry power stuff added by ~Circe~ since it seems to have been
// intended from the beginning but was missing.  This will
// hopefully help fix the problem of scry blockers always working
// 6/20/08

#include <std.h>

#define SCRY_D "/daemon/ic_scry_locate_d"
#define ALLOWED_SPELLS  ({ "detect magic", "detect good", \
                           "detect evil", "message", \
                           "detect aura" })

inherit OBJECT;

object observer, target, scry_object, parent;
int no_move, no_spell, ok_to_scry, ready, spellused;
string alias, *sortrem;

void self_destruct();
int check_activity(string str);
mapping shorten(int newsize, mapping remembered);
object find_miss(object play, object victim);
void set_scry_power(int x);
void query_scry_power();
int power;

void create(){
  ::create();

  set_name("scry_control");
  set_property("no detect",1);
  set_id(({"scryx333"}));
  set_short(0);
  set_hidden(1);
  alias = "scry";
  ready = 0;
  spellused = 0;
}

void init() {
  ::init();
  add_action("help","help");
  add_action("scry","scry");
  add_action("recognize","recognize");
  if(!no_spell) add_action("dismiss","dismiss");
  add_action("look","look");
  add_action("peer","peer");
  add_action("stop","stop");
  add_action("remember","remember");
  //	add_action("chant","chant");
  //	add_action("cast","cast");
}

void dest_me()
{
    if(objectp(parent))
	{
		if(query_property("parent_destroying")) return;
		parent->set_property("scry_ob_destroying", 1);
		parent->dest_effect();
	}
}

int move(mixed dest){
  ::move(dest);
  if(!ready) ready = 1;
}

void set_alias(string str) {
  alias = str;
}

void set_observer(object cas){
  observer = cas;
}

void set_target(object ob){
  target = ob;
}

void set_parent(object ob){
  parent = ob;
}

void set_scry_object(object ob){
  scry_object = ob;
}

//Scry power stuff by ~Circe~ 6/20/08
void set_scry_power(int x){
  power = x;
}

void query_scry_power(){
  if(!power) power = 1;
  return power;
}
//End scry power stuff

object query_observer(){
  return observer;
}

object query_target(){
  return target;
}

object query_parent(){
  return parent;
}

object query_scry_object(){
  return scry_object;
}

void die(object ob){
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
  if(objectp(TP) && !avatarp(TP)) return 0;
  else return ::id(str);
}

// If this object is observing a room instead of a person.
void no_move() { no_move = 1; }

// If this object is not a spell.
void no_spell() { no_spell = 1; }

// This call initiates the self-destruct sequence for this scry
// attempt.  It will use the scry and locate daemon call to
// properly clean up any objects or properties that are left
// over and exit gracefully.
void self_destruct()
{
    dest_me();
  	SCRY_D->stop_scry(TO, 0);
  	if(objectp(TO)) TO->remove();
  	return;
}

int help(string str) {
  if(str != alias) return 0;
  write("Instructions for use of this "+alias+".\n");
  write(
@SCRYING
To start scrying a person................ <scry person NAME>
To start scrying a location.............. <scry location NAME>
To stop scrying.......................... <stop scrying>

Note: You must use the remember command to designate locations for
scrying.  You also must recognize a person as something to scry them.

While scrying:
SCRYING
  );
  write("To quickly peer at the scryed location... <peer through "+alias+">");
  write("To look at the scryed surroundings....... <look through "+alias+">");
  write("To recognize a person scryed............. <recognize ID as NAME through "+alias+">");
  write("To remember the location scryed as [id].. <remember through "+alias+" as ID>");
  //	write("To cast a spell using this object........ <cast [class] [spell] on [target] through "+alias+">");
  //	write("    Spells allowed: detect magic, detect good, and detect evil.");
  if(!TO->is_temporary()) write(
@SCRYING2

If you stop scrying, you can restart scrying by issuing the <scry>
command again with the proper arguments.
SCRYING2
  );
  return 1;
}

int scry(string str)
{
    string targ, real, msg;
    mapping map;
    string* map_keys;
    int i, matches;
    object blockobj;

    if (spellused) {
        write("You've already successfully chosen your scrying target!");
        return 1;
    }

    if (sscanf(str, "person %s", targ) == 1) {
        targ = lower_case(targ);
        if (targ == (string)TPQN && !wizardp(TP)) {
            write("%^BOLD%^RED%^Why don't you just look in a mirror or something?");
            return 1;
        }
        //    if(!TP->isKnown(targ)) {
        // I have no idea how this was supposed to work, but all I know is it was
        // not working right anymore.

        if (TP->isKnown(targ) || ((string)TP->realNameVsProfile(targ) != "")) {
            if (TP->isKnown(targ)) {
                real = targ;
            }else {
                real = (string)TP->realNameVsProfile(targ);
            }

            target = find_player(real);

            if (target == TP && !wizardp(TP)) {
                write("%^BOLD%^RED%^Why don't you just look in a mirror or something?");
                return 1;
            }
        }
        if (!objectp(target)) {
            write("%^BOLD%^%^RED%^The target of your spell is not here!");
            return 1;
        }
        if (target->query_true_invis()) {
            write("%^BOLD%^%^RED%^The target of your spell is not here!");
            return 1;
        }

        if (blockobj = present("blockerx111", environment(target)) || blockobj = present("blockerx111", target)) {
            if (TO->query_scry_power() <= blockobj->query_block_power()) {
                tell_object(ETO, "%^BOLD%^RED%^There appears to be " +
                            "interference blocking your scrying attempt in the " +
                            "vicinity of the target!%^RESET%^");
                dest_me();
                SCRY_D->stop_scry(TO, 0);
                return 1;
            }
        }

        if (!objectp(target)) {
            write("%^BOLD%^RED%^You can't get a fix on that!");
            return 1;
        }
    }else if (sscanf(str, "location %s", targ) == 1) {
        map = TP->query_rem_rooms();
        if (!map[targ]) {
            write("%^BOLD%^RED%^You do not recall a location called " + targ + "!");
            return 1;
        }
        target = find_object_or_load(map[targ]);
        if (blockobj = present("blockerx111", target)) {
            if (TO->query_scry_power() <= blockobj->query_block_power()) {
                tell_object(ETO, "%^BOLD%^RED%^There appears to be " +
                            "interference blocking your scrying attempt in " +
                            "the vicinity of the target!%^RESET%^");
                dest_me();
                SCRY_D->stop_scry(TO, 0);
                return 1;
            }
        }
    }else {
        write("Usage: scry person <name>  OR  "
              "scry location <location-id>");
        return 1;
    }
    if (TP != observer) {
        write("%^BOLD%^RED%^You do not have control of this device!");
        return 1;

    }

    msg = SCRY_D->scry_interface(TP, target, TO, 0);
    write("%^BOLD%^CYAN%^" + msg);
    if (!objectp(scry_object)) {
        write("%^BOLD%^RED%^Your scry attempt failed.");
        dest_me();
        SCRY_D->stop_scry(TO, 0);
        return 1;
    }
    TP->set_paralyzed(8 * 2, "%^BOLD%^You're concentrating on a remote location...");
    write("%^BOLD%^GREEN%^You concentrate on remote location scrying...");
    ok_to_scry = 1;
    scry_object->scry_on();
    spellused = 1;
    return 1;
}

int dismiss(string str) {
  if(TP != observer && !avatarp(TP)) {
    return 0;
  }
  if(str != alias) return 0;
  write("%^BOLD%^YELLOW%^You wave your arms and dismiss the scrying spell.");
  tell_room(ETP, TPQCN+" waves "+TP->query_possessive()+" arms around "
	    "dismissively.", ({ TP }));
  dest_me();
  SCRY_D->stop_scry(TO, 1);
  return 1;
}

int chant() {
  return 0;
}

int stop(string str) {
  if(str != "scrying") return 0;
  if(!ok_to_scry) return 0;
  if(TP != observer) {
    write("%^BOLD%^RED%^You do not have control of this device!");
    return 1;
  }
  if(!objectp(scry_object)) {
    tell_player(TP, "You've lost contact with the target of your scrying!\n");
    return 1;
  }
  scry_object->scry_off();
  ok_to_scry = 0;
  tell_object(TP, "%^BOLD%^YELLOW%^You stop scrying through the "+alias+".\n");
  dest_me();
  SCRY_D->stop_scry(TO, 1);
  return 1;
}

int peer(string str)
{
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", ETO);
        return 0;
    }

    if (str != "through " + alias) {
        return 0;
    }
    if (!ok_to_scry) {
        write("%^BOLD%^RED%^You aren't scrying anything.");
        return 1;
    }
    if (TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()) {
        write("You cannot do that in your current state!");
        return 1;
    }
    write("%^BOLD%^GREEN%^The image zooms out briefly, granting a glance...");
    scry_object->look_room(environment(scry_object));
    return 1;
}

int look(string str)
{

    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", ETO);
        return 0;
    }

    if (str != "through " + alias) {
        return 0;
    }
    if (!ok_to_scry) {
        write("%^BOLD%^RED%^You aren't scrying anything.");
        return 1;
    }
    if (TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()) {
        write("You cannot do that in your current state!");
        return 1;
    }
    write("%^BOLD%^GREEN%^The image zooms out, giving you a long look around...");
    if (objectp(scry_object)) {
        scry_object->long_look_room(environment(scry_object));
    }
    return 1;
}

int recognize(string str)
{
    string who, as;
    object ob;

    if (!str) {
        return 0;
    }

    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", ETO);
        return 0;
    }

    if (sscanf(str, "%s as %s through " + alias, who, as) != 2) {
        return 0;
    }


    ob = present(who, environment(scry_object));
    if (!objectp(ob)) {
        return write("There is no " + who + " in the area you are viewing.\n");
    }
    if (TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()) {
        write("You cannot do that in your current state!");
        return 1;
    }else {
        if (userp(ob)) {
            write("You will recognize " + who + " as " + capitalize(as) + ".");
            TP->addRelationship(ob, as);
        }else {
            write("You can only recognize other players at this time.");
        }
    }
    return 1;
}

int cast(string str) {
  object targ, *armor;
  int i,j,flag;
  int align;
  string str2,tmp;
  string type, spell, tar;

  if(TP != target) return 0;

  if(!str){
    write("Cast what on/at what?");
    return 0;
  }

  if(!sscanf(str,"%s %s through "+alias,type,str2))
    if(!sscanf(str,"%s %s through "+alias,type,str2))
      if(!sscanf(str,"%s %s through "+alias,type,str2))
	return 0;
  str = str2;
  if(!sscanf(str,"%s %s on %s",type,str2,tar))
    if(!sscanf(str,"%s %s at %s",type,str2,tar))
      if(!sscanf(str,"%s %s to %s",type,str2,tar))
	str2 = str;

  if(!member_array(str2, ALLOWED_SPELLS)) {
    write("You cannot cast that spell with this "+alias+".");
    return 1;
  }
  if(!TP->is_class(type)){
    notify_fail("You cannot cast spells as a "+type+"!\n");
    return 1;
  }
  align = TP->query_alignment();
  if(type == "bard" && (align==1 || align==3 || align==7 || align==9)){
    notify_fail("You cannot use your bard commands unless you are "
    		"of a neutral alignment!\n");
    return 1;
  }

  if(type == "mage" || type = "psion"){
    flag = 0;
    armor = TP->all_armour();
    i = sizeof(armor);

    for(j=0;j<i;j++){
      if((string)armor[j]->query_type()!="clothing" &&
	 (string)armor[j]->query_type()!="bracer" &&
	 (string)armor[j]->query_type()!="ring" &&
	 !armor[j]->query_property("magicarmor")) {
	if(TP->is_class("bard") &&
	   ((string)armor[j]->query_type() == "chain" ||
	    (string)armor[j]->query_type() == "leather"))
	  continue;
	flag = 1;
	break;
      }
    }
    if(flag){
      write("You cannot cast while wearing all that armor!");
      return 1;
    }
  }
  tmp = "/cmds/spells/"+spell[0..0]+"/_"+spell+".c";
  if(!file_exists(tmp)){
    tmp = "/cmds/spells/"+spell[0..0]+"/_"+spell+".c";
    if(!file_exists(tmp)){
      write("Either that spell does not exist, or you do not know it!");
      return 1;
    }
  }
  if(!tar)
    tar = 0;
  new(tmp)->wizard_interface(TP,tar);
  return 1;
}

int remember(string str)
{
    object ob;
    int i;
    string filename;
    mapping remembered;
    string name;

    if (!str) {
        return 0;
    }

    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", ETO);
        return 0;
    }

    if (sscanf(str, "through mirror as %s", name) || sscanf(str, "through ball as %s", name) || sscanf(str, "through crystal ball as %s", name) || sscanf(str, "through " + alias + " as %s", name)) {
        if (!name) {
            return notify_fail("Remember this room as what?\n");
        }
        if (TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()) {
            write("You cannot do that in your current state!");
            return 1;
        }

        remembered = TP->query_rem_rooms();
        if (!objectp(scry_object)) {
            return notify_fail("Something is wrong with the scrying sensor. Please contact a wiz.\n");
        }
        ob = environment(scry_object);
        filename = file_name(ob);
        if (!remembered = TP->query_rem_rooms()) { // mapping ([name:place])
            remembered = ([]);
        }
        if (!sortrem = TP->query_rem_rooms_sort()) { //names
            sortrem = ({});
        }
        remembered[name] = filename;
        sortrem = distinct_array(({ name }) + sortrem);
        if (sizeof(sortrem) > (int)TP->query_stats("intelligence")) {
            remembered = shorten((int)TP->query_stats("intelligence"), remembered);
        }
        TP->set_rem_rooms(remembered, sortrem);
        tell_object(TP, "You study the location, retaining its features firmly in your mind.");
    } else {
        return 0;
    }
    return 1;
}

mapping shorten( int newsize, mapping remembered ) {
  while (sizeof(sortrem) > newsize) {
    map_delete( remembered, sortrem[sizeof(sortrem) - 1] );
    sortrem -= ({ sortrem[sizeof(sortrem) - 1]});
  }
  return remembered;
}

// EOF is here/
