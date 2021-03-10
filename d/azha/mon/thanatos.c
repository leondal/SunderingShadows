// Alexei Thanatos, Lich Prince of Azha
// thorn@shadowgate
// 15 November 2000
// Azha

#include <std.h>
#include <daemons.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("thanatos");
    set_id( ({"lich","lich thanatos", "thanatos"}) );
    set_short("%^RESET%^RED%^Alexei %^BOLD%^%^BLACK%^Thanatos,%^RESET%^RED%^ Lich %^BOLD%^BLACK%^Prince of Azha%^RESET%^");
    set_long(
@AZHA
This is Prince Alexei Thanatos, defeated Ruler of Azha in an ancient
time.  After the War of the Black Hand, Thanatos was banished to this
plane by Prince al-Hazen and the 12 holy paladins of the Imperial Guard.
Their price was the corruption of their souls.  Even worse, having
already become a lich, Thanatos could not die, even in demi-plane of
magma.  Now you see nothing of the man except a burning skeleton of
shining adamantium in white hot magical chains.  You see the blue-white
flicker of flame in the glowing sockets that serve for eyes. 
AZHA
    );
    set_race( "undead" );
    set_alignment(9);
    set_hd(48,1);
    set_class("mage");
    set_mlevel("fighter", 48);
    set_mlevel("mage", 45);
    set_gender("male");
    set("aggressive",200);
    add_money("gold",random(10000)+5000);
    set_stats("strength", 25);
    set_stats("constitution", 25);
    set_stats("dexterity", 5);
    set_stats("wisdom", 25);
    set_stats("intelligence", 25);
    set_stats("charisma", 10);
    set_body_type("humanoid");
    set_max_hp(1900);
    set_hp(1500);
    set_size(2);
    set_funcs( ({"cast_spells"}) );
    set_func_chance(80);
    set_exp(190000);
    set_property("full attacks", 1);
    set_property("weapon resistance", 3);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("magic", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");
}

void init(){
    ::init();
    if(!query_property("Gflagprop")) {
      new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO->query_name(),50, 100, "mage");
      set_property("Gflagprop", 1);
    }
    if(!wizardp(TP)){
      kill_ob(TP, 1);
    }
    if(!query_property("Gchaosprop")) {
	  new("/d/azha/equip/fort/swordchaos")->move(TO);
      if(present("chaos", TO)) TO->force_me("wield chaos");
      set_property("Gchaosprop", 1);
    }
}


void cast_spells(object targ){
    int X;
    X = 14;

    if(!TO->query_stoneSkinned()) {
      if(!random(3))
	    new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO->query_name(),50, 100, "mage");
	  return; 
    }

    switch(random(X)){
      case 0:
      case 1:
      case 2:
      case 3:
        new("/cmds/spells/m/_magic_missile")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      case 4:
        new("/cmds/spells/w/_web")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      case 5:
      case 6:
        new("/cmds/spells/c/_chain_lightning")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      case 7:
      case 8:
        new("/cmds/spells/l/_lightning_bolt")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      case 9:
      case 10:
      case 11:
        new("/cmds/spells/f/_fireball")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      case 12:
        new("/cmds/spells/p/_powerword_kill")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      case 13:
        new("/cmds/spells/v/_vampiric_touch")->use_spell(TO,targ->query_name(),50, 100, "mage");
        break;
      default:
        tell_room(ETO, "%^BOLD%^%^RED%^Thanatos' shining skeleton begins to mend itself.");
        add_hp(random(70));
    }
}



void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(query_hp() < query_max_hp())
      add_hp(random(10));
}

void set_paralyzed(int time,string message){return;}

void die(object ob) {
  message("environment",
    "%^YELLOW%^BOLD%^Suddenly, you see the flames in the eyes of Thanatos "
    "flare up!  His skeleton turns a dark black and then becomes transparent. "
    "\n%^CYAN%^The crystal skeleton shatters, leaving only a corpse of shards!"
    ,environment(TO));
  ::die(ob);
}

