//Coded by Lujke

#include <std.h>
#include "../tecqumin.h"
#define OBNAMES ({"stick", "pole", "chest", "sword", "hammer", "mace", "shield", "plate", "banded", "block", "brick", "polearm", "halberd", "awlpike", "lance", "bastard", "bardiche", "rapier", "longsword", "lucern", "axe", "club", "star", "fork", "spear", "staff", "pick", "scythe", "rake", "fauchard", "sickle", "spetum", "shortsword", "longsword", "trident", "wakizashi", "katana", "khopesh", "warhammer", "quarterstaff", "longbow", "crossbow", "shortbow", "bow", "barding", "bronze", "wooden", "helm", "drum", "lute", "lyre", "fiddle", "mandolin", "basket", "lantern", "table", "wood", "block"})
#define DAMAGE_LVLS ({"beginning to show signs of wear and tear", "slightly damaged", "damaged", "seriously damaged", "nearly destroyed"})
inherit "/std/bag_logic";
int closed;
string * drivers;
object * wedges;

void create(){
  ::create();
  set_id( ({"rent", "rent in the fabric of reality", "void", 
                                                "interdimensional void", "rift"}) );
  set_short("A rent in the fabric of reality");
  set_long( (:TO, "long_desc" :) );
  set_weight(50000);
  set_heart_beat(1);
  closed = 0;
  wedges = ({});
  drivers = ({});
  set_max_internal_encumbrance(30000);
}

void init(){
  ::init();
  add_action("enter", "enter", );
  add_action("wedge", "wedge");
  add_action("wedge", "jam");
  add_action("wedge", "brace");
  add_action("wedge", "shove");
  add_action("wedge", "force");
  add_action("wedge", "stick");
  add_action("wedge", "thrust");
  add_action("wedge", "stuff");
  add_action("wedge", "place");
}

object * query_wedges(){
  return wedges;
}

string * query_drivers(){
  return drivers;
}

void set_drivers (string * drv){
  drivers = drv;
}

