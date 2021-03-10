//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"


inherit OBJECT;

int filled, heated;


void create() {
    ::create();
    filled = 0;
    heated = 0;
    set_name("cauldron");
    set_id( ({"cauldron","pot" }) );
    set_short("%^BOLD%^%^BLACK%^large c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^%^BLACK%^ldron%^RESET%^");
    set_weight(8);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  add_action("heat_me", "heat");
  add_action("fill_me", "fill");
  add_action("empty_me", "empty");
  add_action("pour_me", "pour");
  set_long( (:TO, "long_desc":) );
}

string query_content_string(){
  switch (heated){
  case 0:
    switch(filled){
    case 0:
      return "nothing";
      break;
    case ROCKS:
      return "%^ORANGE%^rocks%^RESET%^";
      break;
    case OIL:
      return "%^BOLD%^%^BLACK%^oil%^RESET%^";
      break;
    case WATERYLIQUID:
      return "%^CYAN%^water%^RESET%^";
    case SAND:
      return "%^ORANGE%^sand%^RESET%^";
    }
    break;
  case 1:
    switch(filled){
    case 0:
      return "nothing";
      break;
    case ROCKS:
      return "%^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
            +" %^RESET%^%^ORANGE%^r%^RED%^o%^ORANGE%^cks%^RESET%^";
      break;
    case OIL:
      return "%^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
            +" %^BOLD%^%^BLACK%^o%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^l%^RESET%^";
      break;
    case WATERYLIQUID:
     return "%^BOLD%^%^BLUE%^b%^CYAN%^o%^BOLD%^%^WHITE%^i%^BLUE%^l%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^ng"
            +" %^BOLD%^%^CYAN%^w%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^t%^BLUE%^e%^BOLD%^%^CYAN%^r"
            +"%^RESET%^";
    case SAND:
      return "%^ORANGE%^h%^RED%^0%^ORANGE%^t s%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^nd%^RESET%^";
    }
    break;
  }
}

