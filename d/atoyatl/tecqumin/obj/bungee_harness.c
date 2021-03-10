//Coded by Lujke


#include <std.h>
#include "../tecqumin.h"
inherit ARMOUR;
object *vines;
string anchor_point;
int length;

void drag_rope(string direction);
void break_connection();
int pre_exit_fun(string str);
string dir_to_room(object start_room, object targ_room);
int move(mixed dest);
object * query_vines();
void set_vines(object * v);
void add_vine(object v);
void remove_vine(object v);
string long_desc();
int attach_fun(string str);
void set_anchor_point(string pt);
void untie(string str);

void create() {
  ::create();
  set_name("harness");
  set_id( ({"harness", "bungee harness", "vine harness" }) );
  set_short("%^ORANGE%^h%^GREEN%^a%^ORANGE%^rn%^GREEN%^e"
    +"%^ORANGE%^ss of %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n"
    +"%^ORANGE%^e%^GREEN%^s");
  set_type("ring");
  set_ac(0);
  set_weight(2);
  set_long( (:TO, "long_desc":) );
  set_limbs(({"left leg","right leg", "waist"}));
  vines = ({});
  length = 3;
  anchor_point = "none";
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
  add_action("attach_fun", "attach");
  add_action("attach_fun", "tie");
  add_action("gather_vine", "gather");
}

void drag_rope(string direction){
  int i, count;
  object room;
  string exit;
  count = sizeof(vines);
  tell_object(TP, "You are dragging the vine " + direction);
  if (count>1){
    tell_object(TP, "You are dragging " + count + " vines");
    for(i=0;i<count -1;i++){
      tell_object(TP, "Vine " + i + " is in: " + file_name(environment(vines[i])));
      if (i==0){
        vines[i]->set_entry_point("none");
      } else {
        vines[i]->set_entry_point(vines[i+1]->query_entry_point());
      }
      vines[i]->set_exit_point(vines[i+1]->query_exit_point());
      vines[i]->move(environment(vines[i+1]));
      tell_object(TP, "Vine " + i + " has moved to: " + file_name(environment(vines[i])));
    }
  }
  if (count > 0){
    tell_object(TP, "Last vine is in: " + file_name(environment(vines[count-1])));
    tell_object(TP, "moving the last vine to " + EETO->query_exit(direction));
    room = find_object_or_load(EETO->query_exit(direction));
    if (!objectp(room)){
      tell_object(TP, "There was a problem loading the room: " + EETO->query_exit(direction));
    }
    vines[count-1]->set_exit_point("none");
    vines[count-1]->set_entry_point(dir_to_room(room, EETO));
    vines[count-1]->move(room);
    tell_object(TP, "Last vine is has moved to: " + file_name(environment(vines[count-1])));
  }
}

void break_connection(){
  int i, count;
  count = sizeof(vines);
  if (objectp(ETO) && objectp(EETO)){
    tell_object(ETO, "The harness has become detached from its anchor"
      +" point");
    tell_room(EETO, ETO->QCN + "'s harness has become detached from"
      +" its anchor point", ETO);
  }
  if (count > 0 ){
    for (i=0;i<count;i++){
      if (objectp(vines[i])){
        vines[i]->remove();
      }
    }
  }
  vines = ({});
}

