#include <std.h>
#include "../tecqumin.h"

inherit "/std/bag_logic";
int cloned;

string owner;
string short_desc();
string long_desc();

void create(){
  ::create();
  set_name("many-legged table");
  set_id(({"table", "many-legged table", "tablexxx"}));
  set_short((:TO, "short_desc":));
  set_long((:TO, "long_desc":));
  cloned = 0;
  set_lore("");
  set_property("no animate", 1);
}

void init(){
  if (cloned ==1){// This check prevents abuse by dropping and insta-getting
    remove();
    return;
  }
  ::init();
  add_action("put_into", "put");
  add_action("get_from", "get");
  add_action("claim_me", "claim");
}

int is_living(){
  return 0;
}

int move(object dest){
  object table, *conts;
  int i, count, res;
  if (cloned ==1){remove(); return 0;}
  res = ::move(dest);
  if (cloned == -1){ //so that the object can be moved to a
    cloned = 0;     // non-living environment on creation
    return res;
  }    if (!living(ETO)){
    table = new (OBJ + "table");
    conts = all_inventory(TO);
    count = sizeof(conts);
    if (count>0){
      for (i=count-1;i>-1;i--){   //normal for loop reversed to retain 
        conts[i]->move(table);  //order of items in inv
      }
    }
    if (stringp(owner)){
      table->set_owner(owner);
    }
    cloned = 1;               //
    set_short("");            // These lines avoid any duping 
    set_long("");             // problems
    set_id(({"clonedtable"}));// Lujke
    call_out("remove", 1);
    table->move(ETO);
    return res;
  }
  return res;
}

int get_from(string str){
  if (cloned == 1){
    return 0;
    remove();
  }
  return bag_logic::get_from(str);
}
void set_cloned(int cln){
  cloned = cln;
}

int put_into(string str){
  string this, that;
  if (cloned == 1){
    remove();
    return 0;
  }
  if(stringp(str) && sscanf(str,"%s on %s",this,that) == 2 
                                       &&(that != "ground")){
    return bag_logic::put_into(this + " in "+ that);
  } 
  return notify_fail("Do you want to put it <on> the table?");
}

int is_table(){
  return 1;
}

int claim_me(string str){
  if (!id(str)){
    return notify_fail("claim what?");
  }
  if ( !objectp(ETO) || !living(ETO)){
    return notify_fail("You would have to be carrying the"
     +" table to claim it");
  }
  owner = ETO->query_name();
  tell_object(ETO, "You have claimed the table, and now it is yours");
  return 1;
}

string short_desc(){
  string desc, pile, top_ob, article;
  object * conts;
  int count;
  if (cloned ==1){return "";}
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
  return 1;
}

string query_owner(){
  return owner;
}

string long_desc(){
  object posessor;
  string desc;
  if (cloned ==1){return "";}
  desc = "%^CYAN%^This carved %^RESET%^stone table%^CYAN%^ would be just above"
    +" knee height on the average human.  It is rectangular in shape, with"
    +" multiple pairs of %^ORANGE%^curved legs%^CYAN%^ on the"
    +" long edges. The legs are currently folded under the table. They will"
    +" unfurl when you drop the table.";
  if (stringp(owner) && (string)TP->query_name()==owner){
    desc += "\n%^ORANGE%^This table belongs to you";
  } else {
    if (objectp(ETO)&& stringp(owner)){
      posessor = present(owner, ETO);
      if (objectp(posessor)){
        desc += "This is " + posessor->QCN + "'s table.";
      }
    }
    desc += "\n %^RESET%^If you wish, you could %^ORANGE%^claim%^RESET%^ the"
      +" table for yourself.";
  }
  return desc;
}

int query_weight(){
  int i, count, weight;
  object * conts;
  conts = all_inventory(TO);
  weight = 10;
  count = sizeof(conts);
  if (count >0){
    for (i=0;i<count;i++){
      weight += conts[i]->query_weight();
    }
  }
  return weight;
}
