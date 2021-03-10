//removed the extra eddb databases while updating his storeroom - Styx 9/4/01

#include "/d/shadow/mon/melnmarn.h"
inherit "/std/vendor";
object ob;
void create() {
    ::create();
    set_name("cervantes");
    set_id( ({ "Cervantes", "cervantes","kinnesaruda", "shop keeper", "shopkeeper"}) );
    set_short("Cervantes of the Kinnesaruda.");
    set("aggressive", 0);
    set_level(80);
    set_property("full attacks", 1);
    set_long(
      "   Cervantes is among the very few Kinnesaruda warriors who has attempted to live within the bounds of society.  Said to be over two hundred years old, Cervantes finally escaped the influence of Intruder.\n"
      +"   He can still hear Intruder's voice, though...  It whispers to him at night, beckoning him to return to his rightful lord..."
    );
    set_gender("male");
    set_alignment(4);
    set_race("human");
    set_overall_ac(-20);
    add_money("gold", random(8800));
    set_size(2);
    set_body_type("human");
    set_hd(80,16);
    set_hp(2000+random(6000));
    set_max_hp(query_hp()); 
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
    set_mob_magic_resistance("average");
  
    ob = new("/d/attaya/seneca/obj/claw.c");
    if(random(25) != 10) { ob->set_property("monsterweapon", 1); }
    ob->move(TO);
    ob = new("/d/attaya/seneca/obj/claw.c");
    if(random(25) != 10) { ob->set_property("monsterweapon", 1); }
    ob->move(TO);
    command("wield blades in right hand");
    command ("wield blades 2 in left hand");
    set_storage_room("/d/attaya/seneca/storage/pawn_storage.c");
    set_exp(query_hp()*10);
//    remove_std_db();
//   remove_dbs(({"armors","vendor","weapons"}));
//   remove_random_act_dbs(({"armorsrandom"}));
}

void die(object ob) { 
    message("broadcast","%^BOLD%^%^MAGENTA%^The skies over Seneca suddenly flash a brilliant purple and you hear a horrible shriek!",users());  
    :: die(TO);
}