int pre_exit_fun(string str){
  object wearer, new_anchor, target_room;
  int count;
  if (!objectp(ETO) || !objectp(EETO)){
    return 0;
  }
  if (!living(ETO)){
    return 0;
  }
  count = sizeof(vines);
  if (count>1){
    if (str == (string)vines[count-1]->query_entry_point()){ //this happens if the carrier is going back on themselves
      tell_object(ETO, "You gather up the trailing vine as you go"
        +" back on yourself");
      tell_room(EETO, ETO->QCN + " gathers up the vine trailing"
        +" from " + ETO->QP + " harness of vines as " + ETO->QS 
        + " goes back on " + ETO->QO + "self", ETO);
      vines[count-1]->remove();
      if (count>1){
        vines = vines[0..count-2];
        vines[count-2]->set_exit_point("none");
      }
      return 0;
    }
  }
  if ( anchor_point == "none"){
    if (sizeof(vines)<1){
      return 0;
    }
    drag_rope(str);
    return 0;
  }
  wearer = query_worn();
  if (sizeof(vines) >= length){
  tell_object(TP, "all the rope has played out");
    if (anchor_point != "none"){
      tell_object(TP, "No need to drag anything");
      if (!objectp(wearer)|| wearer != ETO ){
        tell_object(ETO, "The harness is attached to something. You"
          +" can't take it any further");
      } else {
        tell_object(ETO, "The harness is attached to something. You"
          +" can't go any further"); 
      } 
    }
    return 1;
  }
  if (!objectp(EETO)){
    tell_object(ETO, "There's an error - the room you are in"
      +" seems not to exist. Please contact a WIZ");
    return 1;
  }
  target_room = find_object_or_load(EETO->query_exit(str));
  if (!objectp(target_room)||file_name(target_room)=="/d/shadowgate/void"){
    target_room = find_object_or_load(EETO->query_climb_exit(str));
  }
  if (!objectp(target_room)){
    tell_object(ETO, "There's an error - the room you are going to"
      +" seems not to exist. Please contact a WIZ");
    return 1;
  }
  new_anchor = new(OBJ + "bungee_anchor");
  new_anchor->set_harness(TO);
  new_anchor->set_entry_point(dir_to_room( target_room, EETO));
  tell_object(TP, "The rope plays out behind you as you move.");
  if (new_anchor->query_entry_point()=="none"){
    tell_object(ETO, "%^BLUE%^The %^GREEN%^v%^ORANGE%^i%^GREEN%^ne"
      +" %^BLUE%^snags on something and %^ORANGE%^snaps%^BLUE%^!");
    break_connection();
  }
  new_anchor->move(ETP);
  if (sizeof(vines)>0){
    vines[sizeof(vines)-1]->set_exit_point(str);
  }
  add_vine(new_anchor);
  new_anchor->move(target_room);
  return 0;
}

void calculate_climb_exits(object room, string * exits){
  if (!objectp(room)){ return exits;}
  if (room->query_climb_exit("up")!= "/d/shadowgate/void"){exits += ({"up"});}
  if (room->query_climb_exit("down")!= "/d/shadowgate/void"){exits += ({"down"});}
  if (room->query_climb_exit("climb")!= "/d/shadowgate/void"){exits += ({"climb"});}
  if (room->query_climb_exit("descend")!= "/d/shadowgate/void"){exits += ({"descend"});}
  return exits;
} 

string dir_to_room(object start_room, object targ_room){
  object room;
  string * exits;
  int i, count;
  if (!objectp(start_room) ||!objectp(targ_room)){
    return "none";
  }
  exits = start_room->query_exits();
  exits = calculate_climb_exits(start_room, exits);
  count = sizeof(exits);
  if (count<1){
    tell_object(find_player("lujke"), "There are no exits");
    return "none";
  }
  for (i=0;i<count;i++){
    tell_object(find_player("lujke"), "Testing exit: " + exits[i]);
    if (start_room->query_exit(exits[i]) == file_name(targ_room)||
        start_room->query_climb_exit(exits[i])==file_name(targ_room)){
      return exits[i];
    }
  }
  return "none";
}

int move(mixed dest) { 
  if(objectp(dest) && dest->is_room()) { 
    dest->set_had_players(5);
  } 
  return ::move(dest); 
}

object * query_vines(){
  return vines;
}

void set_vines(object * v){
  vines = v;
}

void add_vine(object v){
  if (sizeof(vines)<1){
    vines = ({});
  }
  vines += ({v});
}

void remove_vine(object v){
  if (member_array(v, vines)==-1){
    return;
  }
  vines -= ({v});
}

