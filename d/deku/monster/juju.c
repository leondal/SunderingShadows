//I'm modifying him to be more like the actual AD&D Juju Zombie 
//He doesn't cast spells, has high magic resistance, and 
//only +1 weapons hurt him - Saide 11/24/03

#include <std.h>
inherit MONSTER;

create() {
  ::create();
   set_name("Zombie");
   set_id(({"juju","zombie","Zombie","juju zombie","Juju","undead"}));
   set_gender("male");
   set_race("zombie");
   set_short("A juju zombie");
   set_long("%^RESET%^This creature was obviously a human at "+
   "one time, however, that time has gone.  It is now "+
   "deceased and its flesh has began the inevitable "+
   "process of decaying, it is now a %^BOLD%^%^GREEN%^"+
   "sickly%^RESET%^ gray color that resembles a hard "+
   "leather more than flesh.  Its nude body is in fairly "+
   "good condition, suggesting that its decaying "+
   "process has only recently began.  Its long hair is "+
   "filthy and littered with dirt and grime.  "+
   "Its eyes burn %^RED%^brightly%^RESET%^ with an "+
   "intense %^RED%^hatred%^RESET%^, it is almost as "+
   "if this creature understands its condition and "+
   "loathes anything that lives.");
   
   set_body_type("human");
   set_alignment(6);
   set("aggressive",30);
   	set_hd(22,1);
   	set_hp(255 + random(31));
	set_new_exp(20, "normal");
   //set_exp(13700);
   set_stats("strength",18);
   set_stats("wisdom",10);
   set_stats("intelligence",14);
   set_stats("dexterity",12);
   set_stats("charisma",4);
   set_stats("constitution",12);
   set_property("undead",1);
   //set_property("no death",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   add_money("gold", random(100));
   new("/d/common/obj/weapon/shortsword")->move(TO); 
   command("wield sword");  
   new("/d/common/obj/weapon/shortsword")->move(TO);
   command("wield sword");
}
