//Updated to bring in line with area difficulty - Octothorpe 4/15/10

inherit "/d/common/obj/weapon/giant_battle_axe.c";

create() {
    ::create();
   set_id(({ "axe","giant axe","giant battle axe","battle axe" }));
   set_name("giant axe");
   set_short("%^BOLD%^%^BLACK%^Giant Axe%^RESET%^");
   set_value(3000);
   set_property("enchantment",3+random(2));
}
