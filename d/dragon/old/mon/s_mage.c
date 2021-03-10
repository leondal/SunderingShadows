// Sanctuary Sewer mage.c

#include <std.h>
#include <daemons.h>

inherit MONSTER;

void create() {
  object ob;
  ::create();
  set_name("toris");
  set_id(({"toris","Toris","mage","magician"}));
  set_short("Toris, the evil Magician");
  set_long("%^YELLOW%^
The robed figure, very old and wise, looks upon you with calm glowing eyes.
This figure has lived in these sewers for many centuries.  The eyes of this
figure show she hasn't seen the light of day for many years.  Her skin, 
as pale as the moon, has many wondrous tattoo's.  Her hair, as gray as the
stone around, shows the true age of the figured woman.
  ");
  set_hd(20, 5);
  set_hp(225);
  set_exp(12000);
  set_body_type("human");
  set_class("mage");
  set_guild_level("mage", 20);
  set_spells(({ "magic missile",
                "fireball",
                "lightning bolt",
                "cone of cold"}));
  set_spell_chance(0);
  set_race("elf");
  set_stats("strength", 16);
  set_stats("intelligence", 19);
  set_stats("wisdom", 13);
  set_stats("constitution", 15);
  set_stats("dexterity", 18);
  set_gender("female");
  set_funcs(({"trans_player"}));
  set_func_chance(100);
  set_overall_ac(0);
  ob = new("/d/magic/scroll");
  ob->set_spell_name("animate dead");
  ob->move(TO);
  new("/d/dragon/obj/misc/wand")->move(this_object());
  set_alignment(9);
  set_mob_magic_resistance("average");
}

void init() {
  ::init();
  if(avatarp(TP)) return;
  if(TP->query_invis()) {
    tell_room(ETO, "%^MAGENTA%^Toris says: %^YELLOW%^So you are trying to sneak up upon me.  Because of that foolish mortal, you will die.");
tell_room(ETO, "\n\n%^GREEN%^With a few hand gestures from the magican Toris, "+TPQCN+" becomes visible for all to see.");
    TP->force_me("vis");
    kill_ob(TP, 1);
    return 1;
  } else {
    if(!TP->query_invis() && ALIGN->is_evil(TP)) {
      tell_room(ETO,"%^YELLOW%^What can i do for you, "+TP->query_race()+"!");
      return 1;
    }
    kill_ob(TP, 1);
  }
}


void trans_player(object targ) {
  if(SAVING_D->saving_throw(targ, "spells")) {
    "cmds/spells/m/_monster_summoning_ii"->use_spell(TO,0,30,100,"mage");
    set_func_chance(0);
    set_spell_chance(101);
    tell_room(ETO, "\n\n%^MAGENTA%^Toris says: %^RED%^How dare you enter my sanctuary, foolish mortal.");
  } else {
    set_func_chance(0);
    set_spell_chance(101);
    tell_room(ETO, "\n\n%^MAGENTA%^Toris says: %^RED%^How dare you enter my sanctuary.  For this foolish act, BEGONE.");
    TP->move_player("/d/dragon/sewer/sewer13");
  }
  execute_attack();
  call_out("try_again", 140);
}

void try_again() {
  set_func_chance(101);
  set_spell_chance(0);
}
