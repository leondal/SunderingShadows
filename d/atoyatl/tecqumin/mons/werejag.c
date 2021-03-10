//Coded by Lujke
#include <std.h>
#include <daemons.h>
#include <move.h>

#include "../tecqumin.h"
#define DEST "/daemon/destinations_d.c"
#define JAGUAR 0
#define HUMAN 1
#define HUMANJAG1 2
#define HUMANJAG2 3
#define HUMANJAG3 4
#define JAGHUMAN1 5
#define JAGHUMAN2 6
#define JAGHUMAN3 7

inherit MONSTER;

int flag, form, timer, leaving_lair, acting, para;
nosave int BEAT, heartcount;
object current_room;
string para_message;
void leave_lair();
void lair_actions();
void transform();
void go_bed();
void wake_up();
void grab_run();
void grab_run2();

void create()
{
      object ob;
      int i;
      ::create();  
      /*if (sizeof(children(file_name(TO)))>1){
          children(file_name(TO))[0]->move(find_object_or_load("/d/shadowgate/void"));
          remove();
      }*/
      set_property("no random treasure", 1);
  	set_name("stealthy werejaguar");
  	set_id(({"jaguar", "werejaguar", "stealthy werejaguar"}));

  	set_short( "%^BOLD%^%^BLACK%^stealthy %^YELLOW%^we%^BOLD%^%^BLACK%^re"
        +"%^YELLOW%^j%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^"
        +"u%^YELLOW%^a%^RESET%^%^ORANGE%^r");
      set_gender("male");
      set_long("%^BOLD%^%^BLACK%^This b%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^a"
        +"%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^t %^BOLD%^%^BLACK%^has fur"
        +" patterned in rings and spots in shades of%^RESET%^%^ORANGE%^"
        +" brown%^BOLD%^%^BLACK%^, black and"
        +" %^BOLD%^%^YELLOW%^yellow%^BOLD%^%^BLACK%^. It is half again as long as"
        +" a normal big cat, and perhaps twice the"
        +" bulk. Muscles ripple under its skin as it moves silently through the"
        +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l"
        +"%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^. Its intelligence seems evident in"
        +" glowing %^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^m%^RESET%^%^ORANGE%^b"
        +"%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ eyes.");
  	set_race("jaguar");
  	set_body_type("quadruped");
  	set_hd(35,12);
  	set_size(3);
  	set("aggressive",0);
	set_class("thief");
	set_mlevel("thief",50);
	set_level(50);
	set_guild_level("thief",50);
      set_thief_skill("climb walls", 95);
   	set_hp(random(1000) + 900);
	set_max_level(50);
	set_property("swarm",0);
  	set_overall_ac(-68);
  	set_alignment(4);
      set_property("full attacks",1);
      set_thief_skill("climb walls", 150);
      set_skill("athletics", 90);
      set_funcs(({"roll"}));
      set_func_chance(25);

      add_attack_bonus(67); 
      set_property("magic",1);
      set_monster_feats(({
        "evasion",
        "scramble",
        "damage resistance",
        "disarm",
        "lightning reflexes",
        "dodge",
        "defensive roll",
    })); 
      set_stats("strength",26);
      set_stats("intelligence",10);
      set_stats("dexterity",16);
      set_stats("charisma",6);
      set_stats("wisdom",20);
  	set_alignment(4);
      set_new_exp(level, "normal");
      set_funcs(({"shatter", "sunder", "rush"}));
      set_func_chance(40);
      form = JAGUAR;
    //NO CLEAN STUFF
    set_no_clean(1);
    leaving_lair = 0;
    acting = 0;
    timer = 7200; //(2 hours) 
    BEAT = 0;
    heartcount = 0;
    check_my_heart();
    "/daemon/destinations_d"->set_waystations(CITY_ROOM + "city_jung13", 
      ([ CITY_ROOM + "city_jung13": 1, CITY_ROOM + "city_jung11": 2, CITY_ROOM + "city_jung16": 2,
         CITY_ROOM + "ragged_road03" : 3, CITY_ROOM + "plaza": 4,
         ROOMS + "step7": 5, CITY_ROOM + "palace_entrance": 5,
         CITY_ROOM + "bridge02": 5, ROOMS + "step9": 6,
         CITY_ROOM + "ragged_road02": 6, ROOMS + "step11": 7,
         CITY_ROOM + "ruin03": 7, CITY_ROOM + "canalbank02": 7,
         CITY_ROOM + "city_jung07": 7, CITY_ROOM + "city_jung06": 7,
         CITY_ROOM + "ruin02": 8, ROOMS + "zigzenith": 8 ])
    );
}

