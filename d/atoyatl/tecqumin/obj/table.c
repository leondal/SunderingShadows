#include <std.h>
#include "../tecqumin.h"

inherit MONSTER;
inherit "/std/bag_logic";

string owner;
int cloned;
string short_desc();
string long_desc();
void settle_down();

void create(){
  ::create();
  set_name("many-legged table");
  set_id(({"table", "many-legged table", "followobj"}));
  set_short((:TO, "short_desc":));
  set_long((:TO, "long_desc":));
  set_gender("neuter");
  set_race("piece of furniture");
  cloned = 0;
  set_heart_beat(1);
  set_no_clean(1);
  set_property("no animate",1);
  set_max_internal_encumbrance(100);
}

void heart_beat(){
  object *players, *obs, own, env;
  int i, count;
  if (!stringp(owner)) {return;}
//  ::heart_beat();
  if (!objectp(ETO)){ return;}
//  tell_room(ETO, "Table's heart beats");
  if (!present(owner, ETO)){
    players = children("/std/user.c");
    count = sizeof(players);
    if (count <1) {return;}
    for (i=0;i<count;i++){
      if ((string)players[i]->query_name() == owner){
        own = players[i];
        break;
      }
    }
    if (objectp(own)){
      env = environment(own);
      if (objectp(env)){
        tell_room(ETO, "The many-legged table spins around and then"
          +" rushes off, seemingly in search of something");
        tell_room(env, "A many-legged stone table trips into the room and"
          +" walks happily over to stand by " + own->QCN, own);
        tell_object(own, "A many-legged stone table trips into the room and"
          +" walks happily over to stand next to you.");
        move(env);
        own->add_follower(TO);
      } else {
        tell_room(ETO, "The table looks distressed, as its owner's environment is broken");
      }
    } else {
      tell_room(ETO, "The table looks distressed, as it can't find its owner");
    }
  }
  obs = all_living(ETO);
  count = sizeof(obs);
  for (i=0;i<count;i++){
    if (obs[i]==TO){continue;}
    if (obs[i]->is_table() && (string)obs[i]->query_owner() == owner){
      tell_room(ETO, "The table checks out the other table, and promptly"
      +" sits down on the ground. Even though it doesn't have a face, it" 
      +" manages to look disgruntled.");
      settle_down();
      break;
    }
  }
}

void init(){
  if (cloned ==1){// This check prevents abuse by dropping and insta-getting
    remove();
    return;
  }
  ::init();
  add_action("put_into", "put");
  add_action("get_from", "get");
  add_action("collapse", "collapse");
}

int is_living(){
  return 0;
}

int collapse(string str){
  if (!id(str)){ return notify_fail("Collapse what?");}
  if (cloned == 1){
    remove();
  }
  if (!objectp(ETO)){
    return notify_fail("ERROR - the table's environment is broken."
     +" Please make a bug report on the room you are in");
  }
  tell_object(TP, "You run a hand along either side of the many-legged"
   +" table, and the legs retract as it settles down on the ground");
  tell_room(ETO, TPQCN + " runs a hand along either side of the"
   +" many-legged table, and the legs retract as it settles down on the"
   +" ground", TP);
  settle_down(); //separated some code out, so it can be used with 
  return 1;     //different messages - Lujke
  }

void settle_down(){
  object ob, * conts;
  int i, count;
  if (!objectp(ETO)){return;}
  ob = new(OBJ + "table_ob.c");
  if (!objectp(ob)){
    tell_room(ETO, "ERROR - table_ob isn't working. Please tell Lujke");
  }
  ob->set_cloned(-1);
  ob->move(ETO);
  conts = all_inventory(TO);
  count = sizeof(conts);
  if (count>0){
    for (i= count-1; i>-1;i--){  //normal for loop reversed to retain 
      conts[i]->move(ob);       // order of items in inv
    }    
  }
  if (stringp(owner)){
    ob->set_owner(owner);
  }
  cloned = 1;
  set_name("broken");
  set_race("cloned object");
  set_id(({"clonedtable"}));
  call_out ("remove", 1);
  return 1;
}

