#include <std.h>
inherit "/d/common/obj/lrweapon/flarrows";

void create()
{
    ::create();
    set_id(({ "arrows", "larrows", "longbow arrows", "missiles", "quiver", "heavy quarrel", "shortbow arrow", "longbow arrow", "bullet", "limitless quiver", "leather quiver", "partitioned quiver", "cartridge" }));
    set_short("%^RESET%^%^CYAN%^Lim%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^tl%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^s Qui%^BOLD%^%^CYAN%^v%^RESET%^%^CYAN%^er%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^partitioned leather quiver%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This quiver is made from finely tanned leather, bearing no patterning or decoration to its plain form.  Instead, efforts have been put into its %^RED%^sturdiness %^ORANGE%^and %^CYAN%^serviceability%^ORANGE%^, with carefully reinforced seams and a thick strap to hold it comfortably over the shoulder.  Inside, the main shaft of the quiver has been partitioned into three, with the deepest carrying several fletched %^GREEN%^flight arrows %^ORANGE%^which have been sized for a longbow.  Raised bottoms have been fitted to the other two sections, one of which carries %^BLUE%^shortbow arrows%^ORANGE%^, and the other %^BOLD%^%^BLACK%^crossbow quarrels%^RESET%^%^ORANGE%^.  Finally, two pockets have been fitted on either sode of the quiver.  One which bears a few %^RESET%^smooth stones %^ORANGE%^for a sling, while the other holds numerous %^RESET%^%^RED%^alchemical cartridges %^RESET%^%^ORANGE%^for firearms.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^Such a quiver was once only a common lesser magical item among elvenkind, usually made for flight arrows to fit the longbows that they favor.  Some more resourceful human enchanters have taken on the crafting of similar quivers, but with all kinds of ammunition as the varied races of the realm may seek to use.  Each sleeve and pocket is bestowed with a minor enhancement that replaces any arrow, quarrel or stone taken from it.  In this way an archer might pick up any weapon they choose and never be left without something to fire from it.%^RESET%^");
    set_property("lore difficulty", 10);
    set_shots(-1);
    set_property("repairtype", ({ "leatherwork" }));
    set_value(90);
}

int is_arrows()
{
    return 1;
}

int isMagic()
{
    return 1;
}
