inherit "/std/monster";

void create() {
     ::create();
     set_name("three armed creature");
     set_id(({"three armed", "creature", "a three armed creature"}));
     set_short("A three armed creature");
     set_long("The creature has a satanic star ingraved in his eyes.\n");
     set_alignment(9);
     set("aggressive", 9);
     set_gender("male");
     set_body_type("demon");
     set("race", "demon");
     set("class", "satanic");
     set_hp(600);
     set_level(14);
     set_exp(3000);
      add_limb("middle arm",0,0,0,0);
set_wielding_limbs(({"middle arm"}));
     new("/d/antioch/weapon/arm.c")->move(this_object());
command("wield arm in middle arm");

set_emotes(10, ({
"The Three armed creature rips his arm off, AND WIELDS IT."
}), 0);
}
