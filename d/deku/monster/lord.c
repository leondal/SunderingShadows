inherit "/std/monster";

int step;
void create() {
  ::create();
  set_name("Deadlord");
  set_id(({"deadlord","Deadlord"}));
  set_gender("male");
  set("race","undead");
  set("short","Deadlord, master of darkness");
  set("long","The deadlord is a true undead creature.  As the master of\n"+
             "darkness, Deadlord calls upon all forgotten souls for his\n"+
             "powers.");
  set_level(18);
  set_body_type("human");
  set_class("mage");
  set("aggressive",15);
  set_alignment(9);
  set_size(2);
  set_hd(18,3);
  set_overall_ac(0);
   set_exp(5000);
  set_stats("intelligence",19);
  set_stats("wisdom",14);
  set_stats("strength",17);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_stats("constitution",14);
  set_max_sp(100);
  set_sp(100);
  set_hp(122);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/deku/weapons/dagger2")->move(this_object());
  command("wield dagger in left hand");
  set_funcs(({"summon"}));
  set_func_chance(200);
  set_spell_chance(80);
   set_spells(({"lightning bolt","acid arrow","cone of cold"}));
  set_mp(200);
  set_guild_level("mage", 11);
  step = 1;
}

void summon(object targ) {
  object ob;
  if(step == 1) {
    tell_room(environment(targ), "%^RED%^The Deadlord uses his evil powers to summon monsters to his aid.\n");
    tell_room(environment(targ), "%^GREEN%^From within the shadows, monsters rush in!!");
    new("/d/deku/fortress/monster/banshee")->move(environment(this_object()));
    new("/d/deku/fortress/monster/banshee")->move(environment(this_object()));
    step = 0;
    set_func_chance(00);
    set_spell_chance(80);
    return 1;
  }
 return 1;
}
