
#include <std.h>
#include "../ogres.h"
inherit MONSTER;

object ob;



void create() {
    ::create();
    set_name("Rutterkin Demon");
    set_id( ({"demon", "Rutterkin", "rutterkin", "cavemon"}) );
    set_short("%^RESET%^%^BOLD%^%^BLUE%^Ru%^RESET%^%^BOLD%^%^BLACK%^t%^RESET%^%^BOLD%^%^BLUE%^"+
"terk%^RESET%^%^BOLD%^%^BLACK%^i%^RESET%^%^BOLD%^%^BLUE%^n Dem%^RESET%^%^BOLD%^%^BLACK%^o"+
"%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^");
    set_long( "%^RESET%^%^BOLD%^%^BLUE%^This malformed demon is a mass of ch%^RESET%^%^BLUE%^a"+
"%^RESET%^%^BOLD%^%^BLUE%^otically form%^RESET%^%^BLUE%^e%^RESET%^%^BOLD%^%^BLUE%^d flesh that "+
"pulses and writhes. It stands at six feet tall, yet hunches over under the weight of its own "+
"shape. Its head hangs at an odd angle, the %^RESET%^%^BOLD%^%^BLACK%^skull %^RESET%^%^BOLD%^"+
"%^BLUE%^oddly pointed. The skin covering the demon is blue-v%^RESET%^%^MAGENTA%^i%^RESET%^"+
"%^BOLD%^%^BLUE%^ol%^RESET%^%^MAGENTA%^e%^RESET%^%^BOLD%^%^BLUE%^t with patches of mot%^RESET%^"+
"%^GREEN%^t%^RESET%^%^BOLD%^%^BLUE%^led g%^RESET%^%^GREEN%^r%^RESET%^%^BOLD%^%^BLUE%^een. Two "+
"%^RESET%^%^BOLD%^%^RED%^glo%^RESET%^%^RED%^w%^RESET%^%^BOLD%^%^RED%^ing red %^RESET%^%^RED%^e"+
"%^RESET%^%^BOLD%^%^RED%^yes %^RESET%^%^BOLD%^%^BLUE%^stare out from under thick ridges. %^RESET%^"
    );
    set_race("demon");
    set_body_type("human");
    set_wielding_limbs(({"right hand", "left hand"}) );
    add_limb("fangs", "fangs",25,1,7);
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter", 17);
    set_hd(22,1);
    set_mob_magic_resistance("average");
    set_attack_bonus(3);
    set_max_hp(150+random(200));
    set_hp(query_max_hp());
    set_overall_ac(-10);
    set_property("swarm",1);
    set_property("full attacks", 1);
    set_stats("strength", 17);
   set("aggressive", 25);
    set_mob_magic_resistance("average");
    set_alignment(9);
    add_money("gold", random(500));
    add_money("silver", random(2500));
    switch(random(4)){
        case(0):
            ob = new(OBJ"blacksword.c");
            ob->move(TO);
            command("wield sword");
            ob = new("/d/common/obj/armour/mshield.c");
            ob->set_property("monsterweapon",1);
            ob->set_property("enchantment",2);
            ob->move(TO);
            command("wear shield");
        break;
        case(1):
            ob = new("/d/common/obj/weapon/double_axe.c");
            ob->set_property("monsterweapon",1);
            ob->set_property("enchantment",3);
            ob->move(TO);
            command("wield axe");
            ob = new(OBJ"bloodrobe.c");
            ob->move(TO);
            command("wear robe");
        break;
        default:
            ob = new(OBJ"blacksword.c");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wield sword");
            ob = new("/d/common/obj/armour/mshield.c");
            ob->set_property("monsterweapon",1);
            ob->set_property("enchantment",2);
            ob->move(TO);
            command("wear shield");
        break;
                        return;
    }
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
    set_resistance("electricity",10);
    set_resistance("acid",5);
    set_resistance("cold",5);
    set_resistance("fire",5);
}