void douse_me(object ob, object room, object field){
  int hp;
  switch (heated){
  case 0:
    switch(filled){
    case 0:
      return;
    case ROCKS:
      tell_object(ob, "A bunch of %^ORANGE%^rocks%^RESET%^ hit you on the head!");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets hit on the head with"
                      +" %^ORANGE%^rocks%^RESET%^!", ob);
      hp = 30 + random(30);
      ob->do_damage(ob->return_target_limb(),hp);
      ob->add_attacker(TO);
      ob->continue_attack();
      if(objectp(ob)){
        ob->remove_attacker(TO);
      }
      if (file_name(ob)==MOB + "orog" && random (5)>3){
        tell_room(field, (string)ob->QCN + "%^RESET%^ falls off the wall!");
        ob->die();
        return;
      }
      break;
    case OIL:
      tell_object(ob, "You get sluiced with %^BOLD%^%^BLACK%^o%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^.");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets sluiced with"
                      +" %^BOLD%^%^BLACK%^o%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^.", ob);
      if (file_name(ob)==MOB + "orog" && random (5)>3){
        tell_room(field, (string)ob->QCN + "%^RESET%^ slips and falls off the wall!");
        ob->die();
        return;
      }
      break;
    case WATERYLIQUID:
      tell_object(ob, "You get doused with %^CYAN%^w%^RESET%^a%^CYAN%^ter%^RESET%^ from above");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets doused with %^CYAN%^w%^RESET%^a%^CYAN%^ter",
                            ob);
      if (file_name(ob)==MOB + "orog" && random (7)>5){
        tell_room(field, (string)ob->QCN + "%^RESET%^ slips and falls off the wall!");
        ob->die();
        return;
      }
      break;
    }
    case SAND:
      tell_object(ob, "Someone pours %^ORANGE%^sand%^RESET%^ on your head from above. Weird. It's all"
                     +" in your hair now.");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets %^ORANGE%^sand%^RESET%^ poured on " 
                     + (string)ob->QP + " head.", ob);
    break;
  case 1:
    switch(filled){
    case 0:
      return;
    case ROCKS:
      tell_object(ob, "A bunch of %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
                     +" %^RESET%^%^ORANGE%^r%^RED%^o%^ORANGE%^cks%^RESET%^ hit you on the head!");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets hit on the head with"
                     +" %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
                     +" %^RESET%^%^ORANGE%^r%^RED%^o%^ORANGE%^cks%^RESET%^!", ob);
      hp = 100 + random(80);
      ob->do_damage(ob->return_target_limb(),hp);
      ob->add_attacker(TO);
      ob->continue_attack();
      if(objectp(ob)){
        ob->remove_attacker(TO);
      }
      if (file_name(ob)==MOB + "orog" && random (3)>1){
        tell_room(field, (string)ob->QCN + "%^RESET%^ falls off the wall!");
        ob->die();
        return;
      }
      break;
    case OIL:
      tell_object(ob, "%^BOLD%^%^RED%^S%^RESET%^%^RED%^ea%^BOLD%^%^RED%^r%^RESET%^%^RED%^i%^BOLD%^"
                     +"%^RED%^ng h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t %^BOLD%^%^BLACK%^o%^RESET%^"
                     +"%^RED%^i%^BOLD%^%^BLACK%^l%^RESET%^ sluices down from the top of the wall,"
                     +" %^RED%^b%^BOLD%^%^RED%^u%^RESET%^%^RED%^rn%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng"
                     +"%^RESET%^ you badly!");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets doused in %^BOLD%^%^RED%^s%^RESET%^%^RED%^ea"
                     +"%^BOLD%^%^RED%^r%^RESET%^%^RED%^i%^BOLD%^%^RED%^ng h%^RESET%^%^RED%^o%^BOLD%^"
                     +"%^RED%^t %^BOLD%^%^BLACK%^o%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^l%^RESET%^!", ob);
      hp = 100 + random(120);
      ob->do_damage(ob->return_target_limb(),hp);
      ob->add_attacker(TO);
      ob->continue_attack();
      if(objectp(ob)){
        ob->remove_attacker(TO);   
      }  
      if (file_name(ob)==MOB + "orog" && random (2)>0){
        tell_room(field, (string)ob->QCN + "%^RESET%^ falls off the wall!");
        ob->die();
        return;
      }
      break;
    case WATERYLIQUID:
      tell_object(ob, "You get doused with %^CYAN%^w%^RESET%^a%^CYAN%^ter%^RESET%^ from above");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets doused with %^CYAN%^w%^RESET%^a%^CYAN%^ter",
                            ob);
      if (file_name(ob)==MOB + "orog" && random (7)>5){
        tell_room(field, (string)ob->QCN + "%^RESET%^ slips and falls off the wall!");
        ob->die();
        return;
      }
      break;
    case SAND:
      tell_object(ob, "Someone pours %^RED%^h%^BOLD%^o%^RESET%^%^RED%^t %^ORANGE%^s%^RED%^a"
                     +"%^ORANGE%^nd%^RESET%^ on your head!");
      tell_room(field, (string)ob->QCN + "%^RESET%^ gets doused with"
                +" %^RED%^h%^BOLD%^o%^RESET%^%^RED%^t %^ORANGE%^s%^RED%^a%^ORANGE%^nd%^RESET%^", ob);
      hp = 30 + random(50);
      ob->do_damage(ob->return_target_limb(),hp);
      ob->add_attacker(TO);
      ob->continue_attack();
      if(objectp(ob)){
        ob->remove_attacker(TO);
      }
      if (file_name(ob)==MOB + "orog" && random (5)>3){
        tell_room(field, (string)ob->QCN + "%^RESET%^ slips and falls off the wall!");
        ob->die();
        return;
      }
      break;
    }
  }
}

