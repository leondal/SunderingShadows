#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;
int unlocked;
int opened;

string * contents, treasure_options;

void create() {

  ::create();
  set_short("The Tabaxi elder's hut"); 
  set_long("This small wooden hut is sparsely furnished, with a low table and some cushions. The"
          +" thatched roof keeps it nicely cool, and an easy breeze comes through the un-glassed"
          +" windows. A strongbox is located toward the back of the room, in the shade.");
  set_items(([ ]));
  set_exits( ([ "out" : TABAXROOM + "centre" 
             ]) );
  set_items(([ ({"table", "low table"}): "A simple, low wooden table." ,
             ({ "cushions"}) : "Some large cushions are scattered around the table",
     "strongbox" : (:TO, "strongbox_desc":)
            ]));
  unlocked = 0;
  opened = 0;
  treasure_options = ({
                        TABAXOBJ + "eyepatch", 
                        OBJ + "table",
                        OBJ + "macana", 
                        OBJ + "stone_hammer",
                        OBJ + "bolas_greater"
                          });
  contents = ({});
}

string * query_treasure_options(){
  return treasure_options;
}

string * query_contents(){
  return contents;
}

void init(){
  ::init();
  set_had_players(3);
  add_action("open_strongbox", "open");
  add_action("unlock_strongbox", "unlock");
  add_action("pick_strongbox", "pick");
  add_action("get_stuff", "get");
}

void set_treasures(int num){
  int i;
  string treasure;
  treasure_options -= ({OBJ + "table"});
  contents += ({OBJ + "table"});
  for (i=0;i<num;i++){
    if (sizeof(treasure_options)<1) return;
    treasure  = treasure_options[random(sizeof(treasure_options))];
    treasure_options -= ({treasure});
    contents +=  ({treasure});
  }
}

string strongbox_desc(){
  string result;
  object treasure;
  int i, count;
  result = "The strongbox looks large, very sturdy and very heavy. ";
  if (opened == 1)
  {
    result += "It is standing open at the moment";
    count = sizeof(contents);
    if (count<1)
    {
      result += ", and appears to be empty.";
    } else {
      result += ". Inside, you can see:\n";
      for (i=0;i<count;i++)
      {
        treasure = new(contents[i]);
        if (objectp(treasure))
        {
          if (count>1 && i ==count-1)
          {
            result += "and ";
          }
          result += treasure->query_short();
          if (count > 1 && i<count-1) result += ", ";
        }
      }
    }
  } else {
    result +=  "The key mechanism is of a most complicated and unpickable sort. Makes you"
    +" wonder what's in there.";
  }
  return result;
}

int open_strongbox(string str){
  if (str != "strongbox" && str != "the strongbox")
  {
    return notify_fail("Do you want to open the strongbox");
  }
  if (unlocked == 0)
  {
    tell_object(TP, "The strongbox can only be unlocked with a special key");
    return 1;
  }
  if (opened == 1)
  {
    tell_object(TP, "The strongbox is already open");
    return 1;
  } 
  set_treasures(3); 
  opened = 1;
  tell_object(TP, "You open the strongbox and peer inside");
  TP->force_me("look strongbox");
  tell_room(TO, TPQCN +" %^RESET%^opens the strongbox and looks inside", TP);

}

int unlock_strongbox(string str){
  int num;
  if (str != "strongbox" && str != "the strongbox")
  {
    return notify_fail("Do you want to unlock the strongbox");
  }
  if (unlocked == 1)
  {
    tell_object(TP, "The strongbox is already unlocked");
    return 1;
  }
  if (!present("tabaxkey", TP))
  {
    tell_object(TP, "You don't have the right key for that. Unfortunately, it looks completely unpickable without the key.");
    return 1;
  }
  unlocked = 1;
  tell_object(TP, "You unlock the strongbox with the " + present("tabaxkey", TP)->query_short());
  tell_object(TP, "%^BLUE%^As you finish unlocking the %^RESET%^strongbox%^BLUE%^, the "
    + present("tabaxkey", TP)->query_short() + " %^RESET%^%^BLUE%^disappears, as if by magic");
  tell_object(TP, "(It probably is magic)");
  tell_room(TO, TPQCN +" %^RESET%^unlocks the strongbox with a " + present("tabaxkey", TP)->query_short(), TP);
  present("tabaxkey", TP)->move("/d/shadowgate/void");
  
}

int get_stuff(string str){
  int num, count, i;
  object item;
  string what, where;
  num = sscanf (str, "%s from %s", what, where);
  if (num <2 || (where != "strongbox" && where != "the strongbox") )
  { 
    return notify_fail("Do you want to get something from the strongbox? Try 'get <item> from strongbox'");
  }
  if (sizeof(contents)<1)
  {
    tell_object(TP, "There's nothing in the strongbox at the moment");
    return 1;
  }
  for (i=0;i<sizeof(contents);i++)
  {
    item = new(contents[i]);
    if (item->id(what))
    {
      tell_object (TP, "You get " + item->query_short() + " %^RESET%^from the strongbox");
      tell_room (TPQCN, " %^RESET%^gets " + item->query_short() + " %^RESET%^from the strongbox");
      item->move(TP);
      contents -= ({contents[i]});
      return 1;
    }
  }
  tell_object(TP, "There is no " + what + " %^RESET%^in the strongbox");
  return 1;
}

void reset(){
  object * elders, elder;
  int i, flag;
  ::reset();
  elders = children(MOB + "nobacherie");
  flag = 0;
  if (sizeof(elders)>0){
    for (i=0;i<sizeof(elders);i++){
      if (objectp(elders[i])&& objectp(environment(elders[i]))){
        flag = 1;
        break;
      }
    }
  }
  if (flag <1){
    elder = new(MOB + "nobacherie");
    elder->move(TO);
  }
  if (had_players<1)
  {
    opened = 0;
    unlocked = 0;
  }
}
