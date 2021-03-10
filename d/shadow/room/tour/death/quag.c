inherit "/std/monster";


void create(){
  ::create();
  set_name("Quag");
  set("id", ({"shadow","Quag","quag"}) );
  set("short", "The Dark Shadow Lord, Quag");
  set("long", "This is a shadowy humannoid figure, with "+
      "powerful arms and clawed hands"
      );
  set("race", "elf");
  set_gender("male");
  set_body_type("human");
  set_level(20);
  set_hd(20,3);
  set_overall_ac(5);
  set_size(2);
  set_wielding_limbs(({"right hand","left hand"}));
  set_class("fighter");
  set_hp(300);
  set_sp(400);
  set_exp(3000);
  set_alignment(9);
  set_class("fighter");
  set("aggressive", 1);
  new("/realms/shade/shd_claw")->move(this_object());
  command("wield claw in right hand");
  new("/realms/shade/shd_claw")->move(this_object());
  command("wield claw");
  new("/realms/shade/shdw_amlt")->move(this_object());
  command("wear amulet");

}