int pour_me(string str){
  string filename, what, who, contents;
  object room, field, * climbers, * removals, climber;
  int i;
  filename = TABAXROOM + "battlement";
  if (filled ==0){
    return notify_fail("There is nothing in the cauldron to pour");
  }
  switch (filled){
    case ROCKS:
      contents = "rocks";
      break;
    case OIL:
      contents = "oil";
      break;
    case WATERYLIQUID:
      contents = "water";
      break;
    case SAND:
      contents = "sand";
      break;
  }
  room = ETO;
  if (!objectp(room)){return 0;}
  if (interactive(room)){
    room = EETO;
  }
  if (!objectp(room)){return 0;}
  if (file_name(room)[0..strlen(filename)-1] == filename){
    if (sscanf(str, "%s on %s", what, who)<2){
      return notify_fail("Try %^BOLD%^%^YELLOW%^'pour <what> on climbers'%^RESET%^");
    }
    if (what != contents){
      tell_object(TP, "Try %^BOLD%^%^YELLOW%^<pour " + contents + " on climbers>%^RESET%^, if there"
                     +" is anyone climbing the wall");
      return 1;
    } 
    if (who != "climbers"){
      tell_object(TP, "Try %^BOLD%^%^YELLOW%^<pour " + contents + " on climbers>%^RESET%^, if there"
                     +" is anyone climbing the wall");
      return 1;
    }
    field = (object)room->query_field();
    if (!objectp(field)){
      tell_object(TP, "There's been a problem with the room outside the stockade. Please make a bug"
                     +" report, or tell Lujke he's a silly draconian.");
      return 1;
    }
    climbers = all_living(field);
    if (sizeof(climbers)>0){
      removals = ({});
      for (i=0;i<sizeof(climbers);i++){
        climber = climbers[i];
        if (field->query_climb_positions(climber)<1){
          removals += ({climber});
        }
      }
      if (sizeof(removals)>0){
        climbers -= removals;
      }
      if (sizeof(climbers)>0){
        tell_object(TP, "You pour the " + query_content_string() + " down over the attackers climbing"
                       +" the outside of the wall");
        tell_room(room, TPQCN + "%^RESET%^pours " + query_content_string() + " down over the attackers"
                       +" climbing the outside of the wall", TP);
        if (filled == WATERYLIQUID && heated == 1){
          tell_room(room, "The water %^CYAN%^cools%^RESET%^ down before it hits any of the climbers");
        }
        tell_room(field, "%^BOLD%^%^RED%^Someone pours "+ query_content_string() + "%^BOLD%^%^RED%^"
                        +" over everyone climbing the wall!");
        for (i=0;i<sizeof(climbers);i++){
          douse_me(climber, room, field);
        }
      }
    }
  }
}

int empty_me(string str){
  object contents, room;
  if (!stringp(str)){
    return notify_fail("empty what?");
  }
  if (!id(str)){
    return notify_fail("You could empty the cauldron");
  }
  tell_object(TP, "You tip the contents of the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u"
                 +"%^BOLD%^%^BLACK%^ldron%^RESET%^ out onto the ground");
  if(objectp(ETP)){
    tell_room(ETP, TPQCN + "%^RESET%^ tips the contents of the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a"
                 +"%^RESET%^u%^BOLD%^%^BLACK%^ldron%^RESET%^ out onto the ground", TP);
  }
  room = ETO;
  if (!objectp(room)||interactive(room)){
    filled = 0;
  }
  switch (filled){
    case ROCKS:
      if (heated ==1){
        contents = new (TABAXOBJ + "hot_rocks");
      } else{
        contents = new (TABAXOBJ + "rocks");
      }
      break;
    case OIL:
      if (heated == 1){
        tell_room(ETO, "The %^BOLD%^%^RED%^hot %^RESET%^oil out seeps into the ground.");
      } else {
        tell_room(ETO, "The oil out seeps into the ground.");
      }
      break;
    case WATERYLIQUID:
      if (heated == 1){
        tell_room(ETO, "%^BOLD%^%^BLUE%^The %^BOLD%^%^RED%^hot%^BOLD%^%^BLUE%^ water seeps into the ground.");
      } else {
        tell_room(ETO, "%^BLUE%^The water seeps into the ground.");
      }
      break;
    case SAND:
      if (heated ==1){
        contents = new (TABAXOBJ + "hot_rocks");
      } else{
        contents = new (TABAXOBJ + "rocks");
      }
      break;
  }
  if (objectp(contents)){
    contents->move(room);
  }
  filled= 0;
  return 1;
}

