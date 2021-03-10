#include <std.h>
#include "../../tecqumin.h"
inherit WEAPON;



object payload, bucket;
int sprung, target;
string query_number();
int load_me(string str);

create(){
  ::create();
  set_overallStatus(1);
  sprung = 0;
  target = NO_TARGET;
  set_name("catapult");
  set_id(({"catapult","war engine","wooden catapult"}));
  set_short("A large wooden catapult");
  set_long( (:TO, "long_desc" :) );
  set_weight(1000);
  set_value(200);
  set_size(4);
  bucket = find_object_or_load(TABAXOBJ + "bucket1");
  bucket->set_catapult(TO);
}

void init(){
  ::init();
  add_action("load_me", "load");
  add_action("arm_me", "arm");
  add_action("arm_me", "crank");
  add_action("arm_me", "wind up");
  add_action("arm_me", "tension");
  add_action("aim_me", "aim");
  add_action("aim_me", "target");
  add_action("fix_me", "fix");
  add_action("fix_me", "weaponsmith");
  add_action("fire_me", "fire");
  add_action("fire_me", "release");
  add_action("fire_me", "loose");
  
}

string long_desc(){
  string desc;
  desc = "%^ORANGE%^This is a single-armed torsion %^RESET%^catapult%^ORANGE%^. Its firing arm is"
        +" powered by a large skein of twisted ropes. A heavy racheted %^RESET%^lever%^ORANGE%^ serves"
        +" to tension the arm, and an %^BOLD%^%^BLACK%^iron band%^RESET%^%^ORANGE%^ secures it into"
        +" place, only to be knocked away when the time comes to fire the thing. The ropes are made"
        +" from some form of %^RESET%^sinew%^ORANGE%^, which has good elastic properties.\n";
  if (query_overallStatus()<81){
    desc += "%^RESET%^The catapult appears to be unkempt and inoperative through lack of use. The"
           +" sinewed ropes are slack and fraying, and the securing band for the firing arm is twisted"
           +" out of shape.\n";
  }
  if (sprung >4){
    desc += "%^RESET%^ The firing arm is pulled back into position, and the securing band is holding"
           +" it in place.\n";
  }
  if (objectp(payload)){
    desc += " The catapult is loaded with " + (string)payload->query_short() + "%^RESET%^ and is ready"
           +" to fire.\n";
  }
  switch (target){
  case NO_TARGET:
    desc += "%^RESET%^It doesn't appear to be aimed anywhere in particular.";
    break;
  case LOW_FIELD:
    desc += "%^RESET%^It appears to be aimed toward the lower field, beyond the walls.";
    break;
  case MAIN_FIELD:
    desc += "%^RESET%^It appears to be aimed toward the main maize field, beyond the walls.";
    break;
  case HIGH_FIELD:
    desc += "%^RESET%^It appears to be aimed toward the high field, beyond the walls.";
    break;
  }
  return desc;
}

object query_bucket(){
  return bucket;
}

void set_bucket(object buck){
  bucket = buck;
}

string query_number(){
  int i, num;
  object room, *stuff;
  room = ETO;
  if (!objectp(room)){
    return "error";
  }
  stuff = all_inventory(room);
  num = 0;
  for(i=0;i<sizeof(stuff);i++){ 
    if (stuff[i]->id("catapult")){
      num ++;
    }
    if (stuff[i]==TO){
      switch(num){
      case 1:
        return "first";
      case 2:
        return "second";
      case 3:
        return "third";
      default: 
        return "%^BOLD%^%^RED%^error 1%^RESET%^";
      }
    }
  }
  return "%^BOLD%^%^RED%^error 2%^RESET%^";
}

void broadcast(string str){
  int i;
  object tower, battlement;
  tower = find_object_or_load(TABAXROOM + "watchtower");
  battlement = ETO->query_battlement();
  if (objectp(tower)){
    tell_room(tower, str);
  }
  if (objectp(battlement)){
    tell_room(battlement, str);
  }
}

