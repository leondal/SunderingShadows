#include <std.h>
inherit OBJECT;

string owner;

void create() {
    ::create();
    set_name("sword");
    set_id(({"sword2","hm_quest_ages","sword of the ages","sword"}));
    set_short("%^RESET%^%^BLUE%^Sword of the Ages %^RED%^(%^BLUE%^sheathed%^RED%^)%^RESET%^");
    set_long("%^RESET%^%^BLUE%^This superb weapon %^YELLOW%^blazes%^RESET%^%^BLUE%^ with an %^MAGENTA%^inner light%^BLUE%^ unlike any weapon you have ever seen. The scabbard it is sheathed in "
"is covered with %^RED%^glowing runes%^BLUE%^. A %^BOLD%^%^CYAN%^mithril hilt %^RESET%^%^BLUE%^protrudes from the scabbard, weighted with a fang-shaped pommel, and joined to a gleaming "
"%^BOLD%^%^WHITE%^silvery %^RESET%^%^BLUE%^blade. A brilliant %^GREEN%^emerald %^BLUE%^has been set into the hilt. It must be meant for only an incredibly powerful being to ever wield, as no "
"matter how hard you try, you cannot remove it from its scabbard.%^RESET%^");
    set_weight(15);
    set_value(0);
    set_heart_beat(1);
}

void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}

void heart_beat() {
    object holder;
    if(!objectp(ETO)) return;
    if(!interactive(ETO)) return;
    holder = ETO->query_true_name();
    if(holder != owner) {
      tell_object(ETO,"The Sword of the Ages vanishes!");
      TO->remove();
    }
}