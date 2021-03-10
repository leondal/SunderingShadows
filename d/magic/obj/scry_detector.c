// Scry Detector
// For use with /daemon/ic_scry_locate_d
// Follows around the player or target that it is watching
// and notifies him/her of any scry attempts into that area.
// Thorn@ShadowGate
// 5 January 2001
// scry_detector.c

#include <std.h>
#include <daemons.h>

#define SCRY_D   "/daemon/ic_scry_locate_d"
#define ETC      environment(control)

inherit OBJECT;

object observer, target, control;
object *already;
int no_move, ready;

void self_destruct();
void detect_scrying();
int filter_non_living(object ob);
int look_room(object dest);
string describe_item_contents(object *exclude);
void set_detect_power(int x);
void query_detect_power();
int power;


void create(){
    ::create();
    
    set_name("scry detector");
    set_property("no detect",1);
    set_id(({"detectorx444"}));
    set_short(0);
    //set_invis();
    set_hidden(1);
    //add_limb("body","",0,0,0);
    ready = 0;
    already = ({ });
    set_heart_beat(1);
}

int move(mixed dest){
    ::move(dest);
    if(!ready) ready = 1;
}

void set_target(object ob){
   target = ob;
   target->set_property("detect scrying", TO);
}

void die(object ob){
}

void heart_beat(){
    object to_block;
    if(!objectp(TO)) return;

    //if(!ready) return;
    if(!objectp(target)) {
        self_destruct();
        return;
    }
    //if(!no_move && objectp(environment(target))) 
        //if(ETO != environment(target))
            //move(environment(target));
    if(ETO != target) move(target);

    if(!objectp(ETO)) 
    {
        self_destruct();
        return;
    }
	detect_scrying();

    if(living(ETO))
    {
        if(!objectp(EETO)) 
        {
            self_destruct();
            return;
        }
        else
        {
            to_block = EETO;
        }
    }
    else
    {
        to_block = ETO;
    }
}

void init() {
	::init();
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

// If this object is observing a room instead of a person.
void no_move() { no_move = 1; }

// This call initiates the self-destruct sequence for this scry 
// attempt.  It will use the scry and locate daemon call to 
// properly clean up any objects or properties that are left
// over and exit gracefully.
void self_destruct() {
	if(objectp(target)) target->remove_property("detect scrying");
    if(objectp(TO)) TO->remove();
    return;
}

void detect_scrying() {
   object *inv;
   object control, observer,to_block, myloc;
   int i, detect_power;
   string loc, name;
	
   if(!objectp(ETO)) return;

   if(living(ETO)){ 
      if(!objectp(EETO)) return;
      else to_block = EETO;
   }else{
      to_block=ETO;
   }

   inv = all_inventory(to_block);
   for(i=0;i<sizeof(inv);i++) {
      if(inv[i]->is_scry_object()) {
         if(member_array(inv[i], already) != -1) continue;
         control = inv[i]->query_control();
         if(objectp(control)){
            observer = control->query_observer();
            if(!objectp(observer)) {
               control->self_destruct();
               continue;
            }
         }else{
            observer = inv[i]->query_caster();
            if(!objectp(observer)) observer = inv[i]->query_mycaster();
         }
         if(!living(inv[i])) { continue; }
         already += ({ inv[i] });
         detect_power = TO->query_detect_power();
         if((detect_power + random(10)) > inv[i]->query_scry_power()){ //Adding a check to detect scrying so it's not automatic
            tell_object(target,"%^BOLD%^MAGENTA%^You detect someone scrying you!%^RESET%^");
            if(detect_power > inv[i]->query_scry_power()) { //second check to see if they see the observer
               tell_object(target,"%^BOLD%^YELLOW%^You get an image of who and where they are!%^RESET%^");
               myloc = environment(observer);
               loc = environment(observer)->query_short();
               name = capitalize(observer->query_cap_name());
               look_room(myloc);
               continue;
            }
         }
      }
   }
   return;
}

void set_detect_power(int x){
  power = x;
}

void query_detect_power(){
  if(!power) power = 1;
  return power;
}

int look_room(object dest) {
    string file, desc;
    object *inv;
    int i;
    
    tell_object(target, 
    	"\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n");
    inv = all_inventory(dest);
    
    for(i=0; i<sizeof(inv); i++) {
    	if(!living(inv[i])) continue;
    	if(inv[i]->query_invis()) continue;
    	if(inv[i]->query_hidden()) continue;
    	if(!inv[i]->is_detectable()) continue;
    	tell_object(target, 
    		"%^WHITE%^BOLD%^[S] %^RED%^"+inv[i]->query_short());
	}
//    desc = describe_item_contents( ({ }) );
//    tell_object(target, desc);
    return 1;
}

string describe_item_contents(object *exclude) {
   object *inv;
   mapping list;
   string ret, tmp;
   string *shorts,*temp;
   int i, x;

   i = sizeof(inv = filter_array((all_inventory(ETO)-exclude),
                                 "filter_non_living", this_object()));
   if(!i) return "";
   list = ([]);
   while(i--) {
      if((inv[i]->query_hidden() || inv[i]->query_magic_hidden()) || !inv[i]->is_detectable()) {
          continue;
      }
      TO->set_property("information",1);
      if(!(tmp = (string)inv[i]->query_short())) continue;
      TO->remove_property("information");
      if(tmp == "") continue;
      if( (temp=explode(tmp," ")) == ({}) ) continue;

      if (inv[i]->query_hidden() || inv[i]->query_magic_hidden()) {
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

int filter_non_living(object ob) {return !(living(ob) || ob->query("not living"));}
