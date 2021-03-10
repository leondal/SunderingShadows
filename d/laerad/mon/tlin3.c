//Set to inherit from tlininherit.c - Octothorpe 1/7/10
//Coded by the one and only master of monsters...BANE//
// adding id of laeradmon, lowered scroll frequency, etc. *Styx* 12/20/03, last change 10/31/98

#include <std.h>
inherit "/d/laerad/mon/tlininherit.c";

void create(){
    int num;
    ::create();
    set_class("mage");
    set_guild_level("mage",19);
    set_hd(17,3);
    set_attack_bonus(7);
    set_spells(({
       "magic missile",
       "fireball",
       "lightning bolt",
	   "lightning orb",
       "cone of cold",
	   "shocking grasp",
	   "shout",
       "vampiric touch"
	}));
    set_spell_chance(60);
   set_exp(12500);
    if(random(10) < 1) {
       num = random(6);
       if(num) {
          new("/d/laerad/obj/bracers"+num)->move(TO);
       }
	   else{
          new("/d/laerad/obj/bracers")->move(TO);
       }
       command("wear bracers");
    }
    set_stats("intelligence",19);
}

void reset(){
    object ob;
    ::reset();
    if(!present("scroll") && !random(4)){
       ob=new("/d/magic/scroll");
       ob->set_spell(8);
       ob->move(TO);
    }
}
