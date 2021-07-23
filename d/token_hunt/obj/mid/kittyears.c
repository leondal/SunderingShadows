
inherit "/std/armour";

void create() {
    ::create();
    set_name("cat ears");
    set_id(({ "ears","kitty ears","cat ears" }));
    set_short("%^BOLD%^%^WHITE%^A l%^BLACK%^o%^RESET%^v%^BOLD%^%^BLACK%^e%^WHITE%^l%^RESET%^%^ORANGE%^y p%^WHITE%^a%^BOLD%^i%^RESET%^%^ORANGE%^r %^WHITE%^o%^BOLD%^f %^RESET%^c%^ORANGE%^a%^BOLD%^%^BLACK%^t e%^WHITE%^a%^RESET%^r%^ORANGE%^s%^WHITE%^");
    set_long("%^BOLD%^%^WHITE%^This is a set of very nice cat ears.%^RESET%^ "+
"%^BOLD%^%^WHITE%^They're white with %^BLACK%^black %^WHITE%^and %^RESET%^%^ORANGE%^brown%^WHITE%^ "+
"%^BOLD%^%^WHITE%^spots. Rather fashionable, they'd look%^RESET%^ "+
"%^BOLD%^%^WHITE%^splendid on the head of anything.%^RESET%^ "+
"%^BOLD%^%^WHITE%^Particularly on the head that originally%^RESET%^ "+
"%^BOLD%^%^WHITE%^grew them. %^BLACK%^P%^RESET%^%^ORANGE%^o%^WHITE%^o%^BOLD%^%^BLACK%^r %^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^it%^RESET%^t%^BOLD%^%^BLACK%^y%^WHITE%^.%^RESET%^");
    set_weight(4);
    set_value(7);
    set_type("clothing");
    set_limbs( ({ "head" }) );
    set_ac(0);
    set_property("no disenchant",1);
}
