#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id( ({"sample sheet"}) );
    set_name("sample sheet");
    set("short", "A sheet containing samples of possible emblems");
    set_long(
"%^CYAN%^Rollo Taylor, master tailor: List of Emblems for clothing and sundry\n"+
"%^RESET%^\n"+
"These are the list of emblems that Master Taylor will sew on your item\n"+
"of custom clothing, if you desire.  Of course, these items can be sown\n"+
"with many different thread colors.  Master Taylor will inform you of the\n"+
"colors that he is carrying to embroider your item!\n"+
"%^BOLD%^\n"+
"angel                diamond           lute\n"+
"anvil                eagle             mountain\n"+
"axe                  fish              raven\n"+
"bird                 flame             scale\n"+
"book                 gauntlet          snake\n"+
"candle               hammer            staff\n"+
"castle               helm              sun\n"+
"chimera              helmet            sword\n"+
"club                 hill              talon\n"+
"cross                horned skull      teardrop\n"+
"crossed bones        horse             torch\n"+
"crossed daggers      horse head        unicorn\n"+
"crossed swords       keep              wheel\n"+
"crow                 leaf              wolf\n"+
"dagger               lion\n"+
"demon                lioness\n"+
"%^RESET%^\n"+
"Master Taylor will also be asking which color threads he will sew your\n"+
"emblem with.  He is pleased to carry the following colors...\n"+
"\n"+
"%^RED%^BOLD%^red%^RESET%^\n"+
"%^YELLOW%^yellow%^RESET%^\n"+
"%^GREEN%^BOLD%^green%^RESET%^\n"+
"%^BLUE%^BOLD%^blue%^RESET%^\n"+
"%^BOLD%^silver%^RESET%^\n"+
"%^YELLOW%^BOLD%^golden%^RESET%^\n"+
"\n"+
"%^BOLD%^YELLOW%^Quality is our catchword!%^RESET%^\n"
    );
    set_weight(0);
    set_value(0);
}