int heat_me(string str){
  object room, brazier;
  string * stuff;
  int i;
  if (!objectp(ETO)){ return 0;}
  room = ETO;
  if (!id(str)){
    tell_object(TP, "Try %^BOLD%^%^YELLOW%^<heat cauldron>");
    return 1;
  }
  if (interactive(room)){
    tell_object(ETO, "Probably not a good idea while carrying it");
    return 1;
  }
  if (filled == 0){
    tell_object(TP, "It would probably be sensible to put something in the cauldron first");
    return 1;
  }
  if (room == (find_object_or_load(TABAXROOM + "kitchen"))){
    tell_object(TP, "You begin heating the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                   +"%^BLACK%^ldron%^RESET%^ over the %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^"
                   +"%^RED%^re %^BOLD%^%^BLACK%^p%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t");
    tell_room(room, TPQCN + "%^RESET%^ begins heating the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a"
                   +"%^RESET%^u%^BOLD%^%^BLACK%^ldron%^RESET%^ over the %^BOLD%^%^RED%^f%^RESET%^"
                   +"%^RED%^i%^BOLD%^%^RED%^re %^BOLD%^%^BLACK%^p%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t",
                    TP);
    call_out("heat2", 10);
    return 1;
  }
  stuff = keys(room->query_items());
  if (sizeof(stuff)>0){
    if (member_array("fire", stuff)!=-1 || member_array("fireplace", stuff)!= -1 
                            || member_array("campfire", stuff)!=-1){
      tell_object(TP, "You begin heating the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                     +"%^BLACK%^dron%^RESET%^ on the %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^"
                     +"%^RED%^re%^RESET%^");
      tell_room(room, TPQCN + "%^RESET%^ begins heating the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a"
                     +"%^RESET%^u%^BOLD%^%^BLACK%^dron%^RESET%^ on the %^BOLD%^%^RED%^f%^RESET%^"
                     +"%^RED%^i%^BOLD%^%^RED%^re%^RESET%^", TP);
      call_out("heat2", 12);
     return 1;
    }
  }
  brazier = present("brazier", room);
  if (!objectp(brazier)){
    tell_object(TP, "There doesn't seem to be anything here you could heat the%^BOLD%^%^BLACK%^"
                   +" c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^%^BLACK%^ldron%^RESET%^ on");
    return 1;
  }
  if (brazier->query_lit() ==0){
    tell_object(TP, "You probably need to light the %^BOLD%^%^BLACK%^br%^RESET%^%^RED%^a%^BOLD%^"
                   +"%^BLACK%^z%^RED%^i%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r before you can do that");
    return 1;
  }
  tell_object(TP, "You begin heating the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                   +"%^BLACK%^ldron%^RESET%^ over the %^BOLD%^%^BLACK%^br%^RESET%^%^RED%^a%^BOLD%^"
                   +"%^BLACK%^z%^RED%^i%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r");
  tell_room(room, TPQCN + "%^RESET%^ begin2 heating the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a"
                   +"%^RESET%^u%^BOLD%^%^BLACK%^ldron%^RESET%^ over the %^BOLD%^%^BLACK%^br%^RESET%^"
                   +"%^RED%^a%^BOLD%^%^BLACK%^z%^RED%^i%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r", TP);
  call_out("heat2", 12);
  return 1;
}

void set_filled(int fill){
  filled = fill;
}

int query_filled(){
  return filled;
}

void set_heated(int heat){
  heated = heat;
}

int query_heated(){
  return heated;
}

void heat2(){
  object room, brazier;
  string * stuff;
  int i, num, flag;
  if (!objectp(ETO)){ return;}
  room = ETO;
  if (interactive(room)){
    tell_object(ETO, "The cauldron won't heat while you are carrying it");
    return 1;
  }
  stuff = keys(room->query_items());
  flag = -1;
  if (sizeof(stuff)>0){
    if (member_array("fire", stuff)==-1 && member_array("fireplace", stuff)== -1 
                            && member_array("campfire", stuff)==-1){
      flag = 1;
    }
  }
  num = sizeof(all_inventory(room));
  if (flag <1 && num >0){ 
    for (i=1;i<num+1;i++){
      brazier = present("brazier " + i, room);
      if (!objectp(brazier)){ 
        break;
      }
      if ((int)brazier->query_lit()==1){ 
        flag = 1;
        break;
      }
    }            
  }
  if (flag <1){
    tell_room(room, "The cauldron no longer has a heat source, so it stops heating up");
    return;
  }
  heated = 1;
  tell_room(room, "The contents of the cauldron are well %^BOLD%^%^RED%^h%^RESET%^%^RED%^ea%^BOLD%^"
                 +"%^RED%^t%^RESET%^%^RED%^e%^BOLD%^%^RED%^d%^RESET%^ now");
}

