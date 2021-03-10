// gossip_d.c
//////////////////////////////////////////////////////////////////////
// Coded by Lujke
//////////////////////////////////////////////////////////////////////
// Notes to self
// Rumours work by recognized name - the rumour goes down by the name the subject is known by to the person who first passes it on. True name is recorded in the details of the rumour, to help keep track - but rumours will come out according to those recognised names
// Researching a rumour should lead to a small chance of word getting back to the subject of the rumour that you have been asking about them
// Creating a rumour should lead to a small chance of word getting back to the subject of the rumour that you have been talking about them




#include <std.h>
#include <security.h>
#include <daemons.h>
#include "/daemon/rumours/sources.h"
#define SAVE_DIR "/daemon/save/rumours/"
#define SAVE_FILE "/daemon/save/saved_rumours"
#define RUMOUR "/daemon/rumour.c"

inherit DAEMON;

mapping all_rumours;  // ([ string subject : mapping rumours ]) rumours: ([ string label: mixed details ])
mapping rumour; // ([ int num: ({string subject, int time, int traction, int source_type, int rumour_number })
mapping gossip_times;  //([string gossiper: int * last_gossip_times ])
mapping heard_rumours; //([string subject: mapping heard_rumours]) heard_rumours: ([string heard_label: mixed details])
mapping heard_rumour; // int heard_number: ({string subject_knownas, string truename, string rumour_label)
mapping feedback;

varargs void add_rumour(string subject, string surface, string detail, string secret, string instigator);
varargs mapping query_rumours(string subject, int type);
mixed * query_rumour(string subject, int num);

void create(){
  ::create();
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVE_FILE,1);

}

mixed * query_rumour(string subject, int num){
  mapping my_rumours;
  mixed * result;
  object rum;
  string * subjects, sub, detail, secret, filename;
  int * nums;
  report("query_rumour stage 1");
  if (!mapp(all_rumours) || sizeof(all_rumours)<1) return ({});
  report("query_rumour stage 2");
  subjects = keys(all_rumours);
  sub = subject;
  if (member_array(sub, subjects)==-1) return ({});
  report("query_rumour stage 3");
  my_rumours = all_rumours[sub];
  if (!mapp(my_rumours) || sizeof(all_rumours)<1) return ({});
  report("query_rumour stage 4");
  nums = keys(my_rumours);
  if (member_array(num, nums) ==-1) return ({});
  report("query_rumour stage 5");
//  rum = new(RUMOUR);
  result = my_rumours[num];
  report ("Result loaded. Size of result:" + sizeof(result));
  filename = "/daemon/save/rumours/" + result[RUMOUR_SUBJECT] + result[RUMOUR_NUMBER] + ".o";
  if (file_exists(filename ))
  {
    filename = "/daemon/save/rumours/" + result[RUMOUR_SUBJECT] + result[RUMOUR_NUMBER];
    RUMOUR->LOAD(filename );
  } else
  {
    report ("%^BOLD%^%^GREEN%^Error - file /daemon/save/rumours/" + result[RUMOUR_SUBJECT] + result[RUMOUR_NUMBER] + " does not exist");
  }
  report("query_rumour stage 6");
  report("query_rumour. surface: " + RUMOUR->query_surface() + " detail: " + RUMOUR->query_detail() + " secret: " + RUMOUR->query_secret() + " Number of instigators: " + sizeof(RUMOUR->query_instigator()) + " truename: " + RUMOUR->query_truename());
  result += ({  RUMOUR->query_surface() });
  result += ({  RUMOUR->query_detail() });
  result += ({  RUMOUR->query_secret() });
  result += ({  RUMOUR->query_instigator() });
  result += ({  RUMOUR->query_truename() });
  report("query_rumour stage 7");
  return result;
}

void clear_heard_rumours(){
  tell_object(TP, "%^BOLD%^%^WHITE%^Really? Are you sure you want to delete ALL the heard rumours? This will mean that it will be like no-one has ever heard any rumours...");
  tell_object(TP, "%^ORANGE%^Type %^BOLD%^%^WHITE%^'yes'%^RESET%^%^ORANGE%^ to go ahead - anything else to think again & go and have a bit of a lie down before doing something so drastic");
  input_to("confirm_clear_heard_rumours", 0);
}

void confirm_clear_heard_rumours(string str){
  if (lower_case(str) != "yes") return;
  tell_object(TP, "Okay, ALL heard rumours are cleared. No-one knows nuthin any more!");
  heard_rumours = ([]);
  SAVE();
}

save_rumour_ob(mixed * rum){
  object ob;
  string name, * subjects;
  int num, * nums;
  mapping my_rumours;
//  ob = new(RUMOUR);
  RUMOUR->set_surface(rum[SURFACE]);
  RUMOUR->set_detail(rum[DETAIL]);
  RUMOUR->set_secret(rum[SECRET]);
  RUMOUR->set_instigator(rum[INSTIGATOR]);
  RUMOUR->set_truename(rum[TRUENAME]);
  name = rum[RUMOUR_SUBJECT];
  num = rum[RUMOUR_NUMBER];
  report ("%^BOLD%^%^MAGENTA%^Attempting to save rumour: /daemon/save/rumours/" + name + num);
  RUMOUR->SAVE("/daemon/save/rumours/" + name + num);
  if (!mapp(all_rumours) || sizeof(all_rumours)<1){
    all_rumours = ([]);
    my_rumours = ([]);
  } else {
    subjects = keys(all_rumours);
    if (member_array(name, subjects) == -1)
    {
      my_rumours = ([]);
    } else
    {
      my_rumours = all_rumours[name];
    }
  }
  my_rumours[num] = rum[0..RUMOUR_NUMBER];
  all_rumours[name] = my_rumours;
  SAVE();
}

void convert_rumours(){
  string subject, * subjects;
  int num, * nums;
  mapping rums;
  mixed * rum;
  if (!mapp(all_rumours)||sizeof(all_rumours)<1) return;
  report ("%^BOLD%^%^GREEN%^Converting rumours");
  subjects = keys(all_rumours);
  foreach(subject in subjects)
  {
    rums = all_rumours[subject];
    if (!mapp(rums)|| sizeof(rums)<1) continue;
    nums = keys(rums);
    foreach(num in nums)
    {
      rum = rums[num];
      if (!arrayp(rum) || sizeof(rum)<1) continue;
      report("Saving rumour " + num + " for " + subject);
      save_rumour_ob(rum);
    }
  }
}

mapping query_rumours(string subject, int type){
  string * subjects;
  int nums, num;
  mapping rumours, result;
  if (!mapp (all_rumours) || sizeof(all_rumours)<1) return ([]);
  subjects = keys(all_rumours);
  if (member_array(subject, subjects)==-1) return ([]);
  rumours = all_rumours[subject];
  report("Number of initial rumours found for " + subject + ": " + sizeof(rumours));
  if (intp(type) && type >0)
  {
    report("Type specified when trying to query_rumours");
    report("building list of rumours of the right type");
    result = ([]);
    nums = keys(rumours);
    foreach(num in nums)
    {
      if (rumours[num][SOURCE_TYPE] == type)
      {
        result[num] = rumours[num];
      }
    }
    report ("Finished building list. It has " + sizeof(result) + " members");
    return result;
  }
  return rumours;
}

void leave_feedback(string name, string fb){
  string * subjects;
  mapping feedback_for_subject;
  if (!mapp(feedback)) {
    feedback = ([]);
    feedback_for_subject = ([]);
  } else
  {
    subjects = keys(feedback);
    if (member_array(name, subjects) !=-1)
    {
      feedback_for_subject = feedback[name];
    } else
    {
      feedback_for_subject = ([]);
    }
  }
  feedback_for_subject[time()] = fb;
  feedback[name] = feedback_for_subject;
}

