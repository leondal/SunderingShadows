
#include <std.h>
#include "../ogres.h"
inherit MONSTER;

object ob;

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
        tell_room(ETO, "%^RESET%^RED%^The demon glares in your direction. Power flares "+
"as it pulls you violently from your hiding.");
      TP->set_invis();
      kill_ob(TP, 1);
    }
}

void create() {
    ::create();
    set_name("Maurezhi Demon");
    set_id( ({"demon", "Maurezhi", "maurezhi", "cavemon"}) );
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Ma%^RESET%^%^WHITE%^u%^RESET%^%^BOLD%^%^BLACK%^re"+
"%^RESET%^%^WHITE%^zh%^RESET%^%^BOLD%^%^BLACK%^i Dem%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^"+
"%^BLACK%^n%^RESET%^");
    set_long( "%^RESET%^%^ORANGE%^This creature looks vaguely humanoid in shape but not manner"+
". Pale and hunched, the %^BOLD%^%^BLACK%^Ma%^RESET%^u%^BOLD%^%^BLACK%^re%^RESET%^zh%^BOLD%^"+
"%^BLACK%^i %^RESET%^%^ORANGE%^has tall pointed ears, a slender body and a lithe agile frame,"+
" not unlike that of an %^GREEN%^e%^RESET%^l%^GREEN%^f%^RESET%^%^ORANGE%^. But all similarities"+
" stop there, for the glowing %^YELLOW%^ye%^BLACK%^l%^YELLOW%^l%^BLACK%^o%^YELLOW%^w ey%^BLACK"+
"%^e%^YELLOW%^s %^RESET%^%^ORANGE%^and the row of sharp pointed %^WHITE%^te%^BOLD%^%^BLACK%^et"+
"%^RESET%^h%^ORANGE%^, as well as the feline claws on both hands and feet, disrupt the %^GREEN%^"+
"sy%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^v%^BOLD%^%^BLACK%^an %^RESET%^%^ORANGE%^resemblance. Clad"+
" in little more then cast off %^BOLD%^%^BLACK%^ta%^RESET%^t%^BOLD%^%^BLACK%^te%^RESET%^r%^BOLD%^"+
"%^BLACK%^s%^RESET%^%^ORANGE%^, the demon reeks of death and the horrific scent of rotting offal,"+
" not unlike the smell of a mass open %^RESET%^gra%^BLACK%^%^BOLD%^v%^RESET%^e%^ORANGE%^. It "+
"quickly becomes clear why this is when the beast hisses at you with bits of bloody, rotting "+
"flesh, clinging between the %^YELLOW%^se%^BLACK%^r%^YELLOW%^ra%^BLACK%^te%^YELLOW%^d %^RESET%^"+
"%^ORANGE%^edges of its teeth. Feral and savage, it slinks about clutching at the blood covered "+
"%^WHITE%^fe%^BOLD%^%^BLACK%^mu%^RESET%^r %^ORANGE%^it is still gnawing upon. %^RESET%^"
    );
    set_race("demon");
    set_body_type("human");
    set_wielding_limbs(({"right hand", "left hand"}) );
    add_limb("left wing","left wing",100,1,6);
    add_limb("right wing","right wing",100,1,6);
    add_limb("barbed tail", "barbed tail",50,1,8);
    add_limb("fangs", "fangs",25,1,7);
    add_limb("right talon", "right talon",50,1,3);
    add_limb("left talon", "left talon",50,1,3);
    set_size(2);
    set_class("ranger");
    set_mlevel("ranger", 18);
    set_hd(28,1);
    set_mob_magic_resistance("average");
    set_attack_bonus(3);
   set_max_level(25);
    set_max_hp(150+random(200));
    set_hp(query_max_hp());
    set_overall_ac(-5);
    set_property("swarm",1);
    set_property("full attacks", 1);
    set_stats("strength", 15);
    set("aggressive", 20);
    set_mob_magic_resistance("average");
    set_alignment(9);
    add_money("gold", random(1000));
    add_money("silver", random(2500));
    ob = new(OBJ"demonfork.c");
    ob->move(TO);
    command("wield fork");
    ob = new(OBJ"demonfork.c");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wield fork");
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
