/*
  mpistol.c
  
  The pistol wielded by the captain of the pirate
  treasure-hinting expedition on Tonerra.
  
  Descriptions provided by Cedric/Eduardo.
  
  -- Tlaloc -- 11/2019
*/

inherit "/d/common/obj/lrweapon/pistol.c";

void create()
{
    ::create();
    
    set_name("pistol");
    set_id( ({ "pistol", "matchlock", "matchlock pistol" }) );
    //Stylish Matchlock Pistol
    set_obvious_short("%^BOLD%^%^BLACK%^A st%^MAGENTA%^y%^BLACK%^l%^MAGENTA%^i%^BLACK%^sh %^WHITE%^m%^BLACK%^i%^RESET%^t%^BOLD%^h%^RESET%^r%^BOLD%^i%^BLACK%^l m%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^tchl%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^ck pistol");
    //Matchlock Pistol of the Fiery Phoenix
    set_short("%^BOLD%^M%^BLACK%^a%^WHITE%^tch%^BLACK%^l%^WHITE%^oc%^BLACK%^k %^CYAN%^P%^BLACK%^i%^CYAN%^st%^BLACK%^o%^CYAN%^l %^RESET%^of the %^BOLD%^%^RED%^Fi%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^RED%^y %^BOLD%^P%^MAGENTA%^h%^RED%^o%^MAGENTA%^e%^RED%^ni%^MAGENTA%^x");
    set_long("\
%^BOLD%^%^BLACK%^This %^WHITE%^matchlock %^RESET%^pistol %^BOLD%^%^BLACK%^is a %^CYAN%^vision %^BLACK%^of %^MAGENTA%^beauty %^BLACK%^and %^RESET%^%^CYAN%^art%^BOLD%^%^BLACK%^. The %^RESET%^handle %^BOLD%^%^BLACK%^is made of shining bl%^RESET%^a%^BOLD%^%^BLACK%^ck %^RESET%^lacquered %^BOLD%^%^BLACK%^eb%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^, and engraved on both sides with the %^RESET%^ %^GREEN%^stem %^BOLD%^%^BLACK%^of a rose set in thousands of small emeralds. The stem ends in a flawle %^RESET%^s%^BOLD%^%^BLACK%^sly made %^RED%^red r%^MAGENTA%^o%^RED%^s%^MAGENTA%^e%^BLACK%^, set with hundreds of small %^RED%^rubies%^BLACK%^. The %^WHITE%^mithril matchlock %^BLACK%^is made to %^CYAN%^perfection %^BLACK%^ with the curled back %^ORANGE%^serpentine %^BLACK%^hammer ready to ignite the powder in the small pan. Then entire mechanism is engraved with swirling %^RED%^r%^MAGENTA%^o%^RED%^s%^MAGENTA%^y %^GREEN%^vines %^BLACK%^and inlaid with %^ORANGE%^gold%^BLACK%^. The pistol have %^RESET%^%^CYAN%^3 barrels %^BOLD%^%^BLACK%^arranged in a triangle with one barrel at the top and two at the bottom. The barrels are fixed by two %^ORANGE%^golden bands %^BLACK%^with small engraved images of %^WHITE%^doves%^BLACK%^. The three mouth of the barrels are almost hidden by a %^CYAN%^intricate %^BLACK%^carved %^RED%^ph%^MAGENTA%^o%^RED%^e%^MAGENTA%^n%^RED%^ix %^BLACK%^head, made entirely out of a single %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^. The details of the head in %^MAGENTA%^uncanny%^BLACK%^, and the creature almost seem to be %^GREEN%^alive%^BLACK%^. It is clear, any bullets will never touch the %^RED%^gemstone%^BLACK%^, as the %^RESET%^%^ORANGE%^maw %^BOLD%^%^BLACK%^of the %^GREEN%^beast %^BLACK%^is open in a %^WHITE%^snarl.\n");
    
    set_property("enchantment", 7);
    set_property("no_alter", 1);
    set_property("magic", 1);
    set_lrhit((:this_object(), "weapon_hit":));
    set_weapon_prof("martial");
    set_weight(6);
}

