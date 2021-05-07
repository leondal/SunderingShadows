// Chernobog (3/6/21)
// Shadow Coliseum

inherit "/d/common/obj/misc/street_light.c";

void create(){
    ::create();
    set_id(({"orb","street light","street_light","light"}));
    set_short("%^BOLD%^%^MAGENTA%^A %^RESET%^%^CYAN%^translucent orb %^BOLD%^%^MAGENTA%^hovering in the air%^RESET%^");
    set_dayShort("%^BOLD%^%^MAGENTA%^A %^RESET%^%^CYAN%^translucent orb %^BOLD%^%^MAGENTA%^hovering in the air%^RESET%^");
    set_nightShort("%^BOLD%^%^MAGENTA%^A %^RESET%^%^CYAN%^tr%^BOLD%^an%^WHITE%^slu%^CYAN%^ce%^RESET%^%^CYAN%^nt %^BOLD%^o%^WHITE%^r%^CYAN%^b %^MAGENTA%^hovering in the air%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These large spheres of %^RESET%^%^CYAN%^translucent crystal %^BOLD%^%^BLACK%^hover in the air around the stands. A thin tracery of %^MAGENTA%^s%^RESET%^%^MAGENTA%^i%^BOLD%^g%^RESET%^%^MAGENTA%^i%^BOLD%^l%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^wrap about each globe, the physical binding of magic that keeps them aloft as well as signals them to break into lumination when the sun sets.%^RESET%^");
}

