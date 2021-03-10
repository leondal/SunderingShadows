//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include "../tunnel.h"
inherit MONSTER;

void whip(object targ);

void create()
{
      ::create();
  	set_name("malevolant rock devil");
  	set_id(({"devil","rock devil","malevolant rock devil","monster",
                       "tun mon",}));
  	set_short("%^BOLD%^%^RED%^malevolant %^BOLD%^"
               +"%^BLACK%^rock d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v"
               +"%^RED%^i%^BOLD%^%^BLACK%^l");
  	set_long("%^BOLD%^%^BLACK%^The creature stands almost eight feet"
              +" tall. It has the build of an athletic, muscular humanoid"
              +", but is black skinned and seems formed from the stuff of"
              +" the r%^RESET%^o%^BOLD%^%^BLACK%^cks themselves. It wears"
              +" a pair of %^BOLD%^%^RED%^fine red pants%^BOLD%^%^BLACK%^"
              +", and carries a whip of %^BOLD%^%^RED%^f%^RESET%^%^RED%^i"
              +"%^BOLD%^%^RED%^re%^BOLD%^%^BLACK%^ in one hand.\n");
  	set_race("devil");
  	set_body_type("humanoid");
      set_wielding_limbs(({"right hand","left hand"}));
  	set_gender("male");
  	set_hd(55,12);
  	set_size(3);
  	set("aggressive",25);
	set_class("mage");
	set_mlevel("mage",40);
	set_level(40);
	set_guild_level("mage",40);
   	set_hp(random(50)+300);
	set_speed(30);
 	set_nogo(({ "/d/attaya/rooms/tun15",
                 "/d/attaya/rooms/lair",
                "/d/attaya/rooms/tun17",
               "/d/attaya/rooms/tun20",
              "/d/attaya/rooms/tun14"}));
   	set_exp(10000);
	set_max_level(45);
	set_property("swarm",1);
  	set_overall_ac(-15);
  	set_alignment(4);
      set_mob_magic_resistance("very low");
      set_property("weapon resistance",10);
      set_property("full attacks",1);
      set_spell_chance(20);
  	set_emotes(10,({
		"The %^BOLD%^%^BLACK%^malevolant rock d%^RESET%^%^RED%^e"
           +"%^BOLD%^%^BLACK%^vil cracks its %^BOLD%^%^RED%^f%^YELLOW%^l"
           +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^ming w%^YELLOW%^h%^RESET%^"
           +"%^RED%^i%^BOLD%^%^RED%^p",

            "The %^BOLD%^%^BLACK%^dev%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^l"
           +" stamps his feet, making the ground shake beneath you.",

            "%^BOLD%^%^BLACK%^The dev%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^l's"
           +" %^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^y%^BOLD%^%^RED%^es%^BOLD%^"
           +"%^BLACK%^ light up with an inner %^BOLD%^%^RED%^f%^YELLOW%^i"
           +"%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^!",

            "The %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck"
           +" d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i%^BOLD%^"
           +"%^BLACK%^l %^RESET%^seems completely unaffected by"
           +" %^YELLOW%^any%^RESET%^ of the weapons striking its stoney"
           +" skin.",

            "The blows seem to bounce off of the %^BOLD%^%^BLACK%^r"
           +"%^RESET%^o%^BOLD%^%^BLACK%^ck d%^RESET%^%^RED%^e%^BOLD%^"
           +"%^BLACK%^v%^RED%^i%^BOLD%^%^BLACK%^l %^RESET%^, which seems"
           +" to be made from solid stone!",
    	}),1);
      set_spells( ({"prismatic spray","dispel magic", "magic missile",
                 "hideous laughter", "scorcher" }) );
      new(OBJ+"firewhip")->move(TO);
}
void init()
{
  ::init();
  force_me("wield whip");
}
void die(mixed ob)
{
  object whip;
  if (!objectp(TO)||!objectp(ETO)){return;}
  whip = present("devil whip", TO);
  if (objectp(whip) &&random(8)>0)
  {
    tell_room(ETO,"%^RED%^As the " + query_short()
                + "%^RED%^ falls, its " + whip->query_short()
                + "%^RED%^ is consumed in flame!", TO);
    whip->remove(TO);
  }
  ::die(ob);
}
