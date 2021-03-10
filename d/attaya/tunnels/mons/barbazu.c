//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include "../tunnel.h"
inherit MONSTER;

void whip(object targ);

void create()
{
      ::create();
  	set_name("Barbazu");
  	set_id(({"devil","barbazu","barbazu devil","monster",
                       "tun mon",}));
  	set_short("%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^ie"
               +"%^BOLD%^%^GREEN%^rce %^RESET%^%^GREEN%^b%^BOLD%^"
               +"%^GREEN%^a%^RESET%^%^GREEN%^rb%^BOLD%^%^GREEN%^a"
               +"%^RESET%^%^GREEN%^zu d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
               +"%^RESET%^%^GREEN%^l%^RESET%^");
  	set_long("A %^MAGENTA%^f%^GREEN%^o%^MAGENTA%^ul%^RESET%^ humanoid"
              +" creature about 6 feet tall, with a long tail, clawed"
              +" hands and feet, pointed ears and a %^BOLD%^%^GREEN%^s"
              +"%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^ak%^RESET%^%^GREEN%^e"
              +"%^BOLD%^%^GREEN%^y%^RESET%^, disgusting beard. Its skin"
              +" looks moist, though %^BOLD%^%^GREEN%^s%^RESET%^"
              +"%^GREEN%^c%^BOLD%^%^GREEN%^aly%^RESET%^ like a %^GREEN%^r"
              +"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^pt%^BOLD%^%^GREEN%^i"
              +"%^RESET%^%^GREEN%^le's%^RESET%^.\nIt is wearing a suit of"
              +" strange, gleaming spiked banded mail.");
  	set_race("devil");
  	set_body_type("humanoid");
      set_wielding_limbs(({"right hand","left hand"}));
  	set_gender("male");
  	set_hd(55,12);
  	set_size(2);
  	set("aggressive",25);
	set_class("mage");
	set_mlevel("mage",35);
	set_level(35);
	set_guild_level("mage",35);
   	set_hp(random(50)+250 + random(100));
	set_speed(30);
 	set_nogo(({ "/d/attaya/tun15", "/d/attaya/ugstream",
   "/d/attaya/lair", "/d/attaya/tun17", "/d/attaya/tun20",}));
   	set_exp(10000);
	set_max_level(45);
	set_property("swarm",1);
  	set_overall_ac(-12);
      set_funcs(({"beard_bite", "flame"}));
      set_func_chance(25);
  	set_alignment(4);
      set_mob_magic_resistance("average");
      set_property("weapon resistance",3);
      set_property("full attacks",1);
      set_spell_chance(5);
  	set_emotes(2,({
           "The barbazu %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
          +"%^RESET%^%^GREEN%^l%^RESET%^ flickers a forked tongue out"
          +" into the air",

           "The blade of the %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
          +"%^RESET%^%^GREEN%^l's%^RESET%^ wicked looking oversized"
          +" glaive %^CYAN%^gl%^RESET%^e%^CYAN%^ams%^RESET%^ in the light"
    	}),0);
  	set_emotes(10,({
           "The barbazu %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
          +"%^RESET%^%^GREEN%^l%^RESET%^ leaps high into the air,"
          +" twiriling the glaive behind its back",

           "The barbazu %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
          +"%^RESET%^%^GREEN%^l's%^RESET%^ tail lashes out, narrowly"
          +" missing you",

           "The barbazu %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
          +"%^RESET%^%^GREEN%^l%^RESET%^ ducks low to the ground,"
          +" aiming a blow at his opponent's feet!",

           "The strange banded mail rattles noisily as the %^GREEN%^d"
          +"%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i%^RESET%^%^GREEN%^l"
          +"%^RESET%^ leaps and twirls around the battlefield",

           "The %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i%^RESET%^"
          +"%^GREEN%^l's%^RESET%^ snakelike beard %^MAGENTA%^writhes"
          +"%^RESET%^ and %^YELLOW%^snaps%^RESET%^ out towards you!",

    	}),1);

      set_spells( ({"fireball"}) );
      new(OBJ+"serrated_glaive")->move(TO);
      new(OBJ+"spiked_banded")->move(TO);


}

