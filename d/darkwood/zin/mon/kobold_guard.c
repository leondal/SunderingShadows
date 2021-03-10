#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set_name("Kobold");
    set("id", ({"kobold", "guard"}) );
    set("short", "A Kobold Temple Guard");
    set("long", "This is a mean looking Kobold.  She stand only "+
        "four feet tall, yet sneers at you with a great hatred.  "+
        "Her bloated body is covered with dirt matted hair, and "+
        "she has a huge jaw that jets forward which contain many "+
        "jagged teeth.");
    set("race", "kobold");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({"right hand", "left hand"}) );
    set_hd(2,3);
    set_level(12);
    set_hp(125);
    set_exp(1000);
    set_overall_ac(4);
    set_size(2);
    set_class("fighter");
    set_property("swarm",1);
    new("/d/shadow/obj/weapon/shortsword")->move(this_object());
    command("wield sword in right hand");
}
