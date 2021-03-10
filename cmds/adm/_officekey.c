// This command will move an officekey to an admin
// Pator@ShadowGate
// Jan 14th 1997

#include <std.h>

#define KEYS	"/d/shadowgate/arch/keys/"

int cmd_officekey() {
string who;
	if (!archp(TP)) return 0;

	who = (string)TP->query_true_name();

	switch (who) {

	case "dalamar" : new(KEYS+"dalamarofficekey.c")->move(TP); 
                         break;
	case "firedragon" : new(KEYS+"FDofficekey.c")->move(TP); 
                            break;
	case "grayhawk" : new(KEYS+"grayhawkofficekey.c")->move(TP); 
                          break;
	case "grazzt" : new(KEYS+"grazztofficekey.c")->move(TP); 
                        break;
	case "melnmarn" : new(KEYS+"melnmarnsofficekey.c")->move(TP); 
			  break;
	case "pator" : new("/realms/pator/closed/obj/pator_stone.c")->move(TP); 
		       break;
	case "thorn" : new(KEYS+"thornsofficekey.c")->move(TP); break;
	case "tristan" : new(KEYS+"tristansofficekey.c")->move(TP); break;
			}
	tell_object(TP, "You get a new office key !");
	return 1;
}
