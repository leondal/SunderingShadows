#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"
#include "/realms/grendel/gshorts.h"

inherit MONSTER;

void create(){
    object ob;
    ::create();
    set_name("Storm Giant");
    set_short("Storm Giant");
    set_id( ({"giant", "storm", "storm giant", "Storm Giant"}) );
    set_long(
      "This gigantic humanoid towers over you at just over 26 feet tall.  Powerful muscles ripple under green tinted skin as his long green beard and hair flow around his head in the water.  He is wearing a simple tunic and sandals as he looks you over."
    );
    set_gender("male");
    set_race("giant");
    set_body_type("humanoid");
    set_size(3);
    set_hd(34+random(10), 8);
    set_class("fighter");
    set_mlevel("fighter", query_hd());
    set_max_hp(query_hd()*12);
    set_hp(query_max_hp());
    set_property("full attacks", 1);
    set_overall_ac(-4);
    set_exp(query_hd()*2000);
    set_mob_magic_resistance("average");
    ob = new("/d/shadow/obj/weapon/two_hand_sword.c");
    ob->set_property("monsterweapon", 1);
    ob->set_wc(3,10);
    ob->set_large_wc(3,10);
    ob->move(TO);
    new(OPATH "scalehelm.c")->move(TO);
    command("wear helm");
    command("wield sword");
    set_funcs( ({"bolt"}) );
    set_func_chance(30);

}

int bolt(object targ){

    if("daemon/saving_d"->saving_throw(targ, "spell")){
      tell_object(targ, "%^YELLOW%^The Storm Giant hurls a great bolt of lightning at you, but you are able to dive most of the way out of its path!%^RESET%^");
      tell_room(environment(targ), "%^YELLOW%^The storm giant hurls a great bolt of lighting at "+TARGQCN+", but "+TARGQS+" is able to gain some cover!%^RESET%^", targ);
      targ->do_damage("torso", roll_dice(5,10));
    } else {
      tell_object(targ, "%^YELLOW%^The Storm Giant strikes you full force with a bolt of lightning!");
      tell_room(environment(targ), "%^YELLOW%^The Storm Giant strikes "+TARGQCN+" squarely with a lightning bolt!%^RESET%^", targ);
      targ->do_damage("torso", roll_dice(10,10));
      targ->set_paralyzed(15, "%^YELLOW%^You are shaking from the lightning strike.%^RESET%^");
    }
    return 1;
}