void check_my_heart()
{
    if (heartcount>300){
      if (!objectp(ETO) || !present("player", ETO)){
        move("/d/shadowgate/void");
      }else{
        call_out("check_my_heart", 7);
      }
      return;
    }
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        heartcount ++;
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}

int query_heartcount(){
  return heartcount;
}

int move(mixed dest){
  int result;
  result = ::move(dest);
  if (objectp(ETO)){
    ETO->set_had_players(3);
  }
  return result;
}

int query_form(){
  return form;
}

void transform(){
  switch(form){
  case JAGUAR:
    force_me("emote suddenly arches its back and falls onto its side, panting"
      +" heavily as its body starts to transform");
    para = query_paralyzed();
    para_message = query_paralyze_message();
    set_name("jaguar beginning to change shape");
    set_short("%^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^g"
      +"%^YELLOW%^u%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r %^RESET%^beginning"
      +" to change shape");
    set_long("%^BOLD%^%^BLACK%^This b%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^a"
        +"%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^t %^BOLD%^%^BLACK%^has fur"
        +" patterned in rings and spots in shades of%^RESET%^%^ORANGE%^"
        +" brown%^BOLD%^%^BLACK%^, black and%^BOLD%^%^YELLOW%^" 
        +" yellow%^BOLD%^%^BLACK%^. It is half again as long as a normal big"
        +" cat, and perhaps twice the bulk. It is %^ORANGE%^writhing"
        +"%^BOLD%^%^BLACK%^ as if in pain, as its form starts to change. Its"
        +" back legs are straightening, reversing at the knee joint, and the"
        +" spine is beginning to straighten.");
    set_race("jaguar");
    set_body_type("quadruped");
    form = JAGHUMAN1;
    set_paralyzed(300, "You are changing shape!");
    break;
  case JAGHUMAN1:
    remove_paralyzed();
    force_me("emote 's spine begins to straighten, and its head begins to"
      +" take on human shape as its knees begin to reverse.");
    set_name("Transforming creature");
    set_short("creature transforming from a jaguar into a human");
    set_long("%^ORANGE%^This creature is halfway between a %^BOLD%^%^BLACK%^"
      +"j%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^g%^YELLOW%^u%^RESET%^%^ORANGE%^"
      +"a%^BOLD%^%^BLACK%^r %^RESET%^%^ORANGE%^and a %^RESET%^human%^ORANGE%^"
      +" in shape, with a spine that is beginning to straighten, rear legs"
      +" taking on human form in the knees, and a steadily reducing coverage"
      +" of patterned fur. Its head is starting to take on human shape, but"
      +" the teeth are still pointed and long, the jaws stretched to"
      +" accomodate them. Its tail has shortened slightly in length, but is"
      +" still very furry.");
    set_paralyzed(300, "You are changing shape!");
    form = JAGHUMAN2;
    break;
  case JAGHUMAN2:
    remove_paralyzed();
    force_me("emote 's tail sontinues to shorten, and its claws and fur begin"
      +" to disappear.");
    set_name("Transforming creature");
    set_short("creature transforming from a jaguar into a human");
    set_long("This creature is humanoid in shape, with a flattened skull,"
      +" pointed cat ears and elongated limbs with claws at the ends. It is"
      +" %^ORANGE%^writhing%^RESET%^ as its body changes form. The remains of"
      +" a tail appears to be retracting, as is the last of its"
      +" %^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^tt"
      +"%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^n%^RESET%^"
      +"%^ORANGE%^e%^BOLD%^%^BLACK%^d %^RESET%^fur. Its hunched spine is"
      +" straightening out, and the claws are disappearing. ");
    set_race("human");
    form = JAGHUMAN3;
    set_paralyzed(300, "You are changing shape!");
    break;
  case JAGHUMAN3:
    remove_paralyzed();
    force_me("emote pants heavily, then cries out as its transformation into"
      +" human form is completed");
    set_name("shifty looking Tecqumin human");
    set_short("%^RESET%^shifty looking %^CYAN%^Tecqumin%^RESET%^ human");
    set_long("%^ORANGE%^A short, shifty-looking %^RESET%^human%^ORANGE%^, with"
      +" %^BOLD%^%^BLACK%^black hair%^RESET%^%^ORANGE%^ and mostly"
      +" %^CYAN%^Tecqumin%^ORANGE%^ features, but catlike ear tips and"
      +" %^ORANGE%^amb%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^r"
      +" eyes with vertical slit pupils.");
    set_id(({"human", "werejaguar", "shifty human", "shifty looking human"}));
    set_race("human");
    set_body_type("humanoid");
    set_class("fighter");
    set_mlevel("fighter",33);
    set_level(33);
    set_guild_level("fighter",33);
    set_funcs(({"tumble"}));
    set_func_chance(25);
    form = HUMAN;
    if (para>0){
      set_paralyzed(para, para_message);
    } 
    break;
  case HUMAN:
    para = query_paralyzed();
    para_message = query_paralyze_message();
    force_me("emote cries out and falls onto the floor, his spine hunching"
      +" forward at the shoulders at his body begins to transform, a covering"
      +" of %^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^"
      +"t%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^rn%^BOLD%^"
      +"%^YELLOW%^e%^BOLD%^%^BLACK%^d f%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^r"
      +" beginning to appear.");
    set_name("human writhing on the floor");
    set_short("human %^CYAN%^writhing%^RESET%^ on the floor");
    set_long("This %^CYAN%^Tecqumin%^RESET%^ looking human is%^ORANGE%^"
      +" writhing%^RESET%^ on the floor, its body contorting as it changes"
      +" in shape. The spine is hunching over at the shoulders, and its knees"
      +" appear to be reversing, even as its arms lengthen into legs. Its"
      +" ears are lengthening and moving toward the top of its head, and a"
      +" covering of %^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^"
      +"t%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^rn%^BOLD%^"
      +"%^YELLOW%^e%^BOLD%^%^BLACK%^d f%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^r"
      +" %^RESET%^is beginning to appear.");
    set_race("human");
    form = HUMANJAG1;
    set_paralyzed(50, "You are changing form!");
    break;
  case HUMANJAG1:
    remove_paralyzed();
    force_me("emote 's head changes shape, its jaw stretching forward as the"
      +" top flattens and its ears move upwards. Its knees reverse, in a"
      +" painful looking change, as its arms change into forelegs and the"
      +" %^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^"
      +"t%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^rn%^BOLD%^"
      +"%^YELLOW%^e%^BOLD%^%^BLACK%^d f%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^r"
      +" continues to grow.");
    set_name("Transforming creature");
    set_short("creature transforming from a jaguar into a human");
    set_long("This creature is humanoid in shape, with a flattened skull,"
      +" pointed cat ears and elongated limbs with claws at the ends. It is"
      +" %^ORANGE%^writhing%^RESET%^ as its body changes form. A tail is"
      +" appearing, and"
      +" %^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^tt"
      +"%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^n%^RESET%^"
      +"%^ORANGE%^e%^BOLD%^%^BLACK%^d %^RESET%^fur is growing. Its hunched"
      +" spine is curving, and claws are appearing at the end of its limbs."
        );
    set_race("human");
    form = HUMANJAG2;
    set_paralyzed(50, "You are changing form!");
    break;
  case HUMANJAG2:
    remove_paralyzed();
    force_me("emote gives out a mewling sounding cry, as its transformation"
      +" approaches the end. Its body is now almost completely in the shape and"
      +" form of a powerful jungle cat.");
    set_name("TRansforming creature");
    set_short("creature transforming from a jaguar into a human");
    set_long("%^ORANGE%^This %^CYAN%^contorted %^BOLD%^%^BLACK%^b%^RESET%^"
      +"%^ORANGE%^e%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLACK%^st%^RESET%^%^ORANGE%^"
      +" appears like a %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^"
      +"g%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLACK%^r%^RESET%^"
      +"%^ORANGE%^ with just the last remains of human form. Its eyes are a"
      +" little too round for a cat's, as is its head. Its spine is curving"
      +" further, and %^BOLD%^%^BLACK%^claws%^RESET%^%^ORANGE%^ lengthening"
      +" and thickening. Its fur is filling out, and its tail reaching its final"
      +" length.");
    set_race("jaguar");
    form = HUMANJAG3;
    set_paralyzed(50, "You are changing form!");
    break;
  case HUMANJAG3:
    remove_paralyzed();
    set_name("stealthy werejaguar");
    force_me("emote rises slightly unsteadily to its feet, then pads across the"
      +" floor with increasingly fluid movement");
    set_long("%^BOLD%^%^BLACK%^This b%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^a"
        +"%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^t %^BOLD%^%^BLACK%^has fur"
        +" patterned in rings and spots in shades of%^RESET%^%^ORANGE%^"
        +" brown%^BOLD%^%^BLACK%^, black and"
        +" %^BOLD%^%^YELLOW%^yellow%^BOLD%^%^BLACK%^. It is half again as long as"
        +" a normal big cat, and perhaps twice the"
        +" bulk. Muscles ripple under its skin as it moves silently through the"
        +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l"
        +"%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^. Its intelligence seems evident in"
        +" glowing %^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^m%^RESET%^%^ORANGE%^b"
        +"%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ eyes.");
    set_race("jaguar");
    set_id(({"jaguar", "werejaguar", "stealthy werejaguar"}));
    set_short( "%^BOLD%^%^BLACK%^stealthy %^YELLOW%^we%^BOLD%^%^BLACK%^re%^YELLOW%^j%^RESET%^"
        +"%^ORANGE%^a%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^u%^YELLOW%^a%^RESET%^%^ORANGE%^r");
    set_class("thief");
    set_mlevel("thief",33);
    set_level(33);
    set_guild_level("thief",33);
    set_funcs(({"roll"}));
    set_func_chance(25);
    form = JAGUAR;
    if (para>0){
      set_paralyzed(para, para_message);
    } 
    break;
  }
  acting = 0;
}

