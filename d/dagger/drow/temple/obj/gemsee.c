#include <std.h>

#define QUERY_NAME query_cap_name
inherit OBJECT;
int uses;
void init() {
    ::init();
    add_action("view_func","view");
}
void create() {
    ::create();
    set_id(({"gem","gem of true seeing"}));
    set_name("Gem of true seeing");
    set_short("%^CYAN%^%^BOLD%^Gem of true seeing%^RESET%^");
    set_long("This gem is used to view the area around you or "
    	"in ajoining rooms in method to detect invisible beings."
	"It is used by <view> or <view [direction]>."
);
   set_weight(10);
   set_value(800);
  uses = random(5);
}
int view_func(string str) {
    int i,x,FLAG;
    object locale,*inv,*exits;
    string desc,where;
	
   uses--;
    if (!str) {
        locale = environment(TP);
        desc = (string)locale->query_long()+"\n";
        inv = all_inventory(locale);
        for(i=0; i<sizeof(inv); i++) {
           if(avatarp(inv[i]) && (inv[i]->query_true_invis())) continue;
            if(inv[i]->query_property("no detect")) continue;
            if(inv[i]->query_invis()) {
	        desc += "(";
	        desc += (string)inv[i]->QUERY_NAME()+")\n";
	    } else {
                desc += (string)inv[i]->query_short()+"\n";
            }
        }
        write(
            "%^CYAN%^You concentrate while peering through the gem."
            "\n%^MAGENTA%^"+desc+"%^RESET%^"
        );
        say(
            "%^CYAN%^"+TPQCN+" peers through a gem.%^RESET%^"
        ,TP);
     if(uses < 1) call_out("remove",1);
        return 1;
    }
    where = str;
    exits = environment(TP)->query_exits();
    if(member_array(where, exits) == -1){
        FLAG = 0;
    } else {
        FLAG = 1;
        locale = environment(TP)->query_exit(where);	
        locale = find_object_or_load(locale);
    }
    if(FLAG == 0) {
	write(
	    "%^CYAN%^You cannot view anything there!%^RESET%^"
	);
      if(uses < 1) call_out("remove",1);
        return 1;
    } else {
        desc = (string)locale->query_long()+"\n";
        inv = all_inventory(locale);
        for(i=0; i<sizeof(inv); i++) {
           if(avatarp(inv[i]) && (inv[i]->query_true_invis())) continue;
            if(inv[i]->query_property("no detect")) continue;
            if(inv[i]->query_invis()) {
	        desc += "(";
	        desc += (string)inv[i]->QUERY_NAME()+")\n";
	    } else {
                desc += (string)inv[i]->query_short()+"\n";
            }
        }
        write(
            "%^CYAN%^You concentrate while peering through the gem."
            "\n%^MAGENTA%^"+desc+"%^RESET%^"
        );
        say(
            "%^CYAN%^"+TPQCN+" peers through a gem.%^RESET%^"
        ,TP);
      if(uses < 1) call_out("remove",1);
        return 1;
    }       
}	
