//Coded by Lujke


#include <std.h>
#include "../tecqumin.h"
inherit OBJECT;
object harness;
string entry_point, exit_point, anchor_point, anchor_room;

void create() {
  ::create();
  set_name("vine");
  set_id( ({"vine", "tethered vine", "tether" }) );
  set_short("tethered length of vine");
  set_weight(2000);
  set_long( (:TO, "long_desc":) );
  entry_point = "none";
  exit_point = "none";
  anchor_point = "none";
}

void init(){
  ::init();
  add_action("untie", "untie");
  add_action ("attach", "attach");
  add_action ("attach", "tie");
  add_action("gather", "gather");
  add_action("pull_me", "pull");
  if (objectp(harness) && objectp(environment(TO)) 
      && objectp(environment(harness)) 
      && environment(TO)==environment(harness)){
    if (living(ETO)){
      tell_object(TP, "You tidy the %^GREEN%^v%^ORANGE%^i%^GREEN%^n"
        +"%^ORANGE%^e ro%^GREEN%^p%^ORANGE%^e %^RESET%^away with the"
        +" rest of the %^GREEN%^h%^ORANGE%^a%^GREEN%^rn%^ORANGE%^e"
        +"%^GREEN%^ss");
      tell_room(ETP, TPQCN + " tidies the %^GREEN%^v%^ORANGE%^i"
        +"%^GREEN%^n%^ORANGE%^e ro%^GREEN%^p%^ORANGE%^e %^RESET%^away"
        +" with the rest of the %^GREEN%^h%^ORANGE%^a%^GREEN%^rn"
        +"%^ORANGE%^e%^GREEN%^ss", TP);
    }
    harness->remove_vine( TO );
    remove();
  }
}

int pull_me(string str){
  object carrier, holder, opponent,* vines, start_room, 
                                                targ_room, obs;
  int i, count, mystr, oppstr, mysize, oppsize, myroll, opproll,
                                    j, obcount, myvine, oppvine;
  string exit_name, room_name;
  if (!id(str)){
    return notify_fail("Pull what?");
  }
  //find who you are pulling against
  carrier = environment(harness);
  vines = harness->query_vines();
  count = sizeof(vines);
  if(count>0){
    for (i=0;i<count;i++){
      if (objectp(vines[i])){
        holder = environment(vines[i]);
        if (objectp(holder) && living(holder) && holder!=TP){
          oppvine = i;
          break;
        }
      }
    }
  }
  if (objectp(holder) && living(holder) && holder!=TP){
    opponent = holder;
  } else {
    if (objectp(carrier) && living(carrier) && carrier!=TP){
      opponent = carrier;
      oppvine = sizeof(vines)-1;
    }
  }
  if (!objectp(opponent)){
    tell_object(TP, "There is no-one carrying the other end of the"
      +" %^GREEN%^v%^ORANGE%^i%^GREEN%^ne%^RESET%^. You can just"
      +" %^CYAN%^gather%^RESET%^ it up");
    return 1;
  }
  //SO now you know who you are going to pull against, see whether you can pull them.
  mysize = TP->query_size();
  oppsize = opponent->query_size();
  mystr = TP->query_stats("strength");
  oppstr = opponent->query_stats("strenth");
  myroll = random(30);
  opproll = random(30);
  if ((mysize*10)+ mystr + myroll >(oppsize * 10) + oppstr + opproll){
    tell_object(TP, "You haul on the %^GREEN%^v%^ORANGE%^i%^GREEN%^ne"
      +"%^RESET%^, and drag it toward you");
    if (objectp(ETP)){
      tell_room(ETP, TPQCN + " hauls on the %^GREEN%^v%^ORANGE%^i"
        +"%^GREEN%^ne%^RESET%^, and drags it toward " + TP->QO, TP);
    }
    myvine = member_array(TO, vines);
    start_room = environment(opponent);
    if (!objectp(start_room)){
      tell_object(TP, "There's a problem with the room the other person"
        +" is in. Please make a bug report.");
      return 1;
    }
    if (myvine > oppvine || (objectp(environment(opponent)) 
                            && environment(opponent)->is_vacuum())){
      exit_name = vines[oppvine]->query_exit_point();
    } else {
      exit_name = vines[oppvine]->query_entry_point();
    }
    if (exit_name=="none"){
      tell_object(TP, "There seems to be a problem with the vine you are"
        +" trying to pull. Please make a bug report.");
      return 1;
    }
    room_name = start_room->query_exit(exit_name);
    if (room_name=="/d/shadowgate/void"){
      tell_object(TP, "There is a problem with the exit identified by"
        +" the vine you are trying to pull. Please make a bug report");
      return 1;
    }
    targ_room = find_object_or_load(room_name);
    if (!objectp(targ_room)){
      tell_object(TP, "There seems to be a problem with the room you are"
        +" trying to pull the other person into. Please make a bug"
        +" report.");
      return 1;
    }
    obs = all_inventory(start_room);
    obcount = sizeof(obs);
    if (obcount>0){
      for (j=obcount -1; j >=0;j--){
        if (member_array(obs[j], vines)){
          vines -= ({obs[j]});
          obs[j]->remove();
        }
      }
      harness->set_vines(vines);
    }
    tell_object(opponent, "You are dragged into another room by the"
      +" %^GREEN%^v%^ORANGE%^i%^GREEN%^ne%^RESET%^ you are attached to");
    if (objectp(environment(opponent))){
      tell_room(environment(opponent), (string)opponent->QCN + " is"
        +" dragged into another room by the %^GREEN%^v%^ORANGE%^i"
        +"%^GREEN%^ne%^RESET%^ " + opponent->QS + " is attached to",
                                                               opponent);
    }
    tell_room(targ_room, (string)opponent->QCN + " is dragged in by a"
      +" %^GREEN%^v%^ORANGE%^i%^GREEN%^ne %^ORANGE%^ro%^GREEN%^p"
      +"%^ORANGE%^e%^RESET%^ that " + opponent->QS + " is attached to.");
    opponent->move(targ_room);
    opponent->force_me("look");
  } else{
    tell_object(TP, "You try to pull the %^GREEN%^v%^ORANGE%^i%^GREEN%^"
      +"ne %^RESET%^toward you, but you can't overcome the resistance at"
      +" the other end!");
    tell_room(ETP, TPQCN + "tries to pull the %^GREEN%^v%^ORANGE%^i"
      +"%^GREEN%^ne %^RESET%^toward " + TP->QO +  ", but can't overcome"
      +" the resistance at the other end!");
    tell_object(opponent, "Someone tries to drag you toward them using"
      +" the %^GREEN%^v%^ORANGE%^i%^GREEN%^ne, but you are able to"
      +"d resist!");
    if (objectp(environment(opponent))){
      tell_room(environment(opponent), (string)opponent->QCN + " jerks"
        +" as the %^GREEN%^v%^ORANGE%^i%^GREEN%^ne " + opponent->QS 
        + " is attached to is pulled hard.", opponent);
    }
  }
}