int wedge(string str){
  string rift, what, verb, *ids;
  int num, i, count, flag;
  object ob;
  verb = query_verb();
  if (!stringp(str)){
    switch (verb){
    case "wedge":
    case "brace"://deliberately falling through
      tell_object(TP, "What are you trying to %^BOLD%^%^YELLOW%^<" + verb 
        + " open>%^RESET%^ with what?"); 
      return 1;
    default:
      tell_object(TP, "What are you trying to %^BOLD%^%^YELLOW%^<" + verb
        +" into>%^RESET%^ where?");
      return 1;
    }
  }
  num = sscanf(str, "%s open with %s", rift, what);  
  if (num <2){
    num = sscanf(str, "%s with %s", rift, what);
  }
  if (num < 2){
    num = sscanf(str, "%s into %s", what, rift);  
  }
  if (num<2){
    switch (verb){
    case "wedge":
    case "brace"://deliberately falling through
      tell_object(TP, "What are you trying to %^BOLD%^%^YELLOW%^<" + verb 
        + " open>%^RESET%^ with what?"); 
      return 1;
    default:
      tell_object(TP, "What are you trying to %^BOLD%^%^YELLOW%^<" + verb
        +" into>%^RESET%^ where?");
      return 1;
    }
  }
  ob = present(what, TP);
  if (!objectp(ob)){
    return notify_fail("You don't have a " + what);
  }
  if (!id(rift)){
    switch(verb){
    case "wedge":
    case "brace"://deliberately falling through
      tell_object(TP, "What are you trying to %^BOLD%^%^YELLOW%^" + verb
        + " open%^RESET%^ with " + what + "?");
      return 1; 
      break;
    default:    
      tell_object(TP, "Where are you trying to %^BOLD%^%^YELLOW%^" + verb
        + " %^RESET%^" + what + "?");
      return 1; 
      break;
    }
  }
  ids = ob->query_id();
  flag = 0;
  count = sizeof(ids);
  if (count>0){
    for (i = 0; i<count;i++){
      if (member_array(ids[i], OBNAMES)!=-1){
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1){
    switch(verb){
    case "wedge":
    case "brace"://deliberately falling through
      tell_object(TP, "You " + verb + " the rift open with " 
        + ob->query_short());
      tell_room(ETO, TPQCN + verb + "s the rift open with " 
        + ob->query_short(), TP);
      break;
    default:
      tell_object(TP, "You " + verb + " " + ob->query_short() 
        + " %^RESET%^into the rift, wedging it open." );
      tell_room(ETO, TPQCN + verb + "s "+ ob->query_short()
        + " %^RESET%^into the rift, wedging it open.", TP);
    }
    ob->set_property("added short string",({" (( Wedging open the"
      +" %^BLUE%^rent%^RESET%^ in reality ))"}));
    ob->remove_property("added short");
    ob->set_property("added short",ob->query_property("added short string"));
    ob->move(TO);
    wedges += ({ob});
  } else {
    tell_object(TP, ob->query_short() + " isn't really suitable for"
      +" wedging the rift open");
    return 1;
  }
  return 1;
}

void heart_beat(){
  int i, count, num;
  string * added_short;
  count = sizeof(wedges);
  if (count>0){
    for (i=count-1;i >= 0;i--){
      if (!objectp(wedges[i])) {
        wedges -= ({wedges[i]});
      } else {
        if (!present(wedges[i], TO)){
          added_short = wedges[i]->query_property("added short string");
          num = sizeof(added_short);
          wedges[i]->remove_property("added short string");
          wedges[i]->remove_property("added short");
          if (num > 1){
            added_short = added_short[0..num-2];
            wedges[i]->set_property("added short string", added_short);
            wedges[i]->set_property("added short", added_short);
          }
          wedges -= ({wedges[i]});
        }
      }
    }
  }
}

void destroy(ob){
  object * contents, room;
  int i;
  room = find_object_or_load(TECVOID + "inner_void0");
  if (!objectp(ob)){
    tell_room(ETO, ob->query_short() + " %^BOLD%^%^RED%^breaks%^RESET%^"
      +" under the strain of the closing %^BLUE%^rift%^RESET%^!");
    if (member_array (ob, wedges)!=-1){
      wedges -= ({ob});
    }
    if (wedges[i]->is_container()){
      contents = all_inventory(ob);
      if (sizeof(contents)>0){
        tell_room(ETO, "%^BOLD%^%^YELLOW%^Its contents spill out either"
          +" side of the %^RESET%^%^BLUE%^rift%^BOLD%^%^YELLOW%^!");
        for (i=0;i<sizeof(contents);i++){
          switch(random(2)){
          case 0:
            contents[i]->move(ETO);
            break;
          case 1:
            contents[i]->move(room);
            break;
          }
        }
      }
    }
    ob->remove();
  }
}

void damage(object ob, int dam){
  int condition, i, count;
  if (!objectp(ob)){ return; }
  condition = ob->query_overallStatus();
  if (dam>condition){
    destroy(ob);
    return;
  }
  ob->set_overallStatus(condition - dam);
}

void close(){
  object * rooms, room;
  int i, j,count, dam;
  if (!objectp(ETO)){
    return;
  } 
  rooms = ({ETO});
  room = find_object_or_load(TECVOID + "inner_void0");
  if (objectp(room)){
    rooms += ({room});
  } 
  if (sizeof(wedges)>0){    
    for (i=0;i<sizeof(rooms);i++){
      tell_room(rooms[i], "Something gets in the way of the rift closing!");
    }
    dam = 20 + random(40);
    count = sizeof(wedges);
    for (i=count-1; i >=0;i--){
      if (objectp(wedges[i])){
        damage(wedges[i], dam / sizeof(wedges));
        for (j=0;j<sizeof(rooms); j++){          
          tell_room(rooms[j], wedges[i]->query_short() + " %^RESET%^is damaged by the"
            +" closing %^BLUE%^rift%^RESET%^!" );
        }
      }
    }
  }else{
    for (i=0;i<sizeof(rooms);i++){
      tell_room(rooms[i], "%^BLUE%^The edges of the rift are dragged toward each other");
    }
    closed += 5 + random(10);
  }
  if (closed >= 100){
    for (i=0;i<sizeof(rooms);i++){
      tell_room(rooms[i], "%^BOLD%^%^BLACK%^The %^RESET%^%^BLUE%^rift %^BOLD%^%^BLACK%^"
        +"is fully closed!");
      final_close();
    }    
  }
}

void final_close(){
  object room, hero;
  string * heroes;
  int i, count;
  tell_room(ETO, "A few %^BOLD%^%^YELLOW%^s%^MAGENTA%^p%^BLUE%^a%^CYAN%^r%^MAGENTA%^k"
    +"%^YELLOW%^s%^RESET%^ of %^BOLD%^%^YELLOW%^en%^RED%^e%^YELLOW%^r%^CYAN%^g"
    +"%^YELLOW%^y %^CYAN%^fl%^WHITE%^i%^CYAN%^t %^RESET%^about before the%^BLUE%^"
    +" rift%^RESET%^ disappears completely");
  room = find_object_or_load(TECVOID + "inner_void0");
  if (objectp(room)){
    room->remove_exit("out");
  }
  heroes = query_drivers();
  count = sizeof(heroes);
  if (count >0){
    for (i=0;i<count;i++){
      hero = find_player(heroes[i]);
      if (objectp(hero)){
        grant_quest(hero, "%^GREEN%^Sealed the %^BLUE%^U%^MAGENTA%^nf"
        +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
        +" %^GREEN%^back into the %^BLUE%^v%^BOLD%^%^BLACK%^o%^RESET%^i%^BLUE%^d", 1000000, 
         "The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^"
        +"e%^MAGENTA%^d %^RESET%^is sealed back in its"
        +" %^BOLD%^%^BLACK%^v%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^id%^RESET%^. The Realms"
        +" are safe again, for now.", 1);
      }
    }
  }
  move("/d/shadowgate/void");
}

int query_closed(){
  return closed;
}

void set_closed(int cl){
  closed = cl;
}

int enter(string str){
  object room;
  if (str != "void" && str != "rift" && str != "rent" 
                                      && str != "rent in the fabric of reality") {
    return notify_fail("Enter what?");
  }
  if (objectp(ETO) && present("unfettered", ETO)){
    tell_object(TP, "There is no way you could squeeze in past all the"
      +" %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^BOLD%^%^WHITE%^"
      +"a%^BOLD%^%^BLACK%^cl%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^ and"
      +" %^GREEN%^sl%^BOLD%^i%^RESET%^%^GREEN%^me");
    return 1;
  }
  room = find_object_or_load(TECVOID + "inner_void0");
  if(!objectp(room)){
    tell_object(TP, "There was an ERROR with the void - please contact a WIZ and"
      +" tell them Lujke messed up");
    return 1;
  }
  tell_object(TP, "Taking your %^BOLD%^%^WHITE%^life%^RESET%^ into your hands, you"
    +" take a run up to %^BOLD%^%^BLUE%^leap%^RESET%^ into the" 
    +" %^BOLD%^%^BLACK%^void%^RESET%^");
  tell_room(ETO, "Taking " + TP->QP + " %^BOLD%^%^WHITE%^life%^RESET%^ into "+ TP->QP
    + " hands, " + TPQCN + " takes a run up to %^BOLD%^%^BLUE%^leap%^RESET%^ into"
    +" the %^BOLD%^%^BLACK%^void%^RESET%^", TP);
  call_out("enter2", 2, TP);
  return 1;
}

void enter2(object ob){
  object room;
  if (!objectp(ob)){ return;}
  if (!objectp(ETO) || !present(ob, ETO)){
    tell_object(ob, "The void is no longer near enough for you to leap into");
    return;
  }
  room = find_object_or_load(TECVOID + "inner_void0");
  if(!objectp(room)){
    tell_object(TP, "There was an ERROR with the void - please contact a WIZ and"
      +" tell them Lujke messed up");
    return 1;
  }
  tell_object(ob, "I hope this is a good idea");
  tell_room(ETO, TPQCN + " runs  toward the %^BOLD%^%^BLACK%^void%^RESET%^", ob);
  call_out("enter3", 3, TP);  
} 

void enter3(object ob){
  object room;
  if (!objectp(ob)){ return;}
  if (!objectp(ETO) || !present(ob, ETO)){
    tell_object(ob, "The void is no longer near enough for you to leap into");
    return;
  }
  room = find_object_or_load(TECVOID + "inner_void0");
  if(!objectp(room)){
    tell_object(TP, "There was an ERROR with the void - please contact a WIZ and"
      +" tell them Lujke messed up");
    return 1;
  }
  tell_object(TP, "You launch yourself through the %^BLUE%^rent%^RESET%^ in reality"
    +" and into the %^BOLD%^%^BLACK%^v%^RESET%^o%^BOLD%^%^BLACK%^id%^RESET%^"
    +" beyond!"); 
  tell_room(ETO, TPQCN + " launches " + TP->QO + "self through the"
    +" %^BLUE%^rent%^RESET%^ in reality and into the"
    +" %^BOLD%^%^BLACK%^v%^RESET%^o%^BOLD%^%^BLACK%^id%^RESET%^ beyond!"
     , ob);   
  ob->move(room);
  ob->force_me("look");
}

string long_desc(){
  object room, unfettered;
  string desc, view;
  desc = "A jagged %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ar"
    +"%^RESET%^ in reality opens onto the black confines of an %^BOLD%^%^WHITE%^i"
    +"%^RESET%^n%^BOLD%^"
    +"%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^"
    +"%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s"
    +"%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a%^BOLD%^%^WHITE%^l"
    +" %^RESET%^%^BLUE%^void%^RESET%^. %^MAGENTA%^Purple%^RESET%^ strands and"
    +" %^MAGENTA%^s%^BOLD%^p%^RESET%^%^MAGENTA%^a%^BLUE%^r%^MAGENTA%^ks%^RESET%^ of"
    +" %^BOLD%^%^YELLOW%^energy%^RESET%^ dance around the edges, where the%^CYAN%^"
    +" normal %^ORANGE%^world%^RESET%^ contacts the weirdness of %^BLUE%^Outside"
    +"%^RESET%^.";
  if (present("unfettered", ETO)){
    desc += " The flailing %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^ntac%^BOLD%^"
      +"%^WHITE%^l%^BOLD%^%^BLACK%^es of the %^RESET%^%^MAGENTA%^Un%^BLUE%^f"
      +"%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed%^RESET%^ writhe out"
      +" through the %^BLUE%^rift%^RESET%^, reaching to attack any living thing they"
      +" encounter, and the bulk of its body presses close up to the boundary";
  } else {
    room = find_object_or_load(TECVOID + "inner_void0");
    unfettered = present("unfettered", room);
    if (objectp(room) && objectp(unfettered) 
                      && !unfettered->query_tentacles_withdrawn()){
      desc += " The %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^ntac%^BOLD%^"
      +"%^WHITE%^l%^BOLD%^%^BLACK%^es of the %^RESET%^%^MAGENTA%^Un%^BLUE%^f"
      +"%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^ed%^RESET%^ seem to be"
      +" grasping the edges of the %^BLUE%^rift%^RESET%^, attempting to drag it"
      +" shut.";
    } 
  }
  room = find_object_or_load(TECVOID + "inner_void0");
  switch (closed){
  case 0:
    break;
  case 1..13:
    desc += " It is just beginning to close.";
    break;
  case 14..35:
    desc += " It is partly closed.";
    break;
  case 36..45:
    desc += " It is almost halfway closed.";
    break;
  case 46..55:
    desc += " It is about halfway closed.";
    break;
  case 56..79:
    desc += " It is more than half closed.";
    break;
  case 80..93:
    desc += " It is almost fully closed.";
    break;
  case 94..99:
    desc += " Barely more than a crack remains open";
    break;
  case 100..1000:
    desc += " It is completely closed.";
    break;
  }
  tell_object(TP, desc);
  if (objectp(room)){
    view = room->query_short();
    switch(closed){
    case 0..79:
      tell_object(TP, "%^BLUE%^You can see through to:%^RESET%^");
      tell_object(TP, view);
      tell_object(TP, (string)room->query_short_exits());
      tell_object(TP,(string)room->describe_living_contents(({})));
      desc = (string)room->describe_item_contents(({}));
      break;
    case 80..99:
      tell_object(TP,"%^BLUE%^You can just about see through to:%^RESET%^");
      tell_object(TP, view);
      tell_object(TP,(string)room->query_short_exits());
     tell_object(TP,(string)room->describe_living_contents(({})));
      desc = (string)room->describe_item_contents(({}));
      break;
    default:
      desc = "%^BLUE%^You can't see through it.%^RESET%^";
    }
  }  
  return desc;
}

