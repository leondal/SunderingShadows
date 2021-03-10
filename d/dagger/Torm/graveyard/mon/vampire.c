inherit "/std/monster";
  
void create() {
  ::create();
  set_name("Natas");
  set_id(({"natas","vampire","elf","darkelf","drow"}));
  set("race", "undead");
  set_gender("male");
  set("short","Natas, Vampire of darkness");
    set("long","Messanger of master darkness.  This darkelf figure, this \n"+
               "living death, takes the forgotten souls to purgatory.\n");
  set_level(18);
  set_body_type("elf");
  set_class("mage");
  set("aggressive", 20);
  set_alignment(9);
  set_size(2);
  set_hd(18,1);
  set_wielding_limbs(({"right hand"}));
  set_spell_chance(80);
set_spells(({"magic missile", "lightning bolt", "monster summoning i"}));
  set_property("undead",1);
  add_money("gold",100 + random(100));
  set_hp(200);
  set_exp(3500);
  set_guild_level("mage", 10);
}

void init() {
  object obj;
if( member_array(this_player(), this_object()->query_attackers()) != -1){
    say("%^GREEN%^"+this_object()->query_cap_name()+" regenerates some of his wounds!");
    this_object()->set_hp(this_object()->query_max_hp());
  }
  ::init();
}
