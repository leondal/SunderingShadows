// Modification of the weapon sheath inherit for shields. Nienne, Sep 6th 2004.

#include <std.h>
#include <move.h>
inherit PARMOUR;

#define CM TO->query_property("call_myself")

// STUFF I OVERLOADED FOR THIS BEAST!

int query_internal_encumbrance() {
  int iter;
  int weight;
  object * inv;
  weight = 0;
  if (!sizeof(all_inventory(TO))) return 0;
  for (iter=0,inv=all_inventory(TO);iter<sizeof(inv);iter++) weight += inv[iter]->query_weight();
  return weight;
}

int query_value() {
  int holder;
  if (!(holder=::query_value()))
    return ( 5  * (int)query_property("sheath_size")  * (int)query_property("sheath_size"));
  else return holder;
}

int query_weight() {
  if (sizeof(all_inventory(TO)))
    return TO->query_property("original_weight") + TO->query_internal_encumbrance();
  else 
    return TO->query_property("original_weight");
}

string query_long(string i_do_not_know_why) {
  string str, type;
  string *possible_places;
  int iter,maxiter;
  function QPROP=(:TO, "query_property":);
  str = ::query_long(i_do_not_know_why);

  str += "\n\nThis "+CM+" can be worn only on the back.\n";
  str += "This "+CM+" can only hold a shield.\n";
  if (TP==TP) str += "%^BOLD%^(Try typing <help "+CM+"> as well.)\n";
  return str;
}

int query_size(){
  if(!objectp(TP) || !living(TP)) return 2;
  return TP->query_size();
}

// END OVERLOADS

void create(){
  ::create();
  if (!stringp(TO->query_property("call_myself")))
    set_property("call_myself","strap");
  if (!pointerp(TO->query_property("can_hold")))
    set_property("can_hold",({ "shield", "thiefshield" }));
  if (!intp(TO->query_property("original_weight")))
    set_property("original_weight",2);
  set_property("repairtype",({ "jewel","armorsmith" }));
  set_name("strap");
  set_id(({"strap","straps","shield strap"}));
  set_short("A shield "+CM);
  set_long("This is a shield strap. It is meant to hold a single shield, and has adjustable straps to fit "
"both large and small kinds. The straps are designed to hold the shield upon the wearer's back, so as to "
"keep it in a convenient location when not in use.\n");
  set_type("sheath");
  set_limbs(({"torso"}));
  set_size(2);
  set_value(35);
  set_max_internal_encumbrance(30);
}

void init() {
  ::init();
  if (TP!=TP)
    return;
  add_action("draw_from","draw");
  add_action("sheath_into", "sheath");
  add_action("help","help");
}

int is_mixable() {return 1;}

int put_into(string str){
  int res, i, silly;
  object ths,tht,*inv;
  string this, that;
  if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if (stringp(str) && sscanf(str,"%s in %s",this,that) == 2) {
    if (present(this,this_player())) {
      if (present(that,this_player()) || present(that,environment(this_player()))) {
        ths = present(this,this_player());
        tht = present(that, this_player());
        if(ths == tht) {
          notify_fail("Get real!\n");
          return 0;
        }
        if(!tht) tht = present(that, environment(this_player()));
        if(ths->drop()) {
          notify_fail("You cannot drop that!\n");
          return 0;
        }
        if(tht != TO) return 0;
        if((string)ths->query_type() != "shield" && (string)ths->query_type() != "thiefshield"){
          notify_fail("This is meant for shields only.\n");
          return 0;
        }
        if(sizeof(all_inventory(TO)) > 0) {
          notify_fail("This "+CM+" is already holding something.\n");
          return 0;
        }
        if(sizeof(all_inventory(ths)) > 0) {
          notify_fail("The "+this+" is holding something, you can't fit it into that.\n");
          return 0;
        }
        if (tht->receive_objects()) {
          res = (int)ths->move(tht);
          if (res == MOVE_OK) {
	      write("You put "+ths->query_short()+" in "+tht->query_short()+".\n");
	      say("%^BOLD%^%^BLUE%^"+TPQCN+" secures "+ths->query_short()+ " in "+tht->query_short()+".\n");
	      TP->add_encumbrance(ths->query_weight());
	      return 1;
          }
          if (res == MOVE_NO_ROOM) notify_fail("For some reason it does not fit...\n");
          if (res == MOVE_NOT_ALLOWED) notify_fail("You are not allowed to do that...\n");
          return 0;
        }
        notify_fail("It is closed.\n");
        return 0;
      }
      notify_fail(capitalize(that)+" is not here.\n");
      return 0;
    }
    notify_fail("You are not carrying "+this+".\n");
    return 0;
  }	
  return 0;
}

