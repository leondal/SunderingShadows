#include "/d/islands/dinosaur/lake/lake.h"
#include <std.h>

inherit MONSTER;

void create(){
    ::create();
    set_property("swims", 1);
    set_property("water breather", 1);
    set_name("mermaid");
    set_id( ({"merman", "fish person", "maid", "woman", "fish", "mermaid"}) );
    set_short("Mermaid");
    set_long(
      "This strange looking creature looks to be a beautiful woman from the waist up, but from the waist down her body has been replaced with that of a fish!  You can see a deep pain running in her eyes, and you get the feeling from them that this form was not her original one, and that somthing has made her this way."
    );
    set_race("merperson");
    set_gender("female");
    set_body_type("merperson");
    set_hd(20, 9);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_property("full attacks", 1);
    set_overall_ac(0);
    set_stats("strength", 18);
    set_stats("constitution", 16);
    set_stats("dexterity", 19);
    set_stats("charisma", 20);
    set("aggressive", 10);
    set_alignment(5);
    set_hp(150+random(100));
    add_limb("neck", "torso", 0, 0, 0);
    if(random(4)){
      new(OPATH "trident.c")->move(TO);
      command("wield trident");
    } else {
      new(OPATH "wdagger.c")->move(TO);
      new(OPATH  "pearl_amulet.c")->move(TO);
      command("wear amulet");
      set_class("mage");
      set_mlevel("mage", 20);
      set_guild_level("mage", 20);
      set_spells( ({"fireball", "magic missile", "lightning bolt", "cone of cold"}) );
      set_spell_chance(65);
      command("wield dagger");
    }
}
