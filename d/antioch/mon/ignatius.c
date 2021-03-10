#include <std.h>

inherit "/std/monster";

void create() 
{
  ::create();
  set_name("ignatius");
  set_id(({"ignatius, the wizard"}));
  set("race", "human");
  set_gender("male");
set("short","Ignatius, The once good protector of Antioch");
  set_long("This is Ignatius, the former protector of Antioch and now its destructor, since he went insane.  Fortunately, he remains inside his tower.");
set_level(31);
    set_body_type("human");
  set_class("mage");
  set_guild_level("mage",18);
  set("aggressive",22);
  set_alignment(9);
  set_size(2);
   set_hd(31,0);
  set_wimpy(30);
  set_wielding_limbs(({"right hand"}));
  set_spell_chance(90);
  set_spells( ({
                "hideous laughter",
                "magic missile",
                "lightning bolt",
               "cone of cold",
                 "chain lightning",
                "color spray"
            }) );
  //add_money("gold",1000+random(1000));
set_hp(1000);
  set_mp(300);
  set_exp(25000);
set_overall_ac(0);
  //new("/d/antioch/obj/wand.c")->move(this_object());
  command("wield wand");
}


void heart_beat(){
   ::heart_beat();
  if(!objectp(TO)) return;
  if((TO->query_hp()+1) > TO->query_max_hp())
    TO->set_hp(TO->query_max_hp());
    else TO->add_hp(1);
}

void reset(){
  object ob;
  ::reset();
/*
  if(!present("scroll")){
    ob = new("/d/magic/scroll");
    ob->set_spell(6);
    ob->move(TO);
  }
*/
}
