//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
#define EYECOLOUR ({"%^BOLD%^%^GREEN%^green%^RESET%^",\
                    "%^BOLD%^%^YELLOW%^yellow%^RESET%^"})

inherit MOB + "tabaxi";

int eyecolour;
void create()
{
      object ob;
      ::create();
        set_name("tabaxi");
        set_id(({"tabaxi", "explorer", "tabaxi explorer" "humanoid"}));
        set_short("tabaxi explorer");
      switch (random(2)){
        case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
      set_long( (:TO, "long_desc":) );
        set_race("tabaxi");
        set_body_type("humanoid");
        set_size(2);
        set("aggressive",6);
        set_class("fighter");
        set_mlevel("fighter",45);
        set_guild_level("fighter",45);
        set_hp(random(500)+200);
        set_max_level(45);
        set_property("swarm",1);
        set_overall_ac(-55);
        set_alignment(4);
      set_speed(1);
      set_property("full attacks",1);
      set_property("no random treasure", 1);
      eyecolour = random(sizeof(EYECOLOUR));
      ob = new(TABAXOBJ + "utility_belt");
      ob->move(TO);
      force_me("wear belt");
      new(TABAXOBJ + "parchment_map")->move(ob);
      new(OBJ + "bolas")->move(ob);
      set_property("no random treasure", 1);
      set_property("not random monster", 1);
}

void reply_func(string msg, object speaker){
  string what, how, why;
  object env;
  env = ETO;
  if (!objectp(env)||!objectp(speaker)||!present(speaker, env))
  {
    return;
  }
  if (interact("request", msg) && interact("aid", msg) && (interact("village", msg) 
                                                        || interact ("veellage", msg)))
  {
    if (speaker == requester || member_array(speaker->query_name(), commanders)!=-1)
    {
      return;
    }
    force_me("say Ahm busy explorin' at the moment. Ah'll help thee veelage when Ah get back");
    requester = speaker;
  }
  if (requester == speaker && interact("yes", msg)|| interact ("yeah", msg) || interact ("yep", msg) || interact ("yah", msg))
  {
    give_belt(speaker);
  }
  if (requester == speaker) requester = 0;
  if (interact("lost", msg) || interact ("find", msg) || interact("where", msg) || interact ("locat", msg))
  {
    force_me("say Are jew lost or looking for sumthin? ");
    requester = speaker;
  }
}

void give_belt(object who){
  if (!present("utility belt", TO))
  {
    force_me("say I have nuthin' to give jew for 'elp at thee moment. Maybee another time?");
    return;
  }
  force_me("say Well, ah can' leave jew strugglin' in thee jongle. Maybee thees will elp jew? Jus' remember thee tabaxi kindly if wee need jor 'elp sumtime");
  force_me("give belt to " + who->query_name());
  if (present("utility belt", TO) && !present("utility belt", who))
  {
    force_me("Well, jew can' carry eet jus' now. Ask me again when jew have more space");
  }
}

string long_desc(){
  string desc;
  desc = "%^ORANGE%^This tabaxi is carrying a backpack and a belt equipped"
              +" with various utility items. A fedora style hat is propped"
              +" rakishly on " + QP + "hat. " + capitalize(QP)
              +" brownish red coat has rosetted spots. " + capitalize(QS)
              +" is tall and slender, with eyes of "
              + EYECOLOUR[eyecolour] +"%^ORANGE%^. "
              + capitalize(QS) + " has quick, stealthy movements, and " 
              + QP +" coat"
              +" pattern provides " + QO + " with natural camouflage.";
  return desc;
}
