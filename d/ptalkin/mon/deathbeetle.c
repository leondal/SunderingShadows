inherit "/std/monster";

create() {
    ::create();
set_name("death watch beetle");
set_id(({"death watch beetle", "beetle", "deathwatch beetle"}));
set_short("death watch beetle");
set_long("%^RED%^This monstrous insect disguises itself by wearing carapaces of other giant beetles or by sticking rubbish to itself with a glue of earth and saliva.  The normal attack of this beetle is with its giant mandibles and sonic vibrations.");
set_level(7);
set_property("wimpy", 20);
   set_gender("male");
set("race", "insect");
   set_body_type("quadruped");
   set_alignment(2);
set("aggressive", 0);
set_overall_ac(3);

set_size(2);
   set_max_mp(0);
set_hd(9,8);
set_hp(50);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
add_money("silver", (15));
set_wielding_limbs( ({"head"}) );
new("/realms/svaha/weapons/mandibles")->move(this_object());
command("wield mandibles in head");
}