int gather_harness(object gatherer){
  object * vines, room;
  int num, i, count;
  vines = harness->query_vines();
  count = sizeof(vines);
  if (count<1){
    tell_object(gatherer, "There seems to be a problem with the"
      +" harness attached to this vine. Please make a bug report");
    return 1;
  }
  num = member_array(TO, vines);
  if (num ==-1){
    tell_object(gatherer, "There seems to be a problem with the"
      +" %^GREEN%^v%^ORANGE%^i%^GREEN%^ne%^RESET%^ you are holding."
      +" Please make a bug report");
    return 1;
  }
  if (num>=count-1){
    if (!present(harness, ETO) 
         && (!objectp(EETO)||!present(harness, EETO))){
      tell_object(gatherer, "There seems to be a problem with this"
        +" vine. There should be a harness around here somewhere...");
      remove();
    }
    tell_object(gatherer, "You have one end of the vine, and the"
      +" harness is right here. You can just pick it up!");
    return 1;
  }
  tell_object(gatherer, "You gather up the %^GREEN%^v%^ORANGE%^i"
    +"%^GREEN%^ne%^RESET%^, dragging a %^GREEN%^v%^ORANGE%^i%^GREEN%^"
    +"ne %^ORANGE%^h%^GREEN%^a%^ORANGE%^rn%^GREEN%^e%^ORANGE%^ss"
    +" %^RESET%^into the room with you");
  if (objectp(environment(gatherer))){
    tell_room(environment(gatherer), (string)gatherer->QCN 
      +" %^RESET%^gathers up the %^GREEN%^v%^ORANGE%^i%^GREEN%^"
      +"ne%^RESET%^, dragging a %^GREEN%^v%^ORANGE%^i%^GREEN%^ne"
      +" %^ORANGE%^h%^GREEN%^a%^ORANGE%^rn%^GREEN%^e%^ORANGE%^ss"
      +" %^RESET%^into the room with you", gatherer);
  }
  if (count<1){
    tell_object(TP, "There don't seem to be any vines linked to the harness");
  }
  if (count<num+1){
    tell_object(TP, "There don't seem to be any vines other than this one");
  }
  for (i=count-1;i>num;i--){
    room = environment(vines[i]);
    if (objectp(room)){
      tell_room(room, "A %^GREEN%^v%^ORANGE%^i%^GREEN%^ne %^1ORANGE%^"
        +"h%^GREEN%^a%^ORANGE%^rn%^GREEN%^e%^ORANGE%^ss%^RESET%^"
        +" bumps past you as someone gathers up the"
        +" %^GREEN%^v%^ORANGE%^i%^GREEN%^ne %^RESET%^from elsewhere");
    }
//    vines -= ({vines[i]});
    vines[i]->remove();
  }
  harness->set_vines( ({}) );
  if (living(ETO)){
    if (objectp(environment(ETO))){
      harness->move(environment(ETO));
    } else {
      tell_object(gatherer, "There's a problem with the room the person"
        +" holding the harness is in. Please make a bug report.");
    }
  } else {
    harness->move(ETO);
  }
  return 1;
}

