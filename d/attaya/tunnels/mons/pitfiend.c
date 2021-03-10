//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include "../tunnel.h"
inherit LRESIST_MOB;
#include <daemons.h>
int stoneskins;


void fear(object targ);

object choose_victim();
int spell_effect();
void fear();
void stoneskin();
int aggfunc();
void summon_devils();
int query_opponent_levels();

void create(){
      ::create();

  	set_name("pit fiend");
  	set_id(({"devil","pit fiend","pit devil","fiend","monster",
                       "tun mon",}));
  	set_short("%^BOLD%^%^RED%^terr%^RESET%^%^RED%^i%^BOLD%^%^RED%^ble"
               +" %^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^%^BLACK%^t"
               +" %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^GREEN%^e"
               +"%^RED%^nd%^BOLD%^%^RED%^");
  	set_long("%^RESET%^%^RED%^This %^RESET%^%^MAGENTA%^terrible"
              +" %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^e"
              +"%^BOLD%^%^BLACK%^n%^RED%^d%^RESET%^%^RED%^ stands"
              +" over twelve feet tall. %^BOLD%^%^BLACK%^Black bat wings"
              +" %^RESET%^%^RED%^wrap around its body like a"
              +" %^MAGENTA%^grotesque %^RED%^cloak and the whole"
              +" of its form is %^BOLD%^%^RED%^w%^RESET%^%^RED%^r"
              +"%^BOLD%^%^RED%^ea%^RESET%^%^RED%^t%^BOLD%^%^RED%^h"
              +"%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^%^RED%^in"
              +" %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^"
              +"%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^RED%^s%^RESET%^%^RED%^"
              +". Its vicious %^RESET%^%^ORANGE%^f%^GREEN%^a%^ORANGE%^ngs"
              +" %^RED%^dr%^GREEN%^i%^RED%^p with a %^GREEN%^v%^BOLD%^"
              +"%^GREEN%^i%^RESET%^%^GREEN%^le l%^BOLD%^%^GREEN%^i"
              +"%^RESET%^%^GREEN%^qu%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^d"
              +" %^RED%^and its body is covered with"
              +" %^BOLD%^%^RED%^s%^RESET%^%^RED%^c%^BOLD%^%^RED%^a"
              +"%^RESET%^%^RED%^l%^BOLD%^%^RED%^e%^RESET%^%^RED%^s.");
  	set_race("devil");
  	set_body_type("humanoid");
  	set_gender("male");
  	set_hd(60,120);
  	set_size(3);
  	set("aggressive","aggfunc");
	set_class("mage");
	set_mlevel("mage",50);
	set_level(50);
	set_guild_level("mage",50);
   	set_hp(random(400)+400);
//	set_speed(30);
  	set_nogo(({ "/d/attaya/tun15", "/d/attaya/lair",
   "/d/attaya/tun17", "/d/attaya/tun20", "/d/attaya/tun14"}));
   	set_exp(30000);
	set_max_level(60);
	set_property("swarm",1);
  	set_overall_ac(-20);
      set_funcs(({"fear"}));
      set_func_chance(50);
  	set_alignment(4);
      set_mob_magic_resistance("low");
      set_property("weapon resistance",3);
      set_property("full attacks",1);
      set_spell_chance(50);
      stoneskins = 2 + random(4);
  	set_emotes(10,({
		"%^BOLD%^%^RED%^P%^RESET%^%^RED%^i%^BOLD%^%^RED%^t F%^RESET%^"
           +"%^GREEN%^i%^BOLD%^%^RED%^end %^RESET%^%^RED%^spreads its"
           +" %^BOLD%^%^BLACK%^black wings%^RESET%^%^RED%^ wide and"
           +" throws its head back, howling in %^BOLD%^%^RED%^rage!",

            "",

            "",
    	}),1);
      set_spells( ({"fireball","hold person", "hideous laughter",
                                                      "scorcher" }) );      }

