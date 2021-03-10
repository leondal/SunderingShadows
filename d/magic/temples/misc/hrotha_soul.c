#include <std.h>

inherit WEAPONLESS;

void cage(object targ, int num);

void create()
{
    ::create();
    set_id(({"spectral crone", "hrotha", "crone", "ghost", "specter", "spirit"}));
    set_name("Spectral Crone");

    set_short("%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^p%^BLACK%^e%^RESET%^%^CYAN%^c"
        "%^BOLD%^%^WHITE%^t%^BLACK%^r%^WHITE%^a%^RESET%^%^CYAN%^l "
        "c%^BOLD%^%^BLACK%^r%^WHITE%^o%^BLACK%^n%^RESET%^%^CYAN%^e%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This wretched creature was surely human once but now hangs on in "
        "perpetuity as a %^BOLD%^%^BLACK%^sp%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^ct%^RESET%^r%^BOLD%^%^BLACK%^al "
        "cr%^WHITE%^o%^BLACK%^ne. %^WHITE%^Tran%^RESET%^s%^BOLD%^luc%^RESET%^e%^BOLD%^nt tendr%^RESET%^i%^BOLD%^ls%^BLACK%^ "
        "of scraggly hair drift around the spectral old woman's blank face, out from which two hollow, "
        "yet %^CYAN%^gl%^BLUE%^o%^CYAN%^wing%^BLACK%^ eyes maddeningly stare. A gaping, "
        "toothless mouth hangs open as if in some pathetic, soundless scream. "
        "The rest of the apparition's body is crooked and bent, almost struggling as it shambles along.%^RESET%^");

    set_body_type("human");
    set_race("undead");
    set_gender("female");
    set_alignment(9);
    set_size(2);
    set_hd(40,12);
    set_mlevel("fighter",40);
    set_hp(random(350)+200);
    set_stats("strength",22);
    set_stats("dexterity",19);
    set_new_exp(1,"very low");

    set_overall_ac( ((int)TO->query_max_hp()/10)*-1 );

    set_mob_magic_resistance("average");

    set_damage(1,4);
    set_attacks_num(1);
}
