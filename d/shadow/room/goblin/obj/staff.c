#include <std.h>
inherit "/std/weapon";
create() {
    ::create();
    set_name("staff");
    set_id(({"staff","runestaff"}));
    set_short("%^RED%^Runestaff%^RESET%^");
    set_long("%^RED%^"
	"This finely crafted wooden staff is covered with glowing "
	"red runes and feels warm as you hold it."
	"%^RESET%^"
    );
    set_weight(10);
    set_value(50);
    set_wc(1,6);
    set_large_wc(1,8);
    set_size(2);
    set_type("bludgeoning");
   set_prof_type("staff");
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    write("%^RED%^"
	"The runestaff hums as you wield it."
	"%^RESET%^"
    );
    say("%^RED%^"
	"The staff held by "
	+TPQCN+
	" begins to glow with an red light."
	"%^RESET%^"
    ,TP);
    return 1;
}
int extra_unwield() {
    write("%^RED%^"
	"The staff ceases glowing and seems lifeless now."
	"%^RESET%^"
    );
    say("%^RED%^"
	"The staff wielded by "
	+TPQCN+
	" stops glowing and seems lifeless now."
	"%^RESET%^"
    ,TP);
    return 1;
}
int extra_hit(object ob) {
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if(random(8) < 6) return 1;
    message("my_action","%^RED%^"
	"The runes on the staff flash red!"
	"%^RESET%^"
    ,ETO);
    message("other_action","%^RED%^"
	"The runes on the staff wielded by "
        +ETO->query_cap_name()+
        " flash red!"
	"%^RESET%^"
    ,environment(vic),(({ETO, vic})));
    message("my_action","%^BOLD%^%^YELLOW%^"
        +ETO->query_cap_name()+
        " smites you with great force!"
        "%^RESET%^"
    ,vic);
    ETO->add_hp(random(3)+1);
    return 1;
}
