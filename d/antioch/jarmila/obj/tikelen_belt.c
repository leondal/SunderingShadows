

#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_obvious_short("%^RESET%^%^BOLD%^silv%^RESET%^e%^RESET%^%^BOLD%^r rel%^RESET%^i%^RESET%^%^BOLD%^quary "+
	"on a ch%^RESET%^a%^RESET%^%^BOLD%^in%^RESET%^");
	set_short("%^RESET%^%^BOLD%^The T%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^kelen "+
	"Tru%^RESET%^%^CYAN%^t%^RESET%^%^BOLD%^h%^RESET%^");
    set_name("%^RESET%^%^BOLD%^The T%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^kelen "+
	"Tru%^RESET%^%^CYAN%^t%^RESET%^%^BOLD%^h%^RESET%^");
    set_lore("%^RESET%^%^BOLD%^Mother Tikelen was the mother superior for a small order of nuns devoted "+
        "to the worship of Jarmila.  While the nuns were physically not able to protect the people around them "+
	"they laid down their lives countless times to allow the innocent to survive. The mother herself "+
        "sacrificed herself to save a child of prophesy who would later become one of Jarmila's most powerful "+
	"paladins. The reliquary contains bone fragments gathered from the nun's corpse after she fell.\n");
    set_property("lore difficulty",20);
    set_id(({"belt","chain belt","chain","tikelen truth","reliquary","silver reliquary a chain"}));
    set_property("repairtype",({ "jewel" }));
    set_long("%^RESET%^%^BOLD%^A thin silver chain no wider then a sapling attaches to a small egg "+
	"shaped silver %^RESET%^reliquary%^RESET%^%^BOLD%^. It is obvious that the chain is meant to be "+
	"worn as a belt with the %^RESET%^reliquary%^RESET%^%^BOLD%^ close at hand. The small egg is "+
	"intricately designed and is dominated by %^CYAN%^sacred runes%^RESET%^%^BOLD%^ "+
	"and %^RESET%^%^CYAN%^writings%^RESET%^%^BOLD%^ along it. Though it looks delicate it "+
	"radiates a power that belies its true strength.\n%^RESET%^");
    set_weight(5);
    set_value(2000);
    set_ac(0);
    set_size(-1);
    set_property("enchantment",7);
    set_item_bonus("intelligence",3);
    set_item_bonus("wisdom",3);
    set_type("clothing");
    set_limbs(({"waist"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() { 
      tell_object(ETO,"%^RESET%^%^CYAN%^As you attach the chains and reliquary around "+
	  "you, you feel the strength of old promises seep into you.%^RESET%^");
   return 1;
}

int removeme() {
      tell_object(ETO,"%^RESET%^%^CYAN%^You feel yourself forgetting "+
	  "old promises as you remove the chains and reliquary%^RESET%^.");
   return 1;
}

