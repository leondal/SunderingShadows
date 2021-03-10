#include <std.h>
inherit NPC;
void create(){
    ::create();
    set_nwp("healing", 40);
    set_id(({"hehet","healer","mummy","corpse master"}));
    set_name("hehet");
    set_short("%^RESET%^%^WHITE%^Hehet%^ORANGE%^ the corpse master%^RESET%^");
    set_long(
@EOF
%^RESET%^%^WHITE%^Hehet is an ancient mummy, bound in numerous wraps so that even her eyes are not seen. She wears an apron covered in blood and rot stains, and a tool belt with various knives handy for preparation of corpses.
EOF
    );
    set_race("human");
    set_property("undead",1);
    set_body_type("human");
    set_gender("female");
    set_size(2);
    set_hd(30,2);
    set_hp(300);
    set_overall_ac(0);
    set_exp(100);
    set_alignment(3);
    set("aggressive",0);
}
