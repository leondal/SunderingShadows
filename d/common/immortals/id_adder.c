// Coded by Lujke. These are the devilkin's dancing boots. They are
// enchanted to +1, have an ac setting of -1 when worn, but give a bonus
// of +1 to dex.


#include <std.h>
#include <move.h>
inherit ARMOUR;

string * ids, wearer;

void create()
{
  ::create();
  set_short("id adder");
  set_name("strange item");
  set_id(({"id adder","adder",}));
  set_long("Four sets of red eyes, which Lurue can use alterobj on if she wants it to look fancier");
  set_weight(5);
  set_type("clothing");
  set_limbs(({"head"}));
  set_ac(0);
  set_value(50);
  set_wear((:TO,"wearme":));
  set_read("You can use this item to add or remove ids from the creature who wears it. Use the"
         +" commands:\n add id <id>\ndelete id <id>\n list ids\nclear ids\n You can also 'set wearer"
         +" <wearer>, to change the creature the item is bound to.");
  ids = ({});
}

void init(){
  ::init();
  if (objectp(ETO)&& interactive(ETO)){
    if (!avatarp(ETO)){
      remove();
    }
  }
  add_action("list_ids", "list");
  add_action("add_id", "add");
  add_action("remove_id", "delete");
  add_action("clear_ids", "clear");
  add_action("set_wearer", "set");
}

int set_wearer(string str){
  string who;
  object what;
  if (!avatarp(TP) && !TP->query_true_invis()){
    return 0;
  }
  if (sscanf(str, "wearer %s", who)<1){
    return notify_fail("Try 'set wearer <who>'");
  }

  what = present(who, ETP);
  if (!objectp(what)){
    tell_object(TP, who + " is not here");
  }
  wearer = (string)what->query_name();
  tell_object(TP, "Wearer changed. " + who + " should now be able to wear the item");
  return 1;
}

string query_wearer(){
  return wearer;
}

int wearme()
{ 
  int i;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (!ETO->id(wearer)){
    tell_object(ETO, "You can't wear those! You don't look like a hideous beastie that the avatars"
                    +" need to mess with.");
    call_out("wear2", 2, ETO);
    return 0;
  }
  if (sizeof(ids)>0){
    for (i=0;i<sizeof(ids);i++){
      ETO->add_id(ids[i]);
    }
  }
  return 1;
}

wear2(object ob){
  if (objectp(ob)){
    tell_object(ob, "Well, on reflection maybe you do. But you still can't wear them!");
  }
}


int list_ids(string str){
  int i;
  if (sizeof(ids)<1){
    tell_object(TP, "There are no ids set. Start your own by typing 'add id <id>'");
    return 1;
  }
  tell_object(TP, "The current ids set are:");
  for (i=0;i<sizeof(ids);i++){
    tell_object(TP, ids[i]);
  }
  return 1;
}

int add_id(string str){
  string what;
  if ( sscanf(str, "id %s", what) <1){
    tell_object(TP, "Try  'add id <id>'");
    return 1;
  }
  if (member_array(what, ids)!= -1){
    tell_object(TP, "That id is already on the list");
    return 1;
  }
  tell_object(TP, "id '" + what + "' added.");
  ids += ({what});
  return 1;
}

int remove_id(string str){
  string what;
  if ( sscanf(str, "id %s", what) <1){
    tell_object(TP, "Try  'delete id <id>'");
    return 1;
  }
  if (member_array(what, ids)== -1){
    tell_object(TP, "That id is not on the list. You don't need to delete it.");
    return 1;
  }
  tell_object(TP, "id '" + what + "' removed.");
  ids -= ({what});
  return 1;
}

int clear_ids(string str){
  if (str != "ids"){
    return notify_fail("Try 'clear ids'");
  }
  tell_object(TP, "id list cleared");
  ids = ({});
  return 1;
}