int fire_me(string str){
  string payname, msg, fieldname, fromname;
  object * critters, * casualties, targ, tower, battlement;
  int i, weight, hits, hp;
  if (!stringp(str) || str != "catapult"){
    return 0;
  }
  if (present(str, ETO) != TO){
    notify_fail("There's no "+ str+ " here.");
    return 0;
  }
  if (sprung <5){
    tell_object(TP, "The catapult is not tensioned. You can't fire it yet. You would need to"
                   +" %^BOLD%^%^YELLOW%^<tension catapult>%^RESET%^ first.");
    return 1;
  }
  tell_object(TP, "You release the catapult.");
  tell_room(ETO, TPQCN + "%^RESET%^ releases the catapult.", TP);
  switch (target){
  case LOW_FIELD:
    targ = find_object_or_load(TABAXROOM + "low_field");
    fieldname = "the low field";
    break;
  case MAIN_FIELD:
    targ = find_object_or_load(TABAXROOM + "main_field");
    fieldname = "the main field";
    break;
  case HIGH_FIELD:
    targ = find_object_or_load(TABAXROOM + "high_field");
    fieldname = "the high field";
    break;
  }
  if (!objectp(targ)){
    tell_room(ETO, "%^ORANGE%^The catapult is not aimed anywhere specific and fires off useslessly"
                  +" into the middle of nowhere.");
    sprung = 0;
    payload = 0;
    return 1;
  }
  if (!objectp(payload)){
    tell_room(ETO, "%^BOLD%^%^CYAN%^The catapult bucks and unleashes a massive %^RED%^CRACK%^CYAN%^,"
                  +" as it fires without a payload");
    sprung = 0;
    return 1;
  } else {
    if (interactive(payload)){
      tell_room(ETO, "With a mighty CRACK and THWUMP, the catapult launches " + (string)payload->QCN 
                   + " toward " + (string)targ->query_name());
    } else {
      tell_room(ETO, "With a mighty CRACK and THWUMP, the catapult launches " 
                 + (string)payload->query_name() + " toward " + (string)targ->query_name());
    }
  }
  payname = payload->query_name();
  critters = all_living(targ);
  casualties = ({});
  switch(payname){
  case "rocks":
     tell_room(ETO, "%^BOLD%^%^CYAN%^A barrage of %^RESET%^%^ORANGE%^rocks%^BOLD%^%^CYAN%^ fly up over"
                   +" the stockade wall. The ground %^BOLD%^%^RED%^SHAKES %^CYAN%^as they %^RED%^SLAM"
                   +" %^CYAN%^down out of sight on the other side..");
     tell_room(targ, "%^BOLD%^%^CYAN%^A barrage of %^RESET%^%^ORANGE%^rocks%^BOLD%^%^CYAN%^ flies up"
                   +" from the other side of the stockade wall, crashing down with lethal force all"
                   +" around you.");
     if (sizeof(critters)>0){
       for (i=0;i<sizeof(critters);i++){
         if (random(3)<1){
           casualties += ({critters[i]});
           tell_object(critters[i], "%^BOLD%^%^RED%^You get hit on the head with a large chunk of"
                                    +" rock!");
           tell_room(targ, (string)critters[i]->QCN + " gets hit on the head with a large chunk of"
                          +" rock!",  critters[i]);
           hp = 100 + random(200);
           if (critters[i]->id("orog") || critters[i]->id("tabaxi")){ hp *=1.75;}
           critters[i]->do_damage(critters[i]->return_target_limb(),hp);
           critters[i]->add_attacker(TO);
           critters[i]->continue_attack();
           if(objectp(critters[i]))    critters[i]->remove_attacker(TO);
         }
       }
     }     
     payload->remove();
     break;
  case "hot rocks":
     tell_room(ETO, "%^BOLD%^%^CYAN%^A barrage of %^BOLD%^%^RED%^hot rocks%^BOLD%^%^CYAN%^ fly up over"
                   +" the stockade wall. The ground %^BOLD%^%^RED%^SHAKES %^CYAN%^as they %^RED%^SLAM"
                   +" %^CYAN%^down out of sight on the other side..");
     tell_room(targ, "%^BOLD%^%^CYAN%^A barrage of %^BOLD%^%^RED%^hot rocks%^BOLD%^%^CYAN%^ flies up"
                   +" from the other side of the stockade wall, crashing down with lethal force all"
                   +" around you.");
     if (sizeof(critters)>0){
       for (i=0;i<sizeof(critters);i++){
         if (random(3)<1){
           casualties += ({critters[i]});
           tell_object(critters[i], "%^BOLD%^%^RED%^You get hit on the head with a large chunk of"
                                    +" %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d hot"
                                    +" r%^RESET%^%^RED%^o%^BOLD%^%^RED%^ck!");
           tell_room(targ, (string)critters[i]->QCN + " gets hit on the head with a large chunk of"
                                    +" %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d hot"
                                    +" r%^RESET%^%^RED%^o%^BOLD%^%^RED%^ck!",  critters[i]);
           hp = 150 + random(210);
           if (critters[i]->id("orog") || critters[i]->id("tabaxi")){ hp *=1.75;}
           critters[i]->do_damage(critters[i]->return_target_limb(),hp);
           critters[i]->add_attacker(TO);
           critters[i]->continue_attack();
           if(objectp(critters[i]))    critters[i]->remove_attacker(TO);
         }
       }
     }
     payload->remove();
     break;
  case "sand":
     tell_room(ETO, "%^BOLD%^%^CYAN%^A cloud of %^RESET%^%^ORANGE%^sand%^BOLD%^%^CYAN%^ flies up over"
                   +" the stockade wall and disappears.");
     tell_room(targ, "%^BOLD%^%^CYAN%^A cloud of biting sand flies out at you from the stockade wall");
     if (sizeof(critters)>0){
       for (i=0;i<sizeof(critters);i++){
         if (random(3)<2){
           casualties += ({critters[i]});
           tell_object(critters[i], "%^BOLD%^%^RED%^You get %^RESET%^%^ORANGE%^sand %^BOLD%^%^RED%^"
                                    +"in your eyes!");
           tell_room(targ, (string)critters[i]->QCN + " gets sand in " + (string)critters[i]->QP 
                           + " eyes" ,  critters[i]);
           critters[i]->set_tripped(random(3)+1, "Your eyes are burning and searing with"
                                  +" pain!");
           critters[i]->set_temporary_blinded(3+ random(4));
         }
       }
     }
     payload->remove();
     break;
  case "hot sand":
     tell_room(ETO, "%^BOLD%^%^CYAN%^A cloud of %^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t s%^RESET%^"
                   +"%^ORANGE%^a%^RED%^n%^BOLD%^%^RED%^d%^BOLD%^%^CYAN%^ flies up over"
                   +" the stockade wall and disappears.");
     tell_room(targ, "%^BOLD%^%^CYAN%^A cloud of %^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t s%^RESET%^"
                   +"%^ORANGE%^a%^RED%^n%^BOLD%^%^RED%^d%^BOLD%^%^CYAN%^ flies out at you from behind"
                   +" the stockade wall");
     if (sizeof(critters)>0){
       for (i=0;i<sizeof(critters);i++){
         if (random(3)<2){
           casualties += ({critters[i]});
           tell_object(critters[i], "%^BOLD%^%^RED%^You get h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
                                +" s%^RESET%^%^ORANGE%^a%^RED%^n%^BOLD%^%^RED%^d in your eyes!");
           tell_room(targ, (string)critters[i]->QCN + " gets %^BOLD%^%^RED%^ hot sand%^RESET%^ in " 
                           + (string)critters[i]->QP + " eyes" ,  critters[i]);
           critters[i]->set_tripped(random(4)+2, "Your eyes are burning and searing with"
                                  +" pain!");
           critters[i]->set_blind(1);
         }
       }
     }
     payload->remove();
     break;
  default:
    tell_room(ETO, (string)payload->QCN + " flies out of the catapult and over the stockade wall.");
    tell_object(payload, "You are fired out of the catapult and over the stockade wall!");
    i = random(100);
    if (i < sizeof(critters)){
      casualties += ({critters[i]});
      tell_object(critters[i], "BOLD%^%^RED%^" + (string)payload->QCN + "%^BOLD%^%^RED%^ comes flying"
                             +" over the stockade wall and crashes into you!");
      if (interactive(payload)){
        tell_object(payload, "%^BOLD%^%^RED%^The catapult fires you over the wall and you crash into "
                      + (string) critters[i]->query_short());
        weight = payload->query_player_weight();
      } else {
        weight = payload->query_weight();
      }
      hp = weight *2  + random(weight *2);
      if (critters[i]->id("orog") || critters[i]->id("tabaxi")){ hp *=1.75;}
      critters[i]->do_damage(critters[i]->return_target_limb(),hp);
      critters[i]->add_attacker(TO);
      critters[i]->continue_attack();
      if(objectp(critters[i]))    critters[i]->remove_attacker(TO);
    } else {
      if (interactive(payload)){
        tell_object(payload, "%^BOLD%^%^RED%^The catapult fires you over the stockade wall and you"
                           +" CRASH into the ground!");
      }
      tell_room(targ, (string)payload->QCN + "%^BOLD%^%^CYAN%^Comes flying over the stockade wall and" 
                     +" crashes into the ground!", payload);
    }
    if (objectp(payload)){
      payload->move(targ);
    }
    if (interactive(payload)){
      payload->do_damage(payload->return_target_limb(),150 + random(200));
      payload->add_attacker(TO);
      payload->continue_attack();
      if(objectp(payload))    payload->remove_attacker(TO);
    }    
  }
  if (objectp(payload)){
    msg = "A catapult in " + (string)ETO->query_short() + "%^RESET%^ fires " 
            + (string)payload->query_short() + "%^RESET%^ into " + fieldname 
            + "%^RESET%^."; 
  } else {
    msg = "A catapult in " + (string)ETO->query_short() + "%^RESET%^ fires " 
            + payname + "%^RESET%^ into " + fieldname 
            + "%^RESET%^."; 
  }
  if (sizeof(casualties)>0){
    if (sizeof(casualties ==1)){
      msg += " One person is hit.";
    } else {
      hits = sizeof(casualties);
      msg += hits + " people are hit.";
    }
  }
  broadcast(msg);
  sprung = 0;
  payload = 0;
  return 1;
}