string long_desc(){
  string desc, *anchor_points;
  object room;
  int i, count;
  desc = "%^ORANGE%^The harness is made of %^GREEN%^t%^ORANGE%^w"
    +"%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^s%^ORANGE%^t%^GREEN%^e"
    +"%^ORANGE%^d v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^e"
    +"%^RESET%^%^ORANGE%^s, and seems to be designed to fit around"
    +" the %^RESET%^legs %^ORANGE%^and %^RESET%^waist%^ORANGE%^. It"
    +" is adjustable to fit a variety of sizes, and has a trailing"
    +" %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ne %^ORANGE%^r"
    +"%^GREEN%^o%^ORANGE%^p%^GREEN%^e%^ORANGE%^, which doubtless is"
    +" important to its purpose.";
  room = EETO;
  if (objectp(room)){
    if (sizeof(vines)<1){
      anchor_points = room->query_anchor_points();
      count = sizeof(anchor_points);
      if (count>0){
        desc += "%^GREEN%^ You could attach the rope to a ";
        for (i=0;i<count;i++){
          if (i>0){
            if (i==count-1){
              desc += " or a ";
            } else {
              desc += ", a ";
            }
          }
          desc += anchor_points[i];
        }
        desc += ".";
      }
    } else {
      if (objectp(vines[0])){
        if (objectp(EETO) && vines[0]->query_anchor_room() 
                                                 == file_name(EETO)){
          desc += "%^RESET%^ It is tied to " 
                               + vines[0]->query_anchor_point() + ".";
        }
      } else {
        vines = ({});
      }
    }
  }
  if (sizeof(vines)>1 && objectp (vines[sizeof(vines)-1])){
    desc += " %^RESET%^The rope stretches off to the " 
                     + vines[sizeof(vines)-1]->query_entry_point()+ ".";
  }
  return desc;
}

int attach_fun(string str){
  string what, harness, * anchor_points;
  object anchor;
  int i;
  object anch;
  i = sscanf(str, "%s to a %s", harness, what);
  if (i<2){
    i = sscanf(str, "%s to the %s", harness, what);
  }
  if (i<2){
    i = sscanf(str, "%s to %s", harness, what);
  }
  if (i<2){
    return notify_fail("Attach what to what?");
  }
  if (!id(harness)){
    return notify_fail("That's not suitable for attaching to anything");
  }
  if (sizeof(vines)>0){
    return notify_fail("The harness is already attached to something. You'll"
      +" need to untie it before attaching it to somewhere else");
  }
  anchor_points = ({});
  if (objectp(ETP)){
    anchor_points = ETP->query_anchor_points();
  }
  if (sizeof(anchor_points)<1){
    return notify_fail("There's nowhere suitable to attach it here");
  }
  if (member_array(what, anchor_points)==-1){
    return notify_fail("You can't attach it to that!");
  }
  tell_object(TP, "You attach the " + query_short() + " to the " + what);
  if (objectp(ETP)){
    tell_room(ETP, ETO->QCN + " attaches the " + query_short() + " to the " + what, ETO);
  }
  anchor = new (OBJ + "bungee_anchor");
  anchor->set_anchor_point(what);
  anchor->set_harness(TO);
  anchor->move(ETP);
  anchor->set_anchor_room(file_name(ETP));
  set_anchor_point(what);
  vines = ({anchor});
  return 1;
}

int gather_vine(string str){
  string what;
  int num, i, count;
  num = sscanf(str, "up the %s", what);
  if (num <1){  num = sscanf(str, "up a %s", what);}
  if (num <1){  num = sscanf(str, "the %s", what);}
  if (num <1){  num = sscanf(str, "a %s", what);}
  if (num <1){  num = sscanf(str, "up %s", what);}
  if (num<1){what = str;}
  if (!str || (what!= "vine" && what != "tethered vine" && what != "rope" 
        && what != "vine rope")){
    return notify_fail("Do you want to gather up the vine?");
  }
  if (anchor_point!= "none"){
    tell_object(TP, "The vine is tied to something. You will have to go"
      +" back and untie it.");
    return 1;
  }
  count = sizeof(vines);
  if (count<1){
    tell_object(TP, "The vine does not need gathering up");
    return 1;
  }
  for (i=count-1;i>=0;i--){
    if (objectp(vines[i])){
      if (objectp(environment(vines[i]))){
        tell_room(environment(vines[i]), "The %^GREEN%^v%^ORANGE%^i"
          +"%^GREEN%^ne %^RESET%^slithers past as someone gathers it up");
      }
      vines[i]->remove(); 
    }
  }  
  vines = ({});
  tell_object(TP, "You gather up the trailing %^GREEN%^v%^ORANGE%^i"
    +"%^GREEN%^ne");
}

void set_anchor_point(string pt){
  anchor_point = pt;
}

string query_anchor_point(){
  return anchor_point;
}

void untie(string str){
  return notify_fail("You need to be in the room where the harness is anchored to untie it.");
}
