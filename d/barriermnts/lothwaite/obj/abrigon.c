#include <std.h>

#define COLOR1 ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^%^GREEN%^green","%^YELLOW%^yellow","%^BOLD%^%^RED%^red","%^BOLD%^%^CYAN%^azure","%^BOLD%^%^MAGENTA%^pink"})

#define COLOR2 ({"%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^violet","%^RESET%^%^BLUE%^cobalt","%^RESET%^%^GREEN%^olive green","%^RESET%^%^CYAN%^cyan","%^RESET%^%^RED%^crimson"})

#define COLOR3 ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^RESET%^%^ORANGE%^bronze"})

#define COLOR4 ({"%^RESET%^%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst","%^BOLD%^%^BLUE%^sap%^CYAN%^ph%^BLUE%^ire","%^BOLD%^%^GREEN%^eme%^RESET%^%^GREEN%^ra%^BOLD%^ld","%^YELLOW%^to%^RESET%^%^ORANGE%^p%^YELLOW%^az","%^BOLD%^%^RED%^ru%^RESET%^%^RED%^b%^BOLD%^y","%^RESET%^%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine"})

#define DECORATION ({"leaf","feather","gem","pair of dice","candle","sun","star","moon","heart","stag","bear","boar","bee","dolphin","kingfisher","crane","whale","cat","dog","bird","cloud","crown","dagger","sword","hammer","spear","rose","daisy","lute"})
inherit ARMOUR;

int i,j,k,l,m;
string str, C1, C2, C3, C4, DEC;

void create()
{
   ::create();
	j = random(sizeof(COLOR1));
	C1 = COLOR1[j];
	i = random(sizeof(COLOR2));
	C2 = COLOR2[i];
      k = random(sizeof(COLOR3));
      C3 = COLOR3[k];
      m = random(sizeof(COLOR4));
      C4 = COLOR4[m];
      l = random(sizeof(DECORATION));
      DEC = DECORATION[l];
	set_value(random(25)+200);
      set_name("beaded abrigon");
	set_short("%^BOLD%^%^RED%^b%^RESET%^%^ORANGE%^e%^YELLOW%^a"+
         "%^GREEN%^d%^CYAN%^e%^BLUE%^d %^WHITE%^abrigon%^RESET%^");
	set_id(({"hair wrap","hair decoration","abrigon","beaded abrigon"}));
	set_long("The abrigon is a type of hair decoration in which "+
         "a thin thong of %^ORANGE%^leather %^RESET%^is laced with "+
         "%^BOLD%^%^RED%^b%^YELLOW%^e%^GREEN%^a%^CYAN%^d%^BLUE%^s "+
         "%^RESET%^that can be tied into the wearer's hair.  "+
         "This abrigon has been made of "+C1+"%^RESET%^, "+C2+"%^RESET%^"+
         ", "+C4+"%^RESET%^, and "+C3+" %^BOLD%^%^WHITE%^beads%^RESET%^.  A tiny "+
         "decorative %^ORANGE%^wooden "+DEC+" %^RESET%^has been tied "+
         "onto the end.");
      set_lore("The abrigon is a type of hair decoration favored "+
         "by the firbolgs of Lothwaite.  The word is their own, "+
         "and few now remember its origins.  Most firbolgs have "+
         "an abrigon crafted for them when they come of age, and "+
         "they wear them until they choose to marry.  Then, each "+
         "firbolg cuts the abrigon from his or her air, and they "+
         "are exchanged during the wedding ceremony, much like "+
         "humans exchange rings.  A married firbolg will wear "+
         "his partner's abrigon until death.");
      set_property("lore difficulty",15);
	set_weight(1);
	set_type("ring");
	set_limbs(({"head"}));
	set_ac(0);
}