int weapon_hit(object target)
{
    int roll,
        damage;
        
    string name;
        
    object player,
           room;
           
    player = environment(this_object());
    player && room = environment(player);
    
    
    if(!target || !player || room != environment(target))
        return 0;
    
    roll = roll_dice(1, 10);
    
    if(roll < 9)
        return 0;
    
    //This does an extra attack.
    if(roll == 9)
    {
        player && tell_object(player, "Y%^BOLD%^You %^RESET%^cock %^BOLD%^the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^p%^BOLD%^e%^RESET%^%^CYAN%^n%^BOLD%^ti%^RESET%^%^CYAN%^n%^BOLD%^e %^BLACK%^hammer %^WHITE%^all the way %^RESET%^%^ORANGE%^back%^BOLD%^%^WHITE%^, and as you %^ORANGE%^press %^WHITE%^the %^BLACK%^trigger%^WHITE%^, the %^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^re%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^el%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d p%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^l %^BOLD%^%^WHITE%^fires all at once in a huge %^BLACK%^B%^MAGENTA%^O%^CYAN%^O%^BLACK%^M%^RED%^I%^BLACK%^NG %^RED%^v%^RESET%^%^RED%^o%^BOLD%^l%^RESET%^%^RED%^le%^BOLD%^y %^WHITE%^of %^BLACK%^black smoke %^WHITE%^and %^RESET%^%^RED%^f%^BOLD%^i%^RESET%^%^RED%^r%^BOLD%^e\n");
        target && tell_object(target, "cocks %^BOLD%^the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^p%^BOLD%^e%^RESET%^%^CYAN%^n%^BOLD%^ti%^RESET%^%^CYAN%^n%^BOLD%^e %^BLACK%^hammer %^WHITE%^all the way %^RESET%^%^ORANGE%^back %^BOLD%^%^WHITE%^on his $O, and as %^RESET%^he %^YELLOW%^press %^WHITE%^the %^BLACK%^trigger%^WHITE%^, the %^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^re%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^el%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d p%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^l %^BOLD%^%^WHITE%^fires all at once in a huge %^BLACK%^B%^MAGENTA%^O%^CYAN%^O%^BLACK%^M%^RED%^I%^BLACK%^NG %^RED%^v%^RESET%^%^RED%^o%^BOLD%^l%^RESET%^%^RED%^le%^BOLD%^y %^WHITE%^of %^BLACK%^black smoke %^WHITE%^and %^RESET%^%^RED%^f%^BOLD%^i%^RESET%^%^RED%^r%^BOLD%^e\n");
        tell_room("cocks %^BOLD%^the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^p%^BOLD%^e%^RESET%^%^CYAN%^n%^BOLD%^ti%^RESET%^%^CYAN%^n%^BOLD%^e %^BLACK%^hammer %^WHITE%^all the way %^RESET%^%^ORANGE%^back %^BOLD%^%^WHITE%^on his $O, and as %^RESET%^he %^YELLOW%^press %^WHITE%^the %^BLACK%^trigger%^WHITE%^, the %^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^re%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^el%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d p%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^l %^BOLD%^%^WHITE%^fires all at once in a huge %^BLACK%^B%^MAGENTA%^O%^CYAN%^O%^BLACK%^M%^RED%^I%^BLACK%^NG %^RED%^v%^RESET%^%^RED%^o%^BOLD%^l%^RESET%^%^RED%^le%^BOLD%^y %^WHITE%^of %^BLACK%^black smoke %^WHITE%^and %^RESET%^%^RED%^f%^BOLD%^i%^RESET%^%^RED%^r%^BOLD%^e\n", ({ player, target }));
        
        damage = roll_dice(1,6);
        target && target->do_damage("torso", damage);
        return damage;
    }
    
    //This causes our target to be stunned
    player && tell_object(player, "%^BOLD%^%^BLACK%^You %^GREEN%^throw %^BLACK%^a black %^GREEN%^s%^RESET%^%^GREEN%^ph%^BOLD%^er%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^at $T, and with a %^WHITE%^well aimed %^CYAN%^shot %^BLACK%^from your $O, the %^GREEN%^s%^RESET%^%^GREEN%^ph%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^e %^RED%^e%^ORANGE%^x%^RED%^pl%^ORANGE%^o%^RED%^de%^ORANGE%^s %^BLACK%^in a %^CYAN%^t%^BLACK%^h%^WHITE%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^o%^CYAN%^u%^WHITE%^s %^BLACK%^b%^CYAN%^oo%^BLACK%^m, sending $T %^MAGENTA%^flying %^BLACK%^back, %^WHITE%^stunned.\n");
    target && tell_object(target, "%^BOLD%^%^GREEN%^throws %^BLACK%^a black %^GREEN%^s%^RESET%^%^GREEN%^ph%^BOLD%^er%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^at %^RESET%^you%^BOLD%^%^BLACK%^, and with a %^WHITE%^well aimed %^CYAN%^shot %^BLACK%^from %^RESET%^his %^BOLD%^%^BLACK%^$O, the %^GREEN%^s%^RESET%^%^GREEN%^ph%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^e %^RED%^e%^ORANGE%^x%^RED%^pl%^BLACK%^o%^RED%^de%^ORANGE%^s %^BLACK%^in a %^CYAN%^t%^BLACK%^h%^WHITE%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^o%^CYAN%^u%^WHITE%^s %^BLACK%^b%^CYAN%^oo%^BLACK%^m, sending %^RESET%^you %^BOLD%^%^MAGENTA%^flying %^BLACK%^back, %^WHITE%^stunned.\n");
    tell_room("%^BOLD%^%^GREEN%^throws %^BLACK%^a black %^GREEN%^s%^RESET%^%^GREEN%^ph%^BOLD%^er%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^at %^RESET%^$T%^BOLD%^%^BLACK%^, and with a %^WHITE%^well aimed %^CYAN%^shot %^BLACK%^from %^RESET%^his %^BOLD%^%^BLACK%^$O, the %^GREEN%^s%^RESET%^%^GREEN%^ph%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^e %^RED%^e%^ORANGE%^x%^RED%^pl%^BLACK%^o%^RED%^de%^ORANGE%^s %^BLACK%^in a %^CYAN%^t%^BLACK%^h%^WHITE%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^o%^CYAN%^u%^WHITE%^s %^BLACK%^b%^CYAN%^oo%^BLACK%^m, sending %^RESET%^$T %^BOLD%^%^MAGENTA%^flying %^BLACK%^back, %^WHITE%^stunned.\n", ({ player, target }));

    target->set_paralyzed(8, "You are stunned and can't move!");
    
    return damage;
}