int get_from(string str){
  object ob, *conts;
  int i, count;
//If the table is being picked up, make a new, non-living 
//version and transfer the contents
  if (id(str)){
    return notify_fail("You can't pick up the table when"
     +" it's like this. You'd have to <collapse> it first.");
  }
  return bag_logic::get_from(str);
}

int put_into(string str){
  string this, that;
  if (cloned ==1){remove();}
  if(stringp(str) && sscanf(str,"%s on %s",this,that) == 2 
                                       &&(that != "ground")){
    return bag_logic::put_into(this + " in "+ that);
  } 
  return notify_fail("Do you want to put it <on> the table?");
}

int is_table(){
  return 1;
}



string short_desc(){
  string desc, pile, top_ob, article;
  object * conts;
  int count;
  if (cloned == 1){remove(); return "";}
  desc = "%^RESET%^many-legged stone table with ";
  conts = all_inventory(TO);
  count = sizeof(conts);
  if (count<1){
    pile = "";
    top_ob ="nothing";
  } else {
    top_ob = conts[0]->query_short() + "%^RESET%^";
  }
  if (count == 2){
    pile = " and " + conts[1]->query_short() + "%^RESET%^";
  }
  if (count >2 && count <4){
    pile = " %^RESET%^and a few other things";
  }
  if (count > 3 && count <6){
    pile  = " %^RESET%^and a small pile of other stuff";
  }
  if (count > 5){
    pile = " %^RESET%^and a big pile of other stuff";
  }
  if (top_ob[0] == "a" || top_ob[0] == "e" || top_ob[0] == "i"|| top_ob[0] == "o"|| top_ob[0] == "u"){
    article = "an ";
  } else {
    article = "a ";
  }
  if (count<1){ article = "";}
  desc += article + top_ob;
  if (stringp(pile)){ desc += pile;}
  desc += " on it";
  return desc;
}

int set_owner(string own){
  object leader;
  if (cloned == 1){remove();}
  if (!stringp(own)){ return -1;}
  owner = own;
  leader = find_player(owner);
  if (!objectp(leader)){
    leader = present(owner, ETO);
  }
  if (!objectp(leader)){
    return -1;
  }
  leader->add_follower(TO);
  tell_player(leader,"Table is now following you!\n");
  return 1;
}

string query_owner(){
  return owner;
}

string long_desc(){

  string desc;
  if (cloned == 1){remove(); return "";}
  desc = "%^CYAN%^This carved %^RESET%^stone table%^CYAN%^ would be just above"
    +" knee height on the average human.  It is rectangular in shape, with"
    +" multiple pairs of %^ORANGE%^curved legs%^CYAN%^ supporting it on the"
    +" long edges. Unlike most tables, this one is clearly%^BOLD%^%^YELLOW%^"
    +" magically animated%^RESET%^%^CYAN%^ and is almost constantly moving," 
    +" whether following its owner or simply fidgeting restlessly on the"
    +" spot.  Despite the movement, nothing ever falls off the table,"
    +" which seems able to lengthen or shorten its legs to angle tilt its"
    +" top with exquisite timing to keep everything balanced.%^RESET%^ You"
    +" could probably put stuff on the table, or get things from it. You can't"
    +" pick it up while it's moving around, but you could <collapse> the legs"
    +" if you wanted to\n\n";

  if (!objectp(ETO)){desc += "%^BOLD%^%^RED%^ERROR - the table is in a"
    + " broken environment. Please make a bug report on the table.\n\n";}

  if (stringp(owner) && present(find_player (owner), ETO)){
    if (find_player(owner) == TP){
      desc += "This is your table, and is standing near you.";
    } else {
      desc += "It seems to be standing near " +find_player (owner)->QCN;
    }
  } else {
    desc+= "It seems to be standing on its own and unattended at the"
      +" moment";
  }
  return desc;
}
