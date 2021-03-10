inherit "/std/monster";
  create()
{
  ::create();
set_name("Giant Centipede");
set_id(({"centipede","giant centipede"}));
set("short","A Giant centipede");
set("long","This centipede is about 1' long, and looks mean.");
set("race","Centipede");
set_gender("male");
set_body_type("insectoid");
set_hd(1,1);
set_overall_ac(9);
set_size(1);
set_wielding_limbs(({"right fore leg","left fore leg"}));
set_max_hp(2);
set_hp(2);
set_max_sp(1);
set_sp(1);
//set_exp(35);
set_exp(400);
set_stats("strength",1);
set_stats("intelligence",0);
set_stats("dexterity",2);
set_stats("constitution",1);
set_stats("charisma",1);
set_stats("wisdom",0);
set_class("fighter");
set("agressive",3);
set_property("pincer",1);
new("/d/shadow/mon/obj/pincers.c")->move(this_object());
command("wield pincer in left fore leg");
}