void stoneskin()
{
  if (!objectp(TO)||!objectp(ETO)){return;}
  new("/cmds/spells/s/_stoneskin.c")->use_spell(TO, TO, TO->query_class_level("mage"), 100, "mage" );
  stoneskins-=1;
}

void fear(object targ)
{
  int i;
  object* ob, victim;
  if (!objectp(TO)||!objectp(ETO)||!objectp(targ)){return;}
  tell_room(ETO, "%^BOLD%^%^RED%^P%^RESET%^%^RED%^i%^BOLD%^%^RED%^t"
                +" F%^RESET%^%^GREEN%^i%^BOLD%^%^RED%^end%^GREEN%^"
                +" spreads %^RESET%^%^RED%^ its %^BOLD%^%^BLACK%^wings"
                +" %^RESET%^%^RED%^ and sends a %^RESET%^MAGENTA%^wave"
                +" %^RESET%^%^RED%^of %^BOLD%^%^CYAN%^fear%^RESET%^"
                +" %^RED%^through the room!");
  for (i=0;i<sizeof(all_living(ETO));i++)
  {
    ob = all_living(ETO)[i];
    if (objectp(ob))
    {
      if (!ob->query_true_invis() && (string)ob->query_race()!="devil"
          && (string)ob->query_race()!="devilkin"
          && ob->query_property("scared")<1)
      {
        if(!"daemon/saving_d"->saving_throw(ob,"rod_staff_wand", -15))
        {
          switch(random(3))
          {
          case 0:
            tell_object(ob, "%^BOLD%^%^GREEN%^Panic overwhelms you - you"
                           +" must get away!");
            ob->force_me("flee");
            tell_room(ETO, ob->query_cap_name() + " is overwhelmed with"
                        +" panic!",ob);
            break;
          case 1:
            tell_object(ob, "%^BOLD%^%^GREEN%^Panic overwhelms you - you"
                           +" %^BOLD%^%^CYAN%^freeze%^BOLD%^%^GREEN%^!");
           ob->set_paralyzed(10, "You are %^BOLD%^%^CYAN%^frozen%^RESET%^"
                                 +" in %^BOLD%^%^GREEN%^fear%^RESET%^!");
            tell_room(ETO, ob->query_cap_name()+" %^BOLD%^%^CYAN%^freezes"
                        +" in %^BOLD%^%^GREEN%^fear%^RESET%^!",ob);
            break;
          case 2:
            victim = choose_victim();
            if (!objectp(victim)){return;}
            tell_object(ob,"%^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^a%^BOLD%^"
                        +"%^GREEN%^n%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^c"
                          +" washes through you and you turn your weapon"
                          +" on " + victim->query_cap_name()
                          +"%^BOLD%^%^GREEN%^!");
            tell_room(ETO,"%^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^a%^BOLD%^"
                        +"%^GREEN%^n%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^c"
                          +" washes over "+ ob->query_cap_name() + " and "
                          + ob->query_subjective() + " turns on "
                         + victim->query_cap_name() + "%^BOLD%^%^GREEN%^!"
                          ,ob);
            ob->add_attacker(victim);
          }
          ob->set_property("scared", 4);
        }
        else
        {
         tell_object(ob,"%^BOLD%^%^RED%^You stand %^BLUE%^bravely %^RED%^"
                        +" in the face of the devil's"
                        +" %^RESET%^%^MAGENTA%^a%^BLUE%^u%^MAGENTA%^ra of"
                        +" %^BOLD%^%^CYAN%^fe%^RESET%^%^CYAN%^a%^BOLD%^"
                        +"%^CYAN%^r%^BOLD%^%^RED%^!");
          tell_room(ETO,"%^BOLD%^%^RED%^" + ob->query_cap_name()
                       +"%^BOLD%^%^RED%^stands %^BLUE%^bravely %^RED%^"
                       +" in the face of the devil's"
                       +" %^RESET%^%^MAGENTA%^a%^BLUE%^u%^MAGENTA%^ra of"
                       +" %^BOLD%^%^CYAN%^fe%^RESET%^%^CYAN%^a%^BOLD%^"
                       +"%^CYAN%^r%^BOLD%^%^RED%^!",ob);
        }
      }
      else
      {
        tell_object(ob, "The wave of %^BOLD%^%^CYAN%^fear%^RESET%^ passes"
                       +" you by.");
        if (!ob->query_true_invis() &&(string)ob->query_race()!="devilkin"
                                    &&(string)ob->query_race() != "devil")
        {
          tell_room(ETO, "The wave of %^BOLD%^%^CYAN%^fear%^RESET%^"
                       +" passes " + ob->query_cap_name() + " by.", ob);

        }
        if ((int)ob->query_property("scared")>0)
        {
          ob->set_proprty("scared", -1);
        }

      }

    }
  }
  return 1;
}