int fix_me(string str){
  int skill;
  string what;
  if (!stringp (str) || id(str)<1){
    return 0;
  }
  skill = TP->query_skill("craft, weaponsmith");
  if (skill <10){
    tell_object(TP, "This job is a bit beyond you, really. Maybe if you found someone more skilled in"
                   +" working on weapons, they might be able to help?");
    return 1;
  }
  if (query_verb() != "weaponsmith"){
    tell_object(TP, "You could probably %^BOLD%^%^YELLOW%^<repair>%^RESET%^ the catapult");
    return 1;
  }
  return 0;  
}

int arm_me(string str){
  string verb;
  verb = query_verb();
  if (!stringp (str) || strlen(str)<1 || present(str, ETO)!= TO ){
    notify_fail( "You might be able to <" + verb +" catapult>");
    return 0;
  }
  if (TP->query_property("busy") >0){
    tell_object(TP, "You are busy doing something else at the moment");
    return 1;
  }
  if (query_overallStatus() < 81){
    tell_object(TP, "The catapult is not in good enough condition to be armed at the moment. Try to"
                   +" tension it and you'd probably just end up breaking something.");
    return 1;
  }
  if (sprung > 4){
    if (!objectp(payload)){
      tell_object(TP, "The catapult is already armed.");
      return 1;
    } 
    tell_object(TP, "The catapult is already armed and loaded");
    return 1;
  }
  tell_object(TP, "%^ORANGE%^You crank the lever and begin winding the catapult up to full tension.");
  tell_room(ETO, "%^ORANGE%^" +TPQCN + "%^RESET%^%^ORANGE%^ begins cranking the lever to wind the"
                +" catapult up to full tension", TP);
  TP->set_property("busy", 1);
  call_out("arm2", 4, TP);
  return 1;
}

