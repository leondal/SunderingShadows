#include "std.h";

inherit "/std/monster";

void create() {
        object hammer,armour;
    ::create();
	set_name("knave");
	set_id( ({ "knave", "young man" }) );
	set_race("human");
	set_gender("male");
	set("short", "Castle knave");
	set("long", "A boy longing to become a well-known knight.\n");
	set_level(6);
	set_body_type("human");
	set_class("fighter");
  	set("aggressive", 0);
  	set_alignment(4);
  	set_size(2);
	set_hd(6, 1);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        hammer = new("/d/common/obj/weapon/warhammer");
	hammer->set_name("knave's hammer");
	hammer->set_id( ({"hammer","knave'hammer"}) );
	hammer->set_short("A solid hammer, used by the castle knaves");
	hammer->set_long("A hammer, used by the knaves of Marleen's castle");
        hammer->set_value(1);
        hammer->move(this_object());
      	command("wield hammer");
	armour = new("/d/common/obj/armour/hide");
	armour->set_name("castle leather");
armour->set_id( ({"leather","castle leather","armor","leather armor"}));
	armour->set_short("A leather armour with the castle's emblem on it.");
	armour->set_long("A leather armour with the emblem of Marleen's castle depicted on it. It looks like a knave's armour !");
	armour->set_value(4);
	armour->move(this_object());
      	command("wear leather");
}