void save_rumour(mixed * rum){
  string subject, subjects;
  int nums, num;
  object ob;
  mapping subject_rumours;
  report("Starting save_rumour");
//  ob = new(RUMOUR);
  subject = rum[RUMOUR_SUBJECT];
  num = rum[RUMOUR_NUMBER];
  if (!mapp(all_rumours) || sizeof(all_rumours)<1)
  {
    all_rumours = ([]);
    subject_rumours = ([]);
  } else
  {
    subjects = keys(all_rumours);
    if (sizeof(subjects)<1 || member_array(subject, subjects)==-1)
    {
      subject_rumours = ([]);
    } else
    {
      subject_rumours = all_rumours[subject];
    }
  }
  RUMOUR->set_surface(rum[SURFACE]);
  RUMOUR->set_detail(rum[DETAIL]);
  RUMOUR->set_secret(rum[SECRET]);
  RUMOUR->set_instigator(rum[INSTIGATOR]);
  RUMOUR->set_truename(rum[TRUENAME]);
  RUMOUR->SAVE("/daemon/save/rumours/" + subject + num);
  report("Saving rumour " + num + " about " + subject);
  subject_rumours[num] = rum[0..RUMOUR_NUMBER];
  all_rumours[subject] = subject_rumours;
  SAVE();
  report ("%^BOLD%^%^GREEN%^Successfully saved rumour");
}

