// Chernobog (9/6/21)
// Tharis Hotel

#include "../defs.h"
inherit "/std/barkeep";

void create() {
    ::create();
    set_name("Connor");
    set_id(({"connor","Connor","waiter"}));
    set_short("%^BOLD%^%^MAGENTA%^Connor%^RESET%^%^MAGENTA%^, maitre'd of %^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^V%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t's %^BOLD%^%^BLACK%^Restaurant %^RESET%^%^MAGENTA%^& %^BOLD%^%^BLACK%^Bar%^RESET%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^Tall and slender, this young man is dressed in the livery of %^MAGENTA%^The V%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t%^WHITE%^; a sharp %^BOLD%^%^BLACK%^black suit %^RESET%^with %^MAGENTA%^v%^BOLD%^io%^RESET%^%^MAGENTA%^l%^BOLD%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^BLACK%^p%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^nstr%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^pes %^RESET%^and a %^BOLD%^%^BLACK%^br%^RESET%^o%^BOLD%^%^BLACK%^c%^WHITE%^a%^BLACK%^d%^RESET%^e %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er v%^RESET%^e%^BOLD%^s%^BLACK%^t%^RESET%^. His thick %^BOLD%^white hair %^RESET%^is slicked back and two small %^BOLD%^%^BLACK%^black horns %^RESET%^protrude from his brow, proudly on display. He surveys his domain with %^BOLD%^%^BLACK%^cat%^RESET%^-like %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n e%^RESET%^%^ORANGE%^y%^BOLD%^es%^RESET%^, a %^BOLD%^%^BLACK%^charming %^WHITE%^smile %^RESET%^presented to each guest.%^RESET%^");
    set_gender("male");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_property("no_random_treasure",1);
    set_currency("gold");
    set_menu(
        ({"soup","salad","calamari","filet mignon","lamb","halibut","creme brulee","cobbler","cake","water","tea","lemonade","tequila twilight","whiskey sour","vodka martini","blood wine","chardonnay"}),
        ({"food","food","food","food","food","food","food","food","food","water","soft drink","soft drink","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic"}),
        ({20,25,30,60,70,80,20,25,30,5,10,15,15,20,30,40,50}),
    );
    set_my_mess(({
        "%^RESET%^%^ORANGE%^The soup is thick and %^BOLD%^%^WHITE%^creamy%^RESET%^%^ORANGE%^, filling your belly with warmth.%^WHITE%^",
        "%^RESET%^%^GREEN%^This refreshing salad is a delightful mix of %^ORANGE%^savory%^GREEN%^, %^BOLD%^sour%^RESET%^%^GREEN%^, and %^BOLD%^%^MAGENTA%^sweet %^RESET%^%^GREEN%^flavors.%^RESET%^",
        "%^YELLOW%^You squeeze the lemon over the calamari and dip one of the tender rings into the %^RED%^sauce %^ORANGE%^before popping into your mouth. %^RED%^Delicious%^ORANGE%^!%^RESET%^",
        "%^BOLD%^%^BLACK%^You cut into the st%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ak and take a bite. It is cooked to %^RESET%^%^ORANGE%^perfection%^BOLD%^%^BLACK%^, melting in your mouth.%^RESET%^",
        "%^RESET%^%^RED%^You take a bite of the %^ORANGE%^tender %^BOLD%^%^WHITE%^lamb %^RESET%^%^RED%^shank, the rosemary tantalizing your senses.%^WHITE%^",
        "%^RESET%^%^CYAN%^The fine bread crumb crust and %^BOLD%^%^RED%^tangy %^ORANGE%^m%^RESET%^%^ORANGE%^u%^BOLD%^st%^RESET%^%^ORANGE%^a%^BOLD%^rd %^RESET%^%^CYAN%^enhance the texture and flavor of this wonderfully %^ORANGE%^flaky %^CYAN%^fish.%^WHITE%^",
        "%^RESET%^The cr%^ORANGE%^e%^WHITE%^m%^ORANGE%^e %^WHITE%^br%^ORANGE%^u%^WHITE%^l%^ORANGE%^e%^WHITE%^e is wonderfully creamy and the caramelized %^ORANGE%^brown sugar crust %^WHITE%^melts in your mouth.",
        "%^RESET%^%^ORANGE%^The pe%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^ch%^BOLD%^%^MAGENTA%^e%^RESET%^%^ORANGE%^s in this c%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^bbl%^BOLD%^%^MAGENTA%^e%^RESET%^%^ORANGE%^r are wonderfully %^BOLD%^%^MAGENTA%^sweet %^RESET%^%^ORANGE%^with just the right amount of %^BOLD%^%^MAGENTA%^tartness%^RESET%^%^ORANGE%^.%^WHITE%^",
        "%^BOLD%^%^BLACK%^The c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ke is %^MAGENTA%^exquisite%^BLACK%^, but so r%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ch you can barely finish it!%^RESET%^",
        "%^BOLD%^%^BLUE%^The %^WHITE%^ice%^BLUE%^-cold %^RESET%^%^GREEN%^minty %^BOLD%^%^BLUE%^water hits the spot!%^RESET%^",
        "%^RESET%^%^MAGENTA%^The relaxing l%^BOLD%^a%^RESET%^%^MAGENTA%^v%^BOLD%^e%^RESET%^%^MAGENTA%^nd%^BOLD%^e%^RESET%^%^MAGENTA%^r %^BOLD%^scent %^RESET%^%^MAGENTA%^of the %^BOLD%^%^RED%^hot %^RESET%^%^MAGENTA%^tea calms you.%^WHITE%^",
        "%^YELLOW%^The %^MAGENTA%^tangy %^ORANGE%^sourness of the lemonade is almost too much!%^RESET%^",
        "%^BOLD%^%^BLACK%^The t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^qu%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^la is smooth on the way down, %^RESET%^%^RED%^warming %^BOLD%^%^BLACK%^your belly.%^RESET%^",
        "%^RESET%^%^ORANGE%^The fr%^BOLD%^o%^RESET%^%^ORANGE%^thy e%^BOLD%^g%^RESET%^%^ORANGE%^g %^BOLD%^%^WHITE%^white %^RESET%^%^ORANGE%^offers a %^BOLD%^%^WHITE%^richness %^RESET%^%^ORANGE%^to this %^BOLD%^sour %^RESET%^%^ORANGE%^concoction.%^WHITE%^",
        "%^BOLD%^%^WHITE%^This m%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^rt%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^i %^BOLD%^%^WHITE%^is, in fact, quite d%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^rty!%^RESET%^",
        "%^RESET%^%^RED%^This rich wine has legs for days! You notice subtle flavors of %^ORANGE%^oak%^RED%^, %^BOLD%^%^WHITE%^vanilla%^RESET%^%^RED%^, and even a hint of %^BOLD%^%^BLACK%^tobacco%^RESET%^%^RED%^.%^WHITE%^",
        "%^YELLOW%^Even the glass the ch%^WHITE%^a%^ORANGE%^rd%^WHITE%^o%^ORANGE%^nn%^WHITE%^a%^ORANGE%^y is served in has been %^CYAN%^chilled%^ORANGE%^. You detect hints of %^RED%^apple %^ORANGE%^and lemon in this crisp ch%^WHITE%^a%^ORANGE%^rd%^WHITE%^o%^ORANGE%^nn%^WHITE%^a%^ORANGE%^y.%^RESET%^"
    }));
    set_your_mess(({
        "%^RESET%^%^ORANGE%^enjoys a bowl of %^BOLD%^%^WHITE%^creamy %^RESET%^%^ORANGE%^pumpkin soup.%^WHITE%^",
        "%^RESET%^%^GREEN%^enjoys a refreshing salad.%^RESET%^",
        "%^YELLOW%^enjoys some fried calamari.%^RESET%^",
        "%^BOLD%^%^BLACK%^enjoys the filet mignon and %^RESET%^%^GREEN%^s%^BOLD%^e%^RESET%^%^GREEN%^ason%^BOLD%^a%^RESET%^%^GREEN%^l v%^BOLD%^e%^RESET%^%^GREEN%^get%^BOLD%^a%^RESET%^%^GREEN%^bles%^BOLD%^%^BLACK%^.%^RESET%^",
        "%^RESET%^%^RED%^enjoys the lamb shank, the smell of rosemary permeating the air.%^WHITE%^",
        "%^RESET%^%^CYAN%^enjoys a plate of %^ORANGE%^Dijon-crusted %^CYAN%^fish with %^GREEN%^s%^BOLD%^e%^RESET%^%^GREEN%^ason%^BOLD%^a%^RESET%^%^GREEN%^l v%^BOLD%^e%^RESET%^%^GREEN%^get%^BOLD%^a%^RESET%^%^GREEN%^bles%^CYAN%^.%^WHITE%^",
        "%^RESET%^enjoys the cr%^ORANGE%^e%^WHITE%^m%^ORANGE%^e %^WHITE%^br%^ORANGE%^u%^WHITE%^l%^ORANGE%^e%^WHITE%^e. ",
        "%^RESET%^%^ORANGE%^enjoys the pe%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^ch c%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^bbl%^BOLD%^%^MAGENTA%^e%^RESET%^%^ORANGE%^r.%^WHITE%^",
        "%^BOLD%^%^BLACK%^enjoys a piece of %^MAGENTA%^decadent %^BLACK%^ch%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^te c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ke%^RESET%^",
        "%^BOLD%^%^BLUE%^enjoys an %^WHITE%^ice%^BLUE%^-cold glass of water.%^RESET%^",
        "%^RESET%^%^MAGENTA%^enjoys some %^BOLD%^fragrant %^RESET%^%^MAGENTA%^tea.%^WHITE%^",
        "%^YELLOW%^enjoys a tall glass of lemonade.%^RESET%^",
        "%^BOLD%^%^BLACK%^sips a %^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^-c%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^red cocktail.%^RESET%^",
        "%^RESET%^%^ORANGE%^drinks a %^BOLD%^sunny %^RESET%^%^ORANGE%^c%^BOLD%^o%^RESET%^%^ORANGE%^ckta%^BOLD%^i%^RESET%^%^ORANGE%^l garnished with an orange peel.%^WHITE%^",
        "%^BOLD%^%^WHITE%^puts their pinky up as they sip their d%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^rty m%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^rt%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^. Very fancy!%^RESET%^",
        "%^RESET%^%^RED%^drinks deeply from their glass of b%^BOLD%^u%^RESET%^%^RED%^rg%^BOLD%^u%^RESET%^%^RED%^ndy w%^BOLD%^i%^RESET%^%^RED%^ne.%^WHITE%^",
        "%^YELLOW%^enjoys a glass of %^CYAN%^chilled %^ORANGE%^ch%^WHITE%^a%^ORANGE%^rd%^WHITE%^o%^ORANGE%^nn%^WHITE%^a%^ORANGE%^y.%^RESET%^"
    }));
    set_menu_short(({
        "%^RESET%^%^ORANGE%^Pumpkin Cream Soup%^WHITE%^", 
        "%^RESET%^%^GREEN%^Th%^BOLD%^a%^RESET%^%^GREEN%^r%^BOLD%^i%^RESET%^%^GREEN%^s%^BOLD%^i%^RESET%^%^GREEN%^an S%^BOLD%^a%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^d%^WHITE%^",
        "%^YELLOW%^Fried Calamari%^RESET%^",
        "%^BOLD%^%^BLACK%^F%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^t M%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^",
        "%^RESET%^%^RED%^Rosemary Braised %^BOLD%^%^WHITE%^Lamb %^RESET%^%^RED%^Shank%^RESET%^",
        "%^RESET%^%^ORANGE%^Dijon%^CYAN%^-Crusted %^BOLD%^%^WHITE%^Halibut%^RESET%^",
        "%^RESET%^Cr%^ORANGE%^e%^WHITE%^m%^ORANGE%^e %^WHITE%^Br%^ORANGE%^u%^WHITE%^l%^ORANGE%^e%^WHITE%^e",
        "%^RESET%^%^ORANGE%^Pe%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^ch C%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^bbl%^BOLD%^%^MAGENTA%^e%^RESET%^%^ORANGE%^r%^WHITE%^",
        "%^BOLD%^%^BLACK%^Ch%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^te C%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ke%^RESET%^",
        "%^BOLD%^%^BLUE%^W%^WHITE%^a%^BLUE%^t%^WHITE%^e%^BLUE%^r%^RESET%^",
        "%^RESET%^%^MAGENTA%^L%^BOLD%^a%^RESET%^%^MAGENTA%^v%^BOLD%^e%^RESET%^%^MAGENTA%^nd%^BOLD%^e%^RESET%^%^MAGENTA%^r Tea%^WHITE%^",
        "%^YELLOW%^Lemonade%^RESET%^",
        "%^BOLD%^%^BLACK%^T%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^qu%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^la Tw%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ght%^RESET%^",
        "%^RESET%^%^ORANGE%^Wh%^BOLD%^i%^RESET%^%^ORANGE%^sk%^BOLD%^e%^RESET%^%^ORANGE%^y %^BOLD%^S%^RESET%^%^ORANGE%^o%^BOLD%^ur%^RESET%^",
        "%^BOLD%^D%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^rty M%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^rt%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^i%^WHITE%^",
        "%^BOLD%^%^RED%^B%^RESET%^%^RED%^loo%^BOLD%^d %^RESET%^%^RED%^W%^BOLD%^i%^RESET%^%^RED%^ne%^WHITE%^",
        "%^YELLOW%^Ch%^WHITE%^a%^ORANGE%^rd%^WHITE%^o%^ORANGE%^nn%^WHITE%^a%^ORANGE%^y%^RESET%^"
    }));
    set_menu_long(({
        "%^RESET%^%^ORANGE%^A thick, vibrant orange soup with sw%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^rls of %^BOLD%^%^WHITE%^rich cream%^RESET%^%^ORANGE%^.%^WHITE%^ ",
        "%^RESET%^%^GREEN%^A collection of roasted root vegetables on top of a medley of greens, topped with dried %^RED%^cranberries%^GREEN%^, %^BOLD%^%^WHITE%^goat cheese%^RESET%^%^GREEN%^, and a %^ORANGE%^balsamic vinaigrette%^GREEN%^.%^WHITE%^",
        "%^YELLOW%^A plate of %^RESET%^%^ORANGE%^lightly fried %^BOLD%^calamari with a side of %^RED%^tangy dipping sauce %^ORANGE%^with lemon wedges.%^RESET%^ ",
        "%^BOLD%^%^BLACK%^A perfectly cooked cut of f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^t m%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n accompanied by %^RESET%^%^GREEN%^s%^BOLD%^e%^RESET%^%^GREEN%^ason%^BOLD%^a%^RESET%^%^GREEN%^l v%^BOLD%^e%^RESET%^%^GREEN%^get%^BOLD%^a%^RESET%^%^GREEN%^bles%^BOLD%^%^BLACK%^.%^RESET%^",
        "%^RESET%^%^RED%^A large %^BOLD%^%^WHITE%^lamb %^RESET%^%^RED%^shank resting on a bed of %^BOLD%^%^WHITE%^creamy %^RESET%^mashed potatoes%^RED%^.%^WHITE%^",
        "%^RESET%^%^CYAN%^A plate of %^RESET%^%^ORANGE%^Dijon%^RESET%^%^CYAN%^-crusted %^BOLD%^%^WHITE%^halibut %^RESET%^%^CYAN%^on a bed of %^GREEN%^s%^BOLD%^e%^RESET%^%^GREEN%^ason%^BOLD%^a%^RESET%^%^GREEN%^l v%^BOLD%^e%^RESET%^%^GREEN%^get%^BOLD%^a%^RESET%^%^GREEN%^bles%^CYAN%^.%^WHITE%^",
        "%^RESET%^Cr%^ORANGE%^e%^WHITE%^m%^ORANGE%^e %^WHITE%^br%^ORANGE%^u%^WHITE%^l%^ORANGE%^e%^WHITE%^e with a c%^ORANGE%^a%^WHITE%^r%^ORANGE%^a%^WHITE%^m%^ORANGE%^e%^WHITE%^l%^ORANGE%^i%^WHITE%^z%^ORANGE%^e%^WHITE%^d %^ORANGE%^brown sugar crust%^WHITE%^.",
        "%^RESET%^%^ORANGE%^An ooey gooey heap of pe%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^ch c%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^bbl%^BOLD%^%^MAGENTA%^e%^RESET%^%^ORANGE%^r topped with a scoop of %^BOLD%^%^WHITE%^vanilla ice cream%^RESET%^%^ORANGE%^.%^WHITE%^",
        "%^BOLD%^%^BLACK%^A decadent 13-layer ch%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^te c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ke. Every other layer alternates between dark chocolate and a %^RESET%^%^ORANGE%^milk chocolate %^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^uss%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^.%^RESET%^",
        "%^BOLD%^%^BLUE%^A fr%^WHITE%^o%^BLUE%^st%^WHITE%^y %^BLUE%^gl%^WHITE%^a%^BLUE%^ss of refreshing %^WHITE%^ice %^BLUE%^water garnished with %^RESET%^%^GREEN%^mint%^BOLD%^%^BLUE%^.%^RESET%^",
        "%^RESET%^%^MAGENTA%^A steaming cup of %^BOLD%^fragrant %^RESET%^%^MAGENTA%^tea.%^WHITE%^ ",
        "%^YELLOW%^A tall of sweet and sour lemonade garnished with %^RED%^bright red cherries%^ORANGE%^.%^RESET%^",
        "%^BOLD%^%^BLACK%^This drink is infused with muddled d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^berries%^BOLD%^%^BLACK%^, giving it a d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^violet %^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^e.%^RESET%^",
        "%^RESET%^%^ORANGE%^This %^BOLD%^sunny %^RESET%^%^ORANGE%^dr%^BOLD%^i%^RESET%^%^ORANGE%^nk has a fr%^BOLD%^o%^RESET%^%^ORANGE%^thy f%^BOLD%^o%^RESET%^%^ORANGE%^am and is garnished with an orange peel.%^WHITE%^",
        "%^BOLD%^Three %^RESET%^%^GREEN%^green olives %^BOLD%^%^WHITE%^impaled on a %^RESET%^%^ORANGE%^wooden toothpick %^BOLD%^%^WHITE%^rest in a bath of unassuming clear liquid.%^RESET%^",
        "%^RESET%^%^RED%^A large, round glass of r%^BOLD%^i%^RESET%^%^RED%^ch b%^BOLD%^u%^RESET%^%^RED%^rg%^BOLD%^u%^RESET%^%^RED%^ndy w%^BOLD%^i%^RESET%^%^RED%^ne.%^WHITE%^",
        "%^YELLOW%^A tall glass of %^CYAN%^chilled %^ORANGE%^ch%^WHITE%^a%^ORANGE%^rd%^WHITE%^o%^ORANGE%^nn%^WHITE%^a%^ORANGE%^y%^RESET%^"
    }));
}

