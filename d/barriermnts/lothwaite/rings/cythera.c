#include <std.h>
inherit ARMOUR;

string symbol1;
string symbol2;
string weapon1;
string weapon2;
string initial1;
string initial2;
string background;
void create(){
	::create();
	set_name("signet ring");
	set_id(({"ring","signet ring","signet"}));
	set_short("signet ring");
	symbol1 = "a swarm of five %^YELLOW%^bees %^RESET%^flying a %^CYAN%^diamond-shaped pattern%^RESET%^";
	symbol2 = "a %^YELLOW%^golden crown %^RESET%^glittering with %^BOLD%^je%^CYAN%^we%^WHITE%^ls%^RESET%^";
	background = "a sprawling %^BOLD%^walled city %^RESET%^with a %^CYAN%^tower %^RESET%^rising high";
	set_long("This finely crafted signet ring is made of high quality %^BOLD%^white gold%^RESET%^.  It is a rather thick ring with a round, flat top that features "+(string)TO->query_seal()+"");
	set_weight(1);
	set_value(750);
	set_ac(0);
	set_limbs(({"right hand"}));
	set_type("ring");
set_lore("This signet ring was made by Edric, the firbolg jeweler in the village of Lothwaite.  Its symbols bear meaning for one person and refer to him or her alone.");
set_property("lore difficulty",12);
}
int query_symbol(){ return ""+symbol1+"";}
int query_symbol2(){ return ""+symbol2+"";}
int query_seal(){ return "a backdrop of "+background+".  On top of the background is the finely detailed image of "+symbol1+" beside an intricate depiction of "+symbol2+"."; }
int query_is_seal_device(){ return 1;}