void circulate_rumour(int num, string name, object ob){
  int inf, type, lvl;
  int * instigators, * nums, rumour_num;
  string * subjects, * hearers;
  mixed * rum;
  mapping my_rumours, my_heard_rumours;
  report("Rumours_d circulating rumour. Num: " + num + " Name: " + name + " Circulator: " + ob->query_true_name());
  if (!objectp(ob)) return;
  if (!mapp(heard_rumours)||sizeof(all_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours yet. You'll have to gossip a bit to hear some before you can spread them around");
    return;
  }
  hearers = keys(heard_rumours);
  if (member_array(ob->query_name(), hearers)==-1)
  {
    tell_object(ob, "You haven't heard any rumours yet. You'll have to gossip a bit to hear some before you can spread them around");
    return;
  }
  my_heard_rumours = heard_rumours[ob->query_true_name()];
  if (!mapp(my_heard_rumours)|| sizeof(my_heard_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours yet. You'll have to gossip a bit to hear some before you can spread them around");
    return;
  }
  subjects = keys(my_heard_rumours);
  if(member_array(lower_case(name), subjects)==-1)
  {
    tell_object(ob, "You haven't heard any rumours about " + capitalize(name) + ". You'll either have to dig some dirt on them, or gossip generally until you hear something about them, before you can circulate an existing rumour. Or you could always start a new one, if you like");
    return;
  }
  my_rumours = my_heard_rumours[name];
  if (!mapp(my_rumours) || sizeof(my_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours about " + capitalize(name) + ". You'll either have to dig some dirt on them, or gossip generally until you hear something about them, before you can circulate an existing rumour. Or you could always start a new one, if you like");
    return;
  }
  nums = keys(my_rumours);
  if (member_array(num, nums)==-1)
  {
    tell_object(ob, "You haven't heard a rumour numbered " + num + " about " + capitalize(name) + ". Check your heard rumours list and try again");
    return;
  }
  rum = my_rumours[num];
  lvl = rum[2];
  rumour_num = rum[1];
  rum = query_rumour(name, rumour_num);
  tell_object(ob, "Are you sure you want to circulate this rumour?");
  tell_object(ob, rum[SURFACE]);
  if (lvl >= DETAIL_LVL)
  {
    tell_object(ob, "You have also heard that: ");
    tell_object(ob, rum[DETAIL]);
  }
  if (lvl >= SECRET_LVL)
  {
    tell_object(ob, "It is probably a secret that: ");
    tell_object(ob, rum[SECRET]);
  }
  tell_object(ob,"%^BOLD%^%^WHITE%^Type 'yes' to go ahead and spread the rumour around - anything else to quit");
  input_to("confirm_circulate", 0 ,ob, rum);
}


void quash_rumour(int num, string name, object ob){
  int inf, type, lvl;
  int * instigators, * nums, rumour_num;
  string * subjects, * hearers;
  mixed * rum;
  mapping my_rumours, my_heard_rumours;
  report("Rumours_d quashing rumour. Num: " + num + " Name: " + name + " Quasher: " + ob->query_true_name());
  if (!objectp(ob)) return;
  if (!mapp(heard_rumours)||sizeof(all_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours yet. You'll have to gossip a bit to hear some before you can try to stamp them out");
    return;
  }
  hearers = keys(heard_rumours);
  if (member_array(ob->query_name(), hearers)==-1)
  {
    tell_object(ob, "You haven't heard any rumours yet. You'll have to gossip a bit to hear some before you can try to stamp them out");
    return;
  }
  my_heard_rumours = heard_rumours[ob->query_true_name()];
  if (!mapp(my_heard_rumours)|| sizeof(my_heard_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours yet. You'll have to gossip a bit to hear some before you can try to stamp them out");
    return;
  }
  subjects = keys(my_heard_rumours);
  if(member_array(lower_case(name), subjects)==-1)
  {
    tell_object(ob, "You haven't heard any rumours about " + capitalize(name) + ". You'll either have to dig some dirt on them, or gossip generally until you hear something about them, before you can attempt to quash an existing rumour. Or you could always start a new one, if you like");
    return;
  }
  my_rumours = my_heard_rumours[name];
  if (!mapp(my_rumours) || sizeof(my_rumours)<1)
  {
    tell_object(ob, "You haven't heard any rumours about " + capitalize(name) + ". You'll either have to dig some dirt on them, or gossip generally until you hear something about them, before you can attempt to quash an existing rumour. Or you could always start a new one, if you like");
    return;
  }
  nums = keys(my_rumours);
  if (member_array(num, nums)==-1)
  {
    tell_object(ob, "You haven't heard a rumour numbered " + num + " about " + capitalize(name) + ". Check your heard rumours list and try again");
    return;
  }
  rum = my_rumours[num];
  lvl = rum[2];
  rumour_num = rum[1];
  rum = query_rumour(name, rumour_num);
  tell_object(ob, "Are you sure you want to quash this rumour?");
  tell_object(ob, rum[SURFACE]);
  if (lvl >= DETAIL_LVL)
  {
    tell_object(ob, "You have also heard that: ");
    tell_object(ob, rum[DETAIL]);
  }
  if (lvl >= SECRET_LVL)
  {
    tell_object(ob, "It is probably a secret that: ");
    tell_object(ob, rum[SECRET]);
  }
  tell_object(ob,"%^BOLD%^%^WHITE%^Type 'yes' to go ahead and spread the rumour around - anything else to quit");
  input_to("confirm_quash", 0 ,ob, rum);
}


void confirm_circulate(string str, object ob, mixed * rum){
  int rumnum, inf, trac;
  string * instigators, name, inst_name;
  mixed main_rumour;
  object rum_ob;
  mapping my_rumours;
  if (lower_case(str)!= "yes") return;
  if (!objectp(ob)) return;
  rumnum = rum[RUMOUR_NUMBER];
  name = rum[RUMOUR_SUBJECT];
  if (catch(main_rumour = all_rumours[name][rumnum]))

  {
    tell_object(ob, "Sorry, something went wrong trying to circulate that rumour. Please make a bug report, letting Lujke know that he is a very stable genius");
    return;
  }
  main_rumour = query_rumour(name, rumnum);
//  rum_ob = new(RUMOUR);
  inst_name = ob->query_true_name();
  if (ob->isKnown(inst_name))
  {
    inst_name = ob->knownAs(inst_name);
  }
  RUMOUR->LOAD(name + rumnum);
  instigators = RUMOUR->query_instigator();
  RUMOUR->set_instigator(instigators);
  RUMOUR->SAVE("/daemon/save/rumours/" + rum[RUMOUR_SUBJECT] + rum[RUMOUR_NUMBER]);
  inf = calculate_gossip_skill(ob, main_rumour[SOURCE_TYPE]);
  trac = main_rumour[TRACTION];
  while (trac < inf * 12){
    inf = inf/2;
  }
  trac += inf;
  instigators += ({inst_name});
  main_rumour[TRACTION] = trac;
  main_rumour[INSTIGATOR] = instigators;
  my_rumours = all_rumours[name];
  my_rumours[rumnum] = main_rumour;
  all_rumours[name] = my_rumours;
  tell_object(ob, "You have quiet words with a few interested parties that you think would be likely to pass the rumour on.");
  SAVE();
}


void check_for_feedback(object ob){
  string myname, * subjects;
  mapping my_feedback;
  int * times, inf, i, count, num;
  if (!mapp(feedback) || sizeof(feedback)<1) return;
  subjects = keys(feedback);
  myname = ob->query_name();
  if (member_array(myname, subjects)==-1) return;
  my_feedback = feedback[myname];
  times = keys(my_feedback);
  count = sizeof(times);
  inf = ob->query_skill("influence");
  num = random(inf/15) + 1;
  if (num > count) num = count;
  call_out("give_feedback", 2, ob, num);
}

varargs mapping query_feedback(string subject){
  if (!stringp(subject) || strlen(subject)<1) return feedback;
  return feedback[subject];
}



void give_feedback(object ob, int num){
  int count, n, t, inf, * times, source;
  string fb, sub_name, sub_alias;
  mapping my_feedback;
  report ("Giving feedback");
  if (!objectp(ob)) return;
  my_feedback = feedback[ob->query_name()];
  times = keys(my_feedback);
  count = sizeof(times);
  n = random(count);
  t = times[n];
  fb = my_feedback[t][0];
  source = my_feedback[t][1];
  sub_name = my_feedback[t][2];
  if (ob->isKnown(sub_name)){
    sub_alias = ob->knownAs(sub_name);
  } else
  {
    sub_alias = my_feedback[t][3];
  }
  report ("About to delete case " + t + " from my_feedback");
  my_feedback = map_delete( my_feedback, t);
  inf =   inf = calculate_gossip_skill(ob, source);  //takes into account the objects influece in the sphere where the rumour is circulating
  if (random(200) && random(inf/10)>1)
  {
    tell_object(TP, "You hear a whisper about " + sub_alias);
    tell_object(ob, fb);
  } else {
    report ("Feedback not given due to bad roll");
  }

  feedback[ob->query_name()] = my_feedback;
  SAVE();
  num --;
  if (num>0) call_out("give_feedback", 2+ random(5), ob, num);
  report ("Finished giving feedback");
}

void recall_rumours(object ob){
  string * recallers, recaller, * subs, sub, result, line, name;
  mapping my_heard_rumours;
  int width;
  if (!objectp(ob)) return;
  if (!mapp(heard_rumours)|| sizeof(heard_rumours)<1)
  {
    tell_object(ob, "%^ORANGE%^You have not heard any rumours about anyone");
    return;
  }
  recaller = ob->query_true_name();
  recallers = keys(heard_rumours);
  if (member_array(recaller, recallers)==-1)
  {
    tell_object(ob, "%^ORANGE%^You have not heard any rumours about anyone");
    return;
  }
  my_heard_rumours = heard_rumours[recaller];
  if (!mapp(my_heard_rumours) || sizeof(my_heard_rumours)<1)
  {
    tell_object(ob, "%^ORANGE%^You have not heard any rumours about anyone");
    return;
  }
  subs = keys(my_heard_rumours);
  result = "%^RESET%^%^ORANGE%^You have heard rumours about the following people:\n";
  line = "";
  width = atoi(ob->getenv("SCREEN"));
  foreach(sub in subs)
  {
    name = capitalize(sub) + " ";
    if (strlen(line) + strlen(name) + 1 > width)
    {
      result += line + "\n";
      line = name;
    } else
    {
      line +=  name ;
    }
  }
  if (strlen (name)>3 && line[strlen(line)-4..strlen(line)-1] == name[strlen(name)-4..strlen(name)-1])
  {
    result += line;
  }
  tell_object(ob, result);
}


void set_feedback(string name, string fb, int source_type, string sub_name, string sub_adj){
  string * subjects;
  int * times, when;
  mapping my_feedback;
  if (!mapp(feedback) || sizeof(feedback)<1)
  {
    feedback = ([]);
    my_feedback = ([]);
  } else
  {
    subjects = keys(feedback);
    if (member_array(name, subjects)==-1)
    {
      my_feedback = ([]);
    } else
    {
      my_feedback = feedback[name];
    }
  }
  if (!mapp(my_feedback)) my_feedback = ([]);
  when = time();
  my_feedback[when] = ({fb, source_type, sub_name, sub_adj});
  feedback[name] = my_feedback;
  SAVE();
}

varargs int can_gossip(string subject, int influence){
  int result, inf, * times;
  object ob;
  subject = lower_case(subject);
  if (intp(influence) && influence >-1)
  {
    inf = influence;
  } else
  {
    ob = find_player(subject);
    if (!objectp(ob))
    {
      report("rumours_d next_gossip_time: influence score not valid, and subject '" + subject + "'not available to get new one. Failing");
      return 0;
    }
    inf = ob->query_skill("influence");
  }
  times = delete_old_gossip_times(subject, time()- 259200);

//////////////////////////////////////////////////////////////////
////////CHANGE THIS BACK TO OLD VERION ONCE RUMOURS GO LIVE //////
//  if (sizeof(times) > 3 + inf/8) return 0; //OLD VERSION      //
  if (sizeof(times) > 8 + inf/8) return 0;   //NEW VERSION      //
                                                                //
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

  return 1;
}

void add_gossip_time(string subject){
  string * subjects;
  int * times;
  if (!mapp(gossip_times) || sizeof(gossip_times)<1)
  {
    gossip_times = ([]);
    subjects = ({});
  } else
  {
    subjects = keys(gossip_times);
  }
  subjects = keys(gossip_times);
  if (member_array(subject, subjects)==-1)
  {
    times = ({});
  } else
  {
    times = gossip_times[subject];
  }
  times += ({time()});
  gossip_times[subject] = times;
  SAVE();
}

int * delete_old_gossip_times(string subject, int threshold){
  int * times, t, * result;
  string * subjects;
  if (!mapp(gossip_times) || sizeof(gossip_times)<1)
  {
    gossip_times = ([ subject: ({}) ]);
    return ({});
  }
  subjects = keys(gossip_times);
  if (member_array(subject, subjects) == -1)
  {
    gossip_times[subject] = ({});
    return ({});
  }
  times = gossip_times[subject];
  result = ({});
  foreach(t in times)
  {
    if (t > threshold)
    {
      result += ({t});
    }
  }
  gossip_times[subject] = result;
  SAVE();
  return result;
}

mapping query_all_heard_rumours(){
  return heard_rumours;
}

mapping query_heard_rumours(string hearer){
  string * hearers;
  if (!mapp(heard_rumours) || sizeof(heard_rumours)<1) return ([]);
  hearers = keys(heard_rumours);
  if (member_array(hearer, hearers)==-1) return ([]);
  return heard_rumours[hearer];
}

string * query_subjects(){
  if (!mapp(all_rumours) || sizeof(all_rumours)<1) return ({});
  return keys(all_rumours);
}

mapping query_all_rumours(){
  return all_rumours;
}

void report(string str){

}

int get_next_num_from_array(int nums){
  int num, result;
  result = 1;
  foreach(num in nums)
  {
    if (num>= result) result = num +1;
  }
  return result;
}

int has_heard_rumour(string hearer, mixed * rumour){
  mapping my_heard_rumours, rumours_about_subject;
  mixed * rum;
  int * nums, num, rumour_number, flag;
  string * subjects, subject;
  my_heard_rumours = query_heard_rumours(hearer);
  if (!mapp(heard_rumours) || sizeof(heard_rumours)<1)
  {
    report("hearer has not heard any rumours");
    return 0;
  }
  if (sizeof(rumour)<RUMOUR_SUBJECT+1)
  {
    report("Rumour is too small to have a rumour subject. Size: " + sizeof(rumour));
    return 0;
  }
  subject = rumour[RUMOUR_SUBJECT];
  subjects = keys(my_heard_rumours);
  if (sizeof(subjects)<1 || member_array(subject, subjects)==-1)
  {
    report("hearer has not heard any rumours about subject");
    return 0;
  }
  rumours_about_subject = my_heard_rumours[subject];
  if(sizeof(rumours_about_subject)<1)
  {
    report("Size of rumours about subject is: " + sizeof(rumours_about_subject));
    return 0;
  }
  rumour_number =rumour[RUMOUR_NUMBER];
  if (sizeof(rumours_about_subject)>0){
    nums = keys(rumours_about_subject);
    flag = 0;
    foreach(num in nums)
    {
      rum = rumours_about_subject[num];
      if (sizeof(rum)>0 && rum[1] == rumour_number)
      {
        flag = 1;
        break;
      }
    }
  }
  if(flag==-0)
  {
    report("Hearer has not heard rumour number " + rumour_number + " about " + subject);
    return 0;
  } else
  {
    report("Hearer %^BOLD%^%^RED%^has already heard %^RESET%^rumour number " + rumour_number + " about " + subject);
  }
  return 1;
}

varargs void hear_rumour(string hearer, mixed * rumour, int lvl){
  mapping my_heard_rumours, subject_rumours;
  int * nums, next_num, rumour_number; //, rumour_lvl;
  string * subjects, subject;
  report("hearing rumour");
  if (sizeof(rumour)<RUMOUR_SUBJECT+1)
  {
    report("The rumour is too small to have a subject. Sizeof rumour: " + sizeof(rumour) + "  Rumour subject number: " + RUMOUR_SUBJECT);
  }
  subject = rumour[RUMOUR_SUBJECT];
  rumour_number = rumour[RUMOUR_NUMBER];
  my_heard_rumours = get_my_heard_rumours(hearer);
  if (!intp(lvl) || lvl < 1 || lvl >3) lvl = 1;
  next_num = 0;
  if (!mapp(my_heard_rumours) || sizeof(my_heard_rumours)<1)
  {
    report ("Subject has not heard any rumours. Setting up new mapping");
    my_heard_rumours = ([]);
    subject_rumours = ([]);
    subjects = ({});
    nums = ({});
    next_num = 1;
  } else {
    report ("Subject has heard some rumours before. Getting existing mapping");
    subjects = keys(my_heard_rumours);
    if (member_array(subject, subjects)==-1)
    {
      subject_rumours = ([]);
      nums = (({}));
      next_num = 1;
    } else
    {
      subject_rumours = my_heard_rumours[subject];
      nums = keys(subject_rumours);
      next_num = 0;
    }
  }

  if (arrayp(nums) && sizeof(nums)>0 && next_num<1)
  {
    next_num = get_next_num_from_array(nums);
  }
  rumour = ({subject, rumour_number, lvl});
  subject_rumours[next_num] = rumour;
  my_heard_rumours[subject] = subject_rumours;
  report ("About to save new heard rumour");
  heard_rumours[hearer] = my_heard_rumours;
  SAVE();
}

int get_next_backup_number(){
  string * files, file, junk;
  int num, i, result;
  files = get_dir(SAVE_DIR);
  if (sizeof(files)<1) return 1;
  result = 1;
  foreach(file in files)
  {
    num = sscanf(file, "%s_%d", junk, i);
    if (num>1 && i >= result) result = i+1;
  }
  return result;
}
BACKUP(){
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_DIR + "rumour_backup_" + 1);
    seteuid(getuid());
    return;
}

void SAVE(){
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

int remove_rumour(string subject, int num){
  mapping subject_rumours;
  int nums;
  subject_rumours = query_rumours(subject);
  report("Trying to remove rumour number " + num + " for subject " + subject +"\nNumber of rumours retrieved for subject: " + sizeof(subject_rumours));
  if (sizeof(subject_rumours)<1) return -1;
  report ("Subject does have some rumours");
  nums = keys(subject_rumours);
  report ("Checking whether the rumours include one with the key: " + num);
  if (member_array(num, nums)==-1) return -2;
  report("It did have such a rumour. Removing it now");
  if(sizeof(nums)<2){
    report ("This is the last rumour for " + subject + ". %^BOLD%^%^RED%^Removing subject completely");
    all_rumours = map_delete(all_rumours, subject);
    SAVE();
    return 1;
  }
  subject_rumours = map_delete(subject_rumours, num);
  nums = keys(subject_rumours);
  report ("Checking whether the rumours NOW include one with the key: " + num);
  if (member_array(num, nums)!=-1)  report("It DOES have such a rumour");
  all_rumours[subject] = subject_rumours;
  SAVE();
  return 1;
}

mapping get_my_heard_rumours(string hearer){
  mapping my_heard_rumours;
  string * hearers, * subjects;
  report ("Getting heard rumours for: " + hearer);
  if (!mapp(heard_rumours) || sizeof(heard_rumours)<1)
  {
    report("No heard rumours found for anyone. Starting new mappings");
    heard_rumours = ([]);
    hearers = ({});
  } else
  {
    hearers = keys(heard_rumours);
    report("Some people have heard rumours. Checking whether " + hearer + " has heard any");
  }
  if (sizeof(hearers)<1 || member_array(hearer, hearers)==-1)
  {
    report(hearer + " Has not heard any rumours");
    my_heard_rumours = ([]);
  } else
  {

    my_heard_rumours = heard_rumours[hearer];
    subjects = keys(my_heard_rumours);
    report(hearer + " has heard rumours about " + sizeof(subjects) + " different people. Hurrah!");
  }
  return my_heard_rumours;
}

mapping get_heard_rumours(string hearer, string subject){
  mapping my_heard_rumours, rumours_about_subject;
  string * subjects;
  my_heard_rumours = get_my_heard_rumours(hearer);
  if (sizeof(my_heard_rumours)<1) return ([]);
  subjects = keys(my_heard_rumours);
  if (member_array(subject, subjects)==-1) return ([]);
  rumours_about_subject = my_heard_rumours[subject];
  return rumours_about_subject;
}

int get_next_heard_number(string hearer, string subject){
  mapping rumours_about_subject;
  int * nums, result;
  rumours_about_subject = get_heard_rumours(hearer, subject);
  if (sizeof(rumours_about_subject)<1) return 1;
  nums = keys(rumours_about_subject);
  result = get_next_num_from_array(nums);
  return result;
}

int count_rumours(){
  int count;
  string * subjects, subject;
  mapping my_rumours;
  if (!mapp(all_rumours) || sizeof(all_rumours)<1) return 0;
  count = 0;
  subjects = keys(all_rumours);
  foreach(subject in subjects){
    my_rumours = all_rumours[subject];
    count += sizeof(my_rumours);
  }
  return count;
}

int count_heard_rumours(){
  string * hearers, hearer, *subjects, subject;
  return sizeof("heard_rumours");
}


varargs int add_rumour(string subject, string truename, string * instigator, string surface, string detail, string secret, int source_type, int traction, string adj){
  string  * subjects, * labels, det, sec, * inst, tn, fb;
  int num, st, trac;
  mixed * details;
  mapping rumours;
  object rum;
  report ("Adding a rumour for subject: " + subject);
//  rum = new(RUMOUR);
  if (!mapp (all_rumours) || sizeof(all_rumours)<1)
  {
    all_rumours = ([]);
  }
  if (!stringp(truename)) truename = subject;
  if (!stringp(surface))
  {
    report("No surface rumour to add. Aborting");
    return 0;
  }
  if (!stringp(detail))
  {
    det = "";
  } else
  {
    det = detail;
  }
  if (!stringp(secret))
  {
    sec = "";
  } else
  {
    sec = secret;
  }
  if (!arrayp(instigator))
  {
    inst = ({"no-one"});
  } else
  {
    inst = instigator;
  }
  if (!intp(source_type)){
    st = CITY_SOURCE;
  } else
  {
    st = source_type;
  }
  if (!intp(traction)){
    trac = 50;
  } else
  {
    trac = traction;
  }
  if (!stringp(truename))
  {
    tn = "unknown";
  } else
  {
    tn = truename;
  }
  subjects = keys(all_rumours);
  if (sizeof(subjects)<1 || member_array(subject, subjects)==-1)
  {
    num = 1;
    rumours = ([]);
  } else {
    num = get_next_number(subject);
    rumours = query_rumours(subject);
  }
  RUMOUR->set_surface(surface);
  RUMOUR->set_detail(det);
  RUMOUR->set_secret(sec);
  RUMOUR->set_instigator(inst);
  RUMOUR->set_truename(tn);
  RUMOUR->SAVE("/daemon/save/rumours/" +subject+num);
  details  = ({subject, time(), trac, st, num });
  rumours[num] = details;
  all_rumours[subject] = rumours;
  if (!random(20))
  {
    fb = "They've been gossipping about you ";
    switch(st)
    {
    case CITY_SOURCE:
      "on the streets and in the taverns.";
      break;
    case BEAST_SOURCE:
      "among the beast races";
      break;
    case WILD_SOURCE:
      "with the wild folk and rangers";
      break;

    }
    set_feedback(subject, fb, st, inst, adj);
  }
  SAVE();
  return num;
}

int get_next_number(string subject){
  string * subjects;
  mapping rumours;
  int * nums, result, i, count, num;
  if (!mapp(all_rumours) || sizeof(all_rumours)<1) return 1;
  subjects = keys(all_rumours);
  if (member_array(subject, subjects) == -1) return 1;
  rumours = query_rumours(subject);
  if (sizeof(rumours)<1) return 1;
  count = sizeof(rumours);
  nums = keys(rumours);
  report("About to get next number. Array size: " + sizeof(nums));
  result = get_next_num_from_array(nums);
  return result;
}

varargs mixed * get_rumour_for_subject(string subject, int source, int num){  //returns specified rumour number - if no number specified, returns a random rumour, with chance for each rumour coming up weighted by the amount of traction it has
  mapping rumours, tmp_rumours;
  string * labels;
  mixed * result;
  object ob;
  int trac, total_trac, target,*nums, n;
  tmp_rumours = query_rumours(subject);
  nums = keys(tmp_rumours);
  rumours = ([]);
  foreach(n in nums){
    if (tmp_rumours[n][SOURCE_TYPE] == source || !random(50))
    {
      rumours[n] = tmp_rumours[n];
    }
  }
  if (sizeof(rumours)<1) return ({});
  labels = keys(rumours);
  if (num>0){
    num --;
  } else
  {
    report("No rumour number requested. Getting random rumour");
    total_trac = calculate_total_traction(rumours);
    report("Total traction: " + total_trac);
    trac = 0;
    target = random(total_trac);
    for (num = 0;num<sizeof(labels); num++){
      trac += calculate_traction(rumours[labels[num]]);
      report ("New trac score: " + trac);
      if (trac>target) break;
      report("" + trac + " <= " + total_trac + ". Continuing...");
    }
  }
  result = rumours[labels[num]];
//  ob = new(RUMOUR);
  RUMOUR->LOAD(subject + num);
  result += ({RUMOUR->query_subject(), RUMOUR->query_detail(), RUMOUR->query_secret(), RUMOUR->query_instigator(), RUMOUR->query_truename() });
  return result;
}

mapping get_rumours_for_source_type(int source){
  string * subjects, subject;
  mapping rums, result;
  mixed * rumour_details;
  int * nums, num, type, count;
  if (!mapp(all_rumours) || sizeof(all_rumours)<1)
  {
    return ([]);
  }
  subjects = keys(all_rumours);
  count = 1;
  result = ([]);
  report("About to run through rumours for different subjects");
  foreach(subject in subjects)
  {
    report("Getting rumours for subject: " + subject);
    rums = all_rumours[subject];
    if (!mapp(rums) || sizeof(rums)<1)
    {
      continue;
    } else
    {
      nums = keys(rums);
      foreach(num in nums)
      {
        report("Getting rumour number " + count);
        rumour_details = rums[num];
        type = rumour_details[SOURCE_TYPE];
        if (type == source)
        {
          report("This rumour is the right type. Type: " + type);
          result += ([count : rumour_details]);
          count ++;
        } else
        {
          report("Wrong type of source (" + type + "). Checking for random chance");
          if (!random(60))
          {
            report("Rumour came up by chance");
            result += ([count : rumour_details]);
            count ++;
          } else
          {
            report("Rumour did not come up by chance");
          }
        }
      }
    }
  }
  report("Number of rumours found for source type " + source + ": " + sizeof(result));
  return result;
}


mixed * get_rumour(int source, object audience){
  int total_traction, trac, * nums, i, j, count1, count2, temp_trac, flag, rum_num;
  string * subjects;
  mapping my_rumours;
  mixed * rum;
  object ob;
  my_rumours = get_rumours_for_source_type(source);
  total_traction = calculate_total_traction(my_rumours);
  report("get_rumour: total traction calculated: " + total_traction);
  trac = random(total_traction);
  temp_trac = 0;
  if(!mapp(all_rumours) || sizeof(all_rumours)<1) return ([]);
//  subjects = keys(all_rumours);
//  count1 = sizeof(subjects);
//  report ("going through subjects. Target traction: " + trac);
//  for (i=0;i<count1;i++)
//  {
//    sub_num = i;
//    report("subject: " + subjects[i]);
//    rumours = query_rumours(subjects[i]);
//    if (sizeof(rumours)<1) continue;
    rum = ({});
    count2 = sizeof(my_rumours);
    report("" + count2 + " rumours found");
    nums = keys(my_rumours);
    flag = 0;
    for (j=0;j<count2; j++)
    {
      rum = my_rumours[nums[j]];
      temp_trac += calculate_traction(rum);
      report("Rumour " + (j+1) + " temp_trac: " + temp_trac);
      if (temp_trac>=trac)
      {
//        ob - new(RUMOUR);
        RUMOUR->LOAD("/daemon/save/rumours/" + rum[RUMOUR_SUBJECT] + rum[RUMOUR_NUMBER]);
        rum  += ({ RUMOUR->query_subject(), RUMOUR->query_detail(), RUMOUR->query_secret(), RUMOUR->query_instigator(), RUMOUR->query_truename() });
        flag = 1;
        break;
      }
    }
//    if (flag ==1) break;
//  }
//  rum += ({my_rumours[nums[j]]});

  return rum;
}



int calculate_total_traction(mapping my_rumours){
  int i, j, trac, count1, count2, * nums;
  string * subjects;
  mapping rumours;
  mixed * rum;
  if (!mapp(my_rumours)) my_rumours = all_rumours;
  if (!mapp(my_rumours) || sizeof(my_rumours)<1) return 0;
  subjects = keys(all_rumours);
  count1 = sizeof(subjects);
  trac = 0;
  rumours = my_rumours;
  if (sizeof(rumours)<1) return 0;
  nums = keys(rumours);
  count2 = sizeof(nums);
  for (j=0;j<count2;j++)
  {
    rum = rumours[nums[j]];
    trac += calculate_traction(rum);
  }
  return trac;
}

int calculate_traction(mixed * rumour){
  int t, rumour_time, rumour_traction, modifier, result;
  string s;
  t = time();
  rumour_time = rumour[TIME];
  rumour_traction = rumour[TRACTION];
  if(t - rumour_time < 1200) rumour_time = t - 1201;
  s = "" + sqrt((t - rumour_time)/1200);
  modifier = atoi(s);
  if (modifier<1) modifier = 1;
  result = rumour_traction/modifier;
  return result;
}

void clear_rumours(){
  tell_object(TP, "%^BOLD%^%^RED%^Are you really sure you want to clear all the rumours. \n%^BOLD%^%^MAGENTA%^Really? \n%^BOLD%^%^WHITE%^All%^RED%^ of them?\n%^BOLD%^%^BLUE%^Okay, Type %^WHITE%^'Yes'%^BLUE%^ to go ahead, anything else to abort this madness");
  input_to("definitely_clear_rumours", 0);
}

void definitely_clear_rumours(string str){
  if (lower_case(str)=="yes"){
    all_rumours = ([]);
    heard_rumours = ([]);
    BACKUP();
    tell_object(TP, "That's done it. All the rumours are gone. I hope you are happy now. I did save a backup in the save directory, just in case");
    SAVE();
  }
}

int check_got_details(mixed * rumour, object ob){
  int influence, chance_to_learn;
  influence = ob->query_skill("influence");
  return 1;
}

int check_room_source_type(object room){
  string path, *type_paths, type_path, terrain;
  int room_type;
  if (!objectp(room)) return -2;
  path = room->get_path();
  room_type = -1;
  type_paths = BEAST_PATHS;
//  report("Checking for beast paths");
  foreach(type_path in type_paths)
  {
    if(interact(type_path, path))
    {
      room_type = BEAST_SOURCE;
      break;
    }
  }
  if (room_type == -1)
  {
//    report("Not a beast path. Checking for wild paths");
    type_paths = WILD_PATHS;
    foreach(type_path in type_paths)
    {
      if(interact(type_path, path))
      {
        room_type = WILD_SOURCE;
        break;
      }
    }
  }
  if (room_type == -1)
  {
//    report("Not a wild path. Checking for city paths");
    type_paths = CITY_PATHS;
    foreach(type_path in type_paths)
    {
      if(interact(type_path, path))
      {
        room_type = CITY_SOURCE;
        break;
      }
    }
  }
  if (room_type == -1){
//    report("Not Any of the paths. Checking for standard city rooms");
    terrain = room->query_terrain();
    if (terrain == "city" || present("barkeep", room)|| present("waiter", room) ||present("waitress", room) || present("baker", room)|| present("bartender", room)){
      room_type = CITY_SOURCE;
//      report("Standard city room");
    }
    if (interact("forest", terrain) || interact( "jungle", terrain) || interact( "meadow", terrain)|| interact( "scrub", terrain) || interact( "savannah", terrain) || interact( "desert", terrain)|| interact("mountain", terrain ))
    {
      report("Standard %^BOLD%^%^GREEN%^wild%^RESET%^ room");
      room_type = WILD_SOURCE;
    }
  }
  return room_type;
}

void trace_rumour(object ob, string trace_subject, int trace_num){
  int real_rumour_no, nums, skill, room_type;
  string * hearers, subjects, alleged_instigator, * instigators, message;
  mapping my_heard_rumours, rumours_about_subject;
  mixed * real_rumour, * heard_rumour;
  if (!objectp(ob)) return;
  if (!mapp(heard_rumours) || sizeof(heard_rumours)<1)
  {
    tell_object(ob, "Sorry there was an error tracing your rumour. Attempt abandoned. Please use the game command to make a bug report. You can say that Lujke is far to idle to playtest his code properly");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  hearers = keys(heard_rumours);
  if (member_array(lower_case(ob->query_true_name()), hearers)==-1)
  {
    tell_object("Sorry, you don't seem to have heard any rumours, so I don't know how you came to be trying to trace one. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  my_heard_rumours = heard_rumours[lower_case(ob->query_true_name())];
  if (!mapp(my_heard_rumours) || sizeof(my_heard_rumours)<1)
  {
    tell_object("Sorry, you don't seem to have heard any rumours, so I don't know how you came to be trying to trace one. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  subjects = keys(my_heard_rumours);
  if (sizeof(subjects)<1 || member_array(trace_subject, subjects)==-1)
  {
    tell_object("Sorry, you don't seem to have heard any rumours about " + trace_subject + ", so I don't know how you came to be trying to trace one. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  rumours_about_subject = my_heard_rumours[trace_subject];
  if (!mapp(rumours_about_subject) || sizeof(rumours_about_subject)<1)
  {
    tell_object("Sorry, you don't seem to have heard any rumours about " + trace_subject + ", so I don't know how you came to be trying to trace one. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  nums = keys(rumours_about_subject);
  if (member_array(trace_num, nums)==-1)
  {
    tell_object("Sorry, you don't seem to have heard a rumour numbered " + trace_num + " about " + trace_subject + ", so I don't know how you came to be trying to trace it. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  heard_rumour = rumours_about_subject[trace_num];
  if (sizeof(heard_rumour)<1)
  {
    tell_object("Sorry, there was an early problem loading rumour number " + trace_num + " about " + trace_subject + ", so you are not able to trace its origins at this time. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  real_rumour_no = heard_rumour[1];
  real_rumour = query_rumour(trace_subject, real_rumour_no);
  if (!arrayp(real_rumour) || sizeof(real_rumour)< INSTIGATOR +1)
  {
    tell_object("Sorry, there was a late problem loading rumour number " + trace_num + " about " + trace_subject + ", so you are not able to trace its origins at this time. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  instigators = real_rumour[INSTIGATOR];
  if (!arrayp(instigators) || sizeof(instigators)< 1)
  {
    tell_object("Sorry, there was a problem identifying who started rumour number " + trace_num + " about " + trace_subject + ", so you are not able to trace its origins at this time. Please use the game command to make a bug report.");
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
//////DO CHECKS HERE///////////////
  room_type = check_room_source_type(environment(ob));
  if (room_type != real_rumour[SOURCE_TYPE])
  {
    switch (real_rumour[SOURCE_TYPE])
    {
    case CITY_SOURCE:
      tell_object(ob, "You're not really in the right environment to trace the origins of rumour " + trace_num + " about " + trace_subject + ". That rumour seems to be circulating in human allied cities, so you should check there. ");
      break;
    case WILD_SOURCE:
      tell_object(ob, "You're not really in the right environment to trace the origins of rumour " + trace_num + " about " + trace_subject + ". That rumour seems to be circulating among the peoples of the wild, so you should check there. ");
      break;
    case BEAST_SOURCE:
      tell_object(ob, "You're not really in the right environment to trace the origins of rumour " + trace_num + " about " + trace_subject + ". That rumour seems to be circulating among the beast races, so you should check in their places. ");
      break;
    }
    ob->remove_property("tracing");
    ob->remove_property("gossipping");
    return;
  }
  skill =  calculate_gossip_skill(ob, real_rumour[SOURCE_TYPE]);
  if (random(4) || random (150) > skill) return;

///////////////////////////////////


  alleged_instigator = instigators[random(sizeof(instigators))];
  switch(alleged_instigator)
  {
  case "background":
    message = "%^BOLD%^%^WHITE%^ the rumour you are asking about (number " + trace_num + " about " + capitalize(trace_subject) + "%^BOLD%^%^WHITE%^
seems to be old news that just forms part of a lot of people's background knowledge about them. It seems unlikley you'll be able to find a true source for it.";
    break;
  case "general":
    message = "%^BOLD%^%^WHITE%^ the rumour you are asking about (number " + trace_num + " about " + capitalize(trace_subject) + "%^BOLD%^%^WHITE%^
seems to be old news that just forms part of a lot of people's background knowledge about them. It seems unlikley you'll be able to find a true source for it.";
    break;
  default:
    message = "Word reaches you that the rumour that \n" + real_rumour[SURFACE] + "\n may have been started by " + capitalize(alleged_instigator) + " .";
    break;
  }
  tell_object(ob, message);
}

int update_rumours(){
  int count, * nums, num;
  mapping rumours_about_subject;
  string * subjects, subject;
  count = 0;
  if(!mapp(all_rumours) || sizeof(all_rumours)<1) return 0;
  subjects = keys(all_rumours);
  foreach(subject in subjects)
  {
    rumours_about_subject = all_rumours[subject];
    count += sizeof(rumours_about_subject);
  }
  return count;
}

mixed * completely_random_rumour(){
  int i, count, num, *nums, rumour_num;
  string subject, * subjects;
  mapping rumours_about_subject;
  mixed * result;
  count = count_rumours();
  if (count<1) return ({});
  i = random(count);
  count = 0;
  subjects = keys(all_rumours);
  foreach(subject in subjects)
  {
    rumours_about_subject = all_rumours[subject];
    nums = keys(rumours_about_subject);
    if (sizeof(nums)<1) continue;
    foreach(num in nums)
    {
      if (count == i)
      {
        report("querying rumour " + num + " about subject " + subject);
        result = query_rumour(subject, num);
        return result;
      }
      count ++;
    }
  }
  return ({"There was an error in completely_rand_rumour"});
}

void update_all_rumours(){
  int i, count, num, *nums, rumour_num;
  string subject, * subjects;
  mapping rumours_about_subject;
  mixed * result;
  count = count_rumours();
  if (count<1) return ({});
  i = random(count);
  count = 0;
  subjects = keys(all_rumours);
  foreach(subject in subjects)
  {
//    if (subject != "stefano") continue;
    rumours_about_subject = all_rumours[subject];
    nums = keys(rumours_about_subject);
    if (sizeof(nums)<1) continue;
    foreach(num in nums)
    {
//      if (num > 1) continue;
      report("querying rumour " + num + " about subject " + subject);
      result = query_rumour(subject, num);
      result[TIME] = time();
      save_rumour(result);
    }
  }
  return ({"There was an error in completely_rand_rumour"});
}


void check_for_rumour(object ob){
  int room_type, s_type, skill, num, heard_rumour_num, nums, lvl, trace_num;
  string path, * type_paths, type_path, terrain, target, name, targ_name, * hearers, *subjects, detail, secret, trace_subject;
  object room, rum_ob;
  mixed * rum, * heard_rum;
  mapping my_heard_rumours, rums_about_subject;
  if (!mapp(all_rumours) || sizeof(all_rumours)<1) return;
  if (!objectp(ob) || !ob->query_property("gossipping")) return;
  report("Checking for gossip. Gossipper: " + ob->query_name());
  room = environment(ob);
  if (!objectp(room)) return;
  s_type  = ob->query_property("gossipping");
  room_type = check_room_source_type(room);

  skill = calculate_gossip_skill(ob, room_type);
  if (!ob->query_property("investigating"))
  {
    report("Gossipper is not investigating, just gossipping");
    target = "none";
  } else
  {
    report("Gossipper IS investigating something particular");
    target = ob->query_property("investigating");
  }
  if (target=="none" && ob->query_property("tracing"))
  {
    report("Gossipper is trying to trace the source of a rumour");
    trace_subject = ob->query_property("tracing");
    num = sscanf(trace_subject, "%s_%d", trace_subject, trace_num);
    if (num <2)
    {
      tell_object(ob, "Sorry there was an error with tracing the origin of the rumour you were interested in. Please use the 'game' command to make a bug report, saying that Lujke didn't cross his claws properly");
      ob->remove_property("tracing");
      ob->remove_property("gossipping");
      return;
    }
    trace_rumour(ob, trace_subject, trace_num);
    return;
  }
  if (target == "none")
  {
    report("No target set. Getting rumour");
    report("Checking for gossip at random rumour. Gossip skill is : " + skill);
    if (!random(5) || random(skill)>10)
    {
      report("Getting rumour. Hurrah");
      rum =  get_rumour(room_type, ob);
      name = ob->query_true_name();
      if (has_heard_rumour(name, rum))
      {
        tell_object(ob,  get_source(room_type, get_random_source_number(room_type)) + " thing you already heard before about " + capitalize(rum[RUMOUR_SUBJECT]) +". Again.");
        return;
      }
      report("%^BOLD%^%^CYAN%^About to hear rumour");
      rum = query_rumour(rum[RUMOUR_SUBJECT], rum[RUMOUR_NUMBER]);
      tell_object(ob, get_source(room_type, get_random_source_number(room_type)) + " " + rum[SURFACE]);
      hear_rumour(name, rum, SURFACE_LVL);
      return;
    } else
    {
      tell_object(ob, "You haven't come across any interesting rumours yet. Perhaps you should keep gossiping");
      return;
    }
  } else
  {
    report("target set. checking chances of succeeding with investigation");
    num = sscanf(target, "%s_%d", targ_name, heard_rumour_num);
    if (num ==2){
      report("Checking for more detail on heard rumour number " + heard_rumour_num + " about " + capitalize(targ_name));
      if (!random(2)){
        if (!mapp(heard_rumours)|| sizeof(heard_rumours)<1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate a rumour, but no-one seems to have heard any rumours. Please make a bug report, saying that Lujke may be smart, but he's not stable.");
          ob->remove_property("investigating");
          return;
        }
        hearers = keys(heard_rumours);
        if (member_array(ob->query_true_name(), hearers)==-1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate a rumour, but you don't seem to have heard any rumours. Please make a bug report, saying that Lujke may be smart, but he's not stable.");
          ob->remove_property("investigating");
          return;
        }
        my_heard_rumours = heard_rumours[ob->query_true_name()];
//        name = target;
        if (!mapp(my_heard_rumours) || sizeof(my_heard_rumours)<1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate a rumour, but you don't seem to have heard any rumours. Please make a bug report, saying that Lujke may be a genius, but he's not smart.");
          ob->remove_property("investigating");
          return;
        }
        subjects = keys(my_heard_rumours);
        if (!arrayp(subjects) || sizeof(subjects)<1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate a rumour, but you don't seem to have heard rumours about anyone. Please make a bug report, saying that Lujke may be smart, but he's not a genius.");
          ob->remove_property("investigating");
          return;
        }
        if (member_array(targ_name, subjects) == -1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate a rumour about " + targ_name + ", but you don't seem to have heard any rumours about them. Please make a bug report, saying that Lujke may be a genius, but he's not stable.");
          ob->remove_property("investigating");
          return;
        }
        rums_about_subject = my_heard_rumours[targ_name];
        if (!mapp(rums_about_subject) || sizeof(rums_about_subject)<1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate a rumour about " + targ_name + ", but you don't seem to have heard any rumours about them. Please make a bug report, saying that Lujke may be a genius, but he's not stable.");
          ob->remove_property("investigating");
          return;
        }
        nums = keys(rums_about_subject);
        if (!arrayp(nums)|| sizeof(nums)<1 || member_array(heard_rumour_num, nums)==-1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate rumour number " + heard_rumour_num + " about " + targ_name + ", but you don't seem to have heard such a rumour about them. Please make a bug report, saying that Lujke may be a stable genius, but he's not smart.");
          ob->remove_property("investigating");
          return;
        }
        heard_rum = rums_about_subject[heard_rumour_num];
        lvl = heard_rum[2];
        rum = query_rumour(targ_name, heard_rum[1]);
        if (!arrayp(rum) || sizeof(rum)<1)
        {
          tell_object(ob, "Something seems to have gone wrong. You are trying to further investigate rumour number " + heard_rumour_num + " about " + targ_name + ", but there was an error loading that rumour. Please make a bug report, saying that Lujke may be a stable genius, but he's not, like, very smart.");
          ob->remove_property("investigating");
          return;
        }
        detail = rum[DETAIL];
        secret = rum[SECRET];
        report("Investigating rumour " + rum[RUMOUR_NUMBER] + " about " + rum[RUMOUR_SUBJECT] + ". Currently known at level " + lvl);
        switch(lvl)
        {
        case SURFACE_LVL:
          report("Checking for further detail about surface level rumour");
          if (strlen(detail)>0 && random(500)<calculate_gossip_skill(ob, rum[SOURCE_TYPE]))
          {
            report("PASSED Gossip skill test");
            tell_object(ob, "Your enquiries lead you to the information that " + rum[DETAIL]);
            heard_rum[2] = DETAIL_LVL;
            rums_about_subject[rum[RUMOUR_NUMBER]] = heard_rum;
            my_heard_rumours[targ_name] = rums_about_subject;
            heard_rumours[ob->query_true_name()] = my_heard_rumours;
            ob->remove_property("investigating");
            ob->remove_property("gossipping");
            SAVE();
            return;
          } else
          {
            report("further detail not found. Checking for secret info");
            if (strlen(detail)<1 && strlen(secret)>0 && random(1000)<calculate_gossip_skill(ob, rum[SOURCE_TYPE]))
            {
              tell_object(ob, "A cautious informant gives you the highly secret information that " + rum[SECRET]);
              heard_rum[2] = SECRET_LVL;
              rums_about_subject[rum[RUMOUR_NUMBER]] = heard_rum;
              my_heard_rumours[targ_name] = rums_about_subject;
              heard_rumours[ob->query_true_name()] = my_heard_rumours;
              ob->remove_property("investigating");
              ob->remove_property("gossipping");
              SAVE();
              return;
            } else
            {
              report("Didn't find any secret info");
              tell_object(ob, "You haven't turned up any more information about the rumour you are trying to look into, yet. Keep digging...");
              return;
            }
          }
          break;
        case DETAIL_LVL:
          report("Checking for secret info about detail level rumour");
          if (strlen(secret)>0 && random(1000)<calculate_gossip_skill(ob, rum[SOURCE_TYPE]))
          {
            tell_object(ob, "A cautious informant gives you the highly secret information that" + rum[SECRET]);
            heard_rum[2] = SECRET_LVL;
            rums_about_subject[rum[RUMOUR_NUMBER]] = heard_rum;
            my_heard_rumours[targ_name] = rums_about_subject;
            heard_rumours[ob->query_true_name()] = my_heard_rumours;
            ob->remove_property("investigating");
            ob->remove_property("gossipping");
            SAVE();
            return;
          } else
          {
            report("Didn't find any secret info");
            tell_object(ob, "Your contacts haven't turned up any further information about that rumour yet.");
            return;
          }
          break;
        case SECRET_LVL:
          tell_object(ob, "You already know the deepest secrets the rumour mill can lead you to about that topic. If you want to learn more, you'll need to find another way to investigate. Maybe if you ask " + capitalize(name) + " nicely, they will just tell you more?");
          ob->remove_property("investigating");
          ob->remove_property("gossipping");
          return;
          break;
        }
      } else {
        report("Failed the 1 in 20 chance to get more detail");
        tell_object("You haven't been able to turn up any more information about the rumour you've been asking for, at least until now. Perhaps you should keep trying.");
        return;
      }
    } else
    {
      report ("Looking generally for information about a specific subject.");
      if (random(skill)>5)
      {
        rum =  get_rumour_for_subject(target, room_type);
        name = ob->query_true_name();
        if (has_heard_rumour(name, rum))
        {
          tell_object(ob,  get_source(room_type, get_random_source_number(room_type)) + " thing you already heard before about " + capitalize(rum[RUMOUR_SUBJECT]) +". Again.");
          return;
        }
        report("%^BOLD%^%^CYAN%^About to hear rumour");
        rum = query_rumour(rum[RUMOUR_SUBJECT], rum[RUMOUR_NUMBER]);
        tell_object(ob, get_source(room_type, get_random_source_number(room_type)) + " " + rum[SURFACE]);
        hear_rumour(name, rum, SURFACE_LVL);
        return;
      } else
      {
        tell_object(ob, "You haven't come across any interesting rumours about " + target + " yet. Perhaps you should keep gossiping");
        return;
      }
    }
  }
  tell_object(ob, "You carry on gossiping, in the hope you'll hear something interesting soon");
}

int get_random_source_number(int type){
  int x;
  switch(type)
  {
  case CITY_SOURCE:
    report("%^BOLD%^%^YELLOW%^Looking for random city source number");
    x = random(sizeof(SOURCES));
    break;
  case WILD_SOURCE:
    report("%^BOLD%^%^GREEN%^Looking for random city source number");
    x = random(sizeof(WILDSOURCES));
    break;
  case BEAST_SOURCE:
    report("%^BOLD%^%^BLACK%^Looking for random city source number");
    x = random(sizeof(BEASTSOURCES));
    break;
  }
  report ("number found: " + x);
  return x;
}

string get_source(int type, int number){
  string source;
  switch(type)
  {
  case CITY_SOURCE:
    if (number > sizeof(SOURCES)) return "A source <ERROR DETERMINING SOURCE - PLEASE MAKE A BUG REPORT> informs you that";
    source = SOURCES[number];
    report ("%^BOLD%^%^MAGENTA%^Found source: " + source);
    return SOURCES[number];
    break;
  case WILD_SOURCE:
    if (number > sizeof(WILDSOURCES)) return "A source <ERROR DETERMINING WILD SOURCE - PLEASE MAKE A BUG REPORT> informs you that";
    return WILDSOURCES[number];
    break;
  case BEAST_SOURCE:
    if (number > sizeof(BEASTSOURCES)) return "A source <ERROR DETERMINING BEAST SOURCE - PLEASE MAKE A BUG REPORT> informs you that";
    return BEASTSOURCES[number];
    break;
  }
}

int calculate_gossip_skill(object ob, int gossip_type){
  int final, result, thief, bard, druid, ranger;
  string race, subrace, target;
  report ("%^BOLD%^%^GREEN%^Calculating gossip skill");
  race = ob->query_race();
  subrace = ob->query("subrace");
  if (!stringp(subrace)) subrace = "none";
  result = 5 + ob->query_skill("influence");
  switch(gossip_type)
  {
  case CITY_SOURCE:
    bard = ob->query_class_level("bard");
    thief = ob->query_class_level("thief");
    result += bard *2;
    result += thief;
    switch(race)
    {
    case "bugbear":
    case "drow":
    case "gnoll":
    case "goblin":
    case "half-drow":
    case "half-ogre":
    case "hobgoblin":
    case "kobold":
    case "orc":
    case "ogre-mage":
    case "yuan-ti":
      result = result / 20;
      break;
    case "minotaur":
      result = result/3;
      break;
    case "centaur":
    case "wemic":
      result = result / 2;
      break;
    case "beastman":
    case "firbolg":
    case "half-orc":
      result = (result *3)/4;
      break;
    case "voadkyn":
      result = (result *4) /5;
      break;
    case "elf":
      switch(subrace)
      {
      case "fey'ri":
        result = result /3;
      case "wild elf":
        result = result /3;
      default:
        result = (result*9) /10;
      }
      break;
    case "dwarf":
      switch(subrace)
      {
      case "gray dwarf":
        result = result /3;


      default:
        result = (result*9) /10;
      }
      break;
    case "gnome":
    case "halfling":
    case "half-elf":
    case "human":
      switch(subrace)
      {
      case "deep gnome":
        result = (result*6) /10;
      case "tiefling":
        result = (result*7) /10;
        break;
      default:
        result = result * 1;
        break;
      }
    }
    break;
  default:
    report("NON STANDARD RACE ENCOUNTERED");
    result = result;
    break;
  case WILD_SOURCE:
    ranger = ob->query_class_level("ranger");
    druid = ob->query_class_level("druid");
    result += ranger *2;
    result += druid;
     switch(race)
    {
    case "bugbear":
    case "drow":
    case "gnoll":
    case "goblin":
    case "half-drow":
    case "half-ogre":
    case "hobgoblin":
    case "kobold":
    case "orc":
      result = result / 2;
      break;
    case "ogre-mage":
    case "yuan-ti":
      result = (result *4)/10;
      break;
    case "minotaur":
      result = result / 2;
      break;
    case "centaur":
    case "wemic":
    case "beastman":
      result = result * 1;
      break;
    case "firbolg":
        result = (result*8) /10;
      break;
    case "half-orc":
      result = (result*3)/4;
      break;
    case "voadkyn":
      result = result * 1;
      break;
    case "elf":
      switch(subrace)
      {
      case "fey'ri":
        result = (result*6) /10;
      case "wild elf":
        result = (result*12) /10;
      default:
        result = result * 1;
      }
      break;
    case "dwarf":
      switch(subrace)
      {
      case "gray dwarf":
      result = result / 3;
      default:
        result = (result*6) /10;
      }
      break;
    case "gnome":
    case "halfling":
    case "half-elf":
    case "human":
      switch(subrace)
      {
      case "deep gnome":
        result = (result*6) /10;
      case "tiefling":
        result = (result*7) /10;
        break;
      default:
        result = (result*9) /10;
        break;
      }
    default:
      report("NON STANDARD RACE ENCOUNTERED");
      result = result;

    }
    break;
  case BEAST_SOURCE:
    bard = ob->query_class_level("bard");
    thief = ob->query_class_level("thief");
    result += bard *2;
    result += thief;
    switch(race)
    {
    case "bugbear":
    case "drow":
    case "gnoll":
    case "goblin":
    case "half-drow":
    case "half-ogre":
    case "hobgoblin":
    case "kobold":
    case "orc":
    case "ogre-mage":
    case "yuan-ti":
      result = result * 1;
      break;
    case "minotaur":
      result = (result *7) /10;
      break;
    case "centaur":
    case "wemic":
    case "beastman":
    case "firbolg":
      result = (result *4) /10;
      break;
    case "half-orc":
      result = (result *7) /10;
      break;
    case "voadkyn":
      result = result/3;
      break;
    case "elf":
      switch(subrace)
      {
      case "fey'ri":
        result = (result *8) /10;
      case "wild elf":
      result = result/20;
      default:
      result = result/20;
      }
      break;
    case "dwarf":
      switch(subrace)
      {
      case "gray dwarf":
      result = result/3;
      default:
      result = result/20;
      }
      break;
    case "gnome":
    case "halfling":
    case "half-elf":
    case "human":
      switch(subrace)
      {
      case "deep gnome":
        result = (result *4)/10;
      case "tiefling":
      result = result/5;
        break;
      default:
      result = result/20;
        break;
      }
    default:
      report("NON STANDARD RACE ENCOUNTERED");
      result = result;
    break;
    }
  }
  if (ob->query_property("gossipping"))
  {
    result = result / 3;
  }
  final = (int)result/1 + 6;
  return final;
}

int total_traction_for_subject(string subject, int type){
  mapping rumours;
  int i, count, trac;
  string * labels;
  mixed * r;
  rumours = query_rumours(subject, type);
  if (sizeof(rumours)<1) return 0;
  labels = keys(rumours);
  count = sizeof(labels);
  trac = 0;
  for (i=0;i<count;i++)
  {
    r = rumours[labels[i]];
    trac += r[TRACTION];
  }
  return trac;
}
