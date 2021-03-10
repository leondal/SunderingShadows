#include <std.h>
#include "../zin.h"

inherit MONSTER;

void create() {
   object ob;
    ::create();
    seteuid(getuid());
    set_name("Kobold");
    set("id", ({"kobold", "shaman"}) );
    set("short", "The Kobold Shaman");
    set("long", "This is a nasty looking Kobold.  She stand just over"+
        "four feet tall, and contains a slight hunch in her back.  Two "+
        "crimson eyes are sunk deep into her skull which darting back "+
        "and and forth with blind obsesion.");
    set("race", "kobold");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({"right hand", "left hand"}) );
    set_hd(3,3);
    set_level(15);
    set_guild_level("cleric",15);
    set_hp(200);
    set_exp(3500);
    set_overall_ac(6);
    set_size(2);
    set_class("cleric");
    ob=new("/d/shadow/obj/weapon/quarter_staff");
    ob->set_property("enchantment",2);
    ob->move(this_object());
    new(OBJ_DIR+"shaman_robe")->move(this_object());
    command("wield staff in left hand");
    command("wear robe");
    set_spell_chance(50);
    set_spells(({
      "limb attack",
      "flame strike",
      "cause critical wounds"
    }));
}
