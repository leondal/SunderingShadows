// Chernobog (1/10/21)
// Tonovi Hotel

#include "../defs.h"
inherit "/std/barkeep";

void create() {
    ::create();
    set_name("room service");
    set_id(({"roomservice","servant","slave"}));
    set_short("%^MAGENTA%^A %^BOLD%^human servant%^RESET%^%^MAGENTA%^, pushing a "+
        "%^BOLD%^%^BLACK%^se%^RESET%^r%^BOLD%^v%^RESET%^i%^BOLD%^%^BLACK%^ng "+
        "%^RESET%^c%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^t %^RESET%^%^MAGENTA%^for the "+
        "%^YELLOW%^T%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^no%^RESET%^%^ORANGE%^v"+
        "%^BOLD%^i H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^"+
        "l%^RESET%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CYAN%^Garbed in a tunic and leggings in the %^YELLOW%^T"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^no%^RESET%^%^ORANGE%^v%^BOLD%^i H"+
        "%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^l l"+
        "%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ve%^RESET%^%^ORANGE%^r%^BOLD%^y%^RESET%^"+
        "%^CYAN%^, %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^with %^ORANGE%^g%^BOLD%^o"+
        "%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^n %^BOLD%^t%^WHITE%^r%^ORANGE%^i"+
        "%^RESET%^%^ORANGE%^m%^CYAN%^, this human man stands at attention with "+
        "downcast eyes. Occasionally, he tugs lightly at a %^BOLD%^%^BLACK%^s"+
        "%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r c%^RESET%^h%^BOLD%^ok"+
        "%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^at his neck, featuring a "+
        "single beveled %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by%^RESET%^%^CYAN%^"+
        ". He stands near a large %^BOLD%^%^BLACK%^se%^RESET%^r%^BOLD%^v%^RESET%^i"+
        "%^BOLD%^%^BLACK%^ng %^RESET%^c%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^t%^RESET%^"+
        "%^CYAN%^, laden with various covered dishes.\n\n%^BOLD%^%^BLACK%^They will "+
        "patiently wait on you until you %^WHITE%^dismiss room service%^BLACK%^"+
        ".%^RESET%^");
    set_gender("male");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    new(OBJ"collar.c")->move(TO);
    command("wear collar");
    set_currency("gold");
    set_menu(
        ({"soup","prawns","mushroom medley","salmon","chicken","steak","creme brulee","pudding","trifle","water","tea","brandy","sherry","scotch","chardonnay"}),
        ({"food","food","food","food","food","food","food","food","food","water","soft drink","alcoholic","alcoholic","alcoholic","alcoholic"}),
        ({25,35,45,60,75,90,20,25,30,10,15,20,30,40,50}),
    );
    set_my_mess(({
        "You eat the hearty soup and feel yourself warm up.",
        "You eat the prawns, enjoying the tangy flavor.",
        "You eat the mushroom medley, noticing how the pastry holds in the flavor.",
        "You eat the flakey salmon flavored with lemon and a dash of pepper.",
        "The chicken melts in your mouth, sweet and savory to the tongue.",
        "You eat the steak and potatoes, feeling sated and content.",
        "You eat the creme brulee, noticing the way the fruit flavors the dessert.",
        "You enjoy the spongy cake filled with dates.",
        "You savour the chocolate dessert, noticing how the layers blend.",
        "You drink down the cool lemon water and feel refreshed.",
        "You drink the soothing tea, relaxing with the fragrance of chamomile.",
        "You savour the snifter of iced brandy, letting the liquid fire do its work.",
        "You drink the sherry, noticing the unusual smokey flavor.",
        "You sip the aged scotch, savoring the aged flavor.",
        "You sip the glass of golden chardonnay, enjoying the fragrance."
    }));
    set_your_mess(({
        "eats a hearty bowl of soup.",
        "eats the grilled prawns.",
        "eats the puffed pastry filled with mushrooms.",
        "savors the delicious-smelling salmon.",
        "eats the chicken with a contented smile.",
        "enjoys a plate of steak and potatoes.",
        "eats a dessert of creme brulee and fruit.",
        "enjoys a spongy cake filled with dates.",
        "seems to enjoy a tall chocolate dessert.",
        "drinks a glass of lemon water.",
        "drinks a glass of chamomile tea and sighs contentedly.",
        "downs the snifter of iced brandy.",
        "drinks a glass of smoked sherry.",
        "drinks a glass of aged scotch.",
        "enjoys a glass of golden chardonnay."
    }));
    set_menu_short(({
        "Lamb Barley Soup",
        "Grilled Prawns",
        "Mushroom Medley",
        "Pan-seared Salmon Filet",
        "Grilled Chicken with Strawberry Compote",
        "Steak with Garlic Butter",
        "Creme Brulee",
        "Sticky Toffee Pudding",
        "Chocolate Drambuie Trifle",
        "Lemon Water",
        "Chamomile Tea",
        "Iced Brandy",
        "Smoked Sherry",
        "Aged Scotch",
        "Golden Chardonnay"
    }));
    set_menu_long(({
        "%^RESET%^A %^ORANGE%^he%^RED%^a%^ORANGE%^rty so%^RED%^u%^ORANGE%^p %^WHITE%^"+
            "that is good for cold winter days. %^RED%^L%^BOLD%^a%^RESET%^%^RED%^mb "+
            "%^WHITE%^and %^GREEN%^v%^BOLD%^eg%^RESET%^%^GREEN%^e%^ORANGE%^t%^BOLD%^a"+
            "%^RESET%^%^ORANGE%^b%^BOLD%^%^RED%^l%^RESET%^%^RED%^e%^BOLD%^s %^RESET%^"+
            "are cooked in a %^RED%^beefy %^WHITE%^broth with chewy %^ORANGE%^b"+
            "%^BOLD%^ar%^RESET%^%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^y%^RESET%^.",
        "%^RESET%^Prawns marinated in %^BOLD%^%^GREEN%^li%^RESET%^%^GREEN%^m%^BOLD%^e"+
            "%^RESET%^, %^BOLD%^%^MAGENTA%^on%^RESET%^%^MAGENTA%^i%^BOLD%^o%^RESET%^"+
            "%^MAGENTA%^n%^WHITE%^, and %^BOLD%^ga%^RESET%^r%^BOLD%^l%^RESET%^i"+
            "%^BOLD%^c %^RESET%^and then quickled %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^"+
            "i%^BLACK%^l%^RESET%^l%^BOLD%^e%^BLACK%^d%^RESET%^.",
        "%^RESET%^Mushrooms cooked with %^BOLD%^ga%^RESET%^r%^BOLD%^l%^RESET%^i"+
            "%^BOLD%^c%^RESET%^, %^BOLD%^%^GREEN%^sh%^RESET%^%^GREEN%^a%^BOLD%^ll"+
            "%^RESET%^%^GREEN%^o%^BOLD%^ts%^RESET%^, and %^ORANGE%^cr%^WHITE%^e"+
            "%^BOLD%^a%^RESET%^%^ORANGE%^m%^WHITE%^, topped with a %^ORANGE%^puffed "+
            "pastry%^RESET%^.",
        "%^RESET%^Pan-fried salmon filets with a %^BOLD%^ga%^RESET%^r%^BOLD%^l"+
            "%^RESET%^i%^BOLD%^c %^RESET%^and %^YELLOW%^l%^WHITE%^e%^ORANGE%^mon "+
            "%^RESET%^%^ORANGE%^sauce%^WHITE%^, covered with %^BOLD%^%^RED%^p"+
            "%^ORANGE%^e%^RED%^p%^ORANGE%^p%^RED%^er%^ORANGE%^s%^RESET%^.",
        "%^RESET%^Marinated in tangy %^MAGENTA%^b%^BOLD%^%^BLACK%^a%^RESET%^"+
            "%^MAGENTA%^ls%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^i"+
            "%^RESET%^%^MAGENTA%^c v%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^n%^BOLD%^"+
            "%^BLACK%^e%^RESET%^%^MAGENTA%^ga%^BOLD%^%^BLACK%^r%^RESET%^, this "+
            "grilled chicken has been adorned with a dollop of %^BOLD%^%^RED%^str"+
            "%^RESET%^%^RED%^a%^BOLD%^wber%^RESET%^%^RED%^r%^BOLD%^y %^RESET%^and "+
            "%^ORANGE%^brown sugar %^RESET%^compote.",
        "%^RESET%^A healthy portion of %^BOLD%^mashed potatoes %^RESET%^rests next to "+
            "a %^RED%^se%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d %^WHITE%^"+
            "t-bone steak. It has been properly seasoned and drips with melted "+
            "%^BOLD%^ga%^RESET%^r%^BOLD%^l%^RESET%^i%^BOLD%^c %^ORANGE%^b%^WHITE%^u"+
            "%^ORANGE%^tt%^WHITE%^e%^ORANGE%^r%^RESET%^.",
        "%^RESET%^Stovetop %^YELLOW%^cr%^RESET%^%^ORANGE%^e%^BOLD%^m%^RESET%^"+
            "%^ORANGE%^e %^BOLD%^br%^RESET%^%^ORANGE%^u%^BOLD%^l%^RESET%^%^ORANGE%^e"+
            "%^BOLD%^e %^RESET%^with a %^ORANGE%^carmelized brown sugar %^RESET%^top, "+
            "served over fresh fruit.",
        "%^RESET%^Rich with %^MAGENTA%^d%^BOLD%^a%^RESET%^%^MAGENTA%^te%^BOLD%^s"+
            "%^RESET%^, this dessert pudding cake is topped with a %^ORANGE%^s%^BOLD%^"+
            "w%^WHITE%^e%^ORANGE%^e%^RESET%^%^ORANGE%^t c%^BOLD%^a%^WHITE%^r%^ORANGE%^"+
            "a%^WHITE%^m%^ORANGE%^e%^RESET%^%^ORANGE%^l %^RESET%^sauce.",
        "%^RESET%^A traditional trifle made from homemade %^ORANGE%^sponge cake"+
            "%^WHITE%^, brushed with %^BOLD%^%^MAGENTA%^ras%^RESET%^%^MAGENTA%^p"+
            "%^BOLD%^be%^RESET%^%^MAGENTA%^r%^BOLD%^r%^RESET%^%^MAGENTA%^y %^BOLD%^j"+
            "%^RESET%^%^MAGENTA%^a%^BOLD%^m %^RESET%^and sprinkled with %^YELLOW%^dr"+
            "%^RESET%^%^ORANGE%^a%^BOLD%^mb%^RESET%^%^ORANGE%^u%^BOLD%^ie l%^RESET%^"+
            "%^ORANGE%^i%^BOLD%^qu%^RESET%^%^ORANGE%^o%^BOLD%^re%^RESET%^. It has "+
            "been layered in a glass with %^BOLD%^%^GREEN%^f%^ORANGE%^ru%^RED%^i"+
            "%^RESET%^%^RED%^t%^WHITE%^, %^ORANGE%^van%^WHITE%^i%^ORANGE%^l%^WHITE%^l"+
            "%^ORANGE%^a p%^WHITE%^u%^ORANGE%^dd%^WHITE%^i%^ORANGE%^ng%^WHITE%^, and "+
            "%^BOLD%^wh%^RESET%^i%^BOLD%^pp%^RESET%^e%^BOLD%^d cre%^RESET%^a%^BOLD%^m"+
            "%^RESET%^.",
        "%^RESET%^A sparkling glass of clear, clean %^BOLD%^%^CYAN%^w%^WHITE%^a"+
            "%^CYAN%^ter %^RESET%^with a wedge of %^YELLOW%^l%^WHITE%^e%^ORANGE%^mon "+
            "%^RESET%^placed on the rim.",
        "%^RESET%^A wonderfully scented cup of fresh %^ORANGE%^t%^BOLD%^%^BLACK%^e"+
            "%^RESET%^%^ORANGE%^a%^RESET%^, the fragrance wafting pleasantly to fill "+
            "the room.",
        "%^RESET%^A house creation, this is a snifter of regional %^ORANGE%^b%^RED%^r"+
            "%^ORANGE%^an%^RED%^d%^ORANGE%^y %^WHITE%^that can been %^BOLD%^i%^CYAN%^c"+
            "%^WHITE%^ed %^RESET%^for at least a day.",
        "%^RESET%^A cooking concoction that has caught on as a drink. This particular "+
            "%^YELLOW%^s%^WHITE%^h%^ORANGE%^er%^WHITE%^r%^ORANGE%^y %^RESET%^has been "+
            "run through a barrel of %^RED%^sm%^ORANGE%^o%^RED%^ld%^ORANGE%^e%^RED%^ri"+
            "%^ORANGE%^n%^RED%^g %^ORANGE%^oak%^RESET%^.",
        "%^RESET%^A house creation, this %^ORANGE%^s%^BOLD%^c%^RESET%^%^ORANGE%^o"+
            "%^BOLD%^tc%^RESET%^%^ORANGE%^h %^WHITE%^is aged for twenty five years "+
            "and is a rich %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^"+
            "%^ORANGE%^n a%^BOLD%^m%^WHITE%^b%^ORANGE%^e%^RESET%^%^ORANGE%^r%^WHITE%^"+
            ". Connoisseurs and bards of the realms have written about how smooth "+
            "and warm this drink goes down.",
        "%^RESET%^This tall glass of wine contains a perfectly aged, %^ORANGE%^g"+
            "%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^n %^WHITE%^medly of "+
            "regional %^BOLD%^%^GREEN%^g%^ORANGE%^r%^GREEN%^a%^ORANGE%^pe%^GREEN%^s"+
            "%^RESET%^."
    }));
}