object choose_victim()
{
  object *victims;
  object victim;
  if (!objectp(TO)||!objectp(ETO)){return victim;}
  victims = all_living(ETO);
  if (sizeof(victims)<2){return victim;}
  victims = filter_array(victims, "is_non_immortal_player", FILTERS_D);
  victim=TO;
  while (victim==TO)
  {
    victim = victims[random(sizeof(victims))];
  }
  return victim;
}

int spell_effect()
{
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  force_me("watch");
  command("cast mage stoneskin on fiend");

  new("/cmds/spells/s/_stoneskin.c")->use_spell(TO, TO,
                                     TO->query_class_level("mage"), 100, "mage" );
  stoneskins-=1;
  call_out("spell_effect2",3);
}

void spell_effect2(){
   command("cast mage blink");
   new("/cmds/spells/w/_wall_of_fire.c")->use_spell(TO, TO,
                                       TO->query_class_level("mage"), 100, "mage" );
}

void catch_tell(string str)
{
  if (!objectp(TO)||!objectp(ETO)){return;}
  if (interact("The force protecting you breaks apart", str))
  {
     if (query_opponent_levels()> 50 + random(40)){
       summon_devils();
     }
     call_out("stoneskin", 2+random(2));
  }
  else
  {
    ::catch_tell(str);
  }
}

int aggfunc()
{
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  if(TP->query_true_invis())
  {
 //   return 0;
  }

  kill_ob(TP,1);
  call_out("spell_effect",0);
  force_me("kill "+TPQN+ "");
  return 1;
}

int query_opponent_levels(){
  object * foes;
  string * classes;
  int i,j, levels;
  if (!objectp(ETO)||!objectp(TO)){return 0;}
  foes = query_attackers();
  if (sizeof(foes)<1){return 0;}
  levels = 0;
  for (i=0;i<sizeof(foes);i++){
    classes = foes[i]->query_classes();
    if (sizeof(classes)>0){
      for (j=0; j<sizeof(classes);j++){
        if (j<1){
          levels += ((int)foes[i]->query_class_level(classes[j]));
        } else{
          levels += ((int)foes[i]->query_class_level(classes[j])/(j+2));
        }
      }
    }
  }
  return levels;
}

void summon_devils(){
  if (!objectp(TO)||!objectp(ETO)||present("hellgate",ETO)){return;}
  tell_room(ETO, "%^BOLD%^%^RED%^Flames%^RESET%^%^MAGENTA%^ and %^BOLD%^"
                +"%^RED%^heat %^RESET%^%^MAGENTA%^burst from the "
                + query_short() + "'s%^RESET%^%^MAGENTA%^ body as it"
                +" opens up a gate to %^BOLD%^%^RED%^Hell%^RESET%^"
                +"%^MAGENTA%^. More %^BOLD%^%^RED%^Devils %^RESET%^"
                +"%^MAGENTA%^start pouring through!",TO);
  new(OBJ+"hellgate")->move(TO);
}
