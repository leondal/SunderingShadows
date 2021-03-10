#include <std.h>

inherit MONSTER;

int stoned;

void create()
{
  object ob;
  
  ::create();
  set_name("Aloysius");
  set_id(({ "aloysius", "archmage" }));
  set_race("human");
  set_gender("male");
  set_short("Aloysius, the Archmage");
  set_long(
	"  Aloysius Archmagus was the Grand Master of the Mage's Guild of\n"+
	"Shadow, many years past.  Driven out by his peers when his plots and\n"+
	"hunger for ultimate power frightened and disgusted even the most\n"+
	"powerful of the evil magi.  Now he has raised an army and summons\n"+
	"all of his powers to take the City of Shadow by force, unless you\n"+
	"can stop him.  Good luck, you're going to need it.\n");
  set_level(50);
  set_body_type("human");
  set_class("mage");
  set_guild_level("mage", 40);
  set_alignment(6);
  set_size(2);
  set_hd(50,8);
  set_wimpy(30);
  set_wielding_limbs(({"right hand"}));
  set_spell_chance(90);
  set_spells( ({
                "prismatic spray",
                "magic missile",
                "finger of death",
                "cone of cold",
                "power word kill"
            }) );
  add_money("gold",1000+random(1000));
  set_hp(1000);
  set_mp(300);
  set_exp(150000);
  set_overall_ac(-4);
  ob = new("/d/shadow/obj/weapon/dagger");
  ob->set_property("enchantment",5);
  ob->set_short("Morgul Dagger");
  ob->set_long("This blade was forged in the black fires of Orodumin");
  ob->set_id(({"dagger", "morgul dagger", "morgul" }));
  ob->move(TO);
  command("wield morgul dagger");
  stoned = 30;
}


void heart_beat(){
   ::heart_beat();
  if(!objectp(TO)) return;
  if((TO->query_hp()+2) > TO->query_max_hp())
    TO->set_hp(TO->query_max_hp());
  else TO->add_hp(2);
  stoned++;
  if(stoned >= 30) {
    "/cmds/spells/s/_stoneskin"->use_spell(TO, TO->query_name() ,50, 100, "mage");
    stoned = 0;
  }
}

void reset(){
  object ob;
  ::reset();
  if(!present("scroll")){
    ob = new("/d/magic/scroll");
    ob->set_spell(9);
    ob->move(TO);
  }
}

void set_paralyzed(int time, string message) { return 1; }
