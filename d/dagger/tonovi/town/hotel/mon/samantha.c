// Chernobog (1/10/21)
// Tonovi Hotel

#include "../defs.h"
inherit "/std/vendor.c";

void create() {
    ::create();
    set_name("Samantha");
    set_id(({"samantha","waitress","Samantha"}));
    set_short("%^BOLD%^%^MAGENTA%^Samantha%^RESET%^%^MAGENTA%^, %^BOLD%^cigar girl "+
        "%^RESET%^%^MAGENTA%^for the %^YELLOW%^H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t"+
        "%^RESET%^%^ORANGE%^e%^BOLD%^l R%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^staura"+
        "%^RESET%^%^ORANGE%^n%^BOLD%^t%^RESET%^");
    set("aggressive", 0);
    set_level(10);
    set_long("%^RESET%^%^CYAN%^She is a petite woman, wrapped in a close-fitting "+
        "%^BOLD%^%^BLACK%^knee length dress %^RESET%^%^CYAN%^in the colors of the "+
        "%^YELLOW%^T%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^no%^RESET%^%^ORANGE%^v%^BOLD%^"+
        "i H%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^l "+
        "l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ve%^RESET%^%^ORANGE%^r%^BOLD%^y"+
        "%^RESET%^%^CYAN%^. Her %^BOLD%^%^BLACK%^short black hair %^RESET%^%^CYAN%^"+
        "has been cut in an angled bob, with %^YELLOW%^g%^WHITE%^o%^ORANGE%^l%^RESET%^"+
        "%^ORANGE%^d%^BOLD%^en ea%^WHITE%^r%^ORANGE%^rin%^RESET%^%^ORANGE%^g%^BOLD%^s "+
        "%^RESET%^%^CYAN%^peeking out when her hair sways to the side. A thin %^BOLD%^"+
        "%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r c%^RESET%^h"+
        "%^BOLD%^ok%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^graces her neck, "+
        "featuring a single beveled %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by"+
        "%^RESET%^%^CYAN%^. Carrying a gleaming silver tray, she can be seen making "+
        "her way between the various customers, selling cigars.%^RESET%^");
    set_gender("female");
    set_alignment(6);
    set_race("human");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    add_money("copper", random(200));
    set_items_allowed("tobacco");
    set_storage_room(STOR+ "samantha_storage");
    new(OBJ"collar.c")->move(TO);
    command("wear collar");
}

