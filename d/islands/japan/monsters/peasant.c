#include <std.h>

inherit MONSTER;

void make_me();

void create(){
       ::create();
       set_name("Peasant");
       set_id(({"peasant","smelly peasant","farmer"}));
       set("short","Peasant");
       set("long",
@OLI
       This ruffian is a member of a large group of people who
hunts through Tharis for elves and beats them, sometimes to death.
Rumors have it that these ruffians are paid by the duke himself.
But rumors will be rumors. They are large burly men. Most of these
ruffians are mere fighters, some have been granted small abilities
to cast spells. The hatred of elves has been bred deeply into these
people. Once again you are forced to wonder if such hatred is a
result of natural things or unnatural things.
OLI
       );
       set_hd(15,1);
       set_exp(1800);
       set_stats("strength",17);
       set_stats("wisdom",17);
       set_alignment(3);
       set_size(2);
       set_body_type("human");
       add_limb("neck","neck",0,0,0);
       set_wielding_limbs(({"right hand","left hand"}));
       set_gender("male");
       set("aggressive",6);
       set_property("swarm",1);
       set_mob_magic_resistance("average");
       make_me();
       add_money("gold",random(50));
       add_money("silver",random(50));
       add_money("electrum",random(50));


}
void make_me(){
       object ob;
       int i,j,k;
       string myclass,race;

       set_race("human");
       i = random(3);
       switch(i){
       case 0:
       case 1: myclass = "cleric";
               break;
       case 2: myclass = "mage";
       }
       set_class(myclass);

       switch(myclass){
       case "cleric":
               set_hp(80);
               new("/d/tharis/obj/mrmedalion")->move(TO);
               command("wear medallion");
               ob = new("/d/shadow/obj/weapon/mace");
               ob->set_property("enchantment",1);
               ob->set_property("monsterweapon",1);
               ob->move(TO);
               command("wield mace in right hand");
               new("/d/shadow/obj/armor/chain")->move(TO);
               command("wear armor");
               set_spells(({ "hold person","hold person"}));
               set_spell_chance(50);
               break;
       case "mage":
               set_hp(60);
               new("/d/tharis/obj/mrmedalion")->move(TO);
               command("wear medallion");
               ob = new("/d/shadow/obj/weapon/dagger");
               ob->set_property("enchantment",1);
               ob->set_property("monsterweapon",1);
               ob->move(TO);
               command("wield dagger in right hand");
               set_spells(({"magic missile",
                               "lightning bolt",
                               "burning hands",
                               "wall of fire"}));
               set_spell_chance(90);
               break;
       }
}