int fill_me(string str){
  object room, * stuff, content;
  string what, contents, * items;
  int i, flag;
  if (!stringp(str)){
    return notify_fail("You might be able to fill the cauldron %^BOLD%^%^YELLOW%^with%^RESET%^"
                      +" something");
  }
  sscanf(str, "%s with %s", what, contents);
  if (!id(what)){
    return notify_fail ("Try %^BOLD%^%^YELLOW%^'fill cauldron with <something>'%^RESET%^");
  }
  if (!stringp(contents)){
    tell_object(TP, "Try %^BOLD%^%^YELLOW%^'fill cauldron with <something>'%^RESET%^");
    return 1;
  }
  room = ETO;
  if (!objectp(room)){
    tell_object(TP, "There's a problem with the cauldron's environment. Please accept our apologies"
                   +"and make a bug report, if you are not dead already. If you are dead already,"
                   +" please make a posthumous bug report. Have a nice day.");
    return 1;
  }
  if (interactive(room)){
    room = EETO;
    if (!objectp(room)){
      tell_object(TP, "There's a problem with the cauldron's environment. Please accept our apologies"
                   +"and make a bug report, if you are not dead already. If you are dead already,"
                   +" please make a posthumous bug report. Have a nice day.");
      return 1;
    }
  }
  items = keys(room->query_items());
  stuff = all_inventory(room) + all_inventory(TP);
  flag = -1;
  if (member_array(contents, items)!=-1){
    flag = 1;
  }
  if (sizeof(stuff)>0){
    for (i=0;i<sizeof(stuff);i++){
      if (stuff[i]->id(contents)){
        content = stuff[i];
        flag = 1;
        break;
      }
    }
  }
  if (!objectp(content)||flag == -1){
      tell_object(TP, "You can't see any " + contents + " here to fill the cauldron with");
      return 1;
  }
  switch(contents){
    case "rocks":
    case "rock":
    case "stones":
    case "boulder":
    case "boulders":
    case "rubble":  //fall through to here
      tell_object(TP, "You fill the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                     +"%^BLACK%^ldron%^RESET%^ with the %^ORANGE%^r%^RESET%^o%^ORANGE%^cks%^RESET%^"
                     +" you find here");
      tell_room(TO, TPQCN + "%^RESET%^ fills the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u"
                     +"%^BOLD%^%^BLACK%^ldron%^RESET%^ with %^ORANGE%^r%^RESET%^o%^ORANGE%^cks"
                     +"%^RESET%^");
      filled = ROCKS;
      break;
    case "oil":
      tell_object(TP, "You fill the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                     +"%^BLACK%^ldron%^RESET%^ with %^BOLD%^%^BLACK%^oil%^RESET%^. Slicky, sticky"
                     +" oil.");
      tell_room(TO, TPQCN + "%^RESET%^ fills the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u"
                     +"%^BOLD%^%^BLACK%^ldron%^RESET%^ with %^BOLD%^%^BLACK%^oil%^RESET%^.");
      filled = OIL;
      break;
    case "water":
      tell_object(TP, "You fill the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                     +"%^BLACK%^ldron%^RESET%^ with %^CYAN%^water%^RESET%^. Going to make the tea?");
      tell_room(TO, TPQCN + "%^RESET%^ fills the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u"
                     +"%^BOLD%^%^BLACK%^ldron%^RESET%^ with %^CYAN%^water%^RESET%^.");
      filled = WATERYLIQUID;
      break;
    case "sand":
      tell_object(TP, "You fill the %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                     +"%^BLACK%^ldron%^RESET%^ with %^ORANGE%^sand%^RESET%^.");
       filled = SAND;
       break;
    default: 
      tell_object(TP, "Sorry, you can't fill the cauldron with that. ");
      return 1;
  }
  if (objectp(content)){
    content->remove();
  }
  return 1;
}

string long_desc(){
  string desc, filename, * stuff, * fillings, *fill_here; // fillings = potential things that could
  int i;                                                 //            go in the cauldron
  object room;                                           // fill_here = fillings present in the room
  desc = "%^BOLD%^%^BLACK%^A large iron c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^%^BLACK%^ldron. ";
  switch (filled){
  case 0:
    desc += "%^RESET%^ It is currently empty";
    break;
  case OIL:
    switch (heated){
    case 0:
      desc += "%^RESET%^ It is filled with %^BOLD%^%^BLACK%^oil%^RESET%^.";
      break;
    case 1:
      desc += "%^RESET%^ It is filled with %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
             +" %^BOLD%^%^BLACK%^o%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^l%^RESET%^.";
      break;
    }
    break;
  case ROCKS:
    switch (heated){
    case 0:
      desc += " %^RESET%^It is filled with %^ORANGE%^rocks%^RESET%^";
      break;
    case 1:
      desc += " %^RESET%^It is filled with %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
             +" %^ORANGE%^r%^RED%^o%^ORANGE%^cks%^RESET%^";
    }
    break;
  case SAND:
    switch (heated){
    case 0:
      desc += " %^RESET%^It is filled with %^ORANGE%^sand%^RESET%^";
      break;
    case 1:
      desc += " %^RESET%^It is filled with %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
             +" %^ORANGE%^s%^RED%^a%^ORANGE%^nd%^RESET%^";
    }
    break;
  case WATERYLIQUID:
    switch (heated){
    case 0:
      desc += " %^RESET%^It is filled with %^CYAN%^water%^RESET%^";
      break;
    case 1:
      desc += " %^RESET%^It is filled with %^BOLD%^%^BLUE%^b%^CYAN%^o%^BOLD%^%^WHITE%^i%^BLUE%^l"
             +"%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^CYAN%^w%^BOLD%^%^WHITE%^a%^RESET%^"
             +"%^CYAN%^t%^BLUE%^e%^BOLD%^%^CYAN%^r";
    }
    break;
  }
  room = ETO;
  if (interactive(room)){
    room = EETO;
  }
  if (!objectp(room)){
    return desc;
  }
  if (present("brazier", room)&& heated == 0){
    desc += "\nYou might be able to %^BOLD%^%^RED%^h%^RESET%^%^RED%^ea%^BOLD%^%^RED%^t%^RESET%^"
           +" the cauldron on the brazier here.";
  } else{
    if (room == find_object_or_load(TABAXROOM + "kitchen")&& heated == 0){
      desc += "\nYou might be able to %^BOLD%^%^RED%^h%^RESET%^%^RED%^ea%^BOLD%^%^RED%^t%^RESET%^"
           +" the cauldron on the fire here.";
    }
  }
  filename = TABAXROOM + "battlement";
  if (file_name(room)[0..strlen(filename)-1] == filename){
    switch(filled){
    case 0:
      break;
    case ROCKS:
      desc += "\nYou could probably %^BOLD%^%^YELLOW%^<pour rocks on climbers>%^RESET%^, if there's"
             +" anyone trying to climb the stockade wall at present";
      break;
    case OIL:
      desc += "\nYou could probably %^BOLD%^%^YELLOW%^<pour oil on climbers>%^RESET%^, if there's"
             +" anyone trying to climb the stockade wall at present";
      break;
    case WATERYLIQUID:
      desc += "\nYou could probably %^BOLD%^%^YELLOW%^<pour water on climbers>%^RESET%^, if there's"
             +" anyone trying to climb the stockade wall at present";
      break;
    case SAND: 
      desc += "\nYou could probably %^BOLD%^%^YELLOW%^<pour sand on climbers>%^RESET%^, if there's"
             +" anyone trying to climb the stockade wall at present";
      break;
    }
  }
  if (filled<1){
    stuff = keys(room->query_items());
    if (sizeof(stuff)>0){
      fillings = ({ "rocks", "rock", "stones", "boulder", "boulders", "rubble", "water", "oil",
                    "sand"});
      fill_here = ({});
      for (i=0;i<sizeof(fillings);i++){
        if (member_array(fillings[i], stuff) != -1){
          fill_here += ({fillings[i]});
        }
      }
      if (sizeof(fill_here)>0){
        desc += "\nYou could fill the cauldron with ";
        for (i=0;i<sizeof (fill_here); i ++){
          if (i>0 && i== sizeof(fill_here)-1){
            desc += " or " + fill_here[i];
            continue;
          }
          if (i>0){
            desc == ", ";
          }
          desc += fill_here[i];
        }
        desc += " here.";
      }
    }
  }
  return desc; 
}
