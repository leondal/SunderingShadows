inherit "/std/monster";

void create() {
  ::create();
  set_name("thessingthorn");
  set_id(({"thessingthorn","thess","image of thessingthorn", "image", "sister"}));
  set("race","human");
  set_gender("female");
  set("short","%^RESET%^An image of %^RESET%^%^RED%^Thessingthorn%^RESET%^");
  set("long","Like her sisters, Thessingthorn is so ghastly looking, when\n"+
             "looked upon by her, any creature weakens with fright.");
  set_level(8);
  set_body_type("human");
  set_class("mage");
  set_mlevel("mage", 8);
  set_guild_level("mage",8);
  add_search_path("/cmds/mage");
  set("aggressive", 20);
  set_new_exp(10, "high");
  set_alignment(8);
  set_size(2);
  set_hd(8,1);
  set_stats("intelligence",18);
  set_stats("wisdom",13);
  set_stats("strength",9);
  set_stats("charisma",1);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_hp(76);
  set_wielding_limbs(({"right hand"}));
  new("/d/deku/weapons/dagger")->move(this_object());
  command("wield dagger in right hand");
  set_emotes(5,({"%^RESET%^%^MAGENTA%^Thessinthorn says:%^RESET%^ You will pay foolish mortal!"}), 1);
  add_money("gold",random(200));
  set_spells(({"burning hands", "magic missile", "magic missile", "vampiric touch"}));
  set_spell_chance(65);
}