void arm2(object who){
  if (!objectp(who) ||!objectp(ETO)){
    return;
  }
  if (!present(who, ETO)){
    tell_object(who, "You have left the area of the catapult, so you stop tensioning it.");
    who->remove_property("busy");
    return;
  }
  sprung ++;
  if (sprung>4){
    tell_object(who, "%^ORANGE%^You finish tensioning the catapult and it locks into place with a"
                   +" CLUNK");
    tell_room(ETO, "%^ORANGE%^" + TPQCN+ "%^RESET%^%^ORANGE%^ finishes tensioning the catapult and it"
                  +" locks into place with a CLUNK", who);
    if (who->id("tabaxi")){
      who->force_me("yell Catapohlt fullee tenchoned!");
    }
    who->remove_property("busy");
    return;
  }
  tell_object(who, "%^ORANGE%^You continue cranking the lever, tensioning the catapult.");
  tell_room(ETO, "%^ORANGE%^" + (string)who->QCN+ "%^RESET%^%^ORANGE%^ continues cranking the lever,"
                +" tensioning the catapult.", who);
  call_out("arm2", 2, who);
}

int load_me(string str){
  object cauldron;
  string catapult, what, * ids;
  if (!stringp(str) || sscanf(str, "%s with %s", catapult, what)<2 || !id(catapult)){
    return notify_fail("Try %^BOLD%^%^YELLOW%^<load catapult with [something]>%^RESET%^");
  }
  tell_object(TP, "sscanf successful. About to load%^ORANGE%^ " + catapult+" %^RESET%^with %^ORANGE%^"
              + what);
  if (sprung<5){
    tell_object(TP, "The catapult needs to be tensioned before you can load it.");
    if (TP->id("tabaxi")){
      TP->force_me("yell The catapohlt is not tensioned!");
    }
    return 1;
  }
  if (objectp(payload)){
    tell_object(TP, "The catapult is already loaded with " + (string)payload->query_short());
    return 1;
  }
  what = lower_case(what); 
  switch(what){
  case "me": case "myself": case "self":
    payload = TP;
    TP->move(bucket);
    break;
  case "rocks": case "rock": case "hot rocks": case "hot rock": 
//    tell_object(TP, "attempting to load the catapult with rocks");
    payload = present("rock", ETO);
    if (objectp(payload)){
//      tell_object(TP, "Rocks found in the environment");
      break;
    }
//    tell_object(TP, "No rocks in the environment");
    payload = present("rock", TP);
    if (objectp(payload)){
//      tell_object(TP, "Rocks found in the environment!");
      break;
    }
//    tell_object(TP, "No rocks in you");
    cauldron = present("cauldron", ETO); // see the ../obj/cauldron.c file for details
    if (!objectp(cauldron)){
      break;    
    }
    if ((int)cauldron->query_filled() != ROCKS){
      break;
    }
    switch(cauldron->query_heated()){
    case 0:
      if (interact("hot", what)){
        tell_object(TP, "The rocks in the cauldron aren't hot yet");
        return 1;
      }
      payload = new(TABAXOBJ + "rock");
    case 1:   
      payload = new(TABAXOBJ + "hotrock");
    }
    cauldron->set_filled(0);
    break;
    case "sand": case "hot sand":
    cauldron = present("cauldron", ETO); // see the ../obj/cauldron.c file for details
    if (!objectp(cauldron)){
      break;    
    }
    if ((int)cauldron->query_filled() != SAND){
      break;
    }
    switch(cauldron->query_heated()){
    case 0:
      if (interact("hot", what)){
        tell_object(TP, "The sand in the cauldron isn't hot yet");
        if (TP->id("tabaxi")){
          TP->force_me("yell Thee sand is not hot enuff yet!");
        }
        return 1;
      }
      payload = new(TABAXOBJ + "sand");
    case 1:   
      payload = new(TABAXOBJ + "hotsand");
    }
    cauldron->set_filled(0);
    
    break;
  }
  if (!objectp(payload)){ 
    payload = present(what, TP);
  }
  if (!objectp(payload)){ 
//    tell_object(TP, "Payload invalid. Checking the environment");
    payload = present(what, ETO);
  }
  if (!objectp(payload)){
//    tell_object(TP, "Payload still invalid");
    tell_object(TP, "You don't have any " + what + " to load into the catapult.");
    if (TP->id("tabaxi")){
      TP->force_me("yell We don't haff any " + what + " to load thee catapohlt with!");
    }
    return 1;
  }
  if (payload ==TP){
    tell_object(TP, "You climb into the bucket of the catapult, and wonder whether this is a good"
                   +" idea");
    tell_room(ETO, TPQCN + "%^RESET%^ climbes into the bucket of the catapult. Brave or stupid? You"
                          +" decide.", TP);
    TP->move(bucket);
    TP->force_me("look");
    return 1;
  }
  if (interactive(payload) && payload->query_bound()==0 && payload->query_unconscious()==0){
    tell_object(TP, (string)payload->QCN + "%^RESET%^ probably won't let you do that. A living being"
                 +" would need to load themselves into the catapult, unless they were bound or"
                 +" unconscious.");
    return 1;
  }
  if (objectp(cauldron)){
    tell_object(TP, "You load the catapult with " + (string)payload->query_name()+ " from"
                   +" the cauldron.");
    tell_room(ETO, TPQCN + "%^RESET%^ loads the catapult with "
                  + (string)payload->query_short() + "%^RESET%^ from the cauldron.", TP);
    return 1;
  }
  tell_object(TP, "You load the catapult with " + (string)payload->query_name()+ ".");
  if (TP->id("tabaxi")){
    TP->force_me("yell Catapohlt readee too fire!");
  }
  tell_room(ETO, TPQCN + "%^RESET%^ loads the catapult with "+ (string)payload->query_short()
                + ".",TP);
  payload->move(bucket);
  return 1;
}

