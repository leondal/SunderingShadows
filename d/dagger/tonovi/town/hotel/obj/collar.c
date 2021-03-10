// Chernobog (1/25/21)
// Tonovi Hotel

inherit "/std/armour";

void create(){
    ::create();
    set_name("collar");
    set_id(({ "collar","slave collar","choker" }));
    set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^slender %^BOLD%^%^BLACK%^c"+
        "%^RESET%^h%^BOLD%^ok%^RESET%^e%^BOLD%^%^BLACK%^r displaying a %^RESET%^b"+
        "%^BOLD%^%^BLACK%^evele%^RESET%^d %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^"+
        "by%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^Though appearing to be a delicate choker of %^BOLD%^"+
        "%^BLACK%^s%^RESET%^m%^BOLD%^oo%^RESET%^t%^BOLD%^%^BLACK%^h s%^RESET%^i%^BOLD%^"+
        "lv%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^, the clasp at the nape of "+
        "the neck reveals a %^BOLD%^%^BLACK%^cold iron %^RESET%^%^MAGENTA%^beneath the "+
        "surface. The silver surface has a series of faint impressions that one might "+
        "miss at a cursory glance, of strange %^RED%^glyphs %^MAGENTA%^and %^RED%^"+
        "sigils%^MAGENTA%^. A large %^RED%^b%^BOLD%^ev%^RESET%^%^RED%^e%^BOLD%^le"+
        "%^RESET%^%^RED%^d %^BOLD%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^%^MAGENTA%^"+
        "sits at the forefront, and occasionally pulses with a dim heartbeat.%^RESET%^");
    set_weight(2);
    set_value(100);
    set_type("ring");
    set_limbs(({ "neck" }));
    set_ac(0);
}

