 //Coded by Lujke
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

#define EYE "the %^BOLD%^%^BLUE%^blue eye%^RESET%^ of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^l%^BLUE%^m%^RESET%^ depicted on the upright war gauntlet"
#define JEWEL "the %^BOLD%^%^BLUE%^blue %^CYAN%^av%^BLUE%^enturi%^CYAN%^ne %^RESET%^set on the wrist of the image of the upright war gauntlet"
#define DAY 24000   // 20 seconds in one minute
                    // 60 minutes in one hour
                    // 20 hours in one day

inherit OBJECT;

int opening, sealing;
string * msgs;

void create() {
    ::create();
    opening = 0;
    sealing = 0;
    set_name("Jetstone");
    set_id( ({"jetstone","stone","jet", "jet stone", "xxjetstonexx" }) );
    set_short("%^BOLD%^%^BLACK%^A piece of jetstone%^RESET%^");
    set_weight(1);
    set_long( (:TO, "long_desc" :) );
}

void init(){
  ::init();
  add_action("release_energy", "release");
  add_action("unleash_energy", "unleash");
}

void report(string str){
  "/daemon/reporter_d"->report("lujke", " energy_source_base: " + str);

}

int unleash_energy(string str){
  int num;
  string what, target;
  if (!objectp(ETO) || !interactive(ETO)){
    return 0;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern" ||!EETO->query_seal_revealed()){
    if (!objectp(EETO)) report ("EETO not valid");
    if (base_name(EETO)!= ROOMS + "cavern") report ("base_name(EETO) = " + base_name(EETO));
    if (!EETO->query_seal_revealed()) report ("Seal not revealed");
    return notify_fail("There is nowhere suitable to unleash the energy round here at the moment");
    return 0;
  }
  num = sscanf(str, "%s at %s", what, target);
  if (num <2){
    num = sscanf(str, "%s against %s", what, target);
  }
  if (num <2){
    num = sscanf(str, "%s toward %s", what, target);
  }
  if (num <2){
    num = sscanf(str, "%s on %s", what, target);
  }
  if (num <2 ){
    tell_object(ETO, "What do you want to unleash against what?");
    return 1;
  }
  if (what != "energy" && what != "power" && what != "heart" && what != "jungle heart" && what != "jetstone" && what != "jetstone's energy" ){
    tell_object(ETO, "What do you want to unleash against what?");
    return 1;
  }
  if (target == "seal" || target == "mystic seal"){
    tell_object(ETO, "Which part of the"
      +" %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^"
      +" do you want to unleash energy against? The"
      +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^BOLD%^%^CYAN%^e%^RESET%^ or the"
      +" %^BOLD%^%^CYAN%^j%^BLUE%^ewe%^BOLD%^%^CYAN%^l%^RESET%^ seem likely targets.");
    return 1;
  }
  if (target != "eye" && target != "eye of helm" && target != "blue eye" && target != "blue eye of Helm"
       && target != "jewel" && target != "blue jewel" && target != "aventurine"
       && target != "blue aventurine" && target != "wrist"){
    tell_object(ETO, "What do you want to unleash energy against?");
    return 1;
  }
  switch (target){
  case "eye":
  case "eye of helm":
  case "blue eye":
  case "blue eye of Helm":
    target = EYE;
    opening = 1;
    break;
  case "jewel":
  case "blue jewel":
  case "aventurine":
  case "blue aventurine":
  case "wrist":
    target = JEWEL;
    sealing = 1;
    break;
  }
  if ( EETO->query_seal_broken() )
  {
    tell_object(TP, "As you prepare to unleash the energy of the " + query_short()
      + "%^RESET%^ toward " + target + "%^RESET%^, you notice that the seal is"
      +" already broken. Whatever you were hoping to acheive, it is too late now.");
    return 1;
  }
  if ( EETO->query_seal_strengthened() )
  {
    tell_object(TP, "As you prepare to unleash the energy of the " + query_short()
      + "%^RESET%^ toward " + target + "%^RESET%^, you see that the seal has been"
      + " strengthened. It positively glows with energy, and doesn't seem like it"
      + " could be affected in any way. Whatever you were hoping to do is"
      +" unlikely to work now.");
    return 1;
  }

  tell_object(ETO, "You raise the " + query_short() + "%^RESET%^ and unleash"
    +" its %^ORANGE%^power%^RESET%^ at " + target + "%^RESET%^." + msgs[0] );
  tell_room(EETO, ETO->QCN + "%^RESET%^ raises  the " + query_short() + "%^RESET%^"
    +" and unleashes its %^ORANGE%^power%^RESET%^ at " + target + "%^RESET%^."
    + msgs[0], ETO);
  switch(target){
  case EYE:
    call_out("open_seal", 3, ETO);
    break;
  case JEWEL:
    call_out("seal_seal", 3, ETO);
    break;
  }
  return 1;
}

