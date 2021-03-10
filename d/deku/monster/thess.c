#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("thessingthorn");
  set_id(({"thessingthorn","hag","seahag", "sister"}));
  set("race","human");
  set_gender("female");
  set("short","Thessingthorn, the seahag");
  set("long","Like her sisters, Thessingthorn is so ghastly looking, when\n"+
             "looked upon by her, any creature weakens with fright.");
  set_level(8);
  set_body_type("human");
  set_class("mage");
  set_guild_level("mage",10);
  set("aggressive", 20);
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
  set_wielding_limbs(({"right hand", "left hand"}));
  new("/d/common/obj/weapon/dagger")->move(TO);
  command("wield dagger in right hand");
  set_emotes(10,({"Thessingthorn says: You will pay foolish mortal!"}), 1);
  add_money("gold",random(200));
  set_spells(({"chill touch", "web", "magic missile"}));
  set_spell_chance(65);
  set_overall_ac(3);
}
