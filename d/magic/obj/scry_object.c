// Scry Object
// For use with /daemon/ic_scry_locate_d
// Catches tells, loads short descs of places it moves to,
// can follow a target around.  Basically allows crystal
// ball-like functionality.  Could be set up with filters
// to allow for languages and detect invis.
// Quite a bit ripped off from Listening Shadow priest spell.
// Thorn@ShadowGate
// 2 January 2001
// scry_object.c

#include <std.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"
#define ETC    environment(control)

inherit MONSTER;

object observer, target, control, *already;
int no_move, ok_to_scry, ready;

void self_destruct();
int look_room(object dest);
string describe_item_contents(object *exclude);
int filter_living(object ob);
int filter_non_living(object ob);
int send_living_name(object target);
void int_based_detection(object place);
int arithmetic_progression(int num);

void create()
{
    ::create();
    set_name("scry_object");
    set_property("no detect",1);
    set_id(({"scryx222"}));
    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
    ok_to_scry = 0;
    ready = 0;
    already = ({ });
    set_property("water breather",1);
}

int move(mixed dest)
{
    ::move(dest);
    if(!ready) {
    	ready = 1;
    }
    else {
	    if(objectp(dest)) {
	    	look_room(dest);
	    	int_based_detection(dest);
	    }
	}
}

set_observer(object cas){
   observer = cas;
}

set_target(object ob){
   target = ob;
}

set_control(object ob){
   control = ob;
}

object query_control(){
   return control;
}

void die(object ob){
}