void open_seal7(){
  object room;
  room = find_object_or_load(ROOMS + "cavern");
  room->summon_unfettered();
  opening = 0;
}

void open_seal6(){
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    opening = 0;
    return;
  }
  tell_room(EETO, "Hope you have a plan.");
  call_out("open_seal7", 1);
}

void open_seal5(object ob){
  object * critters, rift, room;
  int i, count, flag;
  string desc;
  if(!objectp(ob) || ob != ETO){
    opening = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    opening = 0;
    return;
  }
  desc = "The seal finally gives way, the pieces flying apart and"
    +" revealing the %^BOLD%^%^BLACK%^blackness %^RESET%^of a"
    +" %^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^ft %^RESET%^in the fabric of"
    +" reality behind it.";
  EETO->set_seal_broken(1);
  critters = children(MOB + "unfettered_main");
  flag = 0;
  count = sizeof(critters);
  if (count>0){
    for (i=0;i<count;i++){
      if (objectp(critters[i])){
        room = environment(critters[i]);
        if (objectp(room)){
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag ==1){
    desc += " There appears to be nothing inside there. With a cold dread, you"
      +" realise that %^BLUE%^The %^MAGENTA%^Unf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^"
      +"e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d %^RESET%^has already been unleashed"
      +" on the world!";
    call_out("empress_warning", 3, ob);
  } else {
    desc += " From the %^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^ft,"
    +" %^MAGENTA%^monstrous %^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt"
    +"%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^cles %^RESET%^begin to pull through."
    +" %^BLUE%^The U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r"
    +"%^BLUE%^e%^MAGENTA%^d%^RESET%^ has arrived!";
    call_out("open_seal6", 1);
  }
  tell_room(EETO, desc);
}

void empress_warning(object ob){
//put code in here for Mehaq, Jontar or Guamansuri to appear and give a warning about the
//Unfettered being free, along with some hint about its whereabouts(maybe to lead them there?)
  object room, discoverer, killer, mehaq, jontar, guamansuri, * empresses, * priests, *consorts;
  room = find_object_or_load(ROOMS + "cavern");
  killer = EVENT_RECORDS_D->has_anyone_here_killed(room, MOB + "empress", DAY * 28);
  if (!objectp(killer)){
    tell_room(room, "No-one here has killed Mehaq");
    empresses = children(MOB + "empress");
    if (sizeof(empresses)>0){
      mehaq = empresses[0];
      room = environment(mehaq);
      if (objectp(room)){
        tell_room(room, "%^CYAN%^The spirit of Mehaq %^BOLD%^sh%^WHITE%^i"
          +"%^CYAN%^mm%^WHITE%^e%^CYAN%^rs%^RESET%^%^CYAN%^ and %^RESET%^"
          +"disappears");
      }
    } else {
      mehaq = new (MOB + "empress");
    }
    room = find_object_or_load( ROOMS + "cavern");
    if (objectp(room)){
      tell_room(room, "%^CYAN%^The spirit of Mehaq appears, in a%^BOLD%^"
        +" sh%^WHITE%^i%^CYAN%^mm%^WHITE%^e%^CYAN%^rr%^WHITE%^i%^CYAN%^ng"
        +" %^RESET%^%^CYAN%^of %^BOLD%^%^WHITE%^pale %^RESET%^%^CYAN%^lights");
      mehaq->move(room);
      mehaq->warn_unfettered_loose();
    }
    return;
  }
  tell_room(room, "Someone here has killed Mehaq");
  killer = EVENT_RECORDS_D->has_anyone_here_killed(room, MOB + "jontar", DAY * 28);
  if (!objectp(killer)){
    tell_room(room, "No-one here has killed Jontar");
    priests = children(MOB + "jontar");
    if (sizeof(priests)>0){
      jontar = priests[0];
      room = environment(jontar);
      if (objectp(room)){
        tell_room(room, "%^CYAN%^The spirit of Jontar %^BOLD%^sh%^WHITE%^i"
          +"%^CYAN%^mm%^WHITE%^e%^CYAN%^rs%^RESET%^%^CYAN%^ and %^RESET%^"
          +"disappears");
      }
    } else {
      jontar = new (MOB + "jontar");
    }
    room = find_object_or_load( ROOMS + "cavern");
    if (objectp(room)){
      tell_room(room, "%^CYAN%^The spirit of Jontar appears, in a%^BOLD%^"
        +" sh%^WHITE%^i%^CYAN%^mm%^WHITE%^e%^CYAN%^rr%^WHITE%^i%^CYAN%^ng"
        +" %^RESET%^%^CYAN%^of %^BOLD%^%^WHITE%^pale %^RESET%^%^CYAN%^lights");
      jontar->move(room);
      jontar->warn_unfettered_loose();
    }
    return;
  }
  discoverer = EVENT_RECORDS_D->has_anyone_here_completed(room, "Reunited Guamansuri and Mehaq", DAY * 28);
  if (!objectp(discoverer)){
    return;
  }
  killer = EVENT_RECORDS_D->has_anyone_here_killed(room, MOB + "guamansuri", DAY * 28);
  if (!objectp(killer)){
    consorts = children(MOB + "guamansuri");
    if (sizeof(consorts)>0){
      guamansuri = consorts[0];
      room = environment(guamansuri);
      if (objectp(room)){
        tell_room(room, "%^CYAN%^The spirit of Mehaq %^BOLD%^sh%^WHITE%^i"
          +"%^CYAN%^mm%^WHITE%^e%^CYAN%^rs%^RESET%^%^CYAN%^ and %^RESET%^"
          +"disappears");
      }
    } else {
      guamansuri = new (MOB + "guamansuri");
    }
    room = find_object_or_load( ROOMS + "cavern");
    if (objectp(room)){
      tell_room(room, "%^CYAN%^The spirit of Guamansuri appears, in a%^BOLD%^"
        +" sh%^WHITE%^i%^CYAN%^mm%^WHITE%^e%^CYAN%^rr%^WHITE%^i%^CYAN%^ng"
        +" %^RESET%^%^CYAN%^of %^BOLD%^%^WHITE%^pale %^RESET%^%^CYAN%^lights");
      guamansuri->move(room);
      guamansuri->warn_unfettered_loose();
    }
    return;
  }
}

void open_seal4(object ob){
  if(!objectp(ob) || ob != ETO){
    opening = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    opening = 0;
    return;
  }
  tell_room(EETO, msgs[2]);
  call_out("open_seal5", 2, ETO);
}


void open_seal3(object ob){
  if(!objectp(ob) || ob != ETO){
    opening = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    opening = 0;
    return;
  }
  tell_room(EETO, msgs[3]);
  call_out("open_seal4", 3, ETO);
}

void open_seal2(object ob){
  if(!objectp(ob) || ob != ETO){
    opening = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    opening = 0;
    return;
  }
  tell_room (EETO, msgs[4]);
  call_out("open_seal3", 3, ETO);
}

void open_seal(object ob){
  if(!objectp(ob) || ob != ETO){
    opening = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    opening = 0;
    return;
  }
  tell_room(EETO, msgs[5]);
  call_out("open_seal2", 3, ETO);
}

void summon_jontar(object ob){
  object jontar, room, * priests;
  if (!objectp(ob)){return;}
  priests = children(MOB + "jontar");
  if (sizeof(priests)>0){
    jontar = priests[0];
    room = environment(jontar);
    tell_room(room, "%^BOLD%^%^CYAN%^Jontar s%^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^"
      +"i%^CYAN%^mm%^CYAN%^ers and %^BLUE%^disappears");
  } else {
    jontar = new(MOB + "jontar");
  }
  room = environment(ob);
  if (!objectp(room)){ return;}
  jontar->move(room);
  tell_room(room, "The %^BOLD%^%^CYAN%^sp%^WHITE%^i%^CYAN%^r%^WHITE%^i%^CYAN%^t"
    +"%^RESET%^ of the old priest Jontar appears with a %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^"
    +"h%^BOLD%^%^WHITE%^i%^CYAN%^mm%^CYAN%^er");
  tell_object(ob, "Calling out quest granting. You are object ob");
  tell_room(room, "Calling out quest granting. You are in the room");
  call_out("grant_quest" , 11, ob, "Fettered the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
    +"%^MAGENTA%^e%^BLUE%^red", 21000000, "You have Fettered the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
    +"%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^. By strengthening the seal on the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
    +"%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d's%^RESET%^ cage, you have helped keep"
    +" a greater menace out of the Realms", 0);
  jontar->congratulate_on_strengthened_seal(ob);
}

void seal_seal4(object ob){
  object room;
  room = find_object_or_load(ROOMS + "cavern");
  tell_room(room, msgs[6]);
  room->strengthen_seal();
  sealing = 0;
  call_out("summon_jontar", 4, ob);
}

varargs void grant_quest(object sealer, string quest, int exp,
                              string explanation, int must_be_near){
  object leader, * party, found_thing;
  string name, party_name, * quests;
  int i, count;
  if (!objectp(sealer)){
    return;
  }
  leader = sealer->query_property("minion");
  if (objectp(leader)){
    sealer = leader;
  }
  party_name = "/adm/daemon/party_d.c"->party_member(sealer);
  party = "/adm/daemon/party_d.c"->query_party_members(party_name);
  count = sizeof(party);

  if (count<1){
    party = ({sealer});
    count = 1;
  }
  for (i=0;i<count;i++){
    name = party[i]->query_name();
    found_thing = PATHFINDER_D->far_present(ETO, name, 4);
    if (must_be_near && !objectp(found_thing)){
      continue;
    }
    tell_object( party[i],explanation);
    quests = party[i]->query_quests();
    if (member_array(quest, quests)!= -1){
      continue;
    }
    party[i]->set_quest(quest);
    tell_object(party[i], explanation);
    party[i]->add_exp(exp);
  }
}

void seal_seal3(object ob){
  if(!objectp(ob) || ob != ETO){
    sealing = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    sealing = 0;
    return;
  }
  tell_room(EETO, "The %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ brightens,"
    +" becoming %^WHITE%^clearer%^RESET%^, and the %^BOLD%^%^GREEN%^s%^RESET%^"
    +"%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^ behind the image of the"
    +" gauntlet begins to gleam, the %^ORANGE%^p%^BOLD%^%^BLACK%^a%^ORANGE%^t"
    +"%^RESET%^i%^ORANGE%^n%^BOLD%^%^BLACK%^a of %^BOLD%^%^GREEN%^c%^RESET%^"
    +"%^GREEN%^o%^BOLD%^%^GREEN%^rr%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^pt"
    +"%^RESET%^%^GREEN%^io%^BOLD%^%^GREEN%^n%^RESET%^ vanishing as it is restored"
    +" with the new energy from the " + query_short() + "%^RESET%^.");
  call_out("seal_seal4", 3, ob);
}

int is_powered(){
  return 1;
}

void seal_seal2(object ob){
  if(!objectp(ob) || ob != ETO){
    sealing = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    sealing = 0;
    return;
  }
  tell_room(EETO, "The war gauntlet %^BOLD%^%^WHITE%^gl%^RESET%^i%^BOLD%^%^CYAN%^t"
    +"%^WHITE%^t%^RESET%^e%^BOLD%^%^WHITE%^rs, as the"
    +" %^BOLD%^%^CYAN%^en%^WHITE%^e%^CYAN%^rgy%^RESET%^ streams up from the"
    +" %^BOLD%^%^BLUE%^blue %^CYAN%^av%^BLUE%^ent%^CYAN%^u%^BLUE%^ri%^CYAN%^ne"
    +" %^RESET%^on the wrist to the central"
    +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^.");
  call_out("seal_seal3", 3, ob);
}

void seal_seal(object ob){
  object completer, killer;
  if(!objectp(ob) || ob != ETO){
    sealing = 0;
    return;
  }
  if (!objectp(EETO) || base_name(EETO)!= ROOMS + "cavern"){
    tell_object(ETO, msgs[1]);
    sealing = 0;
    return;
  }
  tell_room(EETO, msgs[7]);
  completer =  EVENT_RECORDS_D->has_anyone_here_completed(EETO, "Agreed to aid Taluc");
  killer =  EVENT_RECORDS_D->has_anyone_here_killed(EETO, MOB + "taluc");
  if (!objectp(killer) && objectp(completer)){
    call_out("interrupt_seal", 3, ETO);
    return;
  }
  call_out("seal_seal2", 3, ob);
}

void interrupt_seal4(object ob, object taluc){
  if (!objectp(ob)||!objectp(taluc)){ return;}
  if (!objectp(environment(taluc)) || !present(ob, environment(taluc))){
    interrupt_seal(ob);
  }
  taluc->force_me("attack " + ob->query_name());
}

void interrupt_seal3(object ob, object taluc){
  if (!objectp(ob)||!objectp(taluc)){ return;}
  if (!objectp(environment(taluc)) || !present(ob, environment(taluc))){
    interrupt_seal(ob);
  }
  taluc->force_me("say You are supposed to be opening the seal, not strengthening it!");
  call_out("interrupt_seal4", 2, ob, taluc);
}

void interrupt_seal2(object ob, object taluc){
  // tell_room(EETO, "Continuing with 2nd part of interruption");
  if (!objectp(ob)||!objectp(taluc)){ return;}
  if (!objectp(environment(taluc)) || !present(ob, environment(taluc))){
    // tell_room(EETO, "taluc not in room with wielder. Trying to get him to right place");
    interrupt_seal(ob);
    return;
  }
  // tell_room(EETO, "Doing taluc stuff");
  taluc->force_me("emoteat " + ob->query_name() + " points at $N");
  taluc->force_me("say No! What are you doing? Stop right now!");
  tell_object(ob, "The distraction interrupts the flow of energy toward the"
    +" %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^."
    +" You can start again, if you don't mind ignoring the spirit's commands.");
  tell_room(EETO, ob->QCN + " appears distracted and the flow of energy toward the"
    +" %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^"
    +" falters and dies away", ob);
  EVENT_RECORDS_D->record_event(ob->query_name(), "Interrupted sealing seal", time());
  call_out("interrupt_seal3", 2, ob, taluc);
}

void interrupt_seal(object ob){
  object taluc, * betrayers, room;
  int already_here;
  if (objectp(EETO)){
    // tell_room(EETO, "Interrupting sealing of the seal");
  }
  if (!objectp(ob)){
    // tell_room(EETO, "Nonexistant ob; finishing");

    return;
  }
  // tell_room(EETO, "Loading existing talucs");
  betrayers = children(MOB + "taluc");
  // tell_room(EETO, "Finished loading existing talucs");
  if (sizeof(betrayers) > 0){
    // tell_room(EETO, "Taluc already exists, moving him from where he is");
    taluc = betrayers[0];
    room = environment(taluc);
  }  else {
    // tell_room(EETO, "Taluc doesn't exist. Making a new one");
    taluc = new(MOB + "taluc");
  }
  if (objectp(room) && base_name(room) != ROOMS + "cavern" && base_name(room) != TEST + "cavern"){
    tell_room(room, "%^CYAN%^The spirit of Taluc %^BOLD%^sh%^WHITE%^i%^CYAN%^mm"
      +"%^WHITE%^e%^CYAN%^rs%^RESET%^%^CYAN%^ and %^RESET%^disappears");
  } else {
    if (objectp(room)){
      already_here = 1;
    }
  }
  if (objectp(EETO) && base_name(EETO) == TEST+"cavern"){
    // tell_room(EETO, "Moving Taluc to test cavern");
    room = EETO;
  } else {
    // tell_room(EETO, "Moving Taluc to main cavern");
    room = find_object_or_load(ROOMS + "cavern");
  }
  taluc->move(room);
  if (EVENT_RECORDS_D->completed_event(ob->query_name(), "Interrupted sealing seal", DAY * 14)>0){
    // tell_room(EETO, "Second interruption: initiating attack");
    taluc_attack(ob);
    return;
  }
  if (present(ob, room)){
    // tell_room(EETO, "Ob in main cavern; continuing");
    if (already_here != 1){
      tell_room(room, "%^CYAN%^The spirit of Taluc appears with a flash of sparking light.");
    }
    call_out("interrupt_seal2", 1, ob, taluc);
  } else {
    // tell_room(EETO, "Ob not in main cavern; bringing Taluc to ob");
    room = environment(ob);
    if (objectp(room)){
      taluc->move(room);
      if (already_here != 1){
        tell_room(room, "%^CYAN%^The spirit of Taluc appears with a flash of sparking light.");
      }
      taluc->force_me("say You fool! You are supposed to open the seal, not"
        +" strengthen it! It is just as well you moved before the process was complete!"
        +" Now go back in there and get the seal open, before someone can stop you!");
    }
  }
}


void taluc_attack(object ob){
  object taluc, * betrayers, room, here, killer, helper;
  if (objectp(EETO)){
    here = EETO;
  } else {
    if (!objectp(ETO) || interactive(ETO)){
      return;
    }
    here = ETO;
  }
  killer = EVENT_RECORDS_D->has_anyone_here_killed(here, MOB + "taluc", DAY * 30);
  if(objectp (killer)){ //if anyone present has killed Taluc recently, discontinue
    return;
  }
  if (objectp(here)){
    taluc = present("xxtalucxx", here);
    if (!objectp(taluc)){
      betrayers = children(MOB + "taluc");
      if (sizeof(betrayers)<1){
        taluc = new(MOB + "taluc");
      }
      room = environment(taluc);
      if (objectp(room) && room != EETO){
        tell_room(room, "%^BOLD%^%^CYAN%^The spirit of Taluc sh%^WHITE%^i%^CYAN%^m"
          +"%^RESET%^%^CYAN%^m%^BOLD%^e%^RESET%^r%^BOLD%^%^CYAN%^s and%^RESET%^"
          +" disappears");
      }
      taluc->move(here);
      tell_room(here, "%^BOLD%^%^CYAN%^The spirit of Taluc appears amid sh%^WHITE%^i"
        +"%^CYAN%^mm%^RESET%^%^CYAN%^e%^BOLD%^r%^WHITE%^i%^CYAN%^ng %^WHITE%^l"
        +"%^CYAN%^i%^WHITE%^ghts");
      call_out("taluc_attack", 2, ob, taluc);
      return; //summoned or made a new taluc. Now start over...
    }
  }
  taluc->force_me("say I warned you!");
  taluc->force_me("say I will kill you before I let you seal Him in and seal our fate!");
  killer = EVENT_RECORDS_D->has_anyone_here_killed(here, MOB + "guamansuri", DAY * 30);
  if (objectp(killer)){ return;}
  helper = EVENT_RECORDS_D->has_anyone_here_completed(here, "Reunited Mehaq and Guamansuri", DAY * 30);
  if (objectp(helper)){
    summon_guamansuri(taluc);
    return;
  }
  taluc_attack2(ob, taluc);
}

void taluc_attack2(object ob, object taluc){
  if (!objectp(ob) || !objectp(taluc) || !objectp(environment(ob)) || !present(taluc, environment(ob)) ){
    return;
  }
  taluc->force_me("kill " + ob->query_name());
}

void summon_guamansuri(taluc){
  object here, killer, guamansuri, *betrayers, room;
  if (objectp(EETO)){
    here = EETO;
  } else {
    if (!objectp(ETO) || interactive(ETO)){
      return;
    }
    here = ETO;
  }
  killer = EVENT_RECORDS_D->has_anyone_here_killed(here, MOB + "guamansuri", DAY * 30);
  if(objectp (killer)){ //if anyone present has killed guamansuri recently, discontinue
    return;
  }
  if (objectp(here)){
    guamansuri = present("xxguamansurixx", here);
    if (!objectp(guamansuri)){
      betrayers = children(MOB + "guamansuri");
      if (sizeof(betrayers)<1){
        guamansuri = new(MOB + "guamansuri");
      }
      room = environment(guamansuri);
      if (objectp(room)){
        tell_room(room, "%^BOLD%^%^CYAN%^The spirit of guamansuri sh%^WHITE%^i%^CYAN%^m"
          +"%^RESET%^%^CYAN%^m%^BOLD%^e%^RESET%^r%^BOLD%^%^CYAN%^s and%^RESET%^"
          +" disappears");
      }
    }
    guamansuri->move(here);
    tell_room(here, "%^BOLD%^%^CYAN%^The spirit of Guamansuri appears amid sh%^WHITE%^i"
      +"%^CYAN%^mm%^RESET%^%^CYAN%^e%^BOLD%^r%^WHITE%^i%^CYAN%^ng %^WHITE%^l"
      +"%^CYAN%^i%^WHITE%^ghts");
    call_out("summon_guamansuri", 2, taluc, guamansuri);
    return;
  }
  guamansuri->force_me("say Taluc! You traitorous wretch! You will not continue to"
    +" disgrace the %^CYAN%^Tecqumin%^RESET%^ people with your actions. Die, worm!");
  call_out("summon_guamansuri2", 2, guamansuri, taluc);
}

void summon_guamansuri2(object guamansuri, taluc){
  object here;
  if (!objectp(guamansuri)){
    return;
  }
  here = environment(guamansuri);
  if (!objectp(here)){
    return;
  }
  if (!objectp(taluc)|| !present(taluc, here)){
    return;
  }
  guamansuri->force_me("kill taluc");
}

int release_energy(string str){
  if (!objectp(ETO) || !interactive(ETO)){
    return 0;
  }
  if (!objectp(EETO) || (base_name(EETO)!= JUNG_ROOM10 + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return 0;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    return 0;
  }
  tell_object(ETO, msgs[8]);
  tell_room(EETO, ETO->QCN + msgs[9], ETO);
  call_out("release2", 2);
  return 1;
}

void release2(){
  if (!objectp(ETO) || !interactive (ETO)){
    return;
  }
  if (!objectp(EETO) || (base_name(EETO)!= JUNG_ROOM10 + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    tell_room(EETO, msgs[10]);
    return;
  }
  tell_object(ETO, msgs[11]);
  tell_room(EETO, msgs[12], ETO);
  call_out("release3", 3);
}

void release3(){
  if (!objectp(ETO) || !interactive (ETO)){
    return;
  }
  if (!objectp(EETO) || (base_name(EETO)!= JUNG_ROOM10 + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    tell_room(EETO, msgs[10]);
    return;
  }
  tell_room(EETO, msgs[13]);
  call_out("release4", 1);
}

void release4(){
  if (!objectp(ETO) || !interactive (ETO)){
    return;
  }
  if (!objectp(EETO) || (base_name(EETO)!= JUNG_ROOM10 + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    tell_room(EETO, msgs[14]);
    return;
  }
  tell_room(EETO, "Slowly, and with great reluctance, the gate creaks"
    +" open, revealing the opening to a cavern descending below"
    +" ground.");
  if (base_name(EETO) == TEST + "carved_gate"){
    EETO->add_exit(TEST + "cavern", "down");
  } else {
    EETO->add_exit(ROOMS + "cavern", "down");
  }
}