int get_from(string str) {
  int res, i, silly, weight;
  object ob, tmp, *inv;
  string what, where;
  if(!stringp(str)) return 0;
  if(this_player()->query_ghost()) return 0;
    
  if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if(sscanf(str, "%s from %s", what, where) != 2) return 0;
  if(id(where)) tmp = this_object();
  else tmp = parse_objects(environment(this_object()), where);
  if(tmp != this_object()) return 0;

  if(this_object()->receive_objects()) {
    if(what != "all") {
      ob = present(what, this_object());
      if(!ob) ob = parse_objects(this_object(), what);
      if(!ob) {
        write("There is no "+what+" in "+this_object()->query_short()+".");
        return 1;
      }
      weight = ob->query_weight();
      ob->set_weight(0);
      res = (int)ob->move(this_player());
      ob->set_weight(weight);
      if(res == MOVE_OK) {
        if (weight > 0) weight *= -1;
        TO->add_encumbrance(weight);
        write("You get "+ob->query_short()+" from "+this_object()->query_short()+".");
        tell_room(ETP,TPQCN+" gets "+ob->query_short()+" from "+this_object()->query_short()+".",TP);
        return 1;
      }
      if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
      if(res == MOVE_NO_ROOM) write("You can't carry that!");
      return 1;
    }
    inv = all_inventory(this_object());
    if(!sizeof(inv)) {
      write("There is nothing in "+this_object()->query_short()+".");
      return 1;
    }
    // Backwards compatibility, for people who REALLY like to do 'get all'
    for(i=0; i<sizeof(inv); i++) {
      weight = inv[i]->query_weight();
      inv[i]->set_weight(0);
      res = (int)inv[i]->move(this_player());
      inv[i]->set_weight(weight);
      if(res == MOVE_OK) {
        if (weight > 0) weight *= -1;
        TO->add_encumbrance(weight);
        write("You get "+inv[i]->query_short()+" from "+this_object()->query_short()+".");
        tell_room(ETP,TPQCN+" gets "+inv[i]->query_short()+" from "+this_object()->query_short()+".",TP);
      }
      if(res == MOVE_NO_ROOM) write(inv[i]->query_short()+": Too heavy.\n");
    }
    return 1;
  }
  write(query_short()+" is closed.");
  return 1;
}

int draw_from(string str) {
  int silly;
  int res, i, weight;
  object ob, tmp, *inv;
  string what, where;
  if(!stringp(str)) return 0;
  if(this_player()->query_ghost()) return 0;
  if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if(sscanf(str, "%s", what) != 1) return 0;
  if(this_object()->receive_objects()) {
    ob = present(what, this_object());
    if(!ob) ob = parse_objects(this_object(), what);
    if(!ob) {
      notify_fail("You don't have a "+what+" in any of your "+CM+".\n");
      return 0;
    }
    weight = ob->query_weight();
    ob->set_weight(0);
    res = (int)ob->move(this_player());
    ob->set_weight(weight);
    if(res == MOVE_OK) {
      if (weight > 0) weight *= -1;
      TO->add_encumberance(weight);
      write("You get "+ob->query_short()+" from your "+this_object()->query_short()+".");
      tell_room(ETP,""+TPQCN+" takes "+ob->query_short()+" from "+this_object()->query_short()+".",TP);
      TP->force_me("wear "+ ((string *)ob->query_id())[0]);
      return 1;
    }
    if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
    if(res == MOVE_NO_ROOM) write("You can't carry that!");
    return 1;
  }
  write(query_short()+" is closed.");
  return 1;
}

int sheath_into(string str){
  int silly;
  int res, i;
  object ths,tht,*inv;
  string this, that;
  if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if (stringp(str) && sscanf(str,"%s",this) == 1) {
    if (present(this,this_player())) {
      ths = present(this,this_player());
      tht = TO;
      if(ths == tht) {
	  notify_fail("Get real!\n");
        return 0;
      }
      ths->unwear();
      if(ths->query_worn()) {
        return 1;
      }
      //if(!ths->unwear()) {
	  //notify_fail("You cannot put that away!\n");
       // return 0;
      //}
      if((string)ths->query_type() != "shield" && (string)ths->query_type() != "thiefshield"){
        notify_fail("This is meant for shields only.\n");
        return 0;
      }
      if(sizeof(all_inventory(TO)) > 0) {
        notify_fail("You can't find somewhere free to put that.\n");
        return 0;
      }
      if(sizeof(all_inventory(ths)) > 0) {
        notify_fail("The "+this+" is holding something, you can't fit it into that.\n");
        return 0;
      }
      if (tht->receive_objects()) {
        res = (int)ths->move(tht);
        if (res == MOVE_OK) {
            write("You sheathe "+ths->query_short()+" into "+tht->query_short()+".\n");
            say("%^BOLD%^%^BLUE%^"+TPQCN+" secures "+ths->query_short()+ " in "+tht->query_short()+".\n");
            TP->add_encumbrance(ths->query_weight());
	      return 1;
          }
        if (res == MOVE_NO_ROOM) notify_fail("For some reason it does not fit in any of your "+CM+".\n");
        if (res == MOVE_NOT_ALLOWED) notify_fail("You are not allowed to do that.\n");
        return 0;
      }
      notify_fail("It is closed.\n");
      return 0;
    }
    notify_fail("You are not carrying "+this+".\n");
    return 0;
  }	
  return 0;
}

string query_short() {
  string str;
  string inv;
  int i;
  inv = all_inventory(TO);
  str = ::query_short();
  if(!sizeof(inv)) str = str+" (empty)";
  return str;
}

int help(string str){
  if ( !TO->id(str) && str != "strap" ) return 0;
  write("
Commands for shield straps

  put <shield> in strap 
  get <shield> from strap 

    These work the same as a normal bag... if the shield fits.

  draw <shield>

    Takes a shield from a strap, and makes you wear it.

  sheath <shield>

    Sticks a shield in the first available strap it can fit in.

");
  return 1;
}