int gather(string str){
  int dir, i, num, count;
  object * vines, carrier, room;
  if (!str || !id(str)){
    return notify_fail("What are you trying to gather?");
  }
////////This section is just for test purposes////////
  vines = harness->query_vines();
  count = sizeof(vines);
  num = member_array(TO, vines);
  tell_object(TP, "This is vine number " + num + " of " + count);
  for (i=0;i<count;i++){
    room = environment(vines[i]);
    tell_object(TP, "Vine number " + i + " is in: " + file_name(room));
  }
  room = environment(harness);
  tell_object(TP, "The harness is in: " + file_name(room));
////////////////// End of test section////////////////
  if (anchor_point!=("none")){
    if (objectp(harness) && objectp(environment(harness))){ 
      if (living(environment(harness))){
        if (environment(harness)!=TP){
          tell_object(TP, "The vine is attached to something at one"
            +" end. You can't gather it up. You could perhaps <pull>"
            +" it, if whoever has the other end doesn't resist too"
            +" much");
        }
      } else {
        return gather_harness(TP);
      }
    } else {
      tell_object(TP, "There's a problem with the harness the vine"
        +" is attached to. Self-destructing... Please make a bug"
        +" report");
      remove();
    }
  } else {
    if (objectp(harness)){
      vines = harness->query_vines();
      count = sizeof(vines);
      num = member_array(TO, vines);
      if (count<1 || num == -1){tell_object(TP, "There's an ERROR with this"
        +" vine. Removing it. Please make a bug report");
        call_out("remove", 1);
        return 1;
      }
      if (num==0){
        carrier = environment(harness);
        if (objectp(carrier)){
          if (living(carrier)){
            if (carrier == TP){
              return 0;
/*              tell_object(TP, "You pick up the end of the %^GREEN%^v"
                +"%^ORANGE%^i%^GREEN%^ne %^RESET%^and tidy it away.");
              if (objectp(ETP)){
                tell_room(ETP, TPQCN + " picks up the end of the %^GREEN%^v"
                  +"%^ORANGE%^i%^GREEN%^ne %^RESET%^and tidies it away with "
                  + TP->QP + " %^ORANGE%^h%^GREEN%^a%^ORANGE%^rn%^GREEN%^e"
                  +"%^ORANGE%^ss of %^GREEN%^v%^ORANGE%^i%^GREEN%^nes", TP);
              }             
              call_out("remove", 1);
              return 1; */
            }
            tell_object(TP, "You have hold of one end of the vine. Someone"
              +" else has the other. You cannot gather the vine, but you"
              +" could try to <pull> the other end toward you.");
            return 1;
          } else {
            return gather_harness(TP);
          }
        } 
      } else {
        if ((string)harness->query_anchor_point() != "none"){
          tell_object(TP, "Anchor point is NOT 'none'");
          if (objectp(environment(harness))){
            tell_object(TP, "Testing harness environment for livingness");
            if ( living(environment(harness))){
              if (environment(harness)==TP){
                tell_object(TP, "The %^GREEN%^v%^ORANGE%^i%^GREEN%^ne"
                  +" %^RESET%^is tied to something. You will need to go"
                  +" back and untie it.");
                return 1;
              }
              tell_object(TP, "Harness environment is living");
              tell_object(TP, "You have hold of one end of the vine."
                +" Someone else has the other. You cannot gather the vine,"
                +" but you could try to <pull> the other end toward you.");
              return 1;
            } else {
              tell_object(TP, "Harness environment is NOT living");
              return gather_harness(TP);
            }
          } else {
            tell_object(TP, "There is a problem with the room the harness"
              +" is in. Please make a bug report");
            return 1;
          }
        } else {
          tell_object(TP, "You gather up the loose vines");
          tell_room(ETP, TPQCN + " gathers up the loose vines", TP);
          for (i=count-1;i>=num + 1;i--){
            if (!objectp(vines[i])) continue;
            vines -= ({vines[i]});
            room = environment(vines[i]);
            if (objectp(room)){
              tell_room(room, "The vine slithers past as it is gathered up"
                +" from elsewhere", TP);
              vines[i]->remove();
            } else {
              vines[i]->remove();
            }
          }
          harness->set_vines(vines);
          return 1;
        }
      }
    } else {
      tell_object(TP, "There seems to be a problem with the harness"
        +" this vine was attached to. It slithers out of your grasp"
        +" and disappears");
      remove();
    }
  }
  return 0;
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
  if (anchor_point != "none"){
    return notify_fail("The vine is already attached to something. You'll"
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
  set_anchor_point(what);
  set_anchor_room(file_name(ETP));  
  return 1;
}

int move(mixed dest) { 
  if(objectp(dest) && dest->is_room()) { 
    dest->set_had_players(5);
  } 
  return ::move(dest); 
}

void set_entry_point(string pt){
  entry_point = pt;
}

string query_entry_point(){
  return entry_point;
}

void set_exit_point(string pt){
  exit_point = pt;
}

string query_exit_point(){
  return exit_point;
}

string query_anchor_point(){
  return anchor_point;
}

void set_anchor_point(string pt){
  anchor_point = pt;
}

object query_anchor_room(){
  return anchor_room;
}

void set_anchor_room(string rm){
  anchor_room = rm;
}

int untie(string str){
  string anchor, vine;
  int num;
  if (!objectp(harness)){
    tell_object(TP, "There's a problem with the harness this vine is attached to ");
    return 1;
  }
  if (!str){
    return notify_fail("What do you want to untie from what?");
  }
  num = sscanf(str, "%s from the %s", vine, anchor);
  if (num <2) {
    num = sscanf(str, "%s from a %s", vine, anchor);
  }
  if (num <2) {
    num = sscanf(str, "%s from %s", vine, anchor);
  }
  if (num <2 || !id(vine)){
    return notify_fail("What do you want to untie from what?");
  }
  if (anchor_room != file_name(ETO)){
    tell_object(TP, "You aren't at the end of the vine. You"
      +" can't untie it from here.");
    return 1;
  }
  if (anchor_point == "none"){
    tell_object(TP, "The vine is not tied to anything");
    return 1;
  }
  if (anchor != anchor_point){
    tell_object(TP, "The vine is tied to the " + anchor_point);
    return 1;
  }
  tell_object(TP, "You untie the vine from the " + anchor_point);
  tell_room(ETP, TPQCN + " unties the vine from the " 
                                             + anchor_point, TP);
  anchor_point = "none";
  if (objectp(harness)){
    harness->set_anchor_point("none");
  }
  set_weight(1);
  return 1;
}

string long_desc(){
  string desc, * anchor_path;
  object room, carrier;
  int i, count;
  if (!objectp(harness)){
    tell_object(TP, "There was a problem with the vine. Please"
      +" make an error report, pointing an accusatory claw at"
      +" Lujke");
    remove();
  }
  desc = "%^ORANGE%^The %^GREEN%^t%^ORANGE%^w"
    +"%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^s%^ORANGE%^t%^GREEN%^e"
    +"%^ORANGE%^d v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^e"
    +"%^RESET%^%^ORANGE%^s form a strong and resilient rope.";
  if (stringp(anchor_room) && anchor_room == file_name(ETO)){
    desc += " One end is tied here to the " + anchor_point + ".";
  }
  carrier = environment(harness);
  if (objectp(carrier) && objectp(ETO) && present(carrier, ETO)){
    if (carrier == TP){
      desc += " One end is attached to your harness.";
    } else {
      desc += " One end is attached to " + carrier->QCN 
         + "'s harness.";
    }
  }
  if (carrier == ETO){
    desc += " One end is attached to the harness on the ground.";
  }
  if (entry_point != "none"){
    desc += " One end stretches off to the " + entry_point + ".";
    if (exit_point != "none"){ 
      desc += " The other continues to the " + exit_point + ".";
    }    
  } else { 
    if (exit_point != "none"){ 
      desc += " One end stretches off to the " + exit_point + ".";
    }    
  }
  if (anchor_point == "none" && entry_point == "none"){
    if (exit_point == "none" && carrier != environment(TO) 
                             && !present(carrier, environment(TO))){
      tell_object(TP, "There was a problem with what the vine was"
        +" attached to. Please make an error report, pointing an"
        +" accusatory claw at Lujke");
      remove();
    }
    desc += " One end trails limply on the ground.";
  }
  return desc;
}

void set_harness(object harn){
  harness = harn;
}

object query_harness(){
  return harness;
}