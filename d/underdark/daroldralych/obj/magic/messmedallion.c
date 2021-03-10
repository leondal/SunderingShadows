#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("platinum medallion");
   set_id(({"medallion","thick medallion","platinum medallion","thick platinum medallion","messenger medallion"}));
   set_short("%^BOLD%^%^WHITE%^Mes%^CYAN%^s%^WHITE%^enger Medal%^CYAN%^l%^WHITE%^ion%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^thick plati%^CYAN%^n%^WHITE%^um medallion%^RESET%^");
   set_long("This medallion is suspended by a chain of identical metal, "
"polished to a %^BOLD%^%^WHITE%^bri%^YELLOW%^g%^WHITE%^ht %^RESET%^shine. "
" The braided links support the medallion itself, which forms a perfect "
"circle of %^BOLD%^%^WHITE%^pla%^CYAN%^t%^WHITE%^inum %^RESET%^metal.  It "
"bears no markings upon the surface, but upon the underside a line of "
"flowing %^GREEN%^r%^CYAN%^u%^GREEN%^n%^CYAN%^e%^GREEN%^s %^RESET%^have "
"been etched to follow the curved edge of the jewelry.");
   set_lore("Such items as these come in all appearances, and are highly "
"prized by many races.  This one in particular is known to be of "
"underdark origin, crafted by drow.  They tend to be quite rare in such a "
"society, as psionics are near unknown to them, which leaves only the "
"priesthood able to craft them.  And they are not fond of sharing what is "
"theirs.\n");
   set_property("lore difficulty",6);
   set_read("%^RESET%^~ concentrate to %^YELLOW%^contact %^RESET%^someone ~\n");
   set_language("drow");
   set_weight(0);
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(980);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   tracker = 0;
}

void init() {
   ::init();
   add_action("contact_me","contact");
}

int wear_fun() {
   if((int)ETO->query_highest_level() < 15) {
     tell_object(ETO,"Some kind of magical warding prevents you from
wearing the medallion.");
     tell_room(EETO,""+ETOQCN+" seems unable to wear the medallion.",ETO);
     return 0;
   }
   return 1;
}

int contact_me(string str) {
   int targ;
   if(!TO->query_worn()) {
     notify_fail("You should be wearing the medallion to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to contact.\n");
     return 0;
   }
   if(tracker > time()) {
     notify_fail("You've already used this spell recently.\n");
     return 0;
   }
   targ = find_player(TP->realName(lower_case(str)));
   if(!targ) {
     notify_fail("The medallion fails to respond.\n");
     return 0;
   }
   if(targ == ETO) {
     notify_fail("You can't contact yourself.\n");
     return 0;
   }
   if(!interactive(targ)) {
     notify_fail("The medallion fails to respond.\n");
     return 0;
   }
   tracker = time() + 28800;
   new("/cmds/spells/t/_telepathy")->use_spell(ETO,str,40,100,"cleric");
   return 1;
}

void reset_timer() {
   tracker = time();
}
