// Titania (4/18/21)
// Shadow Coliseum

#include <std.h>
inherit "/std/barkeep";

void create() {
    ::create();
   	set_name("vendor");
    	set_id( ({ "vendor", "gil" }) );
    	set_short("%^BOLD%^Gil%^RESET%^%^MAGENTA%^, The %^WHITE%^C%^BOLD%^o%^RED%^n%^RESET%^c%^BOLD%^e%^RED%^s%^RESET%^s%^BOLD%^i%^RED%^o%^RESET%^n%^BOLD%^s %^RESET%^%^MAGENTA%^Man%^WHITE%^");
        set_long("%^RESET%^%^MAGENTA%^Gil spends his days serving concessions to eager customers. The coliseum crowd tends to keep him rather busy, and so he likes to keep his transactions simple and quick, rarely slowing down his pace for some friendly exchanges or other niceties. He wears a red and white %^WHITE%^s%^BOLD%^t%^RED%^r%^RESET%^i%^BOLD%^p%^RED%^e%^RESET%^d s%^BOLD%^h%^RED%^i%^WHITE%^r%^RESET%^t%^MAGENTA%^, and a %^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^te pap%^RESET%^e%^BOLD%^r h%^RESET%^a%^BOLD%^t %^RESET%^%^MAGENTA%^crowns his %^BOLD%^%^RED%^w%^MAGENTA%^i%^RED%^ld %^RESET%^%^MAGENTA%^and %^BOLD%^%^RED%^w%^MAGENTA%^i%^RED%^ry r%^RESET%^%^RED%^e%^BOLD%^d h%^RESET%^%^RED%^a%^BOLD%^i%^RESET%^%^RED%^r%^MAGENTA%^. His short %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d g%^RESET%^%^RED%^o%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^e%^RESET%^%^RED%^e %^MAGENTA%^is kept neatly trimmed.%^WHITE%^");
    set_gender("male");
   	set_exp(20);
   	set_alignment(1);
   	set_level(10);
        set_race("human");
        set_body_type("human");
   	set_hd(10,0);
	set_max_hp(query_hp());
   	add_money("copper", random(200));
   	set_currency("silver");
	set_menu(
        ({"popcorn", "turkey leg", "beer" }),
        ({"food", "food", "alcoholic" }),
        ({25,75,50})
    );
    set_my_mess(({
        "%^YELLOW%^So much heavenly butter....%^RESET%^\n",
        "%^RESET%^%^ORANGE%^Warm, meaty juices and delicate %^GREEN%^herbs %^ORANGE%^infuse your mouth with wonder as you take a big bite of the turkey leg.%^WHITE%^\n",
        "%^RESET%^%^ORANGE%^Gross. It will probably grow on you after a few more.%^WHITE%^\n",      
        }));
    set_your_mess(({
        "inhales a whole handful of popcorn.\n",
        "tears into a big hunk of meat.\n",
        "takes a swig from a bottle.\n",
        })); 
    set_menu_short(({
        "%^BOLD%^%^WHITE%^Popcorn%^RESET%^",
        "%^RESET%^%^ORANGE%^Turkey Leg%^RESET%^",
        "%^RESET%^%^MAGENTA%^Beer%^RESET%^"
        }));
    set_menu_long(({
        "%^BOLD%^%^WHITE%^The scent of this popcorn is absolutely %^RESET%^spellbinding%^BOLD%^. It comes served in a large, %^RED%^s%^WHITE%^tripe%^RED%^d p%^WHITE%^ape%^RED%^r b%^WHITE%^a%^RED%^g%^WHITE%^, and there's certainly enough for sharing. The popped corn kernels have been drenched in %^ORANGE%^velvety butter%^WHITE%^.\n",
        "%^RESET%^%^ORANGE%^This is a big chunk of meat! You would not want to come face to face with the turkey this leg belonged to. It's dripping in %^WHITE%^fat %^ORANGE%^and %^WHITE%^grease%^ORANGE%^.%^WHITE%^\n",
        "%^RESET%^%^GREEN%^This is a bottle of fairly %^BOLD%^foul %^RESET%^%^GREEN%^tasting beer that someone must have %^CYAN%^watered %^GREEN%^down.%^WHITE%^\n",
        }));
}

