inherit "/std/monster";

create() {
  object fangs;
    ::create();
   set_name("lizard");
set_id(({"lizard", "iguana"}));
   set_short("A lizard");
   set_level(3);
   set("long", "This is a small violent lizard, snapping wildly at you.\n");
   set("race", "lizard");
   set_gender("male");
   set_body_type("quadruped");
	set_wielding_limbs(({"head"}));
   set_alignment(2);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",5);
   set_stats("charisma",3);
   set_stats("dexterity",18);
   set_stats("constitution",14);
   set_max_mp(0);
set_hd(9,1);
set_hp(50);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
   new("/d/shadow/mon/obj/fangs")->move(this_object());
command("wield fangs in head");
}