int aim_me(string str){
  string what, tg;
  if (!stringp (str) || strlen(str)<1 || sscanf(str, "%s at %s", what, tg)<2 || TO->id(what)<1){
    tell_object(TP, "You might be able to %^BOLD%^%^YELLOW%^<aim catapult at target>%^RESET%^");
    return 1;
  }
  if (query_overallStatus() < 81){
    tell_object(TP, "The catapult is not in good enough condition to be fired at the moment. Not much"
                   +" point aiming it at anything.");
    return 1;
  }
  switch(lower_case(tg)){
  case "lower field":
    target = LOW_FIELD;
    tell_object(TP, "You begin adjusting the catapult to aim at the lower field");
    if (objectp(ETO)){
      tell_room(ETO, TPQCN + " begins making adjustments to the aiming of the " + query_number() 
                   + " catapult.", TP);
    }
    call_out("aim_low", 4 + random(3), TP, tg);
    break;
  case "main field":
    tell_object(TP, "You begin adjusting the catapult to aim at the main field");
    if (objectp(ETO)){
      tell_room(ETO, TPQCN + " begins making adjustments to the aiming of the " + query_number() 
                   + " catapult.", TP);
    }
    call_out("aim_main", 4 + random(3), TP, tg);
    break;
  case "high field":
    tell_object(TP, "You begin adjusting the catapult to aim at the high field");
    if (objectp(ETO)){
      tell_room(ETO, TPQCN + " begins making adjustments to the aiming of the " + query_number() 
                   + " catapult.", TP);
    }
    call_out("aim_high", 4 + random(3), TP, tg);
    break;
  default:
    tell_object(TP, "You can't aim the catapult at " + tg + "%^RESET%^. From here, the catapult"
               +" could be aimed at the main field, the lower field or the high field.");
  }
  return 1;
}

void aim_low(object who, string tgt){
  if (environment(who)!= ETO){
    tell_object(who, "You left the room before finishing aiming the catapult");
    return;
  }
  tell_object(who, "You finish aiming the " + query_number() + " catapult at the " + tgt);
  tell_room(ETO, who->QCN + " finishes adjusting the aim of the "+ query_number() +" catapult.", who);
  target = LOW_FIELD;
}


void aim_main(object who, string tgt){
  if (environment(who)!= ETO){
    tell_object(who, "You left the room before finishing aiming the catapult");
    return;
  }
  tell_object(who, "You finish aiming the " + query_number() + " catapult at the " + tgt);
  tell_room(ETO, who->QCN + " finishes adjusting the aim of the "+ query_number() +" catapult.", who);
  target = MAIN_FIELD;
}

void aim_high(object who, string tgt){
  if (environment(who)!= ETO){
    tell_object(who, "You left the room before finishing aiming the catapult");
    return;
  }
  tell_object(who, "You finish aiming the " + query_number() + " catapult at the " + tgt);
  tell_room(ETO, who->QCN + " finishes adjusting the aim of the "+ query_number() +" catapult.", who);
  target = HIGH_FIELD;
}
