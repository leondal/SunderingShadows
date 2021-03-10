// webbing bow created by xangli 12/8/09
#include <std.h>
inherit "/d/attaya/obj/deathbow.c";
int uses = 3;
void create(){
  ::create();
  set_obvious_short("Sticky Crossbow");
  set_short("An ivory crossbow");
  set_long("This crossbow appears to "+
    "have been carved from pure %^RESET%^i%^BOLD%^v%^BLACK%^"+
	"o%^WHITE%^r%^RESET%^y, %^BOLD%^%^WHITE%^though it has a"+
	" %^CYAN%^s%^RESET%^t%^BOLD%^r%^BLACK%^a%^WHITE%^n%^CYAN%^"+
	"ge %^WHITE%^underlying %^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^ow"+
	" %^WHITE%^that permeates throughout the weapon from "+
	"within its very core, concentrating amongst the %^BLACK%^"+
	"r%^CYAN%^e%^BLACK%^ce%^CYAN%^s%^RESET%^s%^BOLD%^es of the "+
	"strange %^BLACK%^w%^RESET%^e%^BOLD%^%^BLACK%^b %^WHITE%^like"+
	" %^BLACK%^c%^RESET%^a%^BOLD%^%^CYAN%^r%^WHITE%^v%^BLACK%^i"+
	"%^RESET%^n%^BOLD%^g%^RESET%^s %^BOLD%^etched upon the "+
	"entirety of the cross-piece.  %^BOLD%^Rather than normal"+
	" bowstrings, this crossbow has strong, %^RESET%^s%^BOLD%^"+
	"%^CYAN%^i%^BLACK%^l%^WHITE%^k%^RESET%^y w%^BOLD%^%^BLACK%^"+
	"e%^WHITE%^bl%^BLACK%^i%^RESET%^ke strings %^BOLD%^that "+
	"%^CYAN%^s%^BLACK%^h%^WHITE%^i%^CYAN%^m%^RESET%^m%^BOLD%^%^BLACK%^"+
	"e%^RESET%^r %^BOLD%^always, even when holding the prod taught"+
	" against the stock with the multitudes of pulleys attached to it.");
	
}
void init(){
    ::init();
    add_action("read","read");
    add_action("web","web");

}
void read(string str){
    string tmp;
    if(!str) return notify_fail("Read what?  Crossbow?\n");
    if(!sscanf(str,"crossbow %s",tmp)) return 0;
    write("This is a crossbow of web, it has the following functions:\n"
        "web <name>: shoots a web at target\n"+
        uses+" charges left");
    return 1;
}
void web(string str){
    object ob;
    if(uses < 0) return notify_fail("The crossbow is out of charges.\n");
    if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",TP);
       return 1;
    }


    if(!str) return notify_fail("web who?\n");
    if(!(ob = present(str, ETP))) return notify_fail("That isn't here!\n");
    
   new("/cmds/spells/w/_web")->use_spell(ETO,ob,40,100,"mage");

    uses--;
    return 1;
}