void init()
{
  ::init();
  force_me("wield glaive");
  force_me("wear banded");
}
void flame(object targ)
{
  int i;
  object * foes;
  object victim;
  if (!objectp(targ)||!objectp(TO)||!objectp(ETO)){return;}
  foes=TO->query_attackers();
  tell_room(ETO, "%^RED%^The barbazu %^GREEN%^d%^RED%^e%^GREEN%^v"
                +"%^BOLD%^%^RED%^i%^RESET%^%^GREEN%^l%^RESET%^"
                +" blankets the area in %^BOLD%^%^RED%^f%^YELLOW%^l"
                +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^me!");
  for(i=0;i<sizeof(foes);i++)
  {
    victim = foes[i];
    if (!objectp(victim)){break;}
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand", -15))
    {
      tell_object(victim,"%^BOLD%^%^RED%^The f%^BOLD%^%^YELLOW%^l"
                        +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes sweep over"
                        +" you!");
      tell_room(ETO,"%^BOLD%^%^RED%^The f%^BOLD%^%^YELLOW%^l"
                        +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes sweep over "
                        + victim->query_cap_name() +"!", victim);
      victim->do_damage(50+random(50));
    }
    else
    {
      tell_object(victim,"%^YELLOW%^You manage to dive out of the way of"
                        +" the %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^"
                        +"%^RED%^a%^BOLD%^%^RED%^me!");
      tell_room(ETO, "%^YELLOW%^" + victim->query_cap_name()+ "%^YELLOW%^"
                    +" manages to dive out of the way of the"
                    +" %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a"
                    +"%^BOLD%^%^RED%^me!", victim);
    }
  }
}

void beard_bite(object targ)
{
  object disease;
  if (!objectp(targ)||!objectp(TO)||!objectp(ETO)){return;}
  if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand", -13))
  {
    tell_object(targ, "Hooking the haft of its %^MAGENTA%^gl%^RESET%^a"
                     +"%^ORANGE%^i%^MAGENTA%^ve%^RESET%^ around the back"
                     +" of your neck, the  barbazu %^GREEN%^d%^RED%^e"
                     +"%^GREEN%^v%^BOLD%^%^RED%^i%^RESET%^%^GREEN%^l"
                     +"%^RESET%^ pulls you forward into the flailing"
                     +" strands of its %^GREEN%^b%^BOLD%^%^GREEN%^e"
                     +"%^RESET%^%^GREEN%^ard%^RESET%^, which whip and"
                     +" tear at your flesh, leaving you with a foul mark"
                     +" on your face!"
                      );
    tell_room(ETO, "Hooking the haft of its %^MAGENTA%^gl%^RESET%^a"
                  +"%^ORANGE%^i%^MAGENTA%^ve%^RESET%^ around the back of"
                  +targ->query_cap_name() + "'s neck, the  barbazu"
                  +" %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
                  +"%^RESET%^%^GREEN%^l%^RESET%^ pulls " +targ->QO
                  +" forward into the flailing strands of its %^GREEN%^b"
                  +"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ard%^RESET%^,"
                  +" which whip and tear at "+ targ->QP
                  +" flesh, leaving " +targ->QO+" with a foul mark on "
                  + targ->QP +" face!",targ);
    disease = present("disease", targ);
    if (objectp(disease))
    {
      if ((string)disease->query_name()=="mark")
      {
        return;
      }

    }

    new(OBJ+"devil_mark")->move(targ);
    targ->force_me("wear mark");
    return;
  }

  tell_object(targ, "The  barbazu %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^"
                   +"%^RED%^i%^RESET%^%^GREEN%^l hooks the shaft of its"
                   +" %^MAGENTA%^gl%^RESET%^a%^ORANGE%^i%^MAGENTA%^ve"
                   +"%^RESET%^ around the back of your neck and tries"
                   +" to pull you forwards, but you are just able to"
                   +" duck out of the way in time!");

  tell_room(ETO, "The  barbazu %^GREEN%^d%^RED%^e%^GREEN%^v%^BOLD%^"
                +"%^RED%^i%^RESET%^%^GREEN%^l hooks the shaft of its"
                +" %^MAGENTA%^gl%^RESET%^a%^ORANGE%^i%^MAGENTA%^ve"
                +"%^RESET%^ around the back of " +targ->query_cap_name()
                +"'s neck and tries to pull " +targ->QO + " forwards,"
                +" but " +targ->QS + " is just able to duck out of the"
                +" way in time!",targ);
}

void die(mixed ob)
{
  object glaive;
  object banded;
  if (!objectp(TO)||!objectp(ETO)){return;}
  banded = present("banded", TO);
  glaive = present("glaive", TO);
  if (objectp(glaive) &&random(8)>0)
  {
    tell_room(ETO,"%^GREEN%^As the " + query_short()
                + "%^GREEN%^ falls, its " + glaive->query_short()
                + "%^GREEN%^ is broken asunder!", TO);
    glaive->remove(TO);
  }
  if (objectp(banded) &&random(12)>0)
  {
    banded->remove(TO);
  }

  ::die(ob);
}
