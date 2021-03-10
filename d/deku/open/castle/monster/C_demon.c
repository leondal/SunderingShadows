// C_demon.c
// Pator@ShadowGate
// 06/26/95

inherit "/std/monster";

void create() {
  ::create();
  set_name("svilluulla");
    set_id (({ "svilluulla","torturer" }));
    set_short("Svilluulla the torturer");
  set_long("Once he came from the cold north and he stayed with his cold, ice cold blue eyes to torture people !!\n");
  set_race("half-drow");
  set_gender("male");
  set_class("fighter");
  set_level(10);
  set("aggressive",5);
  set_alignment(0);
  set_size(3);
  set_hd(10,1);
  set_hp(query_max_hp());
  set_wielding_limbs(query_wielding_limbs());
  set_emotes(3, ({ "Torture is my life" }),0);
  set_achats(20, ({"I'll pull your legs out !!",
		     "Your mum was a ***** !!",
		     "Killing gives me a kick !!" }) );
  new("/d/common/obj/weapon/military_fork")->move(this_object());
  command("wield fork");
  add_money("copper",random(70));
}
