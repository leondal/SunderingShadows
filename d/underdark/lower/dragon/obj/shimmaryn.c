#include <std.h>
#include <daemons.h>
inherit OBJECT;

int charges;
void set_mydesc();

void create() {
    ::create();
    set_name("crystal lattice");
    set_id(({"lattice","crystals","lattice of crystals","lattice of translucent crystals","translucent crystals","shimmaryn","Shimmaryn"}));
    set_short("%^RESET%^%^CYAN%^Sh%^BOLD%^i%^RESET%^%^CYAN%^mma%^GREEN%^ry%^CYAN%^n%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^lattice of %^CYAN%^tr%^GREEN%^a%^CYAN%^nsl%^BOLD%^u%^RESET%^%^CYAN%^cent %^ORANGE%^crystals%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^Deceptively decorative, a Shimmaryn lattice is an incredibly dangerous artifact, rarely "
"found and rarely used to good ends.  While to an initial inspection, it appears to be nothing more than a delicate item "
"of jewelry, the truth is far more serious.  The metal lattice itself serves as a magical cage, always crafted of fine "
"copper for its ability to isolate the fragile fragments it holds.  Each 'jewel' is, in fact, a small area of dead magic "
"captured within the warded lattice.  When loosed, they will unleash a destructive burst of magic upon the nearest "
"creature or object, negating any magical effects upon them.  Rumors of such an item can strike fear into the most "
"powerful of spellweavers all across the realms, and with good reason.  You suspect you could %^YELLOW%^break a crystal "
"near%^WHITE%^ someone to try to invoke this powerful effect.%^RESET%^");
    set_property("lore difficulty",30);
    set_property("id difficulty",30);
    set_weight(10);
    set_value(9500);
    charges = 4+ random(5);
    set_mydesc();
}

void init() {
    ::init();
   add_action("shatter_fun","break");
}

void shatter_fun(string str) {
    object mytarg;
    string mytarget;
    if(!userp(ETO)) return notify_fail("You must be holding the crystal lattice to use it.\n");
   if(!str) return notify_fail("What do you want to break?\n");
    if(sscanf(str,"a crystal near %s", mytarget) != 1) return notify_fail("You can't shatter a crystal near that.\n");
    if(!mytarg = present(mytarget,ETP)) return notify_fail("There is no "+mytarget+" here.\n");
   if(!charges) return notify_fail("There are no crystals left to break!\n");
    if(ETO->query_level() < 35) return notify_fail("You are not experienced enough to use this item.\n");
    if((int)ETO->query_property("shimmaryn-use") > time())
      return notify_fail("You need to gather your concentration before you can use such an item again!\n");
    tell_object(ETO,"%^CYAN%^You deftly twist the malleable %^ORANGE%^cop%^BOLD%^%^MAGENTA%^p%^RESET%^%^ORANGE%^er "
"%^CYAN%^wires to free one of the crystals, casting it towards "+mytarg->QCN+", and it %^BOLD%^%^WHITE%^s%^YELLOW%^h"
"%^WHITE%^a%^RESET%^t%^BOLD%^%^BLACK%^t%^RED%^e%^WHITE%^rs %^RESET%^%^CYAN%^into a million tiny fragments as it makes "
"contact!%^RESET%^");
    tell_object(mytarg,"%^CYAN%^"+ETO->QCN+" deftly twists the lattice's malleable %^ORANGE%^cop%^BOLD%^%^MAGENTA%^p"
"%^RESET%^%^ORANGE%^er %^CYAN%^wires to free one of its crystals, casting it towards you, and it %^BOLD%^%^WHITE%^s"
"%^YELLOW%^h%^WHITE%^a%^RESET%^t%^BOLD%^%^BLACK%^t%^RED%^e%^WHITE%^rs %^RESET%^%^CYAN%^into a million tiny fragments as "
"it makes contact!%^RESET%^");
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+" deftly twists the lattice's malleable %^ORANGE%^cop%^BOLD%^%^MAGENTA%^p%^RESET%^"
"%^ORANGE%^er %^CYAN%^wires to free one of its crystals, casting it towards "+mytarg->QCN+", and it %^BOLD%^%^WHITE%^s"
"%^YELLOW%^h%^WHITE%^a%^RESET%^t%^BOLD%^%^BLACK%^t%^RED%^e%^WHITE%^rs %^RESET%^%^CYAN%^into a million tiny fragments as "
"it makes contact!%^RESET%^",({ETO,mytarg}));
    ETO->set_property("shimmaryn-use",(time()+20));
    new("/cmds/spells/g/_greater_dispel_magic")->use_spell(ETO,mytarget,40,100,"mage");
    charges--;
    set_mydesc();
    return 1;
}

int isMagic(){ return 1; }

void set_mydesc() {
    if(!charges) {
      set_long("%^RESET%^The base of this fascinating item is an %^BOLD%^in%^YELLOW%^t%^WHITE%^ricate %^RESET%^plaited "
"mesh of copper.  Each fine thread gleams with a distinct %^ORANGE%^pink%^BOLD%^%^MAGENTA%^i%^RESET%^%^ORANGE%^sh "
"%^RESET%^cast as it overlaps and intertwines with neighbouring strands.  Soft and malleable even now, many of the "
"strands have been looped and woven, leaving spaces to hold some kind of tiny object, each only a finger's width in size"
".  All of the spaces are empty, though; whatever was once there has been since removed.  An initial inspection reveals "
"nothing of its purpose, however, unless it is intended to be merely %^MAGENTA%^dec%^BOLD%^o%^RESET%^%^MAGENTA%^ra%^RED%^t"
"%^MAGENTA%^ive%^RESET%^.");
      return;
    }
    set_long("%^RESET%^The base of this fascinating item is an %^BOLD%^in%^YELLOW%^t%^WHITE%^ricate %^RESET%^plaited "
"mesh of copper.  Each fine thread gleams with a distinct %^ORANGE%^pink%^BOLD%^%^MAGENTA%^i%^RESET%^%^ORANGE%^sh "
"%^RESET%^cast as it overlaps and intertwines with neighbouring strands.  Soft and malleable even now, many of the "
"strands have been looped and woven to hold tiny s%^BOLD%^p%^RESET%^ar%^BOLD%^k%^RESET%^li%^BOLD%^n%^RESET%^g jewels, "
"each only a finger's width in size.  You can count %^YELLOW%^"+charges+" %^RESET%^of them in total.  Each jewel is "
"perfectly symmetrical and semi-translucent, somewhere near the consistency of %^CYAN%^c%^BOLD%^l%^RESET%^%^CYAN%^oudy "
"gl%^GREEN%^as%^CYAN%^s%^RESET%^.  An initial inspection reveals nothing of its purpose, however, unless it is intended "
"to be merely %^MAGENTA%^dec%^BOLD%^o%^RESET%^%^MAGENTA%^ra%^RED%^t%^MAGENTA%^ive%^RESET%^.");
}

void renew_charges() { charges = 4+ random(5); set_mydesc(); }
int is_tazrak_charged() { return 1; }
