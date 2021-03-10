#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon Weapon Shop Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("awlpike"))
      new(WEAPONPATH+"awlpike")->move(TO);
   if(!present("bardiche"))
      new(WEAPONPATH+"bardiche")->move(TO);
   if(!present("bastard"))
      new(WEAPONPATH+"bastard")->move(TO);
   if(!present("bastard_two"))
      new(WEAPONPATH+"bastard_two")->move(TO);
   if(!present("battle axe"))
      new(WEAPONPATH+"battle_axe")->move(TO);
   if(!present("bec de corbin"))
      new(WEAPONPATH+"bec_de_corbin")->move(TO);
   if(!present("bill-guisarme"))
      new(WEAPONPATH+"bill-guisarme")->move(TO);
   if(!present("broad"))
      new(WEAPONPATH+"broad")->move(TO);
   if(!present("club"))
      new(WEAPONPATH+"club")->move(TO);
   if(!present("dagger"))
      new(WEAPONPATH+"dagger")->move(TO);
   if(!present("fauchard"))
      new(WEAPONPATH+"fauchard")->move(TO);
   if(!present("flail"))
      new(WEAPONPATH+"flail")->move(TO);
   if(!present("glaive"))
      new(WEAPONPATH+"glaive")->move(TO);
   if(!present("guisarme"))
      new(WEAPONPATH+"guisarme")->move(TO);
   if(!present("halberd"))
      new(WEAPONPATH+"halberd")->move(TO);
   if(!present("handaxe"))
      new(WEAPONPATH+"handaxe")->move(TO);
   if(!present("khopesh"))
      new(WEAPONPATH+"khopesh")->move(TO);
   if(!present("knife"))
      new(WEAPONPATH+"knife")->move(TO);
   if(!present("longsword"))
      new(WEAPONPATH+"longsword")->move(TO);
   if(!present("mace"))
      new(WEAPONPATH+"mace")->move(TO);
   if(!present("military_fork"))
      new(WEAPONPATH+"military_fork")->move(TO);
   if(!present("morningstar"))
      new(WEAPONPATH+"morningstar")->move(TO);
   if(!present("partisan"))
      new(WEAPONPATH+"partisan")->move(TO);
   if(!present("pick"))
      new(WEAPONPATH+"pick")->move(TO);
   if(!present("sickle"))
      new(WEAPONPATH+"sickle")->move(TO);
   if(!present("quarter_staff"))
      new(WEAPONPATH+"quarter_staff")->move(TO);
   if(!present("scimitar"))
      new(WEAPONPATH+"scimitar")->move(TO);
   if(!present("scourge"))
      new(WEAPONPATH+"scourge")->move(TO);
   if(!present("shortsword"))
      new(WEAPONPATH+"shortsword")->move(TO);
   if(!present("spetum"))
      new(WEAPONPATH+"spetum")->move(TO);
   if(!present("trident"))
      new(WEAPONPATH+"trident")->move(TO);
   if(!present("two_hand_sword"))
      new(WEAPONPATH+"two_hand_sword")->move(TO);
   if(!present("voulge"))
      new(WEAPONPATH+"voulge")->move(TO);
   if(!present("warhammer"))
      new(WEAPONPATH+"warhammer")->move(TO);
   if(!present("whip"))
      new(WEAPONPATH+"whip")->move(TO);
}