void heart_beat(){
    if(!ready) return;
    if(!objectp(observer) || !objectp(target)) {
        self_destruct();
        return;
    }
         if(observer->query_unconscious()) {
      self_destruct();
       return;
    }
    if(target->query_ghost()) {
        self_destruct();
        return;
    }
    if(!no_move && objectp(environment(target)))
        if(ETO != environment(target))
            move(environment(target));
	if(ETO->query_property("no scry")) {
		self_destruct();
		return;
	}
   observer->use_stamina(3);
   observer->increment_stamina(5);
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int is_scry_object(){ return 1; }

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

// If this object is observing a room instead of a person.
void no_move() { no_move = 1; }

// Let the scrying begin.
void scry_on() { ok_to_scry = 1; }

// Turn off sending scry messages to the observer.
void scry_off() { ok_to_scry = 0; }

int look_room(object dest)
{
    string file, desc;
    object *inv;
    object *watchers;
    int i, j;

    watchers = all_living(ETC);
    watchers = filter_array(watchers,"is_player",FILTERS_D);

    if(!watchers)
    {
	    message("living_item", "%^CYAN%^BOLD%^[X] %^RED%^", ETC);
	    return 0;
    }

    for(j=0;j<sizeof(watchers);j++)
    {
         if((watchers[j]->query_unconscious()) || (watchers[j]->query_blindfolded()) || (watchers[j]->query_blind())) watchers -= ({watchers[j]});
    }

    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n",watchers);

    inv = all_inventory(dest);
    for(i=0; i<sizeof(inv); i++)
    {
      if(!living(inv[i])) continue;
      if(inv[i]->id("scryx222")) { continue; }
      if(inv[i]->query_invis()) continue;
    	if(inv[i]->query_hidden()) continue;
     	if(!inv[i]->is_detectable()) continue;
     	TO->send_living_name(inv[i]);
    }
    desc = describe_item_contents( ({ }) );
    message("inanimate_item", desc, watchers);
    return 1;
}

int long_look_room(object dest) {
    string file, desc;
    object *inv;
    object *watchers;
    int i,j;

    if(!ok_to_scry) return 0;
    watchers = all_inventory(ETC);
    if(!watchers) {
	message("living_item", "%^CYAN%^BOLD%^[X] %^RED%^",
	  	ETC);
	return 0;
    }
    for(j=0;j<sizeof(watchers);j++) {
         if((watchers[j]->query_unconscious()) || (watchers[j]->query_blindfolded()) || (watchers[j]->query_blind())) watchers -= ({watchers[j]});
    }
    message("room_description",
    	"\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_long()+"\n", watchers);
    inv = all_inventory(dest);
    for(i=0;i<sizeof(inv);i++) {
     	if(!living(inv[i])) continue;
        if(inv[i]->id("scryx222")) { continue; }
     	if(inv[i]->query_invis()) continue;
    	if(inv[i]->query_hidden()) continue;
    	if(!inv[i]->is_detectable()) continue;
    	TO->send_living_name(inv[i]);
    }
    desc = describe_item_contents( ({ }) );
    message("inanimate_item", desc, watchers);
    return 1;
}

// This call initiates the self-destruct sequence for this scry
// attempt.  It will use the scry and locate daemon call to
// properly clean up any objects or properties that are left
// over and exit gracefully.
void self_destruct() {
    SCRY_D->stop_scry(control, 0);
    if(objectp(TO)) TO->remove();
    return;
}

catch_tell(string str)
{
    object *scry_objects=({}),*people=({}),room;
    int i;

    if(!objectp(control))
    {
        TO->remove();
        return;
    }
    if(!objectp(ETC)) { return; }

    people = all_living(ETC);
    people = filter_array(people,"is_player",FILTERS_D);

    for(i=0;i<sizeof(people);i++)
    {
        if(!objectp(people[i])) { continue; }
        tell_object(people[i],"%^BOLD%^[S]%^RESET%^" +str);
    }
}


string describe_item_contents(object *exclude)
{
   object *inv;
   mapping list;
   string ret, tmp;
   string *shorts,*temp;
   int i, x,j;

   i = sizeof(inv = filter_array((all_inventory(ETO)-exclude),
                                 "filter_non_living", this_object()));

   inv = filter_array(inv,"is_player",FILTERS_D);
    i = sizeof(inv);
   if(!i) return "";
   list = ([]);
   while(i--)
   {
      if((inv[i]->query_hidden() || inv[i]->query_magic_hidden()) || !inv[i]->is_detectable())
      {
          continue;
      }
      TO->set_property("information",1);
      if(!(tmp = (string)inv[i]->query_short())) continue;
      TO->remove_property("information");
      if(tmp == "") continue;
      if( (temp=explode(tmp," ")) == ({}) ) continue;

      if (inv[i]->query_hidden() || inv[i]->query_magic_hidden())
      {
         tmp = "("+tmp+")";
      }
      if(!list[tmp]) list[tmp] = ({ inv[i]});
      else list[tmp] += ({inv[i]});
   }
   i = sizeof(shorts = keys(list));
   if(!i) return "";
   if((x=sizeof(list[shorts[--i]])) == 1)
      ret = capitalize(shorts[i]);
   else ret = capitalize(consolidate(x, shorts[i]));
   if(!i) return(x <2 ? "%^BOLD%^CYAN%^[S] %^MAGENTA%^"+ret+" is here.\n" : "%^BOLD%^CYAN%^[SCRYED] %^MAGENTA%^"+ret +" are here.\n");
   else if(i==1)
      return "%^BOLD%^CYAN%^[S] %^MAGENTA%^"+ret+", and "+
      consolidate(sizeof(list[shorts[0]]), shorts[0])+
      " are here.\n";
   else {
      while(i--) {
         if(!i) ret += ", and ";
         else ret += ", ";
         ret += consolidate(sizeof(list[shorts[i]]), shorts[i]);
      }
   }
   return "%^BOLD%^CYAN%^[S] %^RESET%^"+ret+" are here.\n";
}

int filter_living(object ob) {return(living(ob) || ob->query("not living"));}

int filter_non_living(object ob) {return !(living(ob) || ob->query("not living"));}

int send_living_name(object target) {
	object *watchers;
	string known, str;
	int i,j;

	watchers = all_inventory(ETC);

    watchers = filter_array(watchers,"is_player",FILTERS_D);

	if(!watchers) {
	    message("living_item", "%^CYAN%^BOLD%^[X] %^RED%^",
	    	ETC);
	    return 0;
	}
    for(j=0;j<sizeof(watchers);j++) {
         if((watchers[j]->query_unconscious()) || (watchers[j]->query_blindfolded()) || (watchers[j]->query_blind())) watchers -= ({watchers[j]});
    }
    if(target->is_monster()) {
	str = target->query_short();
	message("living_item", "%^CYAN%^BOLD%^[S] %^RED%^"+str,watchers);
      return 1;
    }
    for(i=0;i<sizeof(watchers);i++) {
	    if(objectp(watchers[i]) && watchers[i]->knownAs(target->query_true_name())) {
	    	known = watchers[i]->knownAs(target->query_true_name());
		}
        str = target->getWholeDescriptivePhrase();
	    if(known) str = capitalize(known)+", "+str;
	    message("living_item", "%^CYAN%^BOLD%^[S] %^RED%^"+str,
	    	watchers[i]);
	    known = 0;
	}
	return 1;
}

void int_based_detection(object place)
{
	object *people;
	int i, intel, base, bonus, chance, roll;

	if(!objectp(place)) return;
	people = filter_array(all_inventory(place), "filter_living", this_object());

    people = filter_array(people,"is_player",FILTERS_D);

//	people += ({ target });
	for(i=0;i<sizeof(people);i++) {
		if(member_array(people[i], already) != -1) continue;
		intel = people[i]->query_stats("intelligence");
		if(intel < 12) continue;
        base = 6;
		bonus = intel - 12;
		bonus = arithmetic_progression(bonus);
		chance = base + bonus;
		roll = random(100)+1;
		if(avatarp(people[i]) || roll <= chance) {
			tell_object(people[i],
				"%^BOLD%^RED%^You are being scryed by someone!");
		}
		already += ({ people[i] });
	}
	return;
}

int arithmetic_progression(int num) {
	int retval, i;

	for(i=0;i<num;i++) {
		retval += i;
	}
	return retval;
}

void set_invis() {
  if (TO->query_invis())
   return;
else return ::set_invis();
}
