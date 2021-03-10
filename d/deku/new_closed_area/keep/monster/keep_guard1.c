//Do not use this one!!!!
//Retiring it and putting variety in the keep_guard.  Styx 2/22/02

inherit "/std/monster";

create() {
  ::create();
  set_name("keep guard");
  set_id(({"guard","keep guard","orc","orc guard"}));
  set("short","Keep guard");
  set("long","This is a guard of Keep Blacktongue.  Obviously an orc because\n"+
             "of his extreme smell and stupid look.  He would do anything to\n"+
             "serve his king.\n");
  set("race","orc");
  set_gender("male");
  set_level(5);
  set_body_type("human");
  set_class("fighter");
  set("aggressive", 17);
  set_alignment(6);
  set_size(2);
  set_hd(5,1);
  set_stats("strength",17);
  set_stats("intelligence",8);
  set_stats("wisdom",5);
  set_stats("charisma",4);
  set_stats("dexterity", 11);
  set_stats("constitution",12);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/common/obj/weapon/scimitar")->move(this_object());
  command("wield scimitar");
  add_money("copper", 5);
}
