//Coded by Lujke

#include <std.h>
#include "../tecqumin.h"
#define OBNAMES ({"stick", "pole", "chest", "sword", "hammer", "mace", "shield", "plate", "banded", "block", "brick", "polearm", "halberd", "awlpike", "lance", "bastard", "bardiche", "rapier", "longsword", "lucern", "axe", "club", "star", "fork", "spear", "staff", "pick", "scythe", "rake", "fauchard", "sickle", "spetum", "shortsword", "longsword", "trident", "wakizashi", "katana", "khopesh", "warhammer", "quarterstaff", "longbow", "crossbow", "shortbow", "bow", "barding", "bronze", "wooden", "helm", "drum", "lute", "lyre", "fiddle", "mandolin", "basket", "lantern", "table", "wood", "block"})

inherit OBJECT;

string exit_room;

string long_desc();

void create(){
  ::create();
  set_id( ({"rent", "void", "inner rent", "tear", "rift"}) );
  set_short("A rent in the fabric of reality");
  set_long( (:TO, "long_desc" :) );
  set_weight(50000);
}

void init(){
  ::init();
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

void set_exit_room(string rm){
  exit_room = rm;
}

string query_exit_room(){
  return exit_room;
}

int wedge(string str){
  string rift, what, verb, *ids;
  int num, i, count, flag;
  object ob, outer_rift, rift_room;
  rift_room = find_object_or_load(exit_room);
  if (!objectp(rift_room)){
    tell_object(TP, "Sorry, there is a problem with the room the rift"
      +" should be opening into. Please make a bug report.");
    return 1;
  }
  outer_rift = present("rift", rift_room);
  if (!objectp(outer_rift)){
    tell_object(TP, "Sorry, there is a problem with the other side of"
      +" the rift. Please make a bug report.");
    return 1;
  }
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
    ob->move(outer_rift);
    outer_rift->add_wedge(ob);
  } else {
    tell_object(TP, ob->query_short() + " isn't really suitable for"
      +" wedging the rift open");
    return 1;
  }
  return 1;
}

string long_desc(){
  object room, rift;
  int closed;
  string desc, view;
//  tell_object(TP, "Preparing to develop long description");
  desc = "A jagged %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ar"
    +"%^RESET%^ in reality opens out into the %^ORANGE%^real world%^RESET%^."
    +" %^MAGENTA%^Purple%^RESET%^ strands and%^MAGENTA%^"
    +" s%^BOLD%^p%^RESET%^%^MAGENTA%^a%^BLUE%^r%^MAGENTA%^ks%^RESET%^ of"
    +" %^BOLD%^%^YELLOW%^energy%^RESET%^ dance around the edges, where the"
    +" weirdness of %^BLUE%^Outside%^RESET%^ contacts the%^CYAN%^"
    +" normal %^ORANGE%^world%^RESET%^.";
//  tell_object(TP, "Finding exit room: " + exit_room);
  room = find_object_or_load(exit_room);
  if (!objectp(room)){
    return desc;
  }
  if (objectp(room)){
    rift = present("outer rent", room);
    if (objectp(rift)){
      closed = rift->query_closed();
    }
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
  }
  desc += "
";
  if (objectp(room)){
    view = room->query_short();
    switch(closed){
    case 0..79:
      desc += "%^BLUE%^You can see through to:%^RESET%^";
      desc +="
";
      desc += view;
      desc+= (string)room->query_short_exits();
      desc +="
";
      desc += (string)room->describe_living_contents(({}));
      desc +="
";
      desc += (string)room->describe_item_contents(({}));
      break;
    case 80..99:
      desc +="
";
      desc += "%^BLUE%^You can just about see through to:%^RESET%^";
      desc +="
";
      desc += view;
      desc += (string)room->query_short_exits();
      desc +="
";
      desc += (string)room->describe_living_contents(({}));
      desc +="
";
      desc += (string)room->describe_item_contents(({}));
      break;
    default:
      desc +="
";
      desc += "%^BLUE%^You can't see through it.%^RESET%^";
    }
  }  
  return desc;
}

