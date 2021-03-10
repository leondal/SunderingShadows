inherit "/std/monster";
void create() {
     ::create();
     set_name("skeleton");
     set_id( ({ "a skeleton", "skeleton" }) );
     set_short("A skeleton");
set_long("It just sits here watching over you, watching every move you make.\n");
     set_hd(10,10);
     set_level(10);
	set_exp(500);
     set_hp(230);
     set_gender("male");
set("race", "undead");
     set_body_type("undead");
     set("class", "skeleton");
     set("aggressive", 9);
     set_alignment( 9 );
     set_size( 2 );
set_wielding_limbs( ({ "right hand", "left hand"}) );
new("/d/antioch/weapon/skelsword.c")->move(this_object());
command("wield sword in left hand");
add_money("silver", random(20));
add_money("gold", random(30));
}