void roll(object targ){
    if(!"daemon/saving_d"->saving_throw(targ, "reflex", -20)){
        tell_object(targ,"The jaguar leaps on you tearing all"
          +" of its claws across your body!");
        tell_room(ETO,"The jaguar leaps on "+targ->query_cap_name()+" tearing its
claws across "+targ->query_possessive()+" body!",targ);
        targ->do_damage(targ->return_target_limb(),roll_dice(3,10));
        targ->do_damage(targ->return_target_limb(),roll_dice(3,10));
        targ->do_damage(targ->return_target_limb(),roll_dice(3,10));
        targ->do_damage(targ->return_target_limb(),roll_dice(3,10));
        targ->set_tripped(1);
        return 1;
    }
    tell_object(targ,"The Jaguar leaps at you but misses!");
    tell_room(ETO,"The Jaguar leaps at "+targ->query_cap_name()+" but
misses!",targ);
    return 1;
}

void tumble(object targ){
  string * exits;
  object * rooms, *attackers, room;
  int i, j, k;
  if (!objectp(ETO)){
    return;
  }
  exits = ETO->query_exits();
  rooms = ({ETO});
  attackers = query_attackers();
  set_attackers( ({}) );
  for (i = 0;i<5;i++){
    exits = ETO->query_exits();
    j = random(sizeof(exits));
    k = 0;
    room = find_object_or_load(ETO->query_exit(exits[j]));
    while (member_array(room, rooms)!=-1 && k<sizeof(exits)){
      j++;
      k++;
      if (j >= sizeof(exits) ){
        j = 0;
      }
      room = find_object_or_load(ETO->query_exit(exits[j]));
    }
    if (member_array(room, rooms)==-1 ){
      if (present(targ, ETO)){
        tell_room(ETO, TO->QCN + " %^BOLD%^%^CYAN%^springs%^RESET%^"
          +" over " + targ->QCN + "%^RESET%^'s head and heads off to the "
          + exits[j], targ);
        tell_object(targ, TO->QCN + " %^BOLD%^%^CYAN%^springs%^RESET%^"
          +" over your head and heads off to the "
          + exits[j]);
        if (targ->query_paralyzed()<1){
          if (!"daemon/saving_d"->saving_throw(targ, "will", -20)){
            targ->set_paralyzed(1, "%^BOLD%^%^BLUE%^You are momentarily"
              +" confused!");
          }
        }
      }
      force_me(exits[j]);
      if (member_array(ETO, rooms)==-1){
        rooms += ({ETO});
      }
    }
  }
}

void grab_run2(){
  string roomname;
  roomname = file_name(ETO);
  acting = 0;
  if (roomname != CITY_ROOM + "grand_interior02"){
    if (roomname == CITY_ROOM + "city_jung14"){
      reach_destination();
      return;
    }
    if (roomname[0..sizeof(CITY_ROOM)-1]==CITY_ROOM){
      start_walking(CITY_ROOM + "city_jung14");
      return;
    }
  }
  force_me("out");
  force_me("north");
  force_me("north");
  force_me("west");
  force_me("northwest");
  reach_destination();
}

void grab_run(){
  force_me("emote %^BOLD%^%^RED%^grabs%^RESET%^ something from"
    +" one of the shelves");
  force_me("emote %^BOLD%^%^BLUE%^darts%^RESET%^ out of the hut"
    +" and makes a run for it!");
  grab_run2();
  acting = 1;
}

void lair_actions(){
  object * killers, room;
  force_me("pose clear");
  room = find_object_or_load(JUNG_ROOM + "jaguar_lair");
  if (objectp(room)&& room !=ETO){
    return;
  }
  killers = query_attackers();
  if (sizeof(killers)>0){
    return;
  }
  if (form == JAGUAR){
    call_out("leave_lair", 3);
    acting = 2;
    return;
  }
  switch(random(18)){
  case 0..2:
    force_me("emote pads over to the little %^GREEN%^bed%^RESET%^ of"
      +" %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^"
      +"v%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s");
    call_out("go_bed", 3);
    acting = 3;
    return;
    break;
  case 3..5:
    force_me("emote rummages around in the %^GREEN%^bed%^RESET%^ of"
      +" %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^"
      +"v%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s");
    break;
  case 6..8: 
    force_me("emote picks up a %^BOLD%^%^WHITE%^kn%^RESET%^i%^BOLD%^%^WHITE%^"
      +"fe%^RESET%^ from the %^ORANGE%^log table %^RESET%^and starts"
      +" tossing it from hand to hand");
  case 9..11:
    force_me("emote rearranges some %^BOLD%^%^WHITE%^F%^MAGENTA%^l%^BOLD%^"
      +"%^WHITE%^ow%^CYAN%^e%^BOLD%^%^WHITE%^rs%^RESET%^ in the vase");  
    break;
  case 12:
    transform();
    break;
  case 13:
    force_me("emote peers out of the %^BOLD%^%^BLACK%^entrance");
    break;
  case 14:
    force_me("emote looks under the %^ORANGE%^log table");
    break;
  case 15:
    force_me("emote %^CYAN%^sniffs%^RESET%^ round the corners of the room");
    break;
  case 16:
    force_me("emote scratches his ear");
    break;
  case 17:
    force_me("emote licks one of his hands clean, then rubs it behind his ear");
    break; 
  }
}

void go_bed(){
  object room;
  acting  = 0;
  room = find_object_or_load(JUNG_ROOM + "jaguar_lair");
  if (!objectp(room)||room !=ETO){
    return;
  }
  force_me("emote crawls into the little bed and curls up");
  force_me("pose sleeping in a little bed");
}

void wake_up(){
  object room;
  room = find_object_or_load(JUNG_ROOM + "jaguar_lair");
  if (!objectp(room)||room !=ETO){
    return;
  }
  force_me("emote wakes up");
  force_me("pose clear");
  acting = 0;
}

void leave_lair(){
  object room;
  room = find_object_or_load(TECSTORE);
  leaving_lair = 1;
  acting = 0;
  if (file_name(ETO) != JUNG_ROOM + "jaguar_lair"){
    return;
  }
  force_me("out");
}

string random_player(){
  object * critters, * players, player;
  int i, num;
  string race;
  if (!objectp(ETO)){
    return "none";
  }
  critters = all_living(ETO);
  if (sizeof(critters)<1){
    return "none";
  }
  players = ({});
  num = sizeof(critters);
  for (i=0;i<num;i++){
    if (critters[i]->is_player()){
      players += ({critters[i]});
    }
  }
  if (sizeof(players)<1){
    return "none";
  }
  player = players[random(sizeof(players))];
  race = player->query_race();
  if (present(race, ETO) == player){
    return race;
  }
  for (i=1;i<num;i++){
    if (present(race + " " + i, ETO)==player){
      return race + " " + i;
    }
  }
  return race;
}

void reach_destination(){
  string * dests, dest, rpath, *elements, path;
  int i, fl, mazetime, waytime, entry, count;
  object room, luj;
  mapping waystations;
  luj = find_player("lujke");
  //choose new destination:
  switch (file_name(ETO)){
  case JUNG_ROOM4 + "city_jung14":
    dests = ({CITY_ROOM + "grand_interior02", JUNG_ROOM4 + "j_link3a", 
       JUNG_ROOM4 + "j_maze30",
       JUNG_ROOM4 + "jag_lair_entry", JUNG_ROOM4 + "j_link4"});
    leaving_lair = 0;
    break;
  case JUNG_ROOM4 + "jag_lair_entry":
//    force_me("say I am at the entrance to my lair. Muahaha");
//    force_me("say leaving_lair setting is: " + leaving_lair);
    switch(leaving_lair){
    case -1..0:
//    force_me("say I am not leaving my lair, so I will go in.");
      room = find_object_or_load(TECSTORE);
      if (objectp(room)){ 
        entry = room->query_jag_entry();
//        force_me("say I will try to go in with this action: " + entry);
      } else {
        force_me("say Well, I, a werejaguar, arrived here, but I don't know what to do now. Please make a bug report on this room, quoting this message");
      }
      switch(entry){
      case CLIMB:
//        force_me("say Trying to climb tree");
        force_me("climb tree");
        break;
      case SCRAMBLE:
//        force_me("say Trying to scramble under fern");
        force_me("scramble under fern");
        break;
      case SQUEEZE:
//        force_me("say Trying to squeeze through thicket");
        force_me("squeeze through thicket");
        break;
      }
      return;
      break;
    case 1:
//    force_me("say I am leaving my lair, so I will decide where to go next");
    dests = ({JUNG_ROOM4 + "city_jung14", JUNG_ROOM4 + "j_link3a", 
       JUNG_ROOM4 + "j_maze30", JUNG_ROOM4 + "j_maze70",
       JUNG_ROOM4 + "j_link4"});      
    break;
    }
  case JUNG_ROOM4 + "j_link3a":
    dests = ({JUNG_ROOM4 + "city_jung14", 
       JUNG_ROOM4 + "j_maze30", JUNG_ROOM4 + "j_maze70",
       JUNG_ROOM4 + "jag_lair_entry"});
    leaving_lair = 0;
    break;
  case JUNG_ROOM4 + "j_link4":
    dests = ({ JUNG_ROOM4 + "j_maze30", JUNG_ROOM4 + "j_maze70",
       JUNG_ROOM4 + "jag_lair_entry", JUNG_ROOM4 + "j_link4"});
    leaving_lair = 0;
    break;
  case CITY_ROOM + "grand_interior02":
  case CITY_ROOM + "grand_interior02":
    waystations = "/daemon/destinations_d"->query_waystations(CITY_ROOM + "city_jung13");
    if (sizeof(waystations)<1){
      force_me("say making new waystations");
      "/daemon/destinations_d"->generate_waystations(CITY_ROOM + "city_jung13", 3, 3);
    }
    dests = ({CITY_ROOM + "city_jung13"});
    leaving_lair = 0;
    break;
  case CITY_ROOM + "city_jung13":
    force_me("northwest");
    return;
  default:
    dests = ({JUNG_ROOM4 + "city_jung14", JUNG_ROOM4 + "j_link3a",
       JUNG_ROOM4 + "j_maze30", JUNG_ROOM4 + "j_maze70",
       JUNG_ROOM4 + "jag_lair_entry", JUNG_ROOM4 + "j_link4"});    
    leaving_lair = 0;
  }  
  i = random(sizeof(dests));
  dest = dests[i];
//  force_me("say I would like to go to " + dest);
  force_me("emote heads off somewhere new");
  room = find_object_or_load(dest);
  while (room == ETO){
    i ++;
    if (i>=sizeof(dests)){
      i=0;
    }
    dest = dests[i];
    room = find_object_or_load(dest);
  }
  if (!interact("/city/", dest)){
    waytime = DEST->query_timing(dest);
    mazetime = "/d/atoyatl/maze_d.c"->query_timing(JUNG_ROOM4 + "j_maze");  
    if (!intp(waytime) || !intp(mazetime) || waytime == 0 || mazetime >= waytime){
    // Above check makes sure the next lag inducing maneuvre only happens
    // if the maze has been reset since the waystations were set up  
      elements = explode(dest, "/");  
      path = "/"; 
      count = sizeof(elements)-1;
      if (count >0){
        for(i=0;i<count;i++){
          path+= elements[i] + "/";
        }
        dest = elements[count];
      }
      DEST->clear_waystations(dest);
      MAZE_D->generate_waystations(path, dest,6, 4);
    }
  }
//  force_me("say going to " + room->query_short());
//  force_me("say " + dest);  
//  if (objectp(luj)){
//    tell_object(luj, "Destination: " + dest);
//  }
  if (dest == JUNG_ROOM4 + "jag_lair_entry") { leaving_lair = -1;}
  set_property("sneaking", 1);
//  force_me("say starting walking towards " + dest);
  start_walking(dest);
  fl = 0;
}

void heart_beat(){
    object store;
    int entry;
    string roomname, player;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;    
//    tell_room(ETO, "Heart beating");
    if(current_room != ETO)
    {
        if(objectp(current_room) && flag) current_room->set_no_clean(0);
        current_room = ETO;
        if(!current_room->query_no_clean()) 
        {
            flag = 1;
            current_room->set_no_clean(1);
        }
        else flag = 0;
    }
    timer--;
    if (present("player", ETO)){
      heartcount = 0;
    }
//    tell_room(ETO, "Timer reduced to " + timer);
    switch(form){
    case HUMANJAG1:
    case HUMANJAG2:
    case HUMANJAG3:
    case JAGHUMAN1:
    case JAGHUMAN2:
    case JAGHUMAN3://deliberately falling through to here
//      tell_room(ETO, "Transforming myself");
      transform();
      return;
      break;
    }
//    tell_room(ETO, "Didn't transform");
    if(sizeof(TO->query_attackers())>0)
    {
        if (query_property("posed") == "sleeping in a little bed"){
            wake_up();
        }
        timer = 7200;
        if(!query_no_clean()) set_no_clean(1);
    }
    else if(timer < 0) { set_no_clean(0); }
    if (!random(3)){ //start him walking if he's idle
      roomname = file_name(ETO);             // and not in his lair
      store = find_object_or_load(TECSTORE);
      if (objectp(store)){
        entry = store->query_jag_entry();
      }
      if (!random(10)){
        player = random_player();
        if (stringp(player) && player != "none"){
          force_me("pp "+  player);
          return;
        }
        transform();
      }
//      tell_room(ETO, "Switching based on room name");
      switch (roomname){
      case JUNG_ROOM + "jag_lair_ground":
        switch (leaving_lair){
        case -1..0:
          force_me("up");
          break;
        case 1:
          switch(entry){
          case CLIMB:
            force_me("up");
            break;
          case SCRAMBLE:
            force_me("scramble under fern");
            break;
          case SQUEEZE:
            force_me("squeeze through thicket");
            break;
          }
          break;
        }
        break;
      case JUNG_ROOM + "jag_lair_outside":
        switch (leaving_lair){
        case -1..0:
          if (form ==JAGUAR){
            acting = 4;
            transform();
            return;
          }
          force_me("enter");
          break;
        case 1:
          switch(entry){
          case CLIMB:
            force_me("leap across");
            break;
          case SCRAMBLE:
          case SQUEEZE:
            force_me("down");
            break;
          }
          break;
        }
        break;
      case JUNG_ROOM + "jag_tree1":
        switch (leaving_lair){
        case -1..0:
          force_me("crawl along branch");
          break;
        case 1:
          force_me("climb down");
          break;
        }
      case JUNG_ROOM + "jag_tree2":
        switch (leaving_lair){
        case -1..0:
          force_me("jump across");
          break;
        case 1:
          force_me("crawl along branch");
          break;
        }
        break;
      case JUNG_ROOM4 + "jag_lair_entry":
        switch (leaving_lair){
        case -1..0:
          switch(entry){
          case CLIMB:
            force_me("climb tree");
            break;
          case SCRAMBLE:
            force_me("scramble under fern");
            break;
          case SQUEEZE:
            force_me("squeeze through thicket");
            break;
          }
          break;
        case 1:
          reach_destination();
          break;
        }
        break;
      case JUNG_ROOM + "jaguar_lair":
        switch(leaving_lair){
        case -1..0:
          if (query_property("posed")== "sleeping in a little bed"){
            if (!random(7)){
              wake_up();
              return;
            } else {
              if (!random(3)){
                switch(random(7)){
                case 0..3:
                  force_me("emote %^CYAN%^snores%^RESET%^ lightly");
                  break;
                case 4:
                  force_me("emote %^ORANGE%^purrs%^RESET%^ in his sleep");
                  break;
                case 5:
                  force_me("emote twitches in his sleep, his leg jerking"
                    +" wildly");
                  break;
                case 6:
                  force_me("emote 's eartips %^BOLD%^%^YELLOW%^swivel"
                    +" %^RESET%^in the direction of a%^BOLD%^%^GREEN%^"
                    +" sound");
                }
              }
              return;
            }
          }
          if (acting ==0){
            lair_actions();
          }
          break;
        case 1:
          if (acting==0){
            leave_lair();
          }
          break;
        }
        break;
      default:
        if( query_walking()<1){ 
          reach_destination();
        }
        break;
      }
    }
//    tell_room(ETO, "Finished heart beat");
    return;    
}

void set_leaving(int leave){
  leaving_lair = leave;
}

int query_leaving(){
  return leaving_lair;
}

void set_acting(int act){
  acting = act;
}

int query_acting(){
  return acting;
}

void die(object ob)
{
    if(objectp(current_room) && flag) current_room->set_no_clean(0);
    return ::die(ob);
}

void set_heart_beat(int h){
  ::set_heart_beat(h);
//  tell_room(ETP, "Heart beat set to " + h);
}